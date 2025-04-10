#pragma once
#include "afxwin.h"
#include "NtlWorldFileMemAccessor.h"



// CFieldsInformation ��ȭ �����Դϴ�.

//////////////////////////////////////////////////////////////////////////
// dNTL_WORLD_FILE : DEFINE
//////////////////////////////////////////////////////////////////////////
#ifdef dNTL_WORLD_FILE

class CFieldsInformation : public CDialog
{
	DECLARE_DYNAMIC(CFieldsInformation)

public:
	CFieldsInformation(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFieldsInformation();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FIELD_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CListBox	m_Fields;
	CEdit		m_Information;
	CString		m_StrBGMName;
	CString		m_StrEnvName;
	CString		m_StrNMapSpec;
	CString		m_MapName;
	CString		m_MobSpawn;
	CString		m_Trigger;
	CString		m_Result;

public:
	VOID RefreshInfo(RwInt32 FieldIdx);

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	afx_msg void OnLbnSelchangeFiFields();
};

//////////////////////////////////////////////////////////////////////////
// dNTL_WORLD_FILE : DEFINE
//////////////////////////////////////////////////////////////////////////
#else

class CFieldsInformation : public CDialog, public CNtlWorldFileMemAccessor
{
	DECLARE_DYNAMIC(CFieldsInformation)

public:
	CFieldsInformation(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFieldsInformation();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FIELD_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CListBox	m_Fields;
	CEdit		m_Information;
	CString		m_StrBGMName;
	CString		m_StrEnvName;
	CString		m_StrNMapSpec;
	CString		m_MapName;
	CString		m_MobSpawn;
	CString		m_Trigger;
	CString		m_Result;

public:
	VOID RefreshInfo(RwInt32 FieldIdx);

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	afx_msg void OnLbnSelchangeFiFields();
};

//////////////////////////////////////////////////////////////////////////
// dNTL_WORLD_FILE : DEFINE
//////////////////////////////////////////////////////////////////////////
#endif