#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_COND_DistNPC ��ȭ �����Դϴ�.

class CAttr_COND_DistNPC : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_DistNPC)

public:
	CAttr_COND_DistNPC();
	virtual ~CAttr_COND_DistNPC();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_DIST_NPC_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	float m_fDistance;
	CString m_strNPCList;
};
