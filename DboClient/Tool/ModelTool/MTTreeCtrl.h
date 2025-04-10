#pragma once

class CPagePC;

typedef std::vector<HTREEITEM> TREEITEM_VECTOR;

/**
 * \ingroup ModelTool
 * \brief CTreeCtrl�� ��ӹ޾� ModelTool���� ����ϴ� TreeCtrl
 * \date 2006-04-17
 * \author agebreak
 */
class CMTTreeCtrl : public CTreeCtrl
{
	DECLARE_DYNAMIC(CMTTreeCtrl)

public:
    enum eITEM_KIND
    {
        ITEM_FOLDER = 10,
        ITEM_SCRIPT,
        ITEM_CLUMP,
        ITEM_FILE
    };

public:
	CMTTreeCtrl();
	virtual ~CMTTreeCtrl();

    void    SetRoot(WCHAR* szRootName);  
    void    SetParent(CPagePC* pLeftView);          ///< Ʈ����Ʈ���� ������ �ִ� ��ü�� �����Ѵ�. (���ʺ��� ��� ��ü�� CPagePC�κ��� ��ӹ���)
    CString SelectScriptName();
    void    SetScriptName(CString sScriptName);
    CString SelectClumpName();
    void    AddItem(const RwChar* sScriptName);     ///< ��ũ��Ʈ �׸��� �߰��Ѵ�.

    void    SaveTree(WCHAR* szRootName, WCHAR* szFileName);     ///< Ʈ�������� XML���Ϸ� �����Ѵ�.
    void    LoadTree(WCHAR* szFileName);     ///< Ʈ�������� XML���Ͽ��� �ҷ��´�.

    void    GetAllChildNode(HTREEITEM hItem, TREEITEM_VECTOR& vTreeItem);   ///< ��� �������� �˻��Ͽ� ���Ϳ� ��´�.

protected:
    void    EndDrag(CPoint point);                  ///< �巡�װ� ������ ȣ��ȴ�
    HTREEITEM GetItemByName(WCHAR* szItemName);     ///< �������� �̸����� �����͸� ã�´�.

protected:
    CImageList*     m_pImageList;                   ///< Ʈ����Ʈ�ѿ� ���Ǵ� �̹��� ����Ʈ 
    HTREEITEM       m_hSelectedItem;                ///< ���� ���õ� ������
    HTREEITEM       m_hCurItem;                     ///< �巡�׿� ���Ǵ� ������
    HTREEITEM       m_hDragItem;                    ///< �巡�׿� ���Ǵ� ������
    BOOL            m_bDrag;                        ///< �巡�׿� ���� �÷���
    CPagePC*        m_pParentView;                  ///< Ʈ���� ������ �ִ� �θ� ��
    CString         m_sPrevScriptName;              ///< ���� ��ũ��Ʈ��. �����̸� ����� �ʿ��ϴ�


protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
public:
    afx_msg void OnMenuAddFolder();
public:
    afx_msg void OnMenuAddScript();
public:
    afx_msg void OnTvnItemexpanding(NMHDR *pNMHDR, LRESULT *pResult);

public:
    afx_msg void OnMenuNewScript();
public:
    afx_msg void OnMenuLoadScript();
public:
    afx_msg void OnMenuDeleteFolder();
public:
    afx_msg void OnMenuDeleteScript();
public:
    afx_msg void OnTvnBegindrag(NMHDR *pNMHDR, LRESULT *pResult);
public:
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
public:
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
public:
    afx_msg void OnMenuRenameFolder();
public:
    afx_msg void OnTvnEndlabeledit(NMHDR *pNMHDR, LRESULT *pResult);
public:
    afx_msg void OnMenuScriptSave();
public:
    afx_msg void OnUpdateMenuScriptSave(CCmdUI *pCmdUI);
public:
    afx_msg void OnMenuScriptSaveas();
public:
    afx_msg void OnMenuScriptRename();
public:
    afx_msg void OnTvnBeginlabeledit(NMHDR *pNMHDR, LRESULT *pResult);
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
    afx_msg void OnSize(UINT nType, int cx, int cy);
};


