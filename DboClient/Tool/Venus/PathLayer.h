#pragma once


// CPathLayer ���Դϴ�.
#include "RollupCtrl.h"

class CPathLayer : public CView
{
	DECLARE_DYNCREATE(CPathLayer)

protected:
	CPathLayer();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CPathLayer();

public:
	BOOL					m_bInitialized;
	CRollupCtrl				m_RollupControl;

	enum EDIT_DIALOG
	{
		EDIT_DIALOG_SPLINE_PATH_LIST = 0x00,
		EDIT_DIALOG_PROPERTY,
	};


	void	RebuildSplinePath();

	void	ResetTreeItemName(const RwChar* strName);
	void	ResetProperties();

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
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};


