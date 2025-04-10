#pragma once

#include "MTItem.h"
#include "afxcmn.h"
#include "ExTreeCtrl.h"

#define TREE_ITEM_FILE_NAME            "TreeItem.XML"
#define ITEM_PROPERTY_LIST_FILE_NAME   "ItemPropertyList.XML"

typedef std::vector<CMTItem*> VMTItem;

// CTreeItemPane form view

class CTreeItemPane : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CTreeItemPane)

protected:
	CTreeItemPane();           // protected constructor used by dynamic creation
	virtual ~CTreeItemPane();

public:
	enum { IDD = IDD_TREEITEMPANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()

public:
    static CTreeItemPane* GetInstance() {return m_pInstance;}

    void SetItem(CMTItem* pItem);
    void   OnDataChanged();                               ///< �����Ͱ� ����Ǿ����� �˸���.
    void   OnShowSaveForChanges();                      ///< �����ϱ����� ����Ȱ��� �����Ұ����� �����.
    

protected:
    void UpdateResFolder(CTreeCtrl* pTreeCtrl, LPCTSTR pstr, HTREEITEM hItemParent, BOOL bFile);                 ///< ���ҽ� ���� ������ Ʈ���� �����Ѵ�.
    RwBool OnSaveScript(HTREEITEM hItem);               ///< �������� ��ũ��Ʈ�� �����Ѵ�.    
    void   OnSavePropertyList();                            ///< Property ����Ʈ ������ �����Ѵ�.

public:
    CExTreeCtrl   m_treeScript;
    CExTreeCtrl   m_treeRes;

protected:
    static CTreeItemPane* m_pInstance;

    CString       m_strResPath;                             ///< ���ҽ� ������ Root ���
    CString       m_strScriptPath;                          ///< ��ũ��Ʈ ���ϵ��� ����� ���
    CString       m_strTreeXMLPath;                         ///< Tree ������ ����� ���
    VWChar        m_vFilePath;
    CString       m_strPrevFileName;                       ///< ���ϸ� ����ÿ� ����ϴ� ����

    CImageList*   m_pImageList;                             ///< Ʈ���� ����� �̹��� ����Ʈ
    HTREEITEM     m_itemResRoot;                            ///< ���ҽ� Ʈ�� Root Item
    HTREEITEM     m_itemScriptRoot;                         ///< Script Ʈ�� Root Item
    
    //VMTItem       m_vMTItem;                                ///< MTItem ��ü ����Ʈ (���ҽ� �信�� ������ �����͸� ��´�)
    CMTItem*      m_pItem;                                  ///< ���� ���ǰ� �ִ� MTItem ��ü

public:
    virtual void OnInitialUpdate();
    afx_msg void OnSetFocus(CWnd* pOldWnd);
    afx_msg void OnTvnSelchangedTreeResource(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnNMRclickTreeResource(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnItemresourceExporttoscript();
    afx_msg void OnTvnSelchangedTreeScript(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnDestroy();
    afx_msg void OnNMRclickTreeScript(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnItemfolderNewfolder();
    afx_msg void OnItemfolderDelete();
    afx_msg void OnItemfolderImportscript();
    afx_msg void OnItemfolderRename();
    afx_msg void OnItemfolderSavetree();
    afx_msg void OnItemscriptDelete();
    afx_msg void OnItemscriptRename();
    afx_msg void OnItemscriptSave();
    afx_msg void OnItemscriptSaveas();
    afx_msg void OnItemscriptSaveall();
    afx_msg void OnItemscriptOverwriteall();
    afx_msg void OnTvnEndlabeleditTreeScript(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnTvnBegindragTreeScript(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnTvnBeginlabeleditTreeScript(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnTvnDeleteitemTreeScript(NMHDR *pNMHDR, LRESULT *pResult);
    
};


