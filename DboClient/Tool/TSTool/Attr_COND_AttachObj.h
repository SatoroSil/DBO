#pragma once


#include "Attr_Page.h"


// CAttr_COND_AttachObj ��ȭ �����Դϴ�.

class CAttr_COND_AttachObj : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_AttachObj)

public:
	CAttr_COND_AttachObj(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_COND_AttachObj();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_ATTACH_OBJ_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_dwWorldIdx;
	CString m_strObjectIdx;
};
