#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_ConcCheck ��ȭ �����Դϴ�.

class CAttr_ACT_ConcCheck : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_ConcCheck)

public:
	CAttr_ACT_ConcCheck();
	virtual ~CAttr_ACT_ConcCheck();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_CONC_CHECK_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	int m_nConcCheckCnt;
	DWORD m_dwResetTime;
	DWORD m_dwObjIdx;
	DWORD m_dwExcTID;
};
