#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_COND_AvatarDead ��ȭ �����Դϴ�.

class CAttr_COND_AvatarDead : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_AvatarDead)

public:
	CAttr_COND_AvatarDead();
	virtual ~CAttr_COND_AvatarDead();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_AVATAR_DEAD_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
