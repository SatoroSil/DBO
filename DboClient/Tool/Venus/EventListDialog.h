#pragma once


// CEventListDialog ��ȭ �����Դϴ�.
#include "EventListCtrl.h"

#include "rwcore.h"

class CEventListDialog : public CDialog
{
	DECLARE_DYNCREATE(CEventListDialog)

public:
	CEventListDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEventListDialog();


	void	ResetTreeItemName(const RwChar* strName);

public:
	BOOL					m_Initialized;
	CEventListCtrl			m_List;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EVENT_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
