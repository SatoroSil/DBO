#pragma once


// CSplinePathListDialog ��ȭ �����Դϴ�.
#include "SplinePathListCtrl.h"
#include "afxwin.h"

class CSplinePathListDialog : public CDialog
{
	DECLARE_DYNCREATE(CSplinePathListDialog)



public:
	BOOL					m_Initialized;
	CSplinePathListCtrl		m_List;


	void	RebuildSplinePath();
	void	ResetTreeItemName(const RwChar* strName);

public:
	CSplinePathListDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSplinePathListDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SPLINE_PATH_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CStatic m_SplinePathFrame;
};
