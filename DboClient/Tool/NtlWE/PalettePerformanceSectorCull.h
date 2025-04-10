#pragma once
#include "afxwin.h"
#include "checkcombobox.h"
#include "NtlWorldFileMemAccessor.h"

// CPalettePerformanceSectorCull ��ȭ �����Դϴ�.

//////////////////////////////////////////////////////////////////////////
// dNTL_WORLD_FILE : DEFINE
//////////////////////////////////////////////////////////////////////////
#ifdef dNTL_WORLD_FILE

class CPalettePerformanceSectorCull : public CDialog
{
	DECLARE_DYNAMIC(CPalettePerformanceSectorCull)

public:
	CPalettePerformanceSectorCull(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPalettePerformanceSectorCull();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PERFORMANCE_SECTORCULL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	void InitializeWorldData();
	afx_msg void OnBnClickedSectorcull();

public:
	CButton m_SectorCull;

public:
	VOID Refresh();

private:
	afx_msg void OnBnClickedAnalyze();
	CCheckComboBox m_SSMCombo;
	CButton m_SSMFieldCheck;
};

//////////////////////////////////////////////////////////////////////////
// dNTL_WORLD_FILE : DEFINE
//////////////////////////////////////////////////////////////////////////
#else

class CPalettePerformanceSectorCull : public CDialog, public CNtlWorldFileMemAccessor
{
	DECLARE_DYNAMIC(CPalettePerformanceSectorCull)

public:
	CPalettePerformanceSectorCull(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPalettePerformanceSectorCull();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PERFORMANCE_SECTORCULL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	void InitializeWorldData();
	afx_msg void OnBnClickedSectorcull();

public:
	CButton m_SectorCull;

public:
	VOID Refresh();

private:
	afx_msg void OnBnClickedAnalyze();
	CCheckComboBox m_SSMCombo;
	CButton m_SSMFieldCheck;
};

//////////////////////////////////////////////////////////////////////////
// dNTL_WORLD_FILE : DEFINE
//////////////////////////////////////////////////////////////////////////
#endif