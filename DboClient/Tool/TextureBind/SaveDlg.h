#pragma once
#include "afxwin.h"


// CSaveDlg ��ȭ �����Դϴ�.

class CSaveDlg : public CDialog
{
	DECLARE_DYNAMIC(CSaveDlg)

public:
	CSaveDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSaveDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox	m_cbbSaveType;
	CString		m_szSavePath;
	int			m_nSaveType;
public:
	afx_msg void OnBnClickedButtonSavePath();
public:
	afx_msg void OnCbnSelchangeComboSaveType();
public:
	virtual BOOL OnInitDialog();
};
