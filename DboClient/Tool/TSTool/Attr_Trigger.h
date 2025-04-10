#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_Trigger ��ȭ �����Դϴ�.

class CAttr_Trigger : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_Trigger)

public:
	CAttr_Trigger();
	virtual ~CAttr_Trigger();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_TRIGGER_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_tID;
	CButton m_ctrRepeat;
	CButton m_ctrCanShare;
	CButton m_ctrOutStateMsg;
	DWORD m_uiTitle;

public:
	afx_msg void OnBnClickedTsTriggerAttrDefIndexBtn();
public:
	afx_msg void OnBnClickedTsTriggerAttrRwdApplyBtn();
};
