// Attr_EVT_ItemIdentity.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_ItemIdentity.h"


// CAttr_EVT_ItemIdentity ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_ItemIdentity, CAttr_Page, 1)

CAttr_EVT_ItemIdentity::CAttr_EVT_ItemIdentity(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_ItemIdentity::IDD)
{

}

CAttr_EVT_ItemIdentity::~CAttr_EVT_ItemIdentity()
{
}

CString CAttr_EVT_ItemIdentity::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_ItemIdentity::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_ItemIdentity::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_ItemIdentity::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_ItemIdentity, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_ItemIdentity �޽��� ó�����Դϴ�.
