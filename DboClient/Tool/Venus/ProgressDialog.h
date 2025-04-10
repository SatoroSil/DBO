#pragma once
#include "afxcmn.h"


// CProgressDialog ��ȭ �����Դϴ�.

class CProgressDialog : public CDialog
{
	DECLARE_DYNAMIC(CProgressDialog)

public:
	CProgressDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CProgressDialog();

	int			m_nCurrentTime;
	int			m_nMaxTime;

	void		Start(char* pWindowTitle, int nMaxTime);

	static CProgressDialog& GetInstance();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROGRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_Progress;
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	CString m_strPercent;
};
