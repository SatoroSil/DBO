#pragma once


// CPaletteRegion ��ȭ �����Դϴ�.

class CPaletteRegion : public CDialog
{
	DECLARE_DYNAMIC(CPaletteRegion)

public:
	CPaletteRegion(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteRegion();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_REGION };

public:
	void InitializeWorldData();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
