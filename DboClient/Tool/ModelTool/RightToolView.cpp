// RightToolView.cpp : implementation file
//

#include "stdafx.h"
#include "MTDef.h"
#include "ModelTool.h"
#include "RightToolView.h"
#include "BottomToolView.h"
#include "AnimToolView.h"
#include "AnimAttrView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRightToolView
CRightToolView* CRightToolView::m_Instance = NULL;

IMPLEMENT_DYNCREATE(CRightToolView, CFormView)

CRightToolView::CRightToolView()
	: CFormView(CRightToolView::IDD)
{
    m_Instance  = this;
    m_pCharacter = NULL;
    m_pAnimTable = NULL;
    m_nCurrentAnimKey = 0;
    m_eAnimSetKind = COMMON_ANIM_SET;
    m_pCurrentAnimData = FALSE;
}

CRightToolView::~CRightToolView()
{
}

void CRightToolView::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CB_ANIM_SET, m_cbAnimSet);    
    DDX_Control(pDX, IDC_LT_ANIM_ITEM, m_ltAnimItem);   
    DDX_Control(pDX, IDC_RA_PHYSICAL, m_raPhysical);
    DDX_Control(pDX, IDC_RA_ENERGY, m_raEnergy);    ;
    DDX_Control(pDX, IDC_LT_ANIM_ITEM2, m_ltUpperAnim);
    DDX_Control(pDX, IDC_ED_DAMAGE00, m_edDamage[0]);
    DDX_Control(pDX, IDC_ED_DAMAGE01, m_edDamage[1]);
    DDX_Control(pDX, IDC_ED_DAMAGE02, m_edDamage[2]);
    DDX_Control(pDX, IDC_ED_DAMAGE03, m_edDamage[3]);
    DDX_Control(pDX, IDC_ED_DAMAGE04, m_edDamage[4]);
    DDX_Control(pDX, IDC_ED_DAMAGE05, m_edDamage[5]);
    DDX_Control(pDX, IDC_ED_DAMAGE06, m_edDamage[6]);
    DDX_Control(pDX, IDC_ED_DAMAGE07, m_edDamage[7]);      
    DDX_Control(pDX, IDC_ED_DAMAGE08, m_edDamage[8]);   
    DDX_Control(pDX, IDC_ED_DAMAGE09, m_edDamage[9]);   
    DDX_Control(pDX, IDC_ED_DAMAGE10, m_edDamage[10]);   
    DDX_Control(pDX, IDC_ED_DAMAGE11, m_edDamage[11]);   
    DDX_Control(pDX, IDC_ED_DAMAGE12, m_edDamage[12]);   
    DDX_Control(pDX, IDC_ED_DAMAGE13, m_edDamage[13]);   
    DDX_Control(pDX, IDC_ED_DAMAGE14, m_edDamage[14]);   
    DDX_Control(pDX, IDC_ED_DAMAGE15, m_edDamage[15]);   
}

BEGIN_MESSAGE_MAP(CRightToolView, CFormView)	
    ON_CBN_SELCHANGE(IDC_CB_ANIM_SET, &CRightToolView::OnCbnSelchangeCbAnimSet)    
    ON_NOTIFY(NM_RCLICK, IDC_LT_ANIM_ITEM, &CRightToolView::OnNMRclickLtAnimItem)
    ON_COMMAND(ID_MENU_ANIM_SET, &CRightToolView::OnMenuAnimSet)
    ON_COMMAND(ID_MENU_ANIM_DELETE, &CRightToolView::OnMenuAnimDelete)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LT_ANIM_ITEM, &CRightToolView::OnLvnItemchangedLtAnimItem)
    ON_BN_CLICKED(IDC_RA_ENERGY, &CRightToolView::OnBnClickedRaEnergy)
    ON_BN_CLICKED(IDC_RA_PHYSICAL, &CRightToolView::OnBnClickedRaPhysical)        
    ON_WM_SIZE()    
    ON_EN_CHANGE(IDC_ED_DAMAGE00, &CRightToolView::OnEnChangeEdDamage00)
    ON_EN_CHANGE(IDC_ED_DAMAGE01, &CRightToolView::OnEnChangeEdDamage01)
    ON_EN_CHANGE(IDC_ED_DAMAGE02, &CRightToolView::OnEnChangeEdDamage02)
    ON_EN_CHANGE(IDC_ED_DAMAGE03, &CRightToolView::OnEnChangeEdDamage03)
    ON_EN_CHANGE(IDC_ED_DAMAGE04, &CRightToolView::OnEnChangeEdDamage04)
    ON_EN_CHANGE(IDC_ED_DAMAGE05, &CRightToolView::OnEnChangeEdDamage05)
    ON_EN_CHANGE(IDC_ED_DAMAGE06, &CRightToolView::OnEnChangeEdDamage06)
    ON_EN_CHANGE(IDC_ED_DAMAGE07, &CRightToolView::OnEnChangeEdDamage07)
    ON_EN_CHANGE(IDC_ED_DAMAGE08, &CRightToolView::OnEnChangeEdDamage08)
    ON_EN_CHANGE(IDC_ED_DAMAGE09, &CRightToolView::OnEnChangeEdDamage09)
    ON_EN_CHANGE(IDC_ED_DAMAGE10, &CRightToolView::OnEnChangeEdDamage10)
    ON_EN_CHANGE(IDC_ED_DAMAGE11, &CRightToolView::OnEnChangeEdDamage11)
    ON_EN_CHANGE(IDC_ED_DAMAGE12, &CRightToolView::OnEnChangeEdDamage12)
    ON_EN_CHANGE(IDC_ED_DAMAGE13, &CRightToolView::OnEnChangeEdDamage13)
    ON_EN_CHANGE(IDC_ED_DAMAGE14, &CRightToolView::OnEnChangeEdDamage14)
    ON_EN_CHANGE(IDC_ED_DAMAGE15, &CRightToolView::OnEnChangeEdDamage15)
END_MESSAGE_MAP()


// CRightToolView diagnostics

#ifdef _DEBUG
void CRightToolView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CRightToolView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CRightToolView message handlers

void CRightToolView::OnInitialUpdate()
{
    CFormView::OnInitialUpdate();

    // Animation Set�� �ʱ�ȭ�Ѵ�.
    m_cbAnimSet.InsertString(COMMON_ANIM_SET, L"Common Animation Set");
    m_cbAnimSet.InsertString(ATTACK_ANIM_SET, L"Attack Animation Set");
    m_cbAnimSet.InsertString(BATTLE_ANIM_SET, L"Battle Animation Set");
    m_cbAnimSet.InsertString(SKILL_ANIM_SET, L"Skill Animation Set");

    m_cbAnimSet.SetCurSel(0);

    m_ltAnimItem.SetExtendedStyle(m_ltAnimItem.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
    m_ltAnimItem.InsertColumn(0, L"ID", 0, 30, 0);
    m_ltAnimItem.InsertColumn(1, L"Anim Name", 0, 160, 1);
    m_ltAnimItem.InsertColumn(2, L"Anim File", 0, 110, 2);
        
    for(int i = 0; i < MAX_HIT_EVENT_COUNT; ++i)
    {
        m_vEventAnimHit[i] = NULL;
    }
    // ó������ ��� Disable �Ǿ� �ִ�.
    SetEnable(DISABLE_ALL);
}


void CRightToolView::SetInit(CMTCharacter* pCharacter)
{
    if(pCharacter == NULL)
    {
        // Anim Edit ����� Disable ��Ų��.
        SetEnable(DISABLE_ALL);
        return;
    }

    m_pCharacter = pCharacter;
    m_pAnimTable  = pCharacter->GetProperty()->GetAnimTable();
    

    // UI �ʱ�ȭ
    m_cbAnimSet.SetCurSel(0);
    OnCbnSelchangeCbAnimSet();

    // AnimData �ʱ�ȭ    
    m_nCurrentAnimKey = 0;

}

void CRightToolView::SetEnable(ECtrlEnable eEnable)
{
    m_cbAnimSet.EnableWindow(FALSE);
    m_ltAnimItem.EnableWindow(FALSE);
    m_ltUpperAnim.EnableWindow(FALSE);
    m_raPhysical.EnableWindow(FALSE);
    m_raEnergy.EnableWindow(FALSE);    
    for(int i = 0; i < MAX_HIT_EVENT_COUNT; ++i)
    {
        m_edDamage[i].EnableWindow(FALSE);
    }

    switch(eEnable)
    {
    case DISABLE_ALL:
        break;

    case ENABLE_ANIMSET:
        m_cbAnimSet.EnableWindow(TRUE);
        m_ltAnimItem.EnableWindow(TRUE);
        m_ltUpperAnim.EnableWindow(TRUE);
        break;
    }    
}

void CRightToolView::SetActiveLeftView(ELeftPage eActiveLeftPage)
{
    m_eActiveLeftPage = eActiveLeftPage;
}

void CRightToolView::OnCbnSelchangeCbAnimSet()
{
    // �޺��ڽ��� ����Ǿ�����, ����Ʈ�� ������ �׸��� �����Ѵ�.
    USES_CONVERSION;

    if(!m_pCharacter || !m_pAnimTable)
        return;

    m_ltAnimItem.DeleteAllItems();

    int nIndex = m_cbAnimSet.GetCurSel();    
    int nAnimKeyStart = 0;
    int nCount = 0;
    int nAnimKenEnd   = 0;

    switch(nIndex)
    {
    case COMMON_ANIM_SET:
        nAnimKeyStart = COMMON_ANIMATION_START;
        nAnimKenEnd   = COMMON_ANIMATION_END;                   
        break;
    case ATTACK_ANIM_SET:
        nAnimKeyStart = ATTACK_ANIMATION_START;
        nAnimKenEnd   = ATTACK_ANIMATION_END;        
        break;
    case BATTLE_ANIM_SET:
        nAnimKeyStart = BATTLE_ANIMATION_START;
        nAnimKenEnd   = BATTLE_ANIMATION_END;        
        break;
    case SKILL_ANIM_SET:
        nAnimKeyStart = SKILL_ANIMATION_START;
        nAnimKenEnd   = SKILL_ANIMATION_END;
        break;
    }    

    SetUIStatus((EAnimSet)nIndex);
    CAnimAttrView::GetInstance()->SetInit(NULL, NULL);
    

    for(int i = nAnimKeyStart; i <= nAnimKenEnd; ++i)
    {
        std::string* sAnimName =  NULL;
        if(m_eActiveLeftPage == LEFT_PAGE_PC)
        {
            sAnimName = m_CharacterPaser.GetPCMatchTable()->GetString(i);
        }
        else if(m_eActiveLeftPage == LEFT_PAGE_MOB)
        {
            sAnimName = m_CharacterPaser.GetMobMatchTable()->GetString(i);
        }
        
        if(sAnimName)
        {
            CString sAnimID;
            sAnimID.Format(L"%d ", i);            
            m_ltAnimItem.InsertItem(nCount, sAnimID);  
            m_ltAnimItem.SetItem(nCount, 1, LVIF_TEXT, A2W(sAnimName->c_str()), 0, 0, 0, 0);

            // �����Ͱ� ������쿡�� ǥ���Ѵ�.
            if(m_pAnimTable)
            {
                STypeAnimData* pAnimData = m_pAnimTable->Get(i);
                if(pAnimData && pAnimData->strAnimName.size() > 0)
                {
                    
                    // ��� ��θ� �����Ѵ�.
                    WCHAR* pChar = wcsstr(A2W(pAnimData->strAnimName.c_str()), L"\\");
                    WCHAR* pAnimName;
                    while(pChar)
                    {
                        pAnimName = pChar + 1;
                        pChar = wcsstr(pAnimName, L"\\");
                    }
                    
                    m_ltAnimItem.SetItem(nCount, 2, LVIF_TEXT, pAnimName, 0, 0, 0, 0);

                }
            }            
            ++nCount;
        }        
    }
}

void CRightToolView::SetUIStatus(EAnimSet eAnimSet)
{
    m_eAnimSetKind = eAnimSet;

    if(!m_pCurrentAnimData)
        return;

    switch(eAnimSet)
    {
    case COMMON_ANIM_SET:
        for(int i = 0; i < MAX_HIT_EVENT_COUNT; ++i)
        {
            // ��� disable
            m_edDamage[i].EnableWindow(FALSE);                     
        }
        m_raPhysical.EnableWindow(FALSE);
        m_raEnergy.EnableWindow(FALSE);

        break;
    case ATTACK_ANIM_SET:        
        m_raPhysical.EnableWindow(TRUE);
        m_raEnergy.EnableWindow(TRUE);
        break;        
    case BATTLE_ANIM_SET:        
        m_raPhysical.EnableWindow(TRUE);
        m_raEnergy.EnableWindow(TRUE);
        break;
    case SKILL_ANIM_SET:        
        m_raPhysical.EnableWindow(TRUE);
        m_raEnergy.EnableWindow(TRUE);
        break;
    }
}


void CRightToolView::OnLvnItemchangedLtAnimItem(NMHDR *pNMHDR, LRESULT *pResult)
{
    USES_CONVERSION;

    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

    // ���õ� �������� ����Ǿ����� �׿� �´� �ִϸ��̼��� �����Ѵ�.

    int nIndex = pNMLV->iItem;

    // ������ �ִϸ��̼��� ������, �� �ִϸ��̼����� �ִϸ��̼��� �����Ѵ�.    
    CNtlPLCharacterProperty*  pCharacterProp = m_pCharacter->GetProperty();
    if(pCharacterProp)
    {
        CString sAnimFileName = m_ltAnimItem.GetItemText(nIndex, 2);
        if(sAnimFileName != "")
        {
            CString sAnimID = m_ltAnimItem.GetItemText(nIndex, 0);
            RwUInt32 uiAnimKey = (RwUInt32)_wtoi(sAnimID);

            SetAnimData(uiAnimKey);
        }
        else
        {
            // ������ �ִϸ��̼������� ������ Edit UI�� Disable ��Ų��.
            SetEnable(ENABLE_ANIMSET);
        }
    }
    *pResult = 0;
}

void CRightToolView::OnNMRclickLtAnimItem(NMHDR *pNMHDR, LRESULT *pResult)
{
    // ������ Ŭ���� �˾��޴��� �ٿ��.
    int nIndex = m_ltAnimItem.GetSelectionMark();
    if(nIndex >= 0)
    {
        POINT pos;
        GetCursorPos(&pos);        
        CMenu   menuPopup;
        menuPopup.LoadMenu(IDR_MENU1);
        CMenu*  subMenu = menuPopup.GetSubMenu(2);

        // �ִϸ��̼����� ������ ���翩�ο� ���� �޴��� �����Ѵ�.
        CString sAnimFileName = m_ltAnimItem.GetItemText(nIndex, 2);
        if(sAnimFileName == "")
        {
            subMenu->EnableMenuItem(ID_MENU_ANIM_SET, FALSE);
            subMenu->EnableMenuItem(ID_MENU_ANIM_DELETE, TRUE);
        }
        else
        {
            subMenu->EnableMenuItem(ID_MENU_ANIM_SET, FALSE);
            subMenu->EnableMenuItem(ID_MENU_ANIM_DELETE, FALSE);
        }
        
        subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pos.x, pos.y, this);
    }

    *pResult = 0;
}

void CRightToolView::SetAnimData(RwUInt32 uiKey)
{
    if(!m_pCharacter || !m_pAnimTable)
        return;

	// �ִϸ��̼��� �𵨿� �����Ѵ�.
    m_pCharacter->SetAnim(uiKey);

    if(m_nCurrentAnimKey == uiKey)
    {
        SetUIStatus(m_eAnimSetKind);
        return;
    }

    m_nCurrentAnimKey = uiKey;
    
    // �����͵��� UI�� �����Ѵ�.
    m_pAnimTable = m_pCharacter->GetProperty()->GetAnimTable();
    m_pCurrentAnimData = m_pAnimTable->Get(uiKey);
    if(!m_pCurrentAnimData)
        return;

    // �ϴܺ��� Bone Edit�� Ȱ��ȭ ��Ų��.
    CBottomToolView::GetInstance()->SetBoneEditEnable(TRUE);

    // �ִϸ��̼� �÷��� ���並 Ȱ��ȭ ��Ų��.
    CAnimToolView::GetInstance()->SetInit(m_pCharacter, m_pCurrentAnimData);
    CAnimToolView::GetInstance()->SetEnable(TRUE);

    // HitEvent Data�� �����Ѵ�. (Damage ����)
    SetAnimEventData(m_pCurrentAnimData);

    SetUIStatus(m_eAnimSetKind);

    // Attack Type
    if(m_vEventAnimHit[0])
    {
        if(m_vEventAnimHit[0]->eAttackType == ATTACK_TYPE_PHYSICAL)
        {
            m_raPhysical.SetCheck(TRUE);
            m_raEnergy.SetCheck(FALSE);
            OnBnClickedRaPhysical();

        }
        else if(m_vEventAnimHit[0]->eAttackType == ATTACK_TYPE_ENERGY)
        {
            m_raEnergy.SetCheck(TRUE);
            m_raPhysical.SetCheck(FALSE);
            OnBnClickedRaEnergy();
        }
    }
}

void CRightToolView::SetAnimEventData(STypeAnimData* pAnimData)
{
    if(!pAnimData)
        return;
    
    pAnimData->AnimEventSort();   

    int nCount = 0;
    for(UINT i = 0; i < pAnimData->vecAnimEvent.size(); ++i)
    {
        if(pAnimData->vecAnimEvent[i]->eEventID == EVENT_ANIM_HIT && pAnimData->vecAnimEvent[i]->fTime > 0.0f)
        {
            m_edDamage[nCount].EnableWindow(TRUE);
            m_vEventAnimHit[nCount] = (SEventAnimHit*)pAnimData->vecAnimEvent[i];
            if(m_vEventAnimHit[nCount])
            {
                CString sDamage;
                sDamage.Format(L"%d", m_vEventAnimHit[nCount]->uiDamage);
                m_edDamage[nCount].SetWindowText(sDamage);
            }

            ++nCount;
        }        
    }

    for(int i = nCount; i < MAX_HIT_EVENT_COUNT; ++i)
    {
        m_edDamage[i].SetWindowText(L"");
        m_edDamage[i].EnableWindow(FALSE);
        m_vEventAnimHit[i] = NULL;        
    }
}

void CRightToolView::OnMenuAnimSet()
{
    // �׸� �ִϸ��̼� ������ �����Ѵ�.
    USES_CONVERSION;

    int nIndex = m_ltAnimItem.GetSelectionMark();

    WCHAR szOpenFilter[] = L"Animation File (*.anm)|*.anm||";
    CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szOpenFilter);
    if(fileDlg.DoModal() == IDOK)
    {
        CString sLoadFilePath = fileDlg.GetPathName();
        CString sLoadFileName = fileDlg.GetFileName();       
        m_ltAnimItem.SetItem(nIndex, 2, LVIF_TEXT, sLoadFileName, 0, 0, 0, 0);

        // ĳ������ Property�� ������ �ش�.        
        CNtlPLCharacterProperty*  pCharacterProp = m_pCharacter->GetProperty();
        if(pCharacterProp)
        {
            // Property�� Anim ���� ��θ� �����Ѵ�. (��� ���)
            //pCharacterProp->SetAnimPath(GetAnimPath(sLoadFilePath));
            
            // property�� �ִϸ��̼� ���� ������ �߰��Ѵ�.
            CString sAnimID = m_ltAnimItem.GetItemText(nIndex, 0);
            RwUInt32 uiAnimKey = (RwUInt32)_wtoi(sAnimID);
            //
            std::string sAnimFileName = GetAnimPath(sLoadFilePath);
            sAnimFileName += W2A(sLoadFileName);
            
            STypeAnimData* pAnimData = m_pAnimTable->Add(uiAnimKey, sAnimFileName);            

            SetAnimData(uiAnimKey);      

            // Play Time�� �����Ѵ�.
            m_pCharacter->Update(0.1f);
            pAnimData->fPlayTime = m_pCharacter->GetBaseDurationAnimTime();
        }
    }	
}

void CRightToolView::OnMenuAnimDelete()
{
    // �׸� �ִ� �ִϸ��̼��� �����Ѵ�.
    if(!m_pCharacter)
        return;

    USES_CONVERSION;

    int nIndex = m_ltAnimItem.GetSelectionMark();

    CString sAnimID = m_ltAnimItem.GetItemText(nIndex, 0);
    RwUInt32 uiAnimKey = (RwUInt32)_wtoi(sAnimID);

    // ������Ƽ�� ���̺��� �����Ѵ�.
    m_pAnimTable->Remove(uiAnimKey);

    // ����Ʈ ��Ͽ��� �����Ѵ�.
    m_ltAnimItem.SetItemText(nIndex, 2, L"");
}

/**
 * �����θ� �Է¹޾� ����η� ��ȯ�Ѵ�.
 * \param sPathName anim������ ���� ���
 * return Peoperty�� �����ϱ� ���� ��� ���
 */
std::string CRightToolView::GetAnimPath(CString sPathName)
{
    USES_CONVERSION;

    std::string sAnimPath = ".";
    sPathName = sPathName.MakeLower();

    if(sPathName.Find(PATH_ANIM_HUMAN_FEMALE) >= 0)
    {
        sAnimPath += W2A(PATH_ANIM_HUMAN_FEMALE);    
    }
    else if(sPathName.Find(PATH_ANIM_HUMAN_MALE) >= 0)
    {
        sAnimPath += W2A(PATH_ANIM_HUMAN_MALE);
    }
    else if(sPathName.Find(PATH_ANIM_MAJIN_FEMALE) >= 0)
    {
        sAnimPath += W2A(PATH_ANIM_MAJIN_FEMALE);
    }
    else if(sPathName.Find(PATH_ANIM_MAJIN_MALE) >= 0)
    {
        sAnimPath += W2A(PATH_ANIM_MAJIN_MALE);
    }
    else if(sPathName.Find(PATH_ANIM_NAMEK) >= 0)
    {
        sAnimPath += W2A(PATH_ANIM_NAMEK);
    }
    else if(sPathName.Find(PATH_ANIM_MOB) >= 0)
    {
        sAnimPath += W2A(PATH_ANIM_MOB);
    }
    else if(sPathName.Find(PATH_ANIM_NPC) >= 0)
    {
        sAnimPath += W2A(PATH_ANIM_NPC);
    }

    return sAnimPath;
}

void CRightToolView::OnBnClickedRaEnergy()
{
    // ������Ƽ�� �����Ѵ�.    
    for(int i = 0; i < MAX_HIT_EVENT_COUNT; ++i)
    {
        if(m_vEventAnimHit[i])
        {
            m_vEventAnimHit[i]->eAttackType = ATTACK_TYPE_ENERGY;
        }        
    }  
}

void CRightToolView::OnBnClickedRaPhysical()
{
    // ������Ƽ�� �����Ѵ�.
    for(int i = 0; i < MAX_HIT_EVENT_COUNT; ++i)
    {
        if(m_vEventAnimHit[i])
        {
            m_vEventAnimHit[i]->eAttackType = ATTACK_TYPE_PHYSICAL;
        }        
    }    
}

void CRightToolView::ChangeDamage(int nIndex)
{
    CString sDamage;
    
    if(!m_vEventAnimHit[nIndex])
        return;

    // ������ 100�� ������ ������ ����ϰ� ���������� �ǵ�����.
    int nTotalDamage = 0;
    for(int i = 0; i < MAX_HIT_EVENT_COUNT; ++i)
    {
        if(m_edDamage[i])
        {
            m_edDamage[i].GetWindowText(sDamage);
            nTotalDamage += _wtoi(sDamage);
        }
    }

    if(nTotalDamage <= 100)
    {
        m_edDamage[nIndex].GetWindowText(sDamage);        
        m_vEventAnimHit[nIndex]->uiDamage = (RwUInt32)(_wtoi(sDamage));        
    }   
    else    // 100���� ũ��
    {
        sDamage.Format(L"%d", m_vEventAnimHit[nIndex]->uiDamage);
        m_edDamage[nIndex].SetWindowText(sDamage);
        MessageBox(L"Total Damage is Over then 100");
    }
}

void CRightToolView::OnSize(UINT nType, int cx, int cy)
{
    CFormView::OnSize(nType, cx, cy);

    SetScrollSizes(MM_TEXT, CSize(cx, cy));   
}

void CRightToolView::OnEnChangeEdDamage00()
{
    ChangeDamage(0);
}

void CRightToolView::OnEnChangeEdDamage01()
{
    ChangeDamage(1);
}

void CRightToolView::OnEnChangeEdDamage02()
{
    ChangeDamage(2);
}

void CRightToolView::OnEnChangeEdDamage03()
{
    ChangeDamage(3);
}

void CRightToolView::OnEnChangeEdDamage04()
{
    ChangeDamage(4);
}

void CRightToolView::OnEnChangeEdDamage05()
{
    ChangeDamage(5);
}

void CRightToolView::OnEnChangeEdDamage06()
{
    ChangeDamage(6);
}

void CRightToolView::OnEnChangeEdDamage07()
{
    ChangeDamage(7);
}

void CRightToolView::OnEnChangeEdDamage08()
{
    ChangeDamage(8);
}

void CRightToolView::OnEnChangeEdDamage09()
{
    ChangeDamage(9);
}

void CRightToolView::OnEnChangeEdDamage10()
{
    ChangeDamage(10);
}

void CRightToolView::OnEnChangeEdDamage11()
{
    ChangeDamage(11);
}

void CRightToolView::OnEnChangeEdDamage12()
{
    ChangeDamage(12);
}

void CRightToolView::OnEnChangeEdDamage13()
{
    ChangeDamage(13);
}

void CRightToolView::OnEnChangeEdDamage14()
{
    ChangeDamage(14);
}

void CRightToolView::OnEnChangeEdDamage15()
{
    ChangeDamage(15);
}

void CRightToolView::CreateAnimFileMap()
{
    m_mapAnimFile.clear();
        
    //TODO: ����Ʈ ���ϸ��� ���� ���� �����Ѵ�.
    
}