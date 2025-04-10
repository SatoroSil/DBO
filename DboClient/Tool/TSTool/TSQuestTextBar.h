#pragma once



// CTSQuestTextBar �� ���Դϴ�.

class CTSQuestTextBar : public CSizingControlBarCF
{
	DECLARE_DYNCREATE(CTSQuestTextBar)

protected:
	CFrameWnd* m_pFrameWnd;
	CCreateContext m_Context;

public:
	CTSQuestTextBar();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CTSQuestTextBar();

	virtual BOOL Create( CWnd* pParentWnd,
						 CRuntimeClass* pViewClass,
						 CCreateContext* pContext = NULL,
						 LPCTSTR lpszWindowName = NULL,
						 DWORD dwStyle = WS_CHILD|WS_VISIBLE|CBRS_TOP,
						 UINT nID = AFX_IDW_PANE_FIRST );
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


