//***********************************************************************************
//
//	File		:	GraphicDataTable.h
//
//	Begin		:	2006-05-29
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Hong Ho Dong   ( battery@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************
#ifndef _GRAPHIC_DATA_TABLE_H_
#define _GRAPHIC_DATA_TABLE_H_

#include "NtlVector.h"

#define	MAX_UPGRADE_EFFECT_COUNT 16
#define MAX_DEFAULT_NAME	    32
#define ANIM_EVENT_NONE_TIME    0.f

// ī�޶� ����ũ 
#define CAMERA_SHAKE_FACTOR             8.0f
#define CAMERA_SHAKE_MAX_HEIGHT_FACTOR  2.0f

typedef char RwChar;
typedef long RwFixed;
typedef int  RwInt32;
typedef unsigned int RwUInt32;
typedef short RwInt16;
typedef unsigned short RwUInt16;
typedef unsigned char RwUInt8;
typedef signed char RwInt8;
typedef float RwReal;
typedef RwInt32 RwBool;


#if _IS_SERVER_
typedef struct RwV2d RwV2d;
struct RwV2d
{
	float x;
	float y;
};
typedef struct RwV3d RwV3d;
struct RwV3d
{
	float x;
	float y;
	float z;
};

struct RwRGBA
{
	RwUInt8 red;    /**< red component */
	RwUInt8 green;  /**< green component */
	RwUInt8 blue;   /**< blue component */
	RwUInt8 alpha;  /**< alpha component */
};
#endif

// Shared
enum EGraphicAnimCommon
{
	ATTACK_ANIMATION_SET_NUM	= 6,

	ATTACK_ANIMATION_START		= 1000,
	ATTACK_ANIMATION_DEFAULT    = ATTACK_ANIMATION_START,
	ATTACK_ANIMATION_GLOVE		= ATTACK_ANIMATION_DEFAULT + ATTACK_ANIMATION_SET_NUM,
	ATTACK_ANIMATION_GUN		= ATTACK_ANIMATION_GLOVE + ATTACK_ANIMATION_SET_NUM,
	ATTACK_ANIMATION_STAFF		= ATTACK_ANIMATION_GUN + ATTACK_ANIMATION_SET_NUM,
	ATTACK_ANIMATION_DUAL_GUN	= ATTACK_ANIMATION_STAFF + ATTACK_ANIMATION_SET_NUM,
	ATTACK_ANIMATION_END        = ATTACK_ANIMATION_DUAL_GUN + ATTACK_ANIMATION_SET_NUM,

	SKILL_ANIMATION_START       = 2000,
	SKILL_ANIMATION_END			= SKILL_ANIMATION_START + 200,

    HTB_ANIMATION_START         = 3000,
    HTB_ANIMATION_END           = HTB_ANIMATION_START + 50,
};

// Social
enum ESocialAnimationList
{
    SOCIAL_ANIMATION_START = 1500,
	SOC_AGREE = SOCIAL_ANIMATION_START,
    SOC_NO,
    SOC_BYE,
    SOC_HAPPY,
    SOC_LAUGH,
    SOC_SAD,
    SOC_CLAP_HANDS,
    SOC_POINT,
    SOC_RUSH,
    SOC_YEAH,
    SOC_AMUSE,
    SOC_HI,
    SOC_PAFUPAFU,
    SOC_COURTESY,
    SOC_POKE,
	SOC_CONFUSION,
	SOCIAL_ANIMATION_END = SOC_CONFUSION,
};

// Attack
enum EAttackAnimationList
{
	ATK_DEF_1 = ATTACK_ANIMATION_START,
	ATK_DEF_2,
	ATK_DEF_3,
	ATK_DEF_4,
	ATK_DEF_5,
	ATK_DEF_6,
	ATK_GLOVE_1,
	ATK_GLOVE_2,
	ATK_GLOVE_3,
	ATK_GLOVE_4,
	ATK_GLOVE_5,
	ATK_GLOVE_6,
	ATK_GUN_1,
	ATK_GUN_2,
	ATK_GUN_3,
	ATK_GUN_4,
	ATK_GUN_5,
	ATK_GUN_6,
	ATK_STAFF_1,
	ATK_STAFF_2,
	ATK_STAFF_3,
	ATK_STAFF_4,
	ATK_STAFF_5,
	ATK_STAFF_6,
	ATK_DGUN_1,
	ATK_DGUN_2,
	ATK_DGUN_3,
	ATK_DGUN_4,
	ATK_DGUN_5,
	ATK_DGUN_6,
};

//Battle
enum EBattleAnimationList
{
	BATTLE_ANIMATION_START = 0x1F4,
	BTL_DEF_FP_LOOP = 0x1F4,
	BTL_DEF_FP_HURT = 0x1F5,
	BTL_DEF_FP_DOT_HURT = 0x1F6,
	BTL_DEF_FP_IDLE = 0x1F7,
	BTL_DEF_BLOCK_DEF = 0x1F8,
	BTL_DEF_BLOCK_START = 0x1F9,
	BTL_DEF_BLOCK_END = 0x1FA,
	BTL_DEF_DODGE = 0x1FB,
	BTL_DEF_KD_FLYING = 0x1FC,
	BTL_DEF_KD_LANDING = 0x1FD,
	BTL_DEF_KD_HURT = 0x1FE,
	BTL_DEF_KD_STAND_UP = 0x1FF,
	BTL_DEF_STUN = 0x200,
	BTL_DEF_COUNTER = 0x201,
	BTL_DEF_GUARD_CRUSH = 0x202,
	BTL_DEF_HTB_HOMING_UP = 0x203,
	BTL_DEF_HTB_HOMING_IDLE = 0x204,
	BTL_DEF_HTB_HOMING_DOWN = 0x205,
	BTL_DEF_HTB_HOMING_LANDING = 0x206,
	BTL_DEF_HTB_TOSS_UP = 0x207,
	BTL_DEF_HTB_TOSS_IDLE = 0x208,
	BTL_DEF_HTB_TOSS_HURT = 0x209,
	BTL_DEF_HTB_FALL_DOWN = 0x20A,
	BTL_DEF_HTB_FALL_DOWN_LANDING = 0x20B,
	BTL_DEF_HTB_FALL_DOWN_HURT = 0x20C,
	BTL_GUN_FP_LOOP = 0x20D,
	BTL_GUN_FP_HURT = 0x20E,
	BTL_GUN_FP_DOT_HURT = 0x20F,
	BTL_GUN_FP_IDLE = 0x210,
	BTL_GUN_BLOCK_DEF = 0x211,
	BTL_GUN_BLOCK_START = 0x212,
	BTL_GUN_BLOCK_END = 0x213,
	BTL_GUN_DODGE = 0x214,
	BTL_GUN_KD_FLYING = 0x215,
	BTL_GUN_KD_LANDING = 0x216,
	BTL_GUN_KD_HURT = 0x217,
	BTL_GUN_KD_STAND_UP = 0x218,
	BTL_GUN_COUNTER = 0x219,
	BTL_GUN_GUARD_CRUSH = 0x21A,
	BTL_STAFF_FP_LOOP = 0x21B,
	BTL_STAFF_FP_HURT = 0x21C,
	BTL_STAFF_FP_DOT_HURT = 0x21D,
	BTL_STAFF_FP_IDLE = 0x21E,
	BTL_STAFF_BLOCK_DEF = 0x21F,
	BTL_STAFF_BLOCK_START = 0x220,
	BTL_STAFF_BLOCK_END = 0x221,
	BTL_STAFF_DODGE = 0x222,
	BTL_STAFF_KD_FLYING = 0x223,
	BTL_STAFF_KD_LANDING = 0x224,
	BTL_STAFF_KD_HURT = 0x225,
	BTL_STAFF_KD_STAND_UP = 0x226,
	BTL_STAFF_COUNTER = 0x227,
	BTL_STAFF_GUARD_CRUSH = 0x228,
	BTL_DGUN_FP_LOOP = 0x229,
	BTL_DGUN_FP_HURT = 0x22A,
	BTL_DGUN_FP_DOT_HURT = 0x22B,
	BTL_DGUN_FP_IDLE = 0x22C,
	BTL_DGUN_BLOCK_DEF = 0x22D,
	BTL_DGUN_BLOCK_START = 0x22E,
	BTL_DGUN_BLOCK_END = 0x22F,
	BTL_DGUN_DODGE = 0x230,
	BTL_DGUN_KD_FLYING = 0x231,
	BTL_DGUN_KD_LANDING = 0x232,
	BTL_DGUN_KD_HURT = 0x233,
	BTL_DGUN_KD_STAND_UP = 0x234,
	BTL_DGUN_COUNTER = 0x235,
	BTL_DGUN_GUARD_CRUSH = 0x236,
	BATTLE_ANIMATION_END = 0x236,
};

//Common Animation
enum ECommonAnimationList
{
	COMMON_ANIMATION_START = 0x1,
	NML_SPAWN = 0x1,
	NML_IDLE_LOOP = 0x2,
	NML_IDLE_01 = 0x3,
	NML_IDLE_02 = 0x4,
	NML_IDLE_HURT = 0x5,
	NML_IDLE_DOT_HURT = 0x6,
	SIT_DOWN = 0x7,
	SIT_IDLE = 0x8,
	SIT_UP = 0x9,
	SIT_HURT = 0xA,
	JUMP_START = 0xB,
	JUMP_HOVER = 0xC,
	JUMP_LANDING_SHORT = 0xD,
	JUMP_LANDING_LONG = 0xE,
	WALK_FRONT = 0xF,
	RUN_FRONT = 0x10,
	IDLE_RUN_FRONT = 0x11,
	RUN_BACK = 0x12,
	IDLE_RUN_BACK = 0x13,
	TURN_LEFT = 0x14,
	TURN_RIGHT = 0x15,
	SWIM_IDLE = 0x16,
	SWIM_FRONT = 0x17,
	SWIM_BACK = 0x18,
	SWIM_IDLE_HURT = 0x19,
	SWIM_FAINTING = 0x1A,
	HOVER_IDLE = 0x1B,
	HOVER_FRONT = 0x1C,
	HOVER_IDLE_HURT = 0x1D,
	HOVER_UP = 0x1E,
	HOVER_DOWN = 0x1F,
	HOVER_LANDING = 0x20,
	FAINTING = 0x21,
	FAINTING_STAND_UP = 0x22,
	NML_DASH_FRONT = 0x23,
	NML_DASH_FRONT_LANDING = 0x24,
	NML_DASH_BACK = 0x25,
	NML_DASH_BACK_LANDING = 0x26,
	NML_DASH_LEFT = 0x27,
	NML_DASH_LEFT_LANDING = 0x28,
	NML_DASH_RIGHT = 0x29,
	NML_DASH_RIGHT_LANDING = 0x2A,
	NML_CHARGE_START = 0x2B,
	NML_CHARGE_LOOP = 0x2C,
	NML_CHARGE_END = 0x2D,
	NML_RIDE = 0x2E,
	NML_SCOUTER_ON_OFF = 0x2F,
	NML_SCOUTER_BURST = 0x30,
	NML_SKILL_ABILITY = 0x31,
	NML_TRANSFORM_SEQUELA = 0x32,
	NML_USE_HOIPOI_CAPSULE = 0x33,
	NML_STAFF_IDLE_LOOP = 0x34,
	NML_STAFF_IDLE_01 = 0x35,
	NML_STAFF_IDLE_02 = 0x36,
	NML_STAFF_FRONT_RUN = 0x37,
	NML_STAFF_IDLE_RUN_FRONT = 0x38,
	NML_STAFF_BACK_RUN = 0x39,
	NML_STAFF_LEFT_TURN = 0x3A,
	NML_STAFF_RIGHT_TURN = 0x3B,
	NML_STAFF_SIT_DOWN = 0x3C,
	NML_STAFF_SIT_IDLE = 0x3D,
	NML_STAFF_SIT_UP = 0x3E,
	NML_DGUN_IDLE_LOOP = 0x3F,
	NML_DGUN_IDLE_01 = 0x40,
	NML_DGUN_IDLE_02 = 0x41,
	NML_DGUN_FRONT_RUN = 0x42,
	NML_DGUN_IDLE_RUN_FRONT = 0x43,
	NML_DGUN_SIT_DOWN = 0x44,
	NML_DGUN_SIT_IDLE = 0x45,
	NML_DGUN_SIT_UP = 0x46,
	NML_RETURN_START = 0x47,
	NML_RETURN_CASTING = 0x48,
	NML_RETURN_END = 0x49,
	NML_COMMON_ANIM_01 = 0x4A,
	FLYING_MOVE_FRONT = 0x4B,
	FLYING_MOVE_BACK = 0x4C,
	FLYING_MOVE_RIGHT = 0x4D,
	FLYING_MOVE_LEFT = 0x4E,
	NML_MOVE_LEFT = 0x4F,
	NML_MOVE_RIGHT = 0x50,
	FLYING_DASH_FRONT = 0x56,
	FLYING_DASH_BACK = 0x57,
	FLYING_STAND_UP = 0x58,
	FLYING_STAND_DOWN = 0x59,
	FLYING_STAND_IDLE = 0x5A,
	FLYING_JUMP_HIGH = 0x5B,
	FLYING_POSE_1 = 0x5C,		// flying front with hands out (accel in tw)
	FLYING_POSE_2 = 0x5D,		// flying front with hands on body
	FLYING_POSE_3 = 0x5E,		// flying front with hands front
	COMMON_ANIMATION_END_CURRENT = 0x5F,
	COMMON_ANIMATION_END = 0x64,
};

// ���� ������ �ִϸ��̼� ����Ʈ
enum ETransformAnimationList
{   
	TRANSFORM_ANIMATION_START = 0x1194,
	TRANS_IDLE = 0x1194,
	TRANS_RUN_FRONT = 0x1195,
	TRANS_RUN_BACK = 0x1196,
	TRANS_ATK_DEF_1 = 0x1197,
	TRANS_ATK_DEF_2 = 0x1198,
	TRANS_SPAWN = 0x1199,
	TRANSFORM_ANIMATION_END = 0x1199,
};

// PC�� Trigger Animation List
enum ETriggerAnimationList
{
    PC_TRIGGER_ANIMATION_START = 4000,
    PC_TRIGGER_ANIMATION_END = PC_TRIGGER_ANIMATION_START + 100,
};

// PC�� ��Ŭ�� Ż���� �ִϸ��̼� ����Ʈ
enum EPCVehicleSRPAnimationList
{
	VEHICLE_SRP1_ANIMATION_START = 0x1388,
	VEHICLE_SRP1_IDLE = 0x1388,
	VEHICLE_SRP1_RUN = 0x1389,
	VEHICLE_SRP1_START = 0x138A,
	VEHICLE_SRP1_STOP = 0x138B,
	VEHICLE_SRP1_JUMP = 0x138C,
	VEHICLE_SRP1_TURN_LEFT = 0x138D,
	VEHICLE_SRP1_TURN_RIGHT = 0x138E,
	VEHICLE_SRP1_LANDING = 0x138F,
	VEHICLE_SRP1_ANIMATION_END = 0x138F,
	VEHICLE_SRP2_ANIMATION_START = 0x13EC,
	VEHICLE_SRP2_IDLE = 0x13EC,
	VEHICLE_SRP2_RUN = 0x13ED,
	VEHICLE_SRP2_START = 0x13EE,
	VEHICLE_SRP2_STOP = 0x13EF,
	VEHICLE_SRP2_JUMP = 0x13F0,
	VEHICLE_SRP2_TURN_LEFT = 0x13F1,
	VEHICLE_SRP2_TURN_RIGHT = 0x13F2,
	VEHICLE_SRP2_LANDING = 0x13F3,
	VEHICLE_SRP2_ANIMATION_END = 0x13F3,
};

/// SubWeapon�� Animation List
enum EItemAnimationList
{
	ITEM_ANIMATION_START = 1,
	ITEM_IDLE = 1,
	ITEM_ATTACK,

	ITEM_ANIMATION_END = ITEM_ATTACK,
};

/// Trigger Object�� Animation List
enum EObjectAnimationList
{
	OBJECT_ANIMATION_START = 1,	
	OBJECT_ANIMATION_END = 20,
};

/// Ż�� �ִϸ��̼� ����Ʈ
enum EVehicleAnimationList
{
    VEHICLE_ANIMATION_START = 1,
    VEHICLE_IDLE = VEHICLE_ANIMATION_START,
    VEHICLE_RUN,
    VEHICLE_START,
    VEHICLE_STOP,
    VEHICLE_JUMP,
    VEHICLE_TURN_LEFT,
    VEHICLE_TURN_RIGHT,
    VEHICLE_LANDING,
    VEHICLE_ANIMATION_END,
};

/// ������ ��� �ִϸ��̼� ����Ʈ
enum EItemUseAnimationList
{
    ITEM_USE_ANIMATION_START = 6000,
    ITEM_USE_ANIMATION_END = 6050,
};

//Animaiton Event
enum EAnimEventType
{
	EVENT_ANIM_NONE,							///< Default
	EVENT_ANIM_END,								///< Animation Play�� ������ ��
	EVENT_ANIM_HIT,								///< Hit Event
    EVENT_ANIM_VISUAL_EFFECT,					///< Visual Effect�� ���� �� (Loop Effect�� ��� Animation�� �ٲ� ��� �Ҹ�ȴ�.)
    EVENT_ANIM_VISUAL_SOUND,					///< Sound�� Play�� �ؾ� �� ���
    EVENT_ANIM_FOOT_STEP,						///< Character�� ���� ���� ������ ���
    EVENT_ANIM_LINK_EFFECT,						///< Character�� Create�� �� �� ���� �ٴ� Effect (Loop Effect�� ����)
    EVENT_ANIM_WEIGHT_TIME,						///< Character���� �������� Ư�� �ð� ���� Time�� ������ �Ǵ� �ʰ� Play �Ұ��(HTB������ ����� �ȴ�.)
    EVENT_ANIM_TRACE_EFFECT,                    ///< ���� ����Ʈ �̺�Ʈ
    EVENT_ANIM_SUB_WEAPON,                      ///< SubWeapon Ȱ��ȭ �̺�Ʈ
    EVENT_ANIM_POST_EFFECT,						///< PostEffect Event
	EVENT_ANIM_SUMMON_PET,						///< SummonPet Effect
    EVENT_ANIM_TMQ,                             ///< TMQ Event
    EVENT_ANIM_ALPHA,                           ///< Alpha Fade Event
    EVENT_ANIM_EXPLOSION,                       ///< TMQ ���� �̺�Ʈ
    EVENT_ANIM_DIRECT,                          ///< ����� �̺�Ʈ
    EVENT_ANIM_COLOR_CHANGE,                    ///< �÷� ü���� �̺�Ʈ
    EVENT_ANIM_STRETCH,                         ///< ���� �ø��� �̺�Ʈ
    EVENT_ANIM_TRIGGER,                         ///< ��ų��� ���Ǵ� Ʈ���� �̺�Ʈ
    EVENT_ANIM_SKILL_CANCEL,                    ///< ��ų ĵ�� Ÿ�̹� �̺�Ʈ
};

enum ETargetBehavior
{
	//Chain Attack
	TARGET_BEHAVIOR_NONE,						///< Default
	TARGET_BEHAVIOR_PUSH,						///< Target�� �ڷ� �и���.
	TARGET_BEHAVIOR_KNOCK_DOWN,					///< Target�� �ڷ� ���� ����.
	
	//HTB
	TARGET_BEHAVIOR_TOSS,						///< Target�� �������� �ø���.
	TARGET_BEHAVIOR_FALL_DOWN,					///< Target�� �ٴ����� ���� ģ��.
};

enum EModuleSkillAnimationList
{
	MODULE_SKILL_ANIMATION_START = 7000,
	MODULE_SKILL_ANIMATION_END = 7400,
};

enum EAttackType
{
	ATTACK_TYPE_PHYSICAL = 0x0,
	ATTACK_TYPE_ENERGY = 0x1,
};

enum EHandType
{
	HAND_TYPE_LEFT = 0x0,
	HAND_TYPE_RIGHT = 0x1,
};

// Projectile�� ��� �������� �÷���
enum EBoneType
{
	BONE_CHARACTER,       ///< ĳ������ Bone���� �߻�ȴ�.
	BONE_WEAPON,          ///< Weapon�� Bone���� �߻�ȴ�. (�ϳ��� Bone�̸����� �������ִ�.)
	BONE_SUB_WEAPON,      ///< Sub Weapon�� Bone���� �߻�ȴ�. (3���̻��� Bone���� ���������� ����ȴ�)
};

// ��� SubWeapon Bone�� ��������(�ߺ���������)�� ���Ǵ� Flag
enum ESubWeaponBoneFlag
{
	SUB_WEAPON_PROJECTILE_1 = 1,
	SUB_WEAPON_PROJECTILE_2 = 2,
	SUB_WEAPON_PROJECTILE_3 = 4,
};

// SubWeapon Event�� ���Ǵ� Flag
enum ESubWeaponActiveFlag
{
	SUB_WEAPON_ACTIVE,      ///< SubWeapon Ȱ��ȭ (SubWeapon���� ���⸦ ü���� �Ѵ�.)
	SUB_WEAPON_DEACTIVE,    ///< SubWeapon ��Ȱ�� (�Ϲ� Weapon���� ���⸦ ü���� �Ѵ�.)
};

// PostEffect Event�� ���Ǵ� Ÿ�� �÷���
enum EPostEffectTypeFlag
{
	POST_EFFECT_TARGET_TYPE_SELF,     ///< PC�� Post Effect ��ġ ����
	POST_EFFECT_TARGET_TYPE_TARGET,  ///< ������ Post Effect ��ġ ����        
};

/// Target�� ǥ�õ� Effect�� ���� ���� �÷���
enum ETargetEffectType
{
	TARGET_EFFECT_TYPE_NONE,		///< �ƹ��� �������� ���� �Ϲ� ����Ʈ
	TARGET_EFFECT_TYPE_SIDE,		///< Ÿ���� ���������� ����Ǵ� ����Ʈ
	TARGET_EFFECT_TYPE_FRONT,		///< Ÿ���� ���� ����(or �ĸ� ����)���� ����Ǵ� ����Ʈ
};

// Projectile Effect Type
enum EProjectileEffectType
{
	BEID_PROJ_BALL = 2000,
	BEID_PROJ_BEAM = 2001,
	BEID_PROJ_HISSIDAN = 2002,
	BEID_PROJ_HELLZONE = 2003,
	BEID_PROJ_MULTI_HISSIDAN = 2004,
	BEID_PROJ_MAGARE = 2005,
};

enum EAnimCinematicEventType
{
	E_ANIM_CINEMATIC_TMQ_IN = 0x0,
	E_ANIM_CINEMATIC_TMQ_OUT = 0x1,
	E_ANIM_CINEMATIC_DWC_IN = 0x2,
};

// Explosion event type
enum ENtlPLExplosionEventType
{
	EXPLOSION_EVENT_TYPE_SMALL = 0,	// ���� ����
	EXPLOSION_EVENT_TYPE_NORMAL = 1,	// �߰� ����
	EXPLOSION_EVENT_TYPE_BIG = 2,	// ū ����
};

// Direct Event Type
enum ENtlPLDirectEventType
{
	DIRECT_EVENT_TYPE_CAMERA_SHAKE,
};

// Foot Step Type
enum EFootStepType
{
	FOOT_LEFT = 0,
	FOOT_RIGHT = 1,
};

// ���ڱ����� � �Ҹ��� ���� Mob Ÿ��
enum EFootStepMobType
{
	FOOT_TYPE_NORMAL,
	FOOT_TYPE_LARGE,
};

enum EColorChangeType
{
	COLOR_CHANGE_TYPE_START,
	COLOR_CHANGE_TYPE_END,
	COLOR_CHANGE_TYPE_ANIM,
};

/// ��Ʈ��ġ �̺�Ʈ Ÿ��
enum EStretchEventType
{
	E_STRETCH_PULLING,              ///< Ǯ�� (���ſ�)
	E_STRETCH_HIT,                  ///< ��Ʈ (���������� ��ġ)
};


// ���־� ����Ʈ Attach Ÿ��
enum EVEAttachType
{
	VE_ATTACH_POS = 0,              ///< ���� ��ġ�� Attach
	VE_ATTACH_BONE,                 ///< ���� ���� Attach
};

//////////////////////////////////////////////////////////////////////////

struct SEventAnim
{
	RwReal			fTime;
	EAnimEventType	eEventID;

	SEventAnim() : fTime(ANIM_EVENT_NONE_TIME) {}
};

#if _IS_SERVER_

// Projectile Type�� ���� �߰� �Ķ���͵��� �����ϱ� ���� Union
struct SHissidanData        /// Hissidan Ÿ���� ���� �߰� ������
{
	RwBool      bApplyAngle;                              ///< ���� ����/������ ���� (�������� �ϸ� Hand Type�� ���� ������ �ش�)
	RwV2d       v2dAngle;                                   ///< �߻� ���� (X��, Y��)
};

struct SMultiHissidanData   /// Multi Hissidan Ÿ���� ���� �߰� ������
{
	RwInt32     nCount;                                   ///< Hissidan ����
	RwV2d*      pArrayAngle;                              ///< �߻� �������� �迭 (���� �Ҵ��Ѵ�)
};

struct SHellZoneData        /// ���� ����ź�� Ÿ���� ���� �߰� ������
{
	RwV3d				vTargetEffectOffset;						///< Target������ Offset �Ÿ�
	RwReal				fTargetEffectStartWaitTime;					///< Target�� ���ư��� ���� ��ٸ��� �ð�
	RwReal				fTargetEffectSpeed;							///< Target�� ���ư��� �ӵ�
};

union UEffectTypeExtraData
{
	SHissidanData       hissidanData;
	SMultiHissidanData  multiHissidanData;
	SHellZoneData       hellZoneData;
};


// Alpha Event 
struct SEventAlpha : SEventAnim
{
	// Alpha Event Apply Type
	enum EAlphaEventType
	{
		E_ALPHA_EVENT_CLUMP,
		E_ALPHA_EVENT_ATOMIC,
	};
	//////////////////////////////////////////////////////////////////////////

	RwInt32       nStartAlpha;              ///< Fade ���� ���İ� (0~255)
	RwInt32       nDestAlpha;               ///< Fade Dest ���İ� (0~255)    
	RwReal        fFadeTime;                ///< Fade �Ǵ� �ð�
	RwReal        fLifeTime;                ///< �̺�Ʈ�� �����Ǵ� Life Time
	EAlphaEventType eAlphaEventType;        ///< ���� �̺�Ʈ ���� Ÿ��
	unsigned int       bfAtomicList;             ///< ���İ� ����� ����͵��� Index �÷���
};

// Į�� ü���� �̺�Ʈ
struct SEventColorChange : SEventAnim
{
	EColorChangeType eType;
	RwRGBA           colorEdge;
	RwRGBA           colorBody;
	RwRGBA           colorAdd;
};

struct SEventLinkEffect : public SEventAnim
{
	RwChar  chEffectName[MAX_DEFAULT_NAME];
	RwChar  chBoneName[MAX_DEFAULT_NAME];
	RwV3d   vOffsetPos;
	RwBool  bAttachBone;

	SEventLinkEffect()
	{
		eEventID = EVENT_ANIM_LINK_EFFECT;
		ZeroMemory(chEffectName, sizeof(chEffectName));
		ZeroMemory(chBoneName, sizeof(chBoneName));
		ZeroMemory(&vOffsetPos, sizeof(vOffsetPos));
		bAttachBone = FALSE;
	}

};

struct SEventAnimEnd : public SEventAnim
{
	RwUInt32	uiAnimKey;
	SEventAnimEnd() : uiAnimKey(0) { eEventID = EVENT_ANIM_END; }

};


struct SEventFootStep : public SEventAnim
{
	EFootStepType eFootStepType;
	EFootStepMobType eFootStepMobType;

	SEventFootStep()
	{
		eEventID = EVENT_ANIM_FOOT_STEP;
		eFootStepType = FOOT_LEFT;
		eFootStepMobType = FOOT_TYPE_NORMAL;
	}
};

struct SEventVisualEffect : public SEventAnim
{
	RwChar  chEffectName[MAX_DEFAULT_NAME];     ///< Effect Name;
	EBoneType eBoneType;                        ///< Effect�� ���� Bone Type
	RwChar  chBoneName[MAX_DEFAULT_NAME];       ///< Attach�� �� Bone Name
	RwV3d   vOffSetPos;                         //<  Offset;    
	RwBool  bAttach;                            ///< �𵨿� Attach ���� ����
	RwBool  bAttachBone;                        ///< Bone�� Attach ���� ���� (TRUE = Bone Attach, FALSE = Pos Attach)
	RwBool  bApplyScale;                        ///< �θ� Entity�� Scale�� �������� ����
	RwBool  bProjectileType;                    ///< �߻�üŸ������ ����

	unsigned int uiUnknown;

	SEventVisualEffect() : eBoneType(BONE_CHARACTER)
	{
		ZeroMemory(chBoneName, sizeof(chBoneName));
		ZeroMemory(chEffectName, sizeof(chEffectName));
		ZeroMemory(&vOffSetPos, sizeof(vOffSetPos));
		bAttach = TRUE;
		bAttachBone = FALSE;
		bApplyScale = TRUE;
		bProjectileType = FALSE;

		uiUnknown = 0;

		eEventID = EVENT_ANIM_VISUAL_EFFECT;
	}

};

///////////////////////////////////////////////////////////////////////////
// Slow Time Event
//////////////////////////////////////////////////////////////////////////
struct SEventWeightTime : public SEventAnim
{
	RwReal fLifeTime;       ///< Slow ȿ���� ���ֵ� �ð�
	RwReal fWeightValue;    ///< �󸶳� ���������� ���� Weight��

	SEventWeightTime()
	{
		eEventID = EVENT_ANIM_WEIGHT_TIME;
		fLifeTime = 0.0f;
		fWeightValue = 1.0f;
	}

};


/// Sub Weapon Ȱ��ȭ �̺�Ʈ
struct SEventSubWeapon : SEventAnim
{
	ESubWeaponActiveFlag    eSubWeaponActiveFlag;

	SEventSubWeapon() : eSubWeaponActiveFlag(SUB_WEAPON_DEACTIVE)
	{
		eEventID = EVENT_ANIM_SUB_WEAPON;
	}

};

/// Post Effect �̺�Ʈ (ȭ������ �߽ɼ� ǥ�� �̺�Ʈ)
struct SEventPostEffect : SEventAnim
{
	RwChar                   szPostEffectName[MAX_DEFAULT_NAME];          ///< ���� PostEffect�� �̸�
	EPostEffectTypeFlag      eTarget;                                     ///< PostEffect�� Target ����
	RwV3d                    v3dOffset;                                   ///< PostEffect�� ���� ��ġ�� Offset��
	RwBool                   bCenterFixEnable;                            ///< �߽��� ���� ���
	RwReal                   fTargetHeight;                               ///< ����� Ÿ������ �����Ѱ�� ���̰�(�ٿ���ڽ� ��밪)
	RwChar                   szPCBoneName[MAX_DEFAULT_NAME];              ///< ����� PC�� �����Ѱ�� Attach�� Bone�� �̸�

	SEventPostEffect()
	{
		eEventID = EVENT_ANIM_POST_EFFECT;

		ZeroMemory(szPostEffectName, sizeof(szPostEffectName));
		ZeroMemory(&v3dOffset, sizeof(v3dOffset));
		ZeroMemory(szPCBoneName, sizeof(szPCBoneName));
		eTarget = POST_EFFECT_TARGET_TYPE_SELF;
		bCenterFixEnable = TRUE;
		fTargetHeight = 1.0f;
	}

};

// Summon Pet Event
struct SEventSummonPet : SEventAnim
{
	SEventSummonPet()
	{
		eEventID = EVENT_ANIM_SUMMON_PET;
	}
};

struct SEventAnimCinematic : public SEventAnim
{
	EAnimCinematicEventType eAnimCinematicEventType;
};

// ���� �̺�Ʈ
struct SEventExplosion : SEventAnim
{
	ENtlPLExplosionEventType  eType;

	SEventExplosion()
	{
		eEventID = EVENT_ANIM_EXPLOSION;
		eType = EXPLOSION_EVENT_TYPE_NORMAL;
	}
};

// ���� �̺�Ʈ
struct SEventDirect : SEventAnim
{
	ENtlPLDirectEventType eType;

	SEventDirect()
	{
		eEventID = EVENT_ANIM_DIRECT;
		eType = DIRECT_EVENT_TYPE_CAMERA_SHAKE;
	}
};

/// BONE�� �ø��� �̺�Ʈ
struct SEventStretch : SEventAnim
{
	EStretchEventType eType;
	RwChar          szBoneName[2][MAX_DEFAULT_NAME];
	RwReal          fStretchSpeed;
	RwReal          fWidth;
	RwReal          fAccel;
	RwChar          szScaleBone[MAX_DEFAULT_NAME];
	RwReal          fScaleSize;
	RwChar          szAxisBone[MAX_DEFAULT_NAME];
	RwChar          szTargetEffect[MAX_DEFAULT_NAME];
};

struct SEventAnimHit : public SEventAnim
{
	RwUInt32			uiDamage;
	RwBool				bPowerEffect;
	EAttackType			eAttackType;								///< Attack Type
	ETargetBehavior		eTargetBehavior;
	RwBool              bKB2Push;                                   ///< �˴ٿ��� ���� ������ Push�� ó������ ���� �÷���
	EHandType			eHandType;									///< HandType
	EProjectileEffectType uiProjectileEffectType;					///< Ball, Beam, Hissidan, hell zone, Multi Hissidan

	EBoneType			eProjectileShotType;						///< ��� Bone���� Projectile�� ���󰡴��� ����
	RwInt32             nSubWeaponFlag;                             ///< SubWeapon�� ��� Bone���� ������ üũ�� �÷���

	RwChar				chBoneName[MAX_DEFAULT_NAME];				///< Character Bone Name	
	RwChar              chProjectileEffectName[MAX_DEFAULT_NAME];	///< ���󰡴� Effect Name
	RwReal				fProjectileSpeed;							///< projectile speed
	RwBool              bTargetAttach;								///< Effect�� Target�� Attach�� ������ ����
	RwReal              fTargetHeight;								///< Target Effect�� ���� ��ġ (1�� �⺻ 100%)

	RwChar              chTargetEffectName[MAX_DEFAULT_NAME];		///< Target�� ǥ�õ� Effect Name
	ETargetEffectType	eTargetEffectType;							///< Target Effct�� ���� ���� Ÿ��
	RwChar              chSubTargetEffect[MAX_DEFAULT_NAME];        ///< ���� ���ݽ� ���� Ÿ�ٿ��� ǥ�õ� ����Ʈ
	RwChar              chTargetSoundName[MAX_DEFAULT_NAME];		///< Target�� �¾��� ��� ������ Sound File Name
	int					eSoundType;									///< Sound type(CHANNEL_GROUP_VOICE_SOUND or CHANNEL_GROUP_EFFECT_SOUND)    
	RwBool              bHitSoundEcho;                              ///< Hit�� ���尡 Echo ������� ����
	RwBool              bCameraShake;                               ///< Target Hit�� Camera Shake����
	RwReal              fCameraShakeFactor;                         ///< ī�޶� ����ũ ����
	RwReal              fCameraShakeMaxHeight;                      ///< ī�޶� ����ũ �ִ밪 ����
	RwChar              chWordEffect[MAX_DEFAULT_NAME];             ///< Target Hit�� ��Ÿ�� Word Effect (ex. ����)

	UEffectTypeExtraData uEffectTypeExtraData;                      ///< Effect Type�� ���� �߰� ������ Union
};

struct SEventTrace : public SEventAnim
{
	/// Trace�� ��� �������� Ÿ��
	enum EAttachType
	{
		CHARACTER_BONE,     ///< ĳ���� ���� �ٴ´�.
		WEAPONE_BONE,       ///< ���� ���� �ٴ´�.
		SUB_WEAPON_BONE,    ///< �������� ���� �ٴ´�.
	};

	/// ���� ������ �̺�Ʈ �������� ������, Weapon �������� ������ ���
	enum ETraceKind
	{
		EVENT_TRACE,        ///< Event�� �������� ������.
		ITEM_TRACE,         ///< Item�� �������� ������.
	};

	RwReal  fLifeTime;           ///< ������ ǥ�� �ð�
	RwReal  fEdgeLifeTime;       ///< Edge�� Life Time    
	EAttachType eAttachType;     ///< ������ ��� ������ 
	ETraceKind  eTraceKind;      ///< ������ Item ������ ������
	RwChar  strStartBoneName[MAX_DEFAULT_NAME];    ///< ù��° Bone�� �̸�
	RwChar  strEndBoneName[MAX_DEFAULT_NAME];      ///< �ι�° Bone�� �̸�
	RwChar  strTexture[MAX_DEFAULT_NAME];          ///< Texture File Name
	RwV3d   v3dStartBoneOffset;  ///< ù��° Bone�� Offset
	RwV3d   v3dEndBoneOffset;    ///< �ι�° Bone�� Offset
	RwReal  fEdgeGap;             ///< ���ʸ��� Edge�� ���������� ��
	RwInt32 nSplinePointCount;   ///< Spline���� �����ϴ� ���ؽ��� ���� (�ΰ��� Edge���̿� �����Ǵ� ���ؽ��� �����̴�)
	RwInt32 nMaxEdgeCount;       ///< �ִ� Edge Count
	RwReal  fMaxLength;          ///< ������ �ִ� ����
	int		eSrcBlend;  ///< Src Blend State
	int		 eDestBlend; ///< Dest Blend State
	RwRGBA  colStartColor;       ///< ���� Color��
	RwRGBA  colEndColor;         ///< �� Color��   
};


struct SEventSound : public SEventAnim
{
	RwChar	chSoundName[MAX_DEFAULT_NAME * 2]; ///< Sound ���ϸ� (Sound ������ ��θ� ����)
	RwChar	chSoundName2[MAX_DEFAULT_NAME * 2]; ///< Sound ���ϸ� (Sound ������ ��θ� ����)
	RwChar	chSoundName3[MAX_DEFAULT_NAME * 2]; ///< Sound ���ϸ� (Sound ������ ��θ� ����)
	RwChar	chSoundName4[MAX_DEFAULT_NAME * 2]; ///< Sound ���ϸ� (Sound ������ ��θ� ����)
	int		eSoundType;				///< Sound Type (CHANNEL_GROUP_VOICE_SOUND or CHANNEL_GROUP_EFFECT_SOUND)    
	RwBool  bLoop;                              ///< Sound Loop ����
	RwReal  fSoundVolume;                       ///< Sound Volume
	RwReal  fSoundDist;                         ///< ��ȿ �Ÿ�
	RwReal  fSoundDecayDist;                    ///< ���� ���� �Ÿ�
	RwReal  fSoundPitchMin;                     ///< ���� ��ġ �ּҰ�
	RwReal  fSoundPitchMax;                     ///< ���� ��ġ �ִ밪
};


/// ��ų��� ���Ǵ� Ʈ���� �̺�Ʈ
struct SEventTrigger : SEventAnim
{
	SEventTrigger()
	{
		eEventID = EVENT_ANIM_TRIGGER;
	}
};


/// ��ų ĵ���� ���Ǵ� �̺�Ʈ
struct SEventSkillCancel : SEventAnim
{
	SEventSkillCancel()
	{
		eEventID = EVENT_ANIM_SKILL_CANCEL;
	}
};

#endif

#endif