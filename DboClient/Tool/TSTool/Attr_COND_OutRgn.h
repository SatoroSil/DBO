#pragma once


#include "Attr_Page.h"


// CAttr_COND_OutRgn ��ȭ �����Դϴ�.

class CAttr_COND_OutRgn : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_COND_OutRgn)

public:
	CAttr_COND_OutRgn();
	virtual ~CAttr_COND_OutRgn();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_COND_OUTRGN_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_dwWorldTblIdx;
	FLOAT m_fX;
	FLOAT m_fZ;
	FLOAT m_fRadius;
};
