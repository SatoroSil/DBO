// Attr_EVT_Teleport.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_Teleport.h"


// CAttr_EVT_Teleport ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_Teleport, CAttr_Page, 1)

CAttr_EVT_Teleport::CAttr_EVT_Teleport(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_Teleport::IDD)
{

}

CAttr_EVT_Teleport::~CAttr_EVT_Teleport()
{
}

CString CAttr_EVT_Teleport::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_Teleport::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_Teleport::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_Teleport::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_Teleport, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_Teleport �޽��� ó�����Դϴ�.
