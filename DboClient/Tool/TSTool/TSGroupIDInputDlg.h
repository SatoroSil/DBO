#pragma once


// CTSGroupIDInputDlg ��ȭ �����Դϴ�.

class CTSGroupIDInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CTSGroupIDInputDlg)

public:
	CTSGroupIDInputDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTSGroupIDInputDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_GROUP_ID_INPUT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	DWORD m_ctrGroupID;

	DWORD m_dwMin;
	DWORD m_dwMax;
};
