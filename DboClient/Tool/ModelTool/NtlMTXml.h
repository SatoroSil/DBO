#pragma once

#include "NtlSharedCommon.h"
#include "NtlXMLDoc.h"

struct SItemNode
{
    WCHAR szParenetName[64];
    WCHAR szNodeName[64];
    int   nImageKind;
};

typedef std::vector<SItemNode> ITEM_VECTOR;

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

    BOOL CreateXML(WCHAR* szRootNodeName);                                           ///< ���ο� XML ��ü�� �����.
    bool Save(WCHAR* szFileName);                                  ///< XML�� ���Ϸ� �����Ѵ�.    
    ITEM_VECTOR LoadTreeXML(WCHAR* szFileName);                     ///< Ʈ�������� XML���Ͽ��� ������ ���͸� ��ȯ�Ѵ�.
    void AddFolderNode( WCHAR* szParentFolder,  WCHAR* szFolderName); ///< ���ο� ������带 �߰��Ѵ�.
    void AddScriptNode( WCHAR* szParentFolder,  WCHAR* szScriptName); ///< ���ο� ��ũ��Ʈ ��带 �߰��Ѵ�


protected:
    IXMLDOMElement*     m_pRootElem;                            ///< Root Element


};
