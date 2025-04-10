// LoadDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TextureBind.h"
#include "LoadDlg.h"


// CLoadDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CLoadDlg, CDialog)

CLoadDlg::CLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoadDlg::IDD, pParent)
	, m_szPath(_T(""))
{

}

CLoadDlg::~CLoadDlg()
{
}

void CLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OPEN_COMBO_TYPE, m_cbbType);
	DDX_Control(pDX, IDC_OPEN_COMBO_SIZE, m_cbbSize);
	DDX_Text(pDX, IDC_OPEN_EDIT_PATH, m_szPath);
}


BEGIN_MESSAGE_MAP(CLoadDlg, CDialog)
	ON_BN_CLICKED(IDC_OPEN_BUTTON_PATH, &CLoadDlg::OnBnClickedOpenButtonPath)
	ON_CBN_SELCHANGE(IDC_OPEN_COMBO_TYPE, &CLoadDlg::OnCbnSelchangeOpenComboType)
	ON_CBN_SELCHANGE(IDC_OPEN_COMBO_SIZE, &CLoadDlg::OnCbnSelchangeOpenComboSize)
END_MESSAGE_MAP()


// CLoadDlg �޽��� ó�����Դϴ�.

void CLoadDlg::OnBnClickedOpenButtonPath()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	ITEMIDLIST        *pidlBrowse;
	char    pszPathname[MAX_PATH];

	BROWSEINFO BrInfo;
	BrInfo.hwndOwner = NULL; //GetSafeHwnd();
	BrInfo.pidlRoot = NULL;

	memset( &BrInfo, 0, sizeof(BrInfo) );
	GetCurrentDirectory( MAX_PATH, pszPathname);
	BrInfo.pszDisplayName = pszPathname;
	BrInfo.lpszTitle = _T("�ؽ��� ���ε�/���ø� �۾��� �Ͻ� ���� ����Ÿ���� �ִ� ������ �����ϼ���.");
	BrInfo.ulFlags = BIF_RETURNONLYFSDIRS;

	// ���̾�α׸� ����
	pidlBrowse = ::SHBrowseForFolder(&BrInfo);   

	if( pidlBrowse != NULL)
	{
		// �н��� ����
		::SHGetPathFromIDList(pidlBrowse, pszPathname);   
		m_szPath = pszPathname;
		//if( !CTBApp::GetInstance()->LoadTexFromPath( pszPathname ) )
		//{
		//	// Message Box
		//}

		UpdateData( FALSE );
	}
}

void CLoadDlg::OnCbnSelchangeOpenComboType()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nTypeSel = m_cbbType.GetCurSel();
}

void CLoadDlg::OnCbnSelchangeOpenComboSize()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nSizeSel = m_cbbSize.GetCurSel();
}

BOOL CLoadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_cbbType.AddString(_T("1 X 1"));
	m_cbbType.AddString(_T("2 X 2"));
	m_cbbType.AddString(_T("4 X 4"));
	m_cbbType.AddString(_T("8 X 8"));
	m_cbbType.AddString(_T("16 X 16"));
	m_cbbType.AddString(_T("32 X 32"));
	m_cbbType.AddString(_T("64 X 64"));
	m_nTypeSel = 0;
	m_cbbType.SetCurSel(m_nTypeSel);

	m_cbbSize.AddString(_T("128 X 128"));
	m_cbbSize.AddString(_T("256 X 256"));
	m_cbbSize.AddString(_T("512 X 512"));
	m_cbbSize.AddString(_T("1024 X 1024"));
	m_cbbSize.AddString(_T("2048 X 2048"));
	m_cbbSize.AddString(_T("4096 X 4096"));
	m_nSizeSel = 0;
	m_cbbSize.SetCurSel(m_nSizeSel);

	UpdateData( FALSE );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
