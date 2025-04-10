#pragma once
#include "afxcmn.h"


// CEffectListDialog ��ȭ �����Դϴ�.

#include "EffectListCtrl.h"
#include "afxwin.h"

class CEffectListDialog : public CDialog
{
	DECLARE_DYNCREATE(CEffectListDialog)

public:
	CEffectListDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEffectListDialog();

public:
	BOOL					m_Initialized;
	CEffectListCtrl			m_List;

public:
	void	ResetTreeItemName(const RwChar* strName);
	void	RebuildResourceEffect();
    RwBool  SaveXMLTree(RwChar* szFileName);


// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EFFECT_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);	
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

protected:
    CStatic m_EffectFrame;                              /// ������ ����Ʈ ��Ʈ�� ��ġ�� ������� ���� ��Ʈ��
};
