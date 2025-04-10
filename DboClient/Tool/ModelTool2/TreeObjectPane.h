#pragma once
#include "afxcmn.h"
#include "ExTreeCtrl.h"


#define SAVE_FILE_NAME                   "TreeObject.XML"
#define OBJECT_PROPERTY_LIST_FILE_NAME   "ObjectPropertyList.XML"

// CTreeObjectPane form view


typedef std::vector<CMTObject*> VMTObject;

class CTreeObjectPane : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CTreeObjectPane)

protected:
	CTreeObjectPane();           // protected constructor used by dynamic creation
	virtual ~CTreeObjectPane();

public:
	enum { IDD = IDD_TREEOBJECTPANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
    static CTreeObjectPane* GetInstance() {return m_pInstance;}

    void   SetObject(CMTObject* pObject);
    void   OnDataChanged();                               ///< �����Ͱ� ����Ǿ����� �˸���.
    void   OnShowSaveForChanges();                      ///< �����ϱ����� ����Ȱ��� �����Ұ����� �����.

protected:
    void UpdateResFolder(CTreeCtrl* pTreeCtrl, LPCTSTR pstr, HTREEITEM hItemParent, BOOL bFile);                 ///< ���ҽ� ���� ������ Ʈ���� �����Ѵ�.
    RwBool OnSaveScript(HTREEITEM hItem);               ///< �������� ��ũ��Ʈ�� �����Ѵ�.    
    void   OnSavePropertyList();                        ///< Property List ������ �����Ѵ�
    
protected:
    static CTreeObjectPane* m_pInstance;

    CString     m_strObjectPath;                        ///< ������Ʈ ���ҽ� ������ ��Ʈ �н�
    CString     m_strScriptPath;                        ///< ��ũ��Ʈ�� ����� ����
    CString     m_strTreeXMLPath;                       ///< TreeXml�� ����� ����
    CImageList* m_pImageList;                           ///< Ʈ���� ����� �̹��� ����Ʈ

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
    CExTreeCtrl   m_treeScript;
    CExTreeCtrl   m_treeRes;
    HTREEITEM     m_itemResRoot;
    HTREEITEM     m_itemScriptRoot;
    VWChar        m_vFilePath;
    VMTObject     m_vMTObject;
    CMTObject*    m_pObject;                               ///< ���� �۾��ϰ� �ִ� Object ��ü
    CString       m_strPrevFileName;                       ///< ���ϸ� ����ÿ� ����ϴ� ����    

public:
    virtual void OnInitialUpdate();
    afx_msg void OnNMRclickTreeResource(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnObjectresourceExporttoscript();
    afx_msg void OnTvnSelchangedTreeResource(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnTvnSelchangedTreeScript(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnSetFocus(CWnd* pOldWnd);
    afx_msg void OnNMRclickTreeScript(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnObjectfolderNewfolder();
    afx_msg void OnTvnEndlabeleditTreeScript(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnObjectfolderRename();
    afx_msg void OnObjectfolderDelete();
    afx_msg void OnObjectfolderImportscript();
    afx_msg void OnObjectscriptRename();
    afx_msg void OnObjectscriptDelete();
    afx_msg void OnDestroy();
    
    afx_msg void OnObjectscriptSave();
    afx_msg void OnObjectscriptSaveas();
    afx_msg void OnObjectscriptSaveall();
    afx_msg void OnObjectfolderSavetree();
public:
    afx_msg void OnTvnDeleteitemTreeScript(NMHDR *pNMHDR, LRESULT *pResult);
};


