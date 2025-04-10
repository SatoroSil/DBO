#pragma once


#include "TSToolDefine.h"


// CTSQuestTextListCtrl ���Դϴ�.

class CTSQuestTextListCtrl : public CListCtrl
{
	DECLARE_DYNCREATE(CTSQuestTextListCtrl)

public:
	struct sENTITY
	{
		CString							strTblIdx;
		CString							strQText;
	};

public:
	CTSQuestTextListCtrl();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CTSQuestTextListCtrl();

protected:
	DECLARE_MESSAGE_MAP()

protected:
	CArray< sENTITY, const sENTITY& >	m_aStringList;

public:
	void								Init( void );
	void								ClearAll( void );

	void								AddEntity( unsigned int uiTableIndex, const CString& strQText );

public:
};


