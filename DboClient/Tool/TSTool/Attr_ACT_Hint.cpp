// Attr_ACT_Hint.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_ACT_Hint.h"


// CAttr_ACT_Hint ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_ACT_Hint, CAttr_Page, 1)

CAttr_ACT_Hint::CAttr_ACT_Hint()
	: CAttr_Page(CAttr_ACT_Hint::IDD)
	, m_taID(NTL_TS_TA_ID_INVALID)
	, m_dwHintIdx(0xffffffff)
{

}

CAttr_ACT_Hint::~CAttr_ACT_Hint()
{
}

CString CAttr_ACT_Hint::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("taid"), m_taID );
	strData += PakingPageData( _T("type"), (int)m_ctrHintType.GetItemData( m_ctrHintType.GetCurSel() ) );
	strData += PakingPageData( _T("idx"), m_dwHintIdx );

	return strData;
}

void CAttr_ACT_Hint::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("taid") == strKey )
	{
		m_taID = atoi( strValue.GetBuffer() );
	}
	else if ( _T("type") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrHintType.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrHintType.GetItemData( i ) == nValue )
			{
				m_ctrHintType.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("idx") == strKey )
	{
		m_dwHintIdx = atoi( strValue.GetBuffer() );
	}
}

void CAttr_ACT_Hint::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TS_ACT_ATTR_HINT_ID_EDITOR, m_taID);
	DDV_MinMaxUInt(pDX, m_taID, 0, NTL_TS_TA_ID_INVALID);
	DDX_Control(pDX, IDC_TS_ACT_ATTR_HINT_HINT_TYPE_COMBO, m_ctrHintType);
	DDX_Text(pDX, IDC_TS_ACT_ATTR_HINT_HINT_IDX_EDITOR, m_dwHintIdx);
}

BOOL CAttr_ACT_Hint::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_ctrHintType.SetItemData( m_ctrHintType.AddString( _T("Guide") ), 1/*HINTICON_GUIDE*/ );
	m_ctrHintType.SetItemData( m_ctrHintType.AddString( _T("Help") ), 0/*HINTICON_HELP*/ );
	m_ctrHintType.SetCurSel( 0 );

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BEGIN_MESSAGE_MAP(CAttr_ACT_Hint, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_ACT_Hint �޽��� ó�����Դϴ�.
