#pragma once


#include "Attr_Page.h"


// CAttr_COND_Lvl ��ȭ �����Դϴ�.

class CAttr_COND_Lvl : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_Lvl)

public:
	CAttr_COND_Lvl();
	virtual ~CAttr_COND_Lvl();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_LVL_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	int m_nMinLevel;
	int m_nMaxLevel;
};
