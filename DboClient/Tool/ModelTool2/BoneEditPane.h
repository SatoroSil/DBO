#pragma once
#include "afxwin.h"



// CBoneEditPane form view

class CBoneEditPane : public CFormView
{
	DECLARE_DYNCREATE(CBoneEditPane)

protected:
	CBoneEditPane();           // protected constructor used by dynamic creation
	virtual ~CBoneEditPane();

public:
	enum { IDD = IDD_BONEEDITPANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
    static CBoneEditPane* GetInstance() {return m_pInstance;};
    
    void   SetModel(CMTCharacter* pCharacter);
    void   SetEnable(BOOL bEnable);

protected:    
    void   OnChangeBoneLength(BOOL bPlus);                      ///< ������ Bone�� Length�� �����Ѵ�.
    void   OnChangeBoneWidth(BOOL bPlus);                       ///< ������ Bone�� Width�� �����Ѵ�.
    void   OnChangeBoneMove(BOOL bPlus);                        ///< ������ Bone�� ��ġ�� �����Ѵ�.
    void   OnChangeSensitive(BOOL bPlus);                       ///< Bone�� ������ Sensitive�� �����Ѵ�.
    void   OnChangeBaseScale(BOOL bPlus);                       ///< Bone�� Base Scale�� �����Ѵ�.

protected:
    static CBoneEditPane* m_pInstance;

    CMTCharacter*               m_pCharacter;
    CNtlPLCharacterProperty*    m_pProperty;
    int                         m_nSelectBoneIndex;              ///< ���� ���õ� Bone Index;

protected:
    CButton m_ckEnableBoneEdit;        
    float m_fBoneLength;
    float m_fBoneWidth;
    float m_fBoneMove;
    float m_fSensitive;
    CEdit m_edBoneLength;
    CEdit m_edBoneWidth;
    CEdit m_edBoneMove;
    CEdit m_edBoneSensitive;
    CSpinButtonCtrl m_spBoneLength;
    CSpinButtonCtrl m_spBoneWidth;
    CSpinButtonCtrl m_spBoneMove;
    CSpinButtonCtrl m_spBoneSensitive;
    CToolTipCtrl    m_ToolTip;
    CButton m_ckEnableBaseScale;
    CXTEdit m_edBoneBaseScale;
    CSpinButtonCtrl m_spBaseBoneScale;
    CComboBox m_cbBoneName;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
    virtual void OnInitialUpdate();
    afx_msg void OnBnClickedCkBoneEdit();    
    void ChangeTgScale();
    void ChangeTgMove();
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnEnChangeEdBoneLength();
    afx_msg void OnEnChangeEdBoneWidth();
    afx_msg void OnEnChangeBoneMove();
    afx_msg void OnEnChangeEtSense();
    afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnDeltaposSpin4(NMHDR *pNMHDR, LRESULT *pResult);
    virtual BOOL PreTranslateMessage(MSG* pMsg);    
    afx_msg void OnBnClickedCkBoneEdit2();
    afx_msg void OnDeltaposSpin5(NMHDR *pNMHDR, LRESULT *pResult);
public:
    afx_msg void OnEnChangeEdBoneLength2();
public:
    
public:
    afx_msg void OnCbnSelchangeCbBone();
};


