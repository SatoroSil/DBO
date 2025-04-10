#pragma once
#include "afxcmn.h"


// CPalettePerformance ��ȭ �����Դϴ�.

class CPalettePerformance : public CDialog
{
	DECLARE_DYNAMIC(CPalettePerformance)

public:
	CPalettePerformance(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPalettePerformance();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PERFORMANCE };
	enum ETAB_ID
	{
		ETAB_ID_NONE = -1,
		ETAB_ID_SECTOR_CULL = 0,
		ETAB_ID_OCCLUSION,
		ETAB_ID_PVS,
		ETAB_ID_IMPOSTER,

		ETAB_ID_NUM,
	};
protected:
	ETAB_ID m_eTabID[ETAB_ID_NUM];

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
	afx_msg void OnTcnSelchangePerformaceTab(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnTcnSelchangingPerformaceTab(NMHDR *pNMHDR, LRESULT *pResult);
};
