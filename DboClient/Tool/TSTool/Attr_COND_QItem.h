#pragma once


#include "Attr_Page.h"


// CAttr_COND_QItem ��ȭ �����Դϴ�.

class CAttr_COND_QItem : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_QItem)

public:
	CAttr_COND_QItem();
	virtual ~CAttr_COND_QItem();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_QITEM_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	CComboBox m_ctrlCheckType;
	DWORD m_dwItemIdx;
	int m_nItemCnt;
};
