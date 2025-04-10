#pragma once


// CStringDialog ��ȭ �����Դϴ�.
#include <string>

class CStringDialog : public CDialog
{
	DECLARE_DYNAMIC(CStringDialog)

public:
	std::string			m_strTitle;
	std::string			m_strEdit;

public:
	CStringDialog(LPCTSTR strTitle, LPCTSTR strEdit = "noname", CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CStringDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_STRING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CString m_strName;
};
