// Attr_COND_BudokaiState.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_COND_BudokaiState.h"
#include "NtlBudokai.h"


// CAttr_COND_BudokaiState ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_COND_BudokaiState, CAttr_Page, 1)

CAttr_COND_BudokaiState::CAttr_COND_BudokaiState()
	: CAttr_Page(CAttr_COND_BudokaiState::IDD)
{

}

CAttr_COND_BudokaiState::~CAttr_COND_BudokaiState()
{
}

CString CAttr_COND_BudokaiState::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("st"), (int)m_ctrState.GetItemData( m_ctrState.GetCurSel() ) );
	strData += PakingPageData( _T("md"), (int)m_ctrMode.GetItemData( m_ctrMode.GetCurSel() ) );

	return strData;
}

void CAttr_COND_BudokaiState::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("st") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrState.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrState.GetItemData( i ) == nValue )
			{
				m_ctrState.SetCurSel( i );
				break;
			}
		}
	}
	else if ( _T("md") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrMode.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrMode.GetItemData( i ) == nValue )
			{
				m_ctrMode.SetCurSel( i );
				break;
			}
		}
	}
}

void CAttr_COND_BudokaiState::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TS_COND_ATTR_MAIN_STATE_COMBO, m_ctrState);
	DDX_Control(pDX, IDC_TS_COND_ATTR_MODE_COMBO, m_ctrMode);
}


BOOL CAttr_COND_BudokaiState::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	int nIdx;

	m_ctrState.SetItemData( m_ctrState.AddString( _T("õ������ ����ȸ ����") ), eTS_BUDOKAI_STATE_CLOSE );
	nIdx = m_ctrState.AddString( _T("õ������ ����ȸ ����") );
	m_ctrState.SetItemData( nIdx, eTS_BUDOKAI_STATE_OPEN );
	m_ctrState.SetCurSel( nIdx );

	m_ctrMode.SetItemData( m_ctrMode.AddString( _T("����") ), eTS_BUDOKAI_MODE_ADULT );
	m_ctrMode.SetItemData( m_ctrMode.AddString( _T("û�ҳ�") ), eTS_BUDOKAI_MODE_CHILD );
	nIdx = m_ctrMode.AddString( _T("���") );
	m_ctrMode.SetItemData( nIdx, eTS_BUDOKAI_MODE_ALL );
	m_ctrMode.SetCurSel( nIdx );

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_COND_BudokaiState, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_COND_BudokaiState �޽��� ó�����Դϴ�.
