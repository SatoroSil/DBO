#pragma once

#include "CustomItems.h"
#include "afxwin.h"

// CPointCustomEditDlg ��ȭ �����Դϴ�.

class CPointCustomEditDlg : public CDialog
{
	DECLARE_DYNAMIC(CPointCustomEditDlg)

public:
	CPointCustomEditDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPointCustomEditDlg();

	INT							m_nCurveNum;
	INT							m_nSelIdx;
	CRect						m_rtCurveArea;

	CRect	GetCurveRect(INT nIdx);

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_POINTCUSTOMEDIT };

public:

	void		InData(void);
	void		OutData(void);

	void		OnPropUpdate(void);
	void		OnPropSelectUpdate(int nSx, int nEx);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnAttributeNotify(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnPaint();
public:
	afx_msg void OnDestroy();
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
	CButton m_btnLoop;
public:
	CEdit m_editFileName;
public:
	afx_msg void OnBnClickedCusveSoundLoop();
public:
	afx_msg void OnEnChangeCusveSoundFilename();
public:
	afx_msg void OnBnClickedCusveSoundClear();
};

