#pragma once


#include "Attr_Page.h"


// CAttr_Group ��ȭ �����Դϴ�.

class CAttr_Group : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_Group)

public:
	CAttr_Group(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_Group();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_GROUP_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	DWORD m_tgID;
};
