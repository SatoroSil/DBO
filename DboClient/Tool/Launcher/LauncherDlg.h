// LauncherDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "BitmapDlg.h"
#include "ImageTextButton.h"
#include "OutputBox.h"
#include "HTTPTransparent.h"

// CLauncherDlg ��ȭ ����
class CLauncherDlg : public CBitmapDlg
{
// �����Դϴ�.
public:
	CLauncherDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LAUNCHER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    
	DECLARE_MESSAGE_MAP()
public:
	int PatchManagerCallBack(unsigned int uiEventID, unsigned int pParam);
    virtual BOOL DestroyWindow();
    afx_msg void OnClose();
    afx_msg void OnBnClickedButtonGameStart();
    afx_msg void OnBnClickedButtonCancel();

protected:
	void AttachBackSlash( CString& strString );

public:
    COutputBox m_StaticFileDown;	
    COutputBox m_StaticInfoOutput;    
    COutputBox m_StaticLog;
    COutputBox m_StaticFIlePatch;

    int m_nIDProgress1;
    int m_nIDProgress2;
    int m_nDownValue;
    int m_nPatchValue;

	CImageTextButton m_ButtonGameStart;
	CImageTextButton m_ButtonCancel;

    CString m_strPatchVer;                          ///< ������� ��ġ�� Ŭ���̾�Ʈ ����
    CString m_strLauncherVer;                       ///< ��ó ����
	
	CHTTPTransparent m_ExplorerInformation;
};
