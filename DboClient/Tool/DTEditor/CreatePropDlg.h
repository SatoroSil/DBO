#pragma once
#include "afxwin.h"


// CCreatePropDlg ��ȭ �����Դϴ�.

enum eCreateType
{
	CREATE_SPLINE,
	CREATE_DIRECTION_NODE,

	INVALID_CREATE_TYPE
};

class CCreatePropDlg : public CDialog
{
	DECLARE_DYNAMIC(CCreatePropDlg)

public:
	CCreatePropDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCreatePropDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ADD_PROP };

public:
	int		m_nIndex;
	int		m_nCreateType;
	CString	m_strString;

public:
	void	SetCreateType(eCreateType byType);

	int		GetSelectedIndex(void) const;
	CString	GetSelectedString();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_PropList;
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
public:
	afx_msg void OnLbnSelchangeAddPropList();
};
