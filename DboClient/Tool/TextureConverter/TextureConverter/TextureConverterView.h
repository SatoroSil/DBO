// TextureConverterView.h : iCTextureConverterView Ŭ������ �������̽�
//


#pragma once


class CTextureConverterView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CTextureConverterView();
	DECLARE_DYNCREATE(CTextureConverterView)

// Ư��
public:
	CTextureConverterDoc* GetDocument() const;

// �۾�
public:

// ������
	public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����
public:
	virtual ~CTextureConverterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TextureConverterView.cpp�� ����� ����
inline CTextureConverterDoc* CTextureConverterView::GetDocument() const
   { return reinterpret_cast<CTextureConverterDoc*>(m_pDocument); }
#endif

