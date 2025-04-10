#pragma once
#include "afxwin.h"


// CPalettePerformancePVS ��ȭ �����Դϴ�.

class CPalettePerformancePVS : public CDialog
{
	DECLARE_DYNAMIC(CPalettePerformancePVS)

public:
	CPalettePerformancePVS(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPalettePerformancePVS();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PERFORMANCE_PVS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	void InitializeWorldData();
public:
	afx_msg void OnBnClickedLosFullBuild();
public:
	afx_msg void OnBnClickedLosFullDestroy();
public:
	CString m_PVSBMPName;
public:
	afx_msg void OnBnClickedLoadPvsBmp();
public:
	afx_msg void OnBnClickedReport();
};
