#ifndef _MTSCRIPTDATA_H
#define _MTSCRIPTDATA_H

#include "NtlPLCharacter.h"

/// ��ũ��Ʈ�� ������ �����ϴ� ����ü
struct SMTScriptData
{
    std::string     m_sClumpFileName;                   ///< ���Ǵ� Clump ���ϸ�
    SBoneScaleData  m_BoneScaledata[MAX_NUM_BONES];     ///< Bone�� ������ ����ִ� ����ü �迭
    RwInt32         m_nBoneNum;                         ///< Bone�� ����

    // todo. Anim ���� ������ ���� �ʿ�

    SMTScriptData()
    {
        m_sClumpFileName = "";
        ZeroMemory(m_BoneScaledata, sizeof(m_BoneScaledata));
        m_nBoneNum = 0;
    };
};


#endif