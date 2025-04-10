#pragma once

#include "NtlWorldPropMaterialController.h"

// MaterialPropDlg ��ȭ �����Դϴ�.

class CMaterialPropDlg : public CDialog
{
	DECLARE_DYNAMIC(CMaterialPropDlg)

private: // user
	enum eWORK 
	{
		eWORK_UPDATE_ALL,
		eWORK_DELETE_ALL,
		eWORK_UPDATE,
		eWORK_DELETE,
		eWORK_EXPORT,
	};

	CNtlWorldPropMaterialController* m_pNtlWorldPropMaterialController;

private:
	void WorkProc(eWORK eWork);

public: // sys
	CMaterialPropDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMaterialPropDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MATERIAL_PROP };

protected:
	virtual void	DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual LRESULT	WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedExport();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedAllDelete();
	afx_msg void OnBnClickedAllUpdate();
};
