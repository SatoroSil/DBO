#pragma once


// CEffectEditLayer ���Դϴ�.
#include "RollupCtrl.h"

#include "NtlEffectDefine.h"
#include "NtlResourceComponentSystem.h"

class CEffectEditLayer : public CView
{
	DECLARE_DYNCREATE(CEffectEditLayer)

protected:
	CEffectEditLayer();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CEffectEditLayer();

public:
	BOOL					m_bInitialized;
	CRollupCtrl				m_RollupControl;

	enum EDIT_DIALOG
	{
		EDIT_DIALOG_EFFECT_LIST = 0x00,
		EDIT_DIALOG_ACTION_LIST,
		EDIT_DIALOG_PROPERTY,
	};


public:
	void	ResetTreeItemName(const RwChar* strName);
	void	ResetProperties();
	void	ResetPropertiesOnly();
	void	RebuildResourceEffect();
    RwBool  SaveXMLTree(RwChar* szFileName);

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};


