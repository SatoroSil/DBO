// TextureBindView.cpp : CTextureBindView Ŭ������ ����
//

#include "stdafx.h"
#include "TextureBind.h"

#include "TextureBindDoc.h"
#include "TextureBindView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextureBindView

IMPLEMENT_DYNCREATE(CTextureBindView, CView)

BEGIN_MESSAGE_MAP(CTextureBindView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTextureBindView ����/�Ҹ�

CTextureBindView::CTextureBindView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CTextureBindView::~CTextureBindView()
{
}

BOOL CTextureBindView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CTextureBindView �׸���

void CTextureBindView::OnDraw(CDC* /*pDC*/)
{
	CTextureBindDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CTextureBindView �μ�

BOOL CTextureBindView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CTextureBindView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CTextureBindView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CTextureBindView ����

#ifdef _DEBUG
void CTextureBindView::AssertValid() const
{
	CView::AssertValid();
}

void CTextureBindView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextureBindDoc* CTextureBindView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextureBindDoc)));
	return (CTextureBindDoc*)m_pDocument;
}
#endif //_DEBUG


// CTextureBindView �޽��� ó����
