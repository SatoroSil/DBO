// Attr_Page.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TSTool.h"
#include "Attr_Page.h"


// CAttr_Page ��ȭ �����Դϴ�.


IMPLEMENT_DYNAMIC(CAttr_Page, COptionPage)

CAttr_Page::CAttr_Page(unsigned int uiIDD)
	: COptionPage(uiIDD)
{

}

CAttr_Page::~CAttr_Page()
{
}

CString CAttr_Page::GetAttr( CString strName )
{
	CString strRet;

	int nStart = m_strData.Find( strName );
	if ( nStart < 0 || nStart >= m_strData.GetLength() ) return CString();

	nStart = m_strData.Find( '#', nStart );
	if ( nStart < 0 || nStart >= m_strData.GetLength() ) return CString();

	strRet = m_strData.Tokenize( "#", nStart );
	strRet.Trim();

	return strRet;
}

void CAttr_Page::AddAttr( CString strData )
{
	m_strData += strData;
}

void CAttr_Page::AddAttr( CString strKey, CString strValue )
{
	m_strData += PakingPageData( strKey, strValue );
}

void CAttr_Page::AddAttr( CString strKey, int nValue )
{
	m_strData += PakingPageData( strKey, nValue );
}

void CAttr_Page::ClearAttr( void )
{
	m_strData.Empty();
}

void CAttr_Page::PakingPageData( CString& strResult, CString strKey, CString strValue )
{
	CString strData;
	strData.Format( _T("%s # %s # "), strKey, strValue );

	strResult += strData;
}

CString CAttr_Page::GetPageData( void )
{
	return CString();
}

void CAttr_Page::SetPageData( CString& strData )
{
	enum { eTOKEN_TYPE_KEY, eTOKEN_TYPE_VALUE };

	CString strKey, strValue;

	CString strToken;
	int nStart = 0;
	bool bLoop = true;

	int nTokType = eTOKEN_TYPE_KEY;

	while ( bLoop )
	{
		strToken = strData.Tokenize( _T("#"), nStart );
		if ( nStart >= strData.GetLength() ) bLoop = false;

		switch ( nTokType )
		{
		case eTOKEN_TYPE_KEY:
			{
				strKey = strToken.Trim();
				strValue.Empty();

				nTokType = eTOKEN_TYPE_VALUE;
			}
			break;

		case eTOKEN_TYPE_VALUE:
			{
				strValue = strToken.Trim();

				UnPakingPageData( strKey, strValue );

				strKey.Empty();
				strValue.Empty();

				nTokType = eTOKEN_TYPE_KEY;
			}
			break;
		}
	}

	UpdateData( false );
}

CString	CAttr_Page::PakingPageData( CString strKey, CString strValue )
{
	CString strData;
	strData.Format( _T("%s # %s # "), strKey, strValue );
	return strData;
}

CString CAttr_Page::PakingPageData( CString strKey, DWORD dwValue )
{
	CString strData;
	strData.Format( _T("%s # %d # "), strKey, dwValue );
	return strData;
}

CString CAttr_Page::PakingPageData( CString strKey, int nValue )
{
	CString strData;
	strData.Format( _T("%s # %d # "), strKey, nValue );
	return strData;
}

CString CAttr_Page::PakingPageData( CString strKey, unsigned int uiValue )
{
	CString strData;
	strData.Format( _T("%s # %d # "), strKey, uiValue );
	return strData;
}

CString CAttr_Page::PakingPageData( CString strKey, float fValue )
{
	CString strData;
	strData.Format( _T("%s # %f # "), strKey, fValue );
	return strData;
}

void CAttr_Page::UnPakingPageData( CString& strKey, CString& strValue )
{
}

void CAttr_Page::DoDataExchange(CDataExchange* pDX)
{
	COptionPage::DoDataExchange(pDX);
}

BOOL CAttr_Page::OnInitDialog()
{
	COptionPage::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	if ( m_strData.GetLength() > 0 ) SetPageData( m_strData );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BEGIN_MESSAGE_MAP(CAttr_Page, COptionPage)
END_MESSAGE_MAP()


// CAttr_Page �޽��� ó�����Դϴ�.

void CAttr_Page::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_strData = GetPageData();

	COptionPage::OnOK();
}
