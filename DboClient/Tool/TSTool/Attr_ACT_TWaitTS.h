#pragma once


#include "Attr_Page.h"


// CAttr_ACT_TWaitTS ��ȭ �����Դϴ�.

class CAttr_ACT_TWaitTS : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_TWaitTS)

public:
	CAttr_ACT_TWaitTS();
	virtual ~CAttr_ACT_TWaitTS();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_TWAITTS_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	DWORD m_dwWTime;
};
