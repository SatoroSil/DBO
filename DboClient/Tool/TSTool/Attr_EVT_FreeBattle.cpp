// Attr_EVT_FreeBattle.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_FreeBattle.h"


// CAttr_EVT_FreeBattle ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_FreeBattle, CAttr_Page, 1)

CAttr_EVT_FreeBattle::CAttr_EVT_FreeBattle(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_FreeBattle::IDD)
{

}

CAttr_EVT_FreeBattle::~CAttr_EVT_FreeBattle()
{
}

CString CAttr_EVT_FreeBattle::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_FreeBattle::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_FreeBattle::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_FreeBattle::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_FreeBattle, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_FreeBattle �޽��� ó�����Դϴ�.
