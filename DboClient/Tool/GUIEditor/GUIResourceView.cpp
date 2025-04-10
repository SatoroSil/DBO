// GUIResourceView.cpp : CGUIResourceView Ŭ������ ����
//

#include "stdafx.h"
#include "GUIEditor.h"

#include "GUIEditorDoc.h"
#include "GUIResourceView.h"
#include "GUIDebugView.h"
#include "GUIFileView.h"
#include ".\guiresourceview.h"

#include "LayerMisc.h"
#include "RectInfoDlg.h"
#include "SurfaceAttributeDlg.h"
#include "ResourceAttributeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CGUIResourceView* g_pResourceView = NULL;

// CGUIResourceView

IMPLEMENT_DYNCREATE(CGUIResourceView, CScrollView)

BEGIN_MESSAGE_MAP(CGUIResourceView, CScrollView)
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_CREATE()
	ON_WM_MOUSEWHEEL()
	ON_WM_TIMER()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CGUIResourceView ����/�Ҹ�

CGUIResourceView::CGUIResourceView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_ptRBtnDown = CPoint( 0, 0 );
	m_bInitialized = FALSE;
}

CGUIResourceView::~CGUIResourceView()
{
}

BOOL CGUIResourceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CGUIResourceView �׸���

void CGUIResourceView::OnDraw(CDC* pDC)
{
	CGUIEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	g_DevILImage.DrawMemDC( m_dcBuffer.GetMDC(), 0, 0 );
	m_selectBox.Erase();

	CRect src,dest;
	src  = m_CoordMgr.GetSrcRect();
	dest = m_CoordMgr.GetDestRect();
	
	::StretchBlt( pDC->GetSafeHdc(), dest.left, dest.top, dest.right, dest.bottom,
				  m_dcBuffer.GetHDC(), src.left, src.top, src.right, src.bottom, SRCCOPY );

	CSurfaceLayer* pView = (CSurfaceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::SURFACE_LAYER );
	CRectInfoDlg* pDlg = (CRectInfoDlg*)pView->GetRollupDlg( CSurfaceLayer::RECTINFODLG );
	//pDlg->SetSrcRect( src );
	//pDlg->SetOffset( m_CoordMgr.GetOffset() );
	pDlg->SetSelectedRect( CRect( m_selectBox.GetCurRect() ) );

	m_dcBuffer.FillColor();	// ���� �����.
}

void CGUIResourceView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);

	m_bInitialized = TRUE;
}


// CGUIResourceView ����

#ifdef _DEBUG
void CGUIResourceView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CGUIResourceView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CGUIEditorDoc* CGUIResourceView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGUIEditorDoc)));
	return (CGUIEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CGUIResourceView �޽��� ó����


void CGUIResourceView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if( nFlags & MK_RBUTTON )
	{
		
		return;
	}

	CPoint fixpoint;
	fixpoint = m_CoordMgr.FixMousePt( point );

	m_selectBox.BoxBegin( fixpoint );
	m_selectBox.Draw( fixpoint );

	// ���� ������ġ�� �̵�
	SetTimer( 0, 40, NULL );

	Invalidate( FALSE );

	CScrollView::OnLButtonDown(nFlags, point);
}

void CGUIResourceView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if( m_dcBuffer.GetMDC() )
		m_dcBuffer.Delete();

	m_CoordMgr.SetClientRect( cx, cy );
	ResizeBuffer();
    
	//if( m_bInitialized )
	//{
	//	CSurfaceLayer* pView = (CSurfaceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::SURFACE_LAYER );
	//	CRectInfoDlg* pDlg = (CRectInfoDlg*)pView->GetRollupDlg( CSurfaceLayer::RECTINFODLG );
	//	pDlg->SetClientRect( CRect( 0, 0, cx, cy ) );
	//}
}

void CGUIResourceView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if( nFlags == MK_LBUTTON )
	{
		CPoint fixpoint;
		fixpoint = m_CoordMgr.FixMousePt( point );

		if( fixpoint.x > m_selectBox.GetCurRect().left )
            fixpoint.x += 1;
		if( fixpoint.y > m_selectBox.GetCurRect().top )
			fixpoint.y += 1;
		m_selectBox.Draw( fixpoint );

		Invalidate( FALSE );
	}
	else if( nFlags == MK_RBUTTON && m_CoordMgr.IsScrollNeed() )
	{
		CPoint ptDiff( 0, 0 );
		ptDiff.x = (INT)( ( m_ptRBtnDown.x - point.x ) / m_CoordMgr.GetFixXScaleFactor() * 2 );
		ptDiff.y = (INT)( ( m_ptRBtnDown.y - point.y ) / m_CoordMgr.GetFixYScaleFactor() * 2 );

		m_ptRBtnDown = point;

		m_CoordMgr.MoveOffset( ptDiff );

		Invalidate( FALSE );
	}

	CSurfaceLayer* pView = (CSurfaceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::SURFACE_LAYER );
	CRectInfoDlg* pDlg = (CRectInfoDlg*)pView->GetRollupDlg( CSurfaceLayer::RECTINFODLG );
	pDlg->SetMousePoint( m_CoordMgr.FixMousePt( point ) );
	//pDlg->SetOriMousePoint( point );
	    
	CScrollView::OnMouseMove(nFlags, point);
}

void CGUIResourceView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_selectBox.BoxEnd();
	KillTimer( 0 );

	// �Ӽ�â�� ���ùڽ� ���� ���.
	UpdateRectInfo();

	// Debug View�� ���ÿ��� ����
	//ShowSelected();

	// �̸� ����.
	CSurfaceLayer* pLayer = (CSurfaceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::SURFACE_LAYER );
	CSurfaceAttributeDlg* pDlg = (CSurfaceAttributeDlg*)pLayer->GetRollupDlg( CSurfaceLayer::SURFACEATTRIBUTEDLG );
	pDlg->SetName( CString( "" ) );

	CLayerMisc::GetInstance().SetLayer( CLayerMisc::SURFACE_LAYER );

	CScrollView::OnLButtonUp(nFlags, point);
}

int CGUIResourceView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_selectBox.Create( GetSafeHwnd(), FALSE );	
	m_CoordMgr.Create( this, 20 );

	return 0;
}

BOOL CGUIResourceView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_CoordMgr.SetMouseDelta( -zDelta );
	Invalidate( TRUE );	

	m_CoordMgr.SetPtToCenter( pt );
	
    return CScrollView::OnMouseWheel(nFlags, zDelta, pt);
}

BOOL CGUIResourceView::LoadImage( CString& strFullPath, CString& strFileName )
{
	BOOL bResult = TRUE;

	if( !g_DevILImage.Load( this, strFullPath ) )
		bResult = FALSE;

	m_selectBox.ClearRects();
	//m_CoordMgr.Reset();
	m_CoordMgr.SetImageRect( CRect( 0, 0, g_DevILImage.GetWidth(), g_DevILImage.GetHeight() ) );

	//�Ӽ�â�� �����̸� ���.
	CResourceLayer* pLayer = (CResourceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::RESOURCE_LAYER );
	CResourceAttributeDlg* pDlg = (CResourceAttributeDlg*)pLayer->GetRollupDlg( CResourceLayer::RESOURCEATTRIBUTEDLG );
	pDlg->SetBlank();
	
	if( bResult )
		pDlg->SetFileName( strFileName );

	UpdateRsrInfo( strFileName );
			
    ResizeBuffer();	

	Invalidate( FALSE );

	return bResult;
}

void CGUIResourceView::OnTimer(UINT nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if( nIDEvent == 0 )
	{
		CPoint point;
		GetCursorPos(&point);
		ScreenToClient( &point );
		CCoordManager::MARGINRECT eRect = m_CoordMgr.PtInMargin( point );
		m_CoordMgr.MarginMove( eRect );	
		if( eRect != CCoordManager::CENTER ) 
			Invalidate( FALSE );
	}

	CScrollView::OnTimer(nIDEvent);
}

void CGUIResourceView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	ReleaseCapture();
	m_ptRBtnDown = CPoint( 0, 0 );
	
	CScrollView::OnRButtonUp(nFlags, point);
}

void CGUIResourceView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if( nFlags & MK_LBUTTON )
		return;

	SetCapture();
	m_ptRBtnDown = point;

	CScrollView::OnRButtonDown(nFlags, point);
}

void CGUIResourceView::OnDestroy()
{
	CScrollView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

void CGUIResourceView::ResizeBuffer()
{
	if( m_dcBuffer.GetMDC() )
		m_dcBuffer.Delete();

	INT	cx, cy;
		
	if( g_DevILImage.GetWidth() > m_CoordMgr.GetViewRect().Width() )
		cx = g_DevILImage.GetWidth();
	else
		cx = m_CoordMgr.GetViewRect().Width();

	if( g_DevILImage.GetHeight() > m_CoordMgr.GetViewRect().Height() )
		cy = g_DevILImage.GetHeight();
	else
		cy = m_CoordMgr.GetViewRect().Height();

    m_dcBuffer.Create( this, cx, cy );

	// ���ùڽ� ������ ����.
	m_selectBox.SetDC( m_dcBuffer.GetMDC() );
	m_selectBox.UpdateClientSize( g_DevILImage.GetWidth(), g_DevILImage.GetHeight() );
}

void CGUIResourceView::SetSelectBox( CRect rcRect )
{
	CPoint	pt;

	pt.x = rcRect.left;
	pt.y = rcRect.top;

	m_selectBox.BoxBegin( pt );

	pt.x = rcRect.right;
	pt.y = rcRect.bottom;

	m_selectBox.Draw( pt );
	m_selectBox.BoxEnd();

	UpdateRectInfo();
}

void CGUIResourceView::UpdateRectInfo()
{
	CSurfaceLayer* pLayer = (CSurfaceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::SURFACE_LAYER );
	CSurfaceAttributeDlg* pDlg = (CSurfaceAttributeDlg*)pLayer->GetRollupDlg( CSurfaceLayer::SURFACEATTRIBUTEDLG );

	CRect rcBox( m_selectBox.GetCurRect() );
	pDlg->SetRect( rcBox );
	pDlg->SetUV( rcBox );
	
	Invalidate( FALSE );
}

void CGUIResourceView::ShowSelected()
{
	CRect	rcSelect = m_selectBox.GetCurRect();
	CSize	sizeRect;

	sizeRect.cx = rcSelect.Width();
	sizeRect.cy = rcSelect.Height();

	g_pDebugView->SetScrollSizes( MM_TEXT, sizeRect );
	g_pDebugView->Invalidate( TRUE );
}

void CGUIResourceView::UpdateRsrInfo( CString& strFilename )
{
	RESOURCEDATA* pData = g_pDocument->GetDataManager().GetResourceDataFromFilename( strFilename );

	CSurfaceLayer* pLayer = (CSurfaceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::SURFACE_LAYER );
	CSurfaceAttributeDlg* pDlg = (CSurfaceAttributeDlg*)pLayer->GetRollupDlg( CSurfaceLayer::SURFACEATTRIBUTEDLG );

	if( !pData )
	{
		pDlg->SetResourceInfo( CString( "" ), CString( "" ) );
		return;
	}

	pDlg->SetResourceInfo( pData->_strName, g_pDocument->GetDataManager().GetRsrFileName() );	
}
void CGUIResourceView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if( nChar == '1' )
	{
		g_DevILImage.SetShowAlpha( !g_DevILImage.GetShowAlpha() );
		Invalidate( FALSE );
	}

	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}
