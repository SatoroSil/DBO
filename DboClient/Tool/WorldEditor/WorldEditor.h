// WorldEditor.h : WorldEditor ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"       // �� ��ȣ

class CFixedString;

// CWorldEditorApp:
// �� Ŭ������ ������ ���ؼ��� WorldEditor.cpp�� �����Ͻʽÿ�.
//

class CWorldEditorApp : public CWinApp
{
public:
	CWorldEditorApp();
	virtual ~CWorldEditorApp();

protected:

// ������
public:

	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnIdle( LONG nCount );
	virtual int ExitInstance();
protected:
	CFixedString *m_pDocName;
public:
	afx_msg void OnModeObjectMove();
	afx_msg void OnModeObjectRotate();
	afx_msg void OnModeObjectScale();
	afx_msg void OnModeCameraViewFree();
	afx_msg void OnModeCameraViewTop();
	afx_msg void OnViewPropertydialogbar();
	afx_msg void OnViewWireframeForObject();
	afx_msg void OnViewWireframeForTerrain();
	afx_msg void OnViewSolidForObject();
	afx_msg void OnViewSolidForTerrain();
	afx_msg void OnViewBoundingForObject();
	afx_msg void OnViewBoundingForTerrain();
};

extern CWorldEditorApp theApp;
