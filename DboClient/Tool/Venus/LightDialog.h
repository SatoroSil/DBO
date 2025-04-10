#pragma once


// CLightDialog ��ȭ �����Դϴ�.

#include "MacSliderCtrl.h"
#include "MacButtons.h"
#include "ColorButton.h"

class CLightDialog : public CDialog
{
	DECLARE_DYNAMIC(CLightDialog)

public:
	int		m_nAmbientColorAll;
	int		m_nLightColorAll;

public:
	CLightDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLightDialog();

	static CLightDialog& GetInstance();

	void	InitSliderButton(CMacSliderCtrl* pSlider, int nStart, int nEnd, int nTic, COLORREF color);

	void	BuildData();
	void	BuildAmbientColor();

	void	BuildLightType();
	void	BuildLightColor();
	void	BuildLightRadius();
	void	BuildLightAngle();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LIGHT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CColorButton m_AmbientColor;
	CMacSliderCtrl m_AmbientColorR;
	CMacSliderCtrl m_AmbientColorG;
	CMacSliderCtrl m_AmbientColorB;
	CString m_strAmbientColorR;
	CString m_strAmbientColorG;
	CString m_strAmbientColorB;
	CComboBox m_LightType;
	CColorButton m_LightColor;
	CMacSliderCtrl m_LightColorR;
	CMacSliderCtrl m_LightColorG;
	CMacSliderCtrl m_LightColorB;
	CString m_strLightColorR;
	CString m_strLightColorG;
	CString m_strLightColorB;
	CMacSliderCtrl m_LightRadius;
	CString m_strLightRadius;
	CMacSliderCtrl m_LightAngle;
	CString m_strLightAngle;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCbnSelchangeLightType();
	afx_msg void OnBnClickedLightColor();
	afx_msg void OnBnClickedAbmientColor();
	CString m_strLightColorAll;
	CMacSliderCtrl m_LightColorAll;
	CMacSliderCtrl m_AmbientColorAll;
	CString m_strAmbientColorAll;
};
