/*****************************************************************************
*
* File			: DLPatchServerConfig.cpp
* Author		: agebreak
* Copyright		: (��)NTL
* Date			: 2007. 10. 4.
* Abstract		: 
*****************************************************************************
* Desc          : Patch Server�� �����ϴ� PatchServerConfig.XML ������ ������
*				  �о �м��ϴ� Ŭ����
*
*****************************************************************************/


#include "StdAfx.h"
#include "DLPatchServerConfig.h"
#include "NtlXMLDoc.h"
#include "DLUtility.h"


#define NODE_SERVER_CAPTION_NAME				_T( "PATCH_SERVER_CONFIG/PATCH_CAPTION_NAME" )

#define NODE_SERVER_WEB_PATCH_HISTORY_PATH		_T( "PATCH_SERVER_CONFIG/PATCH_WEB_PATCH_HISTORY_PATH" )

#define NODE_SERVER_LANGUAGE_SVR_IP				_T( "PATCH_SERVER_CONFIG/PATCH_LANGUAGE_SVR_IP" )
#define NODE_SERVER_LANGUAGE_SVR_PATH			_T( "PATCH_SERVER_CONFIG/PATCH_LANGUAGE_SVR_PATH" )
#define NODE_SERVER_LANGUAGE_SVR_FILENAME		_T( "PATCH_SERVER_CONFIG/PATCH_LANGUAGE_SVR_FILENAME" )

#define NODE_SERVER_PATCH_SVR_MASTER_MODE		_T( "PATCH_SERVER_CONFIG/PATCH_PATCH_SVR_MASTER_MODE" )
#define NODE_SERVER_PATCH_SVR_ENABLE			_T( "PATCH_SERVER_CONFIG/PATCH_PATCH_SVR_ENABLE" )
#define NODE_SERVER_PATCH_SVR_IP				_T( "PATCH_SERVER_CONFIG/PATCH_PATCH_SVR_IP" )
#define NODE_SERVER_PATCH_SVR_PATH				_T( "PATCH_SERVER_CONFIG/PATCH_PATCH_SVR_PATH" )
#define NODE_SERVER_PATCH_SVR_FILENAME			_T( "PATCH_SERVER_CONFIG/PATCH_PATCH_SVR_FILENAME" )

#define NODE_SERVER_INTEGRITY_SVR_ENABLE		_T( "PATCH_SERVER_CONFIG/PATCH_INTEGRITY_SVR_ENABLE" )
#define NODE_SERVER_INTEGRITY_SVR_IP			_T( "PATCH_SERVER_CONFIG/PATCH_INTEGRITY_SVR_IP" )
#define NODE_SERVER_INTEGRITY_SVR_PATH			_T( "PATCH_SERVER_CONFIG/PATCH_INTEGRITY_SVR_PATH" )
#define NODE_SERVER_INTEGRITY_SVR_FILENAME		_T( "PATCH_SERVER_CONFIG/PATCH_INTEGRITY_SVR_FILENAME" )


//////////////////////////////////////////////////////////////////////////
//
// CDLPatchServerConfig
//
//////////////////////////////////////////////////////////////////////////


CDLPatchServerConfig g_clDLPatchServerConfig;


CDLPatchServerConfig::CDLPatchServerConfig( void )
{
	m_bPatchMasterMode = false;
	m_bPatchSvrEnable = false;
	m_bIntegritySvrEnable = false;
}

CDLPatchServerConfig::~CDLPatchServerConfig( void ) 
{

}

bool CDLPatchServerConfig::LoadServerConfigFile( CString strPath ) 
{
    CNtlXMLDoc doc;

	if ( !doc.Create() )
	{
		CString strDebug; strDebug.Format( _T( "Loading the configure is failed. %s, %s, %d" ), strPath, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	LPCTSTR pPath = (LPCTSTR)strPath;

	if ( !doc.Load( (TCHAR*)pPath ) )
	{
		CString strDebug; strDebug.Format( _T( "Loading the configure is failed. %s, %s, %d" ), strPath, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	TCHAR szBuffer[4096] = { 0, };

	//////////////////////////////////////////////////////////////////////////
	//
	//	Caption name
	//
	//////////////////////////////////////////////////////////////////////////

	if ( !doc.GetDataWithXPath( NODE_SERVER_CAPTION_NAME, szBuffer, 4096 ) )
	{
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_CAPTION_NAME, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strCaptionName = szBuffer;

	//////////////////////////////////////////////////////////////////////////
	//
	//	��ó���� ���������� ��ġ ������ ����ϱ� ���� ���Ǵ� ����
	//
	//////////////////////////////////////////////////////////////////////////

	if ( !doc.GetDataWithXPath( NODE_SERVER_WEB_PATCH_HISTORY_PATH, szBuffer, 4096 ) )
	{
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_WEB_PATCH_HISTORY_PATH, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strWebPatchHistoryPath = szBuffer;

	//////////////////////////////////////////////////////////////////////////
	//
	//	��ó���� ��µǴ� ���ڿ��� �����ϱ� ���� ����
	//
	//////////////////////////////////////////////////////////////////////////

	if ( !doc.GetDataWithXPath( NODE_SERVER_LANGUAGE_SVR_IP, szBuffer, 4096 ) )
	{
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_LANGUAGE_SVR_IP, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strLanguageSvrIP = szBuffer;

	if ( !doc.GetDataWithXPath( NODE_SERVER_LANGUAGE_SVR_PATH, szBuffer, 4096 ) )
	{
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_LANGUAGE_SVR_PATH, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strLanguageSvrPath = szBuffer;

	if ( !doc.GetDataWithXPath( NODE_SERVER_LANGUAGE_SVR_FILENAME, szBuffer, 4096 ) )
	{
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_LANGUAGE_SVR_FILENAME, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strLanguageSvrFileName = szBuffer;

	//////////////////////////////////////////////////////////////////////////
	//
	//	��ġ ���� ����
	//
	//////////////////////////////////////////////////////////////////////////

	if ( !doc.GetDataWithXPath( NODE_SERVER_LANGUAGE_SVR_IP, szBuffer, 4096 ) )
	{
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_LANGUAGE_SVR_IP, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strLanguageSvrIP = szBuffer;

	if ( !doc.GetDataWithXPath( NODE_SERVER_LANGUAGE_SVR_PATH, szBuffer, 4096 ) )
	{
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_LANGUAGE_SVR_PATH, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strLanguageSvrPath = szBuffer;

	if ( !doc.GetDataWithXPath( NODE_SERVER_LANGUAGE_SVR_FILENAME, szBuffer, 4096 ) )
	{
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_LANGUAGE_SVR_FILENAME, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strLanguageSvrFileName = szBuffer;

	//////////////////////////////////////////////////////////////////////////
	//
	//	��ġ ���� ����
	//
	//////////////////////////////////////////////////////////////////////////

	if ( doc.GetDataWithXPath( NODE_SERVER_PATCH_SVR_MASTER_MODE, szBuffer, 4096 ) )
	{
		CString strMasterMode( szBuffer );

		strMasterMode.MakeUpper();

		if ( strMasterMode == _T("TRUE") )
		{
			m_bPatchMasterMode = true;
		}
		else
		{
			m_bPatchMasterMode = false;
		}
	}
	else
	{
		m_bPatchMasterMode = false;
	}

	if ( !doc.GetDataWithXPath( NODE_SERVER_PATCH_SVR_ENABLE, szBuffer, 4096 ) )
	{	
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_PATCH_SVR_ENABLE, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_bPatchSvrEnable = _tstoi( szBuffer ) ? true : false;

	if ( !doc.GetDataWithXPath( NODE_SERVER_PATCH_SVR_IP, szBuffer, 4096 ) )
	{	
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_PATCH_SVR_IP, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strPatchSvrIP = szBuffer;

	if ( !doc.GetDataWithXPath( NODE_SERVER_PATCH_SVR_PATH, szBuffer, 4096 ) )
	{	
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_PATCH_SVR_PATH, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strPatchSvrPath = szBuffer;

	if ( !doc.GetDataWithXPath( NODE_SERVER_PATCH_SVR_FILENAME, szBuffer, 4096 ) )
	{	
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_PATCH_SVR_FILENAME, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strPatchSvrFileName = szBuffer;

	//////////////////////////////////////////////////////////////////////////
	//
	//	���Ἲ ���� ����
	//
	//////////////////////////////////////////////////////////////////////////

	if ( !doc.GetDataWithXPath( NODE_SERVER_INTEGRITY_SVR_ENABLE, szBuffer, 4096 ) )
	{	
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_INTEGRITY_SVR_ENABLE, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_bIntegritySvrEnable = _tstoi( szBuffer ) ? true : false;

	if ( !doc.GetDataWithXPath( NODE_SERVER_INTEGRITY_SVR_IP, szBuffer, 4096 ) )
	{	
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_INTEGRITY_SVR_IP, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strIntegritySvrIP = szBuffer;

	if ( !doc.GetDataWithXPath( NODE_SERVER_INTEGRITY_SVR_PATH, szBuffer, 4096 ) )
	{	
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_INTEGRITY_SVR_PATH, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strIntegritySvrPath = szBuffer;

	if ( !doc.GetDataWithXPath( NODE_SERVER_INTEGRITY_SVR_FILENAME, szBuffer, 4096 ) )
	{	
		CString strDebug; strDebug.Format( _T( "Can not find the node or attributes. %s, %s, %s, %d" ), strPath, NODE_SERVER_INTEGRITY_SVR_FILENAME, __FILEW__, __LINE__ );
		DLSendMessage_ForDebug( strDebug );

		return false;
	}

	m_strIntegritySvrFileName = szBuffer;

	return true;
}
