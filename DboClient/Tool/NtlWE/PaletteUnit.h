#pragma once


// CPaletteUnit ��ȭ �����Դϴ�.

class CPaletteUnit : public CDialog
{
	DECLARE_DYNAMIC(CPaletteUnit)

public:
	CPaletteUnit(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteUnit();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_UNIT };

public:
	void InitializeWorldData();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
