#pragma once


#include "Attr_Page.h"
#include "resource.h"


// CAttr_Link ��ȭ �����Դϴ�.

class CAttr_Link : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_Link)

public:
	CAttr_Link(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_Link();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_LINK };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_uiBranchName;
};
