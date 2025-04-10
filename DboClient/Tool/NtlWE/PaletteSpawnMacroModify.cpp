// PaletteSpawnMacroModify.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NtlWE.h"
#include "PaletteSpawnMacroModify.h"
#include "SpawnMacro.h"
#include "SpawnManager.h"


// CPaletteSpawnMacroModify ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPaletteSpawnMacroModify, CDialog)

CPaletteSpawnMacroModify::CPaletteSpawnMacroModify(CWnd* pParent /*=NULL*/)
	: CDialog(CPaletteSpawnMacroModify::IDD, pParent)
	, m_StrCoolTime(_T("1"))
	, m_StrWanderRange(_T("1.0"))
	, m_StrMoveRange(_T("1.0"))
	, m_StrDelayTime(_T("1.0"))
{

}

CPaletteSpawnMacroModify::~CPaletteSpawnMacroModify()
{
}

void CPaletteSpawnMacroModify::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COOLTIME, m_StrCoolTime);
	DDX_Text(pDX, IDC_WANDER_RANGE, m_StrWanderRange);
	DDX_Text(pDX, IDC_MOVE_RANGE, m_StrMoveRange);
	DDX_Text(pDX, IDC_DELAY_TIME, m_StrDelayTime);
	DDX_Control(pDX, IDC_MOVETYPE, m_MoveTypeCombo);
}


BEGIN_MESSAGE_MAP(CPaletteSpawnMacroModify, CDialog)
	ON_BN_CLICKED(IDOK, &CPaletteSpawnMacroModify::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPaletteSpawnMacroModify::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_MOVETYPE, &CPaletteSpawnMacroModify::OnCbnSelchangeMovetype)
END_MESSAGE_MAP()


// CPaletteSpawnMacroModify �޽��� ó�����Դϴ�.

BOOL CPaletteSpawnMacroModify::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0,	SWP_NOMOVE | SWP_NOSIZE);

	m_MoveTypeCombo.SetCurSel(0);

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BOOL CPaletteSpawnMacroModify::PreTranslateMessage(MSG* pMsg)
{
	switch(pMsg->wParam)
	{
	case VK_ESCAPE:
		{
			return true;
		}
	case VK_RETURN:
		{
			return true;
		}
	default:
		break;
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CPaletteSpawnMacroModify::OnBnClickedOk()
{
	UpdateData(TRUE);
	
	// ������ �Ӽ��� ���õǾ� �ִ� ��� ����������Ʈ ��ũ�ο� �����Ѵ�.
	CSpawnMacro CurSpawnMacro;
	CurSpawnMacro.m_CoolTime	= atoi(m_StrCoolTime.GetBuffer(0));
	CurSpawnMacro.m_MoveType	= m_MoveTypeCombo.GetCurSel();
	CurSpawnMacro.m_WanderRange = static_cast<RwReal>(atof(m_StrWanderRange.GetBuffer(0)));
	CurSpawnMacro.m_MoveRange	= static_cast<RwReal>(atof(m_StrMoveRange.GetBuffer(0)));
	CurSpawnMacro.m_DelayTime	= static_cast<RwReal>(atof(m_StrDelayTime.GetBuffer(0)));

	if(!GetSpawnInstance()->SetSpawnMacroToCurSpawns(CurSpawnMacro))
	{
		AfxMessageBox("plz select spawns first");
	}

	OnOK();
}

void CPaletteSpawnMacroModify::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnCancel();
}

void CPaletteSpawnMacroModify::OnCbnSelchangeMovetype()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
