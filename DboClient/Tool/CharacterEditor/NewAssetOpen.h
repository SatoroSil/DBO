#pragma once


// CNewAssetOpen

class CNewAssetOpen : public CFileDialog
{
	DECLARE_DYNAMIC(CNewAssetOpen)

public:
	CNewAssetOpen(BOOL bOpenFileDialog, // FileOpen�� TRUE, FileSaveAs�� FALSE�Դϴ�.
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);
	virtual ~CNewAssetOpen();

protected:
	DECLARE_MESSAGE_MAP()
};


