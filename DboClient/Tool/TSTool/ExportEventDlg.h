#pragma once


// CExportEventDlg ��ȭ �����Դϴ�.

class CExportEventDlg : public CDialog
{
	DECLARE_DYNAMIC(CExportEventDlg)

public:
	CExportEventDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExportEventDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EXPORT_EVENTOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedTablePath();
	afx_msg void OnBnClickedTsPath();

	virtual void OnOK();

public:
	CString m_strCurPath;

	CString m_strTblPath;
	CString m_strTSPath;
};
