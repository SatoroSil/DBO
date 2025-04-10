// AnimationListDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "AnimationListDialog.h"
#include ".\animationlistdialog.h"

#include "rwcore.h"

#include "NtlResourceEffect.h"

#include "NtlEffectSystemFreeList.h"


// CAnimationListDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CAnimationListDialog, CDialog)
CAnimationListDialog::CAnimationListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimationListDialog::IDD, pParent)
{
}

CAnimationListDialog::~CAnimationListDialog()
{
}

void CAnimationListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ANIMATION_LIST, m_AnimationList);
}


BEGIN_MESSAGE_MAP(CAnimationListDialog, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CAnimationListDialog �޽��� ó�����Դϴ�.

BOOL CAnimationListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_AnimationList.InitTreeCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CAnimationListDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


BOOL CAnimationListDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN) 
	{
		if(pMsg->wParam == VK_RETURN) return FALSE;	
		if(pMsg->wParam == VK_ESCAPE) return FALSE;	
        if(pMsg->wParam == VK_F5)
        {
            OnRefresh();
        }
	}
	return CDialog::PreTranslateMessage(pMsg);
}

//------------------------------------------------------------------
//	FuncName	: SerializeList
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
void CAnimationListDialog::SerializeList()
{
	CNtlResourceFileManager::svdef_String::iterator it;
	for (it = CNtlEffectSystemFreeList::m_AnimationFileManager.m_svExt.begin(); it != CNtlEffectSystemFreeList::m_AnimationFileManager.m_svExt.end(); ++ it)
	{
		m_AnimationList.AddExt((*it).c_str());
	}
	m_AnimationList.SerializeList(CNtlEffectSystemFreeList::m_AnimationFileManager.m_strPath.c_str());
}

void CAnimationListDialog::OnRefresh()
{
    m_AnimationList.DeleteAllItems();
    SerializeList();
}