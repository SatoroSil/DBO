// Attr_EVT_HoipoiMix.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_EVT_HoipoiMix.h"


// CAttr_EVT_HoipoiMix ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_EVT_HoipoiMix, CAttr_Page, 1)

CAttr_EVT_HoipoiMix::CAttr_EVT_HoipoiMix(CWnd* pParent /*=NULL*/)
	: CAttr_Page(CAttr_EVT_HoipoiMix::IDD)
{

}

CAttr_EVT_HoipoiMix::~CAttr_EVT_HoipoiMix()
{
}

CString CAttr_EVT_HoipoiMix::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	return strData;
}

void CAttr_EVT_HoipoiMix::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_EVT_HoipoiMix::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
}

BOOL CAttr_EVT_HoipoiMix::OnInitDialog()
{
	CAttr_Page::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_EVT_HoipoiMix, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_EVT_HoipoiMix �޽��� ó�����Դϴ�.
