// MeshListDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "MeshListDialog.h"
#include ".\meshlistdialog.h"

#include "rwcore.h"

#include "VenusFramework.h"
#include "NtlEffectSystemFreeList.h"

// CMeshListDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CMeshListDialog, CDialog)
CMeshListDialog::CMeshListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMeshListDialog::IDD, pParent)
{
	m_Initialized = FALSE;
}

CMeshListDialog::~CMeshListDialog()
{
}

void CMeshListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MESH_LIST, m_MeshList);
}


BEGIN_MESSAGE_MAP(CMeshListDialog, CDialog)
	ON_WM_SIZE()
	ON_NOTIFY(TVN_SELCHANGED, IDC_MESH_LIST, OnTvnSelchangedMeshList)
END_MESSAGE_MAP()


// CMeshListDialog �޽��� ó�����Դϴ�.

BOOL CMeshListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_Initialized = TRUE;

	m_MeshList.InitTreeCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CMeshListDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_Initialized)
	{
	}
}


BOOL CMeshListDialog::PreTranslateMessage(MSG* pMsg)
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
void CMeshListDialog::SerializeList()
{
	CNtlResourceFileManager::svdef_String::iterator it;
	for (it = CNtlEffectSystemFreeList::m_ClumpFileManager.m_svExt.begin(); it != CNtlEffectSystemFreeList::m_ClumpFileManager.m_svExt.end(); ++ it)
	{
		m_MeshList.AddExt((*it).c_str());
	}
	m_MeshList.SerializeList(CNtlEffectSystemFreeList::m_ClumpFileManager.m_strPath.c_str());
}


void CMeshListDialog::OnTvnSelchangedMeshList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	HTREEITEM hItem = m_MeshList.GetSelectedItem();
	if(hItem == NULL)
	{
		CVenusFramework::GetInstance().CreateEffectClump(NULL);
		return;
	}

	CString strFileName = m_MeshList.GetItemText(hItem);
	const RwChar* strPathName = CNtlEffectSystemFreeList::m_ClumpFileManager.GetPathName(strFileName.GetBuffer(0));
	CVenusFramework::GetInstance().CreateEffectClump(strPathName);
	*pResult = 0;
}

void CMeshListDialog::OnRefresh()
{
    m_MeshList.DeleteAllItems();
    SerializeList();
}
