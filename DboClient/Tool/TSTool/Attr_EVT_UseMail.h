#pragma once


#include "Attr_Page.h"


// CAttr_EVT_UseMail ��ȭ �����Դϴ�.

class CAttr_EVT_UseMail : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_EVT_UseMail)

public:
	CAttr_EVT_UseMail(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_EVT_UseMail();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_EVT_USEMAIL_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
