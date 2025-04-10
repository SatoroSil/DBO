// TextureBindView.h : CTextureBindView Ŭ������ �������̽�
//


#pragma once


class CTextureBindView : public CView
{
protected: // serialization������ ��������ϴ�.
	CTextureBindView();
	DECLARE_DYNCREATE(CTextureBindView)

// Ư���Դϴ�.
public:
	CTextureBindDoc* GetDocument() const;

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
	virtual ~CTextureBindView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TextureBindView.cpp�� ����� ����
inline CTextureBindDoc* CTextureBindView::GetDocument() const
   { return reinterpret_cast<CTextureBindDoc*>(m_pDocument); }
#endif

