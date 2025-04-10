#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_Portal ��ȭ �����Դϴ�.

class CAttr_ACT_Portal : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_Portal)

public:
	CAttr_ACT_Portal();
	virtual ~CAttr_ACT_Portal();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_POTRAL_ATTR };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	CComboBox m_ctrPortalType;
	DWORD m_dwWIdx;
	CString m_strPosX, m_strPosY, m_strPosZ;
	CString m_strDirX, m_strDirY, m_strDirZ;
};
