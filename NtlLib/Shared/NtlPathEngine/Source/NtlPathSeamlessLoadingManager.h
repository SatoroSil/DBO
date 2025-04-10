/*****************************************************************************
* File			: NtlPathSeamlessLoadingManager.h
* Author		: Haesung, Cho
* Copyright		: (��)NTL
* Date			: 2009. 03. 19
* Abstract		: Pathengine seamless loading manager
*****************************************************************************
* Desc:
*
*****************************************************************************/

#ifndef _NTL_PATH_SEAMLESS_LOADING_MANAGER_H_
#define _NTL_PATH_SEAMLESS_LOADING_MANAGER_H_

#include "NtlPathCS.h"
#include "NtlPathSeamlessLoader.h"

#include <list>

class CNtlSeamlessMesh;
class CNtlPathSeamlessLoadingManager
{
public:
	enum { eMAX_THREAD_CNT = 1 };

	typedef std::map < std::string, CNtlSeamlessMesh* > mapdef_seamMesh;
	typedef std::list < CNtlSeamlessMesh* > listdef_seamMesh;

protected:
	CNtlPathSeamlessLoadingManager();

public:
	~CNtlPathSeamlessLoadingManager();

	static CNtlPathSeamlessLoadingManager* GetInstance()
	{
		static CNtlPathSeamlessLoadingManager instance;
		return &instance;
	}

	bool	Create();
	void	Update( float fElapsed );
	void	Destroy();

	// �ε� ������ �Ѵ�.
	void	LoadReservation( CNtlSeamlessMesh* pMesh );

	// ���� ���� �ε� ���� �� ���� �����´�.
	CNtlSeamlessMesh*	GetLoadReservation();

	// �ε� ����Ǿ� �ִ� �͵� �߿� �Ÿ����� ��� Tile���� �����Ѵ�.
	void	RemoveReservationByRangeOver( cHorizontalRange& range );

	// �Ϸᰡ �Ǿ��ٴ� ���� �˸���.
	void	Loaded( CNtlSeamlessMesh* pMesh );
	
	// ���� ���� �ε� �Ϸ�� ���� �����´�.
	CNtlSeamlessMesh*	GetLoadedMesh();

	HANDLE				GetEvent();
	void				ResetThreadEvent();
	void				SetThreadEvent();

	void	SetExit(void);
	bool	IsExit(void);

protected:
	CNtlPathCS			m_ReservationCS;
	mapdef_seamMesh		m_mapLoadReservation;
	listdef_seamMesh	m_listLoadReservation;	// ������ �����ϱ� ����

	CNtlPathCS			m_LoadedCS;
	mapdef_seamMesh		m_mapLoaded;
	listdef_seamMesh	m_listLoaded;

	// Thread�� �����ϱ� ���� �̺�Ʈ

	CNtlPathCS			m_EventCS;
	HANDLE				m_hEventForThread;

	// Thread�� Handle
	HANDLE				m_ahThread[eMAX_THREAD_CNT];
	DWORD				m_dwThreadID[eMAX_THREAD_CNT];

	// Thread�� �����Ǿ����� Ȯ���ϱ� ���� �ο�
	bool				m_bCreatedThread;
	
	// �� ��ü�� Destroy �� �Ǿ��ٴ� ���� �˸�
	CNtlPathCS			m_ExitCS;
	bool				m_bExit;

	// ThreadLoader
	CNtlPathSeamlessLoader	m_ThreadLoader;
};

static CNtlPathSeamlessLoadingManager* GetNtlPathEngineLoadingManager()
{
	return CNtlPathSeamlessLoadingManager::GetInstance();
}

#endif