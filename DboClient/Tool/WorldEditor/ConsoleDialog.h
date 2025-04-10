#pragma once

#include "Resource.h"
#include "afxwin.h"
#include "CommandEdit.h"

// CConsoleDialog ��ȭ �����Դϴ�.

class CConsoleDialog : public CDialog
{
	DECLARE_DYNAMIC(CConsoleDialog)

	CString				m_Command;
public:
	CConsoleDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CConsoleDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CONSOLE };

	virtual BOOL OnInitDialog();


	const TCHAR * GetCommand( void ) const { return (LPCTSTR)m_Command; }
	void CancelCommand( void ) { OnCancel(); }
	void SetCommand( TCHAR * pCommand ) { m_Command = pCommand; m_Command.AppendChar( '\n' ); OnOK(); }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CCommandEdit m_EditCommand;
};
