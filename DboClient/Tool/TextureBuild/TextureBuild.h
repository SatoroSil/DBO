#pragma once

#ifndef __AFXWIN_H__
#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include "ConverterDirectX.h"

// CTextureBuildApp:
// �� Ŭ������ ������ ���ؼ��� TextureBuild.cpp�� �����Ͻʽÿ�.
//

class CTextureBuildApp : public CWinApp
{
protected:
	CConverterDirectX m_Converter;

public:
	CConverterDirectX* GetConverter() { return &m_Converter; }


public:
	CTextureBuildApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTextureBuildApp theApp;