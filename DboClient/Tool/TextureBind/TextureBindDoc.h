// TextureBindDoc.h : CTextureBindDoc Ŭ������ �������̽�
//


#pragma once


class CTextureBindDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CTextureBindDoc();
	DECLARE_DYNCREATE(CTextureBindDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CTextureBindDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


