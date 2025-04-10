// AttrRenameDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "2DParticleEditor.h"
#include "AttrRenameDlg.h"


// CAttrRenameDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAttrRenameDlg, CDialog)

CAttrRenameDlg::CAttrRenameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAttrRenameDlg::IDD, pParent)
	, m_strRename(_T(""))
{

}

CAttrRenameDlg::~CAttrRenameDlg()
{
}

void CAttrRenameDlg::SetPrePosition( LPRECT rect )
{
	m_rect = (*rect);
}

void CAttrRenameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_ATTR_RENAME, m_strRename);
	DDV_MaxChars(pDX, m_strRename, 32);
}


BEGIN_MESSAGE_MAP(CAttrRenameDlg, CDialog)
END_MESSAGE_MAP()

// CAttrRenameDlg �޽��� ó�����Դϴ�.

BOOL CAttrRenameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetWindowPos( &wndTop, m_rect.left, m_rect.top, m_rect.Width(), m_rect.Height(), 0 );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
