// InfomationPane.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "2DParticleEditor.h"
#include "InfomationPane.h"

CInfomationPane* CInfomationPane::m_pInstance = NULL;

// CInfomationPane

IMPLEMENT_DYNCREATE(CInfomationPane, CFormView)

CInfomationPane::CInfomationPane()
	: CFormView(CInfomationPane::IDD)
	, m_szClientMouseX(_T(""))
	, m_szClientMouseY(_T(""))
	, m_szParticleMouseX(_T(""))
	, m_szParticleMouseY(_T(""))
	, m_szResolutionWidth(_T(""))
	, m_szResoultionHeight(_T(""))
{
	m_pInstance = this;
}

CInfomationPane::~CInfomationPane()
{
}

void CInfomationPane::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CLIENT_MOUSE_X, m_szClientMouseX);
	DDX_Text(pDX, IDC_CLIENT_MOUSE_Y, m_szClientMouseY);
	DDX_Text(pDX, IDC_PARTICLE_MOUSE_X, m_szParticleMouseX);
	DDX_Text(pDX, IDC_PARTICLE_MOUSE_Y, m_szParticleMouseY);
	DDX_Text(pDX, IDC_RESOLUTION_WIDTH, m_szResolutionWidth);
	DDX_Text(pDX, IDC_RESOLUTION_HEIGHT, m_szResoultionHeight);
}

BEGIN_MESSAGE_MAP(CInfomationPane, CFormView)
END_MESSAGE_MAP()


// CInfomationPane �����Դϴ�.

#ifdef _DEBUG
void CInfomationPane::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInfomationPane::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

#endif
#endif //_DEBUG

void CInfomationPane::SetClientMouse( int nX, int nY )
{
	m_szClientMouseX.Format( _T("%d"), nX );
	m_szClientMouseY.Format( _T("%d"), nY );
	UpdateData( FALSE );
}

void CInfomationPane::SetParticleMouse( int nX, int nY )
{
	m_szParticleMouseX.Format( _T("%d"), nX );
	m_szParticleMouseY.Format( _T("%d"), nY );
	UpdateData( FALSE );
}

void CInfomationPane::SetResolution( int nWidth, int nHeight )
{
	m_szResolutionWidth.Format( _T("%d"), nWidth );
	m_szResoultionHeight.Format( _T("%d"), nHeight );
	UpdateData( FALSE );
}



// CInfomationPane �޽��� ó�����Դϴ�.

void CInfomationPane::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}