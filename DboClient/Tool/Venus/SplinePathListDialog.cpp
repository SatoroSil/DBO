// SplinePathListDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "SplinePathListDialog.h"
#include ".\splinepathlistdialog.h"


// CSplinePathListDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CSplinePathListDialog, CDialog)
CSplinePathListDialog::CSplinePathListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSplinePathListDialog::IDD, pParent)
{
	m_Initialized = FALSE;
}

CSplinePathListDialog::~CSplinePathListDialog()
{
}

void CSplinePathListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPLINE_PATH_LIST, m_SplinePathFrame);
}


BEGIN_MESSAGE_MAP(CSplinePathListDialog, CDialog)
	ON_WM_SIZE()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CSplinePathListDialog �޽��� ó�����Դϴ�.

BOOL CSplinePathListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_Initialized = TRUE;

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CSplinePathListDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_Initialized)
	{
		CRect rc;
		m_SplinePathFrame.GetWindowRect(rc);
		ScreenToClient(rc);
		m_SplinePathFrame.ShowWindow(SW_HIDE);
		if(m_List.GetSafeHwnd())
				m_List.MoveWindow(rc);
	}
}

int CSplinePathListDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
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


BOOL CSplinePathListDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN) 
	{
		if(pMsg->wParam == VK_RETURN) return FALSE;	
		if(pMsg->wParam == VK_ESCAPE) return FALSE;	
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CSplinePathListDialog::RebuildSplinePath()
{
	m_List.RebuildSplinePath();
}

void CSplinePathListDialog::ResetTreeItemName(const RwChar* strName)
{
	m_List.ResetTreeItemName(strName);
}
