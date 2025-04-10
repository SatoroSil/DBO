#pragma once


// CAnimationView ���Դϴ�.
#include "AnimationTreeDialog.h"
#include "AnimationSetDialog.h"

class CAnimationView : public CView
{
	DECLARE_DYNCREATE(CAnimationView)

protected:
	CAnimationView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CAnimationView();

public:
	CAnimationTreeDialog	m_AnimationTreeDialog;
	CAnimationSetDialog	    m_AnimationSetDialog;
public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


