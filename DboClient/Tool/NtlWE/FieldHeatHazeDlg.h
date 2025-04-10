#pragma once
#include "afxcmn.h"


// CFieldHeatHazeDlg ��ȭ �����Դϴ�.

class CFieldHeatHazeDlg : public CDialog
{
	DECLARE_DYNAMIC(CFieldHeatHazeDlg)

public:
	CFieldHeatHazeDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFieldHeatHazeDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ATTR_FIELD_HEATHAZE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	void InitializeWorldData();

protected:
	void ApplyData(sNTL_HEATHAZE* pHeatHaze, RwBool bScrollUpdate = TRUE, RwBool bEditUpdate = TRUE);

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

protected:
	sNTL_HEATHAZE	m_sNtlHeatHaze;

public:
	CSliderCtrl m_SliderMps;
	CSliderCtrl m_SliderExtent;
	CSliderCtrl m_SliderScale;
	CSliderCtrl m_SliderExtentRand;
	CString m_StringMps;
	CString m_StringExtent;
	CString m_StringScale;
	CString m_StringExtentRand;

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
