// WorldEditorDoc.cpp : CWorldEditorDoc Ŭ������ ����
//

#include "stdafx.h"
#include "WorldEditor.h"

#include "WorldEditorDoc.h"

#ifdef _DEBUG
	#define new DEBUG_NEW
#endif


// CWorldEditorDoc

IMPLEMENT_DYNCREATE(CWorldEditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CWorldEditorDoc, CDocument)
	ON_COMMAND(ID_FILE_SAVE, CWorldEditorDoc::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, CWorldEditorDoc::OnFileSaveAs)
END_MESSAGE_MAP()


// CWorldEditorDoc ����/�Ҹ�

CWorldEditorDoc::CWorldEditorDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CWorldEditorDoc::~CWorldEditorDoc()
{
}

BOOL CWorldEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ �ٽ� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}


void CWorldEditorDoc::OnFileSave()
{
	theApp.OnFileSave();
}

void CWorldEditorDoc::OnFileSaveAs()
{
	theApp.OnFileSaveAs();
}


// CWorldEditorDoc serialization

void CWorldEditorDoc::Serialize(CArchive& ar)
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


// CWorldEditorDoc ����

#ifdef _DEBUG
void CWorldEditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWorldEditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWorldEditorDoc ���
