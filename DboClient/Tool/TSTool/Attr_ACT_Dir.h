#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_Dir ��ȭ �����Դϴ�.

class CAttr_ACT_Dir : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_Dir)

public:
	CAttr_ACT_Dir();
	virtual ~CAttr_ACT_Dir();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_DIR_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	DWORD m_dwRange;
	CComboBox m_ctrType;
	DWORD m_TblIdx;
};
