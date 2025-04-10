#pragma once


// CTextureLayer ���Դϴ�.
#include "rwcore.h"

#include "RollupCtrl.h"

class CTextureLayer : public CView
{
	DECLARE_DYNCREATE(CTextureLayer)

protected:
	CTextureLayer();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CTextureLayer();

public:
	void	CreateBitmap(const RwChar* strPathName);

	void	BuildTextureList();

public:
	enum EDIT_DIALOG
	{
		EDIT_DIALOG_TEXTURE_LIST = 0x00,
		EDIT_DIALOG_TEXTURE_INFO,
	};

	BOOL					m_bInitialized;
	CRollupCtrl				m_RollupControl;

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};


