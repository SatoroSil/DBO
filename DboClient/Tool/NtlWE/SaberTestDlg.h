#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CSaberTestDlg ��ȭ �����Դϴ�.

class CSaberTestDlg : public CDialog
{
	DECLARE_DYNAMIC(CSaberTestDlg)

public:
	CSaberTestDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSaberTestDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SABER_TEST_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	void	InitializeWorldData();

protected:
	//void	TerrainTextrueCombine(RwUInt32 iSectorIdx);
	
public:	
	CString			m_strTest1;
	CString			m_strTest2;

	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

