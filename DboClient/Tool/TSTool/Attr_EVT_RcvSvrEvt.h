#pragma once


#include "Attr_Page.h"


// CAttr_EVT_RcvSvrEvt ��ȭ �����Դϴ�.

class CAttr_EVT_RcvSvrEvt : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_EVT_RcvSvrEvt)

public:
	CAttr_EVT_RcvSvrEvt(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_EVT_RcvSvrEvt();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_EVT_RCV_SVR_EVT_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	DWORD m_dwEvtID;
};
