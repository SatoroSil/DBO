#pragma once


#include "Attr_Page.h"


// CAttr_EVT_SlotMachine ��ȭ �����Դϴ�.

class CAttr_EVT_SlotMachine : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_EVT_SlotMachine)

public:
	CAttr_EVT_SlotMachine(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_EVT_SlotMachine();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_EVT_SLOTMACHINE_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
