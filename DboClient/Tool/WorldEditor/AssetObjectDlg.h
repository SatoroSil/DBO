#pragma once

#include "AssetObjectTreeCtrl.h"
#include "Resource.h"


// CAssetObjectDlg ��ȭ �����Դϴ�.

class CAssetObjectDlg : public CDialog
{
	DECLARE_DYNAMIC(CAssetObjectDlg)

public:

	CAssetObjectTreeCtrl	m_TreeCtrl;

public:
	CAssetObjectDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAssetObjectDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ASSETOBJECTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
