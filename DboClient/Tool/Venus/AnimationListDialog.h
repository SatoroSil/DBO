#pragma once
#include "afxcmn.h"


// CAnimationListDialog ��ȭ �����Դϴ�.
#include "DataTreeCtrl.h"

class CAnimationListDialog : public CDialog
{
	DECLARE_DYNCREATE(CAnimationListDialog)

public:

public:
	CAnimationListDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAnimationListDialog();

	void	SerializeList();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ANIMATION_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
    void OnRefresh();

protected:
	CDataTreeCtrl m_AnimationList;
};
