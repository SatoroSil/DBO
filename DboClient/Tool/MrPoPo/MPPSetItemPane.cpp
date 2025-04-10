// MPPSetItemPane.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MrPoPo.h"
#include "MPPSetItemPane.h"
#include "MPPDef.h"
#include "MPPClientEvent.h"

// CMPPSetItemPane

IMPLEMENT_DYNCREATE(CMPPSetItemPane, CXTResizeFormView)

CMPPSetItemPane::CMPPSetItemPane()
: CXTResizeFormView(CMPPSetItemPane::IDD)    
, m_nTeleIndex(0)
{

}

CMPPSetItemPane::~CMPPSetItemPane()
{
}

void CMPPSetItemPane::DoDataExchange(CDataExchange* pDX)
{
    CXTResizeFormView::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT_CREATEITEM, m_edCreateItem);    
    DDX_Control(pDX, IDC_EDIT_SETZENNY, m_edSetZenny);
    DDX_Control(pDX, IDC_EDIT_ADDEXP, m_edAddExp);
    DDX_Control(pDX, IDC_EDIT_SETLEVEL, m_edSetLevel);
    DDX_Control(pDX, IDC_EDIT_SETSPEED, m_edSetSpeed);
    DDX_Control(pDX, IDC_EDIT_OFFENCE, m_edSetOffence);
    DDX_Control(pDX, IDC_EDIT_DEFENCE, m_edSetDefence);
    DDX_Control(pDX, IDC_CB_TELE_SELECT, m_cbTeleSelect);
    DDX_Control(pDX, IDC_ED_TELE_X, m_edTeleX);
    DDX_Control(pDX, IDC_ED_TELE_Z, m_edTeleZ);
    DDX_Control(pDX, IDC_ED_TELE_VISIT, m_edTeleVisit);    
}

BEGIN_MESSAGE_MAP(CMPPSetItemPane, CXTResizeFormView)
    ON_BN_CLICKED(IDC_BTN_CREATEITEM, &CMPPSetItemPane::OnBnClickedBtnCreateitem)
    ON_BN_CLICKED(IDC_BTN_UPGRADEITEM, &CMPPSetItemPane::OnBnClickedBtnUpgradeitem)
    ON_BN_CLICKED(IDC_BTN_SETZENNY, &CMPPSetItemPane::OnBnClickedBtnSetzenny)
    ON_BN_CLICKED(IDC_BTN_ADDEXP, &CMPPSetItemPane::OnBnClickedBtnAddexp)
    ON_BN_CLICKED(IDC_BTN_SETLEVEL, &CMPPSetItemPane::OnBnClickedBtnSetlevel)
    ON_BN_CLICKED(IDC_BTN_COLLECTDRAGONBALL, &CMPPSetItemPane::OnBnClickedBtnCollectdragonball)
    ON_BN_CLICKED(IDC_BTN_SETSPEED, &CMPPSetItemPane::OnBnClickedBtnSetspeed)
    ON_BN_CLICKED(IDC_BTN_OFFENCE, &CMPPSetItemPane::OnBnClickedBtnOffence)
    ON_BN_CLICKED(IDC_BTN_DEFENCE, &CMPPSetItemPane::OnBnClickedBtnDefence)
    ON_BN_CLICKED(IDC_BUTTON1, &CMPPSetItemPane::OnBnClickedButton1)    
    ON_BN_CLICKED(IDC_RD_SELECT, &CMPPSetItemPane::OnBnClickedRdSelect)
    ON_BN_CLICKED(IDC_RD_DIRECT, &CMPPSetItemPane::OnBnClickedRdDirect)
    ON_BN_CLICKED(IDC_RD_VISIT, &CMPPSetItemPane::OnBnClickedRdVisit)
    ON_BN_CLICKED(IDC_BTN_LEARN_ALL_SKILL, &CMPPSetItemPane::OnBnClickedBtnLearnAllSkill)
    ON_BN_CLICKED(IDC_BTN_UPGRADE_ALL_SKILL, &CMPPSetItemPane::OnBnClickedBtnUpgradeAllSkill)
    ON_BN_CLICKED(IDC_BTN_CREATE_LEVEL_ITEMS, &CMPPSetItemPane::OnBnClickedBtnCreateLevelItems)
    ON_BN_CLICKED(IDC_BTN_SUPER_MODE, &CMPPSetItemPane::OnBnClickedBtnSuperMode)
END_MESSAGE_MAP()


// CMPPSetItemPane �����Դϴ�.

#ifdef _DEBUG
void CMPPSetItemPane::AssertValid() const
{
    CXTResizeFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMPPSetItemPane::Dump(CDumpContext& dc) const
{
    CXTResizeFormView::Dump(dc);
}
#endif
#endif //_DEBUG


void CMPPSetItemPane::OnInitialUpdate()
{
    CXTResizeFormView::OnInitialUpdate();

    m_cbTeleSelect.InsertString(MPP_TELE_YAHOI, L"��ȣ�� ����");
    m_cbTeleSelect.InsertString(MPP_TELE_YUREKA, L"����ī ����");
    m_cbTeleSelect.InsertString(MPP_TELE_DALPANG, L"������ ����");
    m_cbTeleSelect.InsertString(MPP_TELE_DRAGON, L"���� �ڰ���");
    m_cbTeleSelect.InsertString(MPP_TELE_BAEE, L"�迡 ������");
    m_cbTeleSelect.InsertString(MPP_TELE_AJIRANG, L"�������� ��");
    m_cbTeleSelect.InsertString(MPP_TELE_KARINGA_1, L"ī������ ����1");
    m_cbTeleSelect.InsertString(MPP_TELE_KARINGA_2, L"ī������ ����2");
    m_cbTeleSelect.InsertString(MPP_TELE_GREAT_TREE, L"�׷���Ʈ Ʈ��");
    m_cbTeleSelect.InsertString(MPP_TELE_KARINGA_3, L"ī������ ����");
    m_cbTeleSelect.InsertString(MPP_TELE_MERMAID, L"�ξ��");
    m_cbTeleSelect.InsertString(MPP_TELE_GANNET, L"���� õ����");
    m_cbTeleSelect.InsertString(MPP_TELE_EMERALD, L"���޶��� ��ġ");
    m_cbTeleSelect.InsertString(MPP_TELE_TEMBARIN, L"�۹��� ķ��");
    m_cbTeleSelect.InsertString(MPP_TELE_CELL, L"�� ��");
    m_cbTeleSelect.InsertString(MPP_TELE_BUU, L"�ο� ����");
    m_cbTeleSelect.InsertString(MPP_TELE_CC, L"CC ���� �ڹ���");
    m_cbTeleSelect.InsertString(MPP_TELE_MUSHROOM, L"������");
}

// CMPPSetItemPane �޽��� ó�����Դϴ�.

void CMPPSetItemPane::OnBnClickedBtnCreateitem()
{
    CString strItemId;
    m_edCreateItem.GetWindowText(strItemId);

    if(strItemId.GetLength() > 0)
    {
        GetMPPClientEvent()->SendEvent(MSG_MRPOPO_CREATE_ITEM, _wtoi(strItemId));
    }    
    else
    {
        MessageBox(L"Input Item Table Id");
    }
}

void CMPPSetItemPane::OnBnClickedBtnUpgradeitem()
{
    GetMPPClientEvent()->SendEvent(MSG_MRPOPO_UPGRADE_ITEM, NULL);    
}

void CMPPSetItemPane::OnBnClickedBtnSetzenny()
{
    CString strZenny;    
    m_edSetZenny.GetWindowText(strZenny);

    if(strZenny.GetLength() > 0)
    {
        GetMPPClientEvent()->SendEvent(MSG_MRPOPO_SET_ZENNY, _wtoi(strZenny));
    }            
    else
    {
        MessageBox(L"Input Zenny Amount");
    }
}

void CMPPSetItemPane::OnBnClickedBtnAddexp()
{
    CString strExp;
    m_edAddExp.GetWindowText(strExp);

    if(strExp.GetLength() > 0)
    {
        GetMPPClientEvent()->SendEvent(MSG_MRPOPO_ADD_EXP, _wtoi(strExp));
    }
    else
    {
        MessageBox(L"Input Add Exp");
    }
}

void CMPPSetItemPane::OnBnClickedBtnSetlevel()
{
    CString str;
    m_edSetLevel.GetWindowText(str);

    if(str.GetLength() > 0)
    {
        GetMPPClientEvent()->SendEvent(MSG_MRPOPO_SET_LEVEL, _wtoi(str));
    }
    else
    {
        MessageBox(L"Input Set Level");
    }
}

void CMPPSetItemPane::OnBnClickedBtnCollectdragonball()
{
    GetMPPClientEvent()->SendEvent(MSG_MRPOPO_COLLECT_DRAGONBALL, NULL);
}

void CMPPSetItemPane::OnBnClickedBtnSetspeed()
{
    CString str;
    m_edSetSpeed.GetWindowText(str);

    if(str.GetLength() > 0)
    {
        GetMPPClientEvent()->SendEvent(MSG_MRPOPO_SETSPEED, _wtoi(str));
    }
    else
    {
        MessageBox(L"Input Set Speed");
    }
}

void CMPPSetItemPane::OnBnClickedBtnOffence()
{

}

void CMPPSetItemPane::OnBnClickedBtnDefence()
{

}


void CMPPSetItemPane::OnBnClickedRdSelect()
{
    m_nTeleIndex = 1;
}

void CMPPSetItemPane::OnBnClickedRdDirect()
{
    m_nTeleIndex = 2;
}

void CMPPSetItemPane::OnBnClickedRdVisit()
{
    m_nTeleIndex = 3;
}

void CMPPSetItemPane::OnBnClickedButton1()
{
    if(m_nTeleIndex <= 0)
        return;

    if(m_nTeleIndex == 1)
    {
        int nIndex = m_cbTeleSelect.GetCurSel();
        GetMPPClientEvent()->SendEvent(MSG_MRPOPO_TELEPORT, nIndex);
    }
    else if(m_nTeleIndex == 2)
    {
        CString strX, strZ;
        m_edTeleX.GetWindowText(strX);
        m_edTeleZ.GetWindowText(strZ);
        GetMPPClientEvent()->SendEvent(MSG_MRPOPO_TELE_DIRECT_X, _wtoi(strX));
        GetMPPClientEvent()->SendEvent(MSG_MRPOPO_TELE_DIRECT_Z, _wtoi(strZ));
    }
    else if(m_nTeleIndex == 3)
    {

    }
}

void CMPPSetItemPane::OnBnClickedBtnLearnAllSkill()
{
    GetMPPClientEvent()->SendEvent(MSG_MRPOPO_LEARN_ALL_SKILL, NULL);   
}

void CMPPSetItemPane::OnBnClickedBtnUpgradeAllSkill()
{
    GetMPPClientEvent()->SendEvent(MSG_MRPOPO_UPGRADE_ALL_SKILL, NULL);   
}

void CMPPSetItemPane::OnBnClickedBtnCreateLevelItems()
{
    GetMPPClientEvent()->SendEvent(MSG_MRPOPO_CREATE_LEVEL_ITEMS, NULL);   
}

void CMPPSetItemPane::OnBnClickedBtnSuperMode()
{
    GetMPPClientEvent()->SendEvent(MSG_MRPOPO_SUPER_MODE, NULL);
}
