#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "ExSliderCtrl.h"


// CAnimToolView form view

class CAnimToolView : public CFormView
{
	DECLARE_DYNCREATE(CAnimToolView)

protected:
	CAnimToolView();           // protected constructor used by dynamic creation
	virtual ~CAnimToolView();

public:
	enum { IDD = IDD_ANIMTOOLVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
    static CAnimToolView* GetInstance();                                ///< �̱��� ��ȯ�Լ�

    void    SetInit(CMTCharacter* pCharacter,STypeAnimData* pAnimData);
    void    SetAnimTime(RwReal fCurrentTime, RwReal fTotalTime);       ///< �ִϸ��̼��� �ð��� �����Ѵ�.
    void    SetEnable(BOOL bEnable);                                   ///< Ȱ��ȭ ������ �����Ѵ�.
    void    Update();                                                  ///< �÷��� Ÿ���� ������Ʈ �Ѵ�.
    void    SetMarkerPos(SEventAnim* pEventAnim);                      ///< ��Ŀ�� ��ġ�� �����Ѵ�.
    void    ChangeAnimPlay();                                          ///< �ִϸ��̼� �÷��� ���¸� �����Ѵ�.
   
protected:
    void    InitMarker();                                              ///< �����̵� ���� ��Ŀǥ�ø� �����Ѵ�.
    RwReal  PosToTime(int nPos);                                       ///< ��ġ���� �ð������� �����Ѵ�.
    int     TimeToPos(RwReal fTime);                                   ///< Time���� Pos��ġ�� ��ȯ�Ѵ�.

protected:
    static CAnimToolView* m_pInstance;
    
    CMTCharacter*       m_pCharacter;                                   ///< �ִϸ��̼� �ð� ������Ʈ�ÿ� ����� ĳ���� ��ü
    STypeAnimData*      m_pAnimData;                                    ///< Anim Data ������
    BOOL                m_bUpdate;                                      ///< Update ����

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
protected:
    CString m_sAnimTime;
    CExSliderCtrl m_slideAnimTime;
    CButton m_btAnimPlay;
    CButton m_btAnimStop;
    CEdit m_edAnimSpeed;
public:
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton1();    
    afx_msg void OnSlidePosChanged();    
    afx_msg void OnSlideMarkerSelect();
    afx_msg void OnSlideMarkerMove();
    afx_msg void OnSlideMarkerChanged();
    afx_msg void OnSlideMarkerRemove(SSliderMarker* pRemovedMarker);

protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);

public:
    afx_msg void OnDeltaposSpinAnimSpeed(NMHDR *pNMHDR, LRESULT *pResult);
protected:
    CSpinButtonCtrl m_spinAnimSpeed;
public:
    afx_msg void OnEnChangeEdit2();
};


