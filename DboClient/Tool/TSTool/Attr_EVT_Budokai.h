#pragma once


#include "Attr_Page.h"


// CAttr_EVT_Budokai ��ȭ �����Դϴ�.

class CAttr_EVT_Budokai : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_EVT_Budokai)

public:
	CAttr_EVT_Budokai(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_EVT_Budokai();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_EVT_BUDOKAI_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
