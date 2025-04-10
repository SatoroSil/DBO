#pragma once


#include "resource.h"

// CInfomationPane �� ���Դϴ�.

class CInfomationPane : public CFormView
{
	DECLARE_DYNCREATE(CInfomationPane)

protected:
	CInfomationPane();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CInfomationPane();

public:
	enum { IDD = IDD_INFOMATION };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	void	SetClientMouse( int nX, int nY );
	void	SetParticleMouse( int nX, int nY );
	void	SetResolution( int nWidth, int nHeight );

	static CInfomationPane* m_pInstance;
	static CInfomationPane* GetInstance() { return m_pInstance; }

public:
	CString m_szClientMouseX;			///< Ŭ���̾�Ʈ ���� ( 0 ~ View ������ )
	CString m_szClientMouseY;
	CString m_szParticleMouseX;			///< ��ƼŬ ���� ( Offset���� ������ )
	CString m_szParticleMouseY;
	CString m_szResolutionWidth;
	CString m_szResoultionHeight;

protected:
	virtual void OnInitialUpdate();
};

static CInfomationPane* GetInfomationPane()
{
	return CInfomationPane::GetInstance();
}

