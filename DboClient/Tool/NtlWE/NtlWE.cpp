// NtlWE.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "NtlWE.h"
#include "NtlWEFrm.h"

#include "NtlWEDoc.h"
#include "NtlWEView.h"
#include ".\ntlwe.h"
#include "NtlWorldMouse.h"
#include "paletteterrain.h"
#include "UpdateEvent.h"
#include "SplashScreenfx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNtlWEApp

BEGIN_MESSAGE_MAP(CNtlWEApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// ǥ�� ������ ���ʷ� �ϴ� ���� ����Դϴ�.
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// ǥ�� �μ� ���� ����Դϴ�.
	//ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CNtlWEApp ����

CNtlWEApp::CNtlWEApp()
{
	_CrtSetDbgFlag   ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG );

	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}

CNtlWEApp::~CNtlWEApp()
{
	
}

// ������ CNtlWEApp ��ü�Դϴ�.

CNtlWEApp theApp;

BOOL CNtlWEApp::InitInstance()
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

	CRuntimeClass* pRuntimeCalss = RUNTIME_CLASS(CNtlWEDoc);

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CNtlWEDoc),
		RUNTIME_CLASS(CNtlWEFrm),       // �� SDI ������ â�Դϴ�.
		RUNTIME_CLASS(CNtlWEView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// ǥ�� �� ���, DDE, ���� ���⿡ ���� ������� ���� �м��մϴ�.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// ����ٿ� ������ ����� ����ġ�մϴ�. ���� ���α׷��� /RegServer, /Register, /Unregserver �Ǵ� /Unregister�� ���۵� ��� FALSE�� ��ȯ�մϴ�.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// â �ϳ��� �ʱ�ȭ�Ǿ����Ƿ� �̸� ǥ���ϰ� ������Ʈ�մϴ�.
	//m_pMainWnd->ShowWindow(SW_SHOW);
	//m_pMainWnd->UpdateWindow();
	// ���̻簡 ���� ��쿡�� DragAcceptFiles�� ȣ���մϴ�.
	// SDI ���� ���α׷������� ProcessShellCommand �Ŀ� �̷��� ȣ���� �߻��ؾ� �մϴ�.

	// accessors
	m_pFrm = (CNtlWEFrm*)AfxGetMainWnd();
	m_pView = (CNtlWEView*)(m_pFrm->GetActiveView());
	m_pDoc = (CNtlWEDoc*)(m_pView->GetDocument());

	// �ε���
	m_menuIdle.LoadMenu(IDR_MENU_IDLE);
	m_menuOutdoor.LoadMenu(IDR_MENU_OUTDOOR);
	m_menuIndoor.LoadMenu(IDR_MENU_INDOOR);

	SetIdleMode();

	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();

	CRect rect;
	CDC* pDC = m_pView->GetDC();
	pDC->GetClipBox(&rect);
	pDC->FillSolidRect(rect.left,rect.top,rect.right,rect.bottom,RGB(150,150,150));
	m_pView->ReleaseDC(pDC);

	// SplashScreen
	CSplashScreenFx *pSplash = new CSplashScreenFx();
	pSplash->Create(AfxGetMainWnd(), "S  A  B  E  R", 0 ,CSS_FADE | CSS_CENTERSCREEN | CSS_SHADOW);

	char szOldDir[NTL_MAX_DIR_PATH] = {0,};
	char szNewDir[NTL_MAX_DIR_PATH] = {0,};
	char szNewBMP[NTL_MAX_DIR_PATH] = {0,};
	::GetCurrentDirectory(NTL_MAX_DIR_PATH, szOldDir);
	::strcpy(szNewDir, szOldDir);
	::strcpy(szNewBMP, szOldDir);
	::strcat(szNewDir, "\\tool\\saber\\texture\\splash\\");
	::strcat(szNewBMP, "\\tool\\saber\\texture\\splash\\*.bmp");
	
	
	CFileFind finder;
	int BMPCnt = 0;
	BOOL bWorking = finder.FindFile(szNewBMP);
	while(bWorking)
	{
		bWorking = finder.FindNextFile();
		BMPCnt++;
	}

	::SetCurrentDirectory(szNewDir);
	CString BMPName;

	::srand( (unsigned )time(NULL));
	int BMPIdx = rand() % BMPCnt;
	if(BMPIdx < 10)
	{
		BMPName.Format("SABER_SPLASH0%d.BMP", BMPIdx);
	}
	else
	{
		BMPName.Format("SABER_SPLASH%d.BMP", BMPIdx);
	}

	pSplash->SetBitmap(BMPName.GetBuffer(0), 12, 41, 80);

	::SetCurrentDirectory(szOldDir);
	
	pSplash->SetTextFont("Arial",120,CSS_TEXT_NORMAL);
	pSplash->SetTextRect(CRect(160,220,390,260));
	pSplash->CreateProgressBar(CRect(200,288,450,295), CSize(0, 2), PBS_SMOOTH);
	//pSplash->SetTextColor(RGB(180, 180, 180));
	pSplash->SetTextColor(RGB(255, 255, 255));
	pSplash->SetTextFormat(DT_SINGLELINE | DT_RIGHT | DT_VCENTER);
	pSplash->Show();	
	pSplash->SetActiveWindow();

	//Sleep(500);

	// SplashScreen	
	pSplash->SetText("ARTRIA ���...");
	{
		m_DI.Init(m_pFrm->GetSafeHwnd());
	//	Sleep(1000);
	}
	pSplash->ProgressStep();

	pSplash->SetText("ARTRIA ���...");
	{
		m_NtlWEApplication.Create(((CNtlWEFrm*)AfxGetMainWnd())->GetActiveView()->GetSafeHwnd());
	}
	pSplash->ProgressStep();

	pSplash->SetText("ARTRIA ����...");
	{
	//	Sleep(1000);
	}
	pSplash->ProgressStep();

	pSplash->Hide();

	return TRUE;
}

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	RwChar Info[NTL_MAX_DIR_PATH] = {0,};

	sprintf_s(Info, NTL_MAX_DIR_PATH, "SABER Version %s", dGET_WORLD_PARAM()->WorldVer);
	GetDlgItem(IDC_SABER_VER)->SetWindowText(Info);

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

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
void CNtlWEApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CNtlWEApp �޽��� ó����
void CNtlWEApp::SetDiffusePickerClr(CString R, CString G, CString B)
{
	m_pFrm->m_pTerrainPalette->UpdateData(TRUE);
	m_pFrm->m_pTerrainPalette->m_ClrDiffusePickerR = R;
	m_pFrm->m_pTerrainPalette->m_ClrDiffusePickerG = G;
	m_pFrm->m_pTerrainPalette->m_ClrDiffusePickerB = B;
	m_pFrm->m_pTerrainPalette->UpdateData(FALSE);
}

BOOL CNtlWEApp::OnIdle(LONG lCount)
{
	// do not render if the app is minimized
	if(m_pMainWnd->IsIconic())
		return FALSE;

	// give app. some rest for other stuff
	//Sleep(1);

	lCount = 0;
	//return CWinApp::OnIdle(lCount);

	
	m_DI.Update();

	dGET_MOUSE()->Update();

	m_NtlWEApplication.OnIdle();

	dGET_MOUSE()->Reset();

	__super::OnIdle(lCount);

	return TRUE;
}

BOOL CNtlWEApp::PreTranslateMessage(MSG* pMsg)
{
	if((CNtlWEFrm*)AfxGetMainWnd())
	{
		HWND hWnd = ((CNtlWEFrm*)AfxGetMainWnd())->GetActiveView()->GetSafeHwnd();
		if(hWnd == pMsg->hwnd)
			m_NtlWEApplication.WndProc(pMsg->hwnd, pMsg->message, pMsg->wParam, pMsg->lParam);
	}

	return CWinApp::PreTranslateMessage(pMsg);
}

int CNtlWEApp::ExitInstance()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	m_DI.Free();
	m_NtlWEApplication.Destroy();

	return CWinApp::ExitInstance();
}

//void CNtlWEApp::OnFinalRelease()
//{
//	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
//
//	//m_NtlWEApplication.Destroy();
//
//	CWinApp::OnFinalRelease();
//}

void CNtlWEApp::SetIndoorMode()
{
	m_pFrm->SetMenu(&m_menuIndoor);
}

void CNtlWEApp::SetOutdoorMode()
{
	m_pFrm->SetMenu(&m_menuOutdoor);
}

void CNtlWEApp::SetIdleMode()
{
	m_pFrm->SetMenu(&m_menuIdle);
}