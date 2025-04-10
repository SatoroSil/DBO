#pragma once

#include "NtlSharedCommon.h"
#include "NtlXMLDoc.h"

enum ENodeType
{
	NODE_FOLDER,
	NODE_SCIRPT,
};

struct SItemNode
{
	CString strNodeName;
    ENodeType eNodeType;
	
	std::vector<SItemNode*> vecChildList;		// �ڽ� ���� 

	SItemNode()
	{
		eNodeType = NODE_FOLDER;
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
};

typedef std::vector<SItemNode*> VEC_ITEM_NODE;

/** 
 * \ingroup NtlXMLLoader
 * \brief Ʈ���� ���� XML�� �ٷ�� Ŭ����. ���ϻ���/�߰��� ���ؼ� ������ Ŭ�������� ��ӹ޾Ƽ� �������.
 * \date 2006-04-26
 * \author agebreak
 */
class CNtlMTXml : public CNtlXMLDoc
{

public:
    CNtlMTXml(void);
    virtual ~CNtlMTXml(void);

    BOOL CreateXML(char* szRootNodeName);                                           ///< ���ο� XML ��ü�� �����.
    bool Save(char* szFileName);                                  ///< XML�� ���Ϸ� �����Ѵ�.    
    bool LoadTreeXML(char* szFileName, SItemNode* itemNode);               ///< Ʈ�������� XML���Ͽ��� ������ ���͸� ��ȯ�Ѵ�.
    void AddFolderNode(char* szParentFolder,  char* szFolderName); ///< ���ο� ������带 �߰��Ѵ�.
    void AddScriptNode(char* szParentFolder,  char* szScriptName); ///< ���ο� ��ũ��Ʈ ��带 �߰��Ѵ�

protected:
	void LoadScipt(IXMLDOMNode* pNode, SItemNode* pParentItem, bool bRoot = FALSE);		///< ��ũ��Ʈ�� �ε��ϴ� ��� �Լ�

protected:
    IXMLDOMElement*     m_pRootElem;                            ///< Root Element
};
