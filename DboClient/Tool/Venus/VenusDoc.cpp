// VenusDoc.cpp : CVenusDoc Ŭ������ ����
//

#include "stdafx.h"
#include "Venus.h"

#include "VenusDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVenusDoc

IMPLEMENT_DYNCREATE(CVenusDoc, CDocument)

BEGIN_MESSAGE_MAP(CVenusDoc, CDocument)
END_MESSAGE_MAP()


// CVenusDoc ����/�Ҹ�

CVenusDoc::CVenusDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CVenusDoc::~CVenusDoc()
{
}

BOOL CVenusDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ �ٽ� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CVenusDoc serialization

void CVenusDoc::Serialize(CArchive& ar)
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


// CVenusDoc ����

#ifdef _DEBUG
void CVenusDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVenusDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CVenusDoc ���
