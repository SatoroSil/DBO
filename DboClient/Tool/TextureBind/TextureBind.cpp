// TextureBind.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "TextureBind.h"
#include "MainFrm.h"

#include "TextureBindDoc.h"
#include "TextureBindView.h"
#include "LoadDlg.h"
#include "SaveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// TB
#include "TBApp.h"


// CTextureBindApp

BEGIN_MESSAGE_MAP(CTextureBindApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CTextureBindApp::OnAppAbout)
	// ǥ�� ������ ���ʷ� �ϴ� ���� ����Դϴ�.
	//ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	
	// ǥ�� �μ� ���� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_TB_OPEN, &CTextureBindApp::OnFileOpen)
	ON_COMMAND(ID_TB_SAVE, &CTextureBindApp::OnFileSave)
END_MESSAGE_MAP()


// CTextureBindApp ����

CTextureBindApp::CTextureBindApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CTextureBindApp ��ü�Դϴ�.

CTextureBindApp theApp;


// CTextureBindApp �ʱ�ȭ

BOOL CTextureBindApp::InitInstance()
{
	// Debuging
	//_CrtSetBreakAlloc( 273 );

	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�. 
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// OLE ���̺귯���� �ʱ�ȭ�մϴ�.
	//if (!AfxOleInit())
	//{
	//	AfxMessageBox(IDP_OLE_INIT_FAILED);
	//	return FALSE;
	//}
	//AfxEnableControlContainer();
	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("Texture Bind"));
	LoadStdProfileSettings(4);  // MRU�� �����Ͽ� ǥ�� INI ���� �ɼ��� �ε��մϴ�.
	// ���� ���α׷��� ���� ���ø��� ����մϴ�. ���� ���ø���
	//  ����, ������ â �� �� ������ ���� ������ �մϴ�.
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CTextureBindDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ������ â�Դϴ�.
		RUNTIME_CLASS(CTextureBindView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// ǥ�� �� ���, DDE, ���� ���⿡ ���� ������� ���� �м��մϴ�.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// ����ٿ� ������ ����� ����ġ�մϴ�.
	// ���� ���α׷��� /RegServer, /Register, /Unregserver �Ǵ� /Unregister�� ���۵� ��� FALSE�� ��ȯ�մϴ�.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// â �ϳ��� �ʱ�ȭ�Ǿ����Ƿ� �̸� ǥ���ϰ� ������Ʈ�մϴ�.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// ���̻簡 ���� ��쿡�� DragAcceptFiles�� ȣ���մϴ�.
	//  SDI ���� ���α׷������� ProcessShellCommand �Ŀ� �̷��� ȣ���� �߻��ؾ� �մϴ�.

	HWND hWnd = ((CMainFrame*)AfxGetMainWnd())->GetActiveView()->GetSafeHwnd();

	RECT rtRect;
	GetClientRect( hWnd, &rtRect );
	RwInt32 nWidth = rtRect.right - rtRect.left;
	RwInt32 nHeight = rtRect.bottom - rtRect.top;

	GetTBApp()->Create( hWnd, nWidth, nHeight );

	return TRUE;
}



// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// ��ȭ ���ڸ� �����ϱ� ���� ���� ���α׷� ����Դϴ�.
void CTextureBindApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CTextureBindApp �޽��� ó����

/**
* \brief �׻� ȣ���ϱ� ���Ͽ� MFC�� OnIdle�� ��� �޾� �׻� TRUE�� �����ϵ��� ����
*/
BOOL CTextureBindApp::OnIdle(LONG lCount)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if( m_pMainWnd->IsIconic() )
		return FALSE;

	GetTBApp()->OnIdle();

	__super::OnIdle(lCount);
	return TRUE;
}

int CTextureBindApp::ExitInstance()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	GetTBApp()->Destroy();

	return CWinApp::ExitInstance();
}

void CTextureBindApp::OnFileOpen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CLoadDlg dlg;

	if( dlg.DoModal() == IDOK )
	{
		CTBApp::GetInstance()->LoadTexFromPath( 
			(CBindingTexManager::eType)dlg.m_nTypeSel,
			(CBindingTexManager::eSize)dlg.m_nSizeSel,
			dlg.m_szPath );
	}
}

//void CTextureBindApp::OnFileSave()
//{
//	CSaveDlg dlg;
//
//	if( dlg.DoModal() == IDOK )
//	{
//		CTBApp::GetInstance()->SaveTexCurrentData(
//			(CBindingTexManager::eSize)dlg.m_nSaveType,
//			dlg.m_szSavePath );
//	}
//}

BOOL CTextureBindApp::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CTBApp::GetInstance()->PreTranslateMessage( pMsg->hwnd, pMsg->message, pMsg->wParam, pMsg->lParam );

	return CWinApp::PreTranslateMessage(pMsg);
}
void CTextureBindApp::OnFileSave()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CSaveDlg dlg;
	
		if( dlg.DoModal() == IDOK )
		{
			CTBApp::GetInstance()->SaveTexCurrentData(
				(CBindingTexManager::eSize)dlg.m_nSaveType,
				dlg.m_szSavePath );
		}
}
