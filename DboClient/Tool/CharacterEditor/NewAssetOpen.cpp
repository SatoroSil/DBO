// NewAssetOpen.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CharacterEditor.h"
#include "NewAssetOpen.h"


// CNewAssetOpen

IMPLEMENT_DYNAMIC(CNewAssetOpen, CFileDialog)
CNewAssetOpen::CNewAssetOpen(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
}

CNewAssetOpen::~CNewAssetOpen()
{
}


BEGIN_MESSAGE_MAP(CNewAssetOpen, CFileDialog)
END_MESSAGE_MAP()



// CNewAssetOpen �޽��� ó�����Դϴ�.

