/*****************************************************************************
*
* File			: OutputBox.h
* Author		:
* Copyright		: (��)NTL
* Date			:
* Abstract		: 
*****************************************************************************
* Desc          :
*
*****************************************************************************/


#pragma once


//////////////////////////////////////////////////////////////////////////
//
// COutputBox
//
//////////////////////////////////////////////////////////////////////////


class COutputBox : public CStatic
{
public:
	bool				m_bIsLog;

public:
	COutputBox( void );
    virtual ~COutputBox( void );

public:
    void				EraseBack( CDialog* pDlg );		// �۾������� �����.

protected:
	afx_msg HBRUSH		CtlColor( CDC* pDC, UINT nCtlColor );

	DECLARE_MESSAGE_MAP()
};
