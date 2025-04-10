#pragma once


// CMeshListDialog ��ȭ �����Դϴ�.

#include "DataTreeCtrl.h"

class CMeshListDialog : public CDialog
{
	DECLARE_DYNCREATE(CMeshListDialog)

public:
	CMeshListDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMeshListDialog();

	void	SerializeList();

public:
	BOOL					m_Initialized;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MESH_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreTranslateMessage(MSG* pMsg);	
	afx_msg void OnTvnSelchangedMeshList(NMHDR *pNMHDR, LRESULT *pResult);

protected:
    void OnRefresh();                               ///< Mesh List�� �ٽ� �о� ���δ�.

protected:
    CDataTreeCtrl m_MeshList;
};
