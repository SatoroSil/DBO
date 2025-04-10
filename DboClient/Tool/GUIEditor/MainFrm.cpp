// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "GUIEditor.h"
#include "GUIEditorDoc.h"

#include "MainFrm.h"
#include ".\mainfrm.h"

#include "GUIResourceView.h"
#include "GUIDebugView.h"
#include "GUIFileInfoView.h"

#include "GUIFileView.h"
#include "ResourceLayer.h"
#include "SurfaceLayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	m_bSplit = FALSE;
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("m_wndToolBar.CreateEx = fail \n");
		return -1;      // ������ ���߽��ϴ�.
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("m_wndStatusBar.Create = fail\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	
	ShowWindow( SW_SHOWMAXIMIZED );

	// ��üȭ �� �� ������ ����.
	ResizeSplitWnd();

	InitCtrlBar();

	return 0;
}

void CMainFrame::InitCtrlBar()
{
	CSize maptoolbarsize;

	maptoolbarsize.cx = 300;
	HDC pDC = ::GetDC( NULL );

	maptoolbarsize.cy = GetDeviceCaps( pDC, VERTRES) - 350;
	::ReleaseDC( NULL, pDC );

	m_wndLayerBar.Create( this, maptoolbarsize , IDW_PROP_BAR );	
	m_wndLayerBar.ShowWindow( SW_HIDE );			

	m_wndLayerBar.SetBarStyle( m_wndLayerBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC );
	m_wndLayerBar.AddView( "ResourceLayer", RUNTIME_CLASS( CResourceLayer ) );
	m_wndLayerBar.AddView( "SurfaceLayer", RUNTIME_CLASS( CSurfaceLayer ) );

	// Add map toolbar palette...
	m_wndLayerBar.EnableDocking( CBRS_ALIGN_RIGHT | CBRS_ALIGN_LEFT ); //| CBRS_ALIGN_TOP | CBRS_ALIGN_BOTTOM );		
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}


// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame �޽��� ó����


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	//return CFrameWnd::OnCreateClient(lpcs, pContext);

	m_wndSplit1.CreateStatic( this, 2, 1, WS_CHILD | WS_VISIBLE, AFX_IDW_PANE_FIRST );
	m_wndSplit2.CreateStatic( &m_wndSplit1, 1, 2, WS_CHILD | WS_VISIBLE, m_wndSplit1.IdFromRowCol( 1, 0 ) );
		
	m_wndSplit1.CreateView( 0, 0, RUNTIME_CLASS( CGUIResourceView ),
		CSize( 10, 10 ), pContext );
	/*m_wndSplit2.CreateView( 0, 0, RUNTIME_CLASS( CGUIDebugView ),
		CSize( 10, 10 ), pContext );*/
	m_wndSplit2.CreateView( 0, 0, RUNTIME_CLASS( CGUIFileInfoView ),
		CSize( 10, 10 ), pContext );
	m_wndSplit2.CreateView( 0, 1, RUNTIME_CLASS( CGUIFileView ),
		CSize( 10, 10 ), pContext );
	
	g_pResourceView	= (CGUIResourceView*)m_wndSplit1.GetPane( 0, 0 );	
	//g_pDebugView	= (CGUIDebugView*)m_wndSplit2.GetPane( 0, 0 );
	g_pFileInfoView	= (CGUIFileInfoView*)m_wndSplit2.GetPane( 0, 0 );
	g_pFileView		= (CGUIFileView*)m_wndSplit2.GetPane( 0, 1 );

	// Config Load
	g_pDocument->GetDataManager().LoadConfig();
			
	// Split �Ϸ�
	m_bSplit = TRUE;

	return TRUE;
}

void CMainFrame::ResizeSplitWnd()
{
	CRect	rect;
	GetClientRect( &rect );

	INT		nRow1Height = ( rect.Height() / 4 ) * 3;
	INT		nCol1Width = ( rect.Width() / 2 );

	m_wndSplit1.SetRowInfo( 0, nRow1Height, 10 );
	m_wndSplit2.SetColumnInfo( 0, nCol1Width, 10 );

	m_wndSplit1.RecalcLayout();
	m_wndSplit2.RecalcLayout();
}

void CMainFrame::ActivateFrame(int nCmdShow)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	static BOOL bFirsttime = TRUE;
	
	if(bFirsttime)
	{
		bFirsttime = FALSE;

		RECT viewwndRect;
		GetActiveView()->GetWindowRect(&viewwndRect);

		SIZE maptoolbarsize;
		maptoolbarsize.cx = 300;
		maptoolbarsize.cy = viewwndRect.bottom - viewwndRect.top - 114;

		m_wndLayerBar.SetFloatingSize( maptoolbarsize );
		DockControlBar(&m_wndLayerBar, AFX_IDW_DOCKBAR_RIGHT);		
		m_wndLayerBar.ShowWindow(SW_NORMAL);
	}

	CFrameWnd::ActivateFrame(nCmdShow);
}
