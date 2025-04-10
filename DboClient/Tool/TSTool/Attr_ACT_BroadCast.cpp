// Attr_ACT_BroadCast.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_ACT_BroadCast.h"
#include "NtlDirection.h"


// CAttr_ACT_BroadCast ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_ACT_BroadCast, CAttr_Page, 1)

CAttr_ACT_BroadCast::CAttr_ACT_BroadCast()
	: CAttr_Page(CAttr_ACT_BroadCast::IDD)
	, m_nCurSelIndex( -1 )
	, m_taID(NTL_TS_TA_ID_INVALID)
	, m_dwNPCTblIdx( 0xffffffff )
	, m_dwSpeechTblIdx( 0xffffffff )
	, m_dwDisplayTime( 0xffffffff )
{
	m_defMapList[eTSTELECAST_TYPE_INVALID].push_back( IDD_TS_ACT_BROADCAST_NPCINDEX_STATIC );
	m_defMapList[eTSTELECAST_TYPE_INVALID].push_back( IDD_TS_ACT_BROADCAST_NPCINDEX_EDITOR );
	m_defMapList[eTSTELECAST_TYPE_INVALID].push_back( IDD_TS_ACT_BROADCAST_MESSAGETYPE_STATIC );
	m_defMapList[eTSTELECAST_TYPE_INVALID].push_back( IDD_TS_ACT_BROADCAST_MESSAGETYPE_COMBO );
	m_defMapList[eTSTELECAST_TYPE_INVALID].push_back( IDD_TS_ACT_BROADCAST_SPEECHINDEX_STATIC );
	m_defMapList[eTSTELECAST_TYPE_INVALID].push_back( IDD_TS_ACT_BROADCAST_SPEECHINDEX_EDITOR );
	m_defMapList[eTSTELECAST_TYPE_INVALID].push_back( IDD_TS_ACT_BROADCAST_DISPLAYTIME_STATIC );
	m_defMapList[eTSTELECAST_TYPE_INVALID].push_back( IDD_TS_ACT_BROADCAST_DISPLAYTIME_EDITOR );

	m_defMapList[eTSTELECAST_TYPE_TIME].push_back( IDD_TS_ACT_BROADCAST_NPCINDEX_STATIC );
	m_defMapList[eTSTELECAST_TYPE_TIME].push_back( IDD_TS_ACT_BROADCAST_NPCINDEX_EDITOR );
	m_defMapList[eTSTELECAST_TYPE_TIME].push_back( IDD_TS_ACT_BROADCAST_MESSAGETYPE_STATIC );
	m_defMapList[eTSTELECAST_TYPE_TIME].push_back( IDD_TS_ACT_BROADCAST_MESSAGETYPE_COMBO );
	m_defMapList[eTSTELECAST_TYPE_TIME].push_back( IDD_TS_ACT_BROADCAST_SPEECHINDEX_STATIC );
	m_defMapList[eTSTELECAST_TYPE_TIME].push_back( IDD_TS_ACT_BROADCAST_SPEECHINDEX_EDITOR );
	m_defMapList[eTSTELECAST_TYPE_TIME].push_back( IDD_TS_ACT_BROADCAST_DISPLAYTIME_STATIC );
	m_defMapList[eTSTELECAST_TYPE_TIME].push_back( IDD_TS_ACT_BROADCAST_DISPLAYTIME_EDITOR );

	m_defMapList[eTSTELECAST_TYPE_BEGIN].push_back( IDD_TS_ACT_BROADCAST_NPCINDEX_STATIC );
	m_defMapList[eTSTELECAST_TYPE_BEGIN].push_back( IDD_TS_ACT_BROADCAST_NPCINDEX_EDITOR );
	m_defMapList[eTSTELECAST_TYPE_BEGIN].push_back( IDD_TS_ACT_BROADCAST_MESSAGETYPE_STATIC );
	m_defMapList[eTSTELECAST_TYPE_BEGIN].push_back( IDD_TS_ACT_BROADCAST_MESSAGETYPE_COMBO );
	m_defMapList[eTSTELECAST_TYPE_BEGIN].push_back( IDD_TS_ACT_BROADCAST_SPEECHINDEX_STATIC );
	m_defMapList[eTSTELECAST_TYPE_BEGIN].push_back( IDD_TS_ACT_BROADCAST_SPEECHINDEX_EDITOR );
}

CAttr_ACT_BroadCast::~CAttr_ACT_BroadCast()
{
}

void CAttr_ACT_BroadCast::InitData( void )
{
	m_nCurSelIndex = -1;
	m_taID = NTL_TS_TA_ID_INVALID;
	m_dwNPCTblIdx = 0xffffffff;
	m_dwSpeechTblIdx = 0xffffffff;
	m_dwDisplayTime = 0xffffffff;

	UpdateData( FALSE );
}

CString CAttr_ACT_BroadCast::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("taid"), m_taID );
	strData += PakingPageData( _T("type"), (int)m_ctrTypeCtrl.GetItemData( m_ctrTypeCtrl.GetCurSel() ) );
	strData += PakingPageData( _T("npcidx"), m_dwNPCTblIdx );
	strData += PakingPageData( _T("msgtype"), (int)m_clMessageTypeCtrl.GetItemData( m_clMessageTypeCtrl.GetCurSel() ) );
	strData += PakingPageData( _T("speechidx"), m_dwSpeechTblIdx );
	strData += PakingPageData( _T("dsptime"), m_dwDisplayTime );

	return strData;
}

void CAttr_ACT_BroadCast::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("taid") == strKey )
	{
		m_taID = atoi( strValue.GetBuffer() );
	}
	else if ( _T("type") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrTypeCtrl.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrTypeCtrl.GetItemData( i ) == nValue )
			{
				m_ctrTypeCtrl.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("npcidx") == strKey )
	{
		m_dwNPCTblIdx = atoi( strValue.GetBuffer() );
	}
	else if ( _T("msgtype") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_clMessageTypeCtrl.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_clMessageTypeCtrl.GetItemData( i ) == nValue )
			{
				m_clMessageTypeCtrl.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("speechidx") == strKey )
	{
		m_dwSpeechTblIdx = atoi( strValue.GetBuffer() );
	}
	else if ( _T("dsptime") == strKey )
	{
		m_dwDisplayTime = atoi( strValue.GetBuffer() );
	}
}

void CAttr_ACT_BroadCast::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TS_ACT_ATTR_BROADCAST_ID_EDITOR, m_taID);
	DDV_MinMaxUInt(pDX, m_taID, 0, NTL_TS_TA_ID_INVALID);

	DDX_Control(pDX, IDD_TS_ACT_BROADCAST_TYPE_COMBO, m_ctrTypeCtrl);
	DDX_Text(pDX, IDD_TS_ACT_BROADCAST_NPCINDEX_EDITOR, m_dwNPCTblIdx);
	DDX_Control(pDX, IDD_TS_ACT_BROADCAST_MESSAGETYPE_COMBO, m_clMessageTypeCtrl);
	DDX_Text(pDX, IDD_TS_ACT_BROADCAST_SPEECHINDEX_EDITOR, m_dwSpeechTblIdx);
	DDX_Text(pDX, IDD_TS_ACT_BROADCAST_DISPLAYTIME_EDITOR, m_dwDisplayTime);
}

BOOL CAttr_ACT_BroadCast::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctrTypeCtrl.SetItemData( m_ctrTypeCtrl.AddString( _T("����") ), eTSTELECAST_TYPE_BEGIN );
	m_ctrTypeCtrl.SetItemData( m_ctrTypeCtrl.AddString( _T("����") ), eTSTELECAST_TYPE_END );
	int nIdx = m_ctrTypeCtrl.AddString( _T("�ð�") );
	m_ctrTypeCtrl.SetItemData( nIdx, eTSTELECAST_TYPE_TIME );
	m_ctrTypeCtrl.SetCurSel( nIdx );

	m_clMessageTypeCtrl.SetItemData( m_clMessageTypeCtrl.AddString( _T("Danger") ), TELECAST_MESSAGE_TYPE_DANGER );
	m_clMessageTypeCtrl.SetItemData( m_clMessageTypeCtrl.AddString( _T("Warning") ), TELECAST_MESSAGE_TYPE_WARNING );
	nIdx = m_clMessageTypeCtrl.AddString( _T("Normal") );
	m_clMessageTypeCtrl.SetItemData( nIdx, TELECAST_MESSAGE_TYPE_NORMAL );
	m_clMessageTypeCtrl.SetCurSel( nIdx );

	vecdef_ControlList::iterator it = m_defMapList[eTSTELECAST_TYPE_INVALID].begin();
	for ( ; it != m_defMapList[eTSTELECAST_TYPE_INVALID].end(); ++it )
	{
		GetDlgItem( *it )->ShowWindow( SW_HIDE );
	}

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	OnCbnSelchangeTsActAttrBroadcastTypeCombo();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_ACT_BroadCast, CAttr_Page)
	ON_CBN_SELCHANGE(IDD_TS_ACT_BROADCAST_TYPE_COMBO, &CAttr_ACT_BroadCast::OnCbnSelchangeTsActAttrBroadcastTypeCombo)
END_MESSAGE_MAP()


// CAttr_ACT_BroadCast �޽��� ó�����Դϴ�.

void CAttr_ACT_BroadCast::OnCbnSelchangeTsActAttrBroadcastTypeCombo()
{
	if ( -1 != m_nCurSelIndex )
	{
		DWORD dwData = (DWORD)m_ctrTypeCtrl.GetItemData( m_nCurSelIndex );

		if ( m_defMapList.end() != m_defMapList.find( dwData ) )
		{
			vecdef_ControlList::iterator it = m_defMapList[dwData].begin();
			for ( ; it != m_defMapList[dwData].end(); ++it )
			{
				GetDlgItem( *it )->ShowWindow( SW_HIDE );
			}
		}

		InitData();
	}

	m_nCurSelIndex = m_ctrTypeCtrl.GetCurSel();
	if ( CB_ERR != m_nCurSelIndex )
	{
		DWORD dwData = (DWORD)m_ctrTypeCtrl.GetItemData( m_nCurSelIndex );

		if ( m_defMapList.end() != m_defMapList.find( dwData ) )
		{
			vecdef_ControlList::iterator it = m_defMapList[dwData].begin();
			for ( ; it != m_defMapList[dwData].end(); ++it )
			{
				GetDlgItem( *it )->ShowWindow( SW_SHOW );
			}
		}
		else
		{
			m_nCurSelIndex = -1;
		}
	}
	else
	{
		m_nCurSelIndex = -1;
	}
}
