#pragma once


// CPalettePerformanceImposter ��ȭ �����Դϴ�.

class CPalettePerformanceImposter : public CDialog
{
	DECLARE_DYNAMIC(CPalettePerformanceImposter)

public:
	CPalettePerformanceImposter(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPalettePerformanceImposter();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PERFORMANCE_IMPOSTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	void InitializeWorldData();
};
