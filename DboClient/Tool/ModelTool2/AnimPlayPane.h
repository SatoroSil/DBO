#pragma once



#include "ExSliderCtrl.h"
#include "afxcmn.h"
#include "afxwin.h"

// CAnimPlayPane form view
enum EAnimPlayPaneState
{
	ANIMPLAYPANE_CHARACTER,
	ANIMPLAYPANE_OBJECT,
};

class CAnimPlayPane : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CAnimPlayPane)

protected:
	CAnimPlayPane();           // protected constructor used by dynamic creation
	virtual ~CAnimPlayPane();

public:
	enum { IDD = IDD_ANIMPLAYPANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
    static CAnimPlayPane* GetInstance() {return m_pIntance;};

    void    SetAnimData(CMTCharacter* pCharacter, STypeAnimData* pAnimData);	
	void	SetTriggerObjectAnimData(CMTObject* pObject, STypeAnimData* pAnimData);
    void    SetAnimTime(RwReal fCurrentTime, RwReal fTotalTime);       ///< �ִϸ��̼��� �ð��� �����Ѵ�.
    void    Update();                                                  ///< �÷��� Ÿ���� ������Ʈ �Ѵ�.
    void    SetMarkerPos(SEventAnim* pEventAnim);                      ///< ��Ŀ�� ��ġ�� �����Ѵ�.    
    void    ChangeAnimPlay();                                          ///< ���� �ִϸ��̼� �÷��̻��¸� ����Ѵ�.

protected:
    void    SetEnable(BOOL bEnable);                                   ///< Ȱ��ȭ ������ �����Ѵ�.
    void    InitMarker();                                              ///< �����̵� ���� ��Ŀǥ�ø� �����Ѵ�.
    RwReal  PosToTime(int nPos);					                   ///< ��ġ���� �ð������� �����Ѵ�.
    int     TimeToPos(RwReal fTime);                                   ///< Time���� Pos��ġ�� ��ȯ�Ѵ�.    
	void	UpdateEventComboBox();									   ///< Event Comobo Box Setup
    RwBool  CheckSkillCancel(RwReal fTime);                            ///< Skill Cancel �̺�Ʈ�� �߰��Ҽ� �ִ��� Ȯ���Ѵ�.

protected:
    static CAnimPlayPane* m_pIntance;

    CMTCharacter*       m_pCharacter;                                   ///< �ִϸ��̼� �ð� ������Ʈ�ÿ� ����� ĳ���� ��ü
	CMTObject*			m_pObject;										///< ������Ʈ �ִϸ��̼ǽ� ����� ������Ʈ ��ü
    STypeAnimData*      m_pAnimData;                                    ///< Anim Data ������
    SEventAnim*         m_pEventHit;                                    ///< ���� Hit ǥ�ø� �ϰ� �ִ� �̺�Ʈ ��ü
    SEventAnim*         m_pEventSound;                                  ///< ���� Sound�� �÷����ϰ� �ִ� �̺�Ʈ ��ü
    SEventAnim*         m_pEventClipBoard;                               ///< copy&paste�� event

	EAnimPlayPaneState	m_eAnimPlayPaneState;							///< ���� ����

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    virtual void OnInitialUpdate();
public:
    CExSliderCtrl m_slideAnimTime;
    CButton m_btAnimPlay;
    CButton m_btAnimStop;
    CEdit m_edAnimSpeed;
    CSpinButtonCtrl m_spinAnimSpeed;
    CEdit m_edAnimTime;
    CComboBox m_cbEvent;

public:
    afx_msg void OnBnClickedBtAnimPlay();
    afx_msg void OnBnClickedBtAnimStop();
    afx_msg void OnSlidePosChanged();    
    afx_msg void OnSlideMarkerAdd(SSliderMarker* pSliderMarker);
    afx_msg void OnSlideMarkerSelect();
    afx_msg void OnSlideMarkerMove();
    afx_msg void OnSlideMarkerChanged();
    afx_msg void OnSlideMarkerRemove(SSliderMarker* pRemovedMarker);
    afx_msg void OnSlideMarkerCopy();
    afx_msg void OnSlideMarkerPaste();

protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
    afx_msg void OnDeltaposSpinAnimSpeed(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnEnChangeEdSpeed();

public:
    afx_msg void OnCbnSelchangeCbEvent();
};


