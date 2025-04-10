#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "NtlMtXml.h"

#include "NtlPLDojo.h"

// CPaletteDojoDlg ��ȭ �����Դϴ�.

class CPaletteDojoDlg : public CDialog
{
	DECLARE_DYNAMIC(CPaletteDojoDlg)

public:
	CPaletteDojoDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteDojoDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ORNAMENT_DOJO };

protected:
	virtual void				DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL				PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()

public:
	void						InitializeWorldData();

protected:
	virtual LRESULT				WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

public:
	afx_msg void				OnBnClickedOk();
	afx_msg void				OnBnClickedCancel();

	afx_msg void				OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void				OnLbnSelchangeListLevel();

public:
	void						UpdatePropertyData(const CNtlPLEntity* pEntity);

	void						InsertItemRecursive(SItemNode* pItemNode, HTREEITEM hParentItem);	

	void						UpdatePreview();
	void						RenderPreview();

	SPLDojoCreateParam*			GetCreateParam(CNtlPLEntity* pEntity);


public:
	CNtlPLDojo*					m_pPLDojoCur;
	SPLDojoCreateParam			m_sDojoCreateParam;

	HTREEITEM					m_hRoot;
	CTreeCtrl					m_TreeOrnament;
	CListBox					m_listLevel;

	CString						m_strTapMovementEdit;
	CString						m_strRotTabValue;
	CString						m_StrScaleValue;
	CString						m_CurDoodadScaleX;
	CString						m_CurDoodadScaleY;
	CString						m_CurDoodadScaleZ;
	
};
