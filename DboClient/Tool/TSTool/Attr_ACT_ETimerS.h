#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_ETimerS ��ȭ �����Դϴ�.

class CAttr_ACT_ETimerS : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_ETimerS)

public:
	CAttr_ACT_ETimerS();
	virtual ~CAttr_ACT_ETimerS();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_EXCEPT_TIMER_S_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	CComboBox m_ctrTimerSort;
	DWORD m_dwWaitTime;
	DWORD m_tgID;
};
