#include "StdAfx.h"
#include "DataType.h"
#include "NtlPatchManager.h"
#include "NtlHttpDownLoader.h"
#include "NtlPatchData.h"
#include "NtlRtPatcher.h"
#include "NtlLauncherConfig.h"
#include "NtlPatchServerConfig.h"

CNtlPatchManager *CNtlPatchManager::s_pInstance = NULL;
CNtlPatchManager::CNtlPatchManager() : m_pDownLoader(NULL),
									   m_pPatchHistory(NULL),
									   m_pPatcher(NULL),
									   m_bActive(FALSE),
									   m_ePatchState(PATCH_STATE_NONE),
									   m_bPendingDestory(FALSE),
									   m_bAbort(FALSE)
{

}

CNtlPatchManager::~CNtlPatchManager()
{
	Destroy();
}

BOOL CNtlPatchManager::Create()
{
	m_pDownLoader = CNtlHttpDownLoader::GetInstance();
	m_pPatchHistory = CNtlPatchHistory::GetInstance();
	m_pPatcher = CNtlRtPatcher::GetInstance();
	
	m_pDownLoader->LinkEvent(this, &CNtlPatchManager::DownLoaderCallBack);
	m_pPatcher->LinkEvent(this, &CNtlPatchManager::PatcherCallBack);
	return TRUE;
}

void CNtlPatchManager::Destroy()
{
	if(m_pDownLoader)
	{
		m_pDownLoader->DestroyInstance();
		m_pDownLoader = NULL;
	}

	if(m_pPatchHistory)
	{
		m_pPatchHistory->DestroyInstance();
		m_pPatchHistory = NULL;
	}

	if(m_pPatcher)
	{
		m_pPatcher->DestroyInstance();
		m_pPatcher = NULL;
	}

    CNtlPatchServerConfig::DeleteInstance();

	std::list<CNtlCallbackParam2*>::iterator it;
	for(it = m_listCallBack.begin(); it != m_listCallBack.end(); ++it)
	{
		CNtlCallbackParam2 *pCurrWidget = *it;
		if(pCurrWidget)
		{
			delete pCurrWidget;
			pCurrWidget = NULL;
		}
	}
	m_listCallBack.clear();
}

void CNtlPatchManager::UnLinkEvent(NTL_PATCHER_CALL_BACK_HANDLE handle)
{
	CNtlCallbackParam2 *pWidget = reinterpret_cast<CNtlCallbackParam2*>(handle);

	std::list<CNtlCallbackParam2*>::iterator it;
	for(it = m_listCallBack.begin(); it != m_listCallBack.end(); ++it)
	{
		CNtlCallbackParam2 *pCurrWidget = *it;

		if(pCurrWidget == pWidget)
		{
			delete pCurrWidget;
			pCurrWidget = NULL;

			m_listCallBack.erase(it);
			break;
		}
	}
}

void CNtlPatchManager::SendEvent(unsigned int uiEventID, void *pParam)
{
	std::list<CNtlCallbackParam2*>::iterator it;
	for(it = m_listCallBack.begin(); it != m_listCallBack.end(); ++it)
	{
		(*it)->Call((unsigned int)uiEventID, (unsigned int)pParam);
	}
}

void CNtlPatchManager::DoAction()
{
    CreateDirectory(PATCH_CLIENT_FILE_TEMP_PATH,NULL);          // �ӽ� ������ �����Ѵ�.

    // ��ġ�� ������ �������� Ȯ���Ѵ�.
    if(!CheckPatchEnable())
    {
        SetAbort(TRUE);        
        SendEvent(EVENT_PM_PENDING_DESTROY, NULL);
        return;
    }

	SetActive(TRUE);
    m_setErrFiles.clear();
	
	//���� Version ������ �о� ���δ�.
	m_pPatchHistory->LoadCurVersion(PATCH_CUR_VER_FILE_NAME);

	SendEvent(EVENT_PM_START, NULL);

	EventPMLastUpdateInfoMsg LastUpdateInfoMsg;
	LastUpdateInfoMsg.pClientVersion = m_pPatchHistory->GetCurVerClient()->Get();
	LastUpdateInfoMsg.pLauncherVersion = m_pPatchHistory->GetCurVerLauncher()->Get();
	SendEvent(EVENT_PM_LAST_UPDATE_INFO, &LastUpdateInfoMsg);

	

	if(m_pDownLoader->RequestFile( CNtlLauncherConfig::GetInstance()->GetPatchServerName(), 
								   CNtlLauncherConfig::GetInstance()->GetPatchServerFilePath(), 
								   PATCH_VER_LIST_FILE_NAME, 
								   PATCH_CLIENT_FILE_TEMP_PATH, 
								   PATCH_VER_LIST_FILE_NAME))
	{
		CString strPatchListFileName = PATCH_CLIENT_FILE_TEMP_PATH;
		strPatchListFileName += "/";
		strPatchListFileName += PATCH_VER_LIST_FILE_NAME;

		m_pPatchHistory->LoadPatchList(strPatchListFileName);
		if(GetPatchState() == PATCH_STATE_NONE)
		{
			CNtlPatchData *pLauncherPatchData = m_pPatchHistory->GetNewVerLauncherRtFull();
			if(pLauncherPatchData != NULL)
			{
				SetPatchState(PATCH_STATE_NEW_LAUNCHER);
				SetAbort(TRUE);
			}
		}
		
		if(GetPatchState() == PATCH_STATE_LAUNCHER)
		{
			CNtlPatchData *pPatchData = m_pPatchHistory->GetNewVerLauncherRtFull();

			if(pPatchData != NULL)
			{
				if(m_pDownLoader->RequestFile( CNtlLauncherConfig::GetInstance()->GetPatchServerName(), 
											   CNtlLauncherConfig::GetInstance()->GetPatchServerFilePath(), 
											   pPatchData->GetServerFileName(), 
											   PATCH_CLIENT_FILE_TEMP_PATH, 
											   pPatchData->GetClientFileName() ) == FALSE )
				{
					if(m_pDownLoader->GetPendingDestroy() == FALSE)
						ASSERT(0);
				}
				else
				{
					if(m_pPatcher->DoAction(PATCH_CLIENT_FILE_PATH, pPatchData->GetClientFullPathFileName() ) == TRUE)
					{
						if( m_pPatcher->GetPendingDestroy() == FALSE)
							m_pPatchHistory->SetCurVerLauncher(pPatchData->GetVersion());

                        SetAbort(TRUE);
					}	
				}
			}
            else
            {
                AfxMessageBox("LAUNCHER PATCH DATA IS NONE!");
                SetAbort(TRUE);
            }            
		}

		if(GetPatchState() == PATCH_STATE_NONE)
		{
			CNtlPatchData *pPatchData = m_pPatchHistory->GetNewVerClientRtDiff();

            // ���� ��ġ�۾��� �����Ѵ�.
			while(pPatchData != NULL)
			{
                // 1. ��ġ ����(rtp)�� �ٿ� �޴´�.
				if( m_pDownLoader->RequestFile( CNtlLauncherConfig::GetInstance()->GetPatchServerName(), 
												CNtlLauncherConfig::GetInstance()->GetPatchServerFilePath(), 
												pPatchData->GetServerFileName(), 
												PATCH_CLIENT_FILE_TEMP_PATH, 
												pPatchData->GetClientFileName() ) == FALSE )
				{
					if(m_pDownLoader->GetPendingDestroy() == FALSE)
						ASSERT(0);
					break;
				}
				else
				{
					if(m_pDownLoader->GetPendingDestroy() == TRUE)
						break;
				}

                // 2. �ٿ���� ��ġ ������ ��ġ�Ѵ�.
				if( m_pPatcher->DoAction(PATCH_CLIENT_FILE_PATH, pPatchData->GetClientFullPathFileName() ) == TRUE)
				{
					if(m_pPatcher->GetPendingDestroy() == FALSE)
					{
                        m_pPatchHistory->SetPatchFileDate(pPatchData->GetDate());
						m_pPatchHistory->SetCurVerClient(pPatchData->GetVersion()); // �̶� �����Ѵ�.
					}
				}
				else
				{
                    // ��ġ�� �����ϸ� Ǯ ������ �ٿ�޾Ƽ� ��ġ�Ѵ�.
					pPatchData = m_pPatchHistory->GetNewVerClientRtFull();
					if(pPatchData != NULL)
					{
						if(m_pDownLoader->RequestFile( CNtlLauncherConfig::GetInstance()->GetPatchServerName(), 
													   CNtlLauncherConfig::GetInstance()->GetPatchServerFilePath(), 
													   pPatchData->GetServerFileName(), 
													   PATCH_CLIENT_FILE_TEMP_PATH, 
													   pPatchData->GetServerFileName()) == FALSE)
						{
							ASSERT(0);
							break;
						}
						
						if(m_pDownLoader->GetPendingDestroy() == TRUE)
							break;

						if(m_pPatcher->DoAction(PATCH_CLIENT_FILE_PATH, pPatchData->GetClientFullPathFileName() ) == TRUE)
						{
							if(m_pPatcher->GetPendingDestroy() == FALSE)
							{
								m_pPatchHistory->SetCurVerClient(pPatchData->GetVersion());
							}
						}
					}
					else
					{
						ASSERT(0);
					}
				}
				pPatchData = m_pPatchHistory->GetNewVerClientRtDiff();
			}
		}
	}
    
    if(!m_bAbort && !m_setErrFiles.empty())     // ��ġ�߿� ������ ���ϵ��� ������...
    {
        // ������ ���ϵ��� Ǯ������ �ִ� �������� �ٿ�޴´�.
        //ProcessMissingFiles();        
    }

	SetActive(FALSE);

	SendEvent(EVENT_PM_COMPLETE, NULL);
	
	LastUpdateInfoMsg.pClientVersion = m_pPatchHistory->GetCurVerClient()->Get();
	LastUpdateInfoMsg.pLauncherVersion = m_pPatchHistory->GetCurVerLauncher()->Get();
	SendEvent(EVENT_PM_LAST_UPDATE_INFO, &LastUpdateInfoMsg);

	if( GetAbort() == TRUE ||
		m_pDownLoader->GetPendingDestroy() == TRUE ||
		m_pPatcher->GetPendingDestroy() == TRUE )
	{
		SetPendingDestory(TRUE);
		SendEvent(EVENT_PM_PENDING_DESTROY, NULL);
	}
}

BOOL CNtlPatchManager::CheckPatchEnable() 
{
    if(m_pDownLoader->RequestFile( CNtlLauncherConfig::GetInstance()->GetPatchServerName(), 
                                   CNtlLauncherConfig::GetInstance()->GetPatchServerFilePath(), 
                                   PATCH_SERVER_CONFIG_FILE_NAME,
                                   PATCH_CLIENT_FILE_TEMP_PATH, 
                                   PATCH_SERVER_CONFIG_FILE_NAME))
    {
        CString strPath = PATCH_CLIENT_FILE_TEMP_PATH;
        strPath += "/";
        strPath += PATCH_SERVER_CONFIG_FILE_NAME;

        if(CNtlPatchServerConfig::GetInstance()->LoadServerConfigFile(strPath))
        {
            if(CNtlPatchServerConfig::GetInstance()->GetPatchEnable())
            {
                return TRUE;
            }
            else
            {
                // �޼��� �ڽ��� �ٿ��.                
                AfxMessageBox(CNtlPatchServerConfig::GetInstance()->GetPatchErrMsg().c_str());                
            }
        }        
    }
    else
    {
        AfxMessageBox("Can't Connect DBO Patch Server...");
    }

    return FALSE;
}

void CNtlPatchManager::SetAbort(BOOL bAbort)
{
	m_pDownLoader->SetAbort(TRUE);
	m_pPatcher->SetAbort(TRUE);
	m_bAbort = TRUE;
}

BOOL CNtlPatchManager::GetAbort() 
{
	return m_bAbort;
}

BOOL CNtlPatchManager::GetActive()
{
	return m_bActive;
}

int CNtlPatchManager::DownLoaderCallBack(unsigned int uiEventID, unsigned int pParam)
{
	SendEvent(uiEventID, (void *)pParam);
	return TRUE;
}

int CNtlPatchManager::PatcherCallBack(unsigned int uiEventID, unsigned int pParam)
{
    switch(uiEventID)
    {
    case EVENT_PH_RT_FILE_PATCH_START:              // ���ϴ� ��ġ�� ���۵ɶ����� ������ �޽���
        {
            EventPHTextMsg* pMsg = (EventPHTextMsg*)pParam;
            m_strCurrentPatchFileName = pMsg->pszMessage;  // ����������� ���ϸ��� �˱����ؼ� �����صд�. (�����޽��������� ���ϸ��� �˼��� ����)
        }
        break;
    case EVENT_PH_RT_WARNING_MESSAGE_HEADER:        // ������ ������ ��� Set�ȿ� �ִ´�. (���ϸ��� �ߺ����� �ʰ�)
        m_setErrFiles.insert(m_strCurrentPatchFileName);    // ���� ��ġ�� �߰��� Add�� ������ �� �ķ� ���������� ��ġ�� �Ǵµ� �̶��� ���� ����Ʈ���� �����ؾ� �Ѵ�.
        break;    
    }

	SendEvent(uiEventID, (void *)pParam);
	return TRUE;
}

BOOL CNtlPatchManager::ProcessMissingFiles() 
{
    BOOL m_bReturn = TRUE;
    for each(std::string strErrFileName in m_setErrFiles)
    {
        if(!m_pDownLoader->RequestFile(CNtlPatchServerConfig::GetInstance()->GetFullVerServerIP().c_str(), 
            CNtlPatchServerConfig::GetInstance()->GetFullVerServerFolder().c_str(),
            strErrFileName.c_str(),
            "", 
            strErrFileName.c_str()))
        {
            m_bReturn = FALSE;
        }
    }

    return m_bReturn;
}