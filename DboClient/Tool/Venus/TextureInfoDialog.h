#pragma once
#include "afxwin.h"


// CTextureInfoDialog ��ȭ �����Դϴ�.
#include "rwcore.h"

#include "libgfl.h"

class CTextureInfoDialog : public CDialog
{
	DECLARE_DYNCREATE(CTextureInfoDialog)

public:
	CTextureInfoDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTextureInfoDialog();

	void	CreateBitmap(const RwChar* strPathName);

public:
	BOOL					m_Initialized;

	GFL_BITMAP*				m_pGflBitmap;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TEXTURE_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_TextureScreen;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_nTextureWidth;
	int m_nTextureHeight;
};
