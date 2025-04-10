// InstanceEffectDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "InstanceEffectDialog.h"
#include ".\instanceeffectdialog.h"


#include ".\venusvisualmanager.h"

#include "NtlDebug.h"
#include "NtlInstanceEffect.h"

// CInstanceEffectDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CInstanceEffectDialog, CDialog)
CInstanceEffectDialog::CInstanceEffectDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CInstanceEffectDialog::IDD, pParent)
{
}

CInstanceEffectDialog::~CInstanceEffectDialog()
{
}

void CInstanceEffectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EFFECT_LIST, m_EffectList);
}


BEGIN_MESSAGE_MAP(CInstanceEffectDialog, CDialog)
	ON_WM_SIZE()
	ON_LBN_SELCHANGE(IDC_EFFECT_LIST, OnLbnSelchangeEffectList)
END_MESSAGE_MAP()


// CInstanceEffectDialog �޽��� ó�����Դϴ�.
CInstanceEffectDialog& CInstanceEffectDialog::GetInstance()
{
	static CInstanceEffectDialog dlg;
	return dlg;
}

BOOL CInstanceEffectDialog::OnInitDialog()
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

void CInstanceEffectDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

BOOL CInstanceEffectDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN) 
	{
	}
	return CDialog::PreTranslateMessage(pMsg);
}
void CInstanceEffectDialog::BuildInstanceEffect()
{
	m_EffectList.ResetContent();
}


void CInstanceEffectDialog::OnLbnSelchangeEffectList()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CVenusVisualManager::GetInstance().m_svSelectInstanceEffect.clear();

	int nSelectCount = m_EffectList.GetSelCount();
	if (nSelectCount <= 0) 
	{
		return;
	}

	int* pListIndex = NTL_NEW int[nSelectCount];
	m_EffectList.GetSelItems(nSelectCount, pListIndex);
	for (int i = 0; i < nSelectCount; ++ i)
	{
//		CNtlInstanceEffect* pInstanceEffect = (CNtlInstanceEffect*)m_EffectList.GetItemData(pListIndex[i]);
//		CVenusVisualManager::GetInstance().m_slSelectInstanceEffect.push_back(pInstanceEffect->GetEffectHandle());
	}

	NTL_ARRAY_DELETE(pListIndex);
}
