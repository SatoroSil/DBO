// Venus.h : Venus ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"       // �� ��ȣ


// CVenusApp:
// �� Ŭ������ ������ ���ؼ��� Venus.cpp�� �����Ͻʽÿ�.
//

class CVenusApp : public CWinApp
{
public:
	CVenusApp();
	
	void	DeleteVenus();

	BOOL	m_bInitialize;

// ������
public:
	virtual BOOL InitInstance();

// ����	
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnIdle(LONG lCount);
};

extern CVenusApp theApp;

inline CVenusApp* gMainApp()
{
	return &theApp;
//	CGaiaApp* pMainApp = (CGaiaApp*)AfxGetApp();
//	return pMainApp;
}
