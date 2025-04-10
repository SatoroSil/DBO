// ResourceAttributeDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "GUIEditor.h"
#include "ResourceAttributeDlg.h"
#include ".\resourceattributedlg.h"
#include "ResourceLayer.h"
#include "LayerMisc.h"
#include "ResourceListDlg.h"
#include "GUIResourceView.h"


// CResourceAttributeDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CResourceAttributeDlg, CDialog)
CResourceAttributeDlg::CResourceAttributeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CResourceAttributeDlg::IDD, pParent)
{
}

CResourceAttributeDlg::~CResourceAttributeDlg()
{
}

void CResourceAttributeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CResourceAttributeDlg, CDialog)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_ADD_RESOURCELIST, OnBnClickedAddResourlist)
	ON_BN_CLICKED(IDC_FIX_RESOURCELIST, &CResourceAttributeDlg::OnBnClickedFixResourcelist)
END_MESSAGE_MAP()


// CResourceAttributeDlg �޽��� ó�����Դϴ�.

BOOL CResourceAttributeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	DWORD dwStyle;
	CRect rc;

	// PTS_NOTIFY - CPropTree will send notification messages to the parent window
	dwStyle = WS_CHILD | WS_VISIBLE | PTS_NOTIFY;

	// Init the control's size to cover the entire client area
	CWnd* pWindow = GetDlgItem( IDC_PROPERTY_STATIC );
	if( pWindow )
	{
		pWindow->GetWindowRect( rc );
		ScreenToClient( &rc );
	}

	//Create CPropTree Control
	m_PropertyTree.Create( dwStyle, rc, this, IDC_PROPERTY_STATIC );

	// Initialize Item
	CPropTreeItem* pRoot;
	pRoot = m_PropertyTree.InsertItem( new CPropTreeItem() );
	pRoot->SetLabelText( _T( "No Selected" ) );

	// End of Initialize
	m_bInitialized = TRUE;

	InitProperty();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CResourceAttributeDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if( m_bInitialized )
	{
		CWnd* pWindow = GetDlgItem( IDC_PROPERTY_STATIC );
		if( pWindow )
		{
			CRect rc;	
			pWindow->GetWindowRect(rc);
			ScreenToClient( &rc );
			rc.right = rc.left + cx;			
			pWindow->MoveWindow( rc.left, rc.top, cx, rc.Height() );

			if ( ::IsWindow( m_PropertyTree.GetSafeHwnd() ) )
				m_PropertyTree.MoveWindow( &rc );		
		}
	}
}

void CResourceAttributeDlg::InitProperty()
{
	m_PropertyTree.DeleteAllItems();

	// Title
	CPropTreeItem* pRoot = m_PropertyTree.InsertItem( new CPropTreeItem() );
	pRoot->Expand();
	pRoot->SetLabelText( _T( "Resource Attribute" ) );
	pRoot->SetCtrlID( PROPERTY_CAPTION );

	// ResourceName
	CPropTreeItemEdit* pEdit;
	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pRoot );
	pEdit->SetLabelText( _T( "Name" ) );
	pEdit->SetInfoText( _T( "Resource Name" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatText );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_RESOURCENAME );

	// ResourceHandle
	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pRoot );
	pEdit->SetLabelText( _T( "Handle" ) );
	pEdit->SetInfoText( _T( "Resource Handle" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_HANDLE );

	// FileName
	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pRoot );
	pEdit->SetLabelText( _T( "FileName" ) );
	pEdit->SetInfoText( _T( "Resource Filename" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatText );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_FILENAME );

}

void CResourceAttributeDlg::SetFileName( LPCTSTR szFileName )
{
	CPropTreeItemEdit* pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_FILENAME );
	pEdit->SetItemValue( (LPARAM)szFileName );
	m_PropertyTree.UpdatedItems();
}

void CResourceAttributeDlg::SetBlank()
{
	CPropTreeItemEdit* pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_RESOURCENAME );
	pEdit->SetItemValue( (LPARAM)"" );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_HANDLE );
	pEdit->SetItemValue( (LPARAM)0 );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_FILENAME );
	pEdit->SetItemValue( (LPARAM)"" );

	m_PropertyTree.UpdateData();
}


void CResourceAttributeDlg::OnBnClickedAddResourlist()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AddData();
	AddCaptionToList();
}

void CResourceAttributeDlg::AddCaptionToList()
{
	CResourceLayer* pView = (CResourceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::RESOURCE_LAYER );
	CResourceListDlg* pDlg = (CResourceListDlg*)pView->GetRollupDlg( CResourceLayer::RESOURCELISTDLG );
	
	pDlg->DisplayList();
}

void CResourceAttributeDlg::AddData()
{
	RESOURCEDATA* pResourceData = new RESOURCEDATA;

	if( pResourceData == NULL )
		return;

	if( !InputData( pResourceData ) )
	{
		delete pResourceData;
		return;
	}

	g_pDocument->GetDataManager().AddResourceData( pResourceData );
}

BOOL CResourceAttributeDlg::InputData( RESOURCEDATA* pResourceData, BOOL bFix /* = FALSE  */)
{
	CPropTreeItemEdit* pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_RESOURCENAME );
	CString str( (LPCTSTR)pEdit->GetItemValue() );
	pResourceData->_strName = str;

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_HANDLE );
	pResourceData->_nHandle = (INT)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_FILENAME );
	str = (LPCTSTR)pEdit->GetItemValue();
	pResourceData->_strFileName = str;

	if( !InputCheck( pResourceData, bFix ) )
		return FALSE;

	return TRUE;
}

void CResourceAttributeDlg::FillResourceProperty( RESOURCEDATA* pResourceData )
{
	if( !pResourceData )
	{
		AfxMessageBox( "�ش� ���ҽ��� �����ϴ�" );
		g_pResourceView->LoadImage( CString( "" ), CString( "" ) );
		return;
	}

	// �ش��ϴ� �׸� ǥ��.
	CString strFullPath = pResourceData->_strFileName;
	if( !g_pResourceView->LoadImage( strFullPath, pResourceData->_strFileName ) )
	{
		strFullPath = g_pDocument->GetDataManager().GetWorkDir() + CString( "\\" ) + pResourceData->_strFileName;
		
		if( !g_pResourceView->LoadImage( strFullPath, pResourceData->_strFileName ) )
		{
			strFullPath = g_pDocument->GetDataManager().GetWorkDir() + CString( "\\texture\\gui\\" ) + pResourceData->_strFileName;

			if( !g_pResourceView->LoadImage( strFullPath, pResourceData->_strFileName ) )
			{
				AfxMessageBox( "�ش� �̹����� �����ϴ�" );
			}
		}
	}
	
	// ������ ǥ��.
	CPropTreeItemEdit* pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_RESOURCENAME );
	pEdit->SetItemValue( (LPARAM)( (LPCTSTR)pResourceData->_strName ) );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_HANDLE );
	pEdit->SetItemValue( (LPARAM)pResourceData->_nHandle );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_FILENAME );
    pEdit->SetItemValue( (LPARAM)( (LPCTSTR)pResourceData->_strFileName ) );

	m_PropertyTree.UpdatedItems();
}

void CResourceAttributeDlg::OnBnClickedFixResourcelist()
{
	// TODO: Add your control notification handler code here
	CResourceLayer* pView = (CResourceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::RESOURCE_LAYER );
	CResourceListDlg* pDlg = (CResourceListDlg*)pView->GetRollupDlg( CResourceLayer::RESOURCELISTDLG );

	INT nFocusID =  pDlg->GetFocusID();

	if( nFocusID < 1 )
	{
		AfxMessageBox( "������ �������� Ŭ���ϼ���" );
		return;
	}

	RESOURCEDATA* pData = g_pDocument->GetDataManager().GetResourceData( nFocusID );

	if( !pData )
		return;

	if( !InputData( pData, TRUE ) )
		return;	

	pDlg->DisplayList();
}

BOOL CResourceAttributeDlg::InputCheck( RESOURCEDATA* pResourceData, BOOL bFIX /* = FALSE  */)
{
	if( pResourceData->_strName == CString( "" ) )
	{
		AfxMessageBox( "�̸��� �Է��ؾ� �մϴ�" );
		return FALSE;
	}

	if( g_pDocument->GetDataManager().GetResourceData( pResourceData->_strName )  && !bFIX )
	{
		AfxMessageBox( "���� �̸��� �Է��� �� �����ϴ�" );
		return FALSE;
	}

	if( pResourceData->_strFileName == CString( "" ) )
	{
		AfxMessageBox( "�����̸��� �Է��ؾ� �մϴ�" );
		return FALSE;
	}

	return TRUE;
}
