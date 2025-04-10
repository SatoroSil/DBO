#pragma once

#include "checkcombobox.h"

// CEffectPropPopup ��ȭ �����Դϴ�.

class CEffectPropPopup : public CDialog
{
	DECLARE_DYNAMIC(CEffectPropPopup)

public:
	CEffectPropPopup(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEffectPropPopup();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EFFECT_PROP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

public:
	CString			m_strVisibleDist;
	CString			m_strName;

	CCheckComboBox	m_cbMinimapLayer;
};
