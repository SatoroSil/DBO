#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_ETimerE ��ȭ �����Դϴ�.

class CAttr_ACT_ETimerE : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_ETimerE)

public:
	CAttr_ACT_ETimerE();
	virtual ~CAttr_ACT_ETimerE();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_EXCEPT_TIMER_E_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;

	DWORD m_tcEID;
	DWORD m_taEID;
};
