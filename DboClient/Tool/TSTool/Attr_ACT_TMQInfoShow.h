#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_TMQInfoShow ��ȭ �����Դϴ�.

class CAttr_ACT_TMQInfoShow : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_TMQInfoShow)

public:
	CAttr_ACT_TMQInfoShow();
	virtual ~CAttr_ACT_TMQInfoShow();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_TMQINFOSHOW_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	CComboBox m_ctrInfoType;
};
