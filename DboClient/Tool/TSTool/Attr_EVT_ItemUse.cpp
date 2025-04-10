// Attr_EVT_ItemUse.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_ItemUse.h"


// CAttr_EVT_ItemUse ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_ItemUse, CAttr_Page, 1)

CAttr_EVT_ItemUse::CAttr_EVT_ItemUse(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_ItemUse::IDD)
	, m_dwItemIdx(0xffffffff)
	, m_dwItemTargetIdx(0xffffffff)
{

}

CAttr_EVT_ItemUse::~CAttr_EVT_ItemUse()
{
}

CString CAttr_EVT_ItemUse::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("idx"), m_dwItemIdx );
	strData += PakingPageData( _T("ttype"), (int)m_ctrItemTargetTypeCombo.GetItemData( m_ctrItemTargetTypeCombo.GetCurSel() ) );
	strData += PakingPageData( _T("tidx"), m_dwItemTargetIdx );

	return strData;
}

void CAttr_EVT_ItemUse::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("idx") == strKey )
	{
		m_dwItemIdx = atoi( strValue.GetBuffer() );
	}
	else if ( _T("ttype") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrItemTargetTypeCombo.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrItemTargetTypeCombo.GetItemData( i ) == nValue )
			{
				m_ctrItemTargetTypeCombo.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("tidx") == strKey )
	{
		m_dwItemTargetIdx = atoi( strValue.GetBuffer() );
	}
}

void CAttr_EVT_ItemUse::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TS_EVT_ATTR_ITEM_USE_EDITOR, m_dwItemIdx);
	DDX_Control(pDX, IDC_TS_EVT_ATTR_ITEMUSE_ITEMTARGETTYPE_COMBO, m_ctrItemTargetTypeCombo );
	DDX_Text(pDX, IDC_TS_EVT_ATTR_ITEMUSE_ITEMTARGETIDX_EDITOR, m_dwItemTargetIdx);
}

BOOL CAttr_EVT_ItemUse::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctrItemTargetTypeCombo.SetItemData( m_ctrItemTargetTypeCombo.AddString( _T("Mob") ), eEVENT_ITEM_TARGET_TYPE_MOB );
	m_ctrItemTargetTypeCombo.SetItemData( m_ctrItemTargetTypeCombo.AddString( _T("NPC") ), eEVENT_ITEM_TARGET_TYPE_NPC );
	m_ctrItemTargetTypeCombo.SetItemData( m_ctrItemTargetTypeCombo.AddString( _T("Avatar") ), eEVENT_ITEM_TARGET_TYPE_AVATAR );
	int nIdx = m_ctrItemTargetTypeCombo.AddString( _T("All") );
	m_ctrItemTargetTypeCombo.SetItemData( nIdx, eEVENT_ITEM_TARGET_TYPE_ALL );
	m_ctrItemTargetTypeCombo.SetCurSel( nIdx );

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_ItemUse, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_ItemUse �޽��� ó�����Դϴ�.
