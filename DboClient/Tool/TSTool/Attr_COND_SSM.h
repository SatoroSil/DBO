#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_COND_SSM ��ȭ �����Դϴ�.

class CAttr_COND_SSM : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_SSM)

public:
	CAttr_COND_SSM();
	virtual ~CAttr_COND_SSM();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_SSM_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	CComboBox m_ctrOPType;
	CComboBox m_ctrSSMId;
	DWORD m_dwValue;
};
