#pragma once


// PointShapeDlg ��ȭ �����Դϴ�.

class CPointShapeDlg : public CDialog
{
	DECLARE_DYNAMIC(CPointShapeDlg)

public:
	CPointShapeDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPointShapeDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_POINTSHAPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
