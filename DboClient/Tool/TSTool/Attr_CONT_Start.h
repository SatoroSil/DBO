#pragma once


#include "Attr_Page.h"


// CAttr_CONT_Start ��ȭ �����Դϴ�.

class CAttr_CONT_Start : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_CONT_Start)

public:
	CAttr_CONT_Start();
	virtual ~CAttr_CONT_Start();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_CONT_START_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_tcID;
	DWORD m_dwToolTip;
};
