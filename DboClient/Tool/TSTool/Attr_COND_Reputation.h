#pragma once


#include "Attr_Page.h"


// CAttr_COND_Reputation ��ȭ �����Դϴ�.

class CAttr_COND_Reputation : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_Reputation)

public:
	CAttr_COND_Reputation();
	virtual ~CAttr_COND_Reputation();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_REPUTATION_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	int m_nMinRT;
	int m_nMaxRT;
};
