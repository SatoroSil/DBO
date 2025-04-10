#include "StdAfx.h"
#include "ModelToolApplication.h"
#include "PageClump.h"
#include "NtlText.h"
#include "NtlToonMaterial.h"
#include "MTCharacter.h"
#include "NtlTypeAnimData.h"
#include "BottomToolView.h"
#include "RightToolView.h"



static RwUInt32             NumIm3DVerts = 0;
static RwIm3DVertex         Im3DVerts[MAX_NUM_SCALE_BONE];
static RwImVertexIndex      Im3DIndices[MAX_NUM_SCALE_BONE << 1];

static RwFrame* GetChildFrame(RwFrame *pFrame, void *pData)
{
    FRAME_MAP *pTable = (FRAME_MAP *)pData;

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


CMTCharacter::CMTCharacter(void)
{
    m_bAnim         = FALSE;
    m_nBoneCount    = 0;
    m_pAnimation    = NULL;    
    m_bRenderBone   = FALSE;
    m_bVisible      = FALSE;

    m_pProperty = new CNtlPLCharacterProperty();
}

CMTCharacter::~CMTCharacter(void)
{
    if(m_pAnimation)
    {
        RtAnimAnimationDestroy(m_pAnimation);
        m_pAnimation = NULL;
    }

    if(m_pProperty)
    {
        delete m_pProperty;
        m_pProperty = NULL;
    }

    for(size_t i = 0; i < m_vMultiTexture.size(); ++i)
    {
        if(m_vMultiTexture[i])
        {
            CNtlPLResourceManager::GetInstance()->UnLoadTexture(m_vMultiTexture[i]);
            m_vMultiTexture[i] = NULL;
        }
        
    }

	m_vecBB.clear();
}

void* CMTCharacter::operator new(size_t size)
{
	return malloc(sizeof(CMTCharacter));
}


void CMTCharacter::operator delete(void *pObj)
{
	free(pObj);
}


RwBool CMTCharacter::Create(const SPLEntityCreateParam *pParam /* = NULL  */)
{
	CreateCartoon();

	//BoneData �������� ���� ������ �߽��ϴ�(2006.4.26 HongHoDong)
	//ScaleBone Data
    m_pTypeBoneData = m_pProperty->GetBoneScaleData();

	m_pTypeBoneData->bBoneScale = TRUE;
    //m_bBoneScaleFlag = TRUE;

    // Bone�� �׸������� Vertex Indices�� �ʱ�ȭ�Ѵ�.
    if(m_pTypeBoneData->bBoneScale)
    {
        RwUInt32	i, j;

        for (i=0, j=0; i < MAX_NUM_SCALE_BONE; i++)
        {
            Im3DIndices[j++] = 0;
            Im3DIndices[j++] = (RwImVertexIndex) i + 1;
            RwIm3DVertexSetRGBA(&Im3DVerts[i], 255, 0, 0, 255);
        }
    }

	return TRUE;
}

/*!
 * \brief ī�������� ���ҽ��� �����Ѵ�.
 * \returns ���� ����
 */
RwBool CMTCharacter::CreateCartoon()
{
	std::string strToonPath = CModelToolApplication::GetInstance()->GetWorkDir();
	strToonPath += "\\character\\toon\\Smooth";

    
	m_ToonData.pTexture   = RwTextureRead(strToonPath.c_str(), 0);
	m_ToonData.pToonPaint = RpToonPaintCreate();
	RpToonPaintSetGradientTexture(m_ToonData.pToonPaint, m_ToonData.pTexture);

	RwRGBA color = {0,0,0,255};
	m_ToonData.pToonInk = RpToonInkCreate();	
	RpToonInkSetOverallThickness(m_ToonData.pToonInk, 1.2f);
	RpToonInkSetColor(m_ToonData.pToonInk, color );
	RpToonInkSetName(m_ToonData.pToonInk, "silhouette" );

	return TRUE;
}

/*!
 * \brief dff ������ �ε��Ѵ�. (path ���� ������)
 * \param szDffName �ε��� ���� �̸� (*.dff) 
 * \returns ���� ���� 
 */
RwBool CMTCharacter::CreateMesh(const char *szDffName)
{
	NTL_PRE(szDffName);

    // �ʿ��� �ʱ�ȭ
    m_nCurrentSelectBoneIndex = 0;

	// File Loading 
	std::string strTexPath = CModelToolApplication::GetInstance()->GetWorkDir();
	SetCurrentDirectoryA(strTexPath.c_str());
	strTexPath = "Texture\\character\\Texture_HumanMale\\;";
	strTexPath += "Texture\\character\\Texture_HumanFemale\\;";
	strTexPath += "Texture\\character\\Texture_Namek\\;";
	strTexPath += "Texture\\character\\Texture_MajinMale\\;";
	strTexPath += "Texture\\character\\Texture_MajinFemale\\;";
	
	strTexPath += "Texture\\character\\Texture_Mob\\;";
	strTexPath += "Texture\\character\\Texture_Npc\\";

	m_pResourceClump = CNtlPLResourceManager::GetInstance()->LoadClump(szDffName, strTexPath.c_str());
    
	if(!m_pResourceClump)
		return FALSE;
	
	m_pClump	= m_pResourceClump->GetClump();
	if(!m_pClump) 
		return FALSE;

    
    // Hierarchy ������ �����´�.
    m_pBaseHierarchy = Helper_GetHierarchyClump(m_pClump);
    NTL_ASSERTE(m_pBaseHierarchy);
    if(m_pBaseHierarchy == NULL)
        NTL_RETURN(FALSE);

    RpHAnimHierarchyAttach(m_pBaseHierarchy);
    m_nBoneCount = m_pBaseHierarchy->numNodes;
    m_pProperty->GetBoneScaleData()->nBoneCount = m_nBoneCount;    

    // �������� �� ���� ���� �ʴ´�.
    //RwFrameForAllChildren(RpClumpGetFrame(m_pClump), GetChildFrame, &m_mapFrame);    
    
    

    // Toon Setting
	Helper_SetToonClump(m_pClump, &m_ToonData);

    // world�� clump�� �߰��Ѵ�.
    RpWorldAddClump(CNtlPLGlobal::m_pRpWorld, m_pClump);
	//GetBone List
	RwFrameForAllChildren( RpClumpGetFrame(m_pClump), GetChildFrame, &m_mapFrame);

    m_bVisible = TRUE;
    SetAnimUpdate(TRUE);
	
	//Effect Test(2006. 5. 10 HongHoDong)
	//CNtlPLEntity *pPLEntity = GetSceneManager()->CreateEntity(PLENTITY_EFFECT, NTL_EFFECT_KEY_MOVEMARK);
	//AttachBone((CNtlPLAttach *)pPLEntity, NTL_BONE_RIGHT_HAND);

	return TRUE;

}

RwBool CMTCharacter::LoadClump(RwChar * filename)
{
	NTL_PRE(filename);


	// �̹� �ε��Ǿ������� �������ش�.
	if(m_pResourceClump)
	{
		RpWorldRemoveClump(CNtlPLGlobal::m_pRpWorld, m_pClump);
		CNtlPLResourceManager::GetInstance()->UnLoad(m_pResourceClump);	        
	}
	
	if(!CreateMesh(filename))
		return FALSE;

	// Clump ���� ������ �����ϰ� ǥ���Ѵ�.
	UpdateClumpInfo();

    m_bAnim = FALSE;

	return TRUE;
}

void CMTCharacter::SetVisible(RwBool bVisible)
{
    if(m_bVisible == bVisible || !m_pClump)
        return;

    m_bVisible = bVisible;
    if(m_bVisible)
    {
        RpWorldAddClump(CNtlPLGlobal::m_pRpWorld, m_pClump);
    }
    else
    {
        RpWorldRemoveClump(CNtlPLGlobal::m_pRpWorld, m_pClump);
    }
}

RwBool CMTCharacter::SaveClump(RwChar* fileName)
{
    NTL_PRE(fileName);
    NTL_PRE(m_pClump);

    RwStream* pStream = RwStreamOpen(rwSTREAMFILENAME, rwSTREAMWRITE, fileName);  
    if(!pStream)
        return FALSE;
    
    RpClumpStreamWrite(m_pClump, pStream);
    RwStreamClose(pStream, NULL);

    return TRUE;
}

RwBool CMTCharacter::RemoveAtomic(RwChar* chAtomicName)
{
    NTL_PRE(chAtomicName);

    RpAtomic* pAtomic = m_charInfo.GetAtomicByName(chAtomicName);
    if(!pAtomic)
        return FALSE;

    RpClump* pRetClump = RpClumpRemoveAtomic(m_pClump, pAtomic);
    if(!pRetClump)
    {
        return FALSE;
    }
    
    RpWorldRemoveAtomic(CNtlPLGlobal::m_pRpWorld, pAtomic);
    RpAtomicDestroy(pAtomic);

    return TRUE;
}

void CMTCharacter::UpdateClumpInfo()
{
    m_charInfo.Destroy();
    ClearBB();
    if(m_pClump)
    {
        m_charInfo.Create(m_pClump);
        DisplayClumpInfo();        
    }    
}

void CMTCharacter::DisplayClumpInfo()
{
	NTL_PRE(m_pClump);

	USES_CONVERSION;
	// ������ ������ View�� ǥ���Ѵ�.

    // 1. Atomic ������ ǥ���Ѵ�.
	CListBox* pAtomicListBox = (CListBox*)CPageClump::GetInstance()->GetDlgItem(IDC_LIST_ATOMIC);
	pAtomicListBox->ResetContent();

	ATOMIC_TABLE_ITER mapIt;
	for(mapIt = m_charInfo.m_mapAtomicTable.begin(); mapIt != m_charInfo.m_mapAtomicTable.end(); ++mapIt)
	{
		std::string atomicName = (mapIt->first);
		pAtomicListBox->AddString(A2W(atomicName.c_str()));
	}

    // 2. Material ������ ǥ���Ѵ�.
    CListBox* pMaterialListBox = (CListBox*)CPageClump::GetInstance()->GetDlgItem(IDC_LIST_MATERIAL);
    pMaterialListBox->ResetContent();

    MATERIAL_TABLE_ITER matIt;
    for(matIt = m_charInfo.m_mapMaterialtable.begin(); matIt != m_charInfo.m_mapMaterialtable.end(); ++matIt)
    {
        std::string strMaterialName = matIt->first;
        pMaterialListBox->AddString(A2W(strMaterialName.c_str()));
    }

    // 3. �ϴܺ信 ������ ǥ���Ѵ�.
    CBottomToolView::GetInstance()->SetInit(this);

    // 4. �����信 ������ ǥ���Ѵ�.
    CRightToolView::GetInstance()->SetInit(this);

}

void CMTCharacter::DisplayMaterialAttribute(RwChar* chMaterialName)
{
    USES_CONVERSION;

    NTL_PRE(chMaterialName);

    CColorButton* pColorBt = (CColorButton*)CPageClump::GetInstance()->GetDlgItem(IDC_BUTTON3);

    RpMaterial* pMaterial = m_charInfo.GetMaterialByName(chMaterialName);
    if(pMaterial)
    {
        // �ؽ��� ����
        RwTexture* pTexture = RpNtlToonMaterialGetTexture(pMaterial);
        if(pTexture)
        {
            // �̸� ����
            std::string strTextureName = RwTextureGetName(pTexture);
            RwRaster* pRaster = RwTextureGetRaster(pTexture);
            RwInt32 nWidth = RwRasterGetWidth(pRaster);
            RwInt32 nHeight = RwRasterGetHeight(pRaster);

            CPageClump::GetInstance()->SetMultiTextureInfo((RwChar*)strTextureName.c_str(), nWidth, nHeight);            
        }
        else
        {
            // MultiTexture�� ������
            CPageClump::GetInstance()->SetMultiTextureInfo(NULL, 0, 0);
        }

        // Į�� ����
        const RwRGBAReal* pColor = RpNtlToonMaterialGetColor(pMaterial);
        if(pColor)
        {
            RwRGBA nColor;
            RwRGBAFromRwRGBAReal(&nColor, pColor);

            pColorBt->SetColor(nColor.red, nColor.green, nColor.blue);
            CPageClump::GetInstance()->Invalidate(FALSE);
        }
    }
}

RwBool CMTCharacter::SetMultiTexture(RwChar* chMaterialName, RwChar* chTextureName, RwChar* chTexturePath)
{
    if(!chMaterialName)
        return FALSE;

    RpMaterial* pMaterial = m_charInfo.GetMaterialByName(chMaterialName);
    if(!pMaterial)
        return FALSE;
    
    // ��Ƽ �ؽ��� ����
    if(chTextureName == NULL)
    {
        RwBool bReturn = RpNtlToonMaterialSetTexture(pMaterial, NULL);
        return bReturn;
    }


    // Texture�� �����Ѵ�.    
    RwTexture* pMultiTexture = CNtlPLResourceManager::GetInstance()->LoadTexture(chTextureName, chTexturePath);
    if(!pMultiTexture)
        return FALSE;

    // ���߿� ������ ���ؼ� Vector�� �ִ´�.
    m_vMultiTexture.push_back(pMultiTexture);

    // Material�� �����Ѵ�.
    RwBool bReturn = RpNtlToonMaterialSetTexture(pMaterial, pMultiTexture);

    return bReturn;
}

void CMTCharacter::SetMaterialColor(RwChar* chMaterialName, int r, int g, int b)
{
    NTL_PRE(chMaterialName);
    
    RpMaterial* pMaterial = m_charInfo.GetMaterialByName(chMaterialName);
    if(!pMaterial)
        return;
    
    RwRGBA color;
    color.red = r;
    color.green = g;
    color.blue = b;
    color.alpha = 255;

    RwRGBAReal realColor;
    RwRGBARealFromRwRGBA(&realColor, &color);
    RpNtlToonMaterialSetColor(pMaterial, &realColor);

    // Color�� �����Ҷ��� MATERIAL_COLOR Flag�� �����Ѵ�.
    RpAtomic* pAtomic = m_charInfo.GetAtomicByMaterial(pMaterial);
    RwInt32 flag = RpNtlAtomicGetRenderFlag(pAtomic);
    flag |= NTL_MATERIAL_COLOR;
    RpNtlAtomicSetRenderFlag(pAtomic, flag);    
 }

void CMTCharacter::CreateBB(RwChar* chAtomicName)
{
	NTL_PRE(chAtomicName);

	// 1. �켱 Name�� �ش��ϴ� Atomic�� ã�Ƴ���.
	RpAtomic* pAtomic = m_charInfo.GetAtomicByName(chAtomicName);
	if(!pAtomic)
		return;

	RwBBox boundingBox;
	boundingBox.sup.x = boundingBox.sup.y = boundingBox.sup.z = -RwRealMAXVAL;
	boundingBox.inf.x = boundingBox.inf.y = boundingBox.inf.z = RwRealMAXVAL;

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

	// Add bounding box
	for(int i = 0; i < numVerts; ++i)
	{
		RwBBoxAddPoint(&boundingBox, &vertOut[i]);
	}

	m_vecBB.push_back(boundingBox);

	delete[] vertOut;
}

void CMTCharacter::ClearBB()
{
	m_vecBB.clear();
}


void CMTCharacter::RenderBB(RwBBox* pBBox)
{
	NTL_PRE(pBBox);

	RwIm3DVertex imVertex[8];
	RwMatrix* ltm = NULL;
	RwImVertexIndex indices[24] = 
	{
		0, 1, 1, 3, 3, 2, 2, 0, 4, 5, 5, 7,
		7, 6, 6, 4, 0, 4, 1, 5, 2, 6, 3, 7
	};
	
	for(int i = 0; i < 8; ++i)
	{
		RwIm3DVertexSetPos(&imVertex[i],
			i & 1 ? pBBox->sup.x : pBBox->inf.x,
			i & 2 ? pBBox->sup.y : pBBox->inf.y,
			i & 4 ? pBBox->sup.z : pBBox->inf.z);

		RwIm3DVertexSetRGBA(&imVertex[i], 255, 0, 0, 255);
	}

	RwRenderStateSet(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEFLAT);
	RwRenderStateSet(rwRENDERSTATETEXTURERASTER, (void*)NULL);

	if(RwIm3DTransform(imVertex, 8, ltm, rwIM3D_ALLOPAQUE))
	{
		RwIm3DRenderIndexedPrimitive(rwPRIMTYPELINELIST, indices, 24);
		RwIm3DEnd();
	}

	RwRenderStateSet(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
}

RwBool CMTCharacter::Update(RwReal fElapsed)
{
    if(m_bAnim)
    {
		//Update�� �̷������� ���־�� �Ѵ�.(by HoDong 2006.4.26)
		CNtlPLCharacter::Update(fElapsed);
    }

	return TRUE;
}

RwBool CMTCharacter::Render()
{
	// Bounding Box Render
	for(size_t i = 0; i < m_vecBB.size(); ++i)
	{
		RenderBB(&(m_vecBB[i]));
	}

    //if(m_bAnim && m_bRenderBone)
    if(m_bRenderBone)
    {
		//Render �κп��� �̰��� �ϸ� �ȵȴ�. (by HoDong 2006.4.26)
        //UpdatePreBoneScale();        
        
        // ���� ���õ� Bone�� ������ �Ѵ�.
        RenderSelectedBoneScale(m_pBaseHierarchy, m_nCurrentSelectBoneIndex);
        
        //UpdatePostBoneScale();        
    }

	return TRUE;
}


void CMTCharacter::DisplayInfo(RtCharset* pCharSet)
{
    if(!pCharSet)
        return;
    
    // ȭ�鿡 ���� ������ ǥ���Ѵ�.
    m_charInfo.DisplayInfo(pCharSet);

    RwChar caption[256] = {0,};

    // Atomic ����
    RsSprintf(caption, RWSTRING("Bones : %d"),m_nBoneCount);
    RsCharsetPrint(pCharSet, caption, 0, 0, rsPRINTPOSBOTTOMLEFT);
}

void CMTCharacter::RenderWireFrame()
{
    if(!m_pClump)
        return;

    RpClumpForAllAtomics(m_pClump, AtomicRenderWireMesh, NULL);
}

RpAtomic* CMTCharacter::AtomicRenderWireMesh(RpAtomic *atomic, void * data __RWUNUSED__)
{
    RpGeometry *geometry;

    geometry = RpAtomicGetGeometry(atomic);

    if( geometry )
    {
        RwReal interpPos = 1.0f, invInterpPos = 0.0f;
        RpMorphTarget *morphTarget;
        RwInt32 nkf;
        RpTriangle *triangle;
        RwV3d *vertPosStart = (RwV3d *)NULL;
        RwV3d *vertPosEnd = (RwV3d *)NULL;
        RwMatrix *LTM;
        RwInt32 numTri, numImmVert, i;
        RwIm3DVertex *imVertex;
        RwRGBA Color = {0, 255, 255, 255};

        nkf = RpGeometryGetNumMorphTargets(geometry);
        numTri = RpGeometryGetNumTriangles(geometry);
        imVertex = (RwIm3DVertex *)RwMalloc(numTri * 6 * sizeof(RwIm3DVertex),
            rwID_NAOBJECT);

        if( nkf > 1 )
        {
            RpInterpolator *interp;
            RwInt32 startMorphTarget, endMorphTarget;

            interp = RpAtomicGetInterpolator(atomic);

            interpPos = RpInterpolatorGetValue(interp) / RpInterpolatorGetScale(interp);

            invInterpPos = 1.0f - interpPos;

            startMorphTarget = RpInterpolatorGetStartMorphTarget(interp);
            endMorphTarget = RpInterpolatorGetEndMorphTarget(interp);

            morphTarget = RpGeometryGetMorphTarget(geometry, startMorphTarget);
            vertPosStart = RpMorphTargetGetVertices(morphTarget);

            morphTarget = RpGeometryGetMorphTarget(geometry, endMorphTarget);
            vertPosEnd = RpMorphTargetGetVertices(morphTarget);
        }
        else
        {
            morphTarget = RpGeometryGetMorphTarget(geometry, 0);
            vertPosStart = RpMorphTargetGetVertices(morphTarget);
        }

        triangle = RpGeometryGetTriangles(geometry);

        for( i = 0; i < numTri; i++ )
        {
            RwUInt16 vert0, vert1, vert2;
            RwV3d vertPos[3];

            RpGeometryTriangleGetVertexIndices(geometry, triangle, &vert0, &vert1, &vert2);

            if( nkf > 1 )
            {
                RwV3d tempVec1, tempVec2;

                RwV3dScale(&tempVec1, &vertPosStart[vert0], invInterpPos);
                RwV3dScale(&tempVec2, &vertPosEnd[vert0], interpPos);
                RwV3dAdd(&vertPos[0], &tempVec1, &tempVec2);

                RwV3dScale(&tempVec1, &vertPosStart[vert1], invInterpPos);
                RwV3dScale(&tempVec2, &vertPosEnd[vert1], interpPos);
                RwV3dAdd(&vertPos[1], &tempVec1, &tempVec2);

                RwV3dScale(&tempVec1, &vertPosStart[vert2], invInterpPos);
                RwV3dScale(&tempVec2, &vertPosEnd[vert2], interpPos);
                RwV3dAdd(&vertPos[2], &tempVec1, &tempVec2);

            }
            else
            {
                vertPos[0] = vertPosStart[vert0];
                vertPos[1] = vertPosStart[vert1];
                vertPos[2] = vertPosStart[vert2];
            }

            RwIm3DVertexSetPos(&imVertex[i*6+0], vertPos[0].x, vertPos[0].y, vertPos[0].z);
            RwIm3DVertexSetRGBA (&imVertex[i*6+0], Color.red, Color.green, Color.blue, Color.alpha);
            RwIm3DVertexSetPos(&imVertex[i*6+1], vertPos[1].x, vertPos[1].y, vertPos[1].z);
            RwIm3DVertexSetRGBA(&imVertex[i*6+1], Color.red, Color.green, Color.blue, Color.alpha);


            RwIm3DVertexSetPos(&imVertex[i*6+2], vertPos[1].x, vertPos[1].y, vertPos[1].z);
            RwIm3DVertexSetRGBA(&imVertex[i*6+2], Color.red, Color.green, Color.blue, Color.alpha);
            RwIm3DVertexSetPos(&imVertex[i*6+3], vertPos[2].x, vertPos[2].y, vertPos[2].z);
            RwIm3DVertexSetRGBA(&imVertex[i*6+3], Color.red, Color.green, Color.blue, Color.alpha);

            RwIm3DVertexSetPos(&imVertex[i*6+4], vertPos[2].x, vertPos[2].y, vertPos[2].z);
            RwIm3DVertexSetRGBA(&imVertex[i*6+4], Color.red, Color.green, Color.blue, Color.alpha);
            RwIm3DVertexSetPos(&imVertex[i*6+5], vertPos[0].x, vertPos[0].y, vertPos[0].z);
            RwIm3DVertexSetRGBA(&imVertex[i*6+5], Color.red, Color.green, Color.blue, Color.alpha);

            triangle++;
        }

        RwRenderStateSet(rwRENDERSTATETEXTURERASTER, NULL);
        RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void *)TRUE);
        RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void *)TRUE);

        i = 0;
        numImmVert = numTri * 6;
        LTM = RwFrameGetLTM(RpAtomicGetFrame(atomic));
        while (numImmVert > DISPATCHSIZE)
        {
            if( RwIm3DTransform(&imVertex[i], DISPATCHSIZE, LTM, 0) )
            {
                RwIm3DRenderPrimitive(rwPRIMTYPELINELIST);

                RwIm3DEnd();
            }

            numImmVert -= DISPATCHSIZE;
            i += DISPATCHSIZE;
        }

        if( RwIm3DTransform(&imVertex[i], numImmVert, LTM, 0) )
        {
            RwIm3DRenderPrimitive(rwPRIMTYPELINELIST);

            RwIm3DEnd();
        }

        RwFree(imVertex);
    }

    return atomic;
}

void CMTCharacter::RenderHierarchy()
{
    if(!m_pClump)
        return;

    RpClumpForAllAtomics(m_pClump, AtomicRenderSkeleton, NULL);
}

RpAtomic* CMTCharacter::AtomicRenderSkeleton(RpAtomic *atomic, void * data __RWUNUSED__)
{
    RpGeometry *geometry;

    geometry = RpAtomicGetGeometry(atomic);

    if( geometry )
    {
        RwFrame *frame = RwFrameGetRoot(RpAtomicGetFrame(atomic));

        if( frame != NULL)
        {
            RwRenderStateSet(rwRENDERSTATETEXTURERASTER, NULL);
            RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void *)FALSE);
            RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void *)FALSE);

            RwFrameForAllChildren(frame, HierarchyRender, NULL);
        }
    }

    return atomic;
}

void CMTCharacter::SkeletonRender(RwMatrix *LTM, RpHAnimHierarchy *hier)
{

    if (hier)
    {
        RwMatrix *matrices;
        RpHAnimNodeInfo *finfo;
        RwMatrix *mstack[128],*parent;
        RwInt32 tos,i;
        RwIm3DVertex *im3DVertices; 
        RwIm3DVertex *imVertex;

        matrices = RpHAnimHierarchyGetMatrixArray(hier);
        finfo = hier->pNodeInfo;
        tos = 0;
        parent = mstack[0] = LTM;

        im3DVertices = (RwIm3DVertex *)RwMalloc(sizeof(RwIm3DVertex) * 128 * 8, rwID_NAOBJECT);
        imVertex = im3DVertices;
        for (i=0; i<hier->numNodes; i++)
        {
            RwV3d tmp;

            RwIm3DVertexSetPos(imVertex, parent->pos.x,parent->pos.y,parent->pos.z);
            RwIm3DVertexSetRGBA(imVertex, 255,255,0,255);
            imVertex++;

            RwIm3DVertexSetPos(imVertex, matrices[i].pos.x,matrices[i].pos.y,matrices[i].pos.z);
            RwIm3DVertexSetRGBA(imVertex, 255,255,0,255);
            imVertex++;

            /* drawn bone axes */
            RwIm3DVertexSetPos(imVertex, matrices[i].pos.x,matrices[i].pos.y,matrices[i].pos.z);
            RwIm3DVertexSetRGBA(imVertex, 255,0,0,255);
            imVertex++;
            RwV3dAdd(&tmp, &matrices[i].pos, &matrices[i].right);
            RwIm3DVertexSetPos(imVertex, tmp.x,tmp.y,tmp.z);
            RwIm3DVertexSetRGBA(imVertex, 255,0,0,255);
            imVertex++;

            RwIm3DVertexSetPos(imVertex, matrices[i].pos.x,matrices[i].pos.y,matrices[i].pos.z);
            RwIm3DVertexSetRGBA(imVertex, 0,255,0,255);
            imVertex++;
            RwV3dAdd(&tmp, &matrices[i].pos, &matrices[i].up);
            RwIm3DVertexSetPos(imVertex, tmp.x,tmp.y,tmp.z);
            RwIm3DVertexSetRGBA(imVertex, 0,255,0,255);
            imVertex++;

            RwIm3DVertexSetPos(imVertex, matrices[i].pos.x,matrices[i].pos.y,matrices[i].pos.z);
            RwIm3DVertexSetRGBA(imVertex, 0,0,255,255);
            imVertex++;
            RwV3dAdd(&tmp, &matrices[i].pos, &matrices[i].at);
            RwIm3DVertexSetPos(imVertex, tmp.x,tmp.y,tmp.z);
            RwIm3DVertexSetRGBA(imVertex, 0,0,255,255);
            imVertex++;

            if (finfo[i].flags & rpHANIMPUSHPARENTMATRIX)
            {
                mstack[++tos] = &matrices[i];
            }

            if (finfo[i].flags & rpHANIMPOPPARENTMATRIX)
            {
                parent = mstack[tos--];
            }
            else
            {
                parent = &matrices[i];
            }
        }

        if( RwIm3DTransform(im3DVertices, imVertex - im3DVertices, (RwMatrix *)NULL, 0) )
        {
            RwIm3DRenderPrimitive(rwPRIMTYPELINELIST);
            RwIm3DEnd();
        }

        RwFree(im3DVertices);
    }
}


RwFrame* CMTCharacter::HierarchyRender(RwFrame *frame, void * data __RWUNUSED__)
{
    RwMatrix *mat[2];
    RwIm3DVertex    imVertex[2];
    RwRGBA Color = {255, 0, 0, 255};

    mat[0] = RwFrameGetLTM(RwFrameGetParent(frame));
    mat[1] = RwFrameGetLTM(frame);

    RwIm3DVertexSetPos(&imVertex[0],
        (RwMatrixGetPos(mat[0]))->x,
        (RwMatrixGetPos(mat[0]))->y,
        (RwMatrixGetPos(mat[0]))->z);

    RwIm3DVertexSetRGBA(&imVertex[0], Color.red, Color.green, Color.blue, Color.alpha);

    RwIm3DVertexSetPos(&imVertex[1],
        (RwMatrixGetPos (mat[1]))->x,
        (RwMatrixGetPos (mat[1]))->y,
        (RwMatrixGetPos (mat[1]))->z);

    RwIm3DVertexSetRGBA(&imVertex[1], Color.red, Color.green, Color.blue, Color.alpha);

    if( RwIm3DTransform(imVertex, 2, (RwMatrix *)NULL, 0) )
    {
        RwIm3DRenderPrimitive(rwPRIMTYPELINELIST);
        RwIm3DEnd();
    }

    SkeletonRender(RwFrameGetLTM(frame), RpHAnimGetHierarchy(frame));

    return RwFrameForAllChildren(frame, HierarchyRender, NULL);

}

void CMTCharacter::Set2Side(RwChar* chAtomicName, RwBool b2Side)
{
    if(!chAtomicName)
        return;

    RpAtomic* pAtomic = m_charInfo.GetAtomicByName(chAtomicName);
    if(!pAtomic)
        return;

    RwInt32 flag = RpNtlAtomicGetRenderFlag(pAtomic);

    if(b2Side)
    {
        flag |= NTL_TWOSIDE;        
    }
    else if(flag & NTL_TWOSIDE)
    {
        flag ^= NTL_TWOSIDE;        
    }

    RpNtlAtomicSetRenderFlag(pAtomic, flag);
}

void CMTCharacter::Set2SideEdge(RwChar* chAtomicName, RwBool b2SideEdge)
{
    if(!chAtomicName)
        return;

    RpAtomic* pAtomic = m_charInfo.GetAtomicByName(chAtomicName);
    if(!pAtomic)
        return;

    RwInt32 flag = RpNtlAtomicGetRenderFlag(pAtomic);

    if(b2SideEdge)
    {
        flag |= NTL_TWOSIDE_EDGE;        
    }
    else if(flag & NTL_TWOSIDE_EDGE)
    {
        flag ^= NTL_TWOSIDE_EDGE;        
    }

    RpNtlAtomicSetRenderFlag(pAtomic, flag);
}

void CMTCharacter::SetAlphaTest(RwChar* chAtomicName, RwBool bAlpha)
{
    if(!chAtomicName)
        return;

    RpAtomic* pAtomic = m_charInfo.GetAtomicByName(chAtomicName);
    if(!pAtomic)
        return;

    RwInt32 flag = RpNtlAtomicGetRenderFlag(pAtomic);

    if(bAlpha)
    {
        flag |= NTL_ALPHA_TEST;
    }
    else if(flag & NTL_ALPHA_TEST)
    {
        flag ^= NTL_ALPHA_TEST;
    }

    RpNtlAtomicSetRenderFlag(pAtomic, flag);
}

RwBool CMTCharacter::SetAnim(RwUInt32 uiKey)
{
    if( !m_pClump)
        return FALSE;

	//Animation ������ �ְ� �ٽ� ������ �ɰ�� ������ ������ ���� (by HoDong 2006.4.26)
    //if(m_uiCurrentAnimKey == uiKey)
       // return TRUE;
    
    if(m_bAnim == FALSE)
    {
        Helper_SetHierarchyClumpSkin(m_pClump, m_pBaseHierarchy);
        RpHAnimHierarchySetFlags( m_pBaseHierarchy,
            (RpHAnimHierarchyFlag)(RpHAnimHierarchyGetFlags(m_pBaseHierarchy) | 
            rpHANIMHIERARCHYUPDATELTMS | 
            rpHANIMHIERARCHYUPDATEMODELLINGMATRICES));
        RpHAnimHierarchyAttach(m_pBaseHierarchy);

		// Animationó���� �̷������� �ϸ� �ȴ�. (by HoDong 2006.4.26)
		//m_pProperty->GetAnimTable()->SetAnimPath(m_pProperty->GetAnimPath());
		m_InstanceAnimTable.Create(m_pProperty->GetAnimTable());
		
		::SetCurrentDirectoryA(CModelToolApplication::GetInstance()->GetWorkDir());

		if(!CreateAnim(uiKey))
			NTL_RETURN(FALSE);

		m_bAnim = TRUE;

		// Default Animation�� Load�� �ǰ� ������ �Ǿ��� ���(by HoDong 2006.4.26)
		m_bResourceLoad = TRUE;
    }
	else
	{
		::SetCurrentDirectoryA(CModelToolApplication::GetInstance()->GetWorkDir());

		CNtlTypeAnimTable *pTypeAnimTable = m_pProperty->GetAnimTable();
		STypeAnimData *pTypeAnimData = pTypeAnimTable->Get(uiKey);
		if(pTypeAnimData != NULL)
		{
			// ���� Animaiton�� �о���� ���(by HoDong 2006.4.26)
			pTypeAnimData->m_bReLoad = FALSE;
			SetBaseAnimation(uiKey);
		}
	}

    return TRUE;
}

void CMTCharacter::RenderSelectedBoneScale(RpHAnimHierarchy *pHierarchy, RwInt32 nCurrentBone)
{
	if(pHierarchy == NULL)
		return;

	RwMatrix    *matrices = RpHAnimHierarchyGetMatrixArray(pHierarchy);
    RwV3d       *rootPos;

    /*
     *  Render the currently selected bone as white lines to child bones.
     *  First set the vertex for the origin of the current bone.
     */
    rootPos = RwMatrixGetPos(&matrices[nCurrentBone]);
    RwIm3DVertexSetPos(&Im3DVerts[0], rootPos->x, rootPos->y, rootPos->z);
    NumIm3DVerts = 1;

    /* 
     *  Does the current bone have any children?
     */
    if (pHierarchy->pNodeInfo[nCurrentBone].flags & rpHANIMPOPPARENTMATRIX)
    {
        RwV3d    pos;

        /*
         *  No children. We just draw a line along the bone's x axis.
         */
        pos = *rootPos;
        RwV3dIncrementScaled(
            &pos, RwMatrixGetRight(&matrices[nCurrentBone]), 0.1f);
        RwIm3DVertexSetPos(&Im3DVerts[NumIm3DVerts], pos.x, pos.y, pos.z);
        NumIm3DVerts++;
    }
    else
    {
        RwInt32     parentsOnStack = 0;
        RwUInt32    currentIndex = nCurrentBone;

        /*
         *  Pick up all children of the current bone and draw a line
         *  to each of them.
         */
        while (parentsOnStack > -1)
        {
            RwUInt32    flags;

            currentIndex++;
            flags = pHierarchy->pNodeInfo[currentIndex].flags;

            /*
             *  Is this bone an immediate child of the current bone?
             */
            if (parentsOnStack == 0)
            {
                RwV3d   *pos = RwMatrixGetPos(matrices + currentIndex);

                RwIm3DVertexSetPos(&Im3DVerts[NumIm3DVerts], 
                    pos->x, pos->y, pos->z);
                NumIm3DVerts++;

                if (!(flags & rpHANIMPUSHPARENTMATRIX))
                {
                    /* 
                     *  This was the last sibling, so quit.
                     */
                    break;
                }
            }

            if (flags & rpHANIMPUSHPARENTMATRIX)
            {
                parentsOnStack++;
            }

            if (flags & rpHANIMPOPPARENTMATRIX)
            {
                parentsOnStack--;
            }
        }
    }

    /*
     *  Now render the lines.
     */
    if (RwIm3DTransform(Im3DVerts, NumIm3DVerts, NULL, 
            rwIM3D_ALLOPAQUE | rwIM3D_VERTEXXYZ))
    {
        RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void *) FALSE);
        RwIm3DRenderIndexedPrimitive(rwPRIMTYPELINELIST, Im3DIndices, 
            (NumIm3DVerts - 1) << 1);
        RwIm3DEnd();
        RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void *) TRUE);
    }
}


RwChar* CMTCharacter::GetBoneName(int nBoneIndex)
{
    if(nBoneIndex < 0)
        return NULL;

    RwFrame* pFrame = m_pBaseHierarchy->pNodeInfo[nBoneIndex].pFrame;
    if(!pFrame)
        return NULL;

    RwChar* sBoneName = Helper_BoneName(pFrame);
    
    return sBoneName;
}

void CMTCharacter::ResetProperty()
{
    if(!m_pProperty)
        return;
    
    //  �켱�� �ִϸ��̼� �����Ϳ� BoneData�� �ʱ�ȭ �Ѵ�.
    CNtlTypeAnimTable* pAnimTable = m_pProperty->GetAnimTable();
    pAnimTable->Destroy();

    STypeBoneData newBoneData;
    STypeBoneData* pBoneData = m_pProperty->GetBoneScaleData();
    *pBoneData = newBoneData;
}