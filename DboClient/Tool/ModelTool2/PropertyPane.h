#pragma once

#include "CustomItems.h"
#include "MTObject.h"
#include "MTItem.h"

#define MAX_ALPHA_ATOMIC 32

// CPropertyPane form view

class CPropertyPane : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CPropertyPane)

public:
    /// ���� �������� ��� 
    enum EPropertyMode
    {
        PROPERTY_MODE_NONE,
        PROPERTY_MODE_CHARACTER,
        PROPERTY_MODE_OBJECT,
        PROPERTY_MODE_ITEM,
        PROPERTY_MODE_ANIM_EVENT,
        PROPERTY_MODE_ANIMATION,
    };

    /// ������Ƽ ��Ʈ�ѿ� ���Ե� �����۵��� ID
    enum EItemID
    {
        // Character ���� ����
        ID_CHAR_FACE_CAMERA_POS,
        ID_CHAR_FACE_CAMERA_HEIGHT,
		ID_CHAR_INIT_WALK_SPEED,
		ID_CHAR_INIT_RUN_SPEED,
        ID_CHAR_APPLY_TANGENT,
        ID_CHAR_ALPHA_DIST,

        // Animation ������Ƽ
        ID_ANIM_CULL_CULLTEST,

        // Hit Event
        ID_HIT_TIME,
        ID_HIT_POWER_EFFECT,
        ID_HIT_TARGET_BRHAVIOR,
        ID_HIT_KB2PUSH,
        ID_HIT_HAND_TYPE,
        ID_HIT_PROJECTILE_TYPE,        
        ID_HIT_PROJECTILE_SHOT,
        ID_HIT_BONE_NAME,
        ID_HIT_SUBWEAPON_BONE_FLAG,
        ID_HIT_PROJECTILE_NAME,
        ID_HIT_PROJECTILE_SPEED,
        ID_HIT_TARGET_ATTACH,
        ID_HIT_TARGET_EFFECT_NAME,
		ID_HIT_TARGET_EFFECT_TYPE,
        ID_HIT_SUB_TARGET_EFFECT,
        ID_HIT_TARGET_SOUND_NAME,
        ID_HIT_SOUND_TYPE,
        ID_HIT_SOUND_ECHO,
        ID_HIT_TARGET_HEIGHT,
        ID_HIT_WORD_EFFECT,
        ID_HIT_CAMERA_SHAKE,
        ID_HIT_SHAKE_FACTOR,
        ID_HIT_SHAKE_MAX_HEIGHT,
        ID_HIT_HOIDAN_OFFSET,
        ID_HIT_HOIDAN_START_WAIT_TIME,
        ID_HIT_HOIDAN_SPEED,
        ID_HIT_HISSDIAN_DIRECTION,
        ID_HIT_HISSIDAN_APPLY_ANGLE,
        ID_HIT_MULTI_HISSIDAN_COUNT,
        ID_HIT_MULTI_HISSIDAN_INDEX,
        ID_HIT_MULTI_HISSIDAN_DIR,

        // Visual Effect Event
        ID_VE_TIME,
        ID_VE_NAME,
        ID_VE_BONE_TYPE,
        ID_VE_BONE_NAME,
        ID_VE_SUB_WEAPON_BONE_NAME,
        ID_VE_ATTACH,
        ID_VE_ATTACH_BONE,
        ID_VE_OFFSET_POS,        
        ID_VE_OFFSET_ROT,  
        ID_VE_APPLY_SCALE,
        ID_VE_PROJECTILE_TYPE,

        // Sound Event
        ID_SE_TIME,        
        ID_SE_SOUND_NAME1,
        ID_SE_SOUND_NAME2,
        ID_SE_SOUND_NAME3,
        ID_SE_SOUND_NAME4,
        ID_SE_SOUND_TYPE,
        ID_SE_SOUND_LOOP,
        ID_SE_SOUND_VOLUME,
        ID_SE_SOUND_DIST,
        ID_SE_SOUND_DECAY_DIST,
        ID_SE_SOUND_PITCH_MIN,
        ID_SE_SOUND_PITCH_MAX,

        // Foot Step Event
        ID_FS_TIME,
        ID_FS_TYPE,
        ID_FS_MOB_TYPE,

        // Link Effect Event
        ID_LE_BONE_NAME,
        ID_LE_ATTACH_BONE,        
        ID_LE_OFFSET_POS,
        ID_LE_OFFSET_ROT,

        // Weight TIme Event
        ID_ST_TIME,
        ID_ST_LIFE_TIME,
        ID_ST_WEIGHT,

        // Trace Effect Event
        ID_TE_TIME,
        ID_TE_LIFE_TIME,
        ID_TE_EDGE_LIFE_TIME,
        ID_TE_SRC_BLEND,
        ID_TE_DEST_BLEND,
        ID_TE_ATTACH_TYPE,
        ID_TE_TRACE_KIND,
        ID_TE_START_BONE_NAME,
        ID_TE_END_BONE_NAME,
        ID_TE_TEXTURE_NAME,
        ID_TE_START_BONE_OFFSET,
        ID_TE_END_BONE_OFFSET,
        ID_TE_FRAME_SKIP_COUNT,
        ID_TE_SPLINE_POINT_COUNT,
        ID_TE_MAX_EDGE_COUNT,
        ID_TE_MAX_LENGTH,
        ID_TE_START_COLOR,
        ID_TE_START_ALPHA,
        ID_TE_END_COLOR,
        ID_TE_END_ALPHA,

        // Sub Weapon Effect Event
        ID_SW_TIME,
        ID_SW_ACTIVE,

        // Post Effect Event
        ID_PE_TIME,
        ID_PE_NAME,
        ID_PE_TARGET,
        ID_PE_OFFSET,
        ID_PE_CENTER_FIX,
        ID_PE_TARGET_HEIGHT,
        ID_PE_PC_BONE,

		// Summon Pet Event
		ID_SUE_TIME,

        // TMQ Event
        ID_TMQ_TIME,
        ID_TMQ_TYPE,

        // Alpha Fade Event        
        ID_ALPHA_TIME,
        ID_ALPHA_START,
        ID_ALPHA_DEST,
        ID_ALPHA_FADE_TIME,
        ID_ALPHA_LIFE_TIME,
        ID_ALPHA_TYPE,
        ID_ALPHA_ATOMIC,

        // Explosion Event
        ID_EXPLOSION_TIME,
        ID_EXPLOSION_TYPE,

        // Object Properties    
        ID_OBJ_SHADOW = ID_ALPHA_ATOMIC + MAX_ALPHA_ATOMIC,        
        ID_OBJ_BBOX,        
        ID_OBJ_PICKING,
        ID_OBJ_CULLDIST,
        ID_OBJ_UVANIM,
        ID_OBJ_UVANIM_SPEED,
        ID_OBJ_ANIM,
        ID_OBJ_COLLISION,        
        ID_OBJ_COLLISON_MESH,
        ID_OBJ_TYPE,
        ID_OBJ_APPLY_PVS,
        ID_OBJ_SORT_BY_POS,
        ID_OBJ_FORCE_PICKING,
        ID_OBJ_PE_NAVI_PRESS,
        ID_OBJ_CULLTEST_ALL_ATOMIC,

        // Item Properties
        ID_ITEM_NAME,
        ID_ITEM_MESH_PATH,
        ID_ITEM_MESH_NAME,
        ID_ITEM_ATTACH_TYPE,
        ID_ITEM_ATTACH_SLOT,
        ID_ITEM_ATTACH_OFFSET,
        ID_ITEM_TRACE_ENABLE,
        ID_ITEM_APPLY_EMBLEM,

        // Upgrade Properties
        ID_UPGRADE_BONE1,
        ID_UPGRADE_BONE2,
        ID_UPGRADE_EFFECT1,
        ID_UPGRADE_EFFECT2,
        ID_UPGRADE_OFFSET1,
        ID_UPGRADE_OFFSET2,

        // Direct Event 
        ID_DIRECT_TIME,
        ID_DIRECT_TYPE,

        // Color Change Event
        ID_COLCHANGE_TIME,
        ID_COLCHANGE_TYPE,
        ID_COLCHANGE_EDGE,
        ID_COLCHANGE_BODY,
        ID_COLCHANGE_ADD,

        // �� �ø��� �̺�Ʈ
        ID_STRETCH_TIME,
        ID_STRETCH_TYPE,
        ID_STRETCH_BONE1_NAME,        
        ID_STRETCH_BONE2_NAME,
        ID_STRETCH_BONE_SPEED,
        ID_STRETCH_BONE_WIDTH,
        ID_STRETCH_BONE_ACCEL,
        ID_STRETCH_SCALE_NAME,
        ID_STRETCH_SCALE_SIZE,
        ID_STRETCH_AXIS_BONE,
        ID_STRETCH_TARGET_EFFECT,

        // Ʈ���� �̺�Ʈ
        ID_TRIGGER_TIME,

        // ��ų ĵ�� �̺�Ʈ
        ID_SC_TIME,
    };

protected:
	CPropertyPane();           // protected constructor used by dynamic creation
	virtual ~CPropertyPane();

public:
	enum { IDD = IDD_PROPERTYPANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
    static CPropertyPane* GetInstance() {return m_pInstance;};

    void SetCharacter(CMTCharacter* pCharacter);                       ///< ������Ƽ �����͸� ������ ĳ���͸� �����Ѵ�.
    void SetEvent(SEventAnim* pEventAnim, RpClump* pClump = NULL, RwBool bRefresh = FALSE);     ///< ������Ƽ�� �����͸� �����Ѵ�.        
    void SetObject(CMTObject* pObject);                                ///< ������Ʈ ������Ƽ�� �����Ѵ�.
    void SetAnimation(STypeAnimData* pTypeAnimData);                   ///< �ִϸ��̼� �����͸� �����Ѵ�.
    void SetItem(CMTItem* pItem);                                      ///< Item Property�� �����Ѵ�.
    void SetAttackType(EAttackType eAttackType);                       ///< Attack Type�� �����Ѵ�.
    void Update();                           ///< ������ ������ ������Ʈ�Ѵ�.

protected:
    void SetBoneList();                      ///< Bone �����͸� ������Ʈ�Ѵ�.            
    void SetAtomicList(const SEventAlpha* pEventAlpah);  ///< Atomic List�� ������Ʈ�Ѵ�.
    void SetEffectTypeList();                ///< Effect Type ����Ʈ �׸��� �����Ѵ�.
    void SetEffectNameList();                ///< Effect Name�� �����ͼ� �����Ѵ�.
    void SetProjectileType();                ///< Projectile Type�� ���� UI�� �����Ѵ�.

    void HideAllCategory();                  ///< ��� ī�װ��� �����.

protected:
    static CPropertyPane* m_pInstance;

    EPropertyMode   m_ePropertyMode;

    RpClump*        m_pClump;
    SEventAnim*     m_pEventAnim;
    CMTObject*      m_pObject;
    CMTItem*        m_pItem;
    CMTCharacter*   m_pCharacter;            ///< ������Ƽ�� �����͸� ������ Character
    STypeAnimData*  m_pAnimData;

protected:    
    CXTPPropertyGrid m_property;
    CXTPPropertyGridItem* m_pCatHitEvent;
    CXTPPropertyGridItem* m_pCatVisualEffectEvent;
    CXTPPropertyGridItem* m_pCatVisualSoundEvent;
    CXTPPropertyGridItem* m_pCatFootStepEvent;
    CXTPPropertyGridItem* m_pCatLinkEffectEvent;
    CXTPPropertyGridItem* m_pCatSlowTimeEvent;
    CXTPPropertyGridItem* m_pCatTraceEvent;
    CXTPPropertyGridItem* m_pCatSubWeaponEvent;
    CXTPPropertyGridItem* m_pCatPostEffectEvent;
	CXTPPropertyGridItem* m_pCatSummonPetEvent;
    CXTPPropertyGridItem* m_pCatObjectProperty;
    CXTPPropertyGridItem* m_pCatItemProperty;
    CXTPPropertyGridItem* m_pCatCharacterProperty;
    CXTPPropertyGridItem* m_pCatUpgradeProperty;
    CXTPPropertyGridItem* m_pCatTMQEvent;
    CXTPPropertyGridItem* m_pCatAlphaEvent;
    CXTPPropertyGridItem* m_pCatExplosionEvent;
    CXTPPropertyGridItem* m_pCatObjSoundProperty;
    CXTPPropertyGridItem* m_pCatDirectEvent;
    CXTPPropertyGridItem* m_pCatColorChangeEvent;
    CXTPPropertyGridItem* m_pCatStretchEvent;
    CXTPPropertyGridItem* m_pCatTriggerEvent;
    CXTPPropertyGridItem* m_pCatSkillCancelEvent;
    CXTPPropertyGridItem* m_pCatAnimation;
    
    // Character
    CCustomItemOffset*          m_pCharFaceCameraPos;
    CCustomItemOffset*          m_pCharFaceCameraLookAt;
	CCustomItemSpinDouble*		m_pCharInitWalkSpeed;
	CCustomItemSpinDouble*		m_pCharInitRunSpeed;
    CXTPPropertyGridItemBool*   m_pCharApplyTangent;
    CCustomItemSpinDouble*      m_pCharAlphaDistance;

    // Animation
    CXTPPropertyGridItemBool*   m_pAnimCullTestAllAtomic;

    // Hit Event
    CCustomItemSpinDouble*      m_pItemTime;            
    CXTPPropertyGridItemBool*   m_pItemPowerEffect;         
    CXTPPropertyGridItemEnum*   m_pItemTargetBehavior;  
    CXTPPropertyGridItemBool*   m_pItemKB2Push;
    CXTPPropertyGridItemEnum*   m_pItemHandType; 
    CXTPPropertyGridItemEnum*   m_pItemProjectileType;    
    CXTPPropertyGridItemEnum*   m_pItemProjectileShot;
    CXTPPropertyGridItem*       m_pItemBoneName        ;
    CXTPPropertyGridItemFlags*  m_pItemSubWeaponBoneFlag;
    CXTPPropertyGridItem*       m_pItemProjectileName  ;
    CCustomItemSpinDouble*      m_pItemProjSpeed;
    CXTPPropertyGridItemBool*   m_pItemTargetAttach;
    CXTPPropertyGridItem*       m_pItemTargetEffectName;    
	CXTPPropertyGridItemEnum*	m_pItemTargetEffectType;
    CXTPPropertyGridItem*       m_pItemSubTargetEffect;
    CCustomItemSpinDouble*      m_pItemTargetHeight    ;
    CCustomItemFileBox*         m_pItemTargetSoundName ;
    CXTPPropertyGridItemEnum*   m_pItemSoundType;
    CXTPPropertyGridItemBool*   m_pItemHitSoundEcho;
    CXTPPropertyGridItem*       m_pItemWordEffect;
    CXTPPropertyGridItemBool*   m_pItemCameraShake;
    CCustomItemSpinDouble*      m_pItemShakeFactor;
    CCustomItemSpinDouble*      m_pItemShakeMaxHeight;
    CXTPPropertyGridItemBool*   m_pHitHissidanApplyAngle;
    CCustomItemOffset*          m_pHitHissidianDirection;
    CCustomItemOffset*          m_pHitHosidanOffset;
    CCustomItemSpinDouble*      m_pHitHosidanWaitTime;
    CCustomItemSpinDouble*      m_pHitHosidanSpeed;    
    CXTPPropertyGridItemNumber* m_pHitMultiHissidanCount;
    CXTPPropertyGridItemEnum*   m_pHitMultiHissidanIndex;
    CCustomItemOffset*          m_pHitMultiHissidanDir;

    // Visual Effect Event  
    CCustomItemSpinDouble*      m_pVETime;
    CXTPPropertyGridItem*       m_pVEName;
    CXTPPropertyGridItemBool*   m_pVEAttach;
    CXTPPropertyGridItemEnum*   m_pVEAttachType;
    CXTPPropertyGridItemBool*   m_pVEProjectileType;
    CXTPPropertyGridItemEnum*   m_pVEBoneType;
    CXTPPropertyGridItem*       m_pVEBoneName;
    CXTPPropertyGridItem*       m_pVEWeaponBoneName;    
    CCustomItemOffset*          m_pVEOffsetPos;
    CXTPPropertyGridItemBool*   m_pVEApplyScale;

    // Visual Sound Event
    CCustomItemSpinDouble*          m_pSETime;
    CCustomItemFileBox*             m_pSESoundName1;
    CCustomItemFileBox*             m_pSESoundName2;
    CCustomItemFileBox*             m_pSESoundName3;
    CCustomItemFileBox*             m_pSESoundName4;
    CXTPPropertyGridItemEnum*       m_pSESoundType;
    CXTPPropertyGridItemBool*       m_pSESoundLoop;
    CCustomItemSpin*                m_pSESoundVolume;
    CCustomItemSpin*                m_pSESoundDist;
    CCustomItemSpin*                m_pSESoundDecayDist;
    CCustomItemSpinDouble*          m_pSESoundPitchMin;
    CCustomItemSpinDouble*          m_pSESoundPitchMax;

    // Foot Step Event
    CCustomItemSpinDouble*          m_pFSTime;
    CXTPPropertyGridItemEnum*       m_pFSType;
    CXTPPropertyGridItemEnum*       m_pFSMobType;

    // Link  Event
    CXTPPropertyGridItem*           m_pLEName;
    CXTPPropertyGridItemBool*       m_pLEAttachBone;    
    CXTPPropertyGridItem*           m_pLEBoneName;    
    CCustomItemOffset*              m_pLEOffsetPos;
    CCustomItemOffset*              m_pLEOffsetRot;

    // Weight TIme Event
    CCustomItemSpinDouble*          m_pSTTime;
    CCustomItemSpinDouble*          m_pSTLifeTime;
    CCustomItemSpinDouble*          m_pSTWeight;

    // Trace Event
    CCustomItemSpinDouble*          m_pTEStartTime;
    CCustomItemSpinDouble*          m_pTELifeTime;
    CCustomItemSpinDouble*          m_pTEEdgeLifeTime;
    CXTPPropertyGridItemEnum*       m_pTEAttachType;
    CXTPPropertyGridItemEnum*       m_pTETraceKind;
    CXTPPropertyGridItem*           m_pTEStartBoneName;    
    CXTPPropertyGridItem*           m_pTEEndBoneName;
    CCustomItemFileBox*             m_pTETexture;
    CCustomItemOffset*              m_pTEStartBoneOffset;
    CCustomItemOffset*              m_pTEEndBoneoffset;
    CCustomItemSpinDouble*          m_pTEEdgeGap;
    CCustomItemSpin*                m_pTESplinePointCount;
    CXTPPropertyGridItemNumber*     m_pTEMaxEdgeCount;
    CCustomItemSpinDouble*          m_pTEMaxLength;
    CXTPPropertyGridItemEnum*       m_pTESrcBlend;
    CXTPPropertyGridItemEnum*       m_pTEDestBlend;
    CXTPPropertyGridItemColor*      m_pTEStartColor;
    CXTPPropertyGridItemNumber*     m_pTEStartAlpha;
    CXTPPropertyGridItemColor*      m_pTEEndColor;
    CXTPPropertyGridItemNumber*     m_pTEEndAlpha;

    // SubWeapon Event
    CCustomItemSpinDouble*          m_pSWTime;
    CXTPPropertyGridItemEnum*       m_pSWActive;

    // PostEffect Event
    CCustomItemSpinDouble*          m_pPETime;
    CXTPPropertyGridItem*           m_pPEEffectName;
    CXTPPropertyGridItemEnum*       m_pPETarget;
    CCustomItemOffset*              m_pPEOffset;
    CXTPPropertyGridItemBool*       m_pPECenterFix;
    CCustomItemSpinDouble*          m_pPETargetHeight;
    CXTPPropertyGridItem*           m_pPEPCBoneName;

	// Summon Event
	CCustomItemSpinDouble*			m_pSUETime;

    // TMQ Event
    CCustomItemSpinDouble*          m_pTMQTime;
    CXTPPropertyGridItemEnum*       m_pTMQType;    

    // Alpha Event
    CCustomItemSpinDouble*          m_pAlphaTime;
    CXTPPropertyGridItemNumber*     m_pAlphaStart;
    CXTPPropertyGridItemNumber*     m_pAlphaDest;
    CCustomItemSpinDouble*          m_pAlphaFadeTime;
    CCustomItemSpinDouble*          m_pAlphaLifeTime;
    CXTPPropertyGridItemEnum*       m_pAlphaType;    
    CXTPPropertyGridItemBool*       m_pAlphaAtomic[MAX_ALPHA_ATOMIC];

    // Explosion Event
    CCustomItemSpinDouble*          m_pExplosionTime;
    CXTPPropertyGridItemEnum*       m_pExplosionType;

    // Object Properties
    CXTPPropertyGridItem*           m_pObjClumpName;
    CXTPPropertyGridItem*           m_pObjName;
    CXTPPropertyGridItemBool*       m_pObjShadow;        
    CCustomItemSpinDouble*          m_pObjCullDist;
    CCustomItemOffset*              m_pObjBBox;
    CCustomItemFileBox*             m_pObjUVAnim;
    CCustomItemSpinDouble*          m_pObjUVAnimSpeed;
    CCustomItemFileBox*             m_pObjAnim;
    CXTPPropertyGridItemBool*       m_pObjCollision;    
    CCustomItemFileBox*             m_pObjCollisonMesh;
    CXTPPropertyGridItemEnum*       m_pObjType;
    CXTPPropertyGridItemBool*       m_pObjApplyPVS;    
    CXTPPropertyGridItemBool*       m_pObjSortByPos;
    CXTPPropertyGridItemBool*       m_pObjForcePicking;
    CXTPPropertyGridItemBool*       m_pObjPENaviPress;
    CXTPPropertyGridItemBool*       m_pObjCullTestAllAtomic;
    CCustomItemFileBox*             m_pObjSoundName;        
    CCustomItemSpin*                m_pObjSoundVolume;
    CCustomItemSpin*                m_pObjSoundDist;
    CCustomItemSpin*                m_pObjSoundDecayDist;
    CCustomItemSpinDouble*          m_pObjSoundPicth;    
    

    // Item Properties
    CXTPPropertyGridItem*           m_pItemName;
    CXTPPropertyGridItem*           m_pItemMeshPath;
    CXTPPropertyGridItem*           m_pItemMeshName;
    CXTPPropertyGridItemEnum*       m_pItemAttachType;
    CXTPPropertyGridItemEnum*       m_pItemAttachSlot;   
    CCustomItemOffset*              m_pItemAttachOffset;
    CXTPPropertyGridItemBool*       m_pItemTraceEnable;
    CXTPPropertyGridItemBool*       m_pItemApplyEmblem;

    // Upgrade Properties
    CXTPPropertyGridItem*           m_pUpgradeBone1;        
    CXTPPropertyGridItem*           m_pUpgradeBone2;    
    CXTPPropertyGridItem*           m_pUpgradeEffect1;
    CXTPPropertyGridItem*           m_pUpgradeEffect2;
    CCustomItemOffset*              m_pUpgradeOffset1;
    CCustomItemOffset*              m_pUpgradeOffset2;

    // Direct Event
    CCustomItemSpinDouble*          m_pDirectEventTime;
    CXTPPropertyGridItemEnum*       m_pDirectEventType;

    // Color Change Event
    CCustomItemSpinDouble*          m_pColChangeEventTime;
    CXTPPropertyGridItemEnum*       m_pColChangeEventType;
    CXTPPropertyGridItemColor*      m_pColChangeEventEdge;
    CXTPPropertyGridItemColor*      m_pColChangeEventBody;
    CXTPPropertyGridItemColor*      m_pColChangeEventAdd;

    // Bone Stretch Event
    CCustomItemSpinDouble*          m_pStretchEventTime;
    CXTPPropertyGridItemEnum*       m_pStretchEventType;
    CXTPPropertyGridItem*           m_pStretchBoneName[2];    
    CCustomItemSpinDouble*          m_pStretchSpeed;    
    CCustomItemSpinDouble*          m_pStretchWidth;
    CCustomItemSpinDouble*          m_pStretchAccel;
    CXTPPropertyGridItem*           m_pStretchScaleName;
    CCustomItemSpinDouble*          m_pStretchScaleSize;
    CXTPPropertyGridItem*           m_pStretchAxisBoneName;
    CXTPPropertyGridItem*           m_pStretchTargetEffect;

    // Trigger Event
    CCustomItemSpinDouble*          m_pTriggerEventTime;

    // Skill Cancel Event
    CCustomItemSpinDouble*          m_pSCTime;
        
protected:  

    void OnUpdateMultiHissidanIndex(SEventAnimHit* pAnimHit);

    // Link Effect Event
    void OnLEBoneName();
    void OnLEAttachBone();    
    void OnLEOffsetPos();
    void OnLEOffsetRot();

    // Weight Time Event
    void OnSTTIme();
    void OnSTLifeTime();
    void OnSTWeight();

    // Character Properties
    void OnCharFaceCameraPos();
    void OnCharFaceCameraHeight();

    void SetObjectProperties(CMTObject* pObject, UINT nID);                          ///< ������Ʈ�� ������Ƽ�� �����Ѵ�.
    void SetItemProperties(CNtlPLItemProperty* pProperty, UINT nID);                 ///< ������ ������Ƽ�� �����Ѵ�.
    void SetCharacterProperties(CNtlPLCharacterProperty* pProperty, UINT nID);       ///< ĳ���� ������Ƽ�� �����Ѵ�.    
    void SetAnimationProperties(STypeAnimData* pAnimData, UINT nID);                 ///< �ִϸ��̼� ������Ƽ�� �����Ѵ�.

    void ApplyHitEventProperties(SEventAnimHit* pAnimHit);
    void SetHitEventProperties(SEventAnimHit* pAnimHit, UINT nID);              

    void ApplyTraceEventProperties(SEventTrace* pEventTrace);                        ///< Trace Event�� ������ �������� ������Ʈ�Ѵ�.
    void SetTraceEventProperties(SEventTrace* pEventTrace, UINT nID);                ///< Trace Event�� ������Ƽ�� �����Ѵ�.

    void ApplyVisualEffectEventProperties(const SEventVisualEffect* pEventVisualEffect);        ///< Visual Effect Event�� ������ �������� ������Ʈ�Ѵ�.
    void SetVisualEffectEventProperties(SEventVisualEffect* pEventVisualEffect, UINT nID);      ///< Visual Effect Event�� ������Ƽ�� �����Ѵ�

    void ApplySubWeaponEventProperties(const SEventSubWeapon* pEventSubWeapon); ///< SubWeapon Evnet�� ������ �������� ������Ʈ�Ѵ�.
    void SetSubWeaponProperties(SEventSubWeapon* pEventSubWeapon, UINT nID);    ///< SubWeapon Event�� ������Ƽ�� �����Ѵ�.

    void ApplyPostEffectEventProperties(const SEventPostEffect* pEventPostEffect);      ///< PostEffect Event�� ������ �������� ������Ʈ�Ѵ�.
    void SetPostEffectEventProperties(SEventPostEffect* pEventPostEffect, UINT nID);    ///< PostEffect Event�� ������Ƽ�� �����Ѵ�.

    void ApplySummonPetEventProperties(const SEventSummonPet* pEventSummonPet);         ///< SummonPet Event�� ������ �������� ������Ʈ �Ѵ�.
    void SetSummonPetEventProperties(SEventSummonPet* pEventSummonPet, UINT nID);       ///< SummonPet Event�� ������Ƽ�� �����Ѵ�.

    void ApplyTMQEventProperties(const SEventAnimCinematic* pEventTMQ);                           ///< TMQ Event�� ������ �������� ��Ʈ�ѵ��� ���� ������Ʈ�Ѵ�.
    void SetTMQEventProperties(SEventAnimCinematic* pEventTMQ, UINT nID);                         ///< TMQ Event�� ������Ƽ�� �����Ѵ�.

    void ApplyAlphaEventProperties(const SEventAlpha* pEventAlpha);                     ///< Alpha Evnet�� ������ �������� ��Ʈ�ѵ��� ���� ������Ʈ�Ѵ�.
    void SetAlphaEventProperties(SEventAlpha* pEventAlpha, UINT nID);                   ///< Alpha Event�� ������Ƽ�� �����Ѵ�.

    void ApplyFootStepEventProperties(const SEventFootStep* pEventFootStep);            ///< ǲ����(���ڱ�) �̺�Ʈ�� ������ �������� ���� ������Ʈ�Ѵ�.
    void SetFootStepEventProperties(SEventFootStep* pEventFootStep, UINT nID);          ///< ǲ������ ������Ƽ�� �����Ѵ�.

    void ApplyExplosionEventProperties(const SEventExplosion* pEventExplosion);         ///< ���� �̺�Ʈ�� ������ �������� ���� ������Ʈ�Ѵ�.
    void SetExplosionEventProperties(SEventExplosion* pEventExplosion, UINT nID);       ///< ���� �̺�Ʈ�� ������Ƽ�� �����Ѵ�.

    void ApplyUpgradeEffectProperties(const SUpgradeEffectProperty* pUpgradeEffectProperty);    ///< ������ ���׷��̵� ����Ʈ ������Ƽ�� ������ �������� ���� ������Ʈ�Ѵ�.
    void SetUpgradeEffectProperties(SUpgradeEffectProperty* pUpgradeEffectProperty, UINT nID);  ///< ������ ���׷��̵� ����Ʈ ������Ƽ�� �����Ѵ�.

    void ApplySoundEventProperties(const SEventSound* pEventSound);                     ///< ���� �̺�Ʈ�� ������ �������� ���� ������Ʈ�Ѵ�.
    void SetSoundEventProperties(SEventSound* pEventSound, UINT nID);                   ///< ���� �̺�Ʈ ������Ƽ�� �����Ѵ�.

    void ApplyDirectEventProperties(const SEventDirect* pEventDirect);                  ///< ����� �̺�Ʈ�� ������ �������� ���� ������Ʈ�Ѵ�.
    void SetDirectEventProperties(SEventDirect* pEventDirect, UINT nID);                ///< ����� �̺�Ʈ ������Ƽ�� �����Ѵ�.

    void ApplyColorChangeEventProperties(const SEventColorChange* pEventColorChange);   ///< ���� ���� �̺�Ʈ ������Ʈ
    void SetColorChangeEventProperties(SEventColorChange* pEventColorChange, UINT nID); ///< ���� ���� ������Ƽ ����

    void ApplyStretchEventProperties(const SEventStretch* pEventStretch);               ///< ��Ʈ��ġ �̺�Ʈ ������Ʈ
    void SetStretchEventProperties(SEventStretch* pEventStretch, UINT nID);             ///< ��Ʈ��ġ �̺�Ʈ ������Ƽ ����

    void ApplyTriggerEventPrperties(const SEventTrigger* pEventTrigger);                ///< Ʈ���� �̺�Ʈ ������Ʈ
    void SetTriggerEventProperties(SEventTrigger* pEventTrigger, UINT nID);             ///< Ʈ���� �̺�Ʈ ������Ƽ ����

    void ApplySkillCancelProperties(const SEventSkillCancel* pEventSkillCancel);         ///< ��ų ĵ�� �̺�Ʈ ������Ʈ
    void SetSkillCancelProperties(SEventSkillCancel* pEventSkillCancel, UINT nID);       ///< ��ų ĵ�� �̺�Ʈ ������Ƽ ����

    //////////////////////////////////////////////////////////////////////////
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    afx_msg LRESULT OnGridNotify(WPARAM, LPARAM);

	DECLARE_MESSAGE_MAP()
public:
    virtual void OnInitialUpdate();
};