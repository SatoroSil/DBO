// ControlView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DTEditor.h"
#include "ControlView.h"


// CControlView

IMPLEMENT_DYNCREATE(CControlView, CXTResizeFormView)

CControlView::CControlView()
	: CXTResizeFormView(CControlView::IDD)
{

}

CControlView::~CControlView()
{
}

void CControlView::DoDataExchange(CDataExchange* pDX)
{
	CXTResizeFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CControlView, CXTResizeFormView)
END_MESSAGE_MAP()


// CControlView �����Դϴ�.

#ifdef _DEBUG
void CControlView::AssertValid() const
{
	CXTResizeFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CControlView::Dump(CDumpContext& dc) const
{
	CXTResizeFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CControlView �޽��� ó�����Դϴ�.
