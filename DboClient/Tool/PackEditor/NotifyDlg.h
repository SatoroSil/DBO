#pragma once


// CNotifyDlg ��ȭ �����Դϴ�.

class CNotifyDlg : public CDialog
{
	DECLARE_DYNAMIC(CNotifyDlg)

public:
	CNotifyDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CNotifyDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_NOTIFY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
