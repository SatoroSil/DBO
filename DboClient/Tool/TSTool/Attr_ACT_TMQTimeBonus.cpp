// Attr_ACT_TMQTimeBonus.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_ACT_TMQTimeBonus.h"


// CAttr_ACT_TMQTimeBonus ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_ACT_TMQTimeBonus, CAttr_Page, 1)

CAttr_ACT_TMQTimeBonus::CAttr_ACT_TMQTimeBonus()
	: CAttr_Page(CAttr_ACT_TMQTimeBonus::IDD)
	, m_taID(NTL_TS_TA_ID_INVALID)
	, m_nBonusTime( 0 )
{

}

CAttr_ACT_TMQTimeBonus::~CAttr_ACT_TMQTimeBonus()
{
}

CString CAttr_ACT_TMQTimeBonus::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("taid"), m_taID );
	strData += PakingPageData( _T("bt"), m_nBonusTime );

	return strData;
}

void CAttr_ACT_TMQTimeBonus::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("taid") == strKey )
	{
		m_taID = atoi( strValue.GetBuffer() );
	}
	else if ( _T("bt") == strKey )
	{
		m_nBonusTime = atoi( strValue.GetBuffer() );
	}
}

void CAttr_ACT_TMQTimeBonus::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TS_ACT_ATTR_TMQTIMEBONUS_ID_EDITOR, m_taID);
	DDV_MinMaxUInt(pDX, m_taID, 0, NTL_TS_TA_ID_INVALID);

	DDX_Text(pDX, IDC_TS_ACT_ATTR_TIMEBONUS_TIME_EDITOR, m_nBonusTime);
}

BOOL CAttr_ACT_TMQTimeBonus::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_ACT_TMQTimeBonus, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_ACT_TMQTimeBonus �޽��� ó�����Դϴ�.
