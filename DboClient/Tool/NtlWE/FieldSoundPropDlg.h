#pragma once
#include "afxwin.h"

#define dFSP_EXPORT_SOUND_BGM	0x00000001
#define dFSP_EXPORT_SOUND_ENV	0x00000002
#define dFSP_EXPORT_SOUND_SHARE	0x00000003


// CFieldSoundPropDlg ��ȭ �����Դϴ�.

class CFieldSoundPropDlg : public CDialog
{
	DECLARE_DYNAMIC(CFieldSoundPropDlg)

public:
	CFieldSoundPropDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFieldSoundPropDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ATTR_FIELD_SOUND };

protected:
	virtual void			DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL			OnInitDialog();

	afx_msg void			OnBnClickedOk();
	afx_msg void			OnBnClickedCancel();
	afx_msg void			OnBnClickedButtonExportBgm();
	afx_msg void			OnBnClickedButtonExportEnv();
	afx_msg void			OnBnClickedButtonExportShare();

public:
	void					SetBGMData(RwInt32 iIdx);
	void					SetENVData(RwInt32 iIdx);
	void					SetShareData(RwInt32 iArrayIdx, RwInt32 iIdx);

	void					ExportFieldSound(RwUInt32 iExportType, RwInt32 iIdx);

public:
	CComboBox				m_cbBGMSound;
	CComboBox				m_cbENVSound;
	CComboBox				m_cbShareSound[5];	
	
};
