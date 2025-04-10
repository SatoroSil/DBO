#pragma once
#include "afxwin.h"
#include "MTCharacterInfo.h"

#define CLUMP_CKBTN_CNT     8

// CClumpPane form view
class CClumpPane : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CClumpPane)

protected:
	CClumpPane();           // protected constructor used by dynamic creation
	virtual ~CClumpPane();

public:
	enum { IDD = IDD_CLUMPPANE };
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
    static  CClumpPane* GetInstance() {return m_pInstance;};

    void    SetClump(CMTClump* pClump);                  ///< Clump�� �����Ѵ�.
    CMTClump* GetEditClump() {return m_pMTClump;}       ///< ���� Edit���� Clump ��ü�� ��ȯ�Ѵ�.
    void    SetEnable(BOOL bEnable);                    ///< Ȱ��ȭ ������ �����Ѵ�.
    void    Render();                                   ///< Clump ���� ������ Render�Ѵ�.    
    void    DisplayInfo(RtCharset* pCharSet);           ///< Clump ���� ������ ȭ�鿡 ǥ���Ѵ�. (2D UI)


protected:
    RwBool  OnLoadClump(RwChar* szClumpFileName);       ///< Clump ������ �ε��Ѵ�.
    void    OnSetCheckButtons(CHAR* szAtomicName);     ///< üũ ��ư ���¸� �����Ѵ�.
    void    DisplayAtomics();                           ///< Atomic ������ ����Ʈ�ڽ��� �߰��Ѵ�
    void    RenderAtomicBB();                           ///< ������ Atomic�� BB�� �׸���.
    void    SetEnableAllButtons(BOOL bEnable);          ///< ��� ��ư���� Enable/Disable�� �����Ѵ�.
	void	SetChangeAtomicFlag(ENtlAtomicFlag eFlag, RwBool bEnable);	///< ����Ʈ�ڽ��� ������ aotmic���� flag�� �����Ѵ�
	void	SetShadowMapSize(CHAR* szAtomicName);		///< �޺��ڽ��� Atomic�� ShadowMap Size�� �����Ѵ�.
    
    void    SetEnvMap();                                ///< ȯ��� ������ Ȯ���Ѵ�.    
    void    SaveEnvMap();                               ///< ȯ�ݸ� ������ �����Ѵ�.

protected:    
    static CClumpPane*  m_pInstance;
    CMTClump*           m_pMTClump;                     ///< ���� ������ MTClump    
    std::vector<CMTClump*> m_vMTClump;                  ///< ������ MTClump ��ü���� �����ϴ� ����(����ɶ� �Ѳ����� �����ȴ�)

    bool                m_bFlagSetModel;                ///< �ٸ� Ŭ������ �𵨿� ���õɶ� ����Ѵ�.
    bool                m_bToon;                        ///< Clump�� Toon�� ����Ǿ� �ִ����� ����
    bool                m_bFlagCkBtn[CLUMP_CKBTN_CNT];  ///< üũ��ư���� ���� ������ ���� �÷���    

protected:
    CXTBrowseEdit m_editClumpName;
    CListBox m_listAtomic;
    CButton m_btDelete;
    CButton m_btSave;
    CButton m_btSaveSplit;
    CButton m_ck2Side;
    CButton m_ck2SideEdge;
    CButton m_ckAlphaTest;
    CButton m_ckAlpha;
    CButton m_ckRender2Side;
    CButton m_ckCollision;    
    CButton m_btSaveClump;
    CButton m_ckNotVisible;
	CButton m_ckDecalVisible;    
	CButton m_ckShadowMap;	
	CComboBox m_cbShadowMapResolution;
	CEdit m_EdFrustum;	
    CStatic m_sttFrustum;
    CButton m_ckCameraCollision;    
    CXTBrowseEdit m_edEnvMap;
    CComboBox m_cbEnv;
    CButton m_ckEmblemMark;

public:
    virtual void OnInitialUpdate();
    afx_msg void OnEnChangeEditClumpName();
    afx_msg void OnLbnSelchangeListAtomic();
    afx_msg void OnBnClickedBtDelete();
    afx_msg void OnBnClickedBtClumpSave();
    afx_msg void OnBnClickedBtClumpSaveAll();
    afx_msg void OnBnClickedCk2side();
    afx_msg void OnBnClickedCk2sideEdge();
    afx_msg void OnBnClickedCheckAlpha();
    afx_msg void OnBnClickedCheckAlpha2();
    afx_msg void OnBnClickedCheckAlpha3();
    afx_msg void OnBnClickedCheckCollision();
    afx_msg void OnBnClickedBtSaveclump();
    afx_msg void OnBnClickedCheckNotVisible();
	afx_msg void OnBnClickedCheckDecalVisible();
	afx_msg void OnBnClickedCheckShadowmap();
    afx_msg void OnBnClickedCheckEmblemMark();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnEnChangeEdFrustum();    
    afx_msg void OnBnClickedCheckCameraCollision();    
    afx_msg void OnEnChangeEditEnvmap();    
    afx_msg void OnCbnSelchangeCbEnv();
};


