#pragma once
#include "afxwin.h"


// CRenamePropDlg ��ȭ �����Դϴ�.

class CRenamePropDlg : public CDialog
{
	DECLARE_DYNAMIC(CRenamePropDlg)

public:
	CRenamePropDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRenamePropDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_RENAME_PROP };

public:

	CString m_strName;

	void	SetName(CString strName);
	CString GetName(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editRename;
public:
	afx_msg void OnBnClickedOk();
public:
	virtual BOOL OnInitDialog();
};
