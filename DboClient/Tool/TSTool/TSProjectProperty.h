#pragma once
#include "afxwin.h"


// CTSProjectProperty ��ȭ �����Դϴ�.

class CTSProjectProperty : public CDialog
{
	DECLARE_DYNAMIC(CTSProjectProperty)

public:
	CTSProjectProperty(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTSProjectProperty();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CREATE_PROJECT_DIAG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnOK();

	DECLARE_MESSAGE_MAP()

public:
	CString m_strProjPath;
	CString m_strProjName;
	CComboBox m_ctrTSMode;
	DWORD m_dwMode;

public:
	virtual BOOL OnInitDialog();

public:
	afx_msg void OnBnClickedButton1();
};
