#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_PCConv ��ȭ �����Դϴ�.

class CAttr_ACT_PCConv : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_PCConv)

public:
	CAttr_ACT_PCConv();
	virtual ~CAttr_ACT_PCConv();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_PCCONV_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	DWORD m_dwTblIdx;
};
