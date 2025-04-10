#ifndef _MODEL_TOOL_APPLICATION_
#define _MODEL_TOOL_APPLICATION_

#include <rwcore.h>
#include <rpworld.h>
#include <rphanim.h>
#include <rptoon.h>
#include <rpskin.h>
#include <rpUsrdat.h>
#include <rpid.h>
#include <ddraw.h>

#include "Resource.h"
#include "MiniDump.h"
#include "NtlApplication.h"
#include "NtlPLApi.h"

#include "NtlPLVisualManager.h"
#include "MTPropertyContainer.h"
#include "NtlPLDecal.h"
#include "NtlDecalManager.h"

#include "NtlPostEffectCamera.h"
#include "ToolCamera.h"

#include "NtlPLCharacter.h"
#include "NtlPLCharacterParser.h"


#include "NtlAtomic.h"
#include "ntlworldplugin.h"

#include "MTCharacter.h"
#include "MTObject.h"
#include "MTItem.h"
#include "NtlPLMaterialExtWrapper.h"
#include "NtlPLDummyWorld.h"
#include "NtlPLCameraRenderTexture.h"

#include "NtlPLResourceManager.h"
#include "MTItemPool.h"
#include "NtlPLWorldEntity.h"

#define GET_KEY_REPEAT(lParam) (lParam & 0x0000ffff)

/*!
 * \brief
 * Model Tool�� App Ŭ����
 * 
 * NtlApplication Ŭ�������� ��ӹ޾Ƽ� Render Ware�� Application Class�� �ȴ�.
 * 
 * \remarks
 * Write remarks for CModelToolApplication here.
 * 
 * \see
 * CNtlApplication
 */
class CModelToolApplication : public CNtlApplication
{
public:    

public:
	CModelToolApplication(void);
	virtual ~CModelToolApplication(void);

	virtual void Destroy();											///< ������ ��ü���� �ı��Ѵ�.
	RwBool	Update(RwReal fTime, RwReal fElapsedTime);				///< Update Method
	RwBool	OnIdle() {return CNtlApplication::Update();}			///< Idle Update 
    RwBool  Resize(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer); ///< ȭ�� ũ�⸦ �����Ҷ� ȣ��ȴ�.

	// Path ����
    char*	GetWorkDir() {return m_chCurrentPath;};					///< ���� ������ ��θ� ��ȯ�Ѵ�.
    char*   GetTexturePath();                                       ///< Texture Path�� ��ȯ�Ѵ�.
	
	/// �̱��� ȣ�� �Լ�
	static	CModelToolApplication* GetInstance() {return (CModelToolApplication*)m_pInstance; }
	CMTCharacter* GetCharcter() {return m_pCharacter;};				///< ĳ���� ��ü�� ��ȯ�Ѵ�.

    // �÷��� ����
    void SetWorldView(RwBool bView);        ///< ���� ǥ�� ������ �����Ѵ�.
    BOOL GetWorldView() {return m_bViewWorld;};                     ///< ���� ǥ�� ������ ��ȯ�Ѵ�.

    void SetWireView(RwBool bView) {m_bViewWire = bView;};          ///< Wireframe ǥ�� ������ �����Ѵ�.
    BOOL GetWireView() {return m_bViewWire;};                       ///< Wireframe ǥ�� ������ ��ȯ�Ѵ�.

    void SetHierarchyView(RwBool bView) {m_bViewHierarchy = bView;}; ///< Hierarchy ǥ�� ������ �����Ѵ�.
    BOOL GetHierarchyView() {return m_bViewHierarchy;};              ///< Hierarchy ǥ�� ������ ��ȯ�Ѵ�.

    void SetBBoxView(RwBool bView) {m_bViewBBox = bView;};          ///< ĳ������ BBox ǥ�� ������ �����Ѵ�.
    BOOL GetBBoxView() {return m_bViewBBox;};                       ///< ĳ������ BBox ǥ�� ������ ��ȯ�Ѵ�.

    void SetToonView(RwBool bView);                                 ///< Toon ������ ������ �����Ѵ�.
    BOOL GetToonView() {return m_bViewToon;}                        ///< Toon ���� ������ ��ȯ�Ѵ�.

    void SetHitEffect(RwBool bView) {m_bHitEffect = bView;}         ///< Hit Effect ǥ�������� �����Ѵ�.
    BOOL GetHitEffect() {return m_bHitEffect;}                      ///< Hit Effect ǥ�������� ��ȯ�Ѵ�.

    void    SetObjectCollisionMesh(RwBool bView) {CNtlPLGlobal::m_bCollObjVisible = bView;}    ///< Object�� Collision Mesh�� ǥ�� ������ �����Ѵ�.
    RwBool  GetObjectCollisionMesh() {return CNtlPLGlobal::m_bCollObjVisible;}                 ///< Objcec�� Collision Mesh�� ǥ�� ������ ��ȯ�Ѵ�.

    void    SetEnableGlowFilter(RwBool bEnable);                    ///< Glow Filter ���������� �����Ѵ�
    RwBool  GetEnableGlowFilter();                                  ///< Glow Filter ���������� ��ȯ�Ѵ�.

    void    SetEnableBlurFilter(RwBool bEnable);                    ///< Blur Filter ���� ������ �����Ѵ�.
    RwBool  GetEnableBlurFilter();                                  ///< Blur Filter ���� ������ ��ȯ�Ѵ�.

    void    SetEnableFrameFix(RwBool bEnable);                      ///< Frame�� 30���������� ������Ų��.
    RwBool  GetEnableFrameFix();                                    ///< Frame Fix ����

    void    SetEnableCameraDistAlpha(RwBool bEnable) {m_bEnableCameraDistAlpha = bEnable;}
    RwBool  GetEnableCameraDistAlpha() {return m_bEnableCameraDistAlpha;}

    void    SetCameraShakeDisable(RwBool bDisable) {m_bCameraShakeDisable = bDisable;}
    RwBool  GetCameraShakeDisable() {return m_bCameraShakeDisable;}

    void SetItemGrade(ENtlPLItemGrade eGrade);                      ///< ���� ȭ�鿡 ��Ÿ���ų�, ĳ���Ϳ� ������ Item�� Grade Effect�� �����Ѵ�.

    // ������ ���� ����
    void SetEditChar(CMTCharacter* pCharacter);                     ///< ���� ȭ�鿡 ���̴� ĳ���͸� �����Ѵ�.
    CMTCharacter* GetEditChar() {return m_pCharacter;}             ///< ���� ȭ�鿡 ���̴� ĳ���͸� ��ȯ�Ѵ�.

    void SetEditObject(CMTObject* pObject);                          ///< ���� ȭ�鿡 ��Ÿ�� ������Ʈ�� �����Ѵ�.
    CMTObject* GetEditObject() {return m_pObject;}                   ///< ���� ȭ�鿡 ��Ÿ���� ������Ʈ�� ��ȯ�Ѵ�.

    void SetEditItem(CMTItem* pItem);                               ///< ���� ������� ������ ��ü�� �����Ѵ�.
    CMTItem* GetEditItem() {return m_pItem;}                        ///< ���� ������� ������ ��ü�� ��ȯ�Ѵ�.

    // ���� ���� ���� ����
    void SetAppMode(EModelToolMode eMode) {m_ePrevAppMode = m_eAppMode; m_eAppMode = eMode;}
    EModelToolMode GetAppMode() {return m_eAppMode;}
    EModelToolMode GetAppPrevMode() {return m_ePrevAppMode;}
    RwBool IsNotChangeMode() {return m_eAppMode == m_ePrevAppMode;}
    void SetDataChanged();                                           ///< �����Ͱ� ����Ǿ����� ȣ���Ѵ�.

    // ī�޶� View ��� ����
    CNtlGameCamera* GetCamera() {return m_pCamera;}   
    void UpdateCameraDistance(CMTClump* pMTClump);                   ///< Model�� ũ�⿡ �°� Camera �Ÿ��� �����Ѵ�.
    void UpdateFaceCamera(const RwV3d& vPos, const RwV3d& vLookAt);  ///< Face ī�޶��� ��ġ�� �����Ѵ�.

	// ���̳ʸ� ������ ����
	CMTPropertyContainer* GetPropertyContainer() {return &m_PropContainer;}	///< ������Ƽ �����̳ʸ� ��ȯ�Ѵ�.	

	virtual LRESULT WndProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam);		///< ������ ���ν��� �Լ�

protected:
	RwBool CreateSubSystem(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer);  ///< ������ �õ����Ŀ� SubSystem���� �����Ѵ�.
    void   SetTexturePath();                                                    ///< TexturePath�� �����Ѵ�.
	RwBool AttachPlugin();														///< �ʿ��� PlugIn���� Attach �Ѵ�.
    RwBool CreateWorld();                                                       ///< ������� ���� ������ �����.                                                        
    void   DisplayInfo();                                                       ///< View ������ ǥ���Ѵ�.    

    int		MouseDownHandler(unsigned int uiMouseData);
    int		MouseUpHandler(unsigned int uiMouseData);
    int		MouseMoveHandler(unsigned int uiMouseData);
    
    void    SetErrorReport();                                                   ///< Error Report ������ �����Ѵ�.

protected:
    CNtlGameCamera*	        m_pCamera;								///< Viewer�� ���� Camera
	RtCharset*				m_pCharset;	
    
	RwRGBA					m_BackgroundColor;						///< Viewer�� Background Color
    RwRGBA					m_ForegorundColor;						///< Viewer�� Foreground Color

	CNtlPLVisualManager*	m_pVisualManager;						///< Visual Manager 
	CNtlPLEventHandler*     m_pPLEventHandler;
	
	RpLight*				m_pLtAmbient;							///< Ambient Light
	RpLight*				m_pLtDirectional;						///< Directional Light 

	CMTPropertyContainer	m_PropContainer;						///< ������Ƽ Container �̱��� ��ü
	CNtlPLResourceManager   m_ResoureManager;						///< Resource Manager �̱��� ��ü
	
	CMTCharacter*			m_pCharacter;							///< ĳ���� ��ü    
    CMTObject*              m_pObject;                              ///< ȭ�鿡 ��Ÿ�� ������Ʈ ��ü
    CMTItem*                m_pItem;                                ///< ���� ������� Item��ü

    // ItemPool
    CMTItemPool*            m_pItemPool;                            ///< Item Pool
	
	char					m_chCurrentPath[256];					///< ���� ���丮�� ������ ����
    RwChar                  m_strTexturePath[1024];                 ///< Texture Folders Path

	DWORD					m_dwPrevLMouseDownTime;
	DWORD					m_dwPrevRMouseDownTime;

	CNtlPLWorldEntity*		m_pWorldEntity;							///< World Entity ��ü    

    // View ���� Flag
    RwBool                  m_bViewWorld;                           ///< ���� ������ ����
    RwBool                  m_bViewWire;                            ///< WireFrame ǥ�� ����
    RwBool                  m_bViewHierarchy;                       ///< Hierarchy ǥ�� ����
    RwBool                  m_bViewBBox;                            ///< ĳ������ BBox�� ǥ�� ����
    RwBool                  m_bViewToon;                            ///< Toon ���� ����
    RwBool                  m_bHitEffect;                           ///< HitEffect ���� ����        
    RwBool                  m_bFrameFix;                            ///< Frame Fix ���� (30���������� ���� ��Ų��.)
    RwBool                  m_bEnableCameraDistAlpha;               ///< ī�޶� �Ÿ��� ���� ���� ó�� ���� ���� �÷���
    RwBool                  m_bCameraShakeDisable;                  ///< ī�޶� ����ũ�� ���� ��� Shake �ϴ��� �÷���

    // �޸� ���� ����
    LPDIRECTDRAW7           m_lpDD;                                 ///< �޸𸮸� ǥ���ϱ� ���� DirectX7 ��ü

    EModelToolMode          m_eAppMode;                             ///< ���� ������ ���� �÷���
    EModelToolMode          m_ePrevAppMode;                         ///< ������ ���� ���� �÷���

    // Input ����
    INPUT_HANDLE	m_handleMouseMove;    
    RwV2d           m_vOldMousePos;

    // Face Camera
    CNtlPLCameraRenderTexture m_faceCamera;                         ///< Face Camera ��ü
    RwV2d                   m_v2FaceCameraPos;                      ///< Face Camera Pos
    RwV2d                   m_v2FaceCameraSize;                     ///< Face Camera Size

};

#endif