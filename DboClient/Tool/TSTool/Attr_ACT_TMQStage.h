#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_TMQStage ��ȭ �����Դϴ�.

class CAttr_ACT_TMQStage : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_TMQStage)

public:
	CAttr_ACT_TMQStage();
	virtual ~CAttr_ACT_TMQStage();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_TMQ_STAGE_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	BYTE m_byStage;
};
