#include "Precomp_NtlPathEngine.h"
#include "NtlPathSeamlessManager.h"

// Define
#include "NtlPathEngineDef.h"

// PathEngine
#include "NtlPathEngine.h"

// Log
#include "NtlPathEngineLog.h"

// MeshFederation
#include "NtlMeshFederation.h"
#include "NtlMeshFederationContainer.h"

// Helper
#include "NtlPathEngineHelper.h"

// Test
#include "PerformanceChecker.h"

// STL
#include <fstream>
#include <sstream>



//////////////////////////////////////////////////////////////////////////
// CNtlPathSeamlessManager class
//////////////////////////////////////////////////////////////////////////

CNtlPathSeamlessManager::CNtlPathSeamlessManager()
{
	m_nCurrentWorldIndex = NTLPE_INVALID_WORLDINDEX;
	m_nSeamlessRange = NTLPE_DEFAULT_SEAMLESSRANGE;
	m_bIsStart = false;
	m_nCurrentPositionX = 0;
	m_nCurrentPositionY = 0;
}

CNtlPathSeamlessManager::~CNtlPathSeamlessManager()
{
	Destroy();	
}

bool CNtlPathSeamlessManager::Create()
{
	if( !CNtlPathSeamlessLoadingManager::GetInstance()->Create() )
	{

		return false;
	}

	return true;
}

void CNtlPathSeamlessManager::Update( float fElapsed )
{
	CNtlPathSeamlessLoadingManager::GetInstance()->Update( fElapsed );

	// �ε��� �Ϸ�� �޽ð� �ִ�.
	CNtlSeamlessMesh* pMesh = CNtlPathSeamlessLoadingManager::GetInstance()->GetLoadedMesh();
	if( pMesh )
	{
		// ���� ���� Ÿ���� �ε�Ǿ� �ִٸ� �����ϰ� �����Ѵ�.
		if( IsLoadedMesh( pMesh ) )
		{
			delete pMesh;
			pMesh = NULL;

			return;
		}

		// ���� World Index�� �ٸ� ���� Ÿ���̶�� ����
		if( m_nCurrentWorldIndex != pMesh->GetWorldIndex() )
		{
			delete pMesh;
			pMesh = NULL;

			return;
		}

		// ���� Seamless Range���� ��� �ִٸ� �����ϰ� �����Ѵ�.
		if( IsSeamlessRangeOver( pMesh ) )
		{
			delete pMesh;
			pMesh = NULL;

			return;
		}

		m_listMesh.push_back( pMesh );
	}

	// Test
	static float fTimer = 0.0f;
	fTimer += fElapsed;

	// 1�ʿ� �ѹ��� ���� ���
	if( fTimer > 5.0f )
	{
		fTimer = 0.0f;

		CNtlPathEngineLog::GetInstance()->Log( "Current loaded mesh : %d", m_listMesh.size() );

		/*CNtlPathSeamlessLoadingManager::GetInstance()->*/
		/*printf_s( "[TICK] Current loaded mesh : %d\tTotal Memory allocated : %u byte\n", m_listMesh.size(), GetNtlPathEngine()->GetPathEngine()->totalMemoryAllocated() );*/
	}
}

void CNtlPathSeamlessManager::Destroy()
{
	ClearSeamlessMesh();
	ClearMeshFederationContainer();

	CNtlPathSeamlessLoadingManager::GetInstance()->Destroy();
}

void CNtlPathSeamlessManager::ClearMeshFederationContainer( void )
{
	// Federation list�� �����ش�.
	for each( std::pair < int, CNtlMeshFederationContainer* > pair in m_mapWorldPath )
	{
		if( pair.second )
		{
			delete pair.second;
			pair.second = NULL;
		}
	}

	m_mapWorldPath.clear();
}

void CNtlPathSeamlessManager::ClearSeamlessMesh( void )
{
	for each( CNtlSeamlessMesh* mesh in m_listMesh )
	{
		if( mesh )
		{
			delete mesh;
			mesh = NULL;
		}
	}

	m_listMesh.clear();
}

void CNtlPathSeamlessManager::AddAgentSize( int nAgnetSize )
{
	// �˻��غ��� ������ �ִ´�.
	for each( int nOldSize in m_vecAgentSize )
	{
		if( nOldSize == nAgnetSize )
			return;
	}

	m_vecAgentSize.push_back( nAgnetSize );
}


void CNtlPathSeamlessManager::Start( int nWorldIndex )
{
	if( m_bIsStart == false )
		m_bIsStart = true;

	ChangeWorld( nWorldIndex );
}

void CNtlPathSeamlessManager::Stop()
{
	if( m_bIsStart == true )
		m_bIsStart = false;
}

void CNtlPathSeamlessManager::ChangeWorld( int nWorldIndex )
{
	if( !m_bIsStart )
		m_bIsStart = true;

	// �ε� ���� �ʾҴ� WorldIndex��� MeshFederation header�� �о�鿩�´�.
	if( !IsLoadedWorld( nWorldIndex ) )
		LoadWorldMeshFederation( nWorldIndex );
	
	// ���� �ִ� World�� Change�Ǵ� World �� Index�� �ٸ��ٸ�
	if( m_nCurrentWorldIndex != nWorldIndex )
	{
		m_nCurrentWorldIndex = nWorldIndex;
		ClearSeamlessMesh();
	}

}

bool CNtlPathSeamlessManager::IsLoadedWorld( int nWorldIndex )
{
	mapdef_WorldMeshFederation::iterator it = m_mapWorldPath.find( nWorldIndex );
	if( it == m_mapWorldPath.end() )
	{
		return false;
	}

	return true;
}

int CNtlPathSeamlessManager::GetLoadedWorldSize()
{
	return (int)m_mapWorldPath.size();
}

bool CNtlPathSeamlessManager::IsLoadedMesh( CNtlSeamlessMesh* pMesh )
{
	for each( CNtlMesh* mesh in m_listMesh )
	{
		if( mesh )
		{
			if( mesh->GetWorldIndex() == pMesh->GetWorldIndex() &&
				mesh->GetFieldIndex() == pMesh->GetFieldIndex() &&
				mesh->GetTileIndex() == pMesh->GetTileIndex() )
			{
				return true;
			}
		}
	}

	return false;
}

bool CNtlPathSeamlessManager::IsLoadedMesh( int nWorldIndex, int nFieldIndex, int nTileIndex )
{
	for each( CNtlMesh* mesh in m_listMesh )
	{
		if( mesh )
		{
			if( nWorldIndex == mesh->GetWorldIndex() &&
				nFieldIndex == mesh->GetFieldIndex() &&
				nTileIndex == mesh->GetTileIndex() )
			{
				return true;
			}
		}
	}

	return false;
}

bool CNtlPathSeamlessManager::IsSeamlessRangeOver( CNtlSeamlessMesh* pMesh )
{
	cHorizontalRange seamRange;
	seamRange.maxX = m_nCurrentPositionX + m_nSeamlessRange;
	seamRange.maxY = m_nCurrentPositionY + m_nSeamlessRange;
	seamRange.minX = m_nCurrentPositionX - m_nSeamlessRange;
	seamRange.minY = m_nCurrentPositionY - m_nSeamlessRange;

	// �������� ��ġ���� �� ��ġ���� Ȯ���Ѵ�.
	return !NTLPE_RangesOverlap( pMesh->GetRangeAtWorld(), seamRange );
}

bool CNtlPathSeamlessManager::UpdatePosition( int nPositionX, int nPositionY, int nPositionZ /*= 0*/ )
{
	// SeamlessManager�� �����ǰ� ���� �ʰų� World�� INVALID �� ����Ű�� �ִٸ� Update�� ���� ���Ѵ�.
	if( !m_bIsStart )
		return false;

	if( NTLPE_INVALID_WORLDINDEX == m_nCurrentWorldIndex  )
		return false;

	// UpdatePosition
	m_nCurrentPositionX = nPositionX;
	m_nCurrentPositionY = nPositionY;
	m_nCurrentPositionZ = nPositionZ;

	// Overlapped�Ǵ� MeshFederation Header���� World������ �о�´�.
	std::list < CNtlMeshFederation* > listOverlapped;
	
	// Agent�� Seamless ������ �����ϰ� �� Tile��� ��ġ�� �� Ȯ���Ѵ�.
	cHorizontalRange agentRange, tileRange, tileLocalRange;
	agentRange.maxX = nPositionX + m_nSeamlessRange;
	agentRange.maxY = nPositionY + m_nSeamlessRange;
	agentRange.minX = nPositionX - m_nSeamlessRange;
	agentRange.minY = nPositionY - m_nSeamlessRange;

	FindOverlappedMeshFederationByRange( agentRange, listOverlapped );

	int nTotalCount = 0;
	int nLoadCount = 0;
	int nOverlapCount = 0;

	int nAllCount = 0;
	int nOneCount = 0;

	for each( CNtlMeshFederation* mf in listOverlapped )
	{
		nAllCount += mf->GetTileCount();
	}

	listdef_NtlSeamlessMesh listSeam;
	// ��ġ�� Ÿ���� ����Ʈ�� �ۼ��Ѵ�.
	for each( CNtlMeshFederation* mf in listOverlapped )
	{
		for( int i=0; i < mf->GetTileCount(); ++i )
		{
			// Ÿ���� ������ ���� �´�.
			mf->getRepresentedRegion_World( i, tileRange );
			mf->getRepresentedRegion_Local( i, tileLocalRange );

			long nCenterAtWorldX;
			long nCenterAtWorldY;
			mf->getTileCenter( i, nCenterAtWorldX, nCenterAtWorldY );

			// Ÿ���� ������ ��ġ���� Ȯ���Ѵ�.
			if( NTLPE_RangesOverlap( agentRange, tileRange ) )
			{
				nOverlapCount++;

				// �̹� ���� �Ѵٸ� ����Ʈ�� ���� �ʰ� �Ѿ��.
				if( IsLoadedMesh( m_nCurrentWorldIndex, mf->GetFieldIndex(), i ) )
					continue;

				// ����Ʈ�� ��´�.
				CNtlSeamlessMesh* pMesh = CreateSeamlessMesh( m_nCurrentWorldIndex, mf->GetFieldIndex(), i, tileRange, tileLocalRange
					,nCenterAtWorldX, nCenterAtWorldY);
				
				for each( int nAgentSize in m_vecAgentSize )
				{
					pMesh->AddAgent( nAgentSize );
				}

				pMesh->SetLoadRange( NTLPE_RangesLengthTo( agentRange, tileRange ));

				listSeam.push_back( pMesh );
			}
		}
	}

	// �־��� �� �Լ��� �˸°� �����Ѵ�.
	listSeam.sort(CNtlPathSeamlessManager::SortSeamlessMeshCompare);

	// ������ �ε� Queue�� ����ش�.
	for each( CNtlSeamlessMesh* pMesh in listSeam )
		CNtlPathSeamlessLoadingManager::GetInstance()->LoadReservation( pMesh );

	// ���� �ε�Ǿ� �ִ� Mesh�߿��� �Ÿ��� ��� �͵� ����
	listdef_NtlSeamlessMesh::iterator it = m_listMesh.begin();
	while( it != m_listMesh.end() )
	{
		CNtlSeamlessMesh* pMesh = (*it);

		if( !pMesh->IsRangeOverlapped( agentRange ) )
		{
			delete pMesh;
			pMesh = NULL;

			it = m_listMesh.erase( it );
		}
		else
		{
			it++;
		}
	}

	// �ε� ���� �Ǿ� �ִ� �͵� �߿��� �Ÿ��� ��� �͵� ����
	CNtlPathSeamlessLoadingManager::GetInstance()->RemoveReservationByRangeOver( agentRange );

	return true;
}


iPath* CNtlPathSeamlessManager::FindShortestPath( int nAgentSize, 
												 int nSrcPositionX, int nSrcPositionY, int nSrcPositionZ,
												 int nDestPositionX, int nDestPositionY, int nDestPositionZ,
												 std::list< cPosition >& listPath)
{
	// ���� �ε� �� Tile �߿� src �� dest�� �� �����ϰ� �ִ� Tile�� ã�Ƴ���.
	// Src X �� Dest X �� Min Max X �� ������
	cHorizontalRange rangeTarget;
	
	if( nSrcPositionX < nDestPositionX )
	{
		rangeTarget.maxX = nDestPositionX;
		rangeTarget.minX = nSrcPositionX;
	}
	else
	{
		rangeTarget.maxX = nSrcPositionX;
		rangeTarget.minX = nDestPositionX;
	}

	if( nSrcPositionY < nDestPositionY )
	{
		rangeTarget.maxY = nDestPositionY;
		rangeTarget.minY = nSrcPositionY;
	}
	else
	{
		rangeTarget.maxY = nSrcPositionY;
		rangeTarget.minY = nDestPositionY;
	}

	for each( CNtlSeamlessMesh* pMesh in m_listMesh )
	{
		if( !pMesh->IsLoad() )
			continue;

		// ���� Source�� Dest�� ���Ե� ������ �� �����ϰ� �ִ� Ÿ���� �ִٸ�
		if( NTLPE_RangesInclusion( pMesh->GetRangeAtWorld(), rangeTarget ) )
		{
			// Source �� �������� ���Ѵ�. Tile�� ���� Local��ǥ�� ������ �����Ƿ� Local ��ǥ�� ��ȯ���ش�.
			nSrcPositionX = nSrcPositionX - pMesh->GetTileCenterAtWorldX();
			nSrcPositionY = nSrcPositionY - pMesh->GetTileCenterAtWorldY();
			// ���̰��� ��ȯ���� �ʴ´�.


			long point[]={nSrcPositionX,nSrcPositionY,nSrcPositionZ};
			cPosition cSourcePos = pMesh->GetMesh()->positionNear3DPoint(point, NTLPE_DEFAULT_HORIZ_RANGE, NTLPE_DEFAULT_VERT_RANGE);
			if(cSourcePos.cell==-1)
			{
				CNtlPathEngineLog::GetInstance()->handle( "NonFatal", "Incorrect position from positionFor3DPoint().", 0);
				return NULL;
			}

			// Dest�� ������ ( ���÷� ��ȯ )
			nDestPositionX = nDestPositionX - pMesh->GetTileCenterAtWorldX();
			nDestPositionY = nDestPositionY - pMesh->GetTileCenterAtWorldY();

			long destPoint[] = {nDestPositionX, nDestPositionY, nDestPositionZ };
			cPosition cTargetPos = pMesh->GetMesh()->positionNear3DPoint( destPoint, NTLPE_DEFAULT_HORIZ_RANGE, NTLPE_DEFAULT_VERT_RANGE);
			if(cTargetPos.cell==-1)
			{
				CNtlPathEngineLog::GetInstance()->handle( "NonFatal", "Incorrect position from positionFor3DPoint().", 0);
				return NULL;
			}

			iPath* pPath = pMesh->FindShortestPath( nAgentSize, cSourcePos, cTargetPos );

			if( pPath )
			{
				for( unsigned int i =0; i < pPath->size(); ++i )
				{
					cPosition pos = pPath->position( i );

					// World�� ��ȯ
					pos.x += pMesh->GetTileCenterAtWorldX();
					pos.y += pMesh->GetTileCenterAtWorldY();

					listPath.push_back( pos );			
				}
			}

			return pPath;
		}
	}

	return NULL;
}

CNtlSeamlessMesh* CNtlPathSeamlessManager::LoadSeamlessMesh( int nWorldIndex, int nFieldIndex, int nTileIndex, cHorizontalRange& rangeAtWorld, cHorizontalRange& rangeAtLocal
															,int nCenterAtWorldX, int nCenterAtWorldY)
{
	char acTileName[NTLPE_MAX_FILENAME_LENGTH+1];
	sprintf_s( acTileName, NTLPE_MAX_FILENAME_LENGTH+1, "%d/%d_f%d", nWorldIndex, nFieldIndex, nTileIndex );

	// (WorldIndex)/(FieldIdx)_f(TileIndex).mf
	std::ostringstream filename;
	filename << acTileName;
	filename << NTLPE_DATA_EXTENSION;

	char* buffer;
	unsigned long size;

	// Load Tile
	buffer = NTLPE_LoadBinary_AllocatedBuffer( filename.str().c_str(), size );
	if( !buffer )
		return NULL;

	iMesh* mesh = GetNtlPathEngine()->GetPathEngine()->loadMeshFromBuffer( NTLPE_DATA_FORMAT, buffer, size, 0 );
	NTLPE_FreeBuffer( buffer );

	// Load Preprocess Infos
	for each ( int nAgentSize in m_vecAgentSize )
	{
		// Load collision preprocess data
		// (WorldIndex)/(FieldIdx)_f(TileIndex)_(agentSize).cf
		std::ostringstream cfname;
		cfname << acTileName;
		cfname << "_" << nAgentSize;
		cfname << NTLPE_DATA_EXTENSION_PRE_COLLISION;

		char* cfBuffer;
		unsigned long cfSize;
		cfBuffer = NTLPE_LoadBinary_AllocatedBuffer( cfname.str().c_str(), cfSize );

		if( !cfBuffer )
		{
			CNtlPathEngineLog::GetInstance()->Log( "failed to load collision preprocess infomantion by %s", cfname.str().c_str() );
			continue;
		}
		NTLPE_FreeBuffer( cfBuffer );

		// Load pathfind preprocess data
		// (WorldIndex)/(FieldIdx)_f(TileIndex)_(agentSize).pf
		std::ostringstream pfname;
		pfname << acTileName;
		pfname << "_" << nAgentSize;
		pfname << NTLPE_DATA_EXTENSION_PRE_PATHFIND;

		char* pfBuffer;
		unsigned long pfSize;
		pfBuffer = NTLPE_LoadBinary_AllocatedBuffer( pfname.str().c_str(), pfSize );

		if( !pfBuffer )
		{
			CNtlPathEngineLog::GetInstance()->Log( "failed to load pathfind preprocess infomantion by %s", pfname.str().c_str() );
			continue;
		}
		NTLPE_FreeBuffer( pfBuffer );
	}

	// Create collision context
	iCollisionContext* pCollisionContext = mesh->newContext();

	CNtlSeamlessMesh* pMesh = new CNtlSeamlessMesh( nWorldIndex, nFieldIndex, nTileIndex, rangeAtWorld,
		rangeAtLocal, 
		nCenterAtWorldX, nCenterAtWorldY,
		mesh, pCollisionContext );

	return pMesh;
}

CNtlSeamlessMesh* CNtlPathSeamlessManager::CreateSeamlessMesh( int nWorldIndex, int nFieldIndex, int nTileIndex, cHorizontalRange& rangeAtWorld, cHorizontalRange& rangeAtLocal
															  ,int nCenterAtWorldX, int nCenterAtWorldY)
{
	CNtlSeamlessMesh* pMesh = new CNtlSeamlessMesh( nWorldIndex, nFieldIndex, nTileIndex, rangeAtWorld, rangeAtLocal,
		nCenterAtWorldX, nCenterAtWorldY);

	return pMesh;
}

CNtlMeshFederationContainer* CNtlPathSeamlessManager::CreateMeshFederationContainer( int nWorldIndex )
{
	mapdef_WorldMeshFederation::iterator it =  m_mapWorldPath.find( nWorldIndex );
	if( it == m_mapWorldPath.end() )
	{
		// ������ ���� �߰� �ϰ� ����
		CNtlMeshFederationContainer* federation = new CNtlMeshFederationContainer(nWorldIndex);
		m_mapWorldPath.insert( std::make_pair( nWorldIndex, federation ) );

		return federation;
	}
	else
	{
		// �ִٸ� �׳� ����
		CNtlMeshFederationContainer* federation = (*it).second;

		return federation;
	}
}

bool CNtlPathSeamlessManager::LoadWorldMeshFederation( int nWorldIndex )
{
	// nWorldIndex �̸��� ���� �������� worldinfo.txt�� �о�´�.
	std::ostringstream filename;

	// (WorldIndex)/worldinfo.txt
	char acFolder[NTLPE_MAX_FILENAME_LENGTH+1];
	_itoa_s( nWorldIndex, acFolder, NTLPE_MAX_FILENAME_LENGTH+1, 10 );
	filename << acFolder;
	filename << "/";
	filename << NTLPE_FILE_WORLDINFO;
	filename << NTLPE_DATA_EXTENSION_SCRIPT;

	CNtlSimpleDOM worldinfoScript;
	{
		std::ifstream is( filename.str().c_str() );
		if( !is.good() )
		{
			// Error
			CNtlPathEngineLog::GetInstance()->Log("Could not open worldinfo script. %s", filename.str().c_str() );
			return false;
		}

		CNtlSimpleDOM::LoadWhiteSpaceDelimited( is, worldinfoScript );
	}

	// Scirpt �� ��� �ʵ� �������� �о�´�.
	if( !LoadWorldMeshFederationByInfoScript( nWorldIndex, worldinfoScript ) )
		return false;

	return true;
}

bool CNtlPathSeamlessManager::LoadWorldMeshFederationByInfoScript( int nWorldIndex, const CNtlSimpleDOM& worldinfoScript )
{
	// worldinfoScript._name ������ Ȱ���ؼ� Version Check �� Format üũ ���� �Ѵ�.

	// ��ũ��Ʈ�� �����߰� ����� �����Ѵٸ� Federation Container�� �����ϰ�
	// ��ũ��Ʈ�� �˸��� Field data���� �ε��Ѵ�.
	CNtlMeshFederationContainer* federation = CreateMeshFederationContainer( nWorldIndex );

	for( int i=0; i < (int)worldinfoScript._children.size(); ++i )
	{
		const CNtlSimpleDOM& instanceDOM = worldinfoScript._children[i];
		if( instanceDOM._name == "field" )
		{
			const std::string strFieldIndex = instanceDOM.getAttribute("index");
			federation->AddFederation( strFieldIndex.c_str() );
		}
	}

	return true;
}

void CNtlPathSeamlessManager::FindOverlappedMeshFederation( int nPositionX, int nPositionY, int nPositionZ, std::list< CNtlMeshFederation* >& listOverlapped )
{
	if( NTLPE_INVALID_WORLDINDEX == m_nCurrentWorldIndex )
		return;

	mapdef_WorldMeshFederation::iterator it = m_mapWorldPath.find( m_nCurrentWorldIndex );
	if( it == m_mapWorldPath.end() )
	{
		CNtlPathEngineLog::GetInstance()->Log( "Failed to query find overlapped mesh federationheader [WORLD %d]", m_nCurrentWorldIndex );
		return;
	}

	CNtlMeshFederationContainer* faderationContainer = (CNtlMeshFederationContainer*)(*it).second;
	faderationContainer->FindOverlappedMeshFederation( nPositionX, nPositionY, listOverlapped );
}

void CNtlPathSeamlessManager::FindOverlappedMeshFederationByRange( cHorizontalRange range, std::list < CNtlMeshFederation* >& listOverlapped )
{
	if( NTLPE_INVALID_WORLDINDEX == m_nCurrentWorldIndex )
		return;

	mapdef_WorldMeshFederation::iterator it = m_mapWorldPath.find( m_nCurrentWorldIndex );
	if( it == m_mapWorldPath.end() )
	{
		CNtlPathEngineLog::GetInstance()->Log( "Failed to query find overlapped mesh federationheader [WORLD %d]", m_nCurrentWorldIndex );
		return;
	}

	CNtlMeshFederationContainer* faderationContainer = (CNtlMeshFederationContainer*)(*it).second;
	faderationContainer->FindOverlappedMeshFederationByRange( range, listOverlapped );
}


void CNtlPathSeamlessManager::GetAgentList( std::vector< int >& listAgent )
{
	listAgent = m_vecAgentSize;
}

bool CNtlPathSeamlessManager::SortSeamlessMeshCompare( CNtlSeamlessMesh* pLeft, CNtlSeamlessMesh* pRight )
{
	return pLeft->GetLoadRange() < pRight->GetLoadRange();
}