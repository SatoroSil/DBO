// TextureBuildDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"

#include "GlobalDef.h"
#include "FileTreeCtrl.h"

// CTextureBuildDlg ��ȭ ����
class CTextureBuildDlg : public CDialog
{
// �����Դϴ�.
public:
	CTextureBuildDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TEXTUREBUILD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.
	
// �����Դϴ�.
protected:
	HICON			m_hIcon;
	CFileTreeCtrl	m_treeFile;
	CProgressCtrl	m_proAllItems;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	afx_msg void OnNMClickTreeFile(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRclickTreeFile(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void On0Setuplevel0();
	afx_msg void On0Setuplevel1();
	afx_msg void On0Setuplevel2();
	afx_msg void On0Setuplevel3();
	afx_msg void On0Export();

	CFileTreeCtrl* GetTreeFile() { return &m_treeFile; }
	CProgressCtrl* GetProgressCtrl() { return &m_proAllItems; }
	afx_msg void On0Texturenum();
};
