#pragma once
#include "afxwin.h"


// CPaletteSpawnMacroModify ��ȭ �����Դϴ�.

class CPaletteSpawnMacroModify : public CDialog
{
	DECLARE_DYNAMIC(CPaletteSpawnMacroModify)

public:
	CPaletteSpawnMacroModify(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteSpawnMacroModify();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SPAWN_MACRO_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	CString m_StrCoolTime;
	CString m_StrWanderRange;
	CString m_StrMoveRange;
	CString m_StrDelayTime;
public:
	CComboBox m_MoveTypeCombo;
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeMovetype();
};
