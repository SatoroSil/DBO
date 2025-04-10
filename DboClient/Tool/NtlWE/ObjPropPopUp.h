#pragma once
#include "afxwin.h"
#include "checkcombobox.h"


// CObjPropPopUp ��ȭ �����Դϴ�.

class CObjPropPopUp : public CDialog
{
	DECLARE_DYNAMIC(CObjPropPopUp)

public:
	CObjPropPopUp(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CObjPropPopUp();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_OBJ_PROP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedTrigger();
	afx_msg void OnEnChangeVisibilityDist();

public:
	sNTL_DOODADS_PROP_PARAM m_NtlDoodadsPropParam;

	CString			m_strGUID;
	CString			m_strAABB;	
	CString			m_strVisibilityDist;
	CButton			m_EnableTrigger;
	CString			m_strMax;

	CComboBox		m_cbObjectType;
	CCheckComboBox	m_cbMinimapLayer;
	CCheckComboBox	m_cbBitProp;
	CCheckComboBox	m_cbLtMapFlagsObject;
	CCheckComboBox	m_cbLtMapFlagsMaterial;

	CString			m_CurName;
	CString			m_NameIndexInput;
	CString			m_DoodadName;
	CString			m_DoodadID;
	CString			m_MilePostGUID;
	CString			m_MilePostMemo;
	CEdit			m_MilePostEditCtrl;
};
