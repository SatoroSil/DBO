#pragma once


#include "Attr_Page.h"


// CAttr_EVT_ItemGet ��ȭ �����Դϴ�.

class CAttr_EVT_ItemGet : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_EVT_ItemGet)

public:
	CAttr_EVT_ItemGet(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_EVT_ItemGet();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_EVT_ITEM_GET_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	DWORD m_dwItemIdx;
};
