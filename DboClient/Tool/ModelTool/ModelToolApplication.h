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
#include "NtlPLPropertyContainer.h"

#include "NtlPostEffectCamera.h"
#include "ToolCamera.h"

#include "NtlPLCharacter.h"
#include "NtlPLCharacterParser.h"


#include "NtlAtomic.h"
#include "ntlworldplugin.h"

#include "RpClump.h"
#include "MTCharacter.h"
#include "NtlToonMaterial.h"

#include "NtlPLResourceManager.h"


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
    enum EModelToolMode
    {
        MODE_CLUMP,
        MODE_PC,
        MODE_MOB,
        MODE_ITEM,
        MODE_OBJECT,
    };

public:
	CModelToolApplication(void);
	virtual ~CModelToolApplication(void);

	virtual void Destroy();											///< ������ ��ü���� �ı��Ѵ�.
	RwBool	Update(RwReal fTime, RwReal fElapsedTime);				///< Update Method
	RwBool	OnIdle() {return CNtlApplication::Update();}			///< Idle Update 
    RwBool  Resize(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer); ///< ȭ�� ũ�⸦ �����Ҷ� ȣ��ȴ�.

	RwBool	LoadClump(RwChar * filename );							///< Clump ������ Loading�Ѵ�.
	char*	GetWorkDir() {return m_chCurrentPath;};					///< ���� ������ ��θ� ��ȯ�Ѵ�.
	
	/// �̱��� ȣ�� �Լ�
	static	CModelToolApplication* GetInstance() {return (CModelToolApplication*)m_pInstance; }
	CMTCharacter* GetCharcter() {return m_pCharacter;};				///< ĳ���� ��ü�� ��ȯ�Ѵ�.

    // �÷��� ����
    void SetWorldView(RwBool bView) {m_bViewWorld = bView;};        ///< ���� ǥ�� ������ �����Ѵ�.
    BOOL GetWorldView() {return m_bViewWorld;};                     ///< ���� ǥ�� ������ ��ȯ�Ѵ�.

    void SetWireView(RwBool bView) {m_bViewWire = bView;};          ///< Wireframe ǥ�� ������ �����Ѵ�.
    BOOL GetWireView() {return m_bViewWire;};                       ///< Wireframe ǥ�� ������ ��ȯ�Ѵ�.

    void SetHierarchyView(RwBool bView) {m_bViewHierarchy = bView;}; ///< Hierarchy ǥ�� ������ �����Ѵ�.
    BOOL GetHierarchyView() {return m_bViewHierarchy;};              ///< Hierarchy ǥ�� ������ ��ȯ�Ѵ�.

    void SetEditChar(CMTCharacter* pCharacter) {m_pAnimEditChar = pCharacter;}; 

    // ���� ���� ���� ����
    void SetAppMode(EModelToolMode eMode) {m_eAppMode = eMode;}
    EModelToolMode GetAppMode() {return m_eAppMode;}

	virtual LRESULT WndProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam);		///< ������ ���ν��� �Լ�

protected:
	RwBool CreateSubSystem(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer);  ///< ������ �õ����Ŀ� SubSystem���� �����Ѵ�.
	RwBool AttachPlugin();														///< �ʿ��� PlugIn���� Attach �Ѵ�.
    RwBool CreateWorld();                                                       ///< ������� ���� ������ �����.                                                    
    void   DisplayInfo();                                                       ///< View ������ ǥ���Ѵ�.
    void   DisplayHitTime();                                                    ///< Hit Time�� ȭ�鿡 ǥ���Ѵ�

protected:
    CNtlGameCamera*	        m_pCamera;								///< Viewer�� ���� Camera
	RtCharset*				m_pCharset;	
    RtCharset*              m_pCharsetHitTime;                      ///< HitTime ǥ�ÿ� CharSet
	RwRGBA					m_BackgroundColor;						///< Viewer�� Background Color
    RwRGBA					m_ForegorundColor;						///< Viewer�� Foreground Color

	CNtlPLVisualManager*	m_pVisualManager;						///< Visual Manager (?)	

	RpWorld*				m_pWorld;								///< World ��ü
	RpLight*				m_pLtAmbient;							///< Ambient Light
	RpLight*				m_pLtDirectional;						///< Directional Light 

	CNtlPLPropertyContainer	m_PropContainer;						///< ������Ƽ Container �̱��� ��ü
	CNtlPLResourceManager   m_ResoureManager;						///< Resource Manager �̱��� ��ü

	
	CMTCharacter*			m_pCharacter;							///< ĳ���� ��ü
    CMTCharacter*           m_pAnimEditChar;                        ///< Anim Edit�� ���� Char �ν��Ͻ�
	
	char					m_chCurrentPath[256];					///< ���� ���丮�� ������ ����

	DWORD					m_dwPrevLMouseDownTime;
	DWORD					m_dwPrevRMouseDownTime;

    CNtlPLResource*         m_pResWorld;                            ///< ���� ���ҽ�
    CNtlPLResource*         m_pResSky;                              ///< �ϴ� ���ҽ�    

    // View ���� Flag
    RwBool                  m_bViewWorld;                           ///< ���� ������ ����
    RwBool                  m_bViewWire;                            ///< WireFrame ǥ�� ����
    RwBool                  m_bViewHierarchy;                       ///< Hierarchy ǥ�� ����

    // �޸� ���� ����
    LPDIRECTDRAW7           m_lpDD;                                 ///< �޸𸮸� ǥ���ϱ� ���� DirectX7 ��ü

    EModelToolMode          m_eAppMode;                             ///< ���� ������ ���� �÷���

   
};

#endif