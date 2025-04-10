#pragma once


#include "Attr_Page.h"
#include "afxwin.h"


// CAttr_ACT_OperateObject ��ȭ �����Դϴ�.

class CAttr_ACT_OperateObject : public CAttr_Page
{
	DECLARE_SERIAL(CAttr_ACT_OperateObject)

public:
	// ���� ������ ���� true�� ����, 
	// false�� ����� ���Ǽ� �Ʒ��� ���� ���߾� ������.
	enum
	{
		eOPERATEOBJECT_TYPE_END,
		eOPERATEOBJECT_TYPE_START
	};

public:
	CAttr_ACT_OperateObject();
	virtual ~CAttr_ACT_OperateObject();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TS_ACT_OPERATEOBJECT_ATTR_DIAG };

	virtual CString	GetPageData( void );
	virtual void	UnPakingPageData( CString& strKey, CString& strValue );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_taID;
	CComboBox m_ctrTypeCtrl;
	DWORD m_dwOperateTime;
	DWORD m_dwDirectionTblIdx;
};
