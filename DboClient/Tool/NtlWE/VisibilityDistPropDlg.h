#pragma once
#include "afxwin.h"


// CVisibilityDistPropDlg ��ȭ �����Դϴ�.

class CVisibilityDistPropDlg : public CDialog
{
	DECLARE_DYNAMIC(CVisibilityDistPropDlg)

public:
	CVisibilityDistPropDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CVisibilityDistPropDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_VISIBILITY_DIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CString m_RangeMin;
	CString m_RangeMax;
	CString m_Dist;
	CButton m_AllFields;

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
