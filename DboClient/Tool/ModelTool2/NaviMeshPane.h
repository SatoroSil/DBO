#pragma once
#include "afxwin.h"

/**
 * \ingroup ModelTool2
 * \brief Navigation Mesh & Obstacle Mesh View Pane
 *
 * \date 2008-11-12
 * \author agebreak
 */
class CNaviMeshPane : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CNaviMeshPane)

protected:
	CNaviMeshPane();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CNaviMeshPane();

public:
	enum { IDD = IDD_NAVIMESHPANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
    static CNaviMeshPane* GetInstance() {return m_pInstance;}

    void SetObject(CMTObject* pObject);                     ///< ������Ʈ�� �����Ѵ�.
    void Render();                                          ///< ���õ� �޽ø� �������Ѵ�.

    virtual void OnInitialUpdate();

protected:
    void CreateClump(CString& strFileName);                 ///< �׺���̼� �޽ø� �����Ѵ�.
    void RemoveAllClump();                                  ///< �׺���̼� �޽� ��θ� �����Ѵ�.

protected:
    static CNaviMeshPane*   m_pInstance;
    
    CListBox m_listNavi;
    CListBox m_listObs;
    std::vector<CMTClump*> m_vecClump;                     ///< ������ �׺���̼� �޽ø� ��� �ִ� ����
    CMTObject* m_pObject;
};


