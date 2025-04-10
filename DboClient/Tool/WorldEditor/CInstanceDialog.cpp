// AssetObjectDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "WorldEditor.h"
#include "CInstanceDialog.h"


// CAssetObjectDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC( CInstanceDialog, CDialog )


CInstanceDialog::CInstanceDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CInstanceDialog::IDD, pParent)
{
}

CInstanceDialog::~CInstanceDialog()
{
}

void CInstanceDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInstanceDialog, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CAssetObjectDlg �޽��� ó�����Դϴ�.

BOOL CInstanceDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	CRect FrameRect(0,0,100,100);

	m_TreeCtrl.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP | TVS_HASBUTTONS |	TVS_HASLINES |
					TVS_LINESATROOT | TVS_SHOWSELALWAYS | TVS_TRACKSELECT, FrameRect, this, 1006);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CInstanceDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	if( m_TreeCtrl.GetSafeHwnd())
		m_TreeCtrl.MoveWindow(0, 0, cx, cy);
}
