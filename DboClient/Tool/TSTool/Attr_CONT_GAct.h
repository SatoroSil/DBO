#pragma once


#include "Attr_Page.h"


// CAttr_CONT_GAct ��ȭ �����Դϴ�.

class CAttr_CONT_GAct : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_CONT_GAct)

public:
	CAttr_CONT_GAct();
	virtual ~CAttr_CONT_GAct();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_CONT_GACT_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	DWORD m_tcID;
};
