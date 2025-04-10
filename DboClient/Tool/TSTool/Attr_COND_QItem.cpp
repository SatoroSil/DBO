// Attr_COND_QItem.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_COND_QItem.h"


// CAttr_COND_QItem ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_COND_QItem, CAttr_Page, 1)

CAttr_COND_QItem::CAttr_COND_QItem()
	: CAttr_Page(CAttr_COND_QItem::IDD)
	, m_dwItemIdx(0xffffffff)
	, m_nItemCnt(0)
{

}

CAttr_COND_QItem::~CAttr_COND_QItem()
{
}

CString CAttr_COND_QItem::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("ct"), (int)m_ctrlCheckType.GetItemData( m_ctrlCheckType.GetCurSel() ) );
	strData += PakingPageData( _T("iidx"), m_dwItemIdx );
	strData += PakingPageData( _T("icnt"), m_nItemCnt );

	return strData;
}

void CAttr_COND_QItem::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("ct") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrlCheckType.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrlCheckType.GetItemData( i ) == nValue )
			{
				m_ctrlCheckType.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("iidx") == strKey )
	{
		m_dwItemIdx = atoi( strValue.GetBuffer() );
	}
	else if ( _T("icnt") == strKey )
	{
		m_nItemCnt = atoi( strValue.GetBuffer() );
	}
}

void CAttr_COND_QItem::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TS_COND_ATTR_QITEM_CHECK_TYPE_COMBO, m_ctrlCheckType);
	DDX_Text(pDX, IDC_TS_COND_ATTR_QITEM_ITEMIDX_EDITOR, m_dwItemIdx);
	DDX_Text(pDX, IDC_TS_COND_ATTR_QITEM_ITEMCNT_EDITOR, m_nItemCnt);
}

BOOL CAttr_COND_QItem::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_ctrlCheckType.SetItemData( m_ctrlCheckType.AddString( _T("Equal") ), eQUEST_ITEM_CHECK_TYPE_EQUAL );
	m_ctrlCheckType.SetItemData( m_ctrlCheckType.AddString( _T("Less") ), eQUEST_ITEM_CHECK_TYPE_LESS );
	int nIdx = m_ctrlCheckType.AddString( _T("More") );
	m_ctrlCheckType.SetItemData( nIdx, eQUEST_ITEM_CHECK_TYPE_MORE );
	m_ctrlCheckType.SetCurSel( nIdx );

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_COND_QItem, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_COND_QItem �޽��� ó�����Դϴ�.
