/*****************************************************************************
 *
 * File			: NtlHttpDownLoader.h
 * Author		: HongHoDong
 * Copyright	: (��)NTL
 * Date			: 2007. 2. 5.
 * Abstract		: 
 *****************************************************************************
 * Desc         : Patch Process���� ��� �Ѵ�.
 *
 *****************************************************************************/
#pragma once
#include <string>
#include <set>
#include "DataType.h"
#include "NtlDownLoader.h"
#include "NtlPatchData.h"
#include "NtlPatcher.h"

#define EVENT_PM_ID_START					(LAUNCHER_EVENT_USER + 100000)
#define EVENT_PM_PENDING_DESTROY			(1001 + EVENT_PM_ID_START)

#define EVENT_PM_START						(1002 + EVENT_PM_ID_START)
#define EVENT_PM_COMPLETE					(1003 + EVENT_PM_ID_START)

#define	EVENT_PM_LAST_UPDATE_INFO			(1004 + EVENT_PM_ID_START)

struct EventPMLastUpdateInfoMsg
{
	const char *pClientVersion;
	const char *pLauncherVersion;    
};

typedef void* NTL_PATCH_MANAGER_CALL_BACK_HANDLE;

enum EPatchState
{
	PATCH_STATE_NONE,
	PATCH_STATE_NEW_LAUNCHER,
	PATCH_STATE_LAUNCHER,
};

class CNtlPatchManager
{
public:
	virtual ~CNtlPatchManager();

	template <class Callbackclass>	
	NTL_PATCH_MANAGER_CALL_BACK_HANDLE LinkEvent(Callbackclass *cbclass,int (Callbackclass::*callback)(unsigned int, unsigned int))
	{
		CNtlCallbackParam2 *pWidget = new CNtlCallbackWidget2<Callbackclass> (cbclass,callback);
		m_listCallBack.push_back(pWidget);
		return pWidget;
	}
	void UnLinkEvent(NTL_PATCHER_CALL_BACK_HANDLE handle);
	void SendEvent(unsigned int uiEventID, void *pParam);

public:
	BOOL	Create();
	void	Destroy();
	void	DoAction();

	void	DoLauncherPatch(const char *pszPatchFullPathFileName, unsigned int uiVersion);

	void	SetActive( BOOL bActive) { m_bActive = bActive; }
	BOOL	GetActive();

	void	SetAbort(BOOL bAbort);
	BOOL	GetAbort();
	
	void	SetPendingDestory(BOOL bPending) { ASSERT(GetActive() != TRUE); m_bPendingDestory = bPending; }
	BOOL	GetPendingDestory() { return m_bPendingDestory; }

	void	SetPatchState(EPatchState eState) { m_ePatchState = eState; }
	BOOL	GetPatchState() { return m_ePatchState; }
	
	virtual void DestroyInstance()
	{
		if(s_pInstance != NULL)
		{
			delete s_pInstance;
			s_pInstance = NULL;
		}
	}

	static CNtlPatchManager *GetInstance()
	{
		if(s_pInstance == NULL)
			s_pInstance = new CNtlPatchManager;

		ASSERT(s_pInstance != NULL);
		return s_pInstance;
	}

	int DownLoaderCallBack(unsigned int uiEventID, unsigned int pParam);
	int PatcherCallBack(unsigned int uiEventID, unsigned int pParam);

protected:
    // �̱��� Ŭ�����̱� ������ �������� ȣ���� ���´�.
    CNtlPatchManager();
    CNtlPatchManager(const CNtlPatchManager& rhs) {}

    BOOL CheckPatchEnable();                                ///< ���� ��ġ ������ ��ġ�� ������ ���������� Ȯ���Ѵ�.
    BOOL ProcessMissingFiles();                             ///< ��ġ�߿� ������ ���ϵ��� Ǯ���� �������� �ٿ� �޴´�.    

protected:
    std::list<CNtlCallbackParam2*> m_listCallBack;
    static CNtlPatchManager *s_pInstance;

    BOOL		m_bActive;
    BOOL		m_bAbort;
    BOOL		m_bPendingDestory;

    EPatchState	m_ePatchState;
    CNtlDownLoader		*m_pDownLoader;
    CNtlPatchHistory	*m_pPatchHistory;
    CNtlPatcher			*m_pPatcher;
    std::string         m_strCurrentPatchFileName;        ///< ���� ��ġ�ǰ� �ִ� ���ϸ�(��ġ���Ͼ��� ��������)    
    std::set<std::string> m_setErrFiles;                  ///< ������ ���ϵ��� ����Ʈ
};


