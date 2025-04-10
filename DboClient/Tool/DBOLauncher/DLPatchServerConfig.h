/*****************************************************************************
*
* File			: DLPatchServerConfig.h
* Author		: agebreak
* Copyright		: (��)NTL
* Date			: 2007. 10. 4.
* Abstract		: 
*****************************************************************************
* Desc          : Patch Server�� �����ϴ� PatchServerConfig.XML ������ ������
*				  �о �м��ϴ� Ŭ����
*
*****************************************************************************/


#pragma once


//////////////////////////////////////////////////////////////////////////
//
// CDLPatchServerConfig
//
//////////////////////////////////////////////////////////////////////////


class CDLPatchServerConfig
{
protected:
	// Caption name
	CString						m_strCaptionName;

	// ��ó���� ���������� ��ġ ������ ����ϱ� ���� ���Ǵ� ����
	CString						m_strWebPatchHistoryPath;

	// ��ó���� ��µǴ� ���ڿ��� �����ϱ� ���� ����
	CString						m_strLanguageSvrIP;
	CString						m_strLanguageSvrPath;
	CString						m_strLanguageSvrFileName;

	// ��ġ ���� ����
	bool						m_bPatchMasterMode;
	bool						m_bPatchSvrEnable;
	CString						m_strPatchSvrIP;
	CString						m_strPatchSvrPath;
	CString						m_strPatchSvrFileName;

	// ���Ἲ ���� ����
	bool						m_bIntegritySvrEnable;
	CString						m_strIntegritySvrIP;
	CString						m_strIntegritySvrPath;
	CString						m_strIntegritySvrFileName;

public:
	CDLPatchServerConfig( void );
	~CDLPatchServerConfig( void );

public:    
	bool						LoadServerConfigFile( CString strPath );									// XML ������ �ε��Ѵ�.

	CString						GetCaptionName( void )				{ return m_strCaptionName; }

	CString						GetWebPatchHistoryPath( void )		{ return m_strWebPatchHistoryPath; }	// Web Patch History ������ �����ϴ� �н� ��ȯ�Ѵ�.

	CString						GetLanguageSvrIP( void )			{ return m_strLanguageSvrIP; }
	CString						GetLanguageSvrPath( void )			{ return m_strLanguageSvrPath; }
	CString						GetLanguageSvrFileName( void )		{ return m_strLanguageSvrFileName; }

	bool						GetPatchSvrMasterMode( void )		{ return m_bPatchMasterMode; }
	bool						GetPatchSvrEnable( void )			{ return m_bPatchSvrEnable; }
	CString						GetPatchSvrIP( void )				{ return m_strPatchSvrIP; }
	CString						GetPatchSvrPath( void )				{ return m_strPatchSvrPath; }
	CString						GetPatchSvrFileName( void )			{ return m_strPatchSvrFileName; }

	bool						GetIntegritySvrEnable( void )		{ return m_bIntegritySvrEnable; }
	CString						GetIntegritySvrIP( void )			{ return m_strIntegritySvrIP; }
	CString						GetIntegritySvrPath( void )			{ return m_strIntegritySvrPath; }
	CString						GetIntegritySvrFileName( void )		{ return m_strIntegritySvrFileName; }
};


extern CDLPatchServerConfig g_clDLPatchServerConfig;