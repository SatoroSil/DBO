// TextureConverterView.cpp : CTextureConverterView Ŭ������ ����
//

#include "stdafx.h"
#include "TextureConverter.h"

#include "TextureConverterDoc.h"
#include "TextureConverterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextureConverterView

IMPLEMENT_DYNCREATE(CTextureConverterView, CScrollView)

BEGIN_MESSAGE_MAP(CTextureConverterView, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTextureConverterView ����/�Ҹ�

CTextureConverterView::CTextureConverterView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CTextureConverterView::~CTextureConverterView()
{
}

BOOL CTextureConverterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CTextureConverterView �׸���

void CTextureConverterView::OnDraw(CDC* pDC)
{
	CTextureConverterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	for( int nIndex = 0; nIndex < GetDocument()->GetFileCount(); ++nIndex )
	{
		pDC->TextOut( 0, nIndex * 16, *(GetDocument()->GetFileName( nIndex )) );
	}
}

void CTextureConverterView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CTextureConverterView �μ�

BOOL CTextureConverterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CTextureConverterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CTextureConverterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CTextureConverterView ����

#ifdef _DEBUG
void CTextureConverterView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CTextureConverterView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CTextureConverterDoc* CTextureConverterView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextureConverterDoc)));
	return (CTextureConverterDoc*)m_pDocument;
}
#endif //_DEBUG


// CTextureConverterView �޽��� ó����
