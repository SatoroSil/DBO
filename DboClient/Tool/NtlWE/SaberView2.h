#pragma once


// CSaberView2 ��ȭ �����Դϴ�.

class CSaberView2 : public CDialog
{
	DECLARE_DYNAMIC(CSaberView2)

public:
	CSaberView2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSaberView2();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SABER_VIEW2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
