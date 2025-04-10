#pragma once

#include "NtlSharedCommon.h"
#include "NtlXMLDoc.h"
#include "MTDef.h"

/**
 * \ingroup ModelTool2
 * \brief Ŭ���̾�Ʈ���� ����� ĳ����(MOB ����), ������Ʈ���� PropertyList.xml�� �����ϴ� Ŭ����
 * \date 2006-06-09
 * \author agebreak
 */
class CPropertyListXML : public CNtlXMLDoc
{
public:
    enum EProperyListMode
    {
        PROPERTY_CHARACTER,
        PROPERTY_OBJECT,
        PROPERTY_ITEM,
    };

public:
    CPropertyListXML(void);
    virtual ~CPropertyListXML(void);
    
    RwBool Save(const CHAR* szFileName, EProperyListMode eMode, CTreeCtrl* pTreeCtrl, TREEITEM_VECTOR vTreeItem);     ///< PropertyList�� XML���·� �����Ѵ�.

protected:
    RwBool CreateHeader();
    RwBool CreateElemList(CTreeCtrl* pTreeCtrl, TREEITEM_VECTOR vTreeItem);

    RwBool SetIndent();                                             ///< XML�� ��Ÿ�� ��Ʈ�� �����Ѵ�. (indent.xls)

protected:
    IXMLDOMElement* m_pRootElem;
    IXMLDOMElement* m_pListElem;

    CString         m_strPropetyName;
    CString         m_strDataPath;
    
};
