// Attr_EVT_ItemEquip.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_ItemEquip.h"


// CAttr_EVT_ItemEquip ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_ItemEquip, CAttr_Page, 1)

CAttr_EVT_ItemEquip::CAttr_EVT_ItemEquip(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_ItemEquip::IDD)
	, m_dwItemIdx(0xffffffff)
{

}

CAttr_EVT_ItemEquip::~CAttr_EVT_ItemEquip()
{
}

CString CAttr_EVT_ItemEquip::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("idx"), m_dwItemIdx );

	return strData;
}

void CAttr_EVT_ItemEquip::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("idx") == strKey )
	{
		m_dwItemIdx = atoi( strValue.GetBuffer() );
	}
}

void CAttr_EVT_ItemEquip::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TS_EVT_ATTR_SCOUT_USE_EDITOR, m_dwItemIdx);
}


BEGIN_MESSAGE_MAP(CAttr_EVT_ItemEquip, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_ItemEquip �޽��� ó�����Դϴ�.
