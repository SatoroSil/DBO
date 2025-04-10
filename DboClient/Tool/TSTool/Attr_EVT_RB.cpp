// Attr_EVT_RB.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_RB.h"


// CAttr_EVT_RB ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_RB, CAttr_Page, 1)

CAttr_EVT_RB::CAttr_EVT_RB(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_RB::IDD)
	, m_dwRBTblIdx(0xffffffff)
{

}

CAttr_EVT_RB::~CAttr_EVT_RB()
{
}

CString CAttr_EVT_RB::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("idx"), m_dwRBTblIdx );

	DWORD m_dwRBCondition = eRB_COND_FLAG_INVALID;
	if ( m_ctrPrivateEnter.GetCheck() == BST_CHECKED ) m_dwRBCondition |= eRB_COND_FLAG_PRIVATE_ENTER;
	if ( m_ctrPrivateWin.GetCheck() == BST_CHECKED ) m_dwRBCondition |= eRB_COND_FLAG_PRIVATE_WIN;
	if ( m_ctrPartyEnter.GetCheck() == BST_CHECKED ) m_dwRBCondition |= eRB_COND_FLAG_PARTY_ENTER;
	if ( m_ctrPartyWin.GetCheck() == BST_CHECKED ) m_dwRBCondition |= eRB_COND_FLAG_PARTY_WIN;

	strData += PakingPageData( _T("cond"), m_dwRBCondition );

	return strData;
}

void CAttr_EVT_RB::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("idx") == strKey )
	{
		m_dwRBTblIdx = atoi( strValue.GetBuffer() );
	}

	if ( _T("cond") == strKey )
	{
		DWORD dwRBCondition = atoi( strValue.GetBuffer() );

		if ( dwRBCondition & eRB_COND_FLAG_PRIVATE_ENTER ) m_ctrPrivateEnter.SetCheck( BST_CHECKED );
		if ( dwRBCondition & eRB_COND_FLAG_PRIVATE_WIN ) m_ctrPrivateWin.SetCheck( BST_CHECKED );
		if ( dwRBCondition & eRB_COND_FLAG_PARTY_ENTER ) m_ctrPartyEnter.SetCheck( BST_CHECKED );
		if ( dwRBCondition & eRB_COND_FLAG_PARTY_WIN ) m_ctrPartyWin.SetCheck( BST_CHECKED );
	}
}

void CAttr_EVT_RB::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TS_EVT_ATTR_RB_TBL_IDX_EDITOR, m_dwRBTblIdx);

	DDX_Control(pDX, IDC_TS_EVT_ATTR_RB_PRIVATE_ENTER_CHECK, m_ctrPrivateEnter );
	DDX_Control(pDX, IDC_TS_EVT_ATTR_RB_PRIVATE_WIN_CHECK, m_ctrPrivateWin );
	DDX_Control(pDX, IDC_TS_EVT_ATTR_RB_PARTY_ENTER_CHECK, m_ctrPartyEnter );
	DDX_Control(pDX, IDC_TS_EVT_ATTR_RB_PARTY_WIN_CHECK, m_ctrPartyWin );
}

BOOL CAttr_EVT_RB::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_RB, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_RB �޽��� ó�����Դϴ�.
