#pragma once



// CGUIControlView �� ���Դϴ�.

class CGUIControlView : public CFormView
{
	DECLARE_DYNCREATE(CGUIControlView)

protected:
	CGUIControlView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CGUIControlView();

public:
	enum { IDD = IDD_FORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CGUIControlView* g_pControlView;

