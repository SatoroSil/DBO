#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_TObjFriendly ��ȭ �����Դϴ�.

class CAttr_ACT_TObjFriendly : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_TObjFriendly)

public:
	CAttr_ACT_TObjFriendly();
	virtual ~CAttr_ACT_TObjFriendly();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_TBOJ_FRIENDLY_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CButton m_ctrPC;
	CButton m_ctrNPC;
	CButton m_ctrMOB;
	CMap<int, const int&, CButton*, CButton*> m_ButtonMap;
};
