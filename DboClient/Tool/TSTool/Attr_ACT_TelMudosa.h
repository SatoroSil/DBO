#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_TelMudosa ��ȭ �����Դϴ�.

class CAttr_ACT_TelMudosa : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_TelMudosa)

public:
	CAttr_ACT_TelMudosa();
	virtual ~CAttr_ACT_TelMudosa();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_DIR_ATTR_TEL_MUDOSA };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
};
