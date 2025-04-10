// WorldEditor.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "MainFrm.h"

#include "CInstanceView.h"
#include "UserMsg.h"

#include "WorldEditorDoc.h"
#include "WorldEditorView.h"

#include "CEditorApplication.h"
#include "CSceneManager.h"
#include "CWorldSectorEntity.h"

#include "Resource.h"

#include "CAtomicEntity.h"
#include "WorldEditor.h"
#include ".\worldeditor.h"

#ifdef _DEBUG
//#define new DEBUG_NEW
#endif


// CWorldEditorApp

BEGIN_MESSAGE_MAP(CWorldEditorApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// ǥ�� ������ ���ʷ� �ϴ� ���� ����Դϴ�.
	// ǥ�� �μ� ���� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_FILE_NEW, CWorldEditorApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWorldEditorApp::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, CWorldEditorApp::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, CWorldEditorApp::OnFileSaveAs)
	ON_COMMAND(ID_MODE_OBJECT_MOVE, OnModeObjectMove)
	ON_COMMAND(ID_MODE_OBJECT_ROTATE, OnModeObjectRotate)
	ON_COMMAND(ID_MODE_OBJECT_SCALE, OnModeObjectScale)
	ON_COMMAND(ID_MODE_CAMERA_VIEW_FREE, OnModeCameraViewFree)
	ON_COMMAND(ID_MODE_CAMERA_VIEW_TOP, OnModeCameraViewTop)
	ON_COMMAND(ID_VIEW_PROPERTYDIALOGBAR, OnViewPropertydialogbar)
	ON_COMMAND(ID_VIEW_WIREFRAME_FOR_OBJECT, OnViewWireframeForObject)
	ON_COMMAND(ID_VIEW_WIREFRAME_FOR_TERRAIN, OnViewWireframeForTerrain)
	ON_COMMAND(ID_VIEW_SOLID_FOR_OBJECT, OnViewSolidForObject)
	ON_COMMAND(ID_VIEW_SOLID_FOR_TERRAIN, OnViewSolidForTerrain)
	ON_COMMAND(ID_VIEW_BOUNDING_FOR_OBJECT, OnViewBoundingForObject)
	ON_COMMAND(ID_VIEW_BOUNDING_FOR_TERRAIN, OnViewBoundingForTerrain)
END_MESSAGE_MAP()


// CWorldEditorApp ����

CWorldEditorApp::CWorldEditorApp()
: m_pDocName(NULL)
{
	CEditorApplication::CreateInstance();

	m_pDocName = NTL_NEW( CFixedString );
	m_pDocName->Assign( _T( "default" ) );

	RwChar				szFilePath[256];
	GetCurrentDirectory( 256, szFilePath );
	CFixedString		FilePath( szFilePath );
	CEditorApplication::SetAppPath( FilePath );

	FilePath.Append( _T( "\\world\\structure" ) );
	CEditorApplication::SetFilePath( FilePath );
	CSceneManager::SetFilePath( FilePath );
	CWorldSectorEntity::SetFilePath( FilePath );
}


CWorldEditorApp::~CWorldEditorApp()
{
	CEditorApplication::DestroyInstance();

	NTL_DELETE( m_pDocName );
	m_pDocName = NULL;
}


// ������ CWorldEditorApp ��ü�Դϴ�.

CWorldEditorApp theApp;

// CWorldEditorApp �ʱ�ȭ

BOOL CWorldEditorApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControls()�� �ʿ��մϴ�. 
	// InitCommonControls()�� ������� ������ â�� ���� �� �����ϴ�.
	InitCommonControls();

	CWinApp::InitInstance();

	// OLE ���̺귯���� �ʱ�ȭ�մϴ�.
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(RWSTRING("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));
	LoadStdProfileSettings(4);  // MRU�� �����Ͽ� ǥ�� INI ���� �ɼ��� �ε��մϴ�.
	// ���� ���α׷��� ���� ���ø��� ����մϴ�. ���� ���ø���
	// ����, ������ â �� �� ������ ���� ������ �մϴ�.
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CWorldEditorDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ������ â�Դϴ�.
		RUNTIME_CLASS(CWorldEditorView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);
	// ǥ�� �� ���, DDE, ���� ���⿡ ���� ������� ���� �м��մϴ�.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	// ����ٿ� ������ ����� ����ġ�մϴ�. ���� ���α׷��� /RegServer, /Register, /Unregserver �Ǵ� /Unregister�� ���۵� ��� FALSE�� ��ȯ�մϴ�.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// â �ϳ��� �ʱ�ȭ�Ǿ����Ƿ� �̸� ǥ���ϰ� ������Ʈ�մϴ�.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// ���̻簡 ���� ��쿡�� DragAcceptFiles�� ȣ���մϴ�.
	// SDI ���� ���α׷������� ProcessShellCommand �Ŀ� �̷��� ȣ���� �߻��ؾ� �մϴ�.

	HWND hWnd = ((CMainFrame*)AfxGetMainWnd())->GetActiveView()->GetSafeHwnd(); 
	g_pEngineApp->Create( hWnd, FALSE );

	::SendMessage(m_pAseetObjectView->GetSafeHwnd(), WM_USER_INIT_CUSTOM_WINDOW, 0, 0);

	CInstanceView::GetInstance()->GetInstanceDialog()->GetTreeCtrl()->InitializeData();

	return TRUE;
}



// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� ������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ����

// ����
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// ��ȭ ���ڸ� �����ϱ� ���� ���� ���α׷� ����Դϴ�.
void CWorldEditorApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


BOOL CWorldEditorApp::OnIdle( LONG nCount )
{
	BOOL bMore = CWinApp::OnIdle( nCount );

	g_pEngineApp->OnIdle();

	return TRUE;
}

int CWorldEditorApp::ExitInstance()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	g_pEngineApp->Destroy();

	return CWinApp::ExitInstance();
}

void CWorldEditorApp::OnFileOpen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CFileDialog		OpenFileDialog( TRUE, _T( "prj" ), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
									_T( "Project Files (*.prj)|*.prj|All Files (*.*)|*.*||" ), NULL );

	if( OpenFileDialog.DoModal() == IDCANCEL )
	{
		return;
	}

	g_pEngineApp->OnFileLoad( OpenFileDialog.GetPathName().GetBuffer() );

	m_pDocName->Assign( OpenFileDialog.GetFileTitle().GetBuffer() );

	return;
}


void CWorldEditorApp::OnFileSave()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	if( m_pDocName->IsEquivalent( _T( "default" ) ) != FALSE )
	{
		OnFileSaveAs();
	}
	else
	{
		g_pEngineApp->OnFileSave( const_cast<RwChar *>(m_pDocName->GetBuffer()) );

		m_pDocName->Assign( m_pDocName->GetBuffer() );
	}

	CMainFrame * pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	pFrame->SetWindowText( m_pDocName->GetBuffer() );

	return;
}


void CWorldEditorApp::OnFileSaveAs()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CFileDialog		OpenFileDialog( FALSE, _T( "prj" ), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
									_T( "Project Files (*.prj)|*.prj|All Files (*.*)|*.*||" ), NULL );

	if( OpenFileDialog.DoModal() == IDCANCEL )
	{
		return;
	}

	g_pEngineApp->OnFileSave( OpenFileDialog.GetFileTitle().GetBuffer() );

	m_pDocName->Assign( OpenFileDialog.GetFileTitle().GetBuffer() );

	CMainFrame * pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	pFrame->SetWindowText( m_pDocName->GetBuffer() );

	return;
}


void CWorldEditorApp::OnFileNew()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	static bool	bFirst = true;

	if( bFirst == true )
	{
		CWinApp::OnFileNew();

		bFirst = false;
	}
	else
	{
		g_pEngineApp->OnFileNew();

		m_pDocName->Assign( _T( "default" ) );
	}

	CMainFrame * pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	pFrame->SetWindowText( m_pDocName->GetBuffer() );

	return;
}


void CWorldEditorApp::OnModeObjectMove()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	g_pEngineApp->SetEditMode( E_EDIT_MODE_OBJECT_MOVE_XZ );

	CMainFrame * pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());

	// Menu

	CMenu *			pMenu = pFrame->GetMenu();

	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 3 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_MODE_OBJECT_MOVE, &Info, FALSE );
	Info.fState = MFS_CHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_OBJECT_MOVE, &Info, FALSE );

	pMenu->GetMenuItemInfo( ID_MODE_OBJECT_ROTATE, &Info, FALSE );
	Info.fState = MFS_UNCHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_OBJECT_ROTATE, &Info, FALSE );

	pMenu->GetMenuItemInfo( ID_MODE_OBJECT_SCALE, &Info, FALSE );
	Info.fState = MFS_UNCHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_OBJECT_SCALE, &Info, FALSE );

	return;
}


void CWorldEditorApp::OnModeObjectRotate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	g_pEngineApp->SetEditMode( E_EDIT_MODE_OBJECT_ROTATE_Y );

	CMainFrame *	pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());

	// Menu

	CMenu *			pMenu = pFrame->GetMenu();

	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 3 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_MODE_OBJECT_MOVE, &Info, FALSE );
	Info.fState = MFS_UNCHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_OBJECT_MOVE, &Info, FALSE );

	pMenu->GetMenuItemInfo( ID_MODE_OBJECT_ROTATE, &Info, FALSE );
	Info.fState = MFS_CHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_OBJECT_ROTATE, &Info, FALSE );

	pMenu->GetMenuItemInfo( ID_MODE_OBJECT_SCALE, &Info, FALSE );
	Info.fState = MFS_UNCHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_OBJECT_SCALE, &Info, FALSE );

	return;
}


void CWorldEditorApp::OnModeObjectScale()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	g_pEngineApp->SetEditMode( E_EDIT_MODE_OBJECT_SCALE_Y );

	CMainFrame * pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());

	// Menu

	CMenu *			pMenu = pFrame->GetMenu();

	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 3 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_MODE_OBJECT_MOVE, &Info, FALSE );
	Info.fState = MFS_UNCHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_OBJECT_MOVE, &Info, FALSE );

	pMenu->GetMenuItemInfo( ID_MODE_OBJECT_ROTATE, &Info, FALSE );
	Info.fState = MFS_UNCHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_OBJECT_ROTATE, &Info, FALSE );

	pMenu->GetMenuItemInfo( ID_MODE_OBJECT_SCALE, &Info, FALSE );
	Info.fState = MFS_CHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_OBJECT_SCALE, &Info, FALSE );

	return;
}


void CWorldEditorApp::OnModeCameraViewFree()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	g_pEngineApp->SetCameraMovementMode( E_CAMERA_MOVEMENT_MODE_FREE );

	CMainFrame * pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	CMenu *			pMenu = pFrame->GetMenu();

	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 3 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_MODE_CAMERA_VIEW_FREE, &Info, FALSE );
	Info.fState = MFS_CHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_CAMERA_VIEW_FREE, &Info, FALSE );

	pMenu->GetMenuItemInfo( ID_MODE_CAMERA_VIEW_TOP, &Info, FALSE );
	Info.fState = MFS_UNCHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_CAMERA_VIEW_TOP, &Info, FALSE );

	return;
}


void CWorldEditorApp::OnModeCameraViewTop()
{
	g_pEngineApp->SetCameraMovementMode( E_CAMERA_MOVEMENT_MODE_TOP );

	CMainFrame * pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());

	// Menu

	CMenu *			pMenu = pFrame->GetMenu();

	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 3 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_MODE_CAMERA_VIEW_FREE, &Info, FALSE );
	Info.fState = MFS_UNCHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_CAMERA_VIEW_FREE, &Info, FALSE );

	pMenu->GetMenuItemInfo( ID_MODE_CAMERA_VIEW_TOP, &Info, FALSE );
	Info.fState = MFS_CHECKED;
	pMenu->SetMenuItemInfo( ID_MODE_CAMERA_VIEW_TOP, &Info, FALSE );

	return;
}

void CWorldEditorApp::OnViewPropertydialogbar()
{
	CMainFrame *	pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	CMenu *			pMenu = pFrame->GetMenu();
	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 2 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_VIEW_PROPERTYDIALOGBAR, &Info, FALSE );

	if( Info.fState == MFS_UNCHECKED )
	{
		Info.fState = MFS_CHECKED;

		pFrame->ShowPropertyDialogBarWindow( true );
	}
	else
	{
		Info.fState = MFS_UNCHECKED;

		pFrame->ShowPropertyDialogBarWindow( false );
	}

	pMenu->SetMenuItemInfo( ID_VIEW_PROPERTYDIALOGBAR, &Info, FALSE );
}


void CWorldEditorApp::OnViewSolidForObject()
{
	CMainFrame *	pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	CMenu *			pMenu = pFrame->GetMenu();
	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 2 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_VIEW_SOLID_FOR_OBJECT, &Info, FALSE );

	if( Info.fState == MFS_UNCHECKED )
	{
		Info.fState = MFS_CHECKED;

		CAtomicEntity::SetRenderSolidForObject( TRUE );
		CAtomicEntity::SetRenderSolidForSelectedObject( TRUE );
	}
	else
	{
		Info.fState = MFS_UNCHECKED;

		CAtomicEntity::SetRenderSolidForObject( FALSE );
		CAtomicEntity::SetRenderSolidForSelectedObject( FALSE );
	}

	pMenu->SetMenuItemInfo( ID_VIEW_SOLID_FOR_OBJECT, &Info, FALSE );
}

void CWorldEditorApp::OnViewSolidForTerrain()
{
	CMainFrame *	pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	CMenu *			pMenu = pFrame->GetMenu();
	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 2 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_VIEW_SOLID_FOR_TERRAIN, &Info, FALSE );

	if( Info.fState == MFS_UNCHECKED )
	{
		Info.fState = MFS_CHECKED;

		CAtomicEntity::SetRenderSolidForTerrain( TRUE );
		CAtomicEntity::SetRenderSolidForSelectedTerrain( TRUE );
	}
	else
	{
		Info.fState = MFS_UNCHECKED;

		CAtomicEntity::SetRenderSolidForTerrain( FALSE );
		CAtomicEntity::SetRenderSolidForSelectedTerrain( FALSE );
	}

	pMenu->SetMenuItemInfo( ID_VIEW_SOLID_FOR_TERRAIN, &Info, FALSE );
}


void CWorldEditorApp::OnViewWireframeForObject()
{
	CMainFrame *	pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	CMenu *			pMenu = pFrame->GetMenu();
	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 2 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_VIEW_WIREFRAME_FOR_OBJECT, &Info, FALSE );

	if( Info.fState == MFS_UNCHECKED )
	{
		Info.fState = MFS_CHECKED;

		CAtomicEntity::SetRenderWireFrameForObject( TRUE );
		CAtomicEntity::SetRenderWireFrameForSelectedObject( TRUE );
	}
	else
	{
		Info.fState = MFS_UNCHECKED;

		CAtomicEntity::SetRenderWireFrameForObject( FALSE );
		CAtomicEntity::SetRenderWireFrameForSelectedObject( FALSE );
	}

	pMenu->SetMenuItemInfo( ID_VIEW_WIREFRAME_FOR_OBJECT, &Info, FALSE );
}


void CWorldEditorApp::OnViewWireframeForTerrain()
{
	CMainFrame *	pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	CMenu *			pMenu = pFrame->GetMenu();
	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 2 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_VIEW_WIREFRAME_FOR_TERRAIN, &Info, FALSE );

	if( Info.fState == MFS_UNCHECKED )
	{
		Info.fState = MFS_CHECKED;

		CAtomicEntity::SetRenderWireFrameForTerrain( TRUE );
		CAtomicEntity::SetRenderWireFrameForSelectedTerrain( TRUE );
	}
	else
	{
		Info.fState = MFS_UNCHECKED;

		CAtomicEntity::SetRenderWireFrameForTerrain( FALSE );
		CAtomicEntity::SetRenderWireFrameForSelectedTerrain( FALSE );
	}

	pMenu->SetMenuItemInfo( ID_VIEW_WIREFRAME_FOR_TERRAIN, &Info, FALSE );
}

void CWorldEditorApp::OnViewBoundingForObject()
{
	CMainFrame *	pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	CMenu *			pMenu = pFrame->GetMenu();
	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 2 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_VIEW_BOUNDING_FOR_OBJECT, &Info, FALSE );

	if( Info.fState == MFS_UNCHECKED )
	{
		Info.fState = MFS_CHECKED;

		CAtomicEntity::SetRenderBoundingForObject( TRUE );
		CAtomicEntity::SetRenderBoundingForSelectedObject( TRUE );
	}
	else
	{
		Info.fState = MFS_UNCHECKED;

		CAtomicEntity::SetRenderBoundingForObject( FALSE );
		CAtomicEntity::SetRenderBoundingForSelectedObject( TRUE );
	}

	pMenu->SetMenuItemInfo( ID_VIEW_BOUNDING_FOR_OBJECT, &Info, FALSE );
}


void CWorldEditorApp::OnViewBoundingForTerrain()
{
	CMainFrame *	pFrame = reinterpret_cast<CMainFrame *>(CMainFrame::GetActiveWnd());
	CMenu *			pMenu = pFrame->GetMenu();
	MENUITEMINFO	Info;

	pMenu = pMenu->GetSubMenu( 2 );

	Info.cbSize = sizeof( MENUITEMINFO );
	Info.fMask = MIIM_STATE;

	pMenu->GetMenuItemInfo( ID_VIEW_BOUNDING_FOR_TERRAIN, &Info, FALSE );

	if( Info.fState == MFS_UNCHECKED )
	{
		Info.fState = MFS_CHECKED;

		CAtomicEntity::SetRenderBoundingForTerrain( TRUE );
		CAtomicEntity::SetRenderBoundingForSelectedTerrain( TRUE );
	}
	else
	{
		Info.fState = MFS_UNCHECKED;

		CAtomicEntity::SetRenderBoundingForTerrain( FALSE );
		CAtomicEntity::SetRenderBoundingForSelectedTerrain( FALSE );
	}

	pMenu->SetMenuItemInfo( ID_VIEW_BOUNDING_FOR_TERRAIN, &Info, FALSE );
}
