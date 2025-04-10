#pragma once

#include "PropertyListCtrl.h"
#include "PropertyAnimData.h"
#include "ToolData.h"

// CAnimAssetAnimSetDlg ��ȭ �����Դϴ�.

class CAnimationSetDialog : public CDialog
{
	DECLARE_DYNAMIC(CAnimationSetDialog)

public:
	CAnimationSetDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAnimationSetDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ANIMASSETANIMSETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CPropertyListCtrl	m_propertyControl;

	CPropertyAnimData	m_propertyAnimData;
	CAnimAdaptablePropertyItemManager m_propertyAnimDataManager;
	virtual BOOL OnInitDialog();
	void UpdateTree();
	void SetAnimDataInfoChange(SToolAnimData *pToolAnimData);
	void SetAnimationFileOpen(SToolAnimData *pToolAnimData);
};
