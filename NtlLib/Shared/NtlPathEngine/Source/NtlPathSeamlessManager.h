/*****************************************************************************
* File			: NtlPathEngineHelper.h
* Author		: Haesung, Cho
* Copyright		: (��)NTL
* Date			: 2009. 03. 16
* Abstract		: NTL Pathengine seamless loading/pathfinding module
*****************************************************************************
* Desc:
*
* ���� agent position�� �������� ���� ����� ��ġ�� Tile �� ���� �ε��Ͽ� list�� �־� ���´�.
* 03. 16 ���� ���� �ۼ���
*****************************************************************************/

#ifndef _NTL_PATH_SEAMLESS_H_
#define _NTL_PATH_SEAMLESS_H_

#include "../PathEngine/i_pathengine.h"
#include "NtlSeamlessMesh.h"
#include "NtlSimpleDOM.h"
#include "NtlPathSeamlessLoadingManager.h"

class CNtlMeshFederation;
class CNtlMeshFederationContainer;

class CNtlPathSeamlessManager
{
public:
	CNtlPathSeamlessManager();
	~CNtlPathSeamlessManager();

	bool	Create();
	void	Update( float fElapsed );
	void	Destroy();

	void	ClearMeshFederationContainer( void );
	void	ClearSeamlessMesh( void );

	void	AddAgentSize( int nAgnetSize );
	void	GetAgentList( std::vector< int >& listAgent );

	void	Start( int nWorldIndex );
	void	Stop( void );

	// Change World
	void	ChangeWorld( int nWorldIndex );
	bool	IsLoadedWorld( int nWorldIndex );
	int		GetLoadedWorldSize();

	// Mesh ����
	bool	IsLoadedMesh( CNtlSeamlessMesh* pMesh );
	bool	IsLoadedMesh( int nWorldIndex, int nFieldIndex, int nTileIndex );

	bool	IsSeamlessRangeOver( CNtlSeamlessMesh* pMesh );

	bool	UpdatePosition( int nPositionX, int nPositionY, int nPositionZ = 0);
	
	// Path ��û �Լ�
	iPath*	FindShortestPath( int nAgentSize, int nSrcPositionX, int nSrcPositionY,
		int nSrcPositionZ, int nDestPositionX, int nDestPositionY , int nDestPositionZ,
		std::list<cPosition>& listPath);

protected:
	CNtlSeamlessMesh*	LoadSeamlessMesh( int nWorldIndex, int nFieldIndex, int nTileIndex, cHorizontalRange& rangeAtWorld, cHorizontalRange& rangeAtLocal, int nCenterAtWorldX, int nCenterAtWorldY );
	CNtlSeamlessMesh*	CreateSeamlessMesh( int nWorldIndex, int nFieldIndex, int nTileIndex, cHorizontalRange& rangeAtWorld, cHorizontalRange& rangeAtLocal, int nCenterAtWorldX, int nCenterAtWorldY );

	CNtlMeshFederationContainer* CreateMeshFederationContainer( int nWorldIndex );
	bool				LoadWorldMeshFederation( int nWorldIndex );
	bool				LoadWorldMeshFederationByInfoScript( int nWorldIndex, const CNtlSimpleDOM& worldinfoScript );

	void				FindOverlappedMeshFederation( int nPositionX, int nPositionY, int nPositionZ,
		std::list< CNtlMeshFederation* >& listOverlapped );

	void				FindOverlappedMeshFederationByRange( cHorizontalRange range, std::list < CNtlMeshFederation* >& listOverlapped );

	static bool				SortSeamlessMeshCompare( CNtlSeamlessMesh* pLeft, CNtlSeamlessMesh* pRight );

protected:
	typedef std::map< int, CNtlMeshFederationContainer* > mapdef_WorldMeshFederation;
	mapdef_WorldMeshFederation		m_mapWorldPath;

	typedef std::list < CNtlSeamlessMesh* > listdef_NtlSeamlessMesh;
	listdef_NtlSeamlessMesh			m_listMesh;

	int								m_nCurrentWorldIndex;

	int								m_nSeamlessRange;
	int								m_nCurrentPositionX;
	int								m_nCurrentPositionY;
	int								m_nCurrentPositionZ;

	// �����ǰ� �ִ� PathManager�� AgentSize��
	typedef std::vector< int >		vecdef_AgentSize;
	vecdef_AgentSize				m_vecAgentSize;

	// ���� Seamless�� �����ǰ� �ִ°�?
	bool							m_bIsStart;
};

#endif