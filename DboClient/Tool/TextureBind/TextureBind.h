// TextureBind.h : TextureBind ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CTextureBindApp:
// �� Ŭ������ ������ ���ؼ��� TextureBind.cpp�� �����Ͻʽÿ�.
//

class CTextureBindApp : public CWinApp
{
public:
	CTextureBindApp();


// �������Դϴ�.
public:
	virtual BOOL	InitInstance();
	virtual int		ExitInstance();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnIdle(LONG lCount);

	afx_msg void OnFileOpen();
//	afx_msg void OnFileSave();
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	afx_msg void OnFileSave();
};

extern CTextureBindApp theApp;