// EffectListCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "InputBox.h"
#include "NtlDebug.h"
#include "Venus.h"
#include "VenusDefine.h"
#include "VenusFrame.h"
#include "EffectListCtrl.h"
#include ".\effectlistctrl.h"
#include "EventLayer.h"
#include "StringManager.h"
#include "EffectEditLayer.h"
#include ".\venuspropertycontainer.h"
#include ".\venusvisualmanager.h"
#include "StringDialog.h"
#include "NtlResourceMeshSystem.h"


// CEffectListCtrl

//IMPLEMENT_DYNAMIC(CEffectListCtrl, CListCtrl)
CEffectListCtrl::CEffectListCtrl()
{
	m_bSequence		= TRUE;
    m_sItemNode.eNodeType = NODE_FOLDER;
    m_pCopyResourceFolder = NULL;
    m_bDrag = FALSE;
    m_bNotSelChange = FALSE;
}

CEffectListCtrl::~CEffectListCtrl()
{
}


BEGIN_MESSAGE_MAP(CEffectListCtrl, CVenusGridCtrl)
	ON_WM_CREATE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(POPUP_CREATE_EFFECT, OnCreateEffect)
	ON_COMMAND(POPUP_DELETE_EFFECT, OnDeleteEffect)
	ON_COMMAND(POPUP_DELETE_SYSTEM, OnDeleteSystem)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnLvnItemchanged)
	ON_COMMAND(POPUP_TEST_EFFECT, OnTestEffect)
	ON_COMMAND(POPUP_CREATE_PARTICLE_SYSTEM, OnCreateParticleSystem)
	ON_COMMAND(POPUP_CREATE_MESH_SYSTEM, OnCreateMeshSystem)
	ON_COMMAND(POPUP_CREATE_BEAM_SYSTEM, OnCreateBeamSystem)
	ON_COMMAND(POPUP_CREATE_HURRICANE_SYSTEM, OnCreateHurricaneSystem)
	ON_WM_TIMER()
	ON_NOTIFY_REFLECT(NM_CLICK, OnNMClick)
	ON_COMMAND(POPUP_CREATE_LIGHTNING_SYSTEM, OnCreateLightningSystem)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnLvnColumnclick)
	ON_COMMAND(POPUP_CREATE_DECAL_SYSTEM, &CEffectListCtrl::OnCreateDecalSystem)
	ON_COMMAND(POPUP_CREATE_POST_EFFECT_SYSTEM, &CEffectListCtrl::OnCreatePostEffectSystem)
    ON_COMMAND(POPUP_CREATE_TRACE_EFFECT_SYSTEM, &CEffectListCtrl::OnCreateTraceEffectSystem)
    ON_COMMAND(POPUP_CREATE_LINE_SYSTEM, &CEffectListCtrl::OnCreateLineSystem)
    ON_WM_LBUTTONUP()
    ON_COMMAND(POPUP_CREATE_FOLDER, &CEffectListCtrl::OnCreateFolder)
    ON_COMMAND(POPUP_DELETE_FOLDER, &CEffectListCtrl::OnDeleteFolder)
    ON_COMMAND(POPUP_RENAME_FOLDER, &CEffectListCtrl::OnRenameFolder)
    //ON_NOTIFY_REFLECT(LVN_BEGINDRAG, &CEffectListCtrl::OnLvnBegindrag)
    ON_NOTIFY_REFLECT(NM_RELEASEDCAPTURE, &CEffectListCtrl::OnNMReleasedcapture)
END_MESSAGE_MAP()



// CEffectListCtrl �޽��� ó�����Դϴ�.


int CEffectListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
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



void CEffectListCtrl::InitializeGrid()
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

	LPTSTR lpszCols[] = {_T("Name"),0};

	LV_COLUMN   lvColumn;
	//initialize the columns
	lvColumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 250;
	lvColumn.pszText = lpszCols[0];
	InsertColumn(0, &lvColumn);
}

void CEffectListCtrl::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu menu;
	menu.CreatePopupMenu();

	if(GetSelectedItem() == -1)
	{
        //  ���� ���� �޴� �߰�
		menu.AppendMenu(MF_STRING, POPUP_CREATE_FOLDER, "Create &Folder");
		menu.AppendMenu(MF_STRING, POPUP_EFFECT_SORT, "Effect Sort");

		if (CVenusPropertyContainer::GetInstance().m_pCopyResourceEffect != NULL && 
			CVenusPropertyContainer::GetInstance().m_pCopyResourceSystem == NULL)
		{
			menu.AppendMenu(MF_SEPARATOR, 0, "");
			menu.AppendMenu(MF_STRING, ID_EDIT_PASTE,	"Paste\tCtrl+V(&P)");
		}

		menu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
		return;
	}

	CTreeItem* pSelectItem = GetTreeItem(GetSelectedItem());
	ETreeItemLevel eLevel = GetTreeItemLevel(pSelectItem);

	switch(eLevel)
	{
    case E_ITEM_LEVEL_FOLDER:        
        {
            // ������ �˾� �޴� ����
            menu.AppendMenu(MF_STRING, POPUP_CREATE_FOLDER, "Create &Folder");
            menu.AppendMenu(MF_STRING, POPUP_CREATE_EFFECT, "Create &Effect");            
            menu.AppendMenu(MF_STRING, ID_EDIT_COPY, "Copy\tCtrl+C(&C)");
            menu.AppendMenu(MF_SEPARATOR, 0, "");
            menu.AppendMenu(MF_STRING, POPUP_RENAME_FOLDER, "&Rename Folder");
            menu.AppendMenu(MF_STRING, POPUP_DELETE_FOLDER, "&Delete Folder");
        }
        break;
	case E_ITEM_LEVEL_EFFECT:
		{
			menu.AppendMenu(MF_STRING, POPUP_TEST_EFFECT, "Create Instance Effect");
			menu.AppendMenu(MF_SEPARATOR, 0, "");

			menu.AppendMenu(MF_STRING, POPUP_CREATE_PARTICLE_SYSTEM,	"&Particle");
			menu.AppendMenu(MF_STRING, POPUP_CREATE_MESH_SYSTEM,		"&Mesh");
			menu.AppendMenu(MF_STRING, POPUP_CREATE_BEAM_SYSTEM,		"&Beam");
			menu.AppendMenu(MF_STRING, POPUP_CREATE_HURRICANE_SYSTEM,	"&Hurricane");
			menu.AppendMenu(MF_STRING, POPUP_CREATE_LIGHTNING_SYSTEM,	"&Lightning");
			menu.AppendMenu(MF_STRING, POPUP_CREATE_DECAL_SYSTEM,		"&Decal");
			menu.AppendMenu(MF_STRING, POPUP_CREATE_POST_EFFECT_SYSTEM,	"&Post Effect");            
            menu.AppendMenu(MF_STRING, POPUP_CREATE_LINE_SYSTEM,        "L&ine System");
			menu.AppendMenu(MF_SEPARATOR, 0, "");
			menu.AppendMenu(MF_STRING, ID_EDIT_COPY,					"Copy\tCtrl+C(&C)");


			if (CVenusPropertyContainer::GetInstance().m_pCopyResourceEffect != NULL && 
				CVenusPropertyContainer::GetInstance().m_pCopyResourceSystem != NULL)
			{
				menu.AppendMenu(MF_SEPARATOR, 0, "");
				menu.AppendMenu(MF_STRING, ID_EDIT_PASTE,	"Paste\tCtrl+V(&P)");
			}

			menu.AppendMenu(MF_SEPARATOR, 0, "");
			menu.AppendMenu(MF_STRING, POPUP_DELETE_EFFECT, "&Delete Effect");
		}
		break;
	case E_ITEM_LEVEL_SYSTEM:
		{
			menu.AppendMenu(MF_STRING, ID_EDIT_CUT,						"Cut\tCtrl+X(&T)");
			menu.AppendMenu(MF_STRING, ID_EDIT_COPY,					"Copy\tCtrl+C(&C)");
			menu.AppendMenu(MF_SEPARATOR, 0, "");
			menu.AppendMenu(MF_STRING, POPUP_DELETE_SYSTEM, "&Delete System");
		}
		break;
	default:
		NTL_ASSERTE(!"default");
	}
	menu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
}

//------------------------------------------------------------------
//	FuncName	: GetImageIndexFromSystemType
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
RwInt32 CEffectListCtrl::GetImageIndexFromSystemType(RwInt32 nSystemType)
{
	switch(nSystemType)
	{
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_PARTICLE:
		return IMAGE_INDEX_RESOURCE_PARTICLE;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_MESH:
		return IMAGE_INDEX_RESOURCE_MESH;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_BEAM:
		return IMAGE_INDEX_RESOURCE_BEAM;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_HURRICANE:
		return IMAGE_INDEX_RESOURCE_HURRICANE;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_LIGHTNING:
		return IMAGE_INDEX_RESOURCE_LIGHTNING;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_DECAL:
		return IMAGE_INDEX_RESOURCE_DECAL;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_POST_EFFECT:
		return IMAGE_INDEX_RESOURCE_POST_EFFECT;
    case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_TRACE:
        return IMAGE_INDEX_RESOURCE_TRACE;
    case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_LINE:
        return IMAGE_INDEX_RESOURCE_LINE;
	default:
		NTL_ASSERTE(!"default");
		break;
	}
	return -1;
}

//------------------------------------------------------------------
//	FuncName	: RebuildResourceEffect
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
void CEffectListCtrl::RebuildResourceEffect()
{
	//SetRedraw(1);

    if(!CVenusPropertyContainer::GetInstance().m_svEffectProperty.empty())
    {
        if(!LoadXMLTree())
        {
            AfxMessageBox("Xml File Not Found.\n Default Tree Create.");
            CreateDefaultXMLTree();
        }
    }
    else
    {
        DeleteAllItems();
        DeleteAll();
        m_sItemNode.vecChildList.clear();
        CNtlTreeXml::m_mapNode.clear();
    }
}

//------------------------------------------------------------------
//	FuncName	: GetRootResourceEffect
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
CNtlResourceEffect* CEffectListCtrl::GetRootResourceEffect()
{
    int nItem = GetSelectedItem();
    if(nItem == -1) return NULL;

    CTreeItem* pSelectItem = GetTreeItem(nItem);
    CTreeItem* pRootItem = NULL;
    if(pSelectItem->m_lpNodeInfo->GetImage() == IMAGE_INDEX_RESOURCE_EFFECT)    
    {
        pRootItem = pSelectItem;        
    }
    else
    {
        pRootItem = GetParentItem(pSelectItem);        
    }
    
	if (pRootItem == NULL) return NULL;

	CItemInfo* pItemInfo = GetData(pRootItem); 
	CNtlResourceEffect* pResourceEffect = (CNtlResourceEffect*)pItemInfo->m_lParam;
	return pResourceEffect;
}

//------------------------------------------------------------------
//	FuncName	: GetSelectResourceEffect
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
CNtlResourceEffect* CEffectListCtrl::GetSelectResourceEffect()
{
	int nItem = GetSelectedItem();
	if(nItem == -1) return NULL;

	CTreeItem* pSelectItem = GetTreeItem(nItem);
	if(pSelectItem == NULL) return NULL;

    if(pSelectItem->m_lpNodeInfo->GetImage() != IMAGE_INDEX_RESOURCE_EFFECT)
	return NULL;

	CItemInfo* pItem = GetData(pSelectItem); 
	return (CNtlResourceEffect*)pItem->m_lParam;
}

//------------------------------------------------------------------
//	FuncName	: GetSelectResourceSystem
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
CNtlResourceComponentSystem* CEffectListCtrl::GetSelectResourceSystem()
{
	int nItem = GetSelectedItem();
	if(nItem == -1) return NULL;

	CTreeItem* pSelectItem = GetTreeItem(nItem);
	if(pSelectItem == NULL) return NULL;

    if(pSelectItem->m_lpNodeInfo->GetImage() == IMAGE_INDEX_RESOURCE_EFFECT ||
       pSelectItem->m_lpNodeInfo->GetImage() == IMAGE_INDEX_RESOURCE_FOLDER)
        return NULL;

	CItemInfo* pItem = GetData(pSelectItem); 
	return (CNtlResourceComponentSystem*)pItem->m_lParam;
}

//------------------------------------------------------------------
//	FuncName	: GetSelectResourceData
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
void CEffectListCtrl::GetSelectResourceData(CNtlResourceEffect*& pResourceEffect, CNtlResourceComponentSystem*& pResourceSystem)
{
	pResourceEffect = NULL;
	pResourceSystem = NULL;

	int nItem = GetSelectedItem();
	if(nItem == -1)
	{
		return;
	}

	CTreeItem* pSelectItem = GetTreeItem(nItem);
	if(pSelectItem == NULL) return;

	CItemInfo* pItem = GetData(pSelectItem);
	RwInt32 nSelectImage = pItem->GetImage();
	switch(nSelectImage)
	{
	case IMAGE_INDEX_RESOURCE_EFFECT:
		{
			pResourceEffect = GetSelectResourceEffect();
			NTL_ASSERTE(pResourceEffect);
		}
		break;
	case IMAGE_INDEX_RESOURCE_PARTICLE:
	case IMAGE_INDEX_RESOURCE_MESH:
	case IMAGE_INDEX_RESOURCE_BEAM:
	case IMAGE_INDEX_RESOURCE_HURRICANE:
	case IMAGE_INDEX_RESOURCE_LIGHTNING:
	case IMAGE_INDEX_RESOURCE_DECAL:
	case IMAGE_INDEX_RESOURCE_POST_EFFECT:
    case IMAGE_INDEX_RESOURCE_TRACE:
    case IMAGE_INDEX_RESOURCE_LINE:
		{
			pResourceEffect = GetRootResourceEffect();
			NTL_ASSERTE(pResourceEffect);
			pResourceSystem = (CNtlResourceComponentSystem*)GetSelectResourceSystem();
			NTL_ASSERTE(pResourceSystem);
		}
		break;
    case IMAGE_INDEX_RESOURCE_FOLDER:
        break;
	default:
		NTL_ASSERTE(!"default");
		break;
	}	
}

//------------------------------------------------------------------
//	FuncName	: CreateResourceSystem
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------

void CEffectListCtrl::CreateResourceSystem(RwInt32 nType, CNtlResourceComponentSystem* pSrcResourceSystem)
{
	int selecteditem = GetSelectedItem();
	if(selecteditem == -1) return;

	CTreeItem* pSelectItem = GetTreeItem(selecteditem);
	ETreeItemLevel level = GetTreeItemLevel(pSelectItem);
    if(level != E_ITEM_LEVEL_EFFECT)
        return;
    
	CItemInfo* pItem = GetData(pSelectItem); 
	CNtlResourceEffect* pResourceEffect = (CNtlResourceEffect*)pItem->m_lParam;

	CString strSystemName;
	RwInt32 count = 0;
	do {
		switch(nType)
		{
		case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_PARTICLE:		strSystemName.Format("ParticleSystem%02d",	count ++);		break;
		case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_MESH:			strSystemName.Format("MeshSystem%02d",		count ++);		break;
		case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_BEAM:			strSystemName.Format("BeamSystem%02d",		count ++);		break;
		case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_HURRICANE:	strSystemName.Format("HurricaneSystem%02d", count ++);		break;
		case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_LIGHTNING:	strSystemName.Format("LightningSystem%02d", count ++);		break;
		case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_DECAL:		strSystemName.Format("DecalSystem%02d",		count ++);		break;
		case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_POST_EFFECT:	strSystemName.Format("PostEffectSystem%02d",count ++);		break;
        case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_TRACE:        strSystemName.Format("TraceEffectSystem%02d", count++);     break;
        case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_LINE:         strSystemName.Format("LineSystem%02d", count++);            break;
		default:															NTL_ASSERTE(!"default");									break;
		}
	} while(CVenusPropertyContainer::GetInstance().IsResourceSystem(pResourceEffect, strSystemName.GetBuffer(0)));

	CNtlResourceComponentSystem* pResourceSystem = CVenusPropertyContainer::GetInstance().CreateResourceSystem(
														pResourceEffect, 
														nType, 
														strSystemName.GetBuffer(0), 
														pSrcResourceSystem);

	CVenusVisualManager::GetInstance().ResetInstanceEffect(pResourceEffect->GetName());

	RwInt32 nImageIndex = 0;
	switch(nType)
	{
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_PARTICLE:		nImageIndex = IMAGE_INDEX_RESOURCE_PARTICLE;	break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_MESH: 		nImageIndex = IMAGE_INDEX_RESOURCE_MESH;		break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_BEAM:			nImageIndex = IMAGE_INDEX_RESOURCE_BEAM;		break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_HURRICANE:	nImageIndex = IMAGE_INDEX_RESOURCE_HURRICANE;	break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_LIGHTNING:	nImageIndex = IMAGE_INDEX_RESOURCE_LIGHTNING;	break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_DECAL:		nImageIndex = IMAGE_INDEX_RESOURCE_DECAL;		break;
	case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_POST_EFFECT:	nImageIndex = IMAGE_INDEX_RESOURCE_POST_EFFECT;	break;
    case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_TRACE:        nImageIndex = IMAGE_INDEX_RESOURCE_TRACE;       break;
    case CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_LINE:         nImageIndex = IMAGE_INDEX_RESOURCE_LINE;        break;    
	default:															NTL_ASSERTE(!"default");						break;
	}    

	InsertTreeItem(strSystemName.GetBuffer(0), nImageIndex, (DWORD_PTR)pResourceSystem, pSelectItem);

	InvalidateRect(NULL, TRUE);
}

void CEffectListCtrl::OnCreateEffect()
{
    CTreeItem* pSelectItem = GetTreeItem(GetSelectedItem());
    SItemNode* pSelectNode = (SItemNode*)pSelectItem->m_lpNodeInfo->m_lParam;
	CString strName, strSrcName;
	RwInt32 count = 0;
	do {
		strName.Format("ResourceEffect%03d", count ++);
	} while(CVenusPropertyContainer::GetInstance().GetProperty(PLENTITY_EFFECT, strName.GetBuffer(0)));

	CNtlResourceEffect* pResourceEffect = (CNtlResourceEffect*)CVenusPropertyContainer::GetInstance().CreateProperty(PLENTITY_EFFECT, strName.GetBuffer(0));
	NTL_ASSERTE(pResourceEffect != NULL);

	InsertTreeItem(strName, IMAGE_INDEX_RESOURCE_EFFECT, (DWORD_PTR)pResourceEffect, pSelectItem, LVIS_SELECTED | LVIS_FOCUSED);
	InvalidateRect(NULL, TRUE);

    SItemNode* pNewNode = NTL_NEW SItemNode();
    pNewNode->eNodeType = NODE_SCIRPT;
    pNewNode->strNodeName = strName;
    pSelectNode->vecChildList.push_back(pNewNode);

	// Event layer ���� ����ϰ� �ִ� ����Ʈ�� ����Ʈ�� �޶� ���Ƿ� ������ �� ��� �Ѵ�.
	CEventLayer* pView = (CEventLayer*)gGetEditLayer(EDIT_LAYER_EVENT);
	pView->ResetProperties();
}


void CEffectListCtrl::OnDeleteEffect()
{
	if (AfxMessageBox("really ?", MB_OKCANCEL) != IDOK) return;
	CNtlResourceEffect* pResourceEffect = GetSelectResourceEffect();
	NTL_ASSERTE(pResourceEffect);

    CTreeItem* pItem = GetTreeItem(GetSelectedItem());
    CTreeItem* pParentItem = pItem->m_pParent;
    SItemNode* pParentNode = (SItemNode*)pParentItem->m_lpNodeInfo->m_lParam;
    pParentNode->EraseChildNode(pResourceEffect->GetName());

	CVenusVisualManager::GetInstance().DeleteInstanceEffect(pResourceEffect->GetName());

	if (CVenusPropertyContainer::GetInstance().DeleteProperty(PLENTITY_EFFECT, pResourceEffect->GetName()))
	{
		DeleteItemEx(GetTreeItem(GetSelectedItem()), GetSelectedItem());
	}
	// Event layer ���� ����ϰ� �ִ� ����Ʈ�� ������ �޶� ���Ƿ� ������ �� ��� �Ѵ�.
	CEventLayer* pView = (CEventLayer*)gGetEditLayer(EDIT_LAYER_EVENT);
	pView->ResetProperties();    

	InvalidateRect(NULL, TRUE);
}


void CEffectListCtrl::OnCreateParticleSystem()
{
	CreateResourceSystem(CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_PARTICLE);
}

void CEffectListCtrl::OnCreateMeshSystem()
{
	CreateResourceSystem(CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_MESH);
}

void CEffectListCtrl::OnCreateBeamSystem()
{
	CreateResourceSystem(CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_BEAM);
}

void CEffectListCtrl::OnCreateHurricaneSystem()
{
	CreateResourceSystem(CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_HURRICANE);
}

void CEffectListCtrl::OnCreateLightningSystem()
{
	CreateResourceSystem(CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_LIGHTNING);
}

void CEffectListCtrl::OnCreateDecalSystem()
{
	CreateResourceSystem(CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_DECAL);
}

void CEffectListCtrl::OnCreatePostEffectSystem()
{
	CreateResourceSystem(CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_POST_EFFECT);
}

void CEffectListCtrl::OnCreateTraceEffectSystem()
{
    CreateResourceSystem(CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_TRACE);
}

void CEffectListCtrl::OnCreateLineSystem()
{
    CreateResourceSystem(CNtlResourceComponentSystem::RESOURCE_SYSTEMTYPE_LINE);
}


void CEffectListCtrl::OnDeleteSystem()
{
	if (AfxMessageBox("really ?", MB_OKCANCEL) != IDOK) return;
	CNtlResourceEffect* pResourceEffect = GetRootResourceEffect();
	NTL_ASSERTE(pResourceEffect);

	CNtlResourceComponentSystem* pResourceSystem = GetSelectResourceSystem();
	NTL_ASSERTE(pResourceSystem);

	CVenusPropertyContainer::GetInstance().DeleteResourceSystem(pResourceEffect, pResourceSystem);

	CVenusVisualManager::GetInstance().ResetInstanceEffect(pResourceEffect->GetName());

	DeleteItemEx(GetTreeItem(GetSelectedItem()), GetSelectedItem());
	InvalidateRect(NULL, TRUE);
}

void CEffectListCtrl::OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	if (pNMLV->uOldState == 0 && pNMLV->uNewState == 0)
		return;	// No change

    *pResult = 0;

    if(m_bNotSelChange)
        return;

	CNtlResourceEffect* pResourceEffect = NULL;
	CNtlResourceComponentSystem* pResourceSystem = NULL;
	GetSelectResourceData(pResourceEffect, pResourceSystem);

	if (CVenusVisualManager::GetInstance().m_pResourceEffect != pResourceEffect ||
		CVenusVisualManager::GetInstance().m_pResourceSystem != pResourceSystem ||
		CVenusVisualManager::GetInstance().m_nSystemDataFlag != 0)
	{
		CEffectEditLayer* pView = (CEffectEditLayer*)gGetEditLayer(EDIT_LAYER_EFFECT_EDIT);
		CVenusVisualManager::GetInstance().SetSelectResourceData(pResourceEffect, pResourceSystem, 0);
		pView->ResetProperties();
	}
	int nItem = GetSelectedItem();
	if(nItem == -1) return;

	CTreeItem* pSelectItem = GetTreeItem(nItem);
	if(pSelectItem == NULL) return;

	CItemInfo* pItem = GetData(pSelectItem); 

	switch(pSelectItem->m_lpNodeInfo->GetImage())
	{
    case IMAGE_INDEX_RESOURCE_FOLDER:   // ����
        {
            if(ItemHasChildren(pSelectItem))
                return;

            BuildChildScript(pSelectItem);            
        }
        break;
	case IMAGE_INDEX_RESOURCE_EFFECT:   // ����Ʈ
		{
			CNtlResourceEffect* pResourceEffect = (CNtlResourceEffect*)pItem->m_lParam;
            if(pResourceEffect)
            {
                pResourceEffect->m_bShow = GetCheck(nItem);

                // ���� ���� �ڽ� �����۵��� ������ ���� ������ �������ش�.
                if(!ItemHasChildren(pSelectItem))
                {
                    for each(CNtlResourceComponentSystem* pResourceSystem in pResourceEffect->m_svResourceSystem)
                    {
                        RwInt32 nImageIndex = GetImageIndexFromSystemType(pResourceSystem->GetSystemType());
                        BuildTreeItem(pResourceSystem->GetSystemName(), nImageIndex, (DWORD_PTR)pResourceSystem, pSelectItem, 0);
                    }
                }                            
            }
            else
            {
                MessageBox("Effect Property is Not Found");                
            }
		}
		break;
    default:    // �׿ܴ� �ý���
        {
            CNtlResourceComponentSystem* pResourceSystem = (CNtlResourceComponentSystem*)pItem->m_lParam;
            pResourceSystem->m_bShow = GetCheck(nItem);
        }
        break;
	}	
}
void CEffectListCtrl::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	if (CVenusVisualManager::GetInstance().m_nSystemDataFlag != 0)
	{
		CNtlResourceEffect* pResourceEffect = NULL;
		CNtlResourceComponentSystem* pResourceSystem = NULL;
		GetSelectResourceData(pResourceEffect, pResourceSystem);

		CEffectEditLayer* pView = (CEffectEditLayer*)gGetEditLayer(EDIT_LAYER_EFFECT_EDIT);
		CVenusVisualManager::GetInstance().SetSelectResourceData(pResourceEffect, pResourceSystem, 0);
		pView->ResetProperties();
	}

    // �θ� Node üũ�� ���� Node�� üũ�ǰ� �����.        
    SetAllChildCheck();

	*pResult = 0;
}

void CEffectListCtrl::OnTestEffect()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CNtlResourceEffect* pResourceEffect = GetSelectResourceEffect();
	NTL_ASSERTE(pResourceEffect);

	// Popup menu �� ���� �ִ½ð��� �ֱ� ������ fElapsedTime Ÿ���� �����Ѵ�.
	// �׷��� ����Ʈ�� �ð����� Ŀ�� �̻��� ������� ������ ������ �� �ð��� ���ִ� ��������
	// timer �� �̿��Ѵ�.
	m_strInstanceEffectName = pResourceEffect->GetName();
	SetTimer(0, 100, NULL);
}

void CEffectListCtrl::OnTimer(UINT nIDEvent)
{
	KillTimer(0);

	switch(nIDEvent)
	{
	case 0:
		{
			CNtlPLEntity* pEffect = CVenusVisualManager::GetInstance().CreateEntity(PLENTITY_EFFECT, m_strInstanceEffectName.c_str());									
		}
		break;
	}
	CVenusGridCtrl::OnTimer(nIDEvent);
}


void CEffectListCtrl::OnEditCopy()
{
	CNtlResourceEffect* pResourceEffect = NULL;
	CNtlResourceComponentSystem* pResourceSystem = NULL;
	GetSelectResourceData(pResourceEffect, pResourceSystem);

    ETreeItemLevel eLevel = GetTreeItemLevel(GetTreeItem(GetSelectedItem()));
    
    if(eLevel == E_ITEM_LEVEL_FOLDER)
    {
        m_pCopyResourceFolder = GetTreeItem(GetSelectedItem());
        CVenusPropertyContainer::GetInstance().SetCopyResourceData(TRUE, NULL, NULL, CVenusPropertyContainer::E_COPY_FOLDER);
    }
    if(eLevel == E_ITEM_LEVEL_EFFECT)
    {
        CVenusPropertyContainer::GetInstance().SetCopyResourceData(TRUE, pResourceEffect, pResourceSystem, CVenusPropertyContainer::E_COPY_EFFECT);
    }
    else if(eLevel == E_ITEM_LEVEL_SYSTEM)
    {
        CVenusPropertyContainer::GetInstance().SetCopyResourceData(TRUE, pResourceEffect, pResourceSystem, CVenusPropertyContainer::E_COPY_SYSTEM);
    }
}

void CEffectListCtrl::OnEditCut()
{
	CNtlResourceEffect* pResourceEffect = NULL;
	CNtlResourceComponentSystem* pResourceSystem = NULL;
	GetSelectResourceData(pResourceEffect, pResourceSystem);

    ETreeItemLevel eLevel = GetTreeItemLevel(GetTreeItem(GetSelectedItem()));
    if(eLevel == E_ITEM_LEVEL_FOLDER)
    {
        m_pCopyResourceFolder = GetTreeItem(GetSelectedItem());
        CVenusPropertyContainer::GetInstance().SetCopyResourceData(FALSE, NULL, NULL, CVenusPropertyContainer::E_COPY_FOLDER);
    }
    else
    {
        CVenusPropertyContainer::GetInstance().SetCopyResourceData(FALSE, pResourceEffect, pResourceSystem, 0);
    }
}

void CEffectListCtrl::OnEditPaste()
{
	int selecteditem = GetSelectedItem();      
    CTreeItem* pParentItem = NULL;

    if(selecteditem != -1)    
       pParentItem = GetTreeItem(selecteditem);

    // ������ ī�� ó�� ����
    if(CVenusPropertyContainer::GetInstance().m_nCopySystemDataFlag == CVenusPropertyContainer::E_COPY_FOLDER)
    {
        if(GetTreeItemLevel(pParentItem) != E_ITEM_LEVEL_FOLDER)
            return;
        
        SItemNode* pItemNode = (SItemNode*)m_pCopyResourceFolder->m_lpNodeInfo->m_lParam;        
        InsertItemRecursive(pItemNode, pParentItem, TRUE);

        if(!CVenusPropertyContainer::GetInstance().m_bCopyResourceData) // Move
        {
            DeleteItemRecursive(pItemNode);
            DeleteItemEx(m_pCopyResourceFolder, m_pCopyResourceFolder->m_nIndex);
            InvalidateRect(NULL, TRUE);
        }
    }
    // ����Ʈ�� ī��
    else if(CVenusPropertyContainer::GetInstance().m_nCopySystemDataFlag == CVenusPropertyContainer::E_COPY_EFFECT)
    {
        if(GetTreeItemLevel(pParentItem) != E_ITEM_LEVEL_FOLDER)
            return;

        CString strName, strSrcName;
        RwInt32 count = 0;
        do
        {
            strName.Format("ResourceEffect%03d", count++);
        } while(CVenusPropertyContainer::GetInstance().GetProperty(PLENTITY_EFFECT, strName));

        CNtlResourceEffect* pResourceEffect = (CNtlResourceEffect*)CVenusPropertyContainer::GetInstance().CreateProperty(PLENTITY_EFFECT, strName, CVenusPropertyContainer::GetInstance().m_pCopyResourceEffect);
        NTL_ASSERTE(pResourceEffect != NULL);

        InsertTreeItem(strName, IMAGE_INDEX_RESOURCE_EFFECT, (DWORD_PTR)pResourceEffect, pParentItem);

        // ���� �ý��۵��� �ڵ����� ī�ǵȴ�.
        CEventLayer* pView = (CEventLayer*)gGetEditLayer(EDIT_LAYER_EVENT);
        pView->ResetProperties();
        
    }
    // ���� �ý����� ī��
    else if(CVenusPropertyContainer::GetInstance().m_nCopySystemDataFlag == CVenusPropertyContainer::E_COPY_SYSTEM)
    {
        if(selecteditem >= 0 && GetTreeItemLevel(GetTreeItem(selecteditem)) == E_ITEM_LEVEL_EFFECT)
        {
            NTL_ASSERTE(CVenusPropertyContainer::GetInstance().m_pCopyResourceSystem != NULL);
            NTL_ASSERTE(CVenusVisualManager::GetInstance().m_pResourceEffect != NULL);

            CreateResourceSystem(CVenusPropertyContainer::GetInstance().m_pCopyResourceSystem->GetSystemType(), CVenusPropertyContainer::GetInstance().m_pCopyResourceSystem);

            if (!CVenusPropertyContainer::GetInstance().m_bCopyResourceData)
            {
                // �� ������ DeleteResourceSystem ���� CVenusPropertyContainer::GetInstance().m_pCopyResourceEffect ��
                // �ʱ�ȭ�� �Ǳ� ������ ���⼭ �̸��� ������ �ִٰ� ResetInstanceEffect �Ҷ� ����Ѵ�.
                std::string strResourceEffectName = CVenusPropertyContainer::GetInstance().m_pCopyResourceEffect->GetName();
                CVenusPropertyContainer::GetInstance().DeleteResourceSystem(
                    CVenusPropertyContainer::GetInstance().m_pCopyResourceEffect,
                    CVenusPropertyContainer::GetInstance().m_pCopyResourceSystem);

                CVenusVisualManager::GetInstance().ResetInstanceEffect(strResourceEffectName.c_str());

                //RebuildResourceEffect();

                CVenusPropertyContainer::GetInstance().SetCopyResourceData(TRUE, NULL, NULL, 0);
            }
        }        
    }
}

void CEffectListCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch(nChar)
	{
	case VK_INSERT:
		{
			CNtlResourceEffect* pResourceEffect = GetRootResourceEffect();
			if (pResourceEffect != NULL)
			{
				m_strInstanceEffectName = pResourceEffect->GetName();
				SetTimer(0, 100, NULL);
			}
		}
		break;
	case VK_DELETE:
		{
			int nItem = GetSelectedItem();
			if(nItem != -1)
			{
				CTreeItem* pSelectItem = GetTreeItem(nItem);
				if(pSelectItem != NULL)
				{
                    switch(GetTreeItemLevel(pSelectItem))
                    {
                    case E_ITEM_LEVEL_FOLDER:
                        OnDeleteFolder();
                        break;
                    case E_ITEM_LEVEL_EFFECT:
                        OnDeleteEffect();
                        break;
                    case E_ITEM_LEVEL_SYSTEM:
                        OnDeleteSystem();
                        break;
                    }                    
				}
			}
		}
		break;
	case VK_CONTROL:
		{
		}
		break;
	case 'C':
		{
			if (nFlags & MK_CONTROL)
				OnEditCopy();
		}
		break;
	case 'T':
		{
			if (nFlags & MK_CONTROL)
				OnEditCut();
		}
		break;
	case 'V':
		{
			if (nFlags & MK_CONTROL)
			{
				if(GetSelectedItem() == -1)
				{
                    // ������ ���� ��Ʈ�� ī�� ����
                    if(CVenusPropertyContainer::GetInstance().m_nCopySystemDataFlag == CVenusPropertyContainer::E_COPY_FOLDER)					
					{
						OnEditPaste();
					}
				}
                else
				{
					CTreeItem* pSelectItem = GetTreeItem(GetSelectedItem());
					int level = pSelectItem->m_lpNodeInfo->GetImage();
                    if(level == IMAGE_INDEX_RESOURCE_FOLDER)
                    {
                        OnEditPaste();
                    }
					else if(level == IMAGE_INDEX_RESOURCE_EFFECT && CVenusPropertyContainer::GetInstance().m_pCopyResourceEffect)
					{
                        OnEditPaste();                        						
					}
                    else if(CVenusPropertyContainer::GetInstance().m_pCopyResourceSystem)
                    {
                        OnEditPaste();
                    }
				}
			}
		}
		break;
	}
	CVenusGridCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CEffectListCtrl::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch(nChar)
	{
		case VK_CONTROL:
		{
		}
		break;
	}

	CVenusGridCtrl::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CEffectListCtrl::OnLvnColumnclick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

    // �̸��� Ŭ���ϸ� ������ ���� ����Ʈ�鸸 ��Ʈ �ȴ�.
    CTreeItem* pParentItem = NULL;
    CTreeItem* pSelectItem = GetTreeItem(GetSelectedItem());
    if(GetTreeItemLevel(pSelectItem) == E_ITEM_LEVEL_FOLDER)
    {
        pParentItem = pSelectItem;
    }
    else
    {
        pParentItem = GetParentItem(pSelectItem);
    }

    if(!pParentItem || !ItemHasChildren(pParentItem))
        return;

    m_bNotSelChange = TRUE;
    POSITION pos = GetHeadPosition(pParentItem);
    while(pos)
    {
        CTreeItem* pChildItem = GetNextChild(pParentItem, pos);
        if(pChildItem)
        {
            DeleteItemEx(pChildItem, pChildItem->m_nIndex, FALSE);
        }            
    }

    SItemNode* pParentNode = (SItemNode*)pParentItem->m_lpNodeInfo->m_lParam;    
    pParentNode->SortChild();

    m_bNotSelChange = FALSE;

    UINT uflag = LVIS_SELECTED | LVIS_FOCUSED;
    SetItemState(pParentItem->m_nIndex, uflag, uflag);

    if(!ItemHasChildren(pParentItem))
    {
        BuildChildScript(pParentItem);
    }    
    
    //m_bSequence		= !m_bSequence;

    SetRedraw(1);
    InvalidateRect(NULL);
    UpdateWindow();

	*pResult = 0;
}

void CEffectListCtrl::SetAllChildCheck()
{
    int nIndex = GetSelectedItem();
    if(nIndex < 0)
        return;
    
    if(GetCount() <= (UINT)nIndex)
        return;
    
    BOOL bCheck = GetCheck(nIndex);

    CTreeItem* pSelectItem = GetTreeItem(nIndex);
    if(pSelectItem == NULL) return;

    if(pSelectItem->m_lpNodeInfo->GetImage() != IMAGE_INDEX_RESOURCE_EFFECT)
        return;

    // Ȯ��Ǿ� ���������� �ڽĵ��� üũ���� �ʴ´�.   
    if(IsCollapsed(pSelectItem))
    {
        return;
    }
    
    if(ItemHasChildren(pSelectItem))
    {
        POSITION pos = GetHeadPosition(pSelectItem);
        while(pos)
        {
            CTreeItem* pChildItem = GetNextChild(pSelectItem, pos);
            if(pChildItem)
            {   
                if(bCheck == FALSE)
                {
                    SetCheck(pChildItem->m_nIndex, FALSE);
                }
                else
                {
                    // Show�� ����Ȱ͸� Check ���ش�.
                    CItemInfo* pItemData = GetData(pChildItem);
                    CNtlResourceComponentSystem* pResourceComponent = (CNtlResourceComponentSystem*)pItemData->m_lParam;
                    SetCheck(pChildItem->m_nIndex, pResourceComponent->m_bShow);
                }
            }            
        }
    }
}


void CEffectListCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
    // �巡�� & ��ӽÿ� �������� ��ġ�� �����Ͽ� �ش�.    

    if(m_bIsDragging)
    {
        KillTimer(1);
        CImageList::DragLeave(this);
        CImageList::EndDrag();
        ReleaseCapture();
        m_bIsDragging = FALSE;
        SetItemState(m_nDragTarget, 0, LVIS_DROPHILITED);
        if((m_nDragTarget != -1) && (m_nDragTarget != m_nDragItem) && (m_nDragItem != -1))
        {
            CTreeItem* pSource = GetTreeItem(m_nDragItem);
            CTreeItem* pTarget = GetTreeItem(m_nDragTarget);
            CTreeItem* pSourceParent = pSource->m_pParent;
            
            if(GetTreeItemLevel(pTarget) == E_ITEM_LEVEL_FOLDER)
            {              
                if(GetTreeItemLevel(pSource) == E_ITEM_LEVEL_FOLDER)
                {
                    SItemNode* pItemNode = (SItemNode*)pSource->m_lpNodeInfo->m_lParam;
                    SItemNode* pTargetNode = (SItemNode*)pTarget->m_lpNodeInfo->m_lParam;

                    if(pItemNode->IsChildNode(pTargetNode))
                    {
                        AfxMessageBox("Not Allow Move [Parent Folder] -> [Child Folder]");
                        CListCtrl::OnLButtonUp(nFlags, point);
                        return;
                    }

                    if(pSourceParent)
                    {
                        SItemNode* pParentItemNode = (SItemNode*)pSourceParent->m_lpNodeInfo->m_lParam;
                        pParentItemNode->EraseChildNode(pItemNode);
                    }
                    else
                    {
                        m_sItemNode.EraseChildNode(pItemNode);
                    }

                    pTargetNode->vecChildList.push_back(pItemNode);
                    
                    DeleteItemEx(pSource, m_nDragItem);
                    
                    // NOTE: �ڽ��� �Ȱ����� �ִ� ��쿡�� ItemChange���� �˻��ؼ� �ڽ��� �߰��ϱ� ������
                    // ���⼭�� �߰����� �ʾƾ� �Ѵ�.
                    if(ItemHasChildren(pTarget))
                    {
                        InsertItemRecursive(pItemNode, pTarget, TRUE);                    
                    }
                    
                    InvalidateRect(NULL, TRUE);                    
                }
                else if(GetTreeItemLevel(pSource) == E_ITEM_LEVEL_EFFECT)
                {
                    CNtlResourceEffect* pSourceEffect = (CNtlResourceEffect*)pSource->m_lpNodeInfo->m_lParam;
                    CString strName = pSourceEffect->GetName();                    

                    SItemNode* pParentNode = (SItemNode*)pSourceParent->m_lpNodeInfo->m_lParam;       
                    SItemNode* pTargetNode = (SItemNode*)pTarget->m_lpNodeInfo->m_lParam;
                    SItemNode* pItemNode = pParentNode->EraseChildNode(strName);
                    pTargetNode->vecChildList.push_back(pItemNode);
                                       
                    if(ItemHasChildren(pTarget))
                    {
                        InsertTreeItem(strName, IMAGE_INDEX_RESOURCE_EFFECT, (DWORD_PTR)pSourceEffect, pTarget);                                        
                    }

                    DeleteItemEx(pSource, m_nDragItem);
                    
                    InvalidateRect(NULL, TRUE);
                }
            }
        }
    }
    else
    {
        CListCtrl::OnLButtonUp(nFlags, point);
    }    
}

RwBool CEffectListCtrl::LoadXMLTree() 
{
    if(CVenusConfig::GetInstance().m_strFileName.GetLength() == 0)
        return FALSE;
    
    USES_CONVERSION;
    CNtlTreeXml xmlLoad;  
    CString strXmlFilePath = PATH_TREE_XML;    
    strXmlFilePath += CVenusConfig::GetInstance().m_strFileName;
    strXmlFilePath.Replace(".eff", ".xml");    
    
    if(!xmlLoad.LoadTreeXML(A2W(strXmlFilePath), &m_sItemNode))
    {
        char szMsg[MAX_PATH] = {0,};
        sprintf(szMsg, "[%s] Is Load Error!", strXmlFilePath);
        AfxMessageBox(szMsg);
        return FALSE;
    }
    
    DeleteAllItems();
    DeleteAll();
    InsertItemRecursive(&m_sItemNode, NULL, FALSE);

    return TRUE;
}

void CEffectListCtrl::InsertItemRecursive(SItemNode* pItemNode, CSuperGridCtrl::CTreeItem* pParentItem, RwBool bUpdate)
{
    if(pItemNode->eNodeType == NODE_SCIRPT)
    {
        // ��ũ��Ʈ��� �ڽ��� �߰��ϰ� ������.        
        //InsertTreeItem(pItemNode->strNodeName, IMAGE_INDEX_RESOURCE_EFFECT, NULL, pParentItem);
    }
    else	// ������� �ڽĵ��� ��ͷ� ����.
    {
        CSuperGridCtrl::CTreeItem* pItem = NULL;
        if(pItemNode != &m_sItemNode)   // ���� ��Ʈ ������ �����Ѵ�.
        {
            pItem = BuildTreeItem(pItemNode->strNodeName, IMAGE_INDEX_RESOURCE_FOLDER, (DWORD_PTR)pItemNode, pParentItem, bUpdate);
        }        

        //for each(SItemNode* pChildNode in pItemNode->vecChildList)
        //{
        //    if(pChildNode)
        //    {
        //        InsertItemRecursive(pChildNode, pItem, bUpdate);
        //    }
        //}

        for each(SItemNode* pChildNode in pItemNode->vecChildList)
        {
            if(pChildNode->eNodeType == NODE_FOLDER)
            {
                BuildTreeItem(pChildNode->strNodeName, IMAGE_INDEX_RESOURCE_FOLDER, (DWORD_PTR)pChildNode, pItem, bUpdate);
            }            
        }
    }
}


ETreeItemLevel CEffectListCtrl::GetTreeItemLevel(CTreeItem* pItem)
{
    if(pItem == NULL)
        return E_ITEM_LEVEL_INVALID;

    ETreeItemLevel level;
    int nImage = pItem->m_lpNodeInfo->GetImage();
    if(nImage == IMAGE_INDEX_RESOURCE_EFFECT)
    {
        level = E_ITEM_LEVEL_EFFECT;
    }
    else if(nImage == IMAGE_INDEX_RESOURCE_FOLDER)
    {
        level = E_ITEM_LEVEL_FOLDER;
    }
    else if(nImage < IMAGE_INDEX_RESOURCE_MAX_COUNT)
    {
        level = E_ITEM_LEVEL_SYSTEM;
    }
    else 
    {
        level = E_ITEM_LEVEL_INVALID;
    }

    return level;    
}

// ���ο� ������ �����Ѵ�.
void CEffectListCtrl::OnCreateFolder()
{
    std::string strNewFolderName;
    static CInputBox cInputBox(AfxGetInstanceHandle());
    char szNewName[21] = {0,};
    if(!cInputBox.ShowInputBox(NULL, "New Folder", "Input Create Folder Name", szNewName, 20))
    {
        return;
    }

    if(strlen(szNewName) == 0)
        return;

    strNewFolderName = szNewName;

    int nSelectItem = GetSelectedItem();        
    if(nSelectItem != -1)
    {
        CTreeItem* pParentItem = GetTreeItem(nSelectItem);
        if(!pParentItem || GetTreeItemLevel(pParentItem) != E_ITEM_LEVEL_FOLDER)
            return;        

        SItemNode* pParentItemNode = (SItemNode*)pParentItem->m_lpNodeInfo->m_lParam;
        SItemNode* pNewItemNode = NTL_NEW SItemNode();
        pParentItemNode->vecChildList.push_back(pNewItemNode);
        pNewItemNode->strNodeName = szNewName;
        pNewItemNode->eNodeType = NODE_FOLDER;
        InsertTreeItem(pNewItemNode->strNodeName, IMAGE_INDEX_RESOURCE_FOLDER, (DWORD_PTR)pNewItemNode, pParentItem);
    }
    else
    {
        SItemNode* pNewItemNode = NTL_NEW SItemNode();
        m_sItemNode.vecChildList.push_back(pNewItemNode);        
        pNewItemNode->strNodeName = szNewName;
        pNewItemNode->eNodeType = NODE_FOLDER;
        BuildTreeItem(pNewItemNode->strNodeName, IMAGE_INDEX_RESOURCE_FOLDER, (DWORD_PTR)pNewItemNode, NULL);
    }
}

// ������ �����Ѵ�.
void CEffectListCtrl::OnDeleteFolder()
{
    if (AfxMessageBox("really Delete Folder?", MB_OKCANCEL) != IDOK) 
        return;

    CTreeItem* pSelectItem = GetTreeItem(GetSelectedItem());
    SItemNode* pItemNode = (SItemNode*)pSelectItem->m_lpNodeInfo->m_lParam;
    
    DeleteItemRecursive(pItemNode);

    DeleteItemEx(GetTreeItem(GetSelectedItem()), GetSelectedItem());

    InvalidateRect(NULL, TRUE);
}

void CEffectListCtrl::DeleteItemRecursive( SItemNode* pItemNode ) 
{
    if(pItemNode->eNodeType == NODE_FOLDER)
    {
        pItemNode->eNodeType = NODE_NONE;
        for each(SItemNode* pChildNode in pItemNode->vecChildList)
        {
            DeleteItemRecursive(pChildNode);
        }

        pItemNode->vecChildList.clear();
    }
    else if(pItemNode->eNodeType == NODE_SCIRPT)
    {
        CVenusVisualManager::GetInstance().DeleteInstanceEffect(pItemNode->strNodeName);
        CVenusPropertyContainer::GetInstance().DeleteProperty(PLENTITY_EFFECT, pItemNode->strNodeName);
    }
}

// ������ �̸��� �����Ѵ�.
void CEffectListCtrl::OnRenameFolder()
{
    CTreeItem* pSelectItem = GetTreeItem(GetSelectedItem());
    if(!pSelectItem)
        return;

    static CInputBox cInputBox(AfxGetInstanceHandle());
    char szNewName[21] = {0,};
    if(cInputBox.ShowInputBox(NULL, "Rename Folder", "Input New Folder Name", szNewName, 20))
    {
        if(strlen(szNewName) > 0)
        {
            SItemNode* pItemNode = (SItemNode*)pSelectItem->m_lpNodeInfo->m_lParam;            
            pItemNode->strNodeName = szNewName;
            ResetTreeItemName(szNewName);            
        }        
    }
}

void CEffectListCtrl::OnLvnBegindrag(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);    
    m_bDrag = TRUE;
    *pResult = 0;
}

void CEffectListCtrl::OnNMReleasedcapture(NMHDR *pNMHDR, LRESULT *pResult)
{
    if(m_bDrag)
    {
        int a = 0;
        m_bDrag = FALSE;
    }

    *pResult = 0;
}

RwBool CEffectListCtrl::SaveXMLTree( RwChar* szFileName ) 
{
    if(!szFileName)
        return FALSE;

    USES_CONVERSION;
    
    CString strRootName = "Effect Script";
    CNtlTreeXml xmlSave;  
    xmlSave.CreateXML(A2W(strRootName));

    int nIndex = GetNextItem(-1, LVNI_ALL);
    if(nIndex != -1)
    {
        POSITION pos = GetRootHeadPosition();
        while(pos != NULL)
        {
            CTreeItem* pParentItem = (CTreeItem*)GetNextRoot(pos);
            CTreeItem* pItem = pParentItem;            

            if(!ItemHasChildren(pParentItem))
            {
                BuildChildScript(pParentItem);
            }

            xmlSave.AddFolderNode(NULL, A2W(pItem->m_lpNodeInfo->GetItemText()));

            for(;;)
            {
                CTreeItem* pCur = GetNext(pParentItem, pItem, TRUE, FALSE);

                if(!IsChildOf(pParentItem, pCur))
                    break;
                if(pCur == pItem)
                    break;
                if(GetTreeItemLevel(pCur) == E_ITEM_LEVEL_SYSTEM)   // �ý����� ������Ѵ�. 
                {
                    pItem = pCur;
                    continue;
                }
                
                CString strParentName, strCurName;
                if(pParentItem)
                {
                    strParentName = pParentItem->m_lpNodeInfo->GetItemText();
                }
                else
                {
                    strParentName = strRootName;
                }
                strCurName = pCur->m_lpNodeInfo->GetItemText();

                switch(GetTreeItemLevel(pCur))
                {
                case E_ITEM_LEVEL_FOLDER:     
                    {
                        SItemNode* pItemNode = (SItemNode*)pCur->m_lpNodeInfo->m_lParam;
                        if(pItemNode->eNodeType == NODE_NONE)
                        {

                        }
                        else
                        {
                            xmlSave.AddFolderNode(A2W(strParentName), A2W(strCurName));
                        }                        
                    }
                    break;
                case E_ITEM_LEVEL_EFFECT:
                    xmlSave.AddScriptNode(A2W(strParentName), A2W(strCurName));
                    break;
                }

                pItem = pCur;
            }
        }
    }

    return xmlSave.Save(A2W(szFileName));
}

void CEffectListCtrl::BuildChildScript( CTreeItem* pParentItem ) 
{
    SItemNode* pItemNode = (SItemNode*)pParentItem->m_lpNodeInfo->m_lParam;
    if(pItemNode)
    {
        for each(SItemNode* pChildNode in pItemNode->vecChildList)
        {
            if(pChildNode->eNodeType == NODE_SCIRPT)    // ���� ��ũ��Ʈ(����Ʈ)���� �߰��Ѵ�.
            {
                CNtlResourceEffect* pResourceEffect = CVenusPropertyContainer::GetInstance().FindProperty(pChildNode->strNodeName);
                // �ߺ��� �̸��� ����Ʈ�� �̹� �����ϸ� ���� �߰����� �ʴ´�.
                if(pResourceEffect)
                {
                    BuildTreeItem(pChildNode->strNodeName, IMAGE_INDEX_RESOURCE_EFFECT, (DWORD_PTR)pResourceEffect, pParentItem);
                }                        
            }
            else if(pChildNode->eNodeType == NODE_FOLDER)
            {
                BuildTreeItem(pChildNode->strNodeName, IMAGE_INDEX_RESOURCE_FOLDER, (DWORD_PTR)pChildNode, pParentItem);
            }
        }                
    }
}

void CEffectListCtrl::CreateDefaultXMLTree() 
{
    //m_sItemNode.vecChildList.clear();
    CTreeItem* pRootItem = NULL;
    SItemNode* pRootNode = NULL;

    // ��Ʈ ��� ����
    CString strRootNodeName = "NewTree";
    pRootItem = Search(strRootNodeName, NULL);
    if(!pRootItem || GetTreeItemLevel(pRootItem) != E_ITEM_LEVEL_FOLDER)      // ���� �̸��� ������ �������� ����. 
    {
        pRootNode = NTL_NEW SItemNode();
        pRootNode->eNodeType = NODE_FOLDER;
        pRootNode->strNodeName = strRootNodeName;
        m_sItemNode.vecChildList.push_back(pRootNode);
        pRootItem = BuildTreeItem(strRootNodeName, IMAGE_INDEX_RESOURCE_FOLDER, (DWORD_PTR)pRootNode, NULL);
    }    
    else // ���� �̸��� ������ ������ (Merge)
    {
        pRootNode = (SItemNode*)pRootItem->m_lpNodeInfo->m_lParam;
    }

    // ����Ʈ�� ��� ����
    for each(CNtlResourceEffect* pResourceEffect in CVenusPropertyContainer::GetInstance().m_svEffectProperty)
    {
        // �̹� ������ ��尡 �ִ� ���� ���� �߰����� �ʴ´�.        
        if(CNtlTreeXml::m_mapNode.find(pResourceEffect->GetName()) != CNtlTreeXml::m_mapNode.end())
            continue;

        SItemNode* pItemNode = NTL_NEW SItemNode();
        pItemNode->eNodeType = NODE_SCIRPT;
        pItemNode->strNodeName = pResourceEffect->GetName();
        pRootNode->vecChildList.push_back(pItemNode);

        BuildTreeItem(pResourceEffect->GetName(), IMAGE_INDEX_RESOURCE_EFFECT, (DWORD_PTR)pResourceEffect, pRootItem);

        CNtlTreeXml::m_mapNode[pResourceEffect->GetName()] = pItemNode;
    }
}

void CEffectListCtrl::ResetTreeItemName( const RwChar* strName ) 
{
    // ����Ʈ �������� SData�� �Ȱ����� �ִ�.
    CTreeItem* pSelectItem = GetTreeItem(GetSelectedItem());    
    if(GetTreeItemLevel(pSelectItem) != E_ITEM_LEVEL_SYSTEM)    // System�� Node�� ���Ե��� �ʱ⶧���� �߰� �۾��� ����.
    {
        CTreeItem* pParentItem = pSelectItem->m_pParent;

        SItemNode* pChildNode = NULL;
        if(pParentItem)
        {
            SItemNode* pParentNode = (SItemNode*)pParentItem->m_lpNodeInfo->m_lParam;            
            for each(SItemNode* pNode in pParentNode->vecChildList)
            {
                if(pNode->strNodeName == pSelectItem->m_lpNodeInfo->GetItemText())
                {
                    pChildNode = pNode;
                    break;
                }
            }        
        }
        else
        {
            pChildNode = m_sItemNode.GetChildNode(pSelectItem->m_lpNodeInfo->GetItemText());
        }

        if(pChildNode)
        {
            pChildNode->strNodeName = strName;
        }
    }

    CVenusGridCtrl::ResetTreeItemName(strName);
}

void CEffectListCtrl::DeleteItemEx( CTreeItem *pSelItem, int nItem, BOOL bUpdate /*= TRUE*/ ) 
{
    if(CNtlTreeXml::m_mapNode.find(pSelItem->m_lpNodeInfo->GetItemText()) != CNtlTreeXml::m_mapNode.end())
    {
        CNtlTreeXml::m_mapNode.erase(CNtlTreeXml::m_mapNode.find(pSelItem->m_lpNodeInfo->GetItemText()));
    }
    
    __super::DeleteItemEx(pSelItem, nItem, bUpdate);
}