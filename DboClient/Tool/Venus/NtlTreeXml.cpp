#include "StdAfx.h"
#include "comutil.h"
#include "NtlTreeXml.h"

std::map<CString, SItemNode*> CNtlTreeXml::m_mapNode;          ///< Node���� �˻��ϱ� ���� Map

CNtlTreeXml::CNtlTreeXml(void)
{
}

CNtlTreeXml::~CNtlTreeXml(void)
{
    
}

BOOL CNtlTreeXml::CreateXML(WCHAR* szRootNodeName)
{
    Create();

    IXMLDOMProcessingInstruction* pPI    = NULL;        
    

    m_pXMLDocument->createProcessingInstruction(L"xml", L"version=\"1.0\" encoding = \"UTF-8\"", &pPI);
    m_pXMLDocument->appendChild(pPI, NULL);

    m_pXMLDocument->createElement(L"FOLDER", &m_pRootElem);
    m_pXMLDocument->appendChild(m_pRootElem, NULL);
    
    IXMLDOMAttribute* pAttr;
    m_pXMLDocument->createAttribute(L"NAME", &pAttr);
    m_pRootElem->setAttributeNode(pAttr, NULL);
    m_pRootElem->setAttribute(L"NAME", (_variant_t)szRootNodeName);

    return TRUE;
}

bool CNtlTreeXml::Save(WCHAR* szFileName)
{
    if(!m_pXMLDocument || !szFileName)
        return false;

    // ��Ÿ�� ��Ʈ�� �����Ͽ� ���̺� �Ѵ�.
    IXMLDOMDocument* pXSL = NULL;
    CoCreateInstance(__uuidof(DOMDocument30), NULL, CLSCTX_INPROC_SERVER, __uuidof(IXMLDOMDocument), (void**)&pXSL);
    if(!pXSL)
        return false;

    VARIANT_BOOL vBool;
    pXSL->put_async(VARIANT_FALSE);
    pXSL->load((_variant_t)L"indent.xsl", &vBool);

    VARIANT vObject;
    VariantInit(&vObject);
    vObject.vt = VT_DISPATCH;
    vObject.pdispVal = m_pXMLDocument;
    
    m_pXMLDocument->transformNodeToObject(pXSL, vObject);

    HRESULT hr = m_pXMLDocument->save((_variant_t)szFileName);
   
    if(pXSL)
    {
        pXSL->Release();
        pXSL = NULL;
    }
    if(hr == S_OK)
    {
        return true;
    }
    else
    {
        return false;
    }        
}

bool CNtlTreeXml::LoadTreeXML(WCHAR* szFileName, SItemNode* itemNode)
{
    if(!Create())
        return FALSE;

    if(!Load(szFileName))
        return FALSE;

	// ù��° ���� ��带 ã�´�.
    IXMLDOMNodeList* pNodeList = SelectNodeList(L"FOLDER");
	if(pNodeList)
	{
		IXMLDOMNode* pNode = NULL;
		pNodeList->get_item(0, &pNode);
		LoadScipt(pNode, itemNode, TRUE);

		pNode->Release();
		pNodeList->Release();
	}

    return TRUE;
}

void CNtlTreeXml::LoadScipt(IXMLDOMNode* pNode, SItemNode* pParentItem, bool bRoot /* = FALSE */)
{
	if(!pNode || !pParentItem)
		return;

	SItemNode* pItemNode = NULL;
	if(bRoot)
	{
		pItemNode = pParentItem;
	}
	else
	{
		pItemNode = new SItemNode();
	}

	// ��� �ڽ��� ������ �����Ѵ�.
	WCHAR szNodeName[32] = {0,};
	GetTextWithAttributeName(pNode, L"NAME", szNodeName, 32);
	
	pItemNode->strNodeName = szNodeName;
	pItemNode->eNodeType = NODE_FOLDER;

	
	// �ڽ��� �ڽ����� ��ũ��Ʈ�� ������ �߰��Ѵ�.
	IXMLDOMNodeList* pNodeList = NULL;	
	pNode->get_childNodes(&pNodeList);
	if(pNodeList)
	{
		long listLen = 0;
		pNodeList->get_length(&listLen);
		for(long i = 0; i < listLen; ++i)
		{
			IXMLDOMNode* pNodeChild = NULL;
			pNodeList->get_item(i, &pNodeChild);
			if(!pNodeChild)
				continue;

			// ������ ��� �Լ��� ����, ��ũ��Ʈ�� �ڽ����� �߰��Ѵ�.
			BSTR strNodeName;
			pNodeChild->get_nodeName(&strNodeName);
			if(wcscmp(L"FOLDER", strNodeName) == 0)
			{
				LoadScipt(pNodeChild, pItemNode);
			}
			else
			{
                // ������ ����
                BSTR strText;
                pNodeChild->get_text(&strText);
                CString strName;
                strName = strText;
                if(m_mapNode.find(strName) == m_mapNode.end())
                {
				    SItemNode* pItemChild = new SItemNode();
				    pItemChild->strNodeName = strName;
				    pItemChild->eNodeType = NODE_SCIRPT;
				    pItemNode->vecChildList.push_back(pItemChild);
                 
                    m_mapNode[strName] = pItemChild;
                }
			} 

			pNodeChild->Release();
		}

		pNodeList->Release();
	}

	if(!bRoot)
	{
		pParentItem->vecChildList.push_back(pItemNode);
	}	
}

/**
 * ���ο� ���� ��带 �߰��Ѵ�
 * \param szParentFolder ���� �θ� ������ �̸�, NULL�� ��쿡�� ��Ʈ�� ���δ�.
 * \param szFolderName �߰��� ��������� �̸� 
 */
void CNtlTreeXml::AddFolderNode( WCHAR* szParentFolder,  WCHAR* szFolderName)
{
    if(!szFolderName)
        return;

    IXMLDOMElement* pElem = NULL;
    m_pXMLDocument->createElement(L"FOLDER", &pElem);
    if(!pElem)
        return;


    IXMLDOMAttribute* pAttr;
    m_pXMLDocument->createAttribute(L"NAME", &pAttr);
    pElem->setAttributeNode(pAttr, NULL);
    pElem->setAttribute(L"NAME", (_variant_t)szFolderName);

    if(szParentFolder == NULL)
    {
        // ��Ʈ ��忡 ���δ�.        
        m_pRootElem->appendChild(pElem, NULL);        
    }
    else
    {
        // �θ��带 ã�Ƽ� �� �ؿ� ���δ�.
        WCHAR szNodeName[128] = {0,};
        swprintf(szNodeName, L"//FOLDER[@NAME=\"%s\"]", szParentFolder);
        IXMLDOMNode* pNode = NULL;
        m_pXMLDocument->selectSingleNode(szNodeName, &pNode);
        if(pNode)
        {
            pNode->appendChild(pElem, NULL);
        }
    }
    if(pElem)
    {
        pElem->Release();
        pElem = NULL;
    }
}

void CNtlTreeXml::AddScriptNode( WCHAR* szParentFolder,  WCHAR* szScriptName)
{
    if(!szParentFolder || !szScriptName)
        return;

    WCHAR szParentName[128] = {0,};
     swprintf(szParentName, L"//FOLDER[@NAME=\"%s\"]", szParentFolder);
    IXMLDOMNode* pNode = NULL;
    m_pXMLDocument->selectSingleNode(szParentName, &pNode);
    if(pNode)
    {
        IXMLDOMElement* pElem = NULL;
        m_pXMLDocument->createElement(L"SCRIPT", &pElem);        

        IXMLDOMText* pText = NULL;
        m_pXMLDocument->createTextNode(szScriptName, &pText);

        pElem->appendChild(pText, NULL);
        pNode->appendChild(pElem, NULL);

        if(pText)
        {
            pText->Release();
            pText = NULL;
        }

        if(pElem)
        {
            pElem->Release();
            pElem = NULL;
        }
    }
}



