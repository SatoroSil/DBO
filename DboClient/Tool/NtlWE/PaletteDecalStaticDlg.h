#pragma once


// PaletteDecalStaticDlg ��ȭ �����Դϴ�.

class CPaletteDecalStaticDlg : public CDialog
{
	DECLARE_DYNAMIC(CPaletteDecalStaticDlg)

public:
	CPaletteDecalStaticDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteDecalStaticDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ORNAMENT_DECAL_STATIC };

protected:
	virtual void		DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual LRESULT		WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL		PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()

public:
	void				InitializeWorldData();

public:
	virtual BOOL		OnInitDialog();
	afx_msg void		OnBnClickedOk();
};
