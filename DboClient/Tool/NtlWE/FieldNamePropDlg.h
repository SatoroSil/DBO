#pragma once


// CFieldNamePropDlg ��ȭ �����Դϴ�.

class CFieldNamePropDlg : public CDialog
{
	DECLARE_DYNAMIC(CFieldNamePropDlg)

public:
	CFieldNamePropDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFieldNamePropDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ATTR_FIELDNAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	CString m_CurMapNameCode;
public:
	CString m_MapNameCodeInput;
};
