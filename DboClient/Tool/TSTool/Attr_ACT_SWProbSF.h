#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_SWProbSF ��ȭ �����Դϴ�.

class CAttr_ACT_SWProbSF : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_SWProbSF)

public:
	CAttr_ACT_SWProbSF();
	virtual ~CAttr_ACT_SWProbSF();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_SWPROBSF_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	float m_fProb;
	DWORD m_dwSuccessBID;
	DWORD m_dwFailBID;
};
