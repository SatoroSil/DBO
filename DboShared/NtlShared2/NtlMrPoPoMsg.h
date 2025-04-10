/// Ŭ���̾�Ʈ ����Ʈ ��(Mr.PoPo)�� Ŭ���̾�Ʈ ���� �����ϴ� ������ �޽���

#pragma once

#define MSG_FROM_MRPOPO                 (WM_USER + 2374)                  ///< ����Ʈ ���κ����� �޽���

enum EMrPoPoMsg
{
    MSG_MRPOPO_CREATE_ITEM = (WM_USER + 101),
    MSG_MRPOPO_UPGRADE_ITEM,
    MSG_MRPOPO_SET_ZENNY,
    MSG_MRPOPO_ADD_EXP,    
    MSG_MRPOPO_SET_LEVEL,
    MSG_MRPOPO_COLLECT_DRAGONBALL,
    MSG_MRPOPO_SETSPEED,
    MSG_MRPOPO_SETOFFENCE,
    MSG_MRPOPO_SETDEFNECE,
    MSG_MRPOPO_TEST_CROWD,                          ///< ���� ���� �׽�Ʈ
    MSG_MRPOPO_TELEPORT,
    MSG_MRPOPO_TELE_DIRECT_X,
    MSG_MRPOPO_TELE_DIRECT_Z,
    MSG_MRPOPO_OBSERVER_STATIC,
    MSG_MRPOPO_OBSERVER_LUA,
    MSG_MRPOPO_FREECAMERA,
    MSG_MRPOPO_SCOUTER_RENDER,
    MSG_MRPOPO_RENDER_MESHSYSTEM,
    MSG_MRPOPO_RENDER_DECALSYSTEM,
    MSG_MRPOPO_LEARN_ALL_SKILL,
    MSG_MRPOPO_UPGRADE_ALL_SKILL,
    MSG_MRPOPO_CREATE_LEVEL_ITEMS,
    MSG_MRPOPO_SUPER_MODE,    

    // Ŭ���̾�Ʈ ġƮ
    MSG_MRPOPO_ELAPSEDTIME_WEIGHT = 1000,                  ///< �ð� ����
    MSG_MRPOPO_DUMP_TO_CONSOLE,                     ///< �ܼ�â ����
    MSG_MRPOPO_DUMP_TO_GUI,                         ///< GUI ����
    MSG_MRPOPO_DUMP_TO_FILE,                        ///< ���� ����
    MSG_MRPOPO_DUMP,                                ///< ������ ���    
    MSG_MRPOPO_DUMP_REG,                            ///< Ÿ���� ���� ��� ���
    MSG_MRPOPO_DUMP_UNREG,                          ///< Ÿ���� ���� ��� ����
    MSG_MRPOPO_LOWSPEC_CHAR,                        ///< ����� ĳ����
    MSG_MRPOPO_LOWSPEC_EFFECT,                      ///< ����� ����Ʈ
    MSG_MRPOPO_TEST1,                               ///< �׽�Ʈ�� ����
    MSG_MRPOPO_TEST2,                               ///< �׽�Ʈ�� ����
    MSG_MRPOPO_TEST3,                               ///< �׽�Ʈ�� ����
    MSG_MRPOPO_TENKAICHI_MARK,                      ///< õ������ ����ȸ ��ũ �׽�Ʈ
    MSG_MRPOPO_TEST_CHANGECOLOR,                    ///< �÷� ���� �̺�Ʈ �׽�Ʈ
    MSG_MRPOPO_TRANSLATE_STATE,                     ///< ���� ����
    MSG_MRPOPO_TRANSFORM,                           ///< ���� 
    MSG_MRPOPO_STUN,                                ///< ���� ���µ� �׽�Ʈ
    MSG_MRPOPO_TARGET_MARKING,                      ///< ��ų�� Ÿ������ Ÿ���� �׽�Ʈ
    MSG_MRPOPO_PUSHING,                             ///< ȸ�� ���ݿ� ���� Push �׽�Ʈ

    // �׷��� ����
    MSG_MRPOPO_SPEC_TERRAIN_DIST = 2000,             ///< ���� �Ÿ�
    MSG_MRPOPO_SPEC_TERRAIN_SHADOW,                 ///< ���� �׸���
    MSG_MRPOPO_SPEC_WATER_SPECULAR,                 ///< ���� ����ŧ��
	MSG_MRPOPO_SPEC_CHAR_DIST,                      ///< ĳ���� Dist
    MSG_MRPOPO_SPEC_CHAR_EDGE,                      ///< ĳ���� EDGE
	MSG_MRPOPO_SPEC_CHAR_GRAYCOLOR,                 ///< ĳ���� Gray Color
    MSG_MRPOPO_SPEC_EFFECT,                         ///< �ο� ���� ����Ʈ
	MSG_MRPOPO_SPEC_EFFECT_PARTICLE_RATIO,          ///< Particle Ratio
	MSG_MRPOPO_SPEC_EFFECT_MESH,					///< Mesh Effect
	MSG_MRPOPO_SPEC_EFFECT_DECAL,			        ///< Decal Effect
};

enum EMPPTeleport
{
    MPP_TELE_YAHOI,             // ��ȣ�� ����
    MPP_TELE_YUREKA,            // ����ī ����
    MPP_TELE_DALPANG,           // ������ ����
    MPP_TELE_DRAGON,            // ���� �ڰ���
    MPP_TELE_BAEE,              // �迡 ������
    MPP_TELE_AJIRANG,           // �������� ��
    MPP_TELE_KARINGA_1,         // ī������ ���� 1
    MPP_TELE_KARINGA_2,         // ī������ ���� 2
    MPP_TELE_GREAT_TREE,        // �׷���Ʈ Ʈ��
    MPP_TELE_KARINGA_3,         // ī������ ����
    MPP_TELE_MERMAID,           // �ξ��
    MPP_TELE_GANNET,            // ���� õ����
    MPP_TELE_EMERALD,           // ���޶��� ��ġ
    MPP_TELE_TEMBARIN,          // �۹��� ķ��    
    MPP_TELE_CELL,              // �и�
    MPP_TELE_BUU,               // �ο� ����
    MPP_TELE_CC,                // CC ���� �ڹ���
    MPP_TELE_MUSHROOM,          // ������
	MPP_TELE_PAPAYA,
};

/// ���� Ÿ��
enum EMPPDumpTarget
{
    MPP_DUMP_SELF,
    MPP_DUMP_TARGET,    
};
