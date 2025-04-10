#pragma once
#include "afxwin.h"
#include "NtlWorldFileMemAccessor.h"

// CFieldSearchDlg ��ȭ �����Դϴ�.

//////////////////////////////////////////////////////////////////////////
// dNTL_WORLD_FILE : DEFINE
//////////////////////////////////////////////////////////////////////////
#ifdef dNTL_WORLD_FILE

class CFieldSearchDlg : public CDialog
{
	DECLARE_DYNAMIC(CFieldSearchDlg)

public:
	CFieldSearchDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFieldSearchDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SEARCH };

	enum ESEARCHLIST_FIELD
	{
		ESEARCHLIST_FIELD_INDEX,
		ESEARCHLIST_FIELD_TYPE,
		ESEARCHLIST_FIELD_NAME,
		ESEARCHLIST_FIELD_POS_X,
		ESEARCHLIST_FIELD_POS_Y,
		ESEARCHLIST_FIELD_POS_Z,
		
		ESEARCHLIST_FIELD_NUM,
	};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	std::vector<RwInt32>	m_vecFieldIdx;

	CString					m_strSearch;
	CListCtrl				m_listSearch;
	RwBool					m_AscendingSortFlags[ESEARCHLIST_FIELD_NUM];
	CString					m_strFieldIdx;
	BOOL					m_bSearchObject;
	BOOL					m_bSearchEffect;
	BOOL					m_bSearchSE;
	BOOL					m_bSearchFieldAll;
	CString					m_strSelectError;

public:
	virtual BOOL			PreTranslateMessage(MSG* pMsg);
	virtual BOOL			OnInitDialog();

	afx_msg void			OnBnClickedOk();
	afx_msg void			OnBnClickedCancel();
	afx_msg void			OnLvnColumnClickList(NMHDR *pNMHDR, LRESULT *pResult);

	void					InitFieldSearch();

protected:
	void					UpdateSearchList();
	void					AddSearchList(RwInt32 iFieldIdx, char* pcType, char* pcName, RwV3d* pvPos);

	RwBool					IsInString(char* pSrc, char* pCmp);
	RwBool					OnSortData(RwInt32 _Index);

	void					Search(RwInt32 iFieldIdx);

	
public:
	afx_msg void OnBnClickedCheckObject();
	afx_msg void OnBnClickedCheckEffect();
	afx_msg void OnBnClickedCheckSe();
	afx_msg void OnBnClickedSearchPortal();
	CString m_strListCnt;
	afx_msg void OnLvnItemchangedSearchList(NMHDR *pNMHDR, LRESULT *pResult);
};

//////////////////////////////////////////////////////////////////////////
// dNTL_WORLD_FILE : DEFINE
//////////////////////////////////////////////////////////////////////////
#else

class CFieldSearchDlg : public CDialog, public CNtlWorldFileMemAccessor
{
	DECLARE_DYNAMIC(CFieldSearchDlg)

public:
	CFieldSearchDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFieldSearchDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SEARCH };

	enum ESEARCHLIST_FIELD
	{
		ESEARCHLIST_FIELD_INDEX,
		ESEARCHLIST_FIELD_TYPE,
		ESEARCHLIST_FIELD_NAME,
		ESEARCHLIST_FIELD_POS_X,
		ESEARCHLIST_FIELD_POS_Y,
		ESEARCHLIST_FIELD_POS_Z,

		ESEARCHLIST_FIELD_NUM,
	};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	std::vector<RwInt32>	m_vecFieldIdx;

	CString					m_strSearch;
	CListCtrl				m_listSearch;
	RwBool					m_AscendingSortFlags[ESEARCHLIST_FIELD_NUM];
	CString					m_strFieldIdx;
	BOOL					m_bSearchObject;
	BOOL					m_bSearchEffect;
	BOOL					m_bSearchSE;
	BOOL					m_bSearchFieldAll;
	CString					m_strSelectError;

public:
	virtual BOOL			PreTranslateMessage(MSG* pMsg);
	virtual BOOL			OnInitDialog();

	afx_msg void			OnBnClickedOk();
	afx_msg void			OnBnClickedCancel();
	afx_msg void			OnLvnColumnClickList(NMHDR *pNMHDR, LRESULT *pResult);

	void					InitFieldSearch();

protected:
	void					UpdateSearchList();
	void					AddSearchList(RwInt32 iFieldIdx, char* pcType, char* pcName, RwV3d* pvPos);

	RwBool					IsInString(char* pSrc, char* pCmp);
	RwBool					OnSortData(RwInt32 _Index);

	void					Search(RwInt32 iFieldIdx);


public:
	afx_msg void OnBnClickedCheckObject();
	afx_msg void OnBnClickedCheckEffect();
	afx_msg void OnBnClickedCheckSe();
	afx_msg void OnBnClickedSearchPortal();
	CString m_strListCnt;
	afx_msg void OnLvnItemchangedSearchList(NMHDR *pNMHDR, LRESULT *pResult);
};

//////////////////////////////////////////////////////////////////////////
// dNTL_WORLD_FILE : DEFINE
//////////////////////////////////////////////////////////////////////////
#endif