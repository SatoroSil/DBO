// CharacterEditorDoc.h : CCharacterEditorDoc Ŭ������ �������̽�
//


#pragma once

class CCharacterEditorDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CCharacterEditorDoc();
	DECLARE_DYNCREATE(CCharacterEditorDoc)

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
	virtual ~CCharacterEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};


