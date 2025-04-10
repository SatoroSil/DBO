/*****************************************************************************
* File			: NtlMeshFederationTileGeneratedCallBack.h
* Author		: Haesung, Cho
* Copyright		: (��)NTL
* Date			: 2009. 03. 11
* Abstract		: Pathengine MeshFederationTileGenerated callback class
*****************************************************************************
* Desc:
*
* ������ �ݹ� Ŭ������ PathEngine�� Mesh Federation ����� ��� �Ҷ� ���������
* �� TILE ���� ���ϵ��� ������ �� �ϴ� �ൿ���� �������ִ� Callback class �̴�.
*****************************************************************************/

#ifndef _NTL_MESH_FEDERATION_TILE_GENERATED_CALLBACK_H_
#define _NTL_MESH_FEDERATION_TILE_GENERATED_CALLBACK_H_

#include "..\PathEngine\i_pathengine.h"
#include "NtlPathEngineDef.h"

class CNtlMeshFederationTileGeneratedCallBack : public iMeshFederationTileGeneratedCallBack
{
public:
	typedef std::vector< int > vecdef_AgentSize;

public:
	CNtlMeshFederationTileGeneratedCallBack(const char* pTilingName,
		bool bPreProcessCollision = false,
		bool bPreProcessPathFind = false,
		vecdef_AgentSize* vecAgentSize = NULL );

	// tile�� generated �� �� ���Ǵ� �Լ�
	void tileGenerated(long tileIndex, iMesh* tileMesh);

protected:
	char		m_acTilingName[NTLPE_MAX_FILENAME_LENGTH+1];

	vecdef_AgentSize m_vecAgentSize;

	// Opt
	bool		m_bPreProcessCollision;
	bool		m_bPreProcessPathFind;
};


#endif