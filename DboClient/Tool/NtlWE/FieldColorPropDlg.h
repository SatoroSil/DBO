#pragma once


// CFieldColorPropDlg ��ȭ �����Դϴ�.

#include "colourpicker.h"

class CFieldColorPropDlg : public CDialog
{
	DECLARE_DYNAMIC(CFieldColorPropDlg)

public:
	CFieldColorPropDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFieldColorPropDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ATTR_FIELDCOLOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	void		 SetColor(int r, int g, int b);

	CString m_strColorR;
	CString m_strColorG;
	CString m_strColorB;
	COLORREF m_clrDiffuser;
	CColourPicker m_clrPicker;

protected:
	void		ApplyData(RwRGBA* pClr);

protected:
	RwRGBA		m_clr;
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedCancel();
};
