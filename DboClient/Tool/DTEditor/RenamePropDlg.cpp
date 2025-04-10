// RenamePropDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DTEditor.h"
#include "RenamePropDlg.h"


// RenamePropDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRenamePropDlg, CDialog)

CRenamePropDlg::CRenamePropDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRenamePropDlg::IDD, pParent)
{

}

CRenamePropDlg::~CRenamePropDlg()
{
}

void CRenamePropDlg::SetName(CString strName)
{
	m_strName = strName;
}

CString CRenamePropDlg::GetName(void)
{
	return m_strName;
}

void CRenamePropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RENAME, m_editRename);
}


BEGIN_MESSAGE_MAP(CRenamePropDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CRenamePropDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CRenamePropDlg �޽��� ó�����Դϴ�.

void CRenamePropDlg::OnBnClickedOk()
{
	GetDlgItemText(IDC_EDIT_RENAME, m_strName);

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}

BOOL CRenamePropDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	SetDlgItemText(IDC_EDIT_RENAME, m_strName);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
