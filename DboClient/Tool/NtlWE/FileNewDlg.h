#pragma once
#include "afxwin.h"


// CFileNewDlg ��ȭ �����Դϴ�.

class CFileNewDlg : public CDialog
{
	DECLARE_DYNAMIC(CFileNewDlg)

public:
	CFileNewDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFileNewDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FILE_NEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	
private:
	void Update();

public:
	afx_msg void OnEnChangeWorldHeightFieldNum();
	afx_msg void OnEnChangeWorldSectorTileSize();
	afx_msg void OnEnChangeWorldSectorTileNum();
	afx_msg void OnEnChangeWorldFieldSectorNum();
	afx_msg void OnEnChangeWorldTexAddr();
	afx_msg void OnEnChangeWorldBlockSize();
	afx_msg void OnBnClickedLoadRaw();

	afx_msg void OnCbnSelchangeSkyType();
	afx_msg void OnCbnSelchangeWorldType();
	afx_msg void OnBnClickedOk();

public:
	CString				m_RAWFileName;
	CComboBox			m_SkyTypeIdxCombo;
	CComboBox			m_WorldTypeCombo;

	CEdit m_WorldHeightfieldNum;
	CEdit m_WorldSectorTileSize;
	CEdit m_WorldSectorTileNum;
	CEdit m_WorldFieldSectorNum;
	CEdit m_WorldTexAddr;
	CEdit m_WorldBlockSize;

	bool m_IsDialogInitialize;	
};