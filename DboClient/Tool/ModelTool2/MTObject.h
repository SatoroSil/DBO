#pragma once

#include "NtlPLObject.h"
#include "MTCharacterInfo.h"

#define OBJECT_MESH_PATH    ".\\Object\\Mesh\\"
#define OBJECT_TEXTURE_PATH ".\\Texture\\Object\\;"

class CMTObject : public CNtlPLObject
{
public:
    CMTObject(void);
    virtual ~CMTObject(void);

    void* operator new(size_t size);
    void operator delete(void *pObj);

    virtual RwBool LoadClump(RwChar* szFileName);
    virtual RwBool Create(const SPLEntityCreateParam * pParam  = NULL);
    virtual RwBool Update(RwReal fElapsed);
    virtual void   SetVisible(BOOL bVisible);
    virtual int	   CallBackBaseAnim(void* pEventData);	            	///< Animation Event�� CallBack �Լ�    
    virtual RwBool SetTriggerAnimation(RwUInt32 uiAnimKey, RwReal fStartTime = 0.0f, RwBool bLoop = TRUE);				///< Trigger Animation�� ����Ѵ�.
    virtual void   SetWeightAlpha(RwReal fWeightValue);							///< Weight Alpha


    CMTClump*      GetClumpInfo() {return &m_MTClump;}                      ///< CMTClump ��ü�� ��ȯ�Ѵ�.
    ENTITY_ATOMIC_VEC   GetAtomicList() {return m_vecAtomicList;}           ///< Atomic List�� ��ȯ�Ѵ�.      (Alpha Event���� Atomic Index ������ ���߱� ���ؼ� �߰�)
	
	virtual const RwBBox* GetBoundingBox(void);
	void	RenderBBox();						                            ///< ������ BBox�� �������Ѵ�.
	void	RenderWireFrame();					                            ///< Object�� Wireframe�� ������ �Ѵ�.

    // Link Effect ����
    CNtlInstanceEffect* GetLinkEffectFromName(RwChar* szName);              ///< Name�� �ش��ϴ� LinkEffect�� ��ȯ�Ѵ�.
    void    AddLoopSound(SOUND_HANDLE hSound) {m_listLoopSound.push_back(hSound);}             ///< LoopSound List�� SoundHandle�� �߰��Ѵ�.
    void    ClearLoopSound();                                                                  ///< LoopSound List�� ����ִ� LoopSound���� �Ҹ��Ѵ�.

    // ���������� �ø��� ���� �ʴ´�.
    virtual RwBool CullingTest(RwCamera* pRwCamera, RwUInt16 uiRenderFrame) {return FALSE;}
    virtual RwBool CullingTest(RwCamera* pRwCamera) {return FALSE;}
	
protected:
    void    CalcBBox();                                                     ///< �⺻ BBox�� ����ؼ�, Property�� �����Ѵ�.    

    virtual void OnEventAlphaFade(SEventAlpha* pEventAlpha);                ///< Model Tool���� Alpha Fade�� �ڱ� ��ü�� ó���Ѵ�.    

protected:
    CMTClump m_MTClump;                         ///< Clump ���� ��ü   
};

