// SystemPane.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "2DParticleEditor.h"
#include "SystemPane.h"

#include "BackManager.h"

CSystemPane* CSystemPane::m_pInstance	= NULL;

// CSystemPane

IMPLEMENT_DYNCREATE(CSystemPane, CFormView)

CSystemPane::CSystemPane()
	: CFormView(CSystemPane::IDD)
	, m_szBackName(_T(""))
	, m_szOffsetX(_T(""))
	, m_szOffsetY(_T(""))
{
	m_pInstance = this;
}

CSystemPane::~CSystemPane()
{
}

void CSystemPane::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SYSTEM_BACK, m_szBackName);
	DDX_Text(pDX, IDC_SYSTEM_OFFSET_X, m_szOffsetX);
	DDX_Text(pDX, IDC_SYSTEM_OFFSET_Y, m_szOffsetY);
}

BEGIN_MESSAGE_MAP(CSystemPane, CFormView)
	ON_BN_CLICKED(IDC_SYSTEM_BACK_FIND, &CSystemPane::OnBnClickedSystemBackFind)
	ON_BN_CLICKED(IDC_SYSTEM_APPLY, &CSystemPane::OnBnClickedSystemApply)
END_MESSAGE_MAP()


// CSystemPane �����Դϴ�.

#ifdef _DEBUG
void CSystemPane::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSystemPane::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

void CSystemPane::SetBackData( const TCHAR* pBackName, int nOffSetX, int nOffsetY )
{
	m_szBackName.Format( _T("%s"), pBackName );
	m_szOffsetX.Format( _T("%d"), nOffSetX );
	m_szOffsetY.Format( _T("%d"), nOffsetY );
	UpdateData( FALSE );
}

// CSystemPane �޽��� ó�����Դϴ�.

void CSystemPane::OnBnClickedSystemBackFind()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	// FileDialog ����
	char szFilter[] = "DBO 2D Background Picture File (*.png)|*.png|All Files(*.*)|*.*|";
	CFileDialog dlg( TRUE, "png", "*.png", 0, szFilter );
	
	if( dlg.DoModal() == IDOK )
	{
		m_szBackName.Format( _T("%s"), dlg.GetPathName().GetBuffer() );
	}

	UpdateData( FALSE );
}

void CSystemPane::OnBnClickedSystemApply()
{
	UpdateData( TRUE );

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetBackManager()->LoadBack( m_szBackName.GetBuffer(),
		_ttoi( m_szOffsetX.GetBuffer() ), 
		_ttoi( m_szOffsetX.GetBuffer() ) );
}