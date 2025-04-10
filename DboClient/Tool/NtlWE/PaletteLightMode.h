#pragma once

#include "NtlPLLightObject.h"
#include "NtlWorldRpLightManager.h"

#include "colourpicker.h"
#include "afxwin.h"

class CPaletteLightMode : public CDialog
{
	DECLARE_DYNAMIC(CPaletteLightMode)

public:
	CPaletteLightMode(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteLightMode();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LIGHT_MODE };

protected:
	virtual void			DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

protected:
	virtual LRESULT			WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

public:
	virtual BOOL			PreTranslateMessage(MSG* pMsg);

public:
	VOID					InitializeWorldData();

public:
	afx_msg void			OnLbnSelchangeListLight();

public:
	// pEntity ������ Dlg Data�� �����Ѵ�.
	void					UpdatePropertyData(SLightModeData* pLightModeData);

	// Dlg Data�� �����Ѵ�.
	void					EnableDlg(RwBool bEnable);
	void					SetLightData(RwInt32 iIdx);
	void					SetColorData(RwUInt8 r, RwUInt8 g, RwUInt8 b);
	void					SetRotationData(RwReal x, RwReal y, RwReal z);

	// Entity�� Dlg ������ �����Ѵ�.
	void					ApplyColor();
	void					ApplyRotate();

	void					Render();
	SLightModeData*			Pick();

	void					InitLightModeData();
	void					GetLightModeDataReal();
	void					GetLightModeDataDummy();
	void					SetLightModeDataReal();
	void					SetLightModeDataDummy();
	void					MoveCameraAtLightModeData();


public:
	void					SetColor(int r, int g, int b);
	CColourPicker			m_clrPicker;
	COLORREF				m_clrDiffuser;

public:
	CListBox				m_LightType;
	CString					m_strColorR;
	CString					m_strColorG;
	CString					m_strColorB;
	CString					m_strRotX;
	CString					m_strRotY;
	CString					m_strRotZ;

	SLightModeData	m_sLightModeData[3];
	SLightModeData*	m_pLightModeCur;
	SLightModeData*	m_pLightModeSel;

public:
	SLightModeData*			SetCurLightData(SLightModeData*	pLightModeCur)	{ return m_pLightModeCur = pLightModeCur; }
	SLightModeData*			GetCurLightData()								{ return m_pLightModeCur; }
	SLightModeData*			GetSelLightData()								{ return m_pLightModeSel; }

	void					UpdateRpLight(SLightModeData* pLightModeData);

	afx_msg void			OnBnClickedButtonGet();
	afx_msg void			OnBnClickedButtonSet();
	afx_msg void			OnBnClickedRadioReal();
	afx_msg void			OnBnClickedRadioDummy();
};
