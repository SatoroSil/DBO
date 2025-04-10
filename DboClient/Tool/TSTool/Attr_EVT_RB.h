#pragma once


#include "Attr_Page.h"


// CAttr_EVT_RB ��ȭ �����Դϴ�.

class CAttr_EVT_RB : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_EVT_RB)

public:
	CAttr_EVT_RB(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_EVT_RB();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_EVT_RB_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	DWORD m_dwRBTblIdx;
	CButton m_ctrPrivateEnter;
	CButton m_ctrPrivateWin;
	CButton m_ctrPartyEnter;
	CButton m_ctrPartyWin;
};
