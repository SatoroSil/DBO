// PaletteUnit.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NtlWE.h"
#include "PaletteUnit.h"


// CPaletteUnit ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPaletteUnit, CDialog)
CPaletteUnit::CPaletteUnit(CWnd* pParent /*=NULL*/)
	: CDialog(CPaletteUnit::IDD, pParent)
{
}

CPaletteUnit::~CPaletteUnit()
{
}

void CPaletteUnit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CPaletteUnit::InitializeWorldData()
{
}

BEGIN_MESSAGE_MAP(CPaletteUnit, CDialog)
END_MESSAGE_MAP()


// CPaletteUnit �޽��� ó�����Դϴ�.
