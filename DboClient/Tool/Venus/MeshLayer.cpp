// MeshLayer.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "VenusFrame.h"
#include "MeshLayer.h"
#include ".\meshlayer.h"

#include "MeshListDialog.h"
#include "AnimationListDialog.h"
#include "UvAniListDialog.h"

// CMeshLayer

IMPLEMENT_DYNCREATE(CMeshLayer, CView)

CMeshLayer::CMeshLayer()
{
	m_bInitialized	= FALSE;
}

CMeshLayer::~CMeshLayer()
{
}

BEGIN_MESSAGE_MAP(CMeshLayer, CView)
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()


// CMeshLayer �׸����Դϴ�.

void CMeshLayer::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CMeshLayer �����Դϴ�.

#ifdef _DEBUG
void CMeshLayer::AssertValid() const
{
	CView::AssertValid();
}

void CMeshLayer::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG


// CMeshLayer �޽��� ó�����Դϴ�.

void CMeshLayer::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_RollupControl.Create(WS_VISIBLE|WS_CHILD, CRect(0,1,190,400), this, IDD_ROLLUPPAGEID);

	m_RollupControl.InsertPage("Mesh List",			IDD_MESH_LIST,		RUNTIME_CLASS(CMeshListDialog));	
	m_RollupControl.InsertPage("Animation List",	IDD_ANIMATION_LIST,	RUNTIME_CLASS(CAnimationListDialog));	
	m_RollupControl.InsertPage("UV Animation List",	IDD_UVANI_LIST,		RUNTIME_CLASS(CUvAniListDialog));	

	m_RollupControl.ExpandAllPages();

	m_bInitialized = TRUE;			
}

void CMeshLayer::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if(m_bInitialized)
	{
		m_RollupControl.MoveWindow(0, 0, cx, cy);
	}
}

void CMeshLayer::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	gSetEditLayer(EDIT_LAYER_MESH);
}

void CMeshLayer::InitializeList()
{
	RC_PAGEINFO* pginfo = m_RollupControl.GetPageInfo(EDIT_DIALOG_MESH_LIST);
	if(pginfo && pginfo->pwndTemplate)
	{
		CMeshListDialog* pDialog = (CMeshListDialog*)pginfo->pwndTemplate;					
		pDialog->SerializeList();
	}

	pginfo = m_RollupControl.GetPageInfo(EDIT_DIALOG_ANIMATION_LIST);
	if(pginfo && pginfo->pwndTemplate)
	{
		CAnimationListDialog* pDialog = (CAnimationListDialog*)pginfo->pwndTemplate;					
		pDialog->SerializeList();
	}

	pginfo = m_RollupControl.GetPageInfo(EDIT_DIALOG_UV_ANIMATION_LIST);
	if(pginfo && pginfo->pwndTemplate)
	{
		CUvAniListDialog* pDialog = (CUvAniListDialog*)pginfo->pwndTemplate;					
		pDialog->SerializeList();
	}
}
