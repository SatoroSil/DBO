#pragma once
#include "afxcmn.h"


// CPaletteOrnamentTabDlg ��ȭ �����Դϴ�.

class CPaletteOrnamentTabDlg : public CDialog
{
	DECLARE_DYNAMIC(CPaletteOrnamentTabDlg)

public:
	CPaletteOrnamentTabDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteOrnamentTabDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ORNAMENT_TAB };
	enum ETAB_ID
	{
		ETAB_ID_NONE = -1,
		ETAB_ID_ORNAMENT = 0,
		ETAB_ID_DECAL,
		ETAB_ID_DECAL_VOLUME,
		ETAB_ID_PLANT,
		ETAB_ID_HEATHAZE,
		ETAB_ID_DOJO,

		ETAB_ID_NUM,
	};
protected:
	ETAB_ID m_eTabID[ETAB_ID_NUM];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

public:
	CTabCtrl m_TabCtrl;

public:
	afx_msg void OnTcnSelchangeWaterTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTcnSelchangingWaterTab(NMHDR *pNMHDR, LRESULT *pResult);

	virtual BOOL	OnInitDialog();
	virtual BOOL	PreTranslateMessage(MSG* pMsg);
	VOID			InitializeWorldData();
};
