#pragma once


#include "Attr_Page.h"


// CAttr_ACT_OPCam ��ȭ �����Դϴ�.

class CAttr_ACT_OPCam : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_OPCam)

public:
	CAttr_ACT_OPCam();
	virtual ~CAttr_ACT_OPCam();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_OPCAM_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	CString m_strFuncName;
};
