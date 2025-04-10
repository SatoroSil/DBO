#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_InSSM ��ȭ �����Դϴ�.

class CAttr_ACT_InSSM : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_InSSM)

public:
	CAttr_ACT_InSSM();
	virtual ~CAttr_ACT_InSSM();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_INSSM_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	CComboBox m_ctrSSMId;
	DWORD m_dwValue;
};
