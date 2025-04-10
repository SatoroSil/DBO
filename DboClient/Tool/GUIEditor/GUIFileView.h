#pragma once

#include "DirTreeCtrlMSC.h"	

#define ID_TREECTRL 10002

// CGUIFileView ���Դϴ�.

class CGUIFileView : public CView
{
	DECLARE_DYNCREATE(CGUIFileView)

protected:
	CGUIFileView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CGUIFileView();

	CDirTreeCtrlMSC	m_DirTree;

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CDirTreeCtrlMSC* GetTreeCtrl() { return &m_DirTree; }

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

extern CGUIFileView* g_pFileView;
