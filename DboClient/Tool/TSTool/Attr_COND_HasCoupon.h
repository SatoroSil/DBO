#pragma once


#include "Attr_Page.h"


// CAttr_COND_HasCoupon ��ȭ �����Դϴ�.

class CAttr_COND_HasCoupon : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_HasCoupon)

public:
	CAttr_COND_HasCoupon();
	virtual ~CAttr_COND_HasCoupon();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_HAS_COUPON_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
};
