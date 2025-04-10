#pragma once
#include "afxwin.h"
#include "togglebutton2.h"
#include "afxcmn.h"


// CBottomToolView form view

class CBottomToolView : public CFormView
{
	DECLARE_DYNCREATE(CBottomToolView)

public:
    /// ���� Bone�� �۾� ���
    enum EBoneEditMode
    {
        BONE_EDIT_NONE,         ///< �ƹ� �۾��� ���ϴ� ���
        BONE_EDIT_SCALE,        ///< Scale �۾� ���
        BONE_EDIT_MOVE,         ///< Move �۾� ���
    };

protected:
	CBottomToolView();           // protected constructor used by dynamic creation
	virtual ~CBottomToolView();

public:
	enum { IDD = IDD_BOTTOMTOOLVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:        
    static CBottomToolView* GetInstance() {return m_Instance;}; ///< �̱��� ��ȯ 
    void   SetInit(CMTCharacter* pCharacter);                   ///< ����Ʈ�� ����� ĳ���Ͱ�ü�� �����ϰ� ���� UI�� �ʱ�ȭ�Ѵ�.
    void   SetBoneEditEnable(BOOL bEnable);                     ///< Bone Edit�� Ȱ��ȭ ������ �����Ѵ�.

protected:
    void   OnSelectBone(int nBoneIndex);                        ///< ������ Bone�� ������ ǥ���Ѵ�.
    void   OnChangeBoneLength(BOOL bPlus);                      ///< ������ Bone�� Length�� �����Ѵ�.
    void   OnChangeBoneWidth(BOOL bPlus);                       ///< ������ Bone�� Width�� �����Ѵ�.
    void   OnChangeBoneMove(BOOL bPlus);                        ///< ������ Bone�� ��ġ�� �����Ѵ�.
    void   OnChangeSensitive(BOOL bPlus);                       ///< Bone�� ������ Sensitive�� �����Ѵ�.
    void   OnChangeBaseScale(BOOL bPlus);                       ///< Bone�� Base Scale�� �����Ѵ�.

protected:
    static CBottomToolView* m_Instance;                         ///< �̱��� �ν��Ͻ�
    int    m_nSelectBoneIndex;                                  ///< ���� ���õ� Bone Index;
    CMTCharacter*            m_pCharacter;                      ///< ����Ʈ�� ����� ĳ������ ������
    CNtlPLCharacterProperty* m_pProperty;                       ///< ����Ʈ�� ����� ���� ������Ƽ ������    
    EBoneEditMode            m_eBoneEditMode;                   ///< ���� Bone�� �۾� ���
    

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()

protected:
    CButton m_ckEnableBoneEdit;    
    CString m_sBoneName;
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
    CEdit m_edBoneBaseScale;
    CSpinButtonCtrl m_spBaseBoneScale;

    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
    
public:
    afx_msg void OnBnClickedCkBoneEdit();
    afx_msg void OnBnClickedBtBonePrev();
    afx_msg void OnBnClickedBtBoneNext();
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
    virtual void OnInitialUpdate();
    afx_msg void OnBnClickedCkBoneEdit2();
    afx_msg void OnDeltaposSpin5(NMHDR *pNMHDR, LRESULT *pResult);
};


