// WorldEditorDoc.h : CWorldEditorDoc Ŭ������ �������̽�
//


#pragma once

class CWorldEditorDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CWorldEditorDoc();
	
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	DECLARE_DYNCREATE(CWorldEditorDoc)

// Ư��
public:

// �۾�
public:

// ������
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ����
public:
	virtual ~CWorldEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};


