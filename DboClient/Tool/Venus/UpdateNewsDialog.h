#pragma once
#include "afxwin.h"


// CUpdateNewsDialog ��ȭ �����Դϴ�.

class CUpdateNewsDialog : public CDialog
{
	DECLARE_DYNAMIC(CUpdateNewsDialog)

public:
	CUpdateNewsDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUpdateNewsDialog();

	static CUpdateNewsDialog& GetInstance();

	BOOL	m_bInitialized;

	void	LoadUpdateNews();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_UPDATE_NEWS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_UpdateNews;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
