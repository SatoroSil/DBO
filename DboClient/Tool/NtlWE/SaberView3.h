#pragma once


// CSaberView3 ��ȭ �����Դϴ�.

class CSaberView3 : public CDialog
{
	DECLARE_DYNAMIC(CSaberView3)

public:
	CSaberView3(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSaberView3();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SABER_VIEW3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
