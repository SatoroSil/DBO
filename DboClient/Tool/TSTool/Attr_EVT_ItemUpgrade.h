#pragma once


#include "Attr_Page.h"


// CAttr_EVT_ItemUpgrade ��ȭ �����Դϴ�.

class CAttr_EVT_ItemUpgrade : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_EVT_ItemUpgrade)

public:
	CAttr_EVT_ItemUpgrade(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_EVT_ItemUpgrade();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_EVT_ITEMUPGRADE_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
