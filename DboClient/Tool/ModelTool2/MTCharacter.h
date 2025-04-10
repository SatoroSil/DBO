#pragma once

#include "MTDef.h"
#include "NtlPLCharacter.h"
#include "MTCharacterInfo.h"
#include "NtlInstanceTraceSystem.h"

class CNtlPLEntityAlphaWeightBlend;

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
    virtual void   Destroy();
	virtual RwBool Update(RwReal fElapsed);
	virtual RwBool Render(void);        
    virtual RwBool	CullingTest(RwCamera* pRwCamera, RwUInt16 uiRenderFrame) {return !IsVisible();}
    virtual RwBool	CullingTest(RwCamera* pRwCamera) {return !IsVisible();}
	//--------------------------------------------------------------------

	RwBool  LoadClump(RwChar* filename);				                	///< clump ������ �ε��Ѵ�.	    
    RwBool  SaveClump(RwChar* fileName);                                    ///< Clump ������ �����Ѵ�.    	
    void    UpdateClumpInfo();                                              ///< Clump�� ������ ���� �����Ѵ�.
    
    void    DisplayInfo(RtCharset* pCharSet);                               ///< ȭ�鿡 ������ ǥ���Ѵ�.
    CMTClump* GetClumpInfo() {return &m_charInfo;}                           ///< CharInfo ��ü�� ��ȯ�Ѵ�.    
    ENTITY_ATOMIC_VEC   GetAtomicList() {return m_vecAtomicList;}           ///< Atomic List�� ��ȯ�Ѵ�.      (Alpha Event���� Atomic Index ������ ���߱� ���ؼ� �߰�)

    // Clump �Ӽ� ����
    char*   GetClumpName() {return m_strClumpPathName;};                     ///< Clump�� Name�� ��ȯ�Ѵ�. (��ü ���)    
    void    SetVisible(RwBool bVisible);                                    ///< ȭ�鿡 ���� ǥ�� ������ �����Ѵ�.
    void    SetAlpha(RwUInt8 byValue);                                      ///< ���ĸ� �����Ѵ�.
    void    SetWeightAlpha(RwReal fWeightValue);							///< Weight Alpha

    // �ٿ�� �ڽ� ����
    void    RenderAnimBBox();                                               ///< ĳ������ Animation BBox�� �������Ѵ�.
    RwBBox  CreateDefaultAnimBBox();                                        ///< ĳ������ �⺻ Animation BBox�� �����.
    
    // WireFrame ������ ����
    void              RenderWireFrame(void);                                ///< WireFrame�� ������ �Ѵ�.    

    // Hierarchy ������ ����
    void             RenderHierarchy(void);                                 ///< Hierarchy�� ������ �Ѵ�.
    static RpAtomic* AtomicRenderSkeleton(RpAtomic *atomic, void * data);
    static RwFrame*  HierarchyRender(RwFrame *frame, void * data);
    static void      SkeletonRender(RwMatrix *LTM, RpHAnimHierarchy *hier);

    // Bone ����
    RwInt32          GetBoneNum() {return m_nBoneCount;};                      ///< Bone�� ������ ��ȯ�Ѵ�.        
    RwBool           SetSelectBone(int nBoneIndex);                             ///< �������� Bone�� �����Ѵ�.
    void             SetRenderBone(RwBool bRender) {m_bRenderBone = bRender;}; ///< Bone�� ������ ������ �����Ѵ�.
    
    // Animation ����   
    RwBool          SetAnim(RwUInt32 uiKey);                                 ///< �ִϸ��̼��� �𵨿� �����Ѵ�.    
    RwUInt32        GetCurrentAnimKey() {return m_uiCurrentAnimKey;}         ///< ���� Play�ǰ� �ִ� Anim Key�� ��ȯ�Ѵ�,.

    // ��ũ��Ʈ ����
    void            ResetProperty();                                        ///< ĳ���� ������Ƽ�� ��� ������ �����Ѵ�.
    CNtlPLCharacterProperty* GetProperty() {return m_pProperty;};           ///< ĳ������ ������Ƽ�� �����͸� ��ȯ�Ѵ�.

    // Item ����    
    CNtlPLItem*	    SetChangeEquipItemForTool(CNtlPLItem *pItem);           ///< Item�� �����Ѵ�.
    virtual RwBool	SetRemoveEquipItem(CNtlPLItem *pItem);                  ///< Item�� �����Ѵ�.

    // Link Effect ����
    CNtlInstanceEffect* GetLinkEffectFromName(RwChar* szName);              ///< Name�� �ش��ϴ� LinkEffect�� ��ȯ�Ѵ�.

    // Hissidian ������ ����
    void            SetRenderHissidian(SEventAnimHit* pEventHissidan) {m_pEventHissidianDir = pEventHissidan;}      ///< Hissidan��  �������ϱ� ���� �̺�Ʈ�� �����Ѵ�.

    // Color ����
    virtual void SetSkinColor(RwUInt8 byRed, RwUInt8 byGreen, RwUInt8 byBlue);							///< Skin Color
    virtual void SetHeadColor(RwUInt8 byRed, RwUInt8 byGreen, RwUInt8 byBlue);							///< Head Color

	// �������� �ӽ������� ȯ����� �����ֱ� ���� method
	void SetEnvMap(RwChar* _pName);

protected:
	//--- �������̵�	
	virtual RwBool CreateMesh(const char *szDffName);		///< Mesh�� �ε��Ѵ�
    virtual RwBool SetBaseAnimation(RwUInt32 uiAnimKey, RwReal fStartTime = 0.f , RwBool bLoop = TRUE );
	//----------------------------------------------------------------------

    // Bone ����    
    void   RenderSelectedBoneScale(RpHAnimHierarchy *pHierarchy, RwInt32 nCurrentBone);    ///< Bone�� ������ �Ѵ�.
    
	virtual int	   CallBackBaseAnim(void* pEventData);

    // Event ó�� ���� �������̵�
    virtual void   OnEventHit(SEventAnimHit* pEventHit);    
    virtual void   OnEventWeightTime(SEventWeightTime* pEventTime);
    virtual void   OnEventAlphaFade(SEventAlpha* pEventAlpha);    
    virtual void   OnEventPostEffect(SEventPostEffect* pEventPostEffect);
    virtual void   OnEventColorChange(SEventColorChange* pEventColorChange);                    ///< ���� ���� �̺�Ʈ ó��
    virtual void   OnEventStretch(SEventStretch* pEventStretch);                                ///< �� �þ�� �̺�Ʈ ó��

    void   RenderHissidainDir();                        ///< Hissidan ������ �������Ѵ�.
    void   UpdateAtomicsColor();                        ///< Color ����
    void   UpdateStretch(RwReal fElapsed);              ///< Stretch �̺�Ʈ ����
    void   UpdateCameraShake(RwReal fElapse);           ///< ī�޶� ����ũ �̺�Ʈ�� ó���Ѵ�. 

protected:
	CMTClump		    m_charInfo;							///< ĳ���� ���ҽ� ������ �����ϴ� ��ü	
    
    bool                m_bAnim;                            ///< �ִϸ��̼��� ���� ����
    RtAnimAnimation*    m_pAnimation;                       ///< ĳ���Ϳ� �����ϴ� �ִϸ��̼�
	RwUInt32			m_uiCurBaseAnimKey;

    RwBool              m_bRemoveColorChange;               ///< �÷����� �̺�Ʈ�� �������� �÷���    

    // Bone ����    
    RwInt32             m_nCurrentSelectBoneIndex;          ///< ���� ���õ� Bone�� Index;
    RwBool              m_bRenderBone;                      ///< Bone�� ������ ����        
    char                m_strClumpPathName[1024];            ///< Clump�� ��ü PathName
    RwUInt32            m_uiCurrentAnimKey;                  ///< ���� Play �ǰ� �ִ� Anim Key

    SEventAnimHit*      m_pEventHissidianDir;               ///< Hissidian�� ������ �������ϱ� ���� �̺�Ʈ ������

    CNtlPLEntityAlphaWeightBlend* m_pAlphaBlend;              ///< ī�޶� �Ÿ�üũ ���� ������ ���� ��ü

    // Stretch Event ����
    RwBool              m_bStretchUpdate;                   ///< Stretch �̺�Ʈ�� ���� �÷���
    RwBool              m_bStretchPulling;                  ///< Stretch �̺�Ʈ�� ���� �÷���
    SEventStretch*      m_pStretchEvent;                    ///< Stretch �̺�Ʈ
    RwReal              m_fStretchPullingSpeed;             ///< Stretch �̺�Ʈ
    RwBool              m_bOrgBoneScale;                    ///< ������ �� ������ �÷���
    RwReal              m_fOrgBoneLength[3];                ///< ������ �� ����
    RwReal              m_fOrgBoneWidth[3];                 ///< ������ �� �β�

    // ī�޶� ����ũ ����
    RwReal              m_fShakeFactor;                     ///< ī�޶� ����ũ ����
    RwReal              m_fShakeMaxHeight;                  ///< ī�޶� ����ũ �ִ밪 ����
    RwReal              m_fShakeElapsedTime;                ///< ī�޶� ����ũ�� ElapsedTime    
};
