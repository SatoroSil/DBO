// Attr_EVT_SearchQuest.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_SearchQuest.h"


// CAttr_EVT_SearchQuest ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_SearchQuest, CAttr_Page, 1)

CAttr_EVT_SearchQuest::CAttr_EVT_SearchQuest(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_SearchQuest::IDD)
{

}

CAttr_EVT_SearchQuest::~CAttr_EVT_SearchQuest()
{
}

CString CAttr_EVT_SearchQuest::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_SearchQuest::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_SearchQuest::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_SearchQuest::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_SearchQuest, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_SearchQuest �޽��� ó�����Դϴ�.
