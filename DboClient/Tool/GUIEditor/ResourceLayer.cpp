// ResourceLayer.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "GUIEditor.h"
#include ".\resourcelayer.h"
#include ".\LayerMisc.h"

#include "FileViewDlg.h"
#include "ResourceListDlg.h"
#include "ResourceAttributeDlg.h"


// CResourceLayer

IMPLEMENT_DYNCREATE(CResourceLayer, CView)

CResourceLayer::CResourceLayer()
{
	m_bInitialized = FALSE;
}

CResourceLayer::~CResourceLayer()
{
}

BEGIN_MESSAGE_MAP(CResourceLayer, CView)
	ON_WM_SIZE()
//	ON_WM_SETCURSOR()
ON_WM_SETFOCUS()
END_MESSAGE_MAP()


// CResourceLayer �׸����Դϴ�.

void CResourceLayer::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CResourceLayer �����Դϴ�.

#ifdef _DEBUG
void CResourceLayer::AssertValid() const
{
	CView::AssertValid();
}

void CResourceLayer::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG


// CResourceLayer �޽��� ó�����Դϴ�.

void CResourceLayer::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if( m_bInitialized )
		m_RollUpCtrl.MoveWindow( 0, 0, cx, cy );
}

void CResourceLayer::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//CLayerMisc::GetInstance().SetLayer( CLayerMisc::RESOURCE_LAYER );
}

void CResourceLayer::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_RollUpCtrl.Create( WS_VISIBLE|WS_CHILD, CRect(0,1,190,400), this, IDD_ROLLUPPAGEID );

	//m_RollUpCtrl.InsertPage( "File View", IDD_FILEVIEWDLG, RUNTIME_CLASS( CFileViewDlg ) );
	m_RollUpCtrl.InsertPage( "Resource List", IDD_RESOURCELISTDLG, RUNTIME_CLASS( CResourceListDlg ) );
	m_RollUpCtrl.InsertPage( "Resource Attribute", IDD_RESOURCEATTRIBUTEDLG, RUNTIME_CLASS( CResourceAttributeDlg ) );

	m_RollUpCtrl.ExpandAllPages();

	m_bInitialized = TRUE;			
}

CDialog* CResourceLayer::GetRollupDlg( RESOURCEDLG eID )
{
	CDialog*	 pDialog = NULL;
	RC_PAGEINFO* pginfo = m_RollUpCtrl.GetPageInfo( eID );
	if(pginfo && pginfo->pwndTemplate)
		pDialog = (CDialog*)pginfo->pwndTemplate;					

	return pDialog;
}
