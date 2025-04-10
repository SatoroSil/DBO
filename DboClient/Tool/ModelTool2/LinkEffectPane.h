#pragma once
#include "afxwin.h"
#include "MTCharacter.h"
#include "MTItem.h"
#include "MTObject.h"


// CLinkEffectPane form view

class CLinkEffectPane : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CLinkEffectPane)

protected:
	CLinkEffectPane();           // protected constructor used by dynamic creation
	virtual ~CLinkEffectPane();

public:
	enum { IDD = IDD_LINKEFFECTPANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
    // Item�� ������ ������ ����ü
    struct SLinkEffectItemData
    {
        SEventLinkEffect* pEventLinkEffect;  ///< Link Effect Proeprty
        CNtlInstanceEffect* pEffectInstance; ///< ������ Effect�� ������
    };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
    static CLinkEffectPane* GetInstance() {return m_pInstance;}

    void SetCharacter(CMTCharacter* pCharacter);        ///< ĳ���͸� �����Ѵ�.
    void SetItem(CMTItem* pItem);                       ///< �������� �����Ѵ�    
    void SetObject(CMTObject* pObject);                 ///< Object�� �����Ѵ�.
    CNtlInstanceEffect*  AttachEffect(SEventLinkEffect* pEventLinkEffect);  ///< Effect�� Attach �Ѵ�.    
    RwBool UpdateEffect(SEventLinkEffect* pEventLinkEffect);  ///< �̹� ������ Effect�� ������ �����Ѵ�.

protected:  
    void SetEnable(BOOL bEnable);                       ///< Control���� Enable�� �����Ѵ�.
    void InitEffectList();                              ///< Effect List�� Parser�κ��� �����ͼ� �����Ѵ�.
    SEventLinkEffect* AddLinkEffect(CString streffectName);          ///< Link Effect�� �߰��Ѵ�.    
    void DeleteEffect(SLinkEffectItemData* pLinkEffectItemData); ///< Effect�� �����Ѵ�.
    void ClearListItem();                              ///< ����Ʈ �ڽ� �׸��� ItemData�� �����Ѵ�.

protected:
    static CLinkEffectPane* m_pInstance;

    // Controls
	CComboBox m_cbEffect;
    CListBox m_lbEffect;

    // Member
    CMTCharacter* m_pCharacter;                          ///< ���� Edit �ϰ� �ִ� ĳ���� ��ü
    CMTItem*      m_pItem;                               ///< ���� Edit �ϰ� �ִ� Item ��ü
    CMTObject*    m_pObject;                             ///< ���� Edit �ϰ� �ִ� Object ��ü
    RpClump*      m_pClump;                              ///< ���� Edit �ϰ� �ִ� ��ü�� Clump
    EModelToolMode m_ePrevMode;                          ///< ���� ���� ���

public:
    virtual void OnInitialUpdate();
    afx_msg void OnCbnSelchangeCbEffect();
    afx_msg void OnLbnSelchangeListEffect();    
    virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
    afx_msg void OnDestroy();
};


