// Attr_COND_OperateObject.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_COND_OperateObject.h"


// CAttr_COND_OperateObject ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_COND_OperateObject, CAttr_Page, 1)

CAttr_COND_OperateObject::CAttr_COND_OperateObject()
	: CAttr_Page(CAttr_COND_OperateObject::IDD)
{

}

CAttr_COND_OperateObject::~CAttr_COND_OperateObject()
{
}

CString CAttr_COND_OperateObject::GetPageData( void )
{
	UpdateData( TRUE );

	return CString(_T(""));
}

void CAttr_COND_OperateObject::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_COND_OperateObject::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAttr_COND_OperateObject, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_COND_OperateObject �޽��� ó�����Դϴ�.
