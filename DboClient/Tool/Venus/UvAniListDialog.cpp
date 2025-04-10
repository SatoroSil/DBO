// UvAniListDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "UvAniListDialog.h"
#include ".\uvanilistdialog.h"

#include "rwcore.h"

#include "NtlEffectSystemFreeList.h"


// CUvAniListDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CUvAniListDialog, CDialog)
CUvAniListDialog::CUvAniListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CUvAniListDialog::IDD, pParent)
{
}

CUvAniListDialog::~CUvAniListDialog()
{
}

void CUvAniListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_UVANIMATION_LIST, m_UvAnimationList);
}


BEGIN_MESSAGE_MAP(CUvAniListDialog, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CUvAniListDialog �޽��� ó�����Դϴ�.

BOOL CUvAniListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_UvAnimationList.InitTreeCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CUvAniListDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

BOOL CUvAniListDialog::PreTranslateMessage(MSG* pMsg)
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
void CUvAniListDialog::SerializeList()
{
	CNtlResourceFileManager::svdef_String::iterator it;
	for (it = CNtlEffectSystemFreeList::m_UvAnimationFileManager.m_svExt.begin(); it != CNtlEffectSystemFreeList::m_UvAnimationFileManager.m_svExt.end(); ++ it)
	{
		m_UvAnimationList.AddExt((*it).c_str());
	}
	m_UvAnimationList.SerializeList(CNtlEffectSystemFreeList::m_UvAnimationFileManager.m_strPath.c_str());
}

void CUvAniListDialog::OnRefresh()
{
    m_UvAnimationList.DeleteAllItems();
    SerializeList();
}

