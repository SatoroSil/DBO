// Attr_EVT_PrivateShop.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_PrivateShop.h"


// CAttr_EVT_PrivateShop ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_PrivateShop, CAttr_Page, 1)

CAttr_EVT_PrivateShop::CAttr_EVT_PrivateShop(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_PrivateShop::IDD)
{

}

CAttr_EVT_PrivateShop::~CAttr_EVT_PrivateShop()
{
}

CString CAttr_EVT_PrivateShop::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_PrivateShop::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_PrivateShop::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_PrivateShop::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_PrivateShop, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_PrivateShop �޽��� ó�����Դϴ�.
