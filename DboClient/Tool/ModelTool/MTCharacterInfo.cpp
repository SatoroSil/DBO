#include "StdAfx.h"
#include "NtlDebug.h"
#include "NtlText.h"
#include "NtlAtomic.h"
#include "MTCharacterInfo.h"

int         MTCharacterInfo::m_nTotalVertices   = 0;
int         MTCharacterInfo::m_nTotalTriangels  = 0;
RpAtomic*   MTCharacterInfo::m_pTempAtomic      = NULL;

MTCharacterInfo::MTCharacterInfo(void)
{
    m_fClumpWidth  = 0.0f;
    m_fClumpHeight = 0.0f;
    m_pTempAtomic  = NULL;
}

MTCharacterInfo::~MTCharacterInfo(void)
{
	Destroy();
}

//////////////////////////////////////////////////////////////////////////
// CallBack �Լ� ����
//////////////////////////////////////////////////////////////////////////
RpAtomic* MTCharacterInfo::GetClumpAllAtomics(RpAtomic* pAtomic, void* pData)
{
	ATOMIC_TABLE_MAP *pTable = (ATOMIC_TABLE_MAP *)pData;

	int count = RpGeometryGetUserDataArrayCount(RpAtomicGetGeometry(pAtomic));
	RpUserDataArray *pUserData = RpGeometryGetUserDataArray(RpAtomicGetGeometry(pAtomic), 0);
	char *chBuffer = RpUserDataArrayGetString(pUserData, 0);

	if(count > 1)
	{
		(*pTable)[chBuffer] = pAtomic;
	}

    // ȭ�鿡 ǥ�õ� �������� �����Ѵ�.
    RpGeometry* pGeom = RpAtomicGetGeometry(pAtomic);
    if(pGeom)
    {
        m_nTotalTriangels += RpGeometryGetNumTriangles(pGeom);
        m_nTotalVertices  += RpGeometryGetNumVertices(pGeom);
    }

    

	return pAtomic;
}

RwFrame* MTCharacterInfo::GetChildFrame(RwFrame* pFrame, void* pData)
{
	FRAME_TABLE_MAP *pTable = (FRAME_TABLE_MAP *)pData;

	RpUserDataArray *pUserData = RwFrameGetUserDataArray(pFrame, 0);
	if(pUserData != NULL)
	{
		char *chBuffer = RpUserDataArrayGetString(pUserData, 0);
		if(chBuffer != NULL)
		{
			(*pTable)[chBuffer] = pFrame;
		}
		RwFrameForAllChildren(pFrame, GetChildFrame, pData);
	}

	return pFrame;
}

RpMaterial* MTCharacterInfo::GetAllMaterials(RpMaterial* material, void* pData)
{
    MTCharacterInfo* pThisCharInfo = (MTCharacterInfo*)pData;	

	RpUserDataArray *pUserData = RpMaterialGetUserDataArray(material, 0);

	if(pUserData != NULL)
	{
		char *chBuffer = RpUserDataArrayGetString(pUserData, 0);
		if(chBuffer != NULL)
		{
			pThisCharInfo->m_mapMaterialtable[chBuffer] = material;

            // Material - Atomic Map�� �����.
            pThisCharInfo->m_mapMaterialAtomicTable[material] = m_pTempAtomic;
		}
	}
	return material;
}
//////////////////////////////////////////////////////////////////////////


/**
 * clump�� ���� ���̺��� �����Ѵ�.
 * \param pClump ������ ������ clump
 * return ���� ����
 */
RwBool MTCharacterInfo::Create(RpClump* pClump)
{
	NTL_PRE(pClump);

	m_pTargetClump = pClump;

	SetClumpInfo();     // Clump ���� ���� ����

    //CreateHierarchy();  // Hierarchy ���� ����

	return TRUE;
}

void MTCharacterInfo::Destroy()
{
	m_mapFrameTable.clear();
	m_mapMaterialtable.clear();
	m_mapAtomicTable.clear();
    m_mapMaterialAtomicTable.clear();
}

void MTCharacterInfo::SetClumpInfo()
{
	NTL_PRE(m_pTargetClump);

    m_nTotalTriangels = 0;
    m_nTotalVertices  = 0;

	// ��� Atomic�� �ʿ� ��´�.
	RpClumpForAllAtomics(m_pTargetClump, GetClumpAllAtomics, &m_mapAtomicTable);
	// ��� Frame�� �ʿ� ��´�.
	RwFrameForAllChildren(RpClumpGetFrame(m_pTargetClump), GetChildFrame, &m_mapFrameTable);

	// ��� Material�� �ʿ� ��´�.
	RpGeometry* pGeom = NULL;
	ATOMIC_TABLE_ITER mapIter;
	for(mapIter = m_mapAtomicTable.begin(); mapIter != m_mapAtomicTable.end(); ++mapIter)
	{
		pGeom = RpAtomicGetGeometry(mapIter->second);
		if(pGeom)
		{
            // ���� Atomic �����͸� �����Ѵ�.
            m_pTempAtomic = mapIter->second;

            // Material - Atomic ��Ʈ�� ����� ���ؼ� this �����͸� �Ѱ��ش�.
			RpGeometryForAllMaterials(pGeom, GetAllMaterials, this);
		}
	}
    
    // ���̿� ���̸� �����Ѵ�.
    UpdateHeightWidth();

}

void MTCharacterInfo::UpdateHeightWidth()
{
    m_fClumpWidth  = 0.0f;
    m_fClumpHeight = 0.0f;

    // �ٿ�� �ڽ��� ���� ����Ѵ�.
    RwBBox boundingBox;
    boundingBox.sup.x = boundingBox.sup.y = boundingBox.sup.z = -RwRealMAXVAL;
    boundingBox.inf.x = boundingBox.inf.y = boundingBox.inf.z = RwRealMAXVAL;

    ATOMIC_TABLE_ITER it;
    for(it = m_mapAtomicTable.begin(); it != m_mapAtomicTable.end(); ++it)
    {
        RpAtomic* pAtomic = it->second;
        if(!pAtomic)
            continue;

        RpGeometry* pGeom = NULL;
        RwV3d *vertIn = NULL, *vertOut = NULL;
        RwInt32 numVerts = 0;
        RwMatrix transForm;	

        pGeom = RpAtomicGetGeometry(pAtomic);
        numVerts = RpGeometryGetNumVertices(pGeom);

        // Vertex positions in atomic local-space
        vertIn = RpMorphTargetGetVertices(RpGeometryGetMorphTarget(pGeom, 0));

        vertOut = new RwV3d[numVerts];

        transForm = *RwFrameGetLTM(RpAtomicGetFrame(pAtomic));

        RwV3dTransformPoints(vertOut, vertIn, numVerts, &transForm);

        for(int i = 0; i < numVerts; ++i)
        {
            RwBBoxAddPoint(&boundingBox, &vertOut[i]);
        }

        delete[] vertOut;
    }

    m_fClumpWidth = boundingBox.sup.x - boundingBox.inf.x;
    m_fClumpHeight = boundingBox.sup.y - boundingBox.inf.y;
}

RpAtomic* MTCharacterInfo::GetAtomicByName(RwChar* chAtomicName)
{
	std::string atomicName = chAtomicName;

	if(m_mapAtomicTable.find(atomicName) == m_mapAtomicTable.end())
	{
		return NULL;
	}

	return m_mapAtomicTable[atomicName];
}

RpAtomic* MTCharacterInfo::GetAtomicByMaterial(RpMaterial* pMaterial)
{
    if(!pMaterial)
        return NULL;

    if(m_mapMaterialAtomicTable.find(pMaterial) == m_mapMaterialAtomicTable.end())
    {
        return NULL;
    }

    return m_mapMaterialAtomicTable[pMaterial];
}


RpMaterial* MTCharacterInfo::GetMaterialByName(RwChar* chMaterialName)
{
	std::string materialName = chMaterialName;

	if(m_mapMaterialtable.find(materialName) == m_mapMaterialtable.end())
	{
		return NULL;
	}

	return m_mapMaterialtable[materialName];
}


RwFrame* MTCharacterInfo::GetFrameByName(RwChar* chFrameName)
{
	std::string frameName = chFrameName;

	if(m_mapFrameTable.find(chFrameName) == m_mapFrameTable.end())
	{
		return NULL;
	}

	return m_mapFrameTable[frameName];
}


void MTCharacterInfo::DisplayInfo(RtCharset* pCharSet)
{
    if(!pCharSet)
        return;

    RwChar caption[256] = {0,};

    // Atomic ����
    RsSprintf(caption, RWSTRING("Atomics : %d"),m_mapAtomicTable.size());
    RsCharsetPrint(pCharSet, caption, 0, 0, rsPRINTPOSTOPLEFT);

    // Triangle ����
    RsSprintf(caption, RWSTRING("Triangels : %d"), m_nTotalTriangels);
    RsCharsetPrint(pCharSet, caption, 0, 1, rsPRINTPOSTOPLEFT);
    
    // vertices ����
    RsSprintf(caption, RWSTRING("Vertices : %d"), m_nTotalVertices);
    RsCharsetPrint(pCharSet, caption, 0, 2, rsPRINTPOSTOPLEFT);

    // ���̿� ����
    RsSprintf(caption, RWSTRING("Hieght : %.2f (m)"), m_fClumpHeight);
    RsCharsetPrint(pCharSet, caption, 0, 3, rsPRINTPOSTOPLEFT);
    RsSprintf(caption, RWSTRING("Width : %.2f (m)"), m_fClumpWidth);
    RsCharsetPrint(pCharSet, caption, 0, 4, rsPRINTPOSTOPLEFT);

}