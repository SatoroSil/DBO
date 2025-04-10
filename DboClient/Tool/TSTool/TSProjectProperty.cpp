// TSProjectProperty.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "TSProjectProperty.h"
#include "TSToolDefine.h"
#include "DirDialog.h"


// CTSProjectProperty ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTSProjectProperty, CDialog)

CTSProjectProperty::CTSProjectProperty(CWnd* pParent /*=NULL*/)
	: CDialog(CTSProjectProperty::IDD, pParent)
	, m_strProjPath(_T(""))
	, m_strProjName(_T(""))
{

}

CTSProjectProperty::~CTSProjectProperty()
{
}

void CTSProjectProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_strProjPath);
	DDX_Text(pDX, IDC_EDIT1, m_strProjName);
	DDX_Control(pDX, IDC_COMBO1, m_ctrTSMode);
}

void CTSProjectProperty::OnOK()
{
	m_dwMode = (DWORD)m_ctrTSMode.GetItemData( m_ctrTSMode.GetCurSel() );

	CDialog::OnOK();
}

BEGIN_MESSAGE_MAP(CTSProjectProperty, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CTSProjectProperty::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTSProjectProperty �޽��� ó�����Դϴ�.

BOOL CTSProjectProperty::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	int nIdx = m_ctrTSMode.AddString( _T("Quest CS") );
	m_ctrTSMode.SetItemData( nIdx, TS_TYPE_QUEST_CS );
	m_ctrTSMode.SetItemData( m_ctrTSMode.AddString( _T("Trigger CS") ), TS_TYPE_PC_TRIGGER_CS );
	m_ctrTSMode.SetItemData( m_ctrTSMode.AddString( _T("Object S") ), TS_TYPE_OBJECT_TRIGGER_S );
	m_ctrTSMode.SetCurSel( nIdx );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CTSProjectProperty::OnBnClickedButton1()
{
	CDirDialog clDir( NULL, NULL, this );
	clDir.m_ofn.lpstrTitle = _T("Trigger system project path");

	if ( IDOK == clDir.DoModal() )
	{
		CString strPath = clDir.GetPath();

		m_strProjPath = strPath;

		UpdateData( FALSE );
	}
}

