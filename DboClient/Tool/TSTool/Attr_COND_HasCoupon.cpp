// Attr_COND_HasCoupon.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_COND_HasCoupon.h"


// CAttr_COND_HasCoupon ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_COND_HasCoupon, CAttr_Page, 1)

CAttr_COND_HasCoupon::CAttr_COND_HasCoupon()
	: CAttr_Page(CAttr_COND_HasCoupon::IDD)
{

}

CAttr_COND_HasCoupon::~CAttr_COND_HasCoupon()
{
}

CString CAttr_COND_HasCoupon::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_COND_HasCoupon::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_COND_HasCoupon::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAttr_COND_HasCoupon, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_COND_HasCoupon �޽��� ó�����Դϴ�.
