// PathLayer.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "VenusFrame.h"
#include "PathLayer.h"
#include ".\pathlayer.h"

#include "SplinePathListDialog.h"
#include "SplinePathPropertyDialog.h"

// CPathLayer

IMPLEMENT_DYNCREATE(CPathLayer, CView)

CPathLayer::CPathLayer()
{
	m_bInitialized	= FALSE;
}

CPathLayer::~CPathLayer()
{
}

BEGIN_MESSAGE_MAP(CPathLayer, CView)
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()


// CPathLayer �׸����Դϴ�.

void CPathLayer::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CPathLayer �����Դϴ�.

#ifdef _DEBUG
void CPathLayer::AssertValid() const
{
	CView::AssertValid();
}

void CPathLayer::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG


// CPathLayer �޽��� ó�����Դϴ�.

void CPathLayer::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_RollupControl.Create(WS_VISIBLE|WS_CHILD, CRect(0,1,190,400), this, IDD_ROLLUPPAGEID);

	m_RollupControl.InsertPage("Spline Path List",			IDD_SPLINE_PATH_LIST,		RUNTIME_CLASS(CSplinePathListDialog));	
	m_RollupControl.InsertPage("Spline Path List",			IDD_SPLINE_PATH_PROPERTY,	RUNTIME_CLASS(CSplinePathPropertyDialog));	

	m_RollupControl.ExpandAllPages();

	m_bInitialized = TRUE;			
}

void CPathLayer::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if(m_bInitialized)
	{
		m_RollupControl.MoveWindow(0, 0, cx, cy);
	}
}

void CPathLayer::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	gSetEditLayer(EDIT_LAYER_PATH);
}


void CPathLayer::RebuildSplinePath()
{
	RC_PAGEINFO* pginfo = m_RollupControl.GetPageInfo(EDIT_DIALOG_SPLINE_PATH_LIST);
	if(pginfo && pginfo->pwndTemplate)
	{
		CSplinePathListDialog* pDialog = (CSplinePathListDialog*)pginfo->pwndTemplate;					
		pDialog->RebuildSplinePath();
	}
}

void CPathLayer::ResetTreeItemName(const RwChar* strName)
{
	RC_PAGEINFO* pginfo = m_RollupControl.GetPageInfo(EDIT_DIALOG_SPLINE_PATH_LIST);
	if(pginfo && pginfo->pwndTemplate)
	{
		CSplinePathListDialog* pDialog = (CSplinePathListDialog*)pginfo->pwndTemplate;					
		pDialog->ResetTreeItemName(strName);
	}
}

void CPathLayer::ResetProperties()
{
	RC_PAGEINFO* pginfo = m_RollupControl.GetPageInfo(EDIT_DIALOG_PROPERTY);
	if(pginfo && pginfo->pwndTemplate)
	{
		CSplinePathPropertyDialog* pDialog = (CSplinePathPropertyDialog*)pginfo->pwndTemplate;					
		pDialog->ResetProperties();
	}
}
