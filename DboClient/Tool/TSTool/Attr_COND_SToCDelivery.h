#pragma once


#include "Attr_Page.h"


// CAttr_COND_SToCDelivery ��ȭ �����Դϴ�.

class CAttr_COND_SToCDelivery : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_SToCDelivery)

public:
	CAttr_COND_SToCDelivery();
	virtual ~CAttr_COND_SToCDelivery();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_STOC_DELIVERY_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_dwItemIdx0;
	int m_nItemCnt0;
	DWORD m_dwItemIdx1;
	int m_nItemCnt1;
	DWORD m_dwItemIdx2;
	int m_nItemCnt2;
};
