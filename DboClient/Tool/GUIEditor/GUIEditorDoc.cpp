// GUIEditorDoc.cpp : CGUIEditorDoc Ŭ������ ����
//

#include "stdafx.h"
#include "GUIEditor.h"

#include "GUIEditorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CGUIEditorDoc* g_pDocument = NULL;


// CGUIEditorDoc

IMPLEMENT_DYNCREATE(CGUIEditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CGUIEditorDoc, CDocument)
END_MESSAGE_MAP()


// CGUIEditorDoc ����/�Ҹ�

CGUIEditorDoc::CGUIEditorDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	g_pDocument = this;
}

CGUIEditorDoc::~CGUIEditorDoc()
{
}

BOOL CGUIEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ �ٽ� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CGUIEditorDoc serialization

void CGUIEditorDoc::Serialize(CArchive& ar)
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


// CGUIEditorDoc ����

#ifdef _DEBUG
void CGUIEditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGUIEditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGUIEditorDoc ���
