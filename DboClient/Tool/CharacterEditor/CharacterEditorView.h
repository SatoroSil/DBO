// CharacterEditorView.h : iCCharacterEditorView Ŭ������ �������̽�
//


#pragma once


class CCharacterEditorView : public CView
{
protected: // serialization������ ��������ϴ�.
	CCharacterEditorView();
	DECLARE_DYNCREATE(CCharacterEditorView)

// Ư��
public:
	CCharacterEditorDoc* GetDocument() const;

// �۾�
public:

// ������
	public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����
public:
	virtual ~CCharacterEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#ifndef _DEBUG  // CharacterEditorView.cpp�� ����� ����
inline CCharacterEditorDoc* CCharacterEditorView::GetDocument() const
   { return reinterpret_cast<CCharacterEditorDoc*>(m_pDocument); }
#endif

