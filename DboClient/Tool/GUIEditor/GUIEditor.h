// GUIEditor.h : GUIEditor ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"       // �� ��ȣ


// CGUIEditorApp:
// �� Ŭ������ ������ ���ؼ��� GUIEditor.cpp�� �����Ͻʽÿ�.
//

class CGUIEditorApp : public CWinApp
{
public:
	CGUIEditorApp();


// ������
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGUIEditorApp theApp;

