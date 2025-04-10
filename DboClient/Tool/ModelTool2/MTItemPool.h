#pragma once

#include "MTItem.h"

typedef std::map<std::string, CMTItem*> MapItem;
/**
 * \ingroup ModelTool2
 * \brief Model Tool���� ������ Item���� �����ϴ� Pool Ŭ����. Item�� TreeItem�� ItemView Pane �α����� ���� ����ϱ� ������
 * Pool Ŭ������ ���ؼ� ����Ѵ�.
 * \date 2006-11-02
 * \author agebreak
 */
class CMTItemPool
{
public:
    CMTItemPool(void);
    virtual ~CMTItemPool(void);

    static CMTItemPool* GetInstance() {return m_pInstance;}

    void        AddItem(CMTItem* pItem);        ///< Item�� Map�� �߰��Ѵ�.
    CMTItem*    GetItem(RwChar* strItemName);   ///< Map���� Item�� �����´�.

protected:
    static CMTItemPool* m_pInstance;

    MapItem     m_mapItem;          ///< ������ Item���� Map

};
