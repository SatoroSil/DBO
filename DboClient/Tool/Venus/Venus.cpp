// Venus.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "VenusFrame.h"

#include "VenusDoc.h"
#include "VenusView.h"

#include "VenusAPI.h"

#include "StatusBarDialog.h"
#include "LightDialog.h"
#include "OptionDialog.h"

#include "EventLayer.h"

#include "NtlEventQueue.h"
#include "NtlPLEntityFreeList.h"
#include "NtlEffectSystemFreeList.h"

#include ".\venuspropertycontainer.h"
#include ".\venusvisualmanager.h"

#include "VenusPlayerEventManager.h"

#include "VenusFramework.H"

#include ".\venusconfig.h"

#include "MeshLayer.h"
#include "TextureLayer.h"

#include "Splash.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVenusApp

BEGIN_MESSAGE_MAP(CVenusApp, CWinApp)	
	// ǥ�� ������ ���ʷ� �ϴ� ���� ����Դϴ�.
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// ǥ�� �μ� ���� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CVenusApp ����

CVenusApp::CVenusApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
	m_bInitialize = FALSE;
}


// ������ CVenusApp ��ü�Դϴ�.

CVenusApp theApp;

// CVenusApp �ʱ�ȭ

BOOL CVenusApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControls()�� �ʿ��մϴ�. 
	// InitCommonControls()�� ������� ������ â�� ���� �� �����ϴ�.
	InitCommonControls();

	CWinApp::InitInstance();

	// OLE ���̺귯���� �ʱ�ȭ�մϴ�.
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));
	LoadStdProfileSettings(4);  // MRU�� �����Ͽ� ǥ�� INI ���� �ɼ��� �ε��մϴ�.
	// ���� ���α׷��� ���� ���ø��� ����մϴ�. ���� ���ø���
	// ����, ������ â �� �� ������ ���� ������ �մϴ�.
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CVenusDoc),
		RUNTIME_CLASS(CVenusFrame),       // �� SDI ������ â�Դϴ�.
		RUNTIME_CLASS(CVenusView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);
	// ǥ�� �� ���, DDE, ���� ���⿡ ���� ������� ���� �м��մϴ�.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// splash window
	CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);

	// ����ٿ� ������ ����� ����ġ�մϴ�. ���� ���α׷��� /RegServer, /Register, /Unregserver �Ǵ� /Unregister�� ���۵� ��� FALSE�� ��ȯ�մϴ�.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// â �ϳ��� �ʱ�ȭ�Ǿ����Ƿ� �̸� ǥ���ϰ� ������Ʈ�մϴ�.
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();
	// ���̻簡 ���� ��쿡�� DragAcceptFiles�� ȣ���մϴ�.
	// SDI ���� ���α׷������� ProcessShellCommand �Ŀ� �̷��� ȣ���� �߻��ؾ� �մϴ�.

	RwChar strMainPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, strMainPath);
	CVenusConfig::GetInstance().m_strMainPath = strMainPath;
	CVenusConfig::GetInstance().Load();

	CStatusBarDialog::GetInstance().BuildData();
	CLightDialog::GetInstance().BuildData();
	COptionDialog::GetInstance().BuildGridWidth();
	COptionDialog::GetInstance().BuildGridCount();

	CEventLayer* pEventLayer = (CEventLayer*) gGetEditLayer(EDIT_LAYER_EVENT);
	pEventLayer->BuildData();

	CVenusFramework::GetInstance().Create(gMainView()->GetSafeHwnd(), FALSE);

	//CreateVenus();

	m_bInitialize = TRUE;

	CSplashWnd::DestroySplashWnd();

	if (CVenusConfig::GetInstance().m_bShowUpdateNews)
	{
		CVenusConfig::GetInstance().ShowUpdateNews();
	}    

	return TRUE;
}

void CVenusApp::DeleteVenus()
{
	CVenusPlayerEventManager::GetInstance().Delete();

	CVenusVisualManager::GetInstance().Destroy();

	CNtlEffectSystemFreeList::Destroy();

	CVenusPropertyContainer::GetInstance().Destroy();

	// Close the event system
	RWS::CEventHandler::UnRegisterStreamChunkHandlers();
	RWS::CEventHandler::Close ();

	CNtlEventQueue::GetInstance()->Destroy();
}

BOOL CVenusApp::OnIdle(LONG lCount)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(m_pMainWnd->IsIconic())
		return FALSE;

	if(m_bInitialize)
	{
		CVenusFramework::GetInstance().OnIdle();
	}

	__super::OnIdle(lCount);
	return TRUE;
//	return CWinApp::OnIdle(lCount);
}

