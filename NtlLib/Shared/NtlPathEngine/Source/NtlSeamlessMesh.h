/*****************************************************************************
* File			: NtlSeamlessMesh.h
* Author		: Haesung, Cho
* Copyright		: (��)NTL
* Date			: 2009. 03. 19
* Abstract		: Pathengine seamless mesh
*****************************************************************************
* Desc:
*
*****************************************************************************/

#ifndef _NTL_SEAMLESS_MESH_H_
#define _NTL_SEAMLESS_MESH_H_

#include "../PathEngine/i_pathengine.h"
#include "NtlMesh.h"
#include <vector>

class CNtlSeamlessMesh : public CNtlMesh
{
public:
	CNtlSeamlessMesh();
	CNtlSeamlessMesh( int nWorldIndex, int nFieldIndex, int nTileIndex, 
		cHorizontalRange& rangeWorld,
		cHorizontalRange& rangeLocal,
		int nCenterAtWorldX, int nCenterAtWorldY,
		iMesh* pMesh = NULL, iCollisionContext* pContext = NULL);
	~CNtlSeamlessMesh();

	bool		IsLoad();

	// ������ �ִ� ������ ����Ͽ� Mesh�� �ε��Ѵ�.
	bool		BuildMeshFromIndexs();

	void		SetLoadRange( int nRange );
	int			GetLoadRange();

	virtual		bool IsRangeOverlapped( cHorizontalRange range );

protected:
	bool				m_bIsLoad;
	int					m_nLoadRange;		///< �Ÿ��� �Ǵ����� ���� �Ÿ�
};

#endif