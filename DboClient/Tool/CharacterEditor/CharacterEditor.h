// CharacterEditor.h : CharacterEditor ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"       // �� ��ȣ


// CCharacterEditorApp:
// �� Ŭ������ ������ ���ؼ��� CharacterEditor.cpp�� �����Ͻʽÿ�.
//
#include "DboCharacterApplication.h"
#include "AnimationTreeDialog.h"
#include "AnimationSetDialog.h"
class CCharacterEditorApp : public CWinApp
{
public:
	CCharacterEditorApp();

public:
	CDboCharacterApplication m_DboApplication;

	CAnimationTreeDialog	 *m_pAnimationTreeDialog;
	CAnimationSetDialog	     *m_pAnimationSetDialog;
// ������
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnIdle(LONG lCount);
	virtual int ExitInstance();

	
	afx_msg void OnAssetNew();
	afx_msg void OnAssetOpen();
	afx_msg void OnAssetSave();
};

extern CCharacterEditorApp theApp;