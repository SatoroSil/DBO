#pragma once


#include "Attr_Page.h"


// CAttr_EVT_ColObject ��ȭ �����Դϴ�.

class CAttr_EVT_ColObject : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_EVT_ColObject)

public:
	CAttr_EVT_ColObject(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttr_EVT_ColObject();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_EVT_COL_OBJECT_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_dwWorldIdx;
	CString m_strObjectIdx;
};
