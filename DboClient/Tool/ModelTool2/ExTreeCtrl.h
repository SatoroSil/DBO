#pragma once

#include "MTDef.h"
#include "NtlMTXml.h"

/**
 * \ingroup ModelTool2
 * \brief Drag&Drop ����� �߰��� Ʈ�� ��Ʈ��
 * \date 2006-06-08
 * \author agebreak
 */
class CExTreeCtrl : public CXTTreeCtrl
{
public:
    CExTreeCtrl(void);
public:
    virtual ~CExTreeCtrl(void); 

public:
    void    OnMoveItem(HTREEITEM hItem, HTREEITEM hParentItem, BOOL bRecrusive = FALSE);
    void    GetAllChildNode(HTREEITEM hItem, TREEITEM_VECTOR& vTreeItem);   ///< ��� �������� �˻��Ͽ� ���Ϳ� ��´�.
    void    ResetBoldColor();

    void    SaveTree(const char* szFileName);     ///< Ʈ�������� XML���Ϸ� �����Ѵ�.
    void    LoadTree(const char* szFileName);     ///< Ʈ�������� XML���Ͽ��� �ҷ��´�.    

    ///----- ���� ���̵� (������ ���� ȭ���� ���ؼ� �����Ѵ�)
    virtual void SetItemBold(HTREEITEM hItem, BOOL bBold = TRUE);
    virtual void SetItemColor(HTREEITEM hItem, COLORREF color);

protected:
	void	InsertItemRecursive(SItemNode* pItemNode, HTREEITEM hParentItem);

protected:
    BOOL            m_bDrag;                ///< �巡�� �÷���    
    HTREEITEM       m_hCurItem;             ///< Ŀ���� ��ġ�� ������
    TREEITEM_VECTOR     m_vBoldColorItem;       ///< Bold�� Color�� ����� Item���� ����Ʈ
	SItemNode		m_itemNode;				///< ��ũ��Ʈ�� ���� ������ ������ ������ �ִ� ��ü

public:
    DECLARE_MESSAGE_MAP()
    afx_msg void OnTvnBegindrag(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};
