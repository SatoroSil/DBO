// WorldPatchProcess.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#define dGET_APP() (&theApp)
#define dGET_DLG() ((CWorldPatchProcessDlg*)((&theApp)->m_pMainWnd))

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.

// CWorldPatchProcessApp:
// �� Ŭ������ ������ ���ؼ��� WorldPatchProcess.cpp�� �����Ͻʽÿ�.
//

class CWorldPatchProcessApp : public CWinApp
{
public:
	CWorldPatchProcessApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CWorldPatchProcessApp theApp;