#pragma once


#include "Attr_Page.h"


// CAttr_COND_ClrQst ��ȭ �����Դϴ�.

class CAttr_COND_ClrQst : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_ClrQst)

public:
	CAttr_COND_ClrQst();
	virtual ~CAttr_COND_ClrQst();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_CLRQST_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CString m_strAndList;
	CString m_strOrList;
};
