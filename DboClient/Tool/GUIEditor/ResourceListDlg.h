#pragma once

// CResourceListDlg ��ȭ �����Դϴ�.
#include "Control/PropTree.h"

class CResourceListDlg : public CDialog
{
	DECLARE_DYNCREATE(CResourceListDlg)

public:
	CResourceListDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CResourceListDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_RESOURCELISTDLG };
	
	enum PROPERTY_ID
	{
		PROPERTY_NONE = -1,

		PROPERTY_CAPTION = 0,
	};

	void	DisplayList();					  // List�� ����մϴ�.
	INT		GetFocusID();					

protected:
	void	AddItem( CString strCaption, INT nIndex, CPropTreeItem* pRoot );	
	void	ShowAttribute( CPropTreeItem* pItem );

protected:
	CPropTree	m_PropertyTree;
	BOOL		m_bInitialized;
		
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedRemoveResourcelist();
	afx_msg void OnBnClickedSaveResourcelist();
	afx_msg void OnBnClickedClearResourcelist();

protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
};
