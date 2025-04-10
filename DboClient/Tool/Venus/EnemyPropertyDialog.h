#pragma once


// CEnemyPropertyDialog ��ȭ �����Դϴ�.
#include "PropTree.h"

#include "rwcore.h"

class CEnemyPropertyDialog : public CDialog
{
	DECLARE_DYNCREATE(CEnemyPropertyDialog)

public:
	CEnemyPropertyDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEnemyPropertyDialog();

	void	ResetProperties(RwUInt32 nCurrentPoint = 0);
	void	ApplyProperties(CPropTreeItem* pItem);

public:
	BOOL						m_Initialized;
	CPropTree					m_PropertyTree;

	enum TIME_TYPE
	{
		TIME_TYPE_RESET_PROPERTIES = 0x00,
	};
	enum _PROPERTY_CONTROL_ID
	{
		_PROPERTY_CONTROL_NONE	= 0x00,

		_PROPERTY_CONTROL_CLUMP_NAME,
		_PROPERTY_CONTROL_IDLE_ANIMATION_NAME,
		_PROPERTY_CONTROL_DAMAGE_ANIMATION_NAME,

		_PROPERTY_CONTROL_EFFECT_NAME,

		_PROPERTY_CONTROL_ID_MAX_COUNT
	};
// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ENEMY_PROPERTY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnItemChanged(NMHDR* pNotifyStruct, LRESULT* plResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
