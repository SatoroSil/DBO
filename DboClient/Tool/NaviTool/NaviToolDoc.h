// NaviToolDoc.h : CNaviToolDoc Ŭ������ �������̽�
//


#pragma once


class CNaviToolDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CNaviToolDoc();
	DECLARE_DYNCREATE(CNaviToolDoc)

// Ư���Դϴ�.
public:
	CString m_strPath;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CNaviToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnLoadWorldData();
	afx_msg void OnSavePathData();
	afx_msg void OnLoadPathData();
	afx_msg void OnProjectViewTotalMemory();
};


