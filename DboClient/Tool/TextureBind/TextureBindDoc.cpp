// TextureBindDoc.cpp : CTextureBindDoc Ŭ������ ����
//

#include "stdafx.h"
#include "TextureBind.h"

#include "TextureBindDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextureBindDoc

IMPLEMENT_DYNCREATE(CTextureBindDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextureBindDoc, CDocument)
END_MESSAGE_MAP()


// CTextureBindDoc ����/�Ҹ�

CTextureBindDoc::CTextureBindDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CTextureBindDoc::~CTextureBindDoc()
{
}

BOOL CTextureBindDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CTextureBindDoc serialization

void CTextureBindDoc::Serialize(CArchive& ar)
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


// CTextureBindDoc ����

#ifdef _DEBUG
void CTextureBindDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextureBindDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTextureBindDoc ���
