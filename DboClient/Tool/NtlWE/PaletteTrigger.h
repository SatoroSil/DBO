#pragma once


// CPaletteTrigger ��ȭ �����Դϴ�.

class CPaletteTrigger : public CDialog
{
	DECLARE_DYNAMIC(CPaletteTrigger)

public:
	CPaletteTrigger(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteTrigger();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TRIGGER };

public:
	void InitializeWorldData();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
