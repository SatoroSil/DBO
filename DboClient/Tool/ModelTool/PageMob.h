#pragma once

#include "PagePc.h"

/**
 * \ingroup ModelTool
 * \brief MOB ���� Edit Left Tree View (CPagePC���� ��ӹ޾Ƽ� ���������)
 * \date 2006-04-28
 * \author agebreak
 */
class CPageMob : public CPagePC
{
	DECLARE_DYNAMIC(CPageMob)

public:
	CPageMob();
	virtual ~CPageMob();

// Dialog Data
	enum { IDD = IDD_PAGEMOB };

    virtual BOOL OnInitDialog();

public:
    afx_msg virtual void OnDestroy();
    virtual BOOL OnSetActive();
	
};
