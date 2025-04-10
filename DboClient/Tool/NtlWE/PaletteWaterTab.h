#pragma once
#include "afxcmn.h"


// CPaletteWaterTab ��ȭ �����Դϴ�.

class CPaletteWaterTab : public CDialog
{
	DECLARE_DYNAMIC(CPaletteWaterTab)

public:
	CPaletteWaterTab(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteWaterTab();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_WATER_TAB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

public:
	void InitializeWorldData();
public:
	CTabCtrl m_TabCtrl;
public:
	afx_msg void OnTcnSelchangeWaterTab(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnTcnSelchangingWaterTab(NMHDR *pNMHDR, LRESULT *pResult);
};
