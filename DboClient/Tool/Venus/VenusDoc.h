// VenusDoc.h : CVenusDoc Ŭ������ �������̽�
//


#pragma once

class CVenusDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CVenusDoc();
	DECLARE_DYNCREATE(CVenusDoc)

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
	virtual ~CVenusDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};


