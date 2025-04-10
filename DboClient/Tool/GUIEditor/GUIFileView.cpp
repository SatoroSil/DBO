// GUIFileView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "GUIEditor.h"
#include "GUIFileView.h"
#include ".\guifileview.h"

CGUIFileView* g_pFileView = NULL;

// CGUIFileView

IMPLEMENT_DYNCREATE(CGUIFileView, CView)

CGUIFileView::CGUIFileView()
{
}

CGUIFileView::~CGUIFileView()
{
}

BEGIN_MESSAGE_MAP(CGUIFileView, CView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CGUIFileView �׸����Դϴ�.

void CGUIFileView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CGUIFileView �����Դϴ�.

#ifdef _DEBUG
void CGUIFileView::AssertValid() const
{
	CView::AssertValid();
}

void CGUIFileView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG


// CGUIFileView �޽��� ó�����Դϴ�.

BOOL CGUIFileView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	BOOL  bRet;

	bRet = CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);

	// this part creates the TreeCtrl and use the CLeftView
	// as his parent Window

	if ( m_DirTree.m_hWnd == NULL && bRet )
	{
		bRet = m_DirTree.Create( WS_CHILD | TVS_LINESATROOT | TVS_HASBUTTONS | WS_VISIBLE | TVS_HASLINES, 
			CRect(0, 0, 0, 0), this, ID_TREECTRL );
		if ( bRet )
			//m_DirTree.DisplayTree( "Z:\\DBO-X\\DboTest\\texture\\gui", TRUE );
			m_DirTree.DisplayTree( NULL, TRUE );
	}

	return bRet;

	//return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CGUIFileView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if ( m_DirTree.m_hWnd )
		m_DirTree.SetWindowPos( NULL, 0, 0, cx, cy, SWP_NOZORDER | SWP_NOMOVE );
}
