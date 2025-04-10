// AnimationView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CharacterEditor.h"
#include "AnimationView.h"
#include ".\animationview.h"


// CAnimationView

IMPLEMENT_DYNCREATE(CAnimationView, CView)

CAnimationView::CAnimationView()
{
}

CAnimationView::~CAnimationView()
{
}

BEGIN_MESSAGE_MAP(CAnimationView, CView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CAnimationView �׸����Դϴ�.

void CAnimationView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CAnimationView �����Դϴ�.

#ifdef _DEBUG
void CAnimationView::AssertValid() const
{
	CView::AssertValid();
}

void CAnimationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG


// CAnimationView �޽��� ó�����Դϴ�.

void CAnimationView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_AnimationTreeDialog.Create(IDD_ANIMASSETDLG, this);
	m_AnimationSetDialog.Create(IDD_ANIMASSETANIMSETDLG, this);

	m_AnimationTreeDialog.ShowWindow(SW_SHOW);
	m_AnimationSetDialog.ShowWindow(SW_SHOW);
}

void CAnimationView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if(m_AnimationTreeDialog.GetSafeHwnd())
	{
		m_AnimationTreeDialog.MoveWindow(0, 0, cx, 300); 
	}

	if(m_AnimationSetDialog.GetSafeHwnd())
	{
		m_AnimationSetDialog.MoveWindow(0, 300, cx, 300 + 250);
	}
}

