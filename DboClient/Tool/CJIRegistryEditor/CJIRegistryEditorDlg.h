// CJIRegistryEditorDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CCJIRegistryEditorDlg ��ȭ ����
class CCJIRegistryEditorDlg : public CDialog
{
// �����Դϴ�.
public:
	CCJIRegistryEditorDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CJIREGISTRYEDITOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	CString	m_strDBODir;

	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CEdit m_CtrEditor;

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
