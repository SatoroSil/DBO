#pragma once


#include "Attr_Page.h"


// CAttr_COND_Item ��ȭ �����Դϴ�.

class CAttr_COND_Item : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_Item)

public:
	CAttr_COND_Item();
	virtual ~CAttr_COND_Item();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_ITEM_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_dwItemIdx;
	int m_nItemCnt;
};
