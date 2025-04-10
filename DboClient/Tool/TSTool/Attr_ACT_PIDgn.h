#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_PIDgn ��ȭ �����Դϴ�.

class CAttr_ACT_PIDgn : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_PIDgn)

public:
	typedef std::vector< unsigned int > vecdef_ControlList;
	typedef std::map< unsigned int, vecdef_ControlList > vecdef_MapList;

protected:
	vecdef_MapList m_defMapList;
	int m_nCurSelIndex;

public:
	CAttr_ACT_PIDgn();
	virtual ~CAttr_ACT_PIDgn();

	void InitData( void );

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_PIDGN_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	CComboBox m_ctrDngType;
	DWORD m_dwNormalTblIdx;
	DWORD m_dwHardTblIdx;

public:
	afx_msg void OnCbnSelchangeTsActAttrPidgnTypeCombo();
};
