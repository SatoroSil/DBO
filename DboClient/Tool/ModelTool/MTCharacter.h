#pragma once

#include "MTDef.h"
#include "NtlPLCharacter.h"
#include "MTCharacterInfo.h"

#define DISPATCHSIZE (1000)

typedef std::map<int, std::string>      BONENAME_MAP;

/*!
 * \brief
 * Model Tool Character ���� Ŭ����
 * 
 * CNtlPLCharacter�� ��ӹ޾Ƽ� �ʿ��� �κ��� �������̵��Ͽ� ����Ѵ�.
 * 
 * \remarks
 * Write remarks for CMTCharacter here.
 * 
 * \see
 * CNtlPLCharacter
 */
class CMTCharacter : public CNtlPLCharacter
{
public:

	// CNtlPLCharacter Ŭ������ �޸�Ǯ�� ������ �־. ������ �������̵� ����.-_-a
	void* operator new(size_t size);
	void operator delete(void *pObj);

	CMTCharacter(void);
	virtual ~CMTCharacter(void);
	
	//--- �������̵�
	virtual RwBool Create(const SPLEntityCreateParam *pParam  = NULL );		///< �ʱ�ȭ �۾��� ���ش�.
	virtual RwBool Update(RwReal fElapsed);
	virtual RwBool Render(void);    
	//--------------------------------------------------------------------

	RwBool  LoadClump(RwChar* filename);				                	///< clump ������ �ε��Ѵ�.	
    RwBool  SaveClump(RwChar* fileName);                                    ///< Clump ������ �����Ѵ�.
	RwBool	RemoveAtomic(RwChar* chAtomicName);			                	///< Atomic�� Clump���� �����Ѵ�.
    void    UpdateClumpInfo();                                              ///< Clump�� ������ ���� �����Ѵ�.
    void    DisplayMaterialAttribute(RwChar* chMaterialName);               ///< Material�� ���� Attribute�� ǥ���Ѵ�.
    void    DisplayInfo(RtCharset* pCharSet);                               ///< ȭ�鿡 ������ ǥ���Ѵ�.

    // Clump �Ӽ� ����
    void    Set2Side(RwChar* chAtomicName, RwBool b2Side);                  ///< 2 Side �÷��׸� �����Ѵ�.
    void    Set2SideEdge(RwChar* chAtomicName, RwBool b2SideEdge);          ///< 2 Side Edge �÷��׸� �����Ѵ�.
    void    SetAlphaTest(RwChar* chAtomicName, RwBool bAlpha);              ///< Alpha Test �÷��׸� �����Ѵ�.
    void    SetVisible(RwBool bVisible);                                    ///< ȭ�鿡 ���� ǥ�� ������ �����Ѵ�.

    // Material ����
    void    SetMaterialColor(RwChar* chMaterialName, int r, int g, int b);  ///< Material�� Color�� �����Ѵ�.
    RwBool  SetMultiTexture(RwChar* chMaterialName, RwChar* chTextureName, RwChar* chTexturePath); ///< Material�� MultiTexture�� �����Ѵ�.

    // �ٿ�� �ڽ� ����
	void	CreateBB(RwChar* chAtomicName);				                	///< �ش� Atomic�� BB�� �����Ѵ�.
	void    ClearBB();								    	                ///< �ٿ�� �ڽ� ������ ����.

    // WireFrame ������ ����
    void              RenderWireFrame(void);                                ///< WireFrame�� ������ �Ѵ�.
    static RpAtomic*  AtomicRenderWireMesh(RpAtomic *atomic, void * data);    

    // Hierarchy ������ ����
    void             RenderHierarchy(void);                                 ///< Hierarchy�� ������ �Ѵ�.
    static RpAtomic* AtomicRenderSkeleton(RpAtomic *atomic, void * data);
    static RwFrame*  HierarchyRender(RwFrame *frame, void * data);
    static void      SkeletonRender(RwMatrix *LTM, RpHAnimHierarchy *hier);

    // Bone ����
    RwInt32          GetBoneNum() {return m_nBoneCount;};                      ///< Bone�� ������ ��ȯ�Ѵ�.    
    RwChar*          GetBoneName(int nBoneIndex);                            ///< Bone�� �̸��� ��ȯ�Ѵ�.
    void             SetSelectBone(int nBoneIndex) {m_nCurrentSelectBoneIndex = nBoneIndex;}; ///< �������� Bone�� �����Ѵ�.
    void             SetRenderBone(RwBool bRender) {m_bRenderBone = bRender;}; ///< Bone�� ������ ������ �����Ѵ�.
    
    

    // Animation ����   
    RwBool          SetAnim(RwUInt32 uiKey);                                 ///< �ִϸ��̼��� �𵨿� �����Ѵ�.    

    // ��ũ��Ʈ ����
    void            ResetProperty();                                        ///< ĳ���� ������Ƽ�� ��� ������ �����Ѵ�.
    CNtlPLCharacterProperty* GetProperty() {return m_pProperty;};           ///< ĳ������ ������Ƽ�� �����͸� ��ȯ�Ѵ�.

protected:
	//--- �������̵�
	virtual RwBool CreateCartoon();							///< ī���� �����Ѵ�.
	virtual RwBool CreateMesh(const char *szDffName);		///< Mesh�� �ε��Ѵ�
	//----------------------------------------------------------------------
	
	void   RenderBB(RwBBox* pBBox);		        			///< �ٿ�� �ڽ��� ������ �Ѵ�.
	void   DisplayClumpInfo();								///< Clump�� ������ ǥ���Ѵ�.

    // Bone ����    
    void   RenderSelectedBoneScale(RpHAnimHierarchy *pHierarchy, RwInt32 nCurrentBone);    ///< Bone�� ������ �Ѵ�.

    
	
protected:
	MTCharacterInfo		m_charInfo;							///< ĳ���� ���ҽ� ������ �����ϴ� ��ü
	std::vector<RwBBox> m_vecBB;							///< �ٿ�� �ڽ� ����Ʈ        
    std::vector<RwTexture*> m_vMultiTexture;                ///< MultiTexture ����Ʈ (���߿� ������ ���� �ʿ��ϴ�)
    bool                m_bAnim;                            ///< �ִϸ��̼��� ���� ����
    RtAnimAnimation*    m_pAnimation;                       ///< ĳ���Ϳ� �����ϴ� �ִϸ��̼�

    // Bone ����    
    RwInt32             m_nCurrentSelectBoneIndex;          ///< ���� ���õ� Bone�� Index;
    RwBool              m_bRenderBone;                      ///< Bone�� ������ ����
    RwBool              m_bVisible;                         ///< ���� ȭ�鿡 ǥ�õǴ��� ����
    int                 m_nBoneCount;

};
