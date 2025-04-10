// StringDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "StringDialog.h"
#include ".\stringdialog.h"

#include "StringManager.h"


// CStringDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CStringDialog, CDialog)
CStringDialog::CStringDialog(LPCTSTR strTitle, LPCTSTR strEdit, CWnd* pParent /*=NULL*/)
	: CDialog(CStringDialog::IDD, pParent)
	, m_strName(_T(""))
{
	m_strTitle = strTitle;
	m_strEdit = strEdit;
}

CStringDialog::~CStringDialog()
{
}

void CStringDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STRING, m_strName);
}


BEGIN_MESSAGE_MAP(CStringDialog, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CStringDialog �޽��� ó�����Դϴ�.

BOOL CStringDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetWindowText(m_strTitle.c_str());

	m_strName = m_strEdit.c_str();
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CStringDialog::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if (m_strName.IsEmpty())
	{
		AfxMessageBox(CStringManager::GetInstance().GetString(STRING_NAME_EMPTY), MB_OK);
		return;
	}
	OnOK();
}
