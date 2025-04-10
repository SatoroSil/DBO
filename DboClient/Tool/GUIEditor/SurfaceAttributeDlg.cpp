// SurfaceAttributeDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "GUIEditor.h"
#include "GUIResourceView.h"
#include "SurfaceAttributeDlg.h"
#include "ResourceAttributeDlg.h"
#include ".\surfaceattributedlg.h"
#include "SurfaceLayer.h"
#include "SurfaceListDlg.h"
#include "LayerMisc.h"


// CSurfaceAttributeDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNCREATE(CSurfaceAttributeDlg, CDialog)
CSurfaceAttributeDlg::CSurfaceAttributeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSurfaceAttributeDlg::IDD, pParent)
{
	m_bInitialized = FALSE;
}

CSurfaceAttributeDlg::~CSurfaceAttributeDlg()
{
}

void CSurfaceAttributeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSurfaceAttributeDlg, CDialog)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_ADD_SURFACELIST, &CSurfaceAttributeDlg::OnBnClickedAddSurfacelist)
	ON_BN_CLICKED(IDC_FIX_SURFACELIST, &CSurfaceAttributeDlg::OnBnClickedFixSurfacelist)
END_MESSAGE_MAP()


// CSurfaceAttributeDlg �޽��� ó�����Դϴ�.

BOOL CSurfaceAttributeDlg::OnInitDialog()
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
	pRoot->SetCtrlID( PROPERTY_NONE );

	// End of Initialize
	m_bInitialized = TRUE;

	InitProperty();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CSurfaceAttributeDlg::OnSize(UINT nType, int cx, int cy)
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

void CSurfaceAttributeDlg::InitProperty()
{
	m_PropertyTree.DeleteAllItems();

	// Title
	CPropTreeItem* pRoot = m_PropertyTree.InsertItem( new CPropTreeItem() );
	pRoot->Expand();
	pRoot->SetLabelText( _T( "Surface Attribute" ) );
	pRoot->SetCtrlID( PROPERTY_GROUP );

	// ResourceName
	CPropTreeItemEdit* pEdit;
	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pRoot );
	pEdit->SetLabelText( _T( "Name" ) );
	pEdit->SetInfoText( _T( "Surface Name" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatText );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_SURFACENAME );

	// ResourceHandle
	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pRoot );
	pEdit->SetLabelText( _T( "Rsr File" ) );
	pEdit->SetInfoText( _T( "Resource FileName" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatText );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_RESOURCEFILE );

	// FileName
	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pRoot );
	pEdit->SetLabelText( _T( "Rsr Name" ) );
	pEdit->SetInfoText( _T( "Resource Name" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatText );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_RESOURCENAME );

	// Coord
	CPropTreeItem* pTree;
	pTree = (CPropTreeItem*)m_PropertyTree.InsertItem( new CPropTreeItem(), pRoot );
	pTree->Expand();
	pTree->SetLabelText( _T( "Coordinates") );
	pTree->SetCtrlID( PROPERTY_GROUP_COORD );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "x" ) );
	pEdit->SetInfoText( _T( "x Coordinates" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_X ); 

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "y" ) );
	pEdit->SetInfoText( _T( "y Coordinates" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_Y ); 

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "width" ) );
	pEdit->SetInfoText( _T( "width" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_WIDTH ); 

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "height" ) );
	pEdit->SetInfoText( _T( "height" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_HEIGHT ); 

	// Color
	pTree = (CPropTreeItem*)m_PropertyTree.InsertItem( new CPropTreeItem(), pRoot );
	pTree->SetLabelText( _T( "Color") );
	pTree->SetCtrlID( PROPERTY_GROUP_COLOR );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "r" ) );
	pEdit->SetInfoText( _T( "Red" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)255 );
	pEdit->SetCtrlID( PROPERTY_R ); 

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "g" ) );
	pEdit->SetInfoText( _T( "Green" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)255 );
	pEdit->SetCtrlID( PROPERTY_G ); 

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "b" ) );
	pEdit->SetInfoText( _T( "Blue" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)255 );
	pEdit->SetCtrlID( PROPERTY_B ); 

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "a" ) );
	pEdit->SetInfoText( _T( "Alpha" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)255 );
	pEdit->SetCtrlID( PROPERTY_A ); 

	// UV
	pTree = (CPropTreeItem*)m_PropertyTree.InsertItem( new CPropTreeItem(), pRoot );
	pTree->Expand();
	pTree->SetLabelText( _T( "UV") );
	pTree->SetCtrlID( PROPERTY_GROUP_UV );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "u1" ) );
	pEdit->SetInfoText( _T( "Left" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_UV_LEFT ); 

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "v1" ) );
	pEdit->SetInfoText( _T( "Top" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_UV_TOP ); 

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "u2" ) );
	pEdit->SetInfoText( _T( "Right" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_UV_RIGHT ); 

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pTree );
	pEdit->SetLabelText( _T( "v2" ) );
	pEdit->SetInfoText( _T( "Bottom" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_UV_BOTTOM ); 

	// Etc
	CPropTreeItemCombo* pCombo;
	pCombo = (CPropTreeItemCombo*)m_PropertyTree.InsertItem( new CPropTreeItemCombo(), pRoot );
	pCombo->SetLabelText( _T( "Blend" ) );
	pCombo->SetInfoText( _T( "Blend Function" ) );
	pCombo->CreateComboBox( WS_CHILD | WS_VSCROLL | CBS_DROPDOWNLIST );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.InsertItem( new CPropTreeItemEdit(), pRoot );
	pEdit->SetLabelText( _T( "Handle" ) );
	pEdit->SetInfoText( _T( "Surface Handle" ) );
	pEdit->SetValueFormat( CPropTreeItemEdit::ValueFormatNumber );
	pEdit->SetItemValue( (LPARAM)0 );
	pEdit->SetCtrlID( PROPERTY_HANDLE ); 

	INT index;
	index = pCombo->AddString( _T( "" ) );
	pCombo->SetItemData( index, 0 );

	pCombo->SetItemValue( (LPARAM)0 );
	pCombo->SetCtrlID( PROPERTY_BLEND );
}

void CSurfaceAttributeDlg::SetUV( CRect& uv )
{
	CPropTreeItemEdit* pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_LEFT );
	pEdit->SetItemValue( (LPARAM)uv.left );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_TOP );
	pEdit->SetItemValue( (LPARAM)uv.top );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_RIGHT );
	pEdit->SetItemValue( (LPARAM)uv.right );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_BOTTOM );
	pEdit->SetItemValue( (LPARAM)uv.bottom );

	m_PropertyTree.UpdatedItems();
}

void CSurfaceAttributeDlg::SetRect( CRect& rect )
{
	CPropTreeItemEdit* pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_WIDTH );
	pEdit->SetItemValue( (LPARAM)rect.Width() );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_HEIGHT );
	pEdit->SetItemValue( (LPARAM)rect.Height() );

	m_PropertyTree.UpdatedItems();
}

void CSurfaceAttributeDlg::OnBnClickedAddSurfacelist()
{
	// TODO: Add your control notification handler code here
	AddData();
	AddCaptionToList();
}

void CSurfaceAttributeDlg::AddCaptionToList()
{
	CSurfaceLayer* pView = (CSurfaceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::SURFACE_LAYER );
	CSurfaceListDlg* pDlg = (CSurfaceListDlg*)pView->GetRollupDlg( CSurfaceLayer::SURFACELISTDLG );

	pDlg->DisplayList();
}

void CSurfaceAttributeDlg::AddData()
{
	SURFACEDATA* pSurfaceData = new SURFACEDATA;

	if( pSurfaceData == NULL )
		return;
		
	if(	!InputData( pSurfaceData ) )
	{
		delete pSurfaceData;
		return;
	}

	g_pDocument->GetDataManager().AddSurfaceData( pSurfaceData );
}

BOOL CSurfaceAttributeDlg::InputData( SURFACEDATA* pSurfaceData, BOOL bFix /* = FALSE  */)
{
	CPropTreeItemEdit* pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_SURFACENAME );
	CString str( (LPCTSTR)pEdit->GetItemValue() );
	pSurfaceData->_strName = str;

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_RESOURCEFILE );
	str = (LPCTSTR)pEdit->GetItemValue();
	pSurfaceData->_strResourceFileName = str;

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_RESOURCENAME );
	str = (LPCTSTR)pEdit->GetItemValue();
	pSurfaceData->_strResourceName = str;

	CRect	rcTemp;
	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_X );
	rcTemp.left = (INT)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_Y );
	rcTemp.top = (INT)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_WIDTH );
	rcTemp.right = (INT)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_HEIGHT );
	rcTemp.bottom = (INT)pEdit->GetItemValue();
	pSurfaceData->_rcCoord = rcTemp;

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_R );
	pSurfaceData->_cRed = (BYTE)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_G );
	pSurfaceData->_cGreen = (BYTE)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_B );
	pSurfaceData->_cBlue = (BYTE)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_A );
	pSurfaceData->_cAlpha = (BYTE)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_LEFT );
	rcTemp.left = (INT)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_TOP );
	rcTemp.top = (INT)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_RIGHT );
	rcTemp.right = (INT)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_BOTTOM );
	rcTemp.bottom = (INT)pEdit->GetItemValue();
	pSurfaceData->_rcUV = rcTemp;

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_HANDLE );
	pSurfaceData->_nHandle = (INT)pEdit->GetItemValue();

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_BLEND );
	// ���� ����.
	pSurfaceData->_strBlendFunction = CString( "0" );

	if( !InputCheck( pSurfaceData, bFix ) )
		return FALSE;

	return TRUE;
}

void CSurfaceAttributeDlg::FillSurfaceProperty( SURFACEDATA* pSurfaceData )
{
	CResourceLayer* pView = (CResourceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::RESOURCE_LAYER );
	CResourceAttributeDlg* pDlg = (CResourceAttributeDlg*)pView->GetRollupDlg( CResourceLayer::RESOURCEATTRIBUTEDLG );

	if( !pSurfaceData )
	{
		AfxMessageBox( "�ش� ���ǽ��� �����ϴ�" );
		pDlg->FillResourceProperty( NULL );
		return;
	}

	// �ش��ϴ� ���ҽ����� �ε�.
	CString strFullPath = pSurfaceData->_strResourceFileName;
	if( !g_pDocument->GetDataManager().LoadRsrFile( strFullPath, pSurfaceData->_strResourceFileName ) )
	{
		strFullPath = g_pDocument->GetDataManager().GetWorkDir() + CString( "\\" ) + pSurfaceData->_strResourceFileName;

		if( !g_pDocument->GetDataManager().LoadRsrFile( strFullPath, pSurfaceData->_strResourceFileName ) )
		{
			strFullPath = g_pDocument->GetDataManager().GetWorkDir() + CString( "\\gui\\" ) + pSurfaceData->_strResourceFileName;

			if( !g_pDocument->GetDataManager().LoadRsrFile( strFullPath, pSurfaceData->_strResourceFileName ) )
			{
				strFullPath = g_pDocument->GetDataManager().GetWorkDir() + CString( "\\gui\\Human\\" ) + pSurfaceData->_strResourceFileName;

				if( !g_pDocument->GetDataManager().LoadRsrFile( strFullPath, pSurfaceData->_strResourceFileName ) )
				{
					AfxMessageBox( "�ش� ���ҽ������� �����ϴ�" );
				}
			}
		}
	}
		
	// �ش��ϴ� ���ҽ� �ε�. ( �׸��� ���ҽ����� �ε�� )
	RESOURCEDATA* pResourceData = g_pDocument->GetDataManager().GetResourceData( pSurfaceData->_strResourceName );
	if( pResourceData )
		pDlg->FillResourceProperty( pResourceData );

	// ������ ǥ��
	CPropTreeItemEdit* pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_SURFACENAME );
	pEdit->SetItemValue( (LPARAM)( (LPCTSTR)pSurfaceData->_strName ) );
	
	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_RESOURCEFILE );
	pEdit->SetItemValue( (LPARAM)( (LPCTSTR)pSurfaceData->_strResourceFileName ) );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_RESOURCENAME );
	pEdit->SetItemValue( (LPARAM)( (LPCTSTR)pSurfaceData->_strResourceName ) );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_X );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_rcCoord.left );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_Y );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_rcCoord.top );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_WIDTH );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_rcCoord.right );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_HEIGHT );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_rcCoord.bottom );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_R );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_cRed );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_G );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_cGreen );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_B );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_cBlue );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_A );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_cAlpha );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_LEFT );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_rcUV.left );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_TOP );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_rcUV.top );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_RIGHT );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_rcUV.right );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_UV_BOTTOM );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_rcUV.bottom );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_HANDLE );
	pEdit->SetItemValue( (LPARAM)pSurfaceData->_nHandle );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_BLEND );
	// ���� ����.
	pEdit->SetItemValue( (LPARAM)0 );

	m_PropertyTree.UpdatedItems();

	// ���ùڽ� ����
	g_pResourceView->SetSelectBox( pSurfaceData->_rcUV );
}

void CSurfaceAttributeDlg::OnBnClickedFixSurfacelist()
{
	// TODO: Add your control notification handler code here
	CSurfaceLayer* pView = (CSurfaceLayer*)CLayerMisc::GetInstance().GetLayer( CLayerMisc::SURFACE_LAYER );
	CSurfaceListDlg* pDlg = (CSurfaceListDlg*)pView->GetRollupDlg( CSurfaceLayer::SURFACELISTDLG );
	
	INT nFocusID =  pDlg->GetFocusID();

	if( nFocusID < 1 )
	{
		AfxMessageBox( "������ �������� Ŭ���ϼ���" );
		return;
	}

	SURFACEDATA* pData = g_pDocument->GetDataManager().GetSurfaceData( nFocusID );

	if( !pData )
		return;

	if( !InputData( pData, TRUE ) )
		return;	

	pDlg->DisplayList();
}

void CSurfaceAttributeDlg::SetResourceInfo( CString& strResourcename, CString& strResourceFilename )
{
	CPropTreeItemEdit* pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_RESOURCEFILE );
	pEdit->SetItemValue( (LPARAM)( (LPCTSTR)strResourceFilename ) );

	pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_RESOURCENAME );
	pEdit->SetItemValue( (LPARAM)( (LPCTSTR)strResourcename ) );

	m_PropertyTree.UpdatedItems();
}

void CSurfaceAttributeDlg::SetName( CString strName )
{
	CPropTreeItemEdit* pEdit = (CPropTreeItemEdit*)m_PropertyTree.FindItem( PROPERTY_SURFACENAME );
	pEdit->SetItemValue( (LPARAM)( (LPCTSTR)strName ) );
}

BOOL CSurfaceAttributeDlg::InputCheck( SURFACEDATA* pSurfaceData, BOOL bFix /* = FALSE  */)
{
	if( pSurfaceData->_strName == CString( "" ) )
	{
		AfxMessageBox( "�̸��� �Է��ؾ� �մϴ�" );
		return FALSE;
	}

	if( g_pDocument->GetDataManager().GetSurfaceData( pSurfaceData->_strName ) && !bFix )
	{
		AfxMessageBox( "���� �̸��� �Է��� �� �����ϴ�" );
		return FALSE;
	}

	if( pSurfaceData->_strResourceName == CString( "" ) ||
		pSurfaceData->_strResourceFileName == CString( "" ) )
	{
		AfxMessageBox( "���ҽ������� �����ϴ�\n���ҽ������� �ε��ϼ���" );
		return FALSE;
	}

	return TRUE;
}