#pragma once
#include "afxwin.h"


// WeatherDlg ��ȭ �����Դϴ�.

class CWeatherDlg : public CDialog
{
	DECLARE_DYNAMIC(CWeatherDlg)

public:
	CWeatherDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CWeatherDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ATTR_WEATHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();

public:
	CComboBox m_cbWeather[5];

protected:
	void	SelectCbWeather(sNTL_FIELD_PROP* pNtlFieldProp);
	RwBool	UpdateCbWeather();
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRefresh();
};
