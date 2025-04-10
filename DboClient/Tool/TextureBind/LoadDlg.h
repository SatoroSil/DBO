#pragma once
#include "afxwin.h"


// CLoadDlg ��ȭ �����Դϴ�.

class CLoadDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoadDlg)

public:
	CLoadDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLoadDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_LOAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CComboBox	m_cbbType;
	CComboBox	m_cbbSize;
	CString		m_szPath;
	int			m_nTypeSel;
	int			m_nSizeSel;

public:
	afx_msg void OnBnClickedOpenButtonPath();
	afx_msg void OnCbnSelchangeOpenComboType();
	afx_msg void OnCbnSelchangeOpenComboSize();
public:
	virtual BOOL OnInitDialog();
};
