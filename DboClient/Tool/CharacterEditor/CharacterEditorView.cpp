// CharacterEditorView.cpp : CCharacterEditorView Ŭ������ ����
//

#include "stdafx.h"
#include "DboCharacterApplication.h"
#include "CharacterEditor.h"

#include "CharacterEditorDoc.h"
#include "CharacterEditorView.h"
#include ".\charactereditorview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCharacterEditorView

IMPLEMENT_DYNCREATE(CCharacterEditorView, CView)

BEGIN_MESSAGE_MAP(CCharacterEditorView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CCharacterEditorView ����/�Ҹ�

CCharacterEditorView::CCharacterEditorView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CCharacterEditorView::~CCharacterEditorView()
{
}

BOOL CCharacterEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CCharacterEditorView �׸���

void CCharacterEditorView::OnDraw(CDC* /*pDC*/)
{
	CCharacterEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CCharacterEditorView �μ�

BOOL CCharacterEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CCharacterEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CCharacterEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CCharacterEditorView ����

#ifdef _DEBUG
void CCharacterEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CCharacterEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCharacterEditorDoc* CCharacterEditorView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCharacterEditorDoc)));
	return (CCharacterEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CCharacterEditorView �޽��� ó����

void CCharacterEditorView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	RECT rc;
	GetClientRect(&rc);
	CDboCharacterApplication::GetInstance()->Resize(rc.right-rc.left, rc.bottom - rc.top, TRUE);
}

BOOL CCharacterEditorView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	theApp.m_DboApplication.WndProc(pMsg->hwnd, pMsg->message, pMsg->wParam, pMsg->lParam);
	return CView::PreTranslateMessage(pMsg);
}
