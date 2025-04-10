#pragma once


// CEventLayer ���Դϴ�.
#include "RollupCtrl.h"

class CEventLayer : public CView
{
	DECLARE_DYNCREATE(CEventLayer)

protected:
	CEventLayer();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CEventLayer();

public:
	BOOL					m_bInitialized;
	CRollupCtrl				m_RollupControl;

	enum EDIT_DIALOG
	{
		EDIT_DIALOG_PLAYER_EVENT_LIST = 0x00,
		EDIT_DIALOG_ENEMY_PROPERTY,
		EDIT_DIALOG_AVATAR_PROPERTY,
	};

public:
	void	ResetProperties();
	void	ResetPropertiesEnemy();
	void	ResetPropertiesAvatar();

	void	ResetTreeItemName(const RwChar* strName);
	void	ResetAnimationTime(RwReal fCurrentTime, RwUInt32 nMaxTime);

	void	BuildData();

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


