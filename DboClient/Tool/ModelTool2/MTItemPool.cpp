#include "StdAfx.h"
#include "MTItemPool.h"
#include "NtlPLSceneManager.h"

CMTItemPool* CMTItemPool::m_pInstance = NULL;

CMTItemPool::CMTItemPool(void)
{
    m_pInstance = this;
}

CMTItemPool::~CMTItemPool(void)
{
    MapItem::iterator it = m_mapItem.begin();
    for(; it != m_mapItem.end(); ++it)
    {
        CMTItem* pItem = (*it).second;
        GetSceneManager()->DeleteEntity(pItem);
        pItem = NULL;
    }

    m_mapItem.clear();
}

void CMTItemPool::AddItem( CMTItem* pItem ) 
{
    // Mesh Name�� Key�� �Ͽ� �ߺ��� �����ʹ� �߰����� �ʴ´�.
    // NOTE : ���� ���� Mesh�� ���� �ΰ��� ���� �ٸ� Item�� �ִٸ� ������ �ִ�. (���� �׷� ��찡 ���⶧����, �켱 �̷��� �����Ѵ�.-_-;)
    if(m_mapItem.find(pItem->GetProperty()->GetName()) == m_mapItem.end())
    {
        // Visual Manager�� �߰��Ѵ�.
        GetSceneManager()->AddPLEntity(pItem);

        m_mapItem[pItem->GetProperty()->GetName()] = pItem;
    }
}

CMTItem* CMTItemPool::GetItem(RwChar* strItemName)
{
    if(m_mapItem.find(strItemName) == m_mapItem.end())
    {
        return NULL;
    }

    return m_mapItem[strItemName];   
}