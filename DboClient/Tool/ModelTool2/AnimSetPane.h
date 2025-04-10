#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "NtlPLCharacterParser.h"
#include "NtlPLItemParser.h"



// CAnimSetPane form view

class CAnimSetPane : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CAnimSetPane)

public:
    enum EAnimSet
    {
        COMMON_ANIM_SET = 0,
        ATTACK_ANIM_SET,
        BATTLE_ANIM_SET,
        SKILL_ANIM_SET,
        HTB_ANIM_SET,
        SOCIAL_ANIM_SET,
        TRIGGER_ANIM_SET,
        TRANSFORM_ANIM_SET,
        VEHICLE_SRP1_ANIM_SET,
        VEHICLE_SRP2_ANIM_SET,
        ITEM_USE_ANIM_SET,
        ITEM_ANIM_SET = 0,	        
    };

    /// AnimSet Pane�� ���
    enum EAnimSetMode
    {
        ANIMSET_CHARACTER,      ///< ĳ���� �ִϸ��̼� ���� ���
        ANIMSET_ITEM,           ///< Item �ִϸ��̼� ���� ���
		ANIMSET_OBJECT,			///< Object Animation ���� ��� (Ʈ���� Object ��)
        ANIMSET_VEHICLE,        ///< Ż�� �ִϸ��̼� ����
    };

protected:
	CAnimSetPane();           // protected constructor used by dynamic creation
	virtual ~CAnimSetPane();

public:
	enum { IDD = IDD_ANIMSETPANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

public:
    static CAnimSetPane* GetInstance() {return m_pInstance;};
    void    SetModel(CNtlPLAttach* pModel);         ///< ����� ���� �����Ѵ�.
    
    void    SetEnable(BOOL bEnable);                    ///< UI Ȱ��ȭ ������ �����Ѵ�
    void    SetAnimData(RwUInt32 uiKey);                ///< �ִϸ��̼��� �����Ѵ�.
    EAnimSet GetAnimSetMode() {return (EAnimSet)m_cbAnimSet.GetCurSel();} ///< ���� �������� Animation Set�� ��ȯ�Ѵ�.

protected:
    static CAnimSetPane* m_pInstance;

    EAnimSetMode         m_eAnimSetMode;                ///< ���� AnimSet Pane�� ���

    // Character ����
    CMTCharacter*        m_pCharacter;                  ///< ���� ������ ĳ���� ��ü
    CNtlTypeAnimTable*   m_pAnimTable;                  ///< Edit�� ����� AnimTable;
    CNtlPLCharacterParser   m_CharacterPaser;           ///< ĳ���� �ļ� (�ִϸ��̼� Set ������ ���)

    // Item ����
    CMTItem*             m_pItem;                       ///< ���� ������ ������ ��ü
    CNtlPLItemParser     m_ItemParser;                  ///< ������ �ļ�

	// Object ����
	CMTObject*			 m_pObject;

protected:
	DECLARE_MESSAGE_MAP()

public:
    virtual void OnInitialUpdate();
    afx_msg void OnCbnSelchangeCbAnimSet();
    afx_msg void OnLvnItemchangedLtAnimItem(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnNMRclickLtAnimItem(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnMenuAnimSet();
    afx_msg void OnMenuAnimDelete();

protected:
    CComboBox m_cbAnimSet;
    CListCtrl m_ltAnimItem;
};


