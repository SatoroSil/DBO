#pragma once
#include "NtlPLItem.h"
#include "MTCharacterInfo.h"

/**
 * \ingroup ModelTool2
 * \brief Model Tool�� ���̴� Item Ŭ����
 * \date 2006-06-26
 * \author agebreak
 */
class CMTItem : public CNtlPLItem
{
public:
    CMTItem(void);
    virtual ~CMTItem(void);

    /// Memory Pool�� ������� �ʱ� ������ new/delete�� Overriding �Ѵ�.
    void* operator new(size_t size);
    void operator delete(void *pObj);

    virtual RwBool  Create(const RwChar* szDffFileName, RwBool bEquip = FALSE);                         ///< Clump ���Ϸκ��� ��ü�� �����Ѵ�.
    virtual void    Destroy(void);    

    virtual void	SetRemoveEquip();    
    virtual void    SetVisible(RwBool bVisible);
    virtual void    AddWorld(void);    
    virtual void    RemoveWorld();

    CMTClump* GetClumpInfo() {return &m_MTClump;}                               ///< MTClump ��ü�� ��ȯ�Ѵ�.

    // Link Effect ����
    CNtlInstanceEffect* GetLinkEffectFromName(RwChar* szName);              ///< Name�� �ش��ϴ� LinkEffect�� ��ȯ�Ѵ�.

protected:
    CMTClump    m_MTClump;                                                      ///< Clump ���� ��ü    
    RwBool      m_bEquipView;                                                   ///< ����������� ������ ���������� �ƴ��� ����
};
