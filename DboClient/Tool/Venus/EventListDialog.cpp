// EventListDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "EventListDialog.h"
#include ".\eventlistdialog.h"


// CEventListDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CEventListDialog, CDialog)
CEventListDialog::CEventListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CEventListDialog::IDD, pParent)
{
	m_Initialized = FALSE;
}

CEventListDialog::~CEventListDialog()
{
}

void CEventListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEventListDialog, CDialog)
	ON_WM_SIZE()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CEventListDialog �޽��� ó�����Դϴ�.

BOOL CEventListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_Initialized = TRUE;

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CEventListDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_Initialized)
	{
		CRect rc;
		GetDlgItem(IDC_EVENT_LIST)->GetWindowRect(rc);
		ScreenToClient(rc);
		GetDlgItem(IDC_EVENT_LIST)->ShowWindow(SW_HIDE);
		if(m_List.GetSafeHwnd())
				m_List.MoveWindow(rc);
	}
}

int CEventListDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	m_List.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP, CRect(0,0,0,0),this,0x1001);	
	m_List.InitializeGrid();
	m_List.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_List.ModifyStyleEx(0,WS_EX_CLIENTEDGE);

	return 0;
}
BOOL CEventListDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN) 
	{
		if(pMsg->wParam == VK_RETURN) return FALSE;	
		if(pMsg->wParam == VK_ESCAPE) return FALSE;	
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CEventListDialog::ResetTreeItemName(const RwChar* strName)
{
	m_List.ResetTreeItemName(strName);
}
