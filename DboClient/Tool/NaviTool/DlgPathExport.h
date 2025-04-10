#pragma once
#include <list>
#include "afxcmn.h"
#include "afxwin.h"
#include "EditListCtrl.h"
#include "NtlNaviDefine.h"

// CDlgPathExport ��ȭ �����Դϴ�.

class CDlgPathExport : public CDialog
{
	DECLARE_DYNAMIC(CDlgPathExport)

public:
	CDlgPathExport(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgPathExport();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_EXPORT_PATHDATA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

public:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL GetExportList( mapdef_ExportList& list );

protected:
	CEditListCtrl		m_editListCtrlExport;
	mapdef_ExportList	m_mapExportList;

public:
	afx_msg void OnBnClickedBtnPathExportAll();
	afx_msg void OnBnClickedBtnPathExportSelect();
};
