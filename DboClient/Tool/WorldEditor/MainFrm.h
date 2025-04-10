// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#pragma once

#include "CEditorMainControlBar.h"

class CMainFrame : public CFrameWnd
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư��
protected:

	CEditorMainControlBar			m_cEditControlBar;

// �۾�
public:

	void ControllBarInitialize(void);

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

public:

	static void			SetActiveWnd( CWnd * pActiveWnd ) { CMainFrame::m_pActiveWnd = pActiveWnd; }
	static CWnd *		GetActiveWnd( void ) { return CMainFrame::m_pActiveWnd; }
	static CWnd *		m_pActiveWnd; 

	bool				SetStatusText( TCHAR * lptText );

	void				ShowPropertyDialogBarWindow( bool bShow );

	virtual void ActivateFrame(int nCmdShow = -1);
	afx_msg void OnDestroy();
};