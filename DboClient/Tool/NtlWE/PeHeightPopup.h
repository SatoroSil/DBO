#pragma once


// CPeHeightPopup ��ȭ �����Դϴ�.

class CPeHeightPopup : public CDialog
{
	DECLARE_DYNAMIC(CPeHeightPopup)

public:
	CPeHeightPopup(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPeHeightPopup();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PE_HEIGHT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual LRESULT	WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CString m_strValue;
	RwReal	m_fValue;
	afx_msg void OnBnClickedOk();
};
