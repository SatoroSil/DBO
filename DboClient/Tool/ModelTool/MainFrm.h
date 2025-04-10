// MainFrm.h : interface of the CMainFrame class
//

#pragma once



class CMainFrame : public CFrameWnd 
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
protected:	
	CSplitterWnd m_wndColSplitter;
	CSplitterWnd m_wndRowSplitter;	
    CSplitterWnd m_wndRowSplitter2;
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar    m_wndToolBar;
    BOOL        m_bCreate;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	HWND GetViewWindow();				///< �߾��� Viewer Window�� �ڵ��� ��ȯ�Ѵ�.
	HWND GetTabWindow();				///< ���� Tab Window�� �ڵ��� ��ȯ�Ѵ�.
    HWND GetRightWindow();              ///< ������ ������Ƽ Window�� �ڵ��� ��ȯ�Ѵ�.
public:
    afx_msg void OnSize(UINT nType, int cx, int cy);
};


