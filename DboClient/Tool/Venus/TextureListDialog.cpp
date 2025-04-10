// TextureListDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "VenusFrame.h"

#include "TextureListDialog.h"

#include "TextureLayer.h"

#include "rwcore.h"

#include "NtlEffectSystemFreeList.h"
#include ".\texturelistdialog.h"

// CTextureListDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CTextureListDialog, CDialog)
CTextureListDialog::CTextureListDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTextureListDialog::IDD, pParent)
{
	m_Initialized = FALSE;
}

CTextureListDialog::~CTextureListDialog()
{
}

void CTextureListDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXTURE_LIST, m_TextureList);
}


BEGIN_MESSAGE_MAP(CTextureListDialog, CDialog)
	ON_WM_SIZE()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TEXTURE_LIST, OnTvnSelchangedTextureList)
END_MESSAGE_MAP()


// CTextureListDialog �޽��� ó�����Դϴ�.
BOOL CTextureListDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_TextureList.InitTreeCtrl();

	m_Initialized = TRUE;
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CTextureListDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_Initialized)
	{
	}
}

BOOL CTextureListDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN) 
	{
		if(pMsg->wParam == VK_RETURN) return FALSE;	
		if(pMsg->wParam == VK_ESCAPE) return FALSE;	
        if(pMsg->wParam == VK_F5) 
        {
            OnRefreshList();
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
void CTextureListDialog::SerializeList()
{
	CNtlResourceFileManager::svdef_String::iterator it;
	for (it = CNtlEffectSystemFreeList::m_TextureFileManager.m_svExt.begin(); it != CNtlEffectSystemFreeList::m_TextureFileManager.m_svExt.end(); ++ it)
	{
		m_TextureList.AddExt((*it).c_str());
	}
	m_TextureList.SerializeList(CNtlEffectSystemFreeList::m_TextureFileManager.m_strPath.c_str());
}

void CTextureListDialog::OnTvnSelchangedTextureList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	HTREEITEM hItem = m_TextureList.GetSelectedItem();
	if(hItem == NULL)
	{
		CTextureLayer* pLayer = (CTextureLayer*)gGetEditLayer(EDIT_LAYER_TEXTURE);
		pLayer->CreateBitmap(NULL);
		return;
	}

	CString strFileName = m_TextureList.GetItemText(hItem);
	const RwChar* strPathName = CNtlEffectSystemFreeList::m_TextureFileManager.GetPathName(strFileName.GetBuffer(0));
	if (strPathName != NULL)
	{
		CTextureLayer* pLayer = (CTextureLayer*)gGetEditLayer(EDIT_LAYER_TEXTURE);
		pLayer->CreateBitmap(strPathName);
	}
	else
	{
		CTextureLayer* pLayer = (CTextureLayer*)gGetEditLayer(EDIT_LAYER_TEXTURE);
		pLayer->CreateBitmap(NULL);
	}

	*pResult = 0;
}

void CTextureListDialog::OnRefreshList()
{
    m_TextureList.DeleteAllItems();

    SerializeList();
}