#pragma once


// CSaberView1 ��ȭ �����Դϴ�.

class CSaberView1 : public CDialog
{
	DECLARE_DYNAMIC(CSaberView1)

public:
	CSaberView1(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSaberView1();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SABER_VIEW1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
