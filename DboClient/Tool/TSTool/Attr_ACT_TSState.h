#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_TSState ��ȭ �����Դϴ�.

class CAttr_ACT_TSState : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_TSState)

public:
	CAttr_ACT_TSState();
	virtual ~CAttr_ACT_TSState();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_TSSTATE_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	CButton m_ctrTypeAddBtn;
	CButton m_ctrTypeRemoveBtn;
	CButton m_ctrTSFailed;
public:
	afx_msg void OnBnClickedTsActAttrTsstateTypeAddCheck();
public:
	afx_msg void OnBnClickedTsActAttrTsstateTypeRemoveCheck();
};
