// TextureConverterDoc.cpp : CTextureConverterDoc Ŭ������ ����
//

#include "stdafx.h"
#include "TextureConverter.h"

#include "TextureConverterDoc.h"
#include ".\textureconverterdoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextureConverterDoc

IMPLEMENT_DYNCREATE(CTextureConverterDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextureConverterDoc, CDocument)
END_MESSAGE_MAP()


// CTextureConverterDoc ����/�Ҹ�

CTextureConverterDoc::CTextureConverterDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

	m_sConverFlag.ReadFromIni( _T( "Convert.ini" ) ); 
	
//	m_sConverFlag.nMipLevel = 1;
//	m_sConverFlag.cFormat = _T( "D3DFMT_L8" );

}

CTextureConverterDoc::~CTextureConverterDoc()
{
}

BOOL CTextureConverterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ �ٽ� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	CFileFind		FileFinder;

	if( m_sConverFlag.cInputPath.GetLength() )
	{
		SetCurrentDirectory( m_sConverFlag.cInputPath.GetBuffer() );
	}

	BOOL	bWorking = FileFinder.FindFile( m_sConverFlag.cFilter.GetBuffer() );
	while( bWorking )
	{
		bWorking = FileFinder.FindNextFile();

		ConvertFile( FileFinder.GetFileName() );
	}

	return TRUE;
}


// CTextureConverterDoc serialization

void CTextureConverterDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CTextureConverterDoc ����

#ifdef _DEBUG
void CTextureConverterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextureConverterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTextureConverterDoc ���

BOOL CTextureConverterDoc::ConvertFile(CString & rcFileName)
{
	m_cFileNameList.AddTail( rcFileName );
	CString		Command;

	if( m_sConverFlag.cInputPath.GetLength() == 0 )
	{
		if( m_sConverFlag.cOutputPath.GetLength() == 0 )
		{
			Command.Format( _T( "texconv %s %s" ), m_sConverFlag.cFlagString.GetBuffer(), rcFileName.GetBuffer() );
		}
		else
		{
			Command.Format( _T( "texconv %s -o %s %s" ), m_sConverFlag.cFlagString.GetBuffer(), m_sConverFlag.cOutputPath.GetBuffer(), rcFileName.GetBuffer() );
		}
	}
	else
	{
		if( m_sConverFlag.cOutputPath.GetLength() == 0 )
		{
			Command.Format( _T( "..\\texconv %s %s" ), m_sConverFlag.cFlagString.GetBuffer(), rcFileName.GetBuffer() );
		}
		else
		{
			Command.Format( _T( "..\\texconv %s -o ..\\%s %s" ), m_sConverFlag.cFlagString.GetBuffer(), m_sConverFlag.cOutputPath.GetBuffer(), rcFileName.GetBuffer() );
		}
	}

	system( Command.GetBuffer() );

/*	STARTUPINFO				StartupInfo;
	PROCESS_INFORMATION		ProcessInfo;

	ZeroMemory( &StartupInfo, sizeof( STARTUPINFO ) );
	StartupInfo.cb = sizeof( STARTUPINFO );

	ZeroMemory( &ProcessInfo, sizeof( PROCESS_INFORMATION ) );

	if( CreateProcess( NULL, Command.GetBuffer(),
					NULL, NULL, FALSE,
					NORMAL_PRIORITY_CLASS, NULL, NULL,
					&StartupInfo, &ProcessInfo ) == FALSE )
	{
		DWORD dwErr = GetLastError();
		return FALSE;
	}*/

	return TRUE;
}

const CString * CTextureConverterDoc::GetFileName(int nFileIndex) const
{
	if( nFileIndex >= GetFileCount() )
		return NULL;
	
	return &(m_cFileNameList.GetAt( m_cFileNameList.FindIndex( nFileIndex ) ));
}

int CTextureConverterDoc::GetFileCount(void) const
{
	return m_cFileNameList.GetCount();
}
