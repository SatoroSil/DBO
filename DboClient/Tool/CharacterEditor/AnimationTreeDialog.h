#pragma once
#include "afxcmn.h"


// CAnimAssetDlg ��ȭ �����Դϴ�.

class CAnimationTreeDialog : public CDialog
{
	DECLARE_DYNAMIC(CAnimationTreeDialog)

public:
	CAnimationTreeDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAnimationTreeDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ANIMASSETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTreeCtrl m_AnimAssetTreeCtrl;
	
	void UpdateTree(CDboCharacterApplication *pDboApp);
	
	
	void CAnimationTreeDialog::DeleteToolAnimData(HTREEITEM hItem);
	void DeleteRecursiveToolAnimData(HTREEITEM hItem);

	afx_msg void OnTvnSelchangedTree2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
};
