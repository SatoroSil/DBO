#pragma once
#include "afxwin.h"


// CAttrRenameDlg ��ȭ �����Դϴ�.

class CAttrRenameDlg : public CDialog
{
	DECLARE_DYNAMIC(CAttrRenameDlg)

public:
	CAttrRenameDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAttrRenameDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ATTR_RENAME };

	void	SetPrePosition( LPRECT rect );
	CRect	m_rect;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strRename;
public:
	virtual BOOL OnInitDialog();
};
