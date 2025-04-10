#pragma once

#include "DirTreeCtrl.h"
#include "ExtFilter.h"

// FileViewDlg ��ȭ �����Դϴ�.

class CFileViewDlg : public CDialog
{
	DECLARE_DYNCREATE(CFileViewDlg)

public:
	CFileViewDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFileViewDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FILEVIEWDLG };

	// variables
	CDirTreeCtrl	m_FileTree;
	CExtFilter		m_ExtFilter;

protected:
	BOOL m_bInitialized;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
