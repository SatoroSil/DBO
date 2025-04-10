#pragma once


#include "OptionSheet.h"


class CAttr_Page;


// CEntityRegisterDiag ��ȭ �����Դϴ�.

class CEntityRegisterDiag : public COptionSheet
{
	DECLARE_DYNAMIC(CEntityRegisterDiag)

protected:
	CAttr_Page*		m_pEditedPage;

public:
	CEntityRegisterDiag(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEntityRegisterDiag();

	CAttr_Page*		GetEditedAttrPage( void );
	void			AddAttrPage( CAttr_Page* pPage );
	void			ClearAttrPage( void );

	virtual INT_PTR DoModal();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};
