#pragma once

#include "resource.h"

// CSystemPane �� ���Դϴ�.

class CSystemPane : public CFormView
{
	DECLARE_DYNCREATE(CSystemPane)

protected:
	CSystemPane();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CSystemPane();

public:
	enum { IDD = IDD_SYSTEMPANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

	static CSystemPane* m_pInstance;
	static CSystemPane*	GetInstance()	{ return m_pInstance; }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	void	SetBackData( const TCHAR* pBackName, int nOffSetX, int nOffsetY );

	CString m_szBackName;				///< File Name
	CString m_szOffsetX;				///< Offset X
	CString m_szOffsetY;				///< Offset Y

	afx_msg void OnBnClickedSystemBackFind();
	afx_msg void OnBnClickedSystemApply();	
};

static CSystemPane* GetSystemPane()
{
	return CSystemPane::GetInstance();
}