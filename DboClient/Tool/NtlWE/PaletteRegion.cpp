// PaletteRegion.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NtlWE.h"
#include "PaletteRegion.h"


// CPaletteRegion ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPaletteRegion, CDialog)
CPaletteRegion::CPaletteRegion(CWnd* pParent /*=NULL*/)
	: CDialog(CPaletteRegion::IDD, pParent)
{
}

CPaletteRegion::~CPaletteRegion()
{
}

void CPaletteRegion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CPaletteRegion::InitializeWorldData()
{
}

BEGIN_MESSAGE_MAP(CPaletteRegion, CDialog)
END_MESSAGE_MAP()


// CPaletteRegion �޽��� ó�����Դϴ�.
