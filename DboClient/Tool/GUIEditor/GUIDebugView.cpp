// GUIDebugView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "GUIEditor.h"
#include "GUIDebugView.h"
#include "GUIResourceView.h"

CGUIDebugView* g_pDebugView = NULL;

// CGUIDebugView

IMPLEMENT_DYNCREATE(CGUIDebugView, CScrollView)

CGUIDebugView::CGUIDebugView()
{
}

CGUIDebugView::~CGUIDebugView()
{
}


BEGIN_MESSAGE_MAP(CGUIDebugView, CScrollView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CGUIDebugView �׸����Դϴ�.

void CGUIDebugView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CGUIDebugView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	
	if( g_DevILImage.IsLoaded() )
	{
		CRect rect = g_pResourceView->GetSelectRect();
		g_DevILImage.DrawMemDC( pDC, rect.left, rect.top, 0, 0, rect.Width(), rect.Height() );
	}
}


// CGUIDebugView �����Դϴ�.

#ifdef _DEBUG
void CGUIDebugView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CGUIDebugView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG


// CGUIDebugView �޽��� ó�����Դϴ�.

void CGUIDebugView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if( g_DevILImage.IsLoaded() )
	{
		CRect rect = g_pResourceView->GetSelectRect();
		CSize sizeRect;
		sizeRect.cx = rect.Width();
		sizeRect.cy = rect.Height();

		SetScrollSizes( MM_TEXT, sizeRect );
	}
}
