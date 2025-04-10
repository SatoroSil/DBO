// AttributePane.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "2DParticleEditor.h"
#include "2DPArticleGlobal.h"
#include "2DParticleApp.h"
#include "2DParticleEditorDoc.h"
#include "MainFrm.h"

// Panes
#include "PropertiesPane.h"
#include "AttributePane.h"

// Dialogs
#include "AttrRenameDlg.h"

//
#include "gui_particle_doc.h"

LRESULT CAttributePane::CAttributeTree::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	switch( message )
	{
	case WM_NCPAINT:
		{
			CTreeCtrl::WindowProc( message, wParam, lParam );

			CRect rc;
			GetWindowRect(&rc);
			CWindowDC dc(this);
			rc.OffsetRect(-rc.TopLeft());
			COLORREF clr = GetXtremeColor(XPCOLOR_STATICFRAME);
			dc.Draw3dRect(rc, clr, clr);

			return TRUE;
		}
	}

	return CTreeCtrl::WindowProc(message, wParam, lParam);
}

BOOL CAttributePane::CAttributeTree::IsName( CString szName, HTREEITEM hSelectedItem )
{
	if( !hSelectedItem  )
		return FALSE;

	// �ߺ� �̸� �˻�
	HTREEITEM hParentItem = GetParentItem( hSelectedItem );

	HTREEITEM hSiblingItem = GetChildItem( hParentItem );
	while( hSiblingItem )
	{
		if( _strcmpi( szName.GetBuffer(), GetItemText( hSiblingItem ).GetBuffer() ) == 0 )
		{
			return TRUE;
		}

		hSiblingItem = GetNextSiblingItem( hSiblingItem );
	}

	return FALSE;
}

// CAttributePane::CAttrButeTree �޽��� ó����
BEGIN_MESSAGE_MAP(CAttributePane::CAttributeTree, CTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CAttributeTree::OnTvnSelchanged)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &CAttributeTree::OnNMDblclk)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

/**
* \brief Ʈ���� �ٸ� �׸��� �������� �� �߻�
*/
void CAttributePane::CAttributeTree::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CPropertiesPane *pPropertyPane = pMainFrame->GetPropertiesPane();

	HTREEITEM hItem = GetSelectedItem();
	if( hItem )
	{
		// �׸��� ���� ���� ��� ���� �׸��� ATTR_TREE_PARTICLE �̶�� ������Ƽ�� Active ������Ƽ �����ͷ� �����ش�.
		SAttrTreeData* pData = (SAttrTreeData*)GetItemData( hItem );
		if( pData )
		{
			if( pData->byType == ATTR_TREE_PARTICLE )
			{
				if( pData->pData )
				{
					gui::CParticleItem* pItem = (gui::CParticleItem*)pData->pData;
					
					pPropertyPane->SetActiveProperty( pItem );
				}
			}
			else
			{
				pPropertyPane->DeActiveProperty();
			}
		}
	}
	else
	{
		pPropertyPane->DeActiveProperty();
	}

	*pResult = 0;
}

/**
* \brief Ʈ���� ���� Ŭ�� ���� �� �߻�
*/
void CAttributePane::CAttributeTree::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	HTREEITEM hSelectedItem = GetSelectedItem();
	if( hSelectedItem )
	{
		CAttrRenameDlg dlg;
		dlg.m_strRename.Format( _T("%s"), GetItemText( hSelectedItem ).GetBuffer() );
		CRect rect;
		GetItemRect( hSelectedItem, &rect, TRUE );
		
		if( rect.Width() < 100 )
			rect.right = rect.left + 100;
		
		CRect rtScreen;
		GetWindowRect( &rtScreen );

		rect.MoveToX( rect.left + rtScreen.left );
		rect.MoveToY( rect.top + rtScreen.top );
		dlg.SetPrePosition( &rect );
		if( dlg.DoModal() == IDOK )
		{
			if( dlg.m_strRename.Compare( GetItemText( hSelectedItem ).GetBuffer() ) != 0 )
			{
				// �̸� �ߺ� �˻�
				if( IsName( dlg.m_strRename, hSelectedItem ) )
				{
					AfxMessageBox( _T("There is currently the same name in depth."), MB_OK );
					*pResult = 0;
					return;
				}

				while( strpbrk( dlg.m_strRename.GetBuffer(), "\t\n " ) )
				{
					AfxMessageBox( _T("The name must not contain spaces."), MB_OK );

					if( dlg.DoModal() == IDCANCEL )
					{
						*pResult = 0;
						return;
					}
				}
			}

			// ���� Doc���� ����Ʈ�� �������� �����´�.
			SAttrTreeData* pData = (SAttrTreeData*)GetItemData( hSelectedItem );
			if( pData == NULL )
				return;

			// �׷��� �̸� ����
			if( pData->byType == ATTR_TREE_GROUP )
			{	
				gui::CParticleGroup *pGroup = gui::GetParticleDoc()->GetReplaceGroupKey( GetItemText( hSelectedItem ), dlg.m_strRename );
				if( pGroup == NULL )
				{
					ASSERT( 0 && "void CAttributePane::CAttributeTree::OnNMDblclk " );
				}
			}
			// ��ƼŬ�� �̸� ����
			else if( pData->byType == ATTR_TREE_PARTICLE )
			{
				HTREEITEM hParentItem = GetParentItem( hSelectedItem );
				
				gui::CParticleGroup* pGroup = gui::GetParticleDoc()->GetParticleGroup( GetItemText( hParentItem ) );
				
				pGroup->GetReplaceItemKey( GetItemText( hParentItem ), dlg.m_strRename );
			}

			SetItemText( hSelectedItem, dlg.m_strRename );
		}
	}

	*pResult = 0;
}

void CAttributePane::CAttributeTree::OnDestroy()
{
	CTreeCtrl::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}




CAttributePane::CAttributePane()
{

}

CAttributePane::~CAttributePane()
{
}

// CAttributePane �޽��� ó����
BEGIN_MESSAGE_MAP(CAttributePane, CWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()	
	ON_COMMAND( ID_ATTR_GADD, OnAttrGAdd )
	ON_UPDATE_COMMAND_UI( ID_ATTR_GADD, OnUpdateAttrGAdd )
	ON_COMMAND( ID_ATTR_DEL, OnAttrDel )
	ON_UPDATE_COMMAND_UI( ID_ATTR_DEL, OnUpdateAttrDel )
	ON_COMMAND( ID_ATTR_PADD, OnAttrPAdd )
	ON_UPDATE_COMMAND_UI( ID_ATTR_PADD, OnUpdateAttrPadd )
	ON_COMMAND( ID_ATTR_PLAY, OnAttrPlay)
	ON_UPDATE_COMMAND_UI( ID_ATTR_PLAY, OnUpdateAttrPlay )
END_MESSAGE_MAP()

void CAttributePane::LoadTree( gui::CParticleDoc* pDoc )
{
	DeleteAllTreeItemData();

	if( pDoc == NULL )
		return;

	// ��ƼŬ �׷��� �о�´�.
	gui::CParticleGroup* pGroup = pDoc->GetFirstGroup();
	HTREEITEM hCurrentGroup;
	while( pGroup )
	{
		SAttrTreeData* pData = new SAttrTreeData;
		pData->byType = ATTR_TREE_GROUP;
		pData->pData = (VOID*)pGroup;

		hCurrentGroup = m_WndTreeCtrl.InsertItem( pGroup->GetName().c_str(), 0, 0, TVI_ROOT );
		m_WndTreeCtrl.SetItemData( hCurrentGroup, (DWORD_PTR)pData );
		
		// ��ƼŬ �׷쿡 �ִ� ��ƼŬ���� ��ȸ�ϸ� ���� �Ӽ����� �о�´�. :: �����ϴ��� Ȯ�� �ؾ���
		gui::CParticleItem* pItem = pGroup->GetFirstParticle();
		while( pItem )
		{
			SAttrTreeData* pData = new SAttrTreeData;
			pData->byType = ATTR_TREE_PARTICLE;
			pData->pData = (VOID*)pItem;

			HTREEITEM hItem = m_WndTreeCtrl.InsertItem( pItem->GetName().c_str(), 1, 1, hCurrentGroup );
			m_WndTreeCtrl.SetItemData( hItem, (DWORD_PTR)pData );

			pItem = pGroup->GetNextParticle();
		}
		pGroup = pDoc->GetNextGroup();
	}
}

int CAttributePane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// �ͽ�Ʈ�� ��Ŷ ���ٸ� ����
	m_wndToolBar.CreateToolBar(WS_VISIBLE | WS_CHILD | CBRS_TOOLTIPS, this );
	m_wndToolBar.LoadToolBar( IDR_ATTRIBUTE );

	// ������ ��Ʈ�� �ε�
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP_ICONS);

	// Ʈ���� ���� BMP ����
	m_ilTreeIcons.Create( 16, 16, ILC_MASK | ILC_COLOR24, 0, 0 );
	m_ilTreeIcons.Add( &bmp, RGB( 0, 255, 0 ) );

	// Ʈ�� ����
	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if( !m_WndTreeCtrl.Create( WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE | TVS_HASLINES |
		TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS,
		CRect( 0, 0, 0, 0 ), this,
		IDC_ATTRIBUTE_TREE ) )
	{
		TRACE0("Failed to create attribute tree control\n");
		return -1;
	}

	// Ʈ���� BMP ����
	m_WndTreeCtrl.ModifyStyleEx( 0, WS_EX_STATICEDGE );
	m_WndTreeCtrl.SetImageList( &m_ilTreeIcons, TVSIL_NORMAL );
	
	return 0;
}

void CAttributePane::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	DeleteAllTreeItemData();
}

void CAttributePane::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	// ���ٸ� �׸��� �� �ؿ� Ʈ���� ��ġ�ϰ� �Ѵ�.
	CSize sz(0);
	if( m_wndToolBar.GetSafeHwnd() )
	{
		sz = m_wndToolBar.CalcDockingLayout( cx, LM_HORZDOCK | LM_HORZ | LM_COMMIT );

		m_wndToolBar.MoveWindow( 0, 0, cx, sz.cy );
		m_wndToolBar.Invalidate( FALSE );
	}

	if( m_WndTreeCtrl.GetSafeHwnd() )
	{
		m_WndTreeCtrl.MoveWindow( 0, sz.cy, cx, cy - sz.cy );
	}
}

void CAttributePane::DeleteTreeItemData( HTREEITEM hItem )
{
	if( hItem == NULL )
		return;

	SAttrTreeData* pData = (SAttrTreeData*)m_WndTreeCtrl.GetItemData(hItem);
	if( pData )
	{
		delete pData;
		pData = NULL;
	}
	m_WndTreeCtrl.SetItemData( hItem, 0 );
}

void CAttributePane::DeleteTreeChildItemData( HTREEITEM hItem )
{
	HTREEITEM hSiblingItem = hItem;
	while( hSiblingItem )
	{
		HTREEITEM hChildItem = m_WndTreeCtrl.GetChildItem( hSiblingItem );
		if( hChildItem )
			DeleteTreeChildItemData( hChildItem );

		DeleteTreeItemData( hSiblingItem );
		hSiblingItem = m_WndTreeCtrl.GetNextSiblingItem( hSiblingItem );
	}
}

void CAttributePane::DeleteTreeSelectedItemData( HTREEITEM hItem )
{
	if( hItem == NULL )
		return;

	HTREEITEM hChildItem = m_WndTreeCtrl.GetChildItem( hItem );
	if( hChildItem )
		DeleteTreeChildItemData( hChildItem );

	DeleteTreeItemData( hItem );
}

void CAttributePane::DeleteAllTreeItemData( void )
{
	HTREEITEM hRootItem = m_WndTreeCtrl.GetRootItem();
	if(hRootItem == NULL)
		return;

	m_WndTreeCtrl.GetItemData(hRootItem);

	DeleteTreeItemData(hRootItem);

	HTREEITEM hSiblingItem = hRootItem;

	while(hSiblingItem)
	{
		HTREEITEM hChildItem = m_WndTreeCtrl.GetChildItem( hSiblingItem );
		if( hChildItem )
		{
			DeleteTreeChildItemData( hChildItem );
		}

		DeleteTreeItemData(hSiblingItem);
		HTREEITEM hPrevItem = hSiblingItem;
		hSiblingItem = m_WndTreeCtrl.GetNextSiblingItem(hSiblingItem);
		m_WndTreeCtrl.DeleteItem( hPrevItem );
	}
}

/**
* \brief ��ƼŬ �׷��� �߰��Ѵ�.
*/
void CAttributePane::OnAttrGAdd()
{
	static int nParticleGroupID = 1;

	SAttrTreeData* pData = new SAttrTreeData;
	pData->byType = ATTR_TREE_GROUP;
	pData->pData = NULL;

	TCHAR tChar[256];
	_stprintf_s( tChar, 256, _T( "ParticleGroup%d" ), nParticleGroupID++ );

	HTREEITEM hRootItem = m_WndTreeCtrl.GetRootItem();
	
	while( m_WndTreeCtrl.IsName( tChar, hRootItem ) )
	{
		_stprintf_s( tChar, 256, _T( "ParticleGroup%d" ), nParticleGroupID++ );
	}

	gui::CParticleGroup* pGroup = gui::GetParticleDoc()->AddParticleGroup( tChar );
	if( pGroup == NULL )
		return;

	pData->pData = (VOID*)pGroup;

	HTREEITEM hItem = m_WndTreeCtrl.InsertItem( tChar, 0, 0, TVI_ROOT );
	m_WndTreeCtrl.SetItemData( hItem, (DWORD_PTR)pData );
}

void CAttributePane::OnUpdateAttrGAdd(CCmdUI* pCmdUI)
{
	
}

/**
* \brief ��ƼŬ �׷쿡 ��ƼŬ�� �߰��Ѵ�.
*/
void CAttributePane::OnAttrPAdd()
{
	static int nParticleID = 1;

	HTREEITEM hItem = m_WndTreeCtrl.GetSelectedItem();
	if( hItem )
	{
		SAttrTreeData* pData = (SAttrTreeData*)m_WndTreeCtrl.GetItemData( hItem );
		if( pData == NULL )
			return;

		if( pData->byType == ATTR_TREE_GROUP )
		{
			SAttrTreeData* pSetData = new SAttrTreeData;
			pSetData->byType = ATTR_TREE_PARTICLE;

			gui::CParticleGroup* pGroup = (gui::CParticleGroup*)pData->pData;
			if( pGroup == NULL )
				return;

			TCHAR tChar[256];
			_stprintf_s( tChar, 256, _T( "Particle%d" ), nParticleID++ );

			while( m_WndTreeCtrl.IsName( tChar, m_WndTreeCtrl.GetChildItem( hItem )  ) )
			{
				_stprintf_s( tChar, 256, _T( "Particle%d" ), nParticleID++ );
			}

			gui::CParticleItem* pItem = pGroup->AddParticle( tChar );
			pSetData->pData = (VOID*)pItem;

			HTREEITEM hAddItem = m_WndTreeCtrl.InsertItem( tChar, 1, 1, hItem);
			m_WndTreeCtrl.SetItemData( hAddItem, (DWORD_PTR)pSetData );
			m_WndTreeCtrl.Expand( hItem, TVE_EXPAND );
		}
	}
}

void CAttributePane::OnUpdateAttrPadd( CCmdUI* pCmdUI )
{
	HTREEITEM hSelectedItem = m_WndTreeCtrl.GetSelectedItem();
	if( hSelectedItem )
	{
		SAttrTreeData* pData = (SAttrTreeData*)m_WndTreeCtrl.GetItemData( hSelectedItem );
		if( pData == NULL )
		{
			return;
		}

		if( pData->byType == ATTR_TREE_GROUP )
		{
			pCmdUI->Enable(TRUE);
		}
		else
		{
			pCmdUI->Enable(FALSE);
		}
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}

void CAttributePane::OnAttrDel()
{
	if( AfxMessageBox( "Are you sure you want to delete?", MB_YESNO | MB_DEFBUTTON2 | MB_ICONQUESTION ) == IDNO )
		return;

	HTREEITEM hSelectedItem = m_WndTreeCtrl.GetSelectedItem();
	if( hSelectedItem )
	{
		SAttrTreeData* pData = (SAttrTreeData*)m_WndTreeCtrl.GetItemData( hSelectedItem );
		if( pData == NULL )
			return;

		if( pData->pData == NULL )
			return;

		if( pData->byType == ATTR_TREE_GROUP )
		{
			gui::CParticleGroup* pGroup = (gui::CParticleGroup*)pData->pData;
			gui::GetParticleDoc()->DelParticleGroup( pGroup->GetName().c_str() );
		}
		else if( pData->byType == ATTR_TREE_PARTICLE )
		{
			HTREEITEM hParentItem = m_WndTreeCtrl.GetParentItem( hSelectedItem );
			if( !hParentItem )
				return;

			gui::CParticleGroup* pGroup = gui::GetParticleDoc()->GetParticleGroup( m_WndTreeCtrl.GetItemText( hParentItem ).GetBuffer() );
			if( pGroup == NULL || pData->pData == NULL )
				return;
					
			gui::CParticleItem* pItem = (gui::CParticleItem*)pData->pData;
			if( pItem == NULL )
				return;

			gui::GetParticleDoc()->DelParticle( pGroup->GetName().c_str(), pItem->GetName().c_str() );
		}
		
		DeleteTreeSelectedItemData( hSelectedItem );
		m_WndTreeCtrl.DeleteItem( hSelectedItem );
	}
}

void CAttributePane::OnUpdateAttrDel( CCmdUI* pCmdUI )
{
	HTREEITEM hSelectedItem = m_WndTreeCtrl.GetSelectedItem();
	if( hSelectedItem )
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

/**
* \brief DOC�� ��ƼŬ���� �����Ѵ�.
*/
void CAttributePane::OnAttrPlay()
{
	HTREEITEM hSelectedItem = m_WndTreeCtrl.GetSelectedItem();
	if( hSelectedItem )
	{
		SAttrTreeData* pData = (SAttrTreeData*)m_WndTreeCtrl.GetItemData( hSelectedItem );
		if( pData != NULL )
		{
			if( pData->byType == ATTR_TREE_GROUP )
			{
				// ���� �ִ� ���������� Particle Box�� ������ �ϰ� �÷��� �ϴ� �Լ��� ����
				GetParticleApp()->Load( m_WndTreeCtrl.GetItemText( hSelectedItem ).GetBuffer() );
				GetParticleApp()->Play( false );
			}
			// �׷��� �ƴ� ��ƼŬ�� ��� ���� ���� Group�� �÷���
			else if( pData->byType == ATTR_TREE_PARTICLE )
			{
				HTREEITEM hParentItem = m_WndTreeCtrl.GetParentItem( hSelectedItem );

				SAttrTreeData* pGroupData = (SAttrTreeData*)m_WndTreeCtrl.GetItemData( hParentItem );
				if( pGroupData != NULL )
				{
					if( pGroupData->byType == ATTR_TREE_GROUP )
					{
						// ���� �ִ� ���������� Particle Box�� ������ �ϰ� �÷��� �ϴ� �Լ��� ����
						GetParticleApp()->Load( m_WndTreeCtrl.GetItemText( hParentItem ).GetBuffer() );
						GetParticleApp()->Play( false );
					}
				}
			}
		}
	}
}

void CAttributePane::OnUpdateAttrPlay( CCmdUI* pCmdUI )
{
	HTREEITEM hSelectedItem = m_WndTreeCtrl.GetSelectedItem();
	if( hSelectedItem )
	{
		SAttrTreeData* pData = (SAttrTreeData*)m_WndTreeCtrl.GetItemData( hSelectedItem );
		if( pData == NULL )
		{
			return;
		}

		if( pData->byType == ATTR_TREE_GROUP )
		{
			pCmdUI->Enable(TRUE);
		}
		/*else
		{
			pCmdUI->Enable(FALSE);
		}*/
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}

}