#include "StdAfx.h"
#include "afxinet.h"
#include "NtlHttpDownLoader.h"

CNtlHttpDownLoader::CNtlHttpDownLoader(void)
{
}

CNtlHttpDownLoader::~CNtlHttpDownLoader(void)
{
	
}

BOOL CNtlHttpDownLoader::RequestFile( const char *pszServerName,
									  const char *pszServerPath,
									  const char *pszServerFileName,
									  const char *pszClientPath,
									  const char *pszClientFileName)
{
	SetActive(TRUE);

	CInternetSession	INetSession;
	CHttpConnection		*pHttpConnection = NULL;
	CHttpFile			*pFile = NULL;
	CFile				*pSaveFile = NULL;
	
	UINT				nFileSize = 0;
	UINT				nFileSaveSize = 0;
	BOOL				bSuccess = TRUE;
	
	CString	strServerFullPathFileName = pszServerPath;
	strServerFullPathFileName += "/";
	strServerFullPathFileName += pszServerFileName;
    strServerFullPathFileName.Replace("\\", "/"); // HTTP������ \�� �����ʴ´�. RTPatch ���ο��� ���� ���ϸ��� \���� ��θ� ǥ���ϱ⶧���� /���� �������ش�.

	CString strClientFullPathFileName = pszClientPath;	
    if(strClientFullPathFileName.GetLength())
    {
        strClientFullPathFileName += "/";
    }
	strClientFullPathFileName += pszClientFileName;
    strClientFullPathFileName.Replace("\\", "/");

	try
	{
		pHttpConnection = INetSession.GetHttpConnection(pszServerName);
		pFile = pHttpConnection->OpenRequest( CHttpConnection::HTTP_VERB_GET,strServerFullPathFileName);
		pFile->SendRequest();
	
		DWORD dwRet;
		pFile->QueryInfoStatusCode(dwRet);

		BYTE downBuffer[1024];
        char szBuf[1024] = {0,};
		if (dwRet == HTTP_STATUS_OK)
		{
			pSaveFile = new CFile;

			//Directory�� ���� ��� File�� ���� �ȵ�, �ܺο��� Directory�� ������ �ְ� ����            
            CreateDirectoryFromFullPath(strClientFullPathFileName);

            CFileException ex;
			if(!pSaveFile->Open( strClientFullPathFileName, CFile::modeCreate | CFile::modeWrite, &ex ))
            {
                BOOL bResult = FALSE;
                char szBuf[1024] = {0,};                
                ex.GetErrorMessage(szBuf, sizeof(szBuf));     

                if(ex.m_cause == CFileException::accessDenied)
                {
                    // ������ �б������̾ ������ �������� �ִ�. �׷��� ������ �̸� �б������� �����Ѵ�.
                    CFileStatus fileStatus;
                    fileStatus.m_attribute = 0x00;
                    CFile::SetStatus(strClientFullPathFileName, fileStatus);
                    if(pSaveFile->Open( strClientFullPathFileName, CFile::modeCreate | CFile::modeWrite, &ex ))
                    {
                       bResult = TRUE;
                    }
                } 

                if(!bResult)
                {
                    INetSession.Close();
                    SetActive(FALSE);                    
                    return FALSE;
                }
            }

			TCHAR	chQueryBuffer[1024];
			DWORD	nQueryBuffer = 1024;
			pFile->QueryInfo( HTTP_QUERY_CONTENT_LENGTH, chQueryBuffer, &nQueryBuffer, NULL);
			nFileSize = _tstoi( chQueryBuffer );

			UINT nRead = 0;
			nRead = pFile->Read(downBuffer, 1024);
			while(nRead > 0)
			{
				nFileSaveSize += nRead;
				pSaveFile->Write( downBuffer, nRead);
				
				//Current ���¸� ������.
				EventDLCompleteThisFileMsg sDLCompleteThisFileMsg;
				sDLCompleteThisFileMsg.pszFileName = (char *)pszServerFileName;
				sDLCompleteThisFileMsg.uiFileSize = nFileSize;
				sDLCompleteThisFileMsg.uiComplete = nFileSaveSize;
				SendEvent(EVENT_DL_COMPLETE_THIS_FILE, &sDLCompleteThisFileMsg);
				
				SendEvent(EVENT_DL_DEAFULT_MSG_PUMP, NULL);

				if(GetAbort() == TRUE)
					break;
				nRead = pFile->Read(downBuffer, 1024);
			}
			
			if(GetAbort() == FALSE)
			{
				ASSERT( nFileSize == nFileSaveSize );
				//������ ����� ���� ������
				if(nFileSize != nFileSaveSize)
				{
					EventDLTextMsg sTextMsg;
					sTextMsg.pszMessage = (char *)pszServerFileName;
					SendEvent(EVENT_DL_ERROR_SERVER_FILE_DOWN, &sTextMsg);
					bSuccess = FALSE;
				}
			}

			pSaveFile->Close();
			if(pSaveFile != NULL)
			{
				delete pSaveFile;
				pSaveFile = NULL;
			}
		}	
		else
		{
			EventDLTextMsg sTextMsg;
			sTextMsg.pszMessage = (char *)pszServerFileName;
			SendEvent(EVENT_DL_ERROR_SERVER_FILE_DOWN, &sTextMsg);
			bSuccess = FALSE;
		}
		
		pFile->Close();
		delete pFile;

		pHttpConnection->Close();
		delete pHttpConnection;
	}
	catch(CInternetException *pEx)
	{
		//pEx->ReportError();
		SendEvent(EVENT_DL_ERROR_SERVER_CONNECT, NULL);
		pEx->Delete();
		bSuccess = FALSE;
	}

	INetSession.Close();
	SetActive(FALSE);

	if(GetAbort() == TRUE)
	{
		SetPendingDestroy(TRUE);
		bSuccess = TRUE;
	}
	
	return bSuccess;
}