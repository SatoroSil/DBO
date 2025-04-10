#pragma once

#include "Control/RollupCtrl.h"

// CSurfaceLayer ���Դϴ�.

class CSurfaceLayer : public CView
{
	DECLARE_DYNCREATE(CSurfaceLayer)

public:
	enum SURFACEDLG { /*SURFACEFILEDLG = 0,*/ RECTINFODLG, SURFACELISTDLG , SURFACEATTRIBUTEDLG };

protected:
	CSurfaceLayer();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CSurfaceLayer();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	CDialog*	GetRollupDlg( SURFACEDLG eID );	

protected:
	DECLARE_MESSAGE_MAP()

protected:
	//variables
	CRollupCtrl	m_RollUpCtrl;
	BOOL		m_bInitialized;			// RollUpCtrl�� Init�Ǹ� TRUE;

public:
	
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};


