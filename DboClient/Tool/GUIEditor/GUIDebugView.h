#pragma once



// CGUIDebugView ���Դϴ�.

class CGUIDebugView : public CScrollView
{
	DECLARE_DYNCREATE(CGUIDebugView)

protected:
	CGUIDebugView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CGUIDebugView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual void OnInitialUpdate();     // ������ �� ó���Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

extern CGUIDebugView* g_pDebugView;
