#pragma once


// CBloomPropDlg ��ȭ �����Դϴ�.

class CBloomPropDlg : public CDialog
{
	DECLARE_DYNAMIC(CBloomPropDlg)

public:
	CBloomPropDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBloomPropDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ATTR_BLOOM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CString m_Power;

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnDestroy();
};
