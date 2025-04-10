#pragma once


// CEffectListCtrl

#include "VenusGridCtrl.h"
#include "NtlResourceEffect.h"
#include "NtlResourceComponentSystem.h"
#include "NtlTreeXml.h"

// Ʈ�� ������ ����
enum ETreeItemLevel
{
    E_ITEM_LEVEL_FOLDER,
    E_ITEM_LEVEL_EFFECT,
    E_ITEM_LEVEL_SYSTEM,
    E_ITEM_LEVEL_INVALID,
};

class CEffectListCtrl : public CVenusGridCtrl
{
//	DECLARE_DYNAMIC(CEffectListCtrl)

protected:
	CImageList m_image;//Must provide an imagelist
public:
	enum IMAGE_INDEX
	{
		IMAGE_INDEX_RESOURCE_FOLDER = 0x00,
		IMAGE_INDEX_RESOURCE_PARTICLE,
		IMAGE_INDEX_RESOURCE_MESH,
		IMAGE_INDEX_RESOURCE_BEAM,
		IMAGE_INDEX_RESOURCE_HURRICANE,
		IMAGE_INDEX_RESOURCE_LIGHTNING,
		IMAGE_INDEX_RESOURCE_DECAL,
		IMAGE_INDEX_RESOURCE_POST_EFFECT,
        IMAGE_INDEX_RESOURCE_TRACE,
        IMAGE_INDEX_RESOURCE_LINE,
        IMAGE_INDEX_RESOURCE_EFFECT,

		IMAGE_INDEX_RESOURCE_MAX_COUNT,
	};

public:
	CEffectListCtrl();
	virtual ~CEffectListCtrl();

	void	InitializeGrid();

	RwInt32 GetImageIndexFromSystemType(RwInt32 nSystemType);
	void	RebuildResourceEffect();
    RwBool  SaveXMLTree(RwChar* szFileName);                                        ///< ����Ʈ Ʈ���� XML ���Ϸ� �����Ѵ�.

	CNtlResourceEffect*				GetRootResourceEffect();
	CNtlResourceEffect*				GetSelectResourceEffect();
	CNtlResourceComponentSystem*	GetSelectResourceSystem();
    void							ResetTreeItemName(const RwChar* strName);

	void							GetSelectResourceData(CNtlResourceEffect*& pResourceEffect, CNtlResourceComponentSystem*& pResourceSystem);
	void							CreateResourceSystem(RwInt32 nType, CNtlResourceComponentSystem* pSrcResourceSystem = NULL);
    void                            DeleteItemEx(CTreeItem *pSelItem, int nItem, BOOL bUpdate = TRUE);

    // �̺�Ʈ ó��
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnCreateEffect();
	afx_msg void OnDeleteEffect();
	afx_msg void OnDeleteSystem();
	afx_msg void OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTestEffect();
	afx_msg void OnCreateParticleSystem();
	afx_msg void OnCreateMeshSystem();
	afx_msg void OnCreateBeamSystem();
	afx_msg void OnCreateHurricaneSystem();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCreateLightningSystem();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLvnColumnclick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCreateDecalSystem();
	afx_msg void OnCreatePostEffectSystem();
    afx_msg void OnCreateTraceEffectSystem();
    afx_msg void OnCreateLineSystem();
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnCreateFolder();
    afx_msg void OnDeleteFolder();
    afx_msg void OnRenameFolder();
    afx_msg void OnLvnBegindrag(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnNMReleasedcapture(NMHDR *pNMHDR, LRESULT *pResult);

protected:
    DECLARE_MESSAGE_MAP()
    void                SetAllChildCheck();                                         ///< ��� �ڽ� Node�鵵 ���� Check/UnCheck�ϰ� �����.
    ETreeItemLevel		GetTreeItemLevel(CTreeItem* pItem);

    RwBool  LoadXMLTree();                                                          ///< XML Tree������ �о���δ�.    
    void    CreateDefaultXMLTree();                                                 ///< �⺻ Tree ������ �����.
    void    InsertItemRecursive(SItemNode* pItemNode, CSuperGridCtrl::CTreeItem* pParentItem, RwBool bUpdate);
    void    DeleteItemRecursive(SItemNode* pItemNode);                              ///< ���� �����۵��� ���� �����Ѵ� (����Ʈ ������Ƽ ����)    
    void    BuildChildScript(CTreeItem* pParentItem);                               ///< �ڽ� �����۵��� �����Ѵ�.
    
public:
    std::string			m_strInstanceEffectName;
    BOOL				m_bSequence;

protected:
    SItemNode           m_sItemNode;       
    CTreeItem*          m_pCopyResourceFolder;  ///< ������ ī��&���̽�Ʈ�� ���� ������
    RwBool              m_bDrag;                ///< �巡�׿� ��������� �Ǵ� �÷���           
    RwBool              m_bNotSelChange;        ///< SelChange Event�� �߻���Ű�� ������켼 ����ϴ� �÷���(Ex.Sort)

};


