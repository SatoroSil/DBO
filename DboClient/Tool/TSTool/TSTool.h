// TSTool.h : TSTool ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CTSApp:
// �� Ŭ������ ������ ���ؼ��� TSTool.cpp�� �����Ͻʽÿ�.
//

class CTSTableMng;

class CTSApp : public CWinApp
{
protected:

public:
	CTSApp();

public:

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTSApp theApp;