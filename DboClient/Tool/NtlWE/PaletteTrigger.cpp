// PaletteTrigger.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NtlWE.h"
#include "PaletteTrigger.h"


// CPaletteTrigger ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPaletteTrigger, CDialog)
CPaletteTrigger::CPaletteTrigger(CWnd* pParent /*=NULL*/)
	: CDialog(CPaletteTrigger::IDD, pParent)
{
}

CPaletteTrigger::~CPaletteTrigger()
{
}

void CPaletteTrigger::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CPaletteTrigger::InitializeWorldData()
{
}

BEGIN_MESSAGE_MAP(CPaletteTrigger, CDialog)
END_MESSAGE_MAP()


// CPaletteTrigger �޽��� ó�����Դϴ�.
