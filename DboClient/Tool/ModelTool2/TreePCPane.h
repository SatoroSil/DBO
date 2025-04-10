#pragma once

#include "ExTreeCtrl.h"

#define TREE_BK_WHITE   RGB(0, 0, 0)
#define TREE_BK_BLUE    RGB(125, 125, 225)

// CTreePCPane view

class CTreePCPane : public CXTTreeView 
{
	DECLARE_DYNCREATE(CTreePCPane)

protected:
	CTreePCPane();           // protected constructor used by dynamic creation
	virtual ~CTreePCPane();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
    static CTreePCPane* GetInstance() {return m_pInstance;};

    virtual void SetModel(CMTCharacter* pCharacter); ///< ����� ���� �����Ѵ�.
    void   OnDataChanged();                          ///< ĳ���� �����Ͱ� ����Ǿ����� ȣ��ȴ�.
    void   OnShowSaveForChanges();                  ///< �����ϱ����� ����Ȱ��� �����Ұ����� �����.

protected:
    virtual void InitClass();                            ///< �� Ŭ������ �´� �ʱ�ȭ

    // Tree ���� ���� ����
    RwBool LoadTreeXML(const CHAR* szXmlFileName);  ///< Ʈ�������� �����ϰ� �ִ� XML ������ �ε��Ѵ�.    
    void   GetAllChildNode(HTREEITEM hItem, TREEITEM_VECTOR& vTreeItem); ///< ��͸� ���鼭 ��� �ڽ� �������� ã�´�.
    RwBool SaveTreeXML(const CHAR* szXmlFileName);  ///< Ʈ�������� XML ���Ͽ� �����Ѵ�.    

    RwBool OnSetClump();                             ///< ���� Clump�� �����Ѵ�.
    RwBool OnSaveScript(HTREEITEM hItem, const CHAR* szScriptName, BOOL bVisible);  ///< ��ũ��Ʈ�� �����Ѵ�.
    void   InsertItemRecursive(SItemNode* pItemNode, HTREEITEM hParentItem);
    void   OnMoveItem(HTREEITEM hItem, HTREEITEM hParentItem, BOOL bRecrusive = FALSE);

protected:
    static CTreePCPane* m_pInstance;
    CMTCharacter*   m_pCharacter;                   ///< ���� ǥ���ϰ� �ִ� ĳ����

    CImageList*     m_pImageList;                   ///< �̹��� ����Ʈ
    CString         m_strRootName;                  ///< Root Item Name
    std::vector<CMTCharacter*> m_vCharacter;        ///< Edit�� ���Ǵ� ĳ���� �ν��Ͻ����� Vector    
    CString         m_sSaveFolderName;              ///< ��ũ��Ʈ�� ������ ������
    CString         m_strTreeFileName;              ///< Ʈ�������� �����ϴ� XML ���ϸ�
    CString         m_strPropertyListFileName;      ///< ������Ƽ ����Ʈ�� ������ ���ϸ�
    CString         m_strPrevScriptName;            ///< ��ũ��Ʈ �̸� ����ÿ� ���    
	SItemNode		m_itemNode;				        ///< ��ũ��Ʈ�� ���� ������ ������ ������ �ִ� ��ü
    RwBool          m_bDrag;                        ///< ������ �巡�� ���� �÷���
    HTREEITEM       m_hCurItem;                     ///< Ŀ���� ��ġ�� ������
    HTREEITEM       m_hDragItem;                    ///< ���� �巡�� �ϰ� �ִ� ������

protected:
	DECLARE_MESSAGE_MAP()
public:
    virtual void OnInitialUpdate();
    afx_msg void OnNMRclick(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnMenuAddFolder();
    afx_msg void OnMenuRenameFolder();
    afx_msg void OnMenuDeleteFolder();
    afx_msg void OnMenuNewScript();
    afx_msg void OnMenuLoadScript();
    afx_msg void OnScriptSetclump();
    afx_msg void OnMenuScriptSave();
    afx_msg void OnMenuScriptSaveas();
    afx_msg void OnMenuScriptRename();
    afx_msg void OnMenuDeleteScript();
    afx_msg void OnTvnEndlabeledit(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnTvnBeginlabeledit(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnDestroy();
    afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnScriptSaveall();
    afx_msg void OnSetFocus(CWnd* pOldWnd);
    afx_msg void OnTvnBegindrag(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};


