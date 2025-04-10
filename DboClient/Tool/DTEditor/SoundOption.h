#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CSoundOption ��ȭ �����Դϴ�.

class CSoundOption : public CDialog
{
	DECLARE_DYNAMIC(CSoundOption)

public:
	CSoundOption(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSoundOption();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SOUND_OPTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:	
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClicked_CheckBgm();
	afx_msg void OnBnClicked_CheckWeatherEffect();
	afx_msg void OnBnClicked_CheckWeatherMusic();
	afx_msg void OnBnClicked_OK();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

protected:
	CButton			m_BtnCheckBGMMute;
	CButton			m_BtnCheckWeatherEffect;
	CButton			m_BtnCheckWeatherMusic;
	CSliderCtrl		m_ScrollbarBGMVolume;
	CSliderCtrl		m_ScrollbarWeatherEffect;
	CSliderCtrl		m_ScrollbarWeatherMusic;
};