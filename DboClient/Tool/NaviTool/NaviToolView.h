// NaviToolView.h : CNaviToolView Ŭ������ �������̽�
//


#pragma once


class CNaviToolView : public CView
{
protected: // serialization������ ��������ϴ�.
	CNaviToolView();
	DECLARE_DYNCREATE(CNaviToolView)

// Ư���Դϴ�.
public:
	CNaviToolDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CNaviToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
};

#ifndef _DEBUG  // NaviToolView.cpp�� ����� ����
inline CNaviToolDoc* CNaviToolView::GetDocument() const
   { return reinterpret_cast<CNaviToolDoc*>(m_pDocument); }
#endif

