#pragma once
#include "stdafx.h"
#include "afxwin.h"
#include "NtlPLCharacterParser.h"
#include "afxcmn.h"

typedef std::map<int, std::string> MapAnimFile;

// CRightToolView form view

class CRightToolView : public CFormView
{
public:
    enum EAnimSet
    {
        COMMON_ANIM_SET,
        ATTACK_ANIM_SET,
        BATTLE_ANIM_SET,
        SKILL_ANIM_SET,
    };

    enum ECtrlEnable
    {
        DISABLE_ALL,
        ENABLE_ANIMSET,
    };

    /// Ȱ��ȭ�� ���� ���� ����
    enum ELeftPage
    {
        LEFT_PAGE_PC,
        LEFT_PAGE_MOB,
    };

	DECLARE_DYNCREATE(CRightToolView)

protected:
	CRightToolView();           // protected constructor used by dynamic creation
	virtual ~CRightToolView();

public:
	enum { IDD = IDD_RIGHTTOOLVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
    static CRightToolView* GetInstance() {return m_Instance;};
    void    SetInit(CMTCharacter* pCharacter);          ///< Edit�� ����� �� ��ü�� �����Ѵ�.    
    void    SetEnable(ECtrlEnable eEnable);             ///< ��ü UI�� Ȱ��ȭ/��Ȱ��ȭ�� �����Ѵ�.
    void    SetActiveLeftView(ELeftPage eActiveLeftPage); ///< ���� �۾����� ���� Page�� ������ �����Ѵ�.
    void    SetAnimEventData(STypeAnimData* pAnimData); ///< Anim Data���� �����Ѵ�.

protected:
    std::string GetAnimPath(CString sPathName);         ///< Anim ���ϵ��� ��θ� ����η� ��ȯ�Ѵ�.
    void    SetAnimData(RwUInt32 uiKey);                ///< Anim Data�� �����Ѵ�.
    void    SetUIStatus(EAnimSet eAnimSet);             ///< Anim Set�� ���� UI�� Ȱ��/��Ȱ��ȭ ��Ų��.    
    void    CreateAnimFileMap();                        ///< ����Ʈ�� ����� Anim FIle Map�� �����Ѵ�.

    // UI ���濡 ���� ���� �޼ҵ��    
    void    ChangeDamage(int nIndex);                   ///< Dmage���� �����Ѵ�.    

protected:
    static CRightToolView*  m_Instance;
    CNtlPLCharacterParser   m_CharacterPaser;           ///< ĳ���� �ļ� (�ִϸ��̼� Set ������ ���)
    CMTCharacter*           m_pCharacter;               ///< ����� �𵨰�ü�� ������    
    CNtlTypeAnimTable*      m_pAnimTable;               ///< Edit�� ����� AnimTable;
    STypeAnimData*          m_pCurrentAnimData;         ///< ���� Edit�߿� AnimData;
    RwUInt32                m_nCurrentAnimKey;          ///< Edit�� ���Ǵ� ���� �ִϸ��̼��� Key
    EAnimSet                m_eAnimSetKind;             ///< ���� �۾��ϰ� �ִ� AnimSet ����
    SEventAnimHit*          m_vEventAnimHit[MAX_HIT_EVENT_COUNT];        ///< Hit Event     
    ELeftPage               m_eActiveLeftPage;          ///< ���� �۾����� ���� PAGE�� ����
    MapAnimFile             m_mapAnimFile;              ///< ����Ʈ�� ����� Anim File���� ��

public:
    CComboBox m_cbAnimSet;
    
protected:    
    CEdit m_edDamage[MAX_HIT_EVENT_COUNT];        
    CButton m_raPhysical;
    CButton m_raEnergy;
    CListCtrl m_ltAnimItem;
    CListCtrl m_ltUpperAnim;

public:
    virtual void OnInitialUpdate();    
    afx_msg void OnCbnSelchangeCbAnimSet();
    afx_msg void OnNMRclickLtAnimItem(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnMenuAnimSet();
    afx_msg void OnMenuAnimDelete();
    afx_msg void OnLvnItemchangedLtAnimItem(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedRaEnergy();
    afx_msg void OnBnClickedRaPhysical();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnEnChangeEdDamage00();
    afx_msg void OnEnChangeEdDamage01();
    afx_msg void OnEnChangeEdDamage02();
    afx_msg void OnEnChangeEdDamage03();
    afx_msg void OnEnChangeEdDamage04();
    afx_msg void OnEnChangeEdDamage05();
    afx_msg void OnEnChangeEdDamage06();
    afx_msg void OnEnChangeEdDamage07();
    afx_msg void OnEnChangeEdDamage08();
    afx_msg void OnEnChangeEdDamage09();
    afx_msg void OnEnChangeEdDamage10();
    afx_msg void OnEnChangeEdDamage11();
    afx_msg void OnEnChangeEdDamage12();
    afx_msg void OnEnChangeEdDamage13();
    afx_msg void OnEnChangeEdDamage14();
    afx_msg void OnEnChangeEdDamage15();
};


