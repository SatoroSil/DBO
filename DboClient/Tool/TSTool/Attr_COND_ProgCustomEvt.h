#pragma once


#include "Attr_Page.h"


// CAttr_COND_ProgCustomEvt ��ȭ �����Դϴ�.

class CAttr_COND_ProgCustomEvt : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_ProgCustomEvt)

public:
	CAttr_COND_ProgCustomEvt();
	virtual ~CAttr_COND_ProgCustomEvt();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_PROGCUSTOMEVT_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_dwQuestID;
};
