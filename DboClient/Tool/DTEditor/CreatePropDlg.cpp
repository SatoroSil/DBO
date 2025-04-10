// CreatePropDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DTEditor.h"

// simulation
#include "NtlSLTBCrowdManager.h"

// DTEdit
#include "CreatePropDlg.h"


// CCreatePropDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCreatePropDlg, CDialog)

CCreatePropDlg::CCreatePropDlg(CWnd* pParent /*=NULL*/)
: CDialog(CCreatePropDlg::IDD, pParent)
,m_nCreateType(INVALID_CREATE_TYPE)
,m_nIndex(0)
{
}

CCreatePropDlg::~CCreatePropDlg()
{
}

void CCreatePropDlg::SetCreateType(eCreateType byType)
{
	m_nCreateType = byType;	
}

int CCreatePropDlg::GetSelectedIndex(void) const
{
	return m_nIndex;
}

CString CCreatePropDlg::GetSelectedString()
{
	return m_strString;
}

void CCreatePropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADD_PROP_LIST, m_PropList);
}


BEGIN_MESSAGE_MAP(CCreatePropDlg, CDialog)
	ON_WM_SHOWWINDOW()
	ON_LBN_SELCHANGE(IDC_ADD_PROP_LIST, &CCreatePropDlg::OnLbnSelchangeAddPropList)
END_MESSAGE_MAP()


// CCreatePropDlg �޽��� ó�����Դϴ�.

BOOL CCreatePropDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	switch( m_nCreateType )
	{
	case CREATE_SPLINE:
		{
			m_PropList.AddString( _T("Line") );
			m_PropList.AddString( _T("Circle") );
			m_PropList.AddString( _T("Hurricane") );

			SetWindowText(_T("Add Property") );
			break;
		}
	case CREATE_DIRECTION_NODE:
		{
			CString strName;

			strName.LoadString(IDS_STRING_EFFECT);
			m_PropList.AddString( strName );

			strName.LoadString(IDS_STRING_SOUND);
			m_PropList.AddString( strName );

			strName.LoadString(IDS_STRING_REFREE);
			m_PropList.AddString( strName );

			SetWindowText(_T("DT Node Name") );
			break;
		}
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CCreatePropDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	if(bShow)
	{
		m_nIndex = 0;
		m_PropList.SetCurSel(0);
	}
	else
	{
		m_nCreateType = INVALID_CREATE_TYPE;
	}
}

void CCreatePropDlg::OnLbnSelchangeAddPropList()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	m_nIndex = m_PropList.GetCurSel();	

	m_PropList.GetText(m_nIndex, m_strString);
}
