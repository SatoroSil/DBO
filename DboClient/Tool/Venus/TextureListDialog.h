#pragma once
#include "afxcmn.h"


// CTextureListDialog ��ȭ �����Դϴ�.
#include "DataTreeCtrl.h"

class CTextureListDialog : public CDialog
{
	DECLARE_DYNCREATE(CTextureListDialog)

public:
	CTextureListDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTextureListDialog();

	void	SerializeList();

public:
	BOOL					m_Initialized;


// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TEXTURE_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);	
	afx_msg void OnTvnSelchangedTextureList(NMHDR *pNMHDR, LRESULT *pResult);

protected:
    void OnRefreshList();                           ///< Texture List�� Refresh�Ѵ�.

protected:
    CDataTreeCtrl m_TextureList;
};
