// Attr_EVT_SlotMachine.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_SlotMachine.h"


// CAttr_EVT_SlotMachine ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_SlotMachine, CAttr_Page, 1)

CAttr_EVT_SlotMachine::CAttr_EVT_SlotMachine(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_SlotMachine::IDD)
{

}

CAttr_EVT_SlotMachine::~CAttr_EVT_SlotMachine()
{
}

CString CAttr_EVT_SlotMachine::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_SlotMachine::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_SlotMachine::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_SlotMachine::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_SlotMachine, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_SlotMachine �޽��� ó�����Դϴ�.
