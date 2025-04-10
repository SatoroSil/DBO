// Attr_COND_DistNPC.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_COND_DistNPC.h"


// CAttr_COND_DistNPC ��ȭ �����Դϴ�.

IMPLEMENT_SERIAL(CAttr_COND_DistNPC, CAttr_Page, 1)

CAttr_COND_DistNPC::CAttr_COND_DistNPC()
	: CAttr_Page(CAttr_COND_DistNPC::IDD)
	, m_fDistance( 0.f )
{

}

CAttr_COND_DistNPC::~CAttr_COND_DistNPC()
{
}

CString CAttr_COND_DistNPC::GetPageData( void )
{
	UpdateData( true );

	CString strData;

	strData += PakingPageData( _T("dist"), m_fDistance );
	strData += PakingPageData( _T("idxlist"), m_strNPCList );

	return strData;
}

void CAttr_COND_DistNPC::UnPakingPageData( CString& strKey, CString& strValue )
{
	if ( _T("dist") == strKey )
	{
		m_fDistance = atof( strValue.GetBuffer() );
	}
	else if ( _T("idxlist") == strKey )
	{
		m_strNPCList = strValue.GetBuffer();
	}
}

void CAttr_COND_DistNPC::DoDataExchange(CDataExchange* pDX)
{
	CAttr_Page::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TS_COND_ATTR_DIST_NPC_DIST_EDITOR, m_fDistance);
	DDX_Text(pDX, IDC_TS_COND_ATTR_DIST_NPC_NPCLIST_EDITOR, m_strNPCList);
}


BEGIN_MESSAGE_MAP(CAttr_COND_DistNPC, CAttr_Page)
END_MESSAGE_MAP()


// CAttr_COND_DistNPC �޽��� ó�����Դϴ�.
