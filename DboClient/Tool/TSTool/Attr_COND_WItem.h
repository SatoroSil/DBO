#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_COND_WItem ��ȭ �����Դϴ�.

class CAttr_COND_WItem : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_WItem)

public:
	CAttr_COND_WItem();
	virtual ~CAttr_COND_WItem();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_WITEM_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_dwItemIdx;
};
