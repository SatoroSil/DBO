#pragma once


// CMPPLogView ���Դϴ�.

class CMPPLogView : public CRichEditView
{
	DECLARE_DYNCREATE(CMPPLogView)

protected:
	CMPPLogView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CMPPLogView();

    static CMPPLogView* m_pInstance;

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
    static CMPPLogView* GetInstance() {return m_pInstance;}

    void AddLog(const CString& strLog);    
    void SetOwnerPane(CXTPDockingPane* pOwnerPane) {m_pOwnerPane = pOwnerPane;}

protected:
	DECLARE_MESSAGE_MAP()

protected:
    CXTPDockingPane*        m_pOwnerPane;
};

static void AddLogView(const CString& strLog)
{
    CMPPLogView::GetInstance()->AddLog(strLog);    
}