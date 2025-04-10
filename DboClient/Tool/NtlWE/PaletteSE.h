#pragma once
#include "afxcmn.h"


// CPaletteSE ��ȭ �����Դϴ�.

class CPaletteSE : public CDialog
{
	DECLARE_DYNAMIC(CPaletteSE)

public:
	CPaletteSE(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteSE();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ATTR_SE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl	m_SETree;

public:
	void		CreateLeafNode(const char *pName, HTREEITEM hTreeItem);
	HTREEITEM	GetItemByName(char* szItemName, HTREEITEM hItem);
	RwBool		GetCurBGMFileName(RwChar _FileName[32]);
	RwBool		GetCurCategoryName(RwChar _CategoryName[32]);

public:
	void InitializeWorldData();

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnTvnSelchangedSeTree(NMHDR *pNMHDR, LRESULT *pResult);

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	
};
