// CharacterEditorDoc.cpp : CCharacterEditorDoc Ŭ������ ����
//

#include "stdafx.h"
#include "CharacterEditor.h"

#include "CharacterEditorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCharacterEditorDoc

IMPLEMENT_DYNCREATE(CCharacterEditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CCharacterEditorDoc, CDocument)
END_MESSAGE_MAP()


// CCharacterEditorDoc ����/�Ҹ�

CCharacterEditorDoc::CCharacterEditorDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CCharacterEditorDoc::~CCharacterEditorDoc()
{
}

BOOL CCharacterEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ �ٽ� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CCharacterEditorDoc serialization

void CCharacterEditorDoc::Serialize(CArchive& ar)
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


// CCharacterEditorDoc ����

#ifdef _DEBUG
void CCharacterEditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCharacterEditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCharacterEditorDoc ���
