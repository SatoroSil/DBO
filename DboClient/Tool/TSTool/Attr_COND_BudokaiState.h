#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_COND_BudokaiState ��ȭ �����Դϴ�.

class CAttr_COND_BudokaiState : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_BudokaiState)

public:
	CAttr_COND_BudokaiState();
	virtual ~CAttr_COND_BudokaiState();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_BUDOKAI_STATE_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	CComboBox m_ctrState;
	CComboBox m_ctrMode;
};
