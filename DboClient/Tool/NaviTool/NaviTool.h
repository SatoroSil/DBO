// NaviTool.h : NaviTool ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CNaviToolApp:
// �� Ŭ������ ������ ���ؼ��� NaviTool.cpp�� �����Ͻʽÿ�.
//

class CNaviToolApp : public CWinApp
{
public:
	CNaviToolApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();


// �����Դϴ�.
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnIdle(LONG lCount);
};

extern CNaviToolApp theApp;