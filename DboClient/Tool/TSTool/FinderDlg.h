#pragma once
#include "afxwin.h"


// CFinderDlg ��ȭ �����Դϴ�.

class CFinderDlg : public CDialog
{
	DECLARE_DYNAMIC(CFinderDlg)

protected:
	typedef std::map< CString, CRuntimeClass* > mapdef_KeyValList;

public:
	CFinderDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFinderDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FINDER_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

protected:
	mapdef_KeyValList	m_defKeyValContList;
	mapdef_KeyValList	m_defKeyValEventList;
	mapdef_KeyValList	m_defKeyValCondList;
	mapdef_KeyValList	m_defKeyValActList;

public:
	CComboBox m_ctrCont;
	CComboBox m_ctrEvent;
	CComboBox m_ctrCond;
	CComboBox m_ctrAct;
	CListBox m_ctrResultOutput;

public:
	afx_msg void OnBnClickedFinderFindBtn();
	afx_msg void OnBnClickedFinderFindResultSaveBtn();

	virtual BOOL OnInitDialog();
};
