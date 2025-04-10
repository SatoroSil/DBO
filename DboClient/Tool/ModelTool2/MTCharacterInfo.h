#pragma once

#include <vector>
#include "NtlAtomic.h"
#include "NtlPLGlobal.h"
#include "NtlPLMaterialExtWrapper.h"
#include "NtlPLResourceManager.h"
#include "NtlPLEntityRenderHelpers.h"

typedef std::map<std::string, RwFrame *>				FRAME_TABLE_MAP;
typedef std::map<std::string, RwFrame *>::iterator		FRAME_TABLE_ITER;

typedef std::map<std::string, RpMaterial *>				MATERIAL_TABLE_MAP;
typedef std::map<std::string, RpMaterial *>::iterator	MATERIAL_TABLE_ITER;

typedef std::map<std::string, RpAtomic *>				ATOMIC_TABLE_MAP;
typedef std::map<std::string, RpAtomic *>::iterator		ATOMIC_TABLE_ITER;
typedef std::map<RpMaterial*, RpAtomic*>                MATERIAL_ATOMIC_MAP;
typedef std::map<RpMaterial*, RpAtomic*>::iterator      MATERIAL_ATOMIC_MAP_ITER;

/**
 * \ingroup ModelTool
 * \brief Clump(ĳ����) ���� ������ �����ϴ� Ŭ���� 
 * \date 2006-04-10
 * \author agebreak
 */
class CMTClump
{
public:
	CMTClump(void);
	virtual ~CMTClump(void);
    static void CreateCartoon();                                 ///< Toon ��ü�� �����Ѵ�
    static void DestroyCartoon();                                ///< Cartoon ��ü�� �����Ѵ�.
    static void SetToonThickness(RwReal fThickness);             ///< Toon Thickness�� �����Ѵ�.
    static void SetToonInkColor(RwRGBA color);                   ///< Toon Ink�� Color�� �����Ѵ�
	static SToonData* GetToonData() {return &m_ToonData;}		 

public:
    RwBool      Load(RwChar* szFileName);                        ///< Clump ������ Load�Ѵ�,
    RwBool      Save(RwChar* szFileName);                        ///< Clump ������ Save�Ѵ�.
	RwBool		Create(RpClump* pClump, RwChar* szClumpName);    ///< ���̺� ������ �����Ѵ�.
	void		Destroy();								         ///< ������ �����Ѵ�.

	RwFrame*	GetFrameByName(RwChar* chFrameName);	         ///< Ư�� Frame�� ��ȯ�Ѵ�.
    RwBBox      GetDefaultBBox()  {return m_bboxCharacter;};     ///< ĳ������ Default BBox�� ��ȯ�Ѵ�.

    // Clump ���� �޼���
    RpClump*    GetClump() {return m_pClump;}                                   ///< RpClump ��ü�� ��ȯ�Ѵ�.
    const char* GetClumpName() {return m_strClumpName;}                         ///< Clump�� PathName�� ��ȯ�Ѵ�.
    void        SetVisible(RwBool bVisible);                                    ///< Clump�� ������ ������ �����Ѵ�.
    void        SetCartoon();                                                   ///< Toon �������� �����Ѵ�.
    void        SetViewEdge(RwBool bVisible);                                   ///< Toon Edge�� On/Off�� �����Ѵ�    

    // Atomic ����
    RpAtomic*	GetAtomicByName(RwChar* chAtomicName);	                        ///< Ư�� Atomic�� ��ȯ�Ѵ�.
    RpAtomic*   GetAtomicByMaterial(RpMaterial* pMaterial);                     ///< �ش� Material�� �������ִ� Atomic�� ��ȯ�Ѵ�.
    std::vector<char*>    GetAtomicNames();                                     ///< Atomic���� �̸��� ��ȯ�Ѵ�.
    RwBool	    RemoveAtomic(RwChar* chAtomicName);	                            ///< Atomic�� Clump���� �����Ѵ�.
    RwBool      CollisionDataBuild(RwChar* szAtomicName);                       ///< Collision Tree �����͸� Build�Ѵ�.
    void        SetAtomicFlag(ENtlAtomicFlag nFlagType, RwChar* szAtomicName, RwBool bEnable); ///< Atomic Flag�� �����Ѵ�.    
    void        SetAtomicFlag(ENtlAtomicFlag nFlag, RpAtomic* pAtomic, RwBool bEnable);
	void		RenderWireFrame();												///< Wireframe�� �������Ѵ�.
    

    // Material ����
    RpMaterial* GetMaterialByName(RwChar* chMaterialName);                      ///< Ư�� Material�� ��ȯ�Ѵ�.
    std::vector<char*>    GetMaterialNames();                                   ///< Material���� �̸��� ��ȯ�Ѵ�    
    void        SetMaterialColor(RwChar* chMaterialName, int r, int g, int b);  ///< Material�� Color�� �����Ѵ�.
    RwBool      SetMultiTexture(RwChar* chMaterialName, RwChar* chTextureName, RwChar* chTexturePath); ///< Material�� MultiTexture�� �����Ѵ�.
    
    // �ٿ�� �ڽ� ����
    void	    CreateBB(RwChar* chAtomicName);				                	///< �ش� Atomic�� BB�� �����Ѵ�.
    void        ClearBB();								    	                ///< �ٿ�� �ڽ� ������ ����.
    void        RenderAtomicBB();                                               ///< ������ Atomic BB�� �������Ѵ�.
    void        RenderBB(RwBBox* pBBox, int r = 255, int g = 255, int b = 0);	///< �ٿ�� �ڽ��� ������ �Ѵ�.	
    RwReal      GetMaxWidthHeight();                                            ///< Clump�� Width, Height�� ū���� ��ȯ�Ѵ�.

    // ȭ�鿡 ǥ���� ���� ����
    void        DisplayInfo(RtCharset* pCharSet);                               ///< Clump ������ ȭ��� ǥ���Ѵ�.

protected:
	void		SetClumpInfo();							///< Clump ���� ������ Map�� �����Ѵ�.
    void        UpdateHeightWidth();                    ///< ���̿� ���� ������ ������Ʈ �Ѵ�.
    void        UpdateAtomicBB();                       ///< AtomicBB���� Update�Ѵ�.

    // CallBack �Լ���
    static RpAtomic*	GetClumpAllAtomics(RpAtomic* pAtomic, void* pData);		///< Clump���� ��� Atomic�� ������ �����ϴ� �ݹ� �Լ�
    static RwFrame*     GetChildFrame(RwFrame* pFrame, void* pData);
    static RpMaterial*  GetAllMaterials(RpMaterial* material, void* pData);


public:
	FRAME_TABLE_MAP		m_mapFrameTable;				///< Frame ���̺�
	MATERIAL_TABLE_MAP	m_mapMaterialtable;				///< Material ���̺�
	ATOMIC_TABLE_MAP	m_mapAtomicTable;				///< Atomic ���̺�
    MATERIAL_ATOMIC_MAP m_mapMaterialAtomicTable;       ///< Material - Atomic ���̺�

    static RpAtomic*    m_pTempAtomic;                  ///< Material - Atomic MAP�� ����� ���� �ӽ� Atomic ������

protected:
    static SToonData    m_ToonData;                     ///< Toon�� ���� ��ü
    RwChar              m_strClumpName[1024];           ///< Clump�� �̸�
	RpClump*			m_pClump;		    			///< ������ �о�� Clump
    CNtlPLResource*     m_pResourceClump;               ///< Clump Load ����� Resource

    RwBool              m_bVisible;                     ///< ȭ�鿡 ��Ÿ���� ����
    std::vector<RwChar*>  m_vecBB;				        ///< �ٿ�� �ڽ� ����Ʈ        

    // ȭ�鿡 ǥ���� ������
    static int          m_nTotalTriangels;              ///< ��ü Triangle ����
    static int          m_nTotalVertices;               ///< ��ü Vertex ����

    RwBBox              m_bboxCharacter;                ///< ĳ������ Default BBox
    RwReal              m_fClumpHeight;                 ///< Clump�� ����
    RwReal              m_fClumpWidth;                  ///< Clump�� �¿� ����
    RwReal              m_fClumpDepth;                  ///< Clump�� �յ� ����

    std::vector<RwTexture*> m_vMultiTexture;             ///< MultiTexture ����Ʈ (���߿� ������ ���� �ʿ��ϴ�)

};
