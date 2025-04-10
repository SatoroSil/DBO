// UpdateNewsDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "UpdateNewsDialog.h"
#include ".\updatenewsdialog.h"

#include <io.h>
#include <fcntl.h>


// CUpdateNewsDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CUpdateNewsDialog, CDialog)
CUpdateNewsDialog::CUpdateNewsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CUpdateNewsDialog::IDD, pParent)
{
	m_bInitialized	= FALSE;
}

CUpdateNewsDialog::~CUpdateNewsDialog()
{
}

void CUpdateNewsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_UPDATE_NEW, m_UpdateNews);
}


BEGIN_MESSAGE_MAP(CUpdateNewsDialog, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CUpdateNewsDialog �޽��� ó�����Դϴ�.


// COptionDialog �޽��� ó�����Դϴ�.
CUpdateNewsDialog& CUpdateNewsDialog::GetInstance()
{
	static CUpdateNewsDialog dlg;
	return dlg;
}
BOOL CUpdateNewsDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CRect rect;
	GetWindowRect(&rect);
	CPoint posStart;
	posStart.x = GetSystemMetrics(SM_CXSCREEN) / 2 - rect.Width() / 2;
	posStart.y = GetSystemMetrics(SM_CYSCREEN) / 2 - rect.Height() / 2;

	rect.left += posStart.x;
	rect.right += posStart.x;
	rect.top += posStart.y;
	rect.bottom += posStart.y;
	MoveWindow(rect);

	LoadUpdateNews();

	m_bInitialized	= TRUE;

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CUpdateNewsDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_bInitialized == FALSE)
	{
		return;
	}

	int nBlank = 11;
	m_UpdateNews.MoveWindow(nBlank, nBlank, cx - nBlank * 2, cy - nBlank * 2);
}


void CUpdateNewsDialog::LoadUpdateNews()
{
	int handle = open("TOOL\\VenusData\\UpdateNews.txt", O_RDONLY | O_BINARY);
	if (handle == -1) 
	{
		return;
	}

	int len = filelength(handle);

	char* string = new char[len+1];

	memset(string, 0, len+1);
	read(handle, string, len);
	close(handle);

	m_UpdateNews.SetWindowText(string);

	delete [] string;
}
