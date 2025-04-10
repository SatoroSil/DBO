#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_COND_ObjState ��ȭ �����Դϴ�.

class CAttr_COND_ObjState : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_ObjState)

public:
	CAttr_COND_ObjState();
	virtual ~CAttr_COND_ObjState();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_OBJSTATE_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_dwWorldIdx;
	DWORD m_dwObjectIdx;
	CComboBox m_ctrMainState;
	CComboBox m_ctrObjShowHide;
};
