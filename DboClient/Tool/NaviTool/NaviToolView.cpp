// NaviToolView.cpp : CNaviToolView Ŭ������ ����
//

#include "stdafx.h"
#include "NaviTool.h"

#include "NaviToolDoc.h"
#include "NaviToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNaviToolView

IMPLEMENT_DYNCREATE(CNaviToolView, CView)

BEGIN_MESSAGE_MAP(CNaviToolView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CNaviToolView ����/�Ҹ�

CNaviToolView::CNaviToolView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CNaviToolView::~CNaviToolView()
{
}

BOOL CNaviToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CNaviToolView �׸���

void CNaviToolView::OnDraw(CDC* /*pDC*/)
{
	CNaviToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CNaviToolView �μ�

BOOL CNaviToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CNaviToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CNaviToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CNaviToolView ����

#ifdef _DEBUG
void CNaviToolView::AssertValid() const
{
	CView::AssertValid();
}

void CNaviToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNaviToolDoc* CNaviToolView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNaviToolDoc)));
	return (CNaviToolDoc*)m_pDocument;
}
#endif //_DEBUG
BOOL CNaviToolView::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	return CView::OnWndMsg(message, wParam, lParam, pResult);
}
