// ProgressDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "ProgressDialog.h"
#include ".\progressdialog.h"


// CProgressDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CProgressDialog, CDialog)
CProgressDialog::CProgressDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressDialog::IDD, pParent)
	, m_strPercent(_T(""))
{
	m_nCurrentTime = 0;
	m_nMaxTime = 0;
}

CProgressDialog::~CProgressDialog()
{
}

void CProgressDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS, m_Progress);
	DDX_Text(pDX, IDC_PERCENT, m_strPercent);
}


BEGIN_MESSAGE_MAP(CProgressDialog, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CProgressDialog �޽��� ó�����Դϴ�.

BOOL CProgressDialog::OnInitDialog()
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

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CProgressDialog::OnTimer(UINT nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch(nIDEvent)
	{
	case 0:
		{
			m_nCurrentTime += 20;
			if (m_nCurrentTime > m_nMaxTime)
			{
				KillTimer(nIDEvent);
				ShowWindow(SW_HIDE);
			}
			else
			{
				m_Progress.SetPos(m_nCurrentTime);
				m_strPercent.Format("%d / %d", m_nCurrentTime, m_nMaxTime);
				UpdateData(FALSE);
			}
		}
		break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CProgressDialog::Start(char* pWindowTitle, int nMaxTime)
{
	CString strWindowTitle;
	strWindowTitle.Format("%s File Saving..", pWindowTitle);
	SetWindowText(strWindowTitle);

	m_nCurrentTime = 0;
	m_nMaxTime = nMaxTime;
	m_Progress.SetRange(0, nMaxTime);
	m_Progress.SetPos(m_nCurrentTime);

	m_strPercent = "";

	ShowWindow(SW_SHOW);
	SetTimer(0, 10, NULL);
}

CProgressDialog& CProgressDialog::GetInstance()
{
	static CProgressDialog dlg;
	return dlg;
}
