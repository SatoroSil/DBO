#pragma once
#include "afxwin.h"


// CMiniMapPropDlg ��ȭ �����Դϴ�.

class CMiniMapPropDlg : public CDialog
{
	DECLARE_DYNAMIC(CMiniMapPropDlg)

public:
	CMiniMapPropDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMiniMapPropDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MINIMAP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnCbnSelchangeTexsize();
	afx_msg void OnBnClickedCreateAll();
	afx_msg void OnBnClickedOk();

public:
	CButton		m_CreateAll;
	CComboBox	m_TexSizeCombo;
	CComboBox	m_MMPropCombo;
};
