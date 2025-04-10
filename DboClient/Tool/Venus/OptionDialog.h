#pragma once
#include "afxcmn.h"


// COptionDialog ��ȭ �����Դϴ�.

#include "Resource.h"

#include "MacSliderCtrl.h"
#include "ColorButton.h"
#include "afxwin.h"

class COptionDialog : public CDialog
{
	DECLARE_DYNAMIC(COptionDialog)

public:
	COptionDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COptionDialog();

	static COptionDialog& GetInstance();


	void	BuildGridWidth();
	void	BuildGridCount();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_OPTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CMacSliderCtrl m_GridWidthSlider;
	CMacSliderCtrl m_GridCountSlider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	float m_fObjectMoveSpeed;
	float m_fObjectRotateSpeed;
	float m_fObjectScaleSpeed;
	CMacSliderCtrl m_ObjectMoveSpeedSlider;
	CMacSliderCtrl m_ObjectRotateSpeedSlider;
	CMacSliderCtrl m_ObjectScaleSpeedSlider;
	CMacSliderCtrl m_CameraMoveSpeedSlider;
	CMacSliderCtrl m_CameraRotateSpeedSlider;
	CMacSliderCtrl m_CameraWheelSpeedSlider;
	float m_fCameraMoveSpeed;
	float m_fCameraRotateSpeed;
	float m_fCameraWheelSpeed;
	CColorButton m_BackGroundButton;
	afx_msg void OnBnClickedBackground();
	CString m_strGridWidth;
	CString m_strGridCount;
};
