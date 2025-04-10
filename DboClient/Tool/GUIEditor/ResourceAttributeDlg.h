#pragma once

#include "Control/PropTree.h"
#include "GUIEditorDoc.h"

// CResourceAttributeDlg ��ȭ �����Դϴ�.

class CResourceAttributeDlg : public CDialog
{
	DECLARE_DYNCREATE(CResourceAttributeDlg)

public:
	CResourceAttributeDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CResourceAttributeDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_RESOURCEATTRIBUTEDLG };

	enum PROPERTY_ID
	{
		PROPERTY_NONE = 0,

		PROPERTY_CAPTION,
		PROPERTY_RESOURCENAME,
		PROPERTY_HANDLE,
		PROPERTY_FILENAME
	};

public:
	void	SetBlank();
	void	SetFileName( LPCTSTR szFileName );
	void	FillResourceProperty( RESOURCEDATA* pResourceData );

protected:
	CPropTree	m_PropertyTree;
	BOOL		m_bInitialized;

protected:
	// Internal Function
	void	InitProperty();		// �׸� ����.

	void	AddCaptionToList();	// List ǥ��
	void	AddData();			// Data�� ����Ʈ�� �߰�.
	BOOL	InputData( RESOURCEDATA* pResourceData, BOOL bFix = FALSE );	// ������ �Է�.
	BOOL	InputCheck( RESOURCEDATA* pResourceData, BOOL bFIX = FALSE );	// ������ üũ.

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedAddResourlist();
protected:

public:
	afx_msg void OnBnClickedFixResourcelist();
};
