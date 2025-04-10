#pragma once
#include "afxwin.h"


// CInstanceEffectDialog ��ȭ �����Դϴ�.

#include "Resource.h"

class CInstanceEffectDialog : public CDialog
{
	DECLARE_DYNAMIC(CInstanceEffectDialog)

public:
	CInstanceEffectDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInstanceEffectDialog();

	static CInstanceEffectDialog& GetInstance();

	void	BuildInstanceEffect();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_INSTANCE_EFFECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListBox m_EffectList;
	afx_msg void OnLbnSelchangeEffectList();
};
