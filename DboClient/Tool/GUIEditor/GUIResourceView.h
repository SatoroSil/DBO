// GUIResourceView.h : iCGUIResourceView Ŭ������ �������̽�
//

#pragma once

#include "CDevILMFCMemDC.h"
#include "KMSelectBox.h"
#include "CoordManager.h"

class CGUIEditorDoc;

class CGUIResourceView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CGUIResourceView();
	DECLARE_DYNCREATE(CGUIResourceView)

// Ư��
public:
	CGUIEditorDoc* GetDocument() const;
	
// �۾�
public:
	//void SSetClientSizeFromImage();

// ������
	public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// ����
public:
	virtual ~CGUIResourceView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	BOOL	LoadImage( CString& strFullPath, CString& strFileName );
	void	SetSelectBox( CRect rcRect );							// ���� �ڽ� �ű�.
	void	ResizeBuffer();
	void	UpdateRectInfo();					
	void	UpdateRsrInfo( CString& strFilename );
	CRect	GetSelectRect() { return m_selectBox.GetCurRect(); }
	void	ShowSelected();

// Variables
protected:
	CKMSelectBox	m_selectBox;	// RectTracker.
	CKMMemDC		m_dcBuffer;		// ������۸�.
	CCoordManager	m_CoordMgr;		// ��ǥ����.

	CPoint			m_ptRBtnDown;	// RButtonDown�� ��ǥ.
	
	BOOL			m_bInitialized;	
			
// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // GUIResourceView.cpp�� ����� ����
inline CGUIEditorDoc* CGUIResourceView::GetDocument() const
   { return reinterpret_cast<CGUIEditorDoc*>(m_pDocument); }
#endif

extern CGUIResourceView* g_pResourceView;

