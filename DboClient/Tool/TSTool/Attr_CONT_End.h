#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_CONT_End ��ȭ �����Դϴ�.

class CAttr_CONT_End : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_CONT_End)

public:
	CAttr_CONT_End();
	virtual ~CAttr_CONT_End();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_CONT_END_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_tcID;
	CComboBox m_ctlEndType;
};
