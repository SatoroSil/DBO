// PageMob.cpp : implementation file
//

#include "stdafx.h"
#include "ModelTool.h"
#include "PageMob.h"
#include "RightToolView.h"


// CPageMob dialog


IMPLEMENT_DYNAMIC(CPageMob, CPropertyPage)

CPageMob::CPageMob()
	: CPagePC(CPageMob::IDD)
{

}

CPageMob::~CPageMob()
{
 
}

BOOL CPageMob::OnInitDialog()
{
    USES_CONVERSION;

    CPropertyPage::OnInitDialog();

    m_treePC.SetRoot(L"MOB");
    m_treePC.SetParent(this);
    m_btSaveScript.EnableWindow(FALSE);

    m_pInstance = this;

    CString sWorkFolder = A2W(CModelToolApplication::GetInstance()->GetWorkDir());
    sWorkFolder += L"\\TreeMOB.xml";
    m_treePC.LoadTree((LPWSTR)(LPCWSTR)sWorkFolder);

    // Save�� �����̸��� �����Ѵ�.
    m_sSaveFolderName = A2W(CModelToolApplication::GetInstance()->GetWorkDir());
    m_sSaveFolderName += L"\\Character\\";

    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

void CPageMob::OnDestroy()
{
    // â�� �������� ���� XML�� ������ �����Ѵ�.
    USES_CONVERSION;

    CString sWorkFolder = A2W(CModelToolApplication::GetInstance()->GetWorkDir());
    sWorkFolder += L"\\TreeMOB.xml";
    m_treePC.SaveTree(L"MOB", (LPWSTR)(LPCWSTR)sWorkFolder);

    CPropertyPage::OnDestroy();    
}

BOOL CPageMob::OnSetActive()
{
    // Ȱ��ȭ �ɶ� RightView�� �ڽ��� ������ �˷���� �Ѵ�.
    // RightView�� �������� ���ǰ�, LeftView�� ������ ����
    // �ִϸ��̼� ������ �޶����� �ϱ� ����
    CRightToolView::GetInstance()->SetActiveLeftView(CRightToolView::LEFT_PAGE_MOB);

    // ���õ� �������� �ٽ��ѹ� ������ �ش�. (������ ������ Ȱ��ȭ�� ����)
    HTREEITEM hSelectedItem = m_treePC.GetSelectedItem();
    if(hSelectedItem)
    {
        m_treePC.SelectItem(m_treePC.GetRootItem());
        m_treePC.SelectItem(hSelectedItem);
    }

    return CPropertyPage::OnSetActive();
}