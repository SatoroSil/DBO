#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CPalettePlantDlg ��ȭ �����Դϴ�.

class CPalettePlantDlg : public CDialog
{
	DECLARE_DYNAMIC(CPalettePlantDlg)

public:
	CPalettePlantDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPalettePlantDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ORNAMENT_PLANT };

protected:
	virtual void	DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL	PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL		OnInitDialog();
	void				InitializeWorldData();
	void				SelectPlantSet(RwInt32 iIdx);
	void				SetBrushSize(RwReal fSize);
	void				SetClipDistance(RwReal fClipDistance);

	void				OnWork(RwV3d vCenter, RwReal fRadius, RwBool bIsCreate);

public:
	CListBox			m_PlantSetList;
	CString				m_strNumMin;
	CString				m_strNumMax;
	CString				m_strScaleMin;
	CString				m_strScaleMax;
	CString				m_strRotationTerrain;
	CListBox			m_PlantSetResList;
	CString				m_strBrushSize;
	CSliderCtrl			m_BrushSizeSlider;
	CString				m_strClipDistance;
	CSliderCtrl			m_ClipDistanceSlider;

public:
	afx_msg void OnLbnSelchangePlantSetListbox();
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
public:
};
