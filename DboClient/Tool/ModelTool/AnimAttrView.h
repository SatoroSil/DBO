#pragma once

#include "PropTree.h"
#include "afxwin.h"
#include "MTCharacter.h"


// CAnimAttrView form view

class CAnimAttrView : public CFormView
{
public:

    /// �׸���� ID 
    enum EControlID
    {
        ID_PROP_ITEM_HITTIME,
        ID_PROP_ITEM_TARGETBEHAVIOR,
        ID_PROP_ITEM_ATTACKPOWER,
        ID_PROP_ITEM_HANDTYPE,
        ID_PROP_ITEM_BONE,
        ID_PROP_ITEM_EFFECTTYPE,
        ID_PROP_ITEM_LUAID,
        ID_PROP_ITEM_SOUND_TIME,
        ID_PROP_ITEM_SOUND_FILE,
    };

    /// ������Ƽ �������� ��� 
    enum EPropertyMode
    {
        MODE_NONE,
        MODE_HIT_EVENT,
        MODE_SOUND_EVENT,
    };

	DECLARE_DYNCREATE(CAnimAttrView)

protected:
	CAnimAttrView();           // protected constructor used by dynamic creation
	virtual ~CAnimAttrView();

public:
	enum { IDD = IDD_ANIMATTRVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
    static CAnimAttrView* GetInstance() {return m_pInstance;};
    void SetPropertyMode(EPropertyMode ePropertyMode);   ///< ������Ƽ �������� ���¸� �����Ѵ�.
    void SetInit(CMTCharacter* pCharacter, SEventAnim* pEventAnim);   ///< ���� �����͸� �����Ѵ�.

protected:
    void InitHitPropertyItem();                          ///< Hit Event �׸���� �����Ѵ�.
    void InitSoundPropertyItem();                        ///< ���� ������Ƽ �׸���� �����Ѵ�.
    void SetBoneList();                                  ///< Bone ����Ʈ �׸��� �����Ѵ�.
    void SetLuaIDList();                                 ///< Lua ID ����Ʈ �׸��� �����Ѵ�.
    void SetEffectTypeList();                            ///< Effect Type ����Ʈ �׸��� �����Ѵ�.
    void SetSoundFileList();                             ///< SoundFile ����Ʈ �׸��� �����Ѵ�.

    // �̺�Ʈ ó��
    void OnChangeHitTime();                              ///< Hit Time ���� �����Ѵ�.
    void OnChangeBehavior();                             ///< Behavior ���� �����Ѵ�.
    void OnChangePowerEffect();                          ///< Power Effect ���� �����Ѵ�.
    void OnChangeHandType();                             ///< HandType ���� �����Ѵ�.
    void OnChangeBone();                                 ///< ���� Bone ���� �����Ѵ�
    void OnChangeEffectType();                           ///< Effect Type���� �����Ѵ�.
    void OnChangeLuaID();                                ///< Lua ID ���� �����Ѵ�.
    void OnChangeSoundTime();                            ///< Sound Time�� �����Ѵ�.
    void OnChangeSoundFile();                            ///< Sound File�� �����Ѵ�.

protected:
    static CAnimAttrView* m_pInstance;

    CMTCharacter*       m_pCharacter;                    ///< �Ӽ��� ������ ĳ����
    SEventAnim*         m_pEventAnim;                     ///< Event�� ������ ������    

    CPropTree           m_HitPropertyTree;               ///< Hit Event ������Ƽ ������ ��Ʈ��    
    CPropTreeItem*      m_pHitPropRoot;                  ///< ��Ʈ �׸�    
    CPropTreeItemEdit*  m_pPropHitTime;                  ///< HitTime �׸�
    CPropTreeItemCombo* m_pPropTargetBehavior;           ///< TargetBehavior �׸�
    CPropTreeItemCombo* m_pPropAttackPower;              ///< AttackPower �׸�
    CPropTreeItemCombo* m_pPropHandType;                 ///< HandType �׸�
    CPropTreeItemCombo* m_pPropBone;                     ///< Bone �׸�
    CPropTreeItemCombo* m_pPropEffectType;               ///< EffectType �׸�
    CPropTreeItemCombo* m_pPropLuaID;                    ///< LUA ID �׸�
    
    CPropTree           m_SoundProperyTree;              ///< Sound Event ������Ƽ ������ ��Ʈ��
    CPropTreeItem*      m_pSoundPropRoot;                ///< Sound ������Ƽ�� Root �׸�
    CPropTreeItemEdit*  m_pPropSoundTime;                ///< Sound Time �׸� 
    CPropTreeItemCombo* m_pPropSoundFile;                ///< Sound File �׸�

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    virtual void OnInitialUpdate();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnItemChanged(NMHDR* pNotifyStruct, LRESULT* plResult);

protected:
    CStatic m_staticFrame;
};


