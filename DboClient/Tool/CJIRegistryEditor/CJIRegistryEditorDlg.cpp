// CJIRegistryEditorDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CJIRegistryEditor.h"
#include "CJIRegistryEditorDlg.h"

#include <string>
#include "DirDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CCJIRegistryEditorDlg ��ȭ ����




CCJIRegistryEditorDlg::CCJIRegistryEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCJIRegistryEditorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCJIRegistryEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_CtrEditor);
}

BEGIN_MESSAGE_MAP(CCJIRegistryEditorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CCJIRegistryEditorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCJIRegistryEditorDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCJIRegistryEditorDlg �޽��� ó����

void RemoveBackSlash( CString& strString )
{
	if ( strString.IsEmpty() )
	{
		return;
	}

	std::string strTemp = strString;

	if ( strTemp[strTemp.size() - 1] == _T('\\') )
	{
		strTemp.erase( strTemp.end() - 1 );
	}

	strString = strTemp.c_str();
}

BOOL CCJIRegistryEditorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	CString strCurDir;

	{
		HKEY hKey = HKEY_LOCAL_MACHINE; 
		HKEY hkResult; 

		CString strKey = _T("Software\\Netmarble\\NetmarbleDBO");

		LONG ret = RegOpenKeyEx( hKey, strKey, 0, KEY_ALL_ACCESS, &hkResult );

		if ( ERROR_SUCCESS == ret )
		{
			CString strValue	= _T("DestDir");

			DWORD dwType;
			TCHAR szData[4096];
			DWORD dwDataSize;

			ret = RegQueryValueEx( hkResult, strValue, 0, &dwType, (BYTE*)szData, &dwDataSize );

			if ( ERROR_SUCCESS == ret )
			{
				strCurDir = szData;

				RemoveBackSlash( strCurDir );
			}

			RegCloseKey( hkResult );
		}
	}

	if ( !strCurDir.IsEmpty() )
	{
		m_CtrEditor.SetWindowText( strCurDir );
	}

	m_strDBODir = strCurDir;

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CCJIRegistryEditorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CCJIRegistryEditorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CCJIRegistryEditorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCJIRegistryEditorDlg::OnBnClickedButton1()
{
	TCHAR szCurDir[4096];
	GetCurrentDirectory( 4096, szCurDir );

	CString strCurDir = szCurDir;

	RemoveBackSlash( strCurDir );

	{
		HKEY hKey = HKEY_LOCAL_MACHINE; 
		HKEY hkResult; 

		CString strKey = _T("Software\\Netmarble\\NetmarbleDBO");

		LONG ret = RegOpenKeyEx( hKey, strKey, 0, KEY_ALL_ACCESS, &hkResult );

		if ( ERROR_SUCCESS == ret )
		{
			CString strValue	= _T("DestDir");

			DWORD dwType;
			TCHAR szData[4096];
			DWORD dwDataSize;

			ret = RegQueryValueEx( hkResult, strValue, 0, &dwType, (BYTE*)szData, &dwDataSize );

			if ( ERROR_SUCCESS == ret )
			{
				strCurDir = szData;

				RemoveBackSlash( strCurDir );
			}

			RegCloseKey( hkResult );
		}
	}

	CDirDialog clDir( strCurDir );

	if ( IDOK != clDir.DoModal() )
	{
		return;
	}

	CString strDBODir = clDir.GetPath();

	if ( strDBODir.IsEmpty() )
	{
		return;
	}

	RemoveBackSlash( strDBODir );

	m_strDBODir = strDBODir;

	m_CtrEditor.SetWindowText( strDBODir );
}

void CCJIRegistryEditorDlg::OnBnClickedButton2()
{
	if ( m_strDBODir.IsEmpty() )
	{
		return;
	}

	RemoveBackSlash( m_strDBODir );

	CString strDBOLauncher = m_strDBODir + _T("\\DBOLauncher.exe");

	{
		HKEY hKey = HKEY_LOCAL_MACHINE; 
		HKEY hkResult;
		DWORD dwState;

		CString strKey = _T("Software\\Netmarble\\NetmarbleDBO");

		LONG ret = RegCreateKeyEx( hKey, strKey, NULL, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hkResult, &dwState );

		if ( ERROR_SUCCESS != ret )
		{
			return;
		}

		CString strValue	= _T("DestDir");
		CString strData		= m_strDBODir;

		ret = RegSetValueEx( hkResult, strValue, NULL, REG_SZ, (const BYTE*)((LPCTSTR)strData), (DWORD)strData.GetLength() );

		if ( ERROR_SUCCESS != ret )
		{
			RegCloseKey( hkResult );
			return;
		}

		strValue			= _T("RunFileName");
		strData				= strDBOLauncher;

		ret = RegSetValueEx( hkResult, strValue, NULL, REG_SZ, (const BYTE*)((LPCTSTR)strData), (DWORD)strData.GetLength() );

		if ( ERROR_SUCCESS != ret )
		{
			RegCloseKey( hkResult );
			return;
		}

		RegCloseKey( hkResult );
	}

	AfxMessageBox( _T("���������� ���� �Ǿ����ϴ�") );
}
