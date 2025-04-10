// MainFrm.h : CMainFrame Ŭ������ �������̽�
//
#pragma once

#include "Control/SizingTabCtrlBar.h"

class CMainFrame : public CFrameWnd
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư��
public:
	BOOL m_bSplit;					// â���ҿϷ�� True;
	CSplitterWnd m_wndSplit1;		
	CSplitterWnd m_wndSplit2;	
		
	CSizingTabCtrlBar m_wndLayerBar;

// �۾�
public:
	void ResizeSplitWnd();
	void InitCtrlBar();

// ������
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	virtual void ActivateFrame(int nCmdShow = -1);
};
