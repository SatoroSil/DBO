#include "Precomp_NtlPathEngine.h"
#include "NtlPathSeamlessLoadingManager.h"

#include <process.h>
#include <sstream>
#include "NtlSeamlessMesh.h"
#include "NtlPathEngineHelper.h"

// Test
#include "NtlPathEngineLog.h"

CNtlPathSeamlessLoadingManager::CNtlPathSeamlessLoadingManager()
{
	// Thread�� �����Ǿ����� Ȯ���ϱ� ���� �ο�
	m_bCreatedThread = false;
	m_hEventForThread = NULL;
	m_bExit = false;
	memset( m_ahThread, 0, sizeof( m_ahThread ) );
	memset( m_dwThreadID, 0, sizeof( m_dwThreadID ) );
}

CNtlPathSeamlessLoadingManager::~CNtlPathSeamlessLoadingManager()
{
	
}

bool CNtlPathSeamlessLoadingManager::Create()
{
	// �̺�Ʈ ����
	m_hEventForThread = CreateEvent( NULL, FALSE, FALSE, NULL );
	if( NULL == m_hEventForThread )
		return false;

	// ������δ� Ŭ���� ����
	if( !m_ThreadLoader.Create() )
		return false;

	// ������ ����
	for( int i = 0; i < eMAX_THREAD_CNT; ++i )
	{
		m_ahThread[i] = (HANDLE)_beginthreadex( 
			NULL,	// �ڵ��� ��� ���� ( NULL�� ��� ��󿡼� ���� )
			0,		// ������ ���� �� ������ ���û����� ( 0 �� Default 1MByte )
			&CNtlPathSeamlessLoader::ThreadFunc,	// ������� ������ �Լ�
			NULL,	// ������� ���޵Ǵ� �Ű������� ������
			0,		// �������� ���� �� ������ �����ϱ� ���� Flag
			NULL);	// ������ ID�� ���޹ޱ� ���� ������ �ּҰ�
	}

	m_bCreatedThread = true;
		
	return true;
}

void CNtlPathSeamlessLoadingManager::Update( float fElapsed )
{
	static float fTimeCheck = 0.f;
	fTimeCheck += fElapsed;

	if( fTimeCheck > 5.0f )
	{
		fTimeCheck = 0.0f;

		CNtlPathEngineLog::GetInstance()->Log("Reservation %d", m_listLoadReservation.size() );
	}

	// Reservation�� �ִ��� Ȯ���Ѵ�.
	// �ִٸ� Thread Event�� Signaled �� �����Ѵ�.
	// ���ٸ� Thread Event�� Reset�Ͽ� UnSignaled �� ���ư��� �Ѵ�.
	if( !m_listLoadReservation.empty() )
		SetThreadEvent();
	else
		ResetThreadEvent();

}

void CNtlPathSeamlessLoadingManager::Destroy()
{
	if( m_bCreatedThread )
	{
		// ���Ḧ �������ְ�
		SetExit();
		
		// Event�� �����Ų��. ( �׷����� ThreadLoader�� ����Ǿ����� �˻��� �� �ִ�. )
		SetThreadEvent();

		// ��� �����尡 ���� ������ ��ٸ���.
		WaitForMultipleObjectsEx( eMAX_THREAD_CNT, m_ahThread, TRUE, INFINITE, FALSE );

		for( int i=0; i < eMAX_THREAD_CNT; ++i )
		{
			if( m_ahThread[i] )
			{
				CloseHandle( m_ahThread[i] );
				m_ahThread[i] = NULL;
			}
		}

		if( m_hEventForThread )
		{
			CloseHandle( m_hEventForThread );
			m_hEventForThread = NULL;
		}

		m_bExit = false;
		m_bCreatedThread = false;
	}
}

void CNtlPathSeamlessLoadingManager::LoadReservation( CNtlSeamlessMesh* pMesh )
{
	m_ReservationCS.Lock();

	// Make key name
	std::ostringstream keyname;
	keyname << pMesh->GetWorldIndex();
	keyname << "_";
	keyname << pMesh->GetFieldIndex();
	keyname << "_";
	keyname << pMesh->GetTileIndex();
	
	// ���� �Ǿ� �ְų� �ε��� �Ϸ� �Ǿ� ������ �߰����� �ʴ´�.
	mapdef_seamMesh::iterator reserIt = m_mapLoadReservation.find( keyname.str().c_str() );
	mapdef_seamMesh::iterator loadedIt = m_mapLoaded.find( keyname.str().c_str() );
	if( reserIt == m_mapLoadReservation.end() &&
		loadedIt == m_mapLoaded.end() )
	{
		m_mapLoadReservation.insert( std::make_pair( keyname.str(), pMesh ) );
		m_listLoadReservation.push_back( pMesh );
	}

	m_ReservationCS.Unlock();
}

CNtlSeamlessMesh* CNtlPathSeamlessLoadingManager::GetLoadReservation()
{
	m_ReservationCS.Lock();
	if( m_listLoadReservation.empty() )
	{
		m_ReservationCS.Unlock();
		return NULL;
	}

	

	CNtlSeamlessMesh* pMesh = (CNtlSeamlessMesh*)m_listLoadReservation.front();
	m_listLoadReservation.pop_front();

	std::ostringstream keyname;
	keyname << pMesh->GetWorldIndex();
	keyname << "_";
	keyname << pMesh->GetFieldIndex();
	keyname << "_";
	keyname << pMesh->GetTileIndex();
	mapdef_seamMesh::iterator reserIt = m_mapLoadReservation.find( keyname.str().c_str() );
	if( reserIt != m_mapLoadReservation.end() )
		m_mapLoadReservation.erase( reserIt );

	m_ReservationCS.Unlock();

	return pMesh;
}

void CNtlPathSeamlessLoadingManager::Loaded( CNtlSeamlessMesh* pMesh )
{
	m_LoadedCS.Lock();
	
	// Make key name
	std::ostringstream keyname;
	keyname << pMesh->GetWorldIndex();
	keyname << "_";
	keyname << pMesh->GetFieldIndex();
	keyname << "_";
	keyname << pMesh->GetTileIndex();

	// �̹� �ε�Ǿ� �ִٸ� �����ϰ� �ε�Ǿ� ���� �ʴٸ� �߰��Ѵ�.
	mapdef_seamMesh::iterator loadedIt = m_mapLoaded.find( keyname.str().c_str() );
	if( loadedIt == m_mapLoaded.end() )
	{
		m_mapLoaded.insert( std::make_pair( keyname.str(), pMesh ) );
		m_listLoaded.push_back( pMesh );
	}
	else
	{
		delete pMesh;
		pMesh = NULL;
	}

	m_LoadedCS.Unlock();
}

CNtlSeamlessMesh* CNtlPathSeamlessLoadingManager::GetLoadedMesh()
{
	m_LoadedCS.Lock();

	if( m_listLoaded.empty() )
	{
		m_LoadedCS.Unlock();
		return NULL;
	}

	CNtlSeamlessMesh* pMesh = (CNtlSeamlessMesh*)m_listLoaded.front();
	m_listLoaded.pop_front();

	std::ostringstream keyname;
	keyname << pMesh->GetWorldIndex();
	keyname << "_";
	keyname << pMesh->GetFieldIndex();
	keyname << "_";
	keyname << pMesh->GetTileIndex();
	mapdef_seamMesh::iterator loadedIt = m_mapLoaded.find( keyname.str().c_str() );
	if( loadedIt != m_mapLoaded.end() )
		m_mapLoaded.erase( loadedIt );


	m_LoadedCS.Unlock();

	return pMesh;
}

HANDLE CNtlPathSeamlessLoadingManager::GetEvent()
{
	m_EventCS.Lock();
	HANDLE hEvent = m_hEventForThread;
	m_EventCS.Unlock();

	return hEvent;
}

void CNtlPathSeamlessLoadingManager::SetExit( void )
{
	m_ExitCS.Lock();
	m_bExit = true;
	m_ExitCS.Unlock();
}

bool CNtlPathSeamlessLoadingManager::IsExit( void )
{
	m_ExitCS.Lock();
	bool bExit = m_bExit;
	m_ExitCS.Unlock();

	return bExit;
}

void CNtlPathSeamlessLoadingManager::ResetThreadEvent()
{
	m_EventCS.Lock();
	ResetEvent( m_hEventForThread );
	m_EventCS.Unlock();
}

void CNtlPathSeamlessLoadingManager::SetThreadEvent()
{
	m_EventCS.Lock();
	SetEvent( m_hEventForThread );
	m_EventCS.Unlock();
}

void CNtlPathSeamlessLoadingManager::RemoveReservationByRangeOver( cHorizontalRange& range )
{
	m_ReservationCS.Lock();
	listdef_seamMesh::iterator it = m_listLoadReservation.begin();
	while( it != m_listLoadReservation.end() )
	{
		CNtlSeamlessMesh* pMesh = (*it);

		// �����.
		if( !NTLPE_RangesOverlap( pMesh->GetRangeAtWorld(), range ) )
		{
			// KeyName���� Map������ ����
			std::ostringstream keyname;
			keyname << pMesh->GetWorldIndex();
			keyname << "_";
			keyname << pMesh->GetFieldIndex();
			keyname << "_";
			keyname << pMesh->GetTileIndex();
			mapdef_seamMesh::iterator reserIt = m_mapLoadReservation.find( keyname.str().c_str() );
			if( reserIt != m_mapLoadReservation.end() )
				m_mapLoadReservation.erase( reserIt );

			// ������ ����
			delete pMesh;
			pMesh = NULL;

			it = m_listLoadReservation.erase( it );
		}
		else
		{
			it++;
		}
	}
	
	m_ReservationCS.Unlock();
}