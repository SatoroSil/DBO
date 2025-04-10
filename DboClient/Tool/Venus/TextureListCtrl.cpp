// TextureListCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "VenusFrame.h"

#include "TextureListCtrl.h"
#include ".\texturelistctrl.h"

#include "NtlDebug.h"

#include ".\venusconfig.h"

#include "NtlResourceEffect.h"
#include "NtlEffectSystemFreeList.h"

#include "TextureLayer.h"
#include "EffectEditLayer.h"

#include "VenusAPI.h"

// CTextureListCtrl

IMPLEMENT_DYNAMIC(CTextureListCtrl, CListCtrl)
CTextureListCtrl::CTextureListCtrl()
{
}

CTextureListCtrl::~CTextureListCtrl()
{
}


BEGIN_MESSAGE_MAP(CTextureListCtrl, CListCtrl)
//	ON_WM_CONTEXTMENU()
//	ON_COMMAND(POPUP_INSERT_TEXTURE, OnInsertTexture)
//	ON_COMMAND(POPUP_DELETE_TEXTURE, OnDeleteTexture)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, OnLvnItemchanged)
END_MESSAGE_MAP()



// CTextureListCtrl �޽��� ó�����Դϴ�.
//void CTextureListCtrl::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//	POSITION pos = GetFirstSelectedItemPosition();
//
//	CMenu menu;
//	menu.CreatePopupMenu();
//
//	if(pos == NULL)
//	{
//		menu.AppendMenu(MF_STRING, POPUP_INSERT_TEXTURE, "&Insert Texture");
//		menu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
//		return;
//	}
//
//	menu.AppendMenu(MF_STRING, POPUP_INSERT_TEXTURE, "&Insert Texture");
////	menu.AppendMenu(MF_STRING, POPUP_DELETE_TEXTURE, "&Delete Texture");
//	menu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
//}

//void CTextureListCtrl::OnInsertTexture()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//	CFileDialog dlg(TRUE, NULL, "Venus", OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_ALLOWMULTISELECT, "Texture File|*.*");
//	dlg.m_ofn.nMaxFile = 10000;
//	dlg.m_ofn.lpstrFile = NTL_NEW TCHAR[10000];
//	memset(dlg.m_ofn.lpstrFile, 0, sizeof(TCHAR) * 10000);
//
//	CString strWorkingFolder;
//	strWorkingFolder.Format("%s\\Textures\\Effect\\", CVenusConfig::GetInstance().m_strMainPath.c_str());
//	dlg.m_ofn.lpstrInitialDir = strWorkingFolder;
//	if (dlg.DoModal() == IDOK)
//	{
//		RwChar strCurrentPath[MAX_PATH];
//		GetCurrentDirectory(MAX_PATH, strCurrentPath);
//
//		CVenusConfig::GetInstance().SetMainDirectory();
//
//        POSITION pos = dlg.GetStartPosition();
//        while(pos)
//        {
//            CString strPathName = dlg.GetNextPathName(pos);
//            CString strFileName  = strPathName.Right(strPathName.GetLength() - (strlen(strCurrentPath) + 1));
//
//			RwChar strDirectory[MAX_PATH];
//			NTL_ASSERTE(strPathName.GetLength() < MAX_PATH);
//
//			strcpy(strDirectory, strPathName);
//
//			strDirectory[strPathName.GetLength() - strFileName.GetLength()] = '\0';
//
//			RwTexture* pTexture = CVenusEffectManager::GetTextureInstance().CreateTexture(strDirectory, strFileName.GetBuffer(0));
////			InsertTexture(pTexture, strPathName);
//		}
//		BuildTextureList();
//
//		CEffectEditLayer* pView = (CEffectEditLayer*)gGetEditLayer(EDIT_LAYER_EFFECT_EDIT);
//		pView->ResetPropertiesOnly();
//	}
//    NTL_ARRAY_DELETE(dlg.m_ofn.lpstrFile);
//}

//void CTextureListCtrl::OnDeleteTexture()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//	RwUInt32 result = AfxMessageBox("���� �ؽ��� ��� ���ο� ���� ���� üũ�� ���� �ʴ´� \n�ٸ������� ����ϴ� �ؽ��ĸ� ������� �ϸ� ���� �����̴�\n�׷��� ������ΰ� ?", MB_OKCANCEL);
//	if (result != IDOK) return;
//
//	POSITION pos = GetFirstSelectedItemPosition();
//	if (pos == NULL) return;
//
//	RwInt32 nItem = GetNextSelectedItem(pos);
//
//	RwTexture* pTexture = reinterpret_cast<RwTexture*>(GetItemData(nItem));
//	pTexture = CVenusEffectManager::GetTextureInstance().RemoveTexture(pTexture);
//	RwTextureDestroy(pTexture);
//
//	BuildTextureList();
//
//	CEffectEditLayer* pView = (CEffectEditLayer*)gGetEditLayer(EDIT_LAYER_EFFECT_EDIT);
//	pView->ResetPropertiesOnly();
//}


void CTextureListCtrl::OnInitControl()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_ImageList.Create(THUMBNAIL_WIDTH, THUMBNAIL_HEIGHT, ILC_COLOR24, 0, 1);
	SetImageList(&m_ImageList, LVSIL_NORMAL);
	SetIconSpacing(80, 90);
}

void CTextureListCtrl::BuildTextureList()
{
	// reset our image list
	for(RwInt32 i = 0; i < m_ImageList.GetImageCount(); ++i)
	{
		m_ImageList.Remove(i);
	}
	DeleteAllItems();

	m_ImageList.SetImageCount(CNtlEffectSystemFreeList::m_TextureFileManager.size());
	SetRedraw(FALSE);

	CNtlResourceFileManager::smdef_Entity::iterator it;
	for (it = CNtlEffectSystemFreeList::m_TextureFileManager.m_smEntity.begin(); it != CNtlEffectSystemFreeList::m_TextureFileManager.m_smEntity.end(); ++ it)
	{
		std::string strFileName = (*it).first.c_str();
		std::string strPathName = (*it).second.c_str();
		InsertTexture(strFileName.c_str(), strPathName.c_str());
	}

	SetRedraw(TRUE);
	Invalidate();
}
void CTextureListCtrl::InsertTexture(const RwChar* strFileName, const RwChar* strPathName)
{
	RwInt32 nIndex = InsertItem(GetItemCount(), strFileName, GetItemCount());
	InsertTextureImage(nIndex, strPathName);
}

RwBool CTextureListCtrl::InsertTextureImage(RwInt32 index, const RwChar* strPathName)
{
	GFL_LOAD_PARAMS load_params;

	gflGetDefaultPreviewParams(&load_params);
	load_params.Flags |= GFL_LOAD_SKIP_ALPHA;
	load_params.Origin = GFL_BOTTOM_LEFT; 
	load_params.ColorModel = GFL_BGR; 
	load_params.LinePadding = 4;

	GFL_BITMAP *gflBitmap = NULL;
	GFL_ERROR errorcode = gflLoadBitmap(strPathName, &gflBitmap, &load_params, NULL);

	if( GFL_NO_ERROR != errorcode ) return FALSE;

	// image bilinear scale
	CSize szPic(gflBitmap->Width, gflBitmap->Height);
	int x = 0, y = 0, cx = THUMBNAIL_WIDTH, cy = THUMBNAIL_HEIGHT;
	double ratio = (double)szPic.cx/(double)szPic.cy;
	CRect rcDest;

	if (szPic.cx >= THUMBNAIL_WIDTH || szPic.cy >= THUMBNAIL_HEIGHT)
	{
		if (ratio > 1)
		{
			cy = (int)((double)cy/ratio);
			y  = (THUMBNAIL_HEIGHT-cy)/2;
		}
		else if (ratio < 1)
		{
			cx = (int)((double)cx*ratio);
			x  = (THUMBNAIL_WIDTH-cx)/2;
		}
		
		rcDest = CRect(x, y, x+cx, y+cy);
	}
	else
	{
		x = (THUMBNAIL_WIDTH-szPic.cx)/2;
		y = (THUMBNAIL_HEIGHT-szPic.cy)/2;
		rcDest = CRect(x, y, x+szPic.cx, y+szPic.cy);
	}
	gflResize(gflBitmap, NULL, rcDest.Width(), rcDest.Height(), GFL_RESIZE_BILINEAR, 0);

	CClientDC dc(this);
	CBitmap bitmap, *pOldBitmap;
	bitmap.CreateCompatibleBitmap(&dc, THUMBNAIL_WIDTH, THUMBNAIL_HEIGHT);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	pOldBitmap = memDC.SelectObject(&bitmap);

	unsigned char *dib_data = NULL;
	BITMAPINFOHEADER dib_info;

	GetDIBFromBitmap(gflBitmap, &dib_info, &dib_data);

	memDC.FillSolidRect(0, 0, THUMBNAIL_WIDTH, THUMBNAIL_HEIGHT, RGB(255,255,255));
	StretchDIBits(
		memDC.m_hDC,
		x,
		y,
		gflBitmap->Width,
		gflBitmap->Height,
		0,
		0,
		gflBitmap->Width,
		gflBitmap->Height,
		dib_data ? dib_data : gflBitmap->Data,
		(BITMAPINFO *)&dib_info,
		DIB_RGB_COLORS,
		SRCCOPY);

	memDC.SelectObject(pOldBitmap);

	m_ImageList.Replace(index, &bitmap, NULL);

	bitmap.DeleteObject();
	if (dib_data)  { free(dib_data); dib_data = NULL; }
	if (gflBitmap) { gflFreeBitmap(gflBitmap); gflBitmap = NULL; }

	return TRUE;
}


void CTextureListCtrl::OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	POSITION pos = GetFirstSelectedItemPosition();
	if (pos == NULL) return;

	RwInt32 nItem = GetNextSelectedItem(pos);

	CString strFileName = GetItemText(nItem, 0);

	NTL_ASSERTE(CNtlEffectSystemFreeList::m_TextureFileManager.IsFile(strFileName.GetBuffer(0)));
	std::string strPathName = CNtlEffectSystemFreeList::m_TextureFileManager.GetPathName(strFileName.GetBuffer(0));

	CTextureLayer* pLayer = (CTextureLayer*)gGetEditLayer(EDIT_LAYER_TEXTURE);
	pLayer->CreateBitmap(strPathName.c_str());
	*pResult = 0;
}
