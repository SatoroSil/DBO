#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_TelMinorMatch ��ȭ �����Դϴ�.

class CAttr_ACT_TelMinorMatch : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_TelMinorMatch)

public:
	CAttr_ACT_TelMinorMatch();
	virtual ~CAttr_ACT_TelMinorMatch();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_DIR_ATTR_TEL_MINOR_MATCH };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
};
