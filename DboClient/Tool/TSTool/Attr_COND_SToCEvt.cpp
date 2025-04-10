// Attr_COND_SToCEvt.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_COND_SToCEvt.h"


// CAttr_COND_SToCEvt ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_COND_SToCEvt, CAttr_Page, 1)

CAttr_COND_SToCEvt::CAttr_COND_SToCEvt()
	: CAttr_Page(CAttr_COND_SToCEvt::IDD)
{

}

CAttr_COND_SToCEvt::~CAttr_COND_SToCEvt()
{
}

CString CAttr_COND_SToCEvt::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("itype"), (int)m_ctrSvrEvtType.GetItemData( m_ctrSvrEvtType.GetCurSel() ) );

	return strData;
}

void CAttr_COND_SToCEvt::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("itype") == strKey )
	{
		int nValue = atoi( strValue.GetBuffer() );

		int nCnt = m_ctrSvrEvtType.GetCount();
		for ( int i = 0; i < nCnt; ++i )
		{
			if ( m_ctrSvrEvtType.GetItemData( i ) == nValue )
			{
				m_ctrSvrEvtType.SetCurSel( i );
				break;
			}
		}
	}
}

void CAttr_COND_SToCEvt::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TS_COND_ATTR_STOCEVT_EVTTYPE_COMBO, m_ctrSvrEvtType);
}

BOOL CAttr_COND_SToCEvt::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	int nIdx = m_ctrSvrEvtType.AddString( _T("Invalid") );
	m_ctrSvrEvtType.SetItemData(  nIdx, eSTOC_EVT_DATA_TYPE_INVALID );
	m_ctrSvrEvtType.SetItemData( m_ctrSvrEvtType.AddString( _T("Mob kill") ), eSTOC_EVT_DATA_TYPE_MOB_KILL_CNT );
	m_ctrSvrEvtType.SetItemData( m_ctrSvrEvtType.AddString( _T("Mob item") ), eSTOC_EVT_DATA_TYPE_MOB_KILL_ITEM_CNT );
	m_ctrSvrEvtType.SetItemData( m_ctrSvrEvtType.AddString( _T("Item delivery") ), eSTOC_EVT_DATA_TYPE_DELIVERY_ITEM );
	m_ctrSvrEvtType.SetItemData( m_ctrSvrEvtType.AddString( _T("Object item") ), eSTOC_EVT_DATA_TYPE_OBJECT_ITEM );
	m_ctrSvrEvtType.SetItemData( m_ctrSvrEvtType.AddString( _T("Public item") ), eSTOC_EVT_DATA_TYPE_PUBLIC_MOB_ITEM_CNT );
	m_ctrSvrEvtType.SetItemData( m_ctrSvrEvtType.AddString( _T("Custom event") ), eSTOC_EVT_DATA_TYPE_CUSTOM_EVT_CNT );
	m_ctrSvrEvtType.SetItemData( m_ctrSvrEvtType.AddString( _T("Visit") ), eSTOC_EVT_DATA_TYPE_VISIT );
	m_ctrSvrEvtType.SetCurSel( nIdx );

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_COND_SToCEvt, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_COND_SToCEvt �޽��� ó�����Դϴ�.
