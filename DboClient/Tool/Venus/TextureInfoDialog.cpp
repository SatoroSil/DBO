// TextureInfoDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "TextureInfoDialog.h"

#include "VenusAPI.h"
#include ".\textureinfodialog.h"

// CTextureInfoDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CTextureInfoDialog, CDialog)
CTextureInfoDialog::CTextureInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTextureInfoDialog::IDD, pParent)
	, m_nTextureWidth(0)
	, m_nTextureHeight(0)
{
	m_Initialized	= FALSE;
	m_pGflBitmap	= NULL;
}

CTextureInfoDialog::~CTextureInfoDialog()
{
	if(m_pGflBitmap)
	{
		gflFreeBitmap(m_pGflBitmap);
		m_pGflBitmap = NULL; 
	}
}

void CTextureInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXTURE, m_TextureScreen);
	DDX_Text(pDX, IDC_TEXTURE_WIDTH, m_nTextureWidth);
	DDX_Text(pDX, IDC_TEXTURE_HEIGHT, m_nTextureHeight);
}


BEGIN_MESSAGE_MAP(CTextureInfoDialog, CDialog)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTextureInfoDialog �޽��� ó�����Դϴ�.

BOOL CTextureInfoDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_Initialized = TRUE;

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CTextureInfoDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_Initialized)
	{
	}
}

BOOL CTextureInfoDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN) 
	{
		if(pMsg->wParam == VK_RETURN) return FALSE;	
		if(pMsg->wParam == VK_ESCAPE) return FALSE;	
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CTextureInfoDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CDialog::OnPaint()��(��) ȣ������ ���ʽÿ�.
	if(!m_pGflBitmap) return;

	CRect rect;
	m_TextureScreen.GetWindowRect(rect);
	ScreenToClient( &rect );

/*	int minsize = ( rect.Width() < rect.Height() ) ? rect.Width() : rect.Height();
	minsize -= 4;
	minsize = (minsize>>1);

	int centerx = rect.left + (rect.Width()>>1);
	int centery = rect.top  + (rect.Height()>>1);

	rect.left   = centerx-minsize;
	rect.right  = centerx+minsize-1;
	rect.top    = centery-minsize;
	rect.bottom = centery+minsize-1;
*/
	HBRUSH hBrush=::CreateSolidBrush(RGB(255, 255, 255));
	::FillRect( dc.GetSafeHdc(), rect, hBrush);
	DeleteObject(hBrush);

	unsigned char *dib_data;
	BITMAPINFOHEADER dib_info;
	GetDIBFromBitmap( m_pGflBitmap, &dib_info, &dib_data );
	StretchDIBits( dc.GetSafeHdc(), rect.left, rect.top, rect.Width(), rect.Height(),
//	StretchDIBits( dc.GetSafeHdc(), rect.left, rect.top, (minsize<<1), (minsize<<1),
		0, 0, m_pGflBitmap->Width, m_pGflBitmap->Height, 
		dib_data ? dib_data : m_pGflBitmap->Data, (BITMAPINFO *)&dib_info, DIB_RGB_COLORS, SRCCOPY );				
	if ( dib_data ) free( dib_data ); 
}


void CTextureInfoDialog::CreateBitmap(const RwChar* strPathName)
{
	if(m_pGflBitmap)
	{
		gflFreeBitmap(m_pGflBitmap);
		m_pGflBitmap = NULL; 
	}

	if (strPathName == NULL)
	{
		Invalidate(TRUE);
		return;
	}

	GFL_LOAD_PARAMS load_params;	
	gflGetDefaultPreviewParams(&load_params);
	load_params.Flags |= GFL_LOAD_SKIP_ALPHA;
	load_params.Origin = GFL_BOTTOM_LEFT; 
	load_params.ColorModel = GFL_BGR; 
	load_params.LinePadding = 4;

	GFL_ERROR errorcode = gflLoadBitmap(strPathName, &m_pGflBitmap, &load_params, NULL);
	if( m_pGflBitmap )
	{
		m_nTextureWidth	= m_pGflBitmap->Width;
		m_nTextureHeight = m_pGflBitmap->Height;

		CRect rect;
		m_TextureScreen.GetWindowRect(rect);
		ScreenToClient( &rect );

//		int minsize = ( rect.Width() < rect.Height() ) ? rect.Width() : rect.Height();
//		minsize -= 4;						
//		gflResize(m_pGflBitmap, NULL, minsize, minsize, GFL_RESIZE_BILINEAR, 0);
		gflResize(m_pGflBitmap, NULL, rect.Width(), rect.Height(), GFL_RESIZE_BILINEAR, 0);

		RedrawWindow( &rect, NULL, RDW_INVALIDATE | RDW_UPDATENOW );

		UpdateData( FALSE );
	}
}

