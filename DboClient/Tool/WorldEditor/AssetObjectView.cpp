// AssetObjectView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "WorldEditor.h"
#include "AssetObjectView.h"
#include ".\assetobjectview.h"


// CAssetObjectView

IMPLEMENT_DYNCREATE(CAssetObjectView, CView)

CAssetObjectView::CAssetObjectView()
{
}

CAssetObjectView::~CAssetObjectView()
{
}

BEGIN_MESSAGE_MAP(CAssetObjectView, CView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CAssetObjectView �׸����Դϴ�.

void CAssetObjectView::OnDraw(CDC* pDC)
{
//	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CAssetObjectView �����Դϴ�.

#ifdef _DEBUG
void CAssetObjectView::AssertValid() const
{
	CView::AssertValid();
}

void CAssetObjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG


// CAssetObjectView �޽��� ó�����Դϴ�.

void CAssetObjectView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_ObjDlg.Create(IDD_ASSET_OBJECT, this);
	m_ObjDlg.ShowWindow(SW_SHOW);
}

void CAssetObjectView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	if(m_ObjDlg.GetSafeHwnd())
	{
		m_ObjDlg.MoveWindow(0, 0, cx, cy);
	}
}

