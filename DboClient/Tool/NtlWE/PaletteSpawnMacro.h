#pragma once
#include "afxwin.h"


// CPaletteSpawnMacro ��ȭ �����Դϴ�.

class CPaletteSpawnMacro : public CDialog
{
	DECLARE_DYNAMIC(CPaletteSpawnMacro)

public:
	CPaletteSpawnMacro(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteSpawnMacro();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SPAWN_MACRO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_CoolTime;
	CComboBox m_MoveType;
	CString m_WanderRange;
	CString m_MoveRange;
	CString m_DelayTime;
public:
	afx_msg void OnBnClickedCreate();
public:
	afx_msg void OnBnClickedDelete();
public:
	CListBox m_SpawnMacro;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	virtual BOOL OnInitDialog();
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnLbnSelchangeSpawnMacro();

public:
	VOID RefreshSMIListCtrl();
};
