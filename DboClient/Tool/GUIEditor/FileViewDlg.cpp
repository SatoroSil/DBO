// FileViewDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "GUIEditor.h"
#include "FileViewDlg.h"
#include ".\fileviewdlg.h"
#include "GUIResourceView.h"
#include "resource.h"

// FileViewDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CFileViewDlg, CDialog)
CFileViewDlg::CFileViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileViewDlg::IDD, pParent)
{
	m_bInitialized = FALSE;
}

CFileViewDlg::~CFileViewDlg()
{
}

void CFileViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFileViewDlg, CDialog)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnTvnSelchangedTree1)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// FileViewDlg �޽��� ó�����Դϴ�.

BOOL CFileViewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	if ( !m_FileTree.m_hWnd )
	{
		if ( m_FileTree.SubclassDlgItem( IDC_TREE1, this ) )
		{			
			m_FileTree.DisplayTree( NULL /*Display all*/, TRUE /* TRUE = Display Files*/ );
			//m_FileTree.DisplayTree( "Z:\\", TRUE );
	
			//_getcwd( szWorkDir, 256 );
			//// set the Path to the current Work-Directory
			//m_FileTree.SetSelPath( szWorkDir );
			//m_FileTree.SetSelPath( "Z:\\DBO-X\\DboTest\\texture\\gui" );
		}
	}

	m_bInitialized = TRUE;

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CFileViewDlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strFullPath = (LPCTSTR)m_FileTree.GetFullPath( pNMTreeView->itemNew.hItem );
	CString strSubPath = (LPCTSTR)m_FileTree.GetSubPath( (LPCTSTR)strFullPath );
		
	if( m_ExtFilter.GetType( (LPCTSTR)strFullPath ) == CExtFilter::IMAGE )
	{
		g_pResourceView->LoadImage( strFullPath, strSubPath );
		g_pResourceView->Invalidate();
	}

	*pResult = 0;
}

void CFileViewDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if( m_bInitialized )
	{
		CWnd* pWindow = GetDlgItem( IDC_TREE1 );
		
		if( pWindow )
		{
			CRect rc;
			pWindow->GetWindowRect( rc );
			ScreenToClient( &rc );
			pWindow->MoveWindow( rc.left, rc.top, cx, rc.Height() );
		}	
	}
}
