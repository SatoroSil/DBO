#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_COND_NPCDead ��ȭ �����Դϴ�.

class CAttr_COND_NPCDead : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_NPCDead)

public:
	CAttr_COND_NPCDead();
	virtual ~CAttr_COND_NPCDead();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_NPC_DEAD_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CString m_strNPCList;
};
