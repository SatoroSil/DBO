#pragma once


#include "Attr_Page.h"


// CAttr_EVT_ItemIdentity ��ȭ �����Դϴ�.

class CAttr_EVT_ItemIdentity : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_EVT_ItemIdentity)

public:
	CAttr_EVT_ItemIdentity(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_EVT_ItemIdentity();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_EVT_ITEMIDENTITY_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
