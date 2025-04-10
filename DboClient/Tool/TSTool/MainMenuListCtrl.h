#pragma once


#include "TSToolDefine.h"


// CMainMenuListCtrl ���Դϴ�.

class CMainMenuListCtrl : public CListCtrl
{
	DECLARE_DYNCREATE(CMainMenuListCtrl)

public:
	CMainMenuListCtrl();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CMainMenuListCtrl();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

protected:
	CArray< CString, const CString& >	m_aStringList;

public:
	void								Init( void );
	void								ClearAll( void );

	void								AddList( const CString& strName );

public:
	afx_msg BOOL						OnEraseBkgnd(CDC* pDC);
	afx_msg void						OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void						OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
};


