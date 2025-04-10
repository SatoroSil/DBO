/*****************************************************************************
*
* File			: DLLocalConfig.h
* Author		: 
* Copyright		: (��) NTL
* Date			:
* Abstract		: 
*****************************************************************************
* Desc          : 
*
*****************************************************************************/


#pragma once


//////////////////////////////////////////////////////////////////////////
//
// CDLLocalConfig
//
//////////////////////////////////////////////////////////////////////////


class CDLLocalConfig
{
protected:
	CString					m_strInitConnectionIP;				// ��ó �ʱ� ���� ���� IP
	CString					m_strInitConnectionPath;			// ��ó �ʱ� ���� ���� Path
	CString					m_strInitConnectionFileName;		// ��ó �ʱ� ���� ���� FileName

public:
	CDLLocalConfig( void ) { return; }
	~CDLLocalConfig( void ) { return; }

public:
	bool					Load( CString strPath );

	const CString&			GetInitConnectionSvrIP( void ) const;
	const CString&			GetInitConnectionSvrPath( void ) const;
	const CString&			GetInitConnectionSvrFileName( void ) const;
};


extern CDLLocalConfig g_clDLLocalConfig;