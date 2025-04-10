#pragma once
#include "afxcmn.h"


// CPaletteLightAndShadow ��ȭ �����Դϴ�.

class CPaletteLightAndShadow : public CDialog
{
	DECLARE_DYNAMIC(CPaletteLightAndShadow)

public:
	CPaletteLightAndShadow(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteLightAndShadow();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LIGHT_SHADOW };
	enum ETAB_ID
	{
		ETAB_ID_NONE = -1,
		ETAB_ID_SHADOW = 0,
		// CZ-SS
		//ETAB_ID_SOFT_SPOT,
		ETAB_ID_WORLD_LIGHT,
		ETAB_ID_LIGHT,
		ETAB_ID_LIGHT_MODE,

		ETAB_ID_NUM,
	};
protected:
	ETAB_ID m_eTabID[ETAB_ID_NUM];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CTabCtrl m_TabCtrl;

protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

public:
	void			InitializeWorldData();
	void			CreateWorldLightByLightObject(CNtlPLEntity* pPLEntity);

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTcnSelchangeSalTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTcnSelchangingSalTab(NMHDR *pNMHDR, LRESULT *pResult);
};
