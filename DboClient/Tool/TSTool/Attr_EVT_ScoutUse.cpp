// Attr_EVT_ScoutUse.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_ScoutUse.h"


// CAttr_EVT_ScoutUse ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_ScoutUse, CAttr_Page, 1)

CAttr_EVT_ScoutUse::CAttr_EVT_ScoutUse(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_ScoutUse::IDD)
	, m_dwItemIdx(0xffffffff)
	, m_dwTargetIdx(0xffffffff)
{

}

CAttr_EVT_ScoutUse::~CAttr_EVT_ScoutUse()
{
}

CString CAttr_EVT_ScoutUse::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("idx"), m_dwItemIdx );
	strData += PakingPageData( _T("tt"), (int)m_ctrTargetTypeCombo.GetItemData( m_ctrTargetTypeCombo.GetCurSel() ) );
	strData += PakingPageData( _T("tidx"), m_dwTargetIdx );

	return strData;
}

void CAttr_EVT_ScoutUse::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("idx") == strKey )
	{
		m_dwItemIdx = atoi( strValue.GetBuffer() );
	}
	else if ( _T("tt") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrTargetTypeCombo.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrTargetTypeCombo.GetItemData( i ) == nValue )
			{
				m_ctrTargetTypeCombo.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("tidx") == strKey )
	{
		m_dwTargetIdx = atoi( strValue.GetBuffer() );
	}
}

void CAttr_EVT_ScoutUse::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TS_EVT_ATTR_SCOUTER_USE_EDITOR, m_dwItemIdx);
	DDX_Control(pDX, IDC_TS_EVT_ATTR_SCOUTER_USE_TARGET_TYPE_COMBO, m_ctrTargetTypeCombo );
	DDX_Text(pDX, IDC_TS_EVT_ATTR_SCOUTER_USE_TARGET_IDX_EDITOR, m_dwTargetIdx);
}

BOOL CAttr_EVT_ScoutUse::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctrTargetTypeCombo.SetItemData( m_ctrTargetTypeCombo.AddString( _T("Mob") ), eEVENT_SCOUTER_TARGET_TYPE_MOB );
	m_ctrTargetTypeCombo.SetItemData( m_ctrTargetTypeCombo.AddString( _T("NPC") ), eEVENT_SCOUTER_TARGET_TYPE_NPC );
	m_ctrTargetTypeCombo.SetItemData( m_ctrTargetTypeCombo.AddString( _T("Avatar") ), eEVENT_SCOUTER_TARGET_TYPE_AVATAR );
	int nIdx = m_ctrTargetTypeCombo.AddString( _T("All") );
	m_ctrTargetTypeCombo.SetItemData(  nIdx, eEVENT_SCOUTER_TARGET_TYPE_ALL );
	m_ctrTargetTypeCombo.SetCurSel( nIdx );

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_ScoutUse, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_ScoutUse �޽��� ó�����Դϴ�.
