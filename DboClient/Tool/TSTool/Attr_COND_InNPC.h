#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_COND_InNPC ��ȭ �����Դϴ�.

class CAttr_COND_InNPC : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_InNPC)

public:
	CAttr_COND_InNPC();
	virtual ~CAttr_COND_InNPC();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_INNPC_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_dwIndex;
	int m_nRadius;
};
