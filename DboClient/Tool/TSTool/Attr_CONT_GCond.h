#pragma once


#include "Attr_Page.h"


// CAttr_CONT_GCond ��ȭ �����Դϴ�.

class CAttr_CONT_GCond : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_CONT_GCond)

public:
	CAttr_CONT_GCond();
	virtual ~CAttr_CONT_GCond();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_CONT_GCOND_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_tcID;
	CButton m_ctrRewardMark;
};
