// EffectListDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "EffectListDialog.h"
#include ".\effectlistdialog.h"


// CEffectListDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CEffectListDialog, CDialog)
CEffectListDialog::CEffectListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CEffectListDialog::IDD, pParent)
{
	m_Initialized = FALSE;
}

CEffectListDialog::~CEffectListDialog()
{
}

void CEffectListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RESOURCE_EFFECT_LIST, m_EffectFrame);
}


BEGIN_MESSAGE_MAP(CEffectListDialog, CDialog)
	ON_WM_SIZE()
	ON_WM_CREATE()    
    ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CEffectListDialog �޽��� ó�����Դϴ�.

BOOL CEffectListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_Initialized = TRUE;

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CEffectListDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_Initialized)
	{
		CRect rc;
		m_EffectFrame.GetWindowRect(rc);
		ScreenToClient(rc);
		m_EffectFrame.ShowWindow(SW_HIDE);
		if(m_List.GetSafeHwnd())
				m_List.MoveWindow(rc);
//		m_List.SetWindowPos(0,-1,-1,cx,cy,SWP_SHOWWINDOW);
	}
}

BOOL CEffectListDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN) 
	{
		if(pMsg->wParam == VK_RETURN) return FALSE;	
		if(pMsg->wParam == VK_ESCAPE) return FALSE;	
	}
	return CDialog::PreTranslateMessage(pMsg);
}


int CEffectListDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	m_List.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP, CRect(0,0,0,0),this,0x1001);	
	m_List.InitializeGrid();
//	m_List.SetExtendedStyle(0);
	m_List.ModifyStyleEx(0,WS_EX_CLIENTEDGE);

	return 0;
}


void CEffectListDialog::ResetTreeItemName(const RwChar* strName)
{
	m_List.ResetTreeItemName(strName);
}


//------------------------------------------------------------------
//	FuncName	: RebuildResourceEffect
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
void CEffectListDialog::RebuildResourceEffect()
{
	m_List.RebuildResourceEffect();
}

// ������ ����Ʈ ��Ʈ���� ������ Ʋ�� Ŭ�������� ȣ��ȴ�.
// ����Ʈ ��Ʈ�ѿ��� ������ ����Ʈ�� �����Ѵ�.
void CEffectListDialog::OnLButtonUp(UINT nFlags, CPoint point)
{
    int nSelect = m_List.GetSelectedItem();
    m_List.SetItemState(nSelect, LVIS_FOCUSED, LVIS_SELECTED);

    CDialog::OnLButtonUp(nFlags, point);
}

RwBool CEffectListDialog::SaveXMLTree( RwChar* szFileName ) 
{
    return m_List.SaveXMLTree(szFileName);
}