// PalettePerformanceImposter.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NtlWE.h"
#include "PalettePerformanceImposter.h"


// CPalettePerformanceImposter ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPalettePerformanceImposter, CDialog)

CPalettePerformanceImposter::CPalettePerformanceImposter(CWnd* pParent /*=NULL*/)
	: CDialog(CPalettePerformanceImposter::IDD, pParent)
{

}

CPalettePerformanceImposter::~CPalettePerformanceImposter()
{
}

void CPalettePerformanceImposter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPalettePerformanceImposter, CDialog)
END_MESSAGE_MAP()


// CPalettePerformanceImposter �޽��� ó�����Դϴ�.

BOOL CPalettePerformanceImposter::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BOOL CPalettePerformanceImposter::PreTranslateMessage(MSG* pMsg)
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

void CPalettePerformanceImposter::InitializeWorldData()
{

}