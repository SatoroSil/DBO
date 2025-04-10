// TextureLayer.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "VenusFrame.h"
#include "TextureLayer.h"

#include "TextureListDialog.h"
#include "TextureInfoDialog.h"
#include ".\texturelayer.h"


// CTextureLayer

IMPLEMENT_DYNCREATE(CTextureLayer, CView)

CTextureLayer::CTextureLayer()
{
	m_bInitialized = FALSE;
}

CTextureLayer::~CTextureLayer()
{
}

BEGIN_MESSAGE_MAP(CTextureLayer, CView)
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()


// CTextureLayer �׸����Դϴ�.

void CTextureLayer::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CTextureLayer �����Դϴ�.

#ifdef _DEBUG
void CTextureLayer::AssertValid() const
{
	CView::AssertValid();
}

void CTextureLayer::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG


// CTextureLayer �޽��� ó�����Դϴ�.

void CTextureLayer::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_RollupControl.Create( WS_VISIBLE|WS_CHILD, CRect(0,1,190,400), this, IDD_ROLLUPPAGEID);

	m_RollupControl.InsertPage("Texture List",			IDD_TEXTURE_LIST,		RUNTIME_CLASS(CTextureListDialog));	
	m_RollupControl.InsertPage("Texture Information",	IDD_TEXTURE_INFO,		RUNTIME_CLASS(CTextureInfoDialog));

	m_RollupControl.ExpandAllPages();

	m_bInitialized = TRUE;			
}

void CTextureLayer::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if(m_bInitialized)
	{
		m_RollupControl.MoveWindow(0, 0, cx, cy);
	}
}

void CTextureLayer::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	gSetEditLayer(EDIT_LAYER_TEXTURE);
}

void CTextureLayer::CreateBitmap(const RwChar* strPathName)
{
	RC_PAGEINFO* pginfo = m_RollupControl.GetPageInfo(EDIT_DIALOG_TEXTURE_INFO);
	if(pginfo && pginfo->pwndTemplate)
	{
		CTextureInfoDialog* pDialog = (CTextureInfoDialog*)pginfo->pwndTemplate;					
		pDialog->CreateBitmap(strPathName);
	}
}


void CTextureLayer::BuildTextureList()
{
	RC_PAGEINFO* pginfo = m_RollupControl.GetPageInfo(EDIT_DIALOG_TEXTURE_LIST);
	if(pginfo && pginfo->pwndTemplate)
	{
		CTextureListDialog* pDialog = (CTextureListDialog*)pginfo->pwndTemplate;					
		pDialog->SerializeList();
	}
}
