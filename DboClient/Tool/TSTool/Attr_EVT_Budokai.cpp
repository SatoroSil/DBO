// Attr_EVT_Budokai.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_Budokai.h"


// CAttr_EVT_Budokai ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_Budokai, CAttr_Page, 1)

CAttr_EVT_Budokai::CAttr_EVT_Budokai(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_Budokai::IDD)
{

}

CAttr_EVT_Budokai::~CAttr_EVT_Budokai()
{
}

CString CAttr_EVT_Budokai::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_Budokai::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_Budokai::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_Budokai::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_Budokai, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_Budokai �޽��� ó�����Դϴ�.
