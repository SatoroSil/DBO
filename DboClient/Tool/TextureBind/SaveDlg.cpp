// SaveDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TextureBind.h"
#include "SaveDlg.h"


// CSaveDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSaveDlg, CDialog)

CSaveDlg::CSaveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSaveDlg::IDD, pParent)
	, m_szSavePath(_T(""))
{

}

CSaveDlg::~CSaveDlg()
{
}

void CSaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SAVE_TYPE, m_cbbSaveType);
	DDX_Text(pDX, IDC_EDIT_SAVE_PATH, m_szSavePath);
}


BEGIN_MESSAGE_MAP(CSaveDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_PATH, &CSaveDlg::OnBnClickedButtonSavePath)
	ON_CBN_SELCHANGE(IDC_COMBO_SAVE_TYPE, &CSaveDlg::OnCbnSelchangeComboSaveType)
END_MESSAGE_MAP()


// CSaveDlg �޽��� ó�����Դϴ�.

void CSaveDlg::OnBnClickedButtonSavePath()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	BrInfo.lpszTitle = "���ε� �Ǵ� ���ø��� �� �ؽ��ĵ��� ��ġ�� ������ �����ϼ���.";
	BrInfo.ulFlags = BIF_RETURNONLYFSDIRS;

	// ���̾�α׸� ����
	pidlBrowse = ::SHBrowseForFolder(&BrInfo);   

	if( pidlBrowse != NULL)
	{
		// �н��� ����
		::SHGetPathFromIDList(pidlBrowse, pszPathname);   
		m_szSavePath = pszPathname;

		UpdateData( FALSE );
	}
}

void CSaveDlg::OnCbnSelchangeComboSaveType()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nSaveType = m_cbbSaveType.GetCurSel();
}

BOOL CSaveDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_cbbSaveType.AddString("128 X 128");
	m_cbbSaveType.AddString("256 X 256");
	m_cbbSaveType.AddString("512 X 512");
	m_cbbSaveType.AddString("1024 X 1024");
	m_cbbSaveType.AddString("2048 X 2048");
	m_cbbSaveType.AddString("4096 X 4096");
	m_nSaveType = 0;
	m_cbbSaveType.SetCurSel( m_nSaveType );

	UpdateData( FALSE );


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
