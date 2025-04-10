// GUIEditorDoc.h : CGUIEditorDoc Ŭ������ �������̽�
//
#pragma once

#include "DataManager.h"

class CGUIEditorDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CGUIEditorDoc();
	DECLARE_DYNCREATE(CGUIEditorDoc)

// Ư��
public:
	CDataManager&	GetDataManager() { return m_DataManager; }
	
// �۾�
public:
	
// ������
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ����
public:
	virtual ~CGUIEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CDataManager	m_DataManager;
	
// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

extern CGUIEditorDoc* g_pDocument;

