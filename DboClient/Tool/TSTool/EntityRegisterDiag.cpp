// EntityRegisterDiag.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "EntityRegisterDiag.h"
#include "Attr_Page.h"


// CEntityRegisterDiag ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CEntityRegisterDiag, COptionSheet)

CEntityRegisterDiag::CEntityRegisterDiag(CWnd* pParent /*=NULL*/)
	: COptionSheet(_T("Entity Register Dialog"), pParent)
{

}

CEntityRegisterDiag::~CEntityRegisterDiag()
{
}

CAttr_Page* CEntityRegisterDiag::GetEditedAttrPage( void )
{
	return m_pEditedPage;
}

void CEntityRegisterDiag::AddAttrPage( CAttr_Page* pPage )
{
	AddGroup( pPage );
}

void CEntityRegisterDiag::ClearAttrPage( void )
{
	m_Pages.RemoveAll();
}

INT_PTR CEntityRegisterDiag::DoModal()
{
	return COptionSheet::DoModal();
}

void CEntityRegisterDiag::DoDataExchange(CDataExchange* pDX)
{
	COptionSheet::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEntityRegisterDiag, COptionSheet)
END_MESSAGE_MAP()


// CEntityRegisterDiag �޽��� ó�����Դϴ�.

BOOL CEntityRegisterDiag::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	if ( IDOK == LOWORD( wParam ) && NULL != lParam )
	{
		m_pEditedPage = DYNAMIC_DOWNCAST( CAttr_Page, GetActivePage() );
	}
	else
	{
		m_pEditedPage = NULL;
	}

	return COptionSheet::OnCommand(wParam, lParam);
}
