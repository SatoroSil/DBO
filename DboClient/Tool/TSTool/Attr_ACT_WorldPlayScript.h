#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_WorldPlayScript ��ȭ �����Դϴ�.

class CAttr_ACT_WorldPlayScript : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_WorldPlayScript)

public:
	typedef std::vector< unsigned int > vecdef_ControlList;
	typedef std::map< unsigned int, vecdef_ControlList > vecdef_MapList;

protected:
	enum { WPS_INVLAID = 0xff };

protected:
	vecdef_MapList m_defMapList;
	int m_nCurSelIndex;

public:
	CAttr_ACT_WorldPlayScript();
	virtual ~CAttr_ACT_WorldPlayScript();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_WORLDPLAYSCRIPT_ATTR_DIAG };

	void InitData( void );

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	CComboBox m_ctrStart;
	CButton m_ctrUOFailed;
	DWORD m_dwScriptID;

public:
	afx_msg void OnCbnSelchangeTsActAttrWorldplayscriptStartCombo();
};
