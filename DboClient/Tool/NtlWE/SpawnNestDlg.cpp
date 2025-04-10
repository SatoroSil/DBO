// SpawnNestDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NtlWE.h"
#include "SpawnNestDlg.h"
#include "NtlWEDoc.h"
#include "SpawnManager.h"


// CSpawnNestDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSpawnNestDlg, CDialog)

CSpawnNestDlg::CSpawnNestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpawnNestDlg::IDD, pParent)
	, m_NestMemberCnt(_T("1"))
	, m_StrPathIndex(_T("-999"))
{

}

CSpawnNestDlg::~CSpawnNestDlg()
{
}

void CSpawnNestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NEST_MEMBER_CNT, m_NestMemberCnt);
	DDX_Text(pDX, IDC_PATH_INDEX, m_StrPathIndex);
}


BEGIN_MESSAGE_MAP(CSpawnNestDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CSpawnNestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSpawnNestDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CSpawnNestDlg �޽��� ó�����Դϴ�.

BOOL CSpawnNestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_NestMemberCnt.Format("%d", GetSpawnInstance()->GetCurNestMemberCnt());

	if(GetSpawnInstance()->GetPathIndex() == -1 || GetSpawnInstance()->GetPathIndex() == -999)
	{
		m_StrPathIndex = _T("@");
	}
	else
	{
		m_StrPathIndex.Format("%d", GetSpawnInstance()->GetPathIndex());
	}

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BOOL CSpawnNestDlg::PreTranslateMessage(MSG* pMsg)
{
	// prevent keys; escape, return
	if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_ESCAPE:
			{
				return true;
				break;
			}
		case VK_RETURN:
			{
				return true;
				break;
			}
		default:
			break;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

LRESULT CSpawnNestDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CLOSE:
		{
			UpdateData(TRUE);

			dGETDOC()->m_CurNestMemberCnt = m_NestMemberCnt;

			break;
		}
	}

	return CDialog::WindowProc(message, wParam, lParam);
}

void CSpawnNestDlg::OnBnClickedOk()	
{
	UpdateData(TRUE);

	dGETDOC()->m_CurNestMemberCnt = m_NestMemberCnt;
	dGETDOC()->m_CurPathIndex = m_StrPathIndex;

	OnOK();
}

void CSpawnNestDlg::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnCancel();
}
