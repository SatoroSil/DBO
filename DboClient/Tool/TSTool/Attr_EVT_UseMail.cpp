// Attr_EVT_UseMail.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_UseMail.h"


// CAttr_EVT_UseMail ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_UseMail, CAttr_Page, 1)

CAttr_EVT_UseMail::CAttr_EVT_UseMail(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_UseMail::IDD)
{

}

CAttr_EVT_UseMail::~CAttr_EVT_UseMail()
{
}

CString CAttr_EVT_UseMail::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_UseMail::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_UseMail::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_UseMail::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_UseMail, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_UseMail �޽��� ó�����Դϴ�.
