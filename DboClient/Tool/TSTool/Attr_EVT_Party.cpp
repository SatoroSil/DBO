// Attr_EVT_Party.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_Party.h"


// CAttr_EVT_Party ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_Party, CAttr_Page, 1)

CAttr_EVT_Party::CAttr_EVT_Party(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_Party::IDD)
{

}

CAttr_EVT_Party::~CAttr_EVT_Party()
{
}

CString CAttr_EVT_Party::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_Party::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_Party::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_Party::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_Party, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_Party �޽��� ó�����Դϴ�.
