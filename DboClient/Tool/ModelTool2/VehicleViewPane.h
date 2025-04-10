#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "ExTreeCtrl.h"


// CVehicleViewPane �� ���Դϴ�.

class CVehicleViewPane : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CVehicleViewPane)

protected:
	CVehicleViewPane();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CVehicleViewPane();

public:
	enum { IDD = IDD_VEHICLEVIEWPANE };
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
    static CVehicleViewPane* GetInstance() {return m_pInstance;};

    virtual void OnInitialUpdate();
    afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
    afx_msg void OnTvnSelchangedTreeVehicle(NMHDR *pNMHDR, LRESULT *pResult);
    
    void    SetVehicle(CMTCharacter* pVehicle);
    void    SetVehicleAnimation(RwUInt32 uiAnimID);

protected:
    void    UpdateTree();                               ///< Ʈ���� ������ ������Ʈ�Ѵ�.
    void    AttachVehicle(HTREEITEM hItem);             ///< ��Ŭ�� ĳ���͸� ž�½�Ų��.

public:
    CImageList*   m_pImageList;                        ///< Ʈ���� ����� �̹��� ����Ʈ
    CExTreeCtrl   m_treeVehicle;    
    
protected:
    static CVehicleViewPane* m_pInstance;

    CMTCharacter*   m_pCharacter;                       ///< ���� Attach�Ǿ� �ִ� ĳ����
    CMTCharacter*   m_pVehicle;                         ///< ���� Attach�ϴ� Vehicle
    
};


