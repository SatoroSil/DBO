#pragma once



// CControlView �� ���Դϴ�.

class CControlView : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CControlView)

protected:
	CControlView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CControlView();

public:
	enum { IDD = IDD_CONTROL_PANE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};


