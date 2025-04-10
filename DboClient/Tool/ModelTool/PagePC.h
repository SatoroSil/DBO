#pragma once
#include "afxcmn.h"
#include "MTTreeCtrl.h"
#include "afxwin.h"
#include "NtlPLCharacterProperty.h"

// CPagePC dialog



class CPagePC : public CPropertyPage
{
	DECLARE_DYNAMIC(CPagePC)

public:
	CPagePC();
    CPagePC(int nEnum);
	virtual ~CPagePC();

// Dialog Data
	enum { IDD = IDD_PAGEPC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
    
public:
    static CPagePC*    GetInstance() {return m_pInstance;};
    void OnSaveScript(const WCHAR* szScriptName, BOOL bVisible);                   ///< ��ũ��Ʈ ������ �����Ѵ�.

protected:
    BOOL OnDisplayScriptInfo(CString strFileName);      ///< ��ũ��Ʈ ������ �о ������ ǥ���Ѵ�.        
    

protected:
    static CPagePC* m_pInstance;
    CNtlPLCharacterProperty* m_pCharacterProperty;        ///< ���� ������Ƽ ������
    std::vector<CMTCharacter*> m_vCharacter;              ///< Edit�� ���Ǵ� ĳ���� �ν��Ͻ����� Vector    
    CString m_sSaveFolderName;                             ///< ��ũ��Ʈ�� ������ ������

protected:            
    CEdit m_edScriptFileName;                            ///< ��ũ��Ʈ ���ϸ��� ǥ���Ѵ�.
    CEdit m_edClumpFileName;
    CButton m_btLoadClump;
    CButton m_btSaveScript;
    CButton m_btSaveAll;
    CMTTreeCtrl m_treePC;
    CImageList* m_pImageList;
    

public:
    virtual BOOL OnInitDialog();
    afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
    afx_msg void OnTvnSelchangedTreePc(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedBtSetClump();
    virtual BOOL OnKillActive();
    afx_msg void OnBnClickedButton1();
    afx_msg void OnMenuLoadScript();
    afx_msg virtual void OnDestroy();
    virtual BOOL OnSetActive();
    virtual void OnMenuNewScript();
    afx_msg void OnBnClickedBtSaveAll();
    afx_msg void OnMenuScriptSave();
    afx_msg void OnMenuScriptSaveas();
    void OnMenuScriptRename(CString sOrgScriptName, CString sNewScriptName);
    void OnMenuDeleteScript(HTREEITEM hItem);
    afx_msg void OnSize(UINT nType, int cx, int cy);
};
