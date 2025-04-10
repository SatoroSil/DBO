// Attr_ACT_Escort.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_ACT_Escort.h"
#include "NtlSharedType.h"
#include "NtlDirection.h"


// CAttr_ACT_Escort ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_ACT_Escort, CAttr_Page, 1)

CAttr_ACT_Escort::CAttr_ACT_Escort()
	: CAttr_Page(CAttr_ACT_Escort::IDD)
	, m_taID(NTL_TS_TA_ID_INVALID)
	, m_dwNPCTblIdx( 0xffffffff )
{

}

CAttr_ACT_Escort::~CAttr_ACT_Escort()
{
}

CString CAttr_ACT_Escort::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("taid"), m_taID );
	strData += PakingPageData( _T("start"), (int)m_ctrStartType.GetItemData( m_ctrStartType.GetCurSel() ) );
	strData += PakingPageData( _T("etype"), (int)m_ctrEscortType.GetItemData( m_ctrEscortType.GetCurSel() ) );
	strData += PakingPageData( _T("tsshare"), (int)m_ctrShareType.GetItemData( m_ctrShareType.GetCurSel() ) );
	strData += PakingPageData( _T("tblidx"), m_dwNPCTblIdx );

	return strData;
}

void CAttr_ACT_Escort::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("taid") == strKey )
	{
		m_taID = atoi( strValue.GetBuffer() );
	}
	else if ( _T("start") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrStartType.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrStartType.GetItemData( i ) == nValue )
			{
				m_ctrStartType.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("etype") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrEscortType.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrEscortType.GetItemData( i ) == nValue )
			{
				m_ctrEscortType.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("tsshare") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrShareType.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrShareType.GetItemData( i ) == nValue )
			{
				m_ctrShareType.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("tblidx") == strKey )
	{
		m_dwNPCTblIdx = atoi( strValue.GetBuffer() );
	}
}

void CAttr_ACT_Escort::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TS_ACT_ATTR_ESCORT_ID_EDITOR, m_taID);
	DDV_MinMaxUInt(pDX, m_taID, 0, NTL_TS_TA_ID_INVALID);

	DDX_Control(pDX, IDC_TS_ACT_ATTR_ESCORT_START_COMBO, m_ctrStartType);
	DDX_Control(pDX, IDC_TS_ACT_ATTR_ESCORT_TYPE_COMBO, m_ctrEscortType);
	DDX_Control(pDX, IDC_TS_ACT_ATTR_ESCORT_SHARETYPE_COMBO, m_ctrShareType);

	DDX_Text(pDX, IDC_TS_ACT_ATTR_ESCORT_NPCTBLIDX_EDITOR, m_dwNPCTblIdx);
}

BOOL CAttr_ACT_Escort::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctrStartType.SetItemData( m_ctrStartType.AddString( _T("����") ), 0 );
	int nIdx = m_ctrStartType.AddString( _T("����") );
	m_ctrStartType.SetItemData( nIdx, 1 );
	m_ctrStartType.SetCurSel( nIdx );

	m_ctrEscortType.SetItemData( m_ctrEscortType.AddString( _T("Follow") ), ESCORT_TYPE_TARGET_FOLLOW );
	nIdx = m_ctrEscortType.AddString( _T("Under escort") );
	m_ctrEscortType.SetItemData( nIdx, ESCORT_TYPE_UNDER_ESCORT );
	m_ctrEscortType.SetCurSel( nIdx );

	m_ctrShareType.SetItemData( m_ctrShareType.AddString( _T("���� ����") ), SHARE_INDIVISUAL );
	nIdx = m_ctrShareType.AddString( _T("��Ƽ ����") );
	m_ctrShareType.SetItemData( nIdx, SHARE_PARTY );
	m_ctrShareType.SetCurSel( nIdx );

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_ACT_Escort, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_ACT_Escort �޽��� ó�����Դϴ�.
