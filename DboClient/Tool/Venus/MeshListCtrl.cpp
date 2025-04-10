// MeshListCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "VenusFrame.h"

#include "MeshListCtrl.h"
#include ".\meshlistctrl.h"

#include "TextureLayer.h"
#include "EffectEditLayer.h"

#include "VenusConfig.h"

#include "NtlResourceEffect.h"

#include "NtlDebug.h"

#include "NtlResourceFileManager.h"
#include "NtlEffectSystemFreeList.h"

// CMeshListCtrl

IMPLEMENT_DYNAMIC(CMeshListCtrl, CListCtrl)
CMeshListCtrl::CMeshListCtrl()
{
}

CMeshListCtrl::~CMeshListCtrl()
{
}


BEGIN_MESSAGE_MAP(CMeshListCtrl, CVenusGridCtrl)
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CMeshListCtrl �޽��� ó�����Դϴ�.


int CMeshListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CVenusGridCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if(!m_image.Create(IDB_EFFECT_LIST_IMAGE,16,1,RGB(0, 255, 255)))
		return -1;

	SetImageList(&m_image, LVSIL_SMALL);
	CImageList *pImageList = GetImageList(LVSIL_SMALL);
	if(pImageList)
		ImageList_GetIconSize(pImageList->m_hImageList, &m_cxImage, &m_cyImage);
	else
		return -1;

	return 0;
}

void CMeshListCtrl::InitializeGrid()
{
	/*
	ExtendedStyle support:
	LVS_EX_TRACKSELECT
	LVS_EX_GRIDLINES
	LVS_EX_FLATSB
	LVS_EX_CHECKBOXES
	LVS_EX_FLATSB
	all other ExStyles are not supported...buhhh and you call your self a windows-developer :(
	*/
	SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES);

	LPTSTR lpszCols[] = {_T("Name"),_T("Test"),0};

	LV_COLUMN   lvColumn;
	//initialize the columns
	lvColumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 230;
	lvColumn.pszText = lpszCols[0];
	InsertColumn(0, &lvColumn);

//	lvColumn.cx = 100;
//	lvColumn.pszText = lpszCols[1];
//	InsertColumn(1, &lvColumn);
}

void CMeshListCtrl::RebuildMeshList()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	DeleteAllItems();
	DeleteAll();

	CNtlResourceFileManager::smdef_Entity::iterator it;
	for (it = CNtlEffectSystemFreeList::m_ClumpFileManager.m_smEntity.begin(); it != CNtlEffectSystemFreeList::m_ClumpFileManager.m_smEntity.end(); ++ it)
	{
		std::string strFileName = (*it).first.c_str();
		InsertTreeItem(strFileName.c_str(), 0, NULL, NULL);
	}
}
