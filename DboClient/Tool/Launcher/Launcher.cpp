// Launcher.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "io.h"


#include "Launcher.h"
#include "LauncherDlg.h"
#include "DataType.h"
#include "NtlLauncherConfig.h"
#include "NtlPatchManager.h"
#include "NtlHttpDownLoader.h"
#include "NtlRtPatcher.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MUTEX_DBO           "DragonBall"
#define MUTEX_DBO_LAUNCHER  "DBO Launcher"

// CLauncherApp

BEGIN_MESSAGE_MAP(CLauncherApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLauncherApp ����

CLauncherApp::CLauncherApp()
: m_bPatchStart(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CLauncherApp ��ü�Դϴ�.

CLauncherApp theApp;


BOOL IsMultiOpen(const char *pExeName, BOOL bCreateMutex)
{
    if(bCreateMutex)
    {
        HANDLE hMutex = ::CreateMutex(NULL, FALSE, pExeName);
        if(hMutex) 
        {
            if(GetLastError() == ERROR_ALREADY_EXISTS)
                return TRUE;
        }
        else // NULL�̸� �̹� �����ִ°��̴�.
        {
            return TRUE;
        }
    }
    else
    {
	    HANDLE hMutex = ::OpenMutex(NULL, FALSE, pExeName);
	    if(hMutex) // NULL�� �ƴϸ� �̹� ���� �ִ� ���̴�.
		    return TRUE;
    }

	return FALSE;
}

// CLauncherApp �ʱ�ȭ
BOOL CLauncherApp::InitInstance() 
{
    if(IsMultiOpen(MUTEX_DBO, FALSE))
    {
        ::MessageBox(NULL, "DragonBall Online is already opened !!!", "DragonBall Online", MB_OK);
        return FALSE;
    }

    if(IsMultiOpen(MUTEX_DBO_LAUNCHER, TRUE))
    {
        ::MessageBox(NULL, "DragonBall Online Launcher is already opened !!!", "DragonBall Online", MB_OK);
        return FALSE;
    }

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

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));
	
	//m_bCompletePatch
	m_bPatchStart = false;
	CNtlLauncherConfig::GetInstance()->Create(LAUNCHER_CONFIG);
	CNtlPatchManager::GetInstance()->Create();

	//CmdLine Tokenize
	CString strCmdLine = m_lpCmdLine;
	if(strCmdLine == LAUNCHER_CMD_LAUNCHER_PATCH)
	{
		CNtlPatchManager::GetInstance()->SetPatchState(PATCH_STATE_LAUNCHER);
	}
	
	if(CNtlPatchManager::GetInstance()->GetPatchState() == PATCH_STATE_NONE)
	{
		if( _access(LAUNCHER_PATCH_EXE_FILE_NAME, 0) == 0)
		{
			while(1)
			{
				if( DeleteFile(LAUNCHER_PATCH_EXE_FILE_NAME) )
					break;
			}
		}

		CLauncherDlg dlg;
		m_pMainWnd = &dlg;

        INT_PTR nResponse = dlg.DoModal();		
	}
	else
	{
		CLauncherDlg dlg;
		m_pMainWnd = &dlg;

		INT_PTR nResponse = dlg.DoModal();        
	}
	
	// ��ȭ ���ڰ� �������Ƿ� ���� ���α׷��� �޽��� ������ �������� �ʰ�  ���� ���α׷��� ���� �� �ֵ��� FALSE��
	// ��ȯ�մϴ�.
	return FALSE;
}

int CLauncherApp::ExitInstance()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(CNtlPatchManager::GetInstance()->GetPatchState() == PATCH_STATE_NEW_LAUNCHER)
	{
		CopyFile(LAUNCHER_CUR_EXE_FILE_NAME, LAUNCHER_PATCH_EXE_FILE_NAME, FALSE);
		CString strLauncherPatchCmd = LAUNCHER_CMD_LAUNCHER_PATCH;
		ShellExecute(NULL, NULL, LAUNCHER_PATCH_EXE_FILE_NAME, strLauncherPatchCmd, NULL, 0);
	}
	else if(CNtlPatchManager::GetInstance()->GetPatchState() == PATCH_STATE_LAUNCHER)
	{
		ShellExecute(NULL, NULL, LAUNCHER_CUR_EXE_FILE_NAME, NULL, NULL, 1);
	}
	
	CNtlPatchManager::GetInstance()->DestroyInstance();
	CNtlLauncherConfig::GetInstance()->DestroyInstance();
	
	return CWinApp::ExitInstance();
}

BOOL CLauncherApp::PumpMessage()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	//ȭ���� ó�� ǥ�� �� �İ� ���� �ۿ� ã������ ������.
	if(m_bPatchStart == false)
	{
		m_bPatchStart = true;
		CNtlPatchManager::GetInstance()->DoAction();
	}

	return CWinApp::PumpMessage();
}
