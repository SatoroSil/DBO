#pragma once


#include "Attr_Page.h"


// CAttr_EVT_ClickMob ��ȭ �����Դϴ�.

class CAttr_EVT_ClickMob : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_EVT_ClickMob)

public:
	CAttr_EVT_ClickMob(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_EVT_ClickMob();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_EVT_CLICK_MOB_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	DWORD m_dwMobGroupIdx;
};
