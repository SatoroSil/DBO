// Attr_EVT_ItemUpgrade.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_ItemUpgrade.h"


// CAttr_EVT_ItemUpgrade ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_ItemUpgrade, CAttr_Page, 1)

CAttr_EVT_ItemUpgrade::CAttr_EVT_ItemUpgrade(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_ItemUpgrade::IDD)
{

}

CAttr_EVT_ItemUpgrade::~CAttr_EVT_ItemUpgrade()
{
}

CString CAttr_EVT_ItemUpgrade::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_ItemUpgrade::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_ItemUpgrade::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_ItemUpgrade::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_ItemUpgrade, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_ItemUpgrade �޽��� ó�����Դϴ�.
