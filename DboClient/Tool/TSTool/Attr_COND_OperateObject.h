#pragma once


#include "Attr_Page.h"


// CAttr_COND_OperateObject ��ȭ �����Դϴ�.

class CAttr_COND_OperateObject : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_OperateObject)

public:
	CAttr_COND_OperateObject();
	virtual ~CAttr_COND_OperateObject();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_OPERATEOBJECT_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
};
