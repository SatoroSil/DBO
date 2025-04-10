#pragma once


// CActionListDialog ��ȭ �����Դϴ�.

#include "ActionListCtrl.h"
#include "afxwin.h"

class CActionListDialog : public CDialog
{
	DECLARE_DYNCREATE(CActionListDialog)

public:
	CActionListDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CActionListDialog();

	void	ResetResourceSystem();

public:
	BOOL					m_Initialized;
	CActionListCtrl			m_List;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ACTION_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CStatic m_ActionFrame;
};
