// Chaoz.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CChaozApp:
// �� Ŭ������ ������ ���ؼ��� Chaoz.cpp�� �����Ͻʽÿ�.
//

class CChaozApp : public CWinApp
{
public:
	CChaozApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CChaozApp theApp;