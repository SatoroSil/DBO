// PropTreeInfo.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "PropTreeInfo.h"

#include "PropTree.h"
#include ".\proptreeinfo.h"

// CPropTreeInfo

IMPLEMENT_DYNAMIC(CPropTreeInfo, CStatic)
CPropTreeInfo::CPropTreeInfo() :
	m_pProp(NULL)
{
}

CPropTreeInfo::~CPropTreeInfo()
{
}


BEGIN_MESSAGE_MAP(CPropTreeInfo, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CPropTreeInfo �޽��� ó�����Դϴ�.


void CPropTreeInfo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
	CRect rc;

	GetClientRect(rc);

	dc.SelectObject(GetSysColorBrush(COLOR_BTNFACE));
	dc.PatBlt(rc.left, rc.top, rc.Width(), rc.Height(), PATCOPY);

	dc.DrawEdge(&rc, BDR_SUNKENOUTER, BF_RECT);
	rc.DeflateRect(4, 4);

	ASSERT(m_pProp!=NULL);

	CPropTreeItem* pItem = m_pProp->GetFocusedItem();

	if (!m_pProp->IsWindowEnabled())
		dc.SetTextColor(GetSysColor(COLOR_GRAYTEXT));
	else
		dc.SetTextColor(GetSysColor(COLOR_BTNTEXT));

	dc.SetBkMode(TRANSPARENT);
	dc.SelectObject(m_pProp->GetBoldFont());

	CString txt;

	if (!pItem)
		txt.LoadString(IDS_NOITEMSEL);
	else
		txt = pItem->GetLabelText();

	CRect ir;
	ir = rc;

	// draw label
	dc.DrawText(txt, &ir, DT_SINGLELINE|DT_CALCRECT);
	dc.DrawText(txt, &ir, DT_SINGLELINE);

	ir.top = ir.bottom;
	ir.bottom = rc.bottom;
	ir.right = rc.right;

	if (pItem)
		txt = pItem->GetInfoText();
	else
		txt.LoadString(IDS_SELFORINFO);

	dc.SelectObject(m_pProp->GetNormalFont());
	dc.DrawText(txt, &ir, DT_WORDBREAK);
}


void CPropTreeInfo::SetPropOwner(CPropTree* pProp)
{
	m_pProp = pProp;
}