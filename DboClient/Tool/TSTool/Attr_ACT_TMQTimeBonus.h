#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_TMQTimeBonus ��ȭ �����Դϴ�.

class CAttr_ACT_TMQTimeBonus : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_TMQTimeBonus)

public:
	CAttr_ACT_TMQTimeBonus();
	virtual ~CAttr_ACT_TMQTimeBonus();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_TMQTIMEBONUS_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	int m_nBonusTime;
};
