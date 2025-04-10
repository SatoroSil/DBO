#include "Precomp_NtlPathEngine.h"
#include "NtlMeshFederationTileGeneratedCallback.h"

// STL
#include <sstream>

// Stream
#include "NtlFileOutputStream.h"
#include "NtlPathEngine.h"

CNtlMeshFederationTileGeneratedCallBack::CNtlMeshFederationTileGeneratedCallBack( const char* pTilingName,
																				 bool bPreProcessCollision,
																				 bool bPreProcessPathFind,
																				 vecdef_AgentSize* vecAgentSize)
{
	m_bPreProcessCollision = bPreProcessCollision;
	m_bPreProcessPathFind = bPreProcessPathFind;

	if( vecAgentSize )
	{
		if( !vecAgentSize->empty() )
		{
			m_vecAgentSize = (*vecAgentSize);
		}
	}

	if( NULL == pTilingName )
	{
		// Error?
	}
	
	strcpy_s( m_acTilingName, NTLPE_MAX_FILENAME_LENGTH+1, pTilingName );
}

/**
* \brief TILE �� Generated �� �� ȣ��ȴ�. 
* \param tileIndex	TILE�� ���� Index
* \param tileMesh	TILE�� ���� iMesh
*/
void CNtlMeshFederationTileGeneratedCallBack::tileGenerated( long tileIndex, iMesh* tileMesh )
{
	printf_s("Tile Generatated : %5d\n", tileIndex);

	std::ostringstream fileName;
	fileName << m_acTilingName << NTLPE_FEDERATION_APPEND_TILE << tileIndex << NTLPE_DATA_EXTENSION;
	CNtlFileOutputStream fos(fileName.str().c_str());
	tileMesh->saveGround(NTLPE_DATA_FORMAT, true, &fos);

	// Agent Size list�� �ְ� PreProcess �ɼǵ��� ������ PreProcess ó���� �Ѵ�.
	for each( int nAgentSize in m_vecAgentSize )
	{
		if( m_bPreProcessCollision )
		{
			iShape* agentShape;
			
			long array[] =
			{
				-nAgentSize, nAgentSize,
				nAgentSize, nAgentSize,
				nAgentSize, -nAgentSize,
				-nAgentSize, -nAgentSize,
			};

			agentShape = GetNtlPathEngine()->GetPathEngine()->newShape( sizeof(array)/sizeof(*array)/2, array );
			
			std::ostringstream precollisionname;
			precollisionname << m_acTilingName << NTLPE_FEDERATION_APPEND_TILE << tileIndex;
			precollisionname << "_" << nAgentSize;
			precollisionname << NTLPE_DATA_EXTENSION_PRE_COLLISION;
			CNtlFileOutputStream cffos(precollisionname.str().c_str());

			// Collision Preprocess create and save
			tileMesh->generateCollisionPreprocessFor( agentShape, 0 );
			tileMesh->saveCollisionPreprocessFor( agentShape, &cffos );

			if( m_bPreProcessPathFind )
			{
				const char* attributes[3];
				attributes[0] = "split_with_circumference_below";
				attributes[1] = "2000";
				attributes[2] = 0;

				std::ostringstream prepathfindname;
				prepathfindname << m_acTilingName << NTLPE_FEDERATION_APPEND_TILE << tileIndex;
				prepathfindname << "_" << nAgentSize;
				prepathfindname << NTLPE_DATA_EXTENSION_PRE_PATHFIND;
				CNtlFileOutputStream pffos(prepathfindname.str().c_str());

				// PathFind Preprocess create and save
				tileMesh->generatePathfindPreprocessFor( agentShape, attributes );
				tileMesh->savePathfindPreprocessFor( agentShape, &pffos );
			}

			if( agentShape )
			{
				delete agentShape;
				agentShape = NULL;
			}
		}
	}	
	
	delete tileMesh;
}