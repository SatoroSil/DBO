// Attr_EVT_BindStone.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_BindStone.h"


// CAttr_EVT_BindStone ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_BindStone, CAttr_Page, 1)

CAttr_EVT_BindStone::CAttr_EVT_BindStone(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_BindStone::IDD)
{

}

CAttr_EVT_BindStone::~CAttr_EVT_BindStone()
{
}

CString CAttr_EVT_BindStone::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_BindStone::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_BindStone::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_BindStone::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_BindStone, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_BindStone �޽��� ó�����Դϴ�.
