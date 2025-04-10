#pragma once

#include "VenusXMLDoc.h"
#include <map>

enum ENodeType
{
	NODE_FOLDER,
	NODE_SCIRPT,
    NODE_NONE,
};

struct SItemNode
{
	CString strNodeName;
    ENodeType eNodeType;    
	
	std::vector<SItemNode*> vecChildList;		// �ڽ� ���� 

	SItemNode()
	{
		eNodeType = NODE_NONE;
		vecChildList.reserve(30);
	}

	~SItemNode()
	{
		for each(SItemNode* pItemNode in vecChildList)
		{
			delete pItemNode;
			pItemNode = NULL;
		}
		vecChildList.clear();
	}

    SItemNode* EraseChildNode(SItemNode* pChildNode)
    {
        std::vector<SItemNode*>::iterator it;
        for(it = vecChildList.begin(); it != vecChildList.end(); ++it)
        {
            SItemNode* pItemNode = *it;
            if(pItemNode == pChildNode)
            {
                vecChildList.erase(it);
                return pItemNode;                
            }
        }

        return NULL;
    }

    SItemNode* EraseChildNode(const CString& strNodeName)
    {
        std::vector<SItemNode*>::iterator it;
        for(it = vecChildList.begin(); it != vecChildList.end(); ++it)
        {
            SItemNode* pItemNode = *it;
            if(pItemNode->strNodeName == strNodeName)
            {
                vecChildList.erase(it);
                return pItemNode;
            }
        }        

        return NULL;
    }

    RwBool IsChildNode(SItemNode* pChildNode)
    {
        if(this == pChildNode)
            return TRUE;

        for each(SItemNode* pItemNode in vecChildList)
        {
            if(pItemNode->IsChildNode(pChildNode))
                return TRUE;
        }

        return FALSE;
    }

    void SortChild()
    {
        std::map<CString, SItemNode*> mapSort;
        for each(SItemNode* pItemNode in vecChildList)
        {
            mapSort[pItemNode->strNodeName] = pItemNode;
        }

        vecChildList.clear();

        for each(std::pair<CString, SItemNode*> it in mapSort)
        {
            vecChildList.push_back(it.second);
        }
    }

    SItemNode* GetChildNode(const CString& strName)
    {
        for each(SItemNode* pItemNode in vecChildList)
        {
            if(pItemNode->strNodeName == strName)
                return pItemNode;
        }

        return NULL;
    }
};

typedef std::vector<SItemNode*> VEC_ITEM_NODE;

/** 
 * \ingroup NtlXMLLoader
 * \brief Ʈ���� ���� XML�� �ٷ�� Ŭ����. ���ϻ���/�߰��� ���ؼ� ������ Ŭ�������� ��ӹ޾Ƽ� �������.
 * \date 2006-04-26
 * \author agebreak
 */
class CNtlTreeXml : public CVenusXMLDoc
{
public:
    CNtlTreeXml(void); 
    virtual ~CNtlTreeXml(void);

    BOOL CreateXML(WCHAR* szRootNodeName);                                           ///< ���ο� XML ��ü�� �����.
    bool Save(WCHAR* szFileName);                                  ///< XML�� ���Ϸ� �����Ѵ�.    
    bool LoadTreeXML(WCHAR* szFileName, SItemNode* itemNode);               ///< Ʈ�������� XML���Ͽ��� ������ ���͸� ��ȯ�Ѵ�.
    void AddFolderNode(WCHAR* szParentFolder,  WCHAR* szFolderName); ///< ���ο� ������带 �߰��Ѵ�.
    void AddScriptNode(WCHAR* szParentFolder,  WCHAR* szScriptName); ///< ���ο� ��ũ��Ʈ ��带 �߰��Ѵ�

protected:
	void LoadScipt(IXMLDOMNode* pNode, SItemNode* pParentItem, bool bRoot = FALSE);		///< ��ũ��Ʈ�� �ε��ϴ� ��� �Լ�

public:
    static std::map<CString, SItemNode*>            m_mapNode;          ///< Node���� �˻��ϱ� ���� Map

protected:
    IXMLDOMElement*     m_pRootElem;                            ///< Root Element
};
