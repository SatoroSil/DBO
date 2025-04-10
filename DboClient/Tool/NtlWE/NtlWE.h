// NtlWE.h : NtlWE ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"       // �� ��ȣ
#include "ntlweapplication.h"
#include "NtlWorldDI.h"
#include "NtlWEFrm.h"


// CNtlWEApp:
// �� Ŭ������ ������ ���ؼ��� NtlWE.cpp�� �����Ͻʽÿ�.
//

class CNtlWEFrm;
class CNtlWEView;
class CNtlWEDoc;


class CNtlWEApp : public CWinApp
{
public:
	CNtlWEApp();
	~CNtlWEApp();

public:
	CNtlWEFrm	*m_pFrm;
	CNtlWEView	*m_pView;
	CNtlWEDoc	*m_pDoc;
	CDI			m_DI;
	CNtlWEApplication m_NtlWEApplication;

private:
	CMenu		m_menuIdle;
	CMenu		m_menuOutdoor;
	CMenu		m_menuIndoor;

public:
	void SetDiffusePickerClr(CString R, CString G, CString B);

// ������
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnIdle(LONG lCount);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual int ExitInstance();
//	virtual void OnFinalRelease();

	// �ε���
public:
	void	SetIdleMode();
	void	SetIndoorMode();
	void	SetOutdoorMode();
};

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// ��ȭ ���� ������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ����

	// ����
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

extern CNtlWEApp theApp;
