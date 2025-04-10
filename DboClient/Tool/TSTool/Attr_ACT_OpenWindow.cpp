// CAttr_ACT_OpenWindow.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_ACT_OpenWindow.h"


// CAttr_ACT_OpenWindow ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_ACT_OpenWindow, CAttr_Page, 1)

CAttr_ACT_OpenWindow::CAttr_ACT_OpenWindow()
	: CAttr_Page(CAttr_ACT_OpenWindow::IDD)
	, m_nCurSelIndex( -1 )
	, m_taID(NTL_TS_TA_ID_INVALID)
	, m_dwTblIdx( 0xffffffff )
{
	m_defMapList[eWINDOW_TYPE_INVALID].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_STATIC );
	m_defMapList[eWINDOW_TYPE_INVALID].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_EDITOR );

	m_defMapList[eWINDOW_TYPE_TUTORIALHINT].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_STATIC );
	m_defMapList[eWINDOW_TYPE_TUTORIALHINT].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_EDITOR );

	//m_defMapList[eWINDOW_TYPE_HELP].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_STATIC );
	//m_defMapList[eWINDOW_TYPE_HELP].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_EDITOR );

	//m_defMapList[eWINDOW_TYPE_INVENTORY].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_STATIC );
	//m_defMapList[eWINDOW_TYPE_INVENTORY].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_EDITOR );

	//m_defMapList[eWINDOW_TYPE_SKILL].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_STATIC );
	//m_defMapList[eWINDOW_TYPE_SKILL].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_EDITOR );

	//m_defMapList[eWINDOW_TYPE_CHARINFO].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_STATIC );
	//m_defMapList[eWINDOW_TYPE_CHARINFO].push_back( IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_EDITOR );
}

CAttr_ACT_OpenWindow::~CAttr_ACT_OpenWindow()
{
}

CString CAttr_ACT_OpenWindow::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("taid"), m_taID );

	if ( m_ctrShowBtn.GetCheck() == BST_CHECKED )	strData += PakingPageData( _T("show"), 1 );
	else strData += PakingPageData( _T("show"), 0 );

	strData += PakingPageData( _T("wtype"), (int)m_ctrWindowTypeCombo.GetItemData( m_ctrWindowTypeCombo.GetCurSel() ) );

	strData += PakingPageData( _T("tblidx"), m_dwTblIdx );

	return strData;
}

void CAttr_ACT_OpenWindow::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("taid") == strKey )
	{
		m_taID = atoi( strValue.GetBuffer() );
	}
	else if ( _T("show") == strKey )
	{
		bool bShow = (bool)atoi( strValue.GetBuffer() );

		if ( bShow )
		{
			m_ctrShowBtn.SetCheck( BST_CHECKED );
		}
		else
		{
			m_ctrShowBtn.SetCheck( BST_UNCHECKED );
		}
	}
	else if ( _T("wtype") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrWindowTypeCombo.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrWindowTypeCombo.GetItemData( i ) == nValue )
			{
				m_ctrWindowTypeCombo.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("tblidx") == strKey )
	{
		m_dwTblIdx = atoi( strValue.GetBuffer() );
	}
}

void CAttr_ACT_OpenWindow::InitData( void )
{
	m_dwTblIdx = 0xffffffff;

	UpdateData( FALSE );
}

void CAttr_ACT_OpenWindow::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TS_ACT_ATTR_OPENWINDOW_ID_EDITOR, m_taID);
	DDV_MinMaxUInt(pDX, m_taID, 0, NTL_TS_TA_ID_INVALID);
	DDX_Control(pDX, IDC_TS_ACT_ATTR_OPENWINDOW_SHOW_CHECKBOX, m_ctrShowBtn);
	DDX_Control(pDX, IDC_TS_ACT_ATTR_OPENWINDOW_WINDOW_TYPE_COMBO, m_ctrWindowTypeCombo);
	DDX_Text(pDX, IDC_TS_ACT_ATTR_OPENWINDOW_TBLIDX_EDITOR, m_dwTblIdx);
}

BOOL CAttr_ACT_OpenWindow::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_ctrShowBtn.SetCheck( BST_CHECKED );

	m_ctrWindowTypeCombo.SetItemData( m_ctrWindowTypeCombo.AddString( _T("Ʃ�丮�� ��Ʈ â") ), eWINDOW_TYPE_TUTORIALHINT );
	m_ctrWindowTypeCombo.SetItemData( m_ctrWindowTypeCombo.AddString( _T("���� â") ), eWINDOW_TYPE_HELP );
	m_ctrWindowTypeCombo.SetItemData( m_ctrWindowTypeCombo.AddString( _T("�κ��丮 â") ), eWINDOW_TYPE_INVENTORY );
	m_ctrWindowTypeCombo.SetItemData( m_ctrWindowTypeCombo.AddString( _T("��ų â") ), eWINDOW_TYPE_SKILL );
	int nIdx = m_ctrWindowTypeCombo.AddString( _T("ĳ���� ���� â") );
	m_ctrWindowTypeCombo.SetItemData( nIdx, eWINDOW_TYPE_CHARINFO );
	m_ctrWindowTypeCombo.SetCurSel( nIdx );

	vecdef_ControlList::iterator it = m_defMapList[eWINDOW_TYPE_INVALID].begin();
	for ( ; it != m_defMapList[eWINDOW_TYPE_INVALID].end(); ++it )
	{
		GetDlgItem( *it )->ShowWindow( SW_HIDE );
	}

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	OnCbnSelchangeTsActAttrOpenWindowCombo();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_ACT_OpenWindow, CAttr_Page)
	ON_CBN_SELCHANGE(IDC_TS_ACT_ATTR_OPENWINDOW_WINDOW_TYPE_COMBO, &CAttr_ACT_OpenWindow::OnCbnSelchangeTsActAttrOpenWindowCombo)
END_MESSAGE_MAP()


// CAttr_ACT_OpenWindow �޽��� ó�����Դϴ�.
void CAttr_ACT_OpenWindow::OnCbnSelchangeTsActAttrOpenWindowCombo()
{
	if ( -1 != m_nCurSelIndex )
	{
		DWORD dwData = (DWORD)m_ctrWindowTypeCombo.GetItemData( m_nCurSelIndex );

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

	m_nCurSelIndex = m_ctrWindowTypeCombo.GetCurSel();
	if ( CB_ERR != m_nCurSelIndex )
	{
		DWORD dwData = (DWORD)m_ctrWindowTypeCombo.GetItemData( m_nCurSelIndex );

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
