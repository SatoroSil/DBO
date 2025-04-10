#pragma once

#include "Control/RollupCtrl.h"

// CResourceLayer ���Դϴ�.

class CResourceLayer : public CView
{
	DECLARE_DYNCREATE(CResourceLayer)

public:
	enum RESOURCEDLG { /*RESOURCEFILEDLG = 0,*/ RESOURCELISTDLG , RESOURCEATTRIBUTEDLG };

protected:
	CResourceLayer();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CResourceLayer();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	CDialog*	GetRollupDlg( RESOURCEDLG eID );	

protected:
	DECLARE_MESSAGE_MAP()

protected:
	//variables
	CRollupCtrl	m_RollUpCtrl;
	BOOL		m_bInitialized;			// RollUpCtrl�� Init�Ǹ� TRUE;

public:
		
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	virtual void OnInitialUpdate();
};


