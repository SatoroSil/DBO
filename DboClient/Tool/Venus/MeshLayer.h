#pragma once


// CMeshLayer ���Դϴ�.
#include "RollupCtrl.h"

class CMeshLayer : public CView
{
	DECLARE_DYNCREATE(CMeshLayer)

protected:
	CMeshLayer();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CMeshLayer();

public:
	BOOL					m_bInitialized;
	CRollupCtrl				m_RollupControl;

	enum EDIT_DIALOG
	{
		EDIT_DIALOG_MESH_LIST = 0x00,
		EDIT_DIALOG_ANIMATION_LIST,
		EDIT_DIALOG_UV_ANIMATION_LIST,
		EDIT_DIALOG_PROPERTY,
	};

public:

	void	InitializeList();

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


