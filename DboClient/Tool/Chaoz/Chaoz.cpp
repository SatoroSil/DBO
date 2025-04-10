// Chaoz.cpp : Defines the class behavior for the application.
//

#include "stdafx.h"
#include "Chaoz.h"
#include "ChaozDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChaozApp

BEGIN_MESSAGE_MAP(CChaozApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CChaozApp ����

CChaozApp::CChaozApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CChaozApp ��ü�Դϴ�.

CChaozApp theApp;


// CChaozApp �ʱ�ȭ

BOOL CChaozApp::InitInstance()
{
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

	AfxEnableControlContainer();

	// standard initialization
		// To reduce the size of the final executable file without using these features
		// specific initialization not needed below
		// routines must be removed.
		// Change the registry key where those settings are stored.
		// TODO: This string is the same as the name of your company or organization.
		// You need to modify it with the appropriate content.
	//SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));

	CChaozDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Click OK here to process when the dialog box is gone
		// Place the code.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Click [Cancel] here to process when dialog disappears
		// Place the code.
	}

	// FALSE to allow the application to exit without starting the application's message pump because the dialog is closed
	// returns.
	return FALSE;
}
