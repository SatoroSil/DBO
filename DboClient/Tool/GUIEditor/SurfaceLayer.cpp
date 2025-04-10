// SurfaceLayer.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "GUIEditor.h"
#include ".\surfacelayer.h"
#include ".\LayerMisc.h"

#include "FileViewDlg.h"
#include "SurfaceListDlg.h"
#include "SurfaceAttributeDlg.h"
#include "RectInfoDlg.h"


// CSurfaceLayer

IMPLEMENT_DYNCREATE(CSurfaceLayer, CView)

CSurfaceLayer::CSurfaceLayer()
{
	m_bInitialized = FALSE;
}

CSurfaceLayer::~CSurfaceLayer()
{
}

BEGIN_MESSAGE_MAP(CSurfaceLayer, CView)
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()


// CSurfaceLayer �׸����Դϴ�.

void CSurfaceLayer::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CSurfaceLayer �����Դϴ�.

#ifdef _DEBUG
void CSurfaceLayer::AssertValid() const
{
	CView::AssertValid();
}

void CSurfaceLayer::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG


// CSurfaceLayer �޽��� ó�����Դϴ�.

void CSurfaceLayer::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_RollUpCtrl.Create( WS_VISIBLE|WS_CHILD, CRect(0,1,190,400), this, IDD_ROLLUPPAGEID );

	//m_RollUpCtrl.InsertPage( "File View", IDD_FILEVIEWDLG, RUNTIME_CLASS( CFileViewDlg ) );
	m_RollUpCtrl.InsertPage( "Rect Info", IDD_RECTINFODLG, RUNTIME_CLASS( CRectInfoDlg ) );
	m_RollUpCtrl.InsertPage( "Surface List", IDD_SURFACELISTDLG, RUNTIME_CLASS( CSurfaceListDlg ) );
	m_RollUpCtrl.InsertPage( "Surface Attribute", IDD_SURFACEATTRIBUTEDLG, RUNTIME_CLASS( CSurfaceAttributeDlg ) );

	m_RollUpCtrl.ExpandAllPages();

	m_bInitialized = TRUE;		
}

void CSurfaceLayer::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	if( m_bInitialized )
		m_RollUpCtrl.MoveWindow( 0, 0, cx, cy );
}

void CSurfaceLayer::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//CLayerMisc::GetInstance().SetLayer( CLayerMisc::SURFACE_LAYER );
}

CDialog* CSurfaceLayer::GetRollupDlg( SURFACEDLG eID )
{
	CDialog*	 pDialog = NULL;
	RC_PAGEINFO* pginfo = m_RollUpCtrl.GetPageInfo( eID );
	if(pginfo && pginfo->pwndTemplate)
		pDialog = (CDialog*)pginfo->pwndTemplate;					

	return pDialog;
}
