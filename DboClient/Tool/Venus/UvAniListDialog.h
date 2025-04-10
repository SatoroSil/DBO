#pragma once
#include "afxcmn.h"


// CUvAniListDialog ��ȭ �����Դϴ�.
#include "DataTreeCtrl.h"

class CUvAniListDialog : public CDialog
{
	DECLARE_DYNCREATE(CUvAniListDialog)

public:

public:
	CUvAniListDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUvAniListDialog();

	void	SerializeList();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_UVANI_LIST };

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
    CDataTreeCtrl m_UvAnimationList;
};
