/*****************************************************************************
*
* File			: DLUtility.h
* Author		: 
* Copyright		: (��) NTL
* Date			:
* Abstract		: 
*****************************************************************************
* Desc          : 
*
*****************************************************************************/


#pragma once


#include "DBOLauncherDef.h"
#include "DLEventSys.h"


//////////////////////////////////////////////////////////////////////////
//
// ���� �����Ǵ� Ŭ���̾�Ʈ�� Language type�� ���� �Լ�
//
//////////////////////////////////////////////////////////////////////////


extern eDL_LANGUAGE_TYPE	GetLanguageType( void );


//////////////////////////////////////////////////////////////////////////
//
// ���� �������� system�� ���´�
//
//////////////////////////////////////////////////////////////////////////


class CDLProcessSys;
class CDLMessageSys;
class CDLIntegritySys;
class CDLSkinSys;
class CDLStateSys;

extern CDLProcessSys*		GetProcessSys( void );
extern CDLEventSys*			GetEventSys( void );
extern CDLMessageSys*		GetMessageSys( void );
extern CDLIntegritySys*		GetIntegritySys( void );
extern CDLSkinSys*			GetSkinSys( void );
extern CDLStateSys*			GetStateSys( void );


//////////////////////////////////////////////////////////////////////////
//
// Event
//
//////////////////////////////////////////////////////////////////////////


extern void					DLSendEvent( eDL_EVENT eMsg, sDL_EVENT_DATA_BASE* pData );
extern void					DLPostEvent( eDL_EVENT eMsg, sDL_EVENT_DATA_BASE* pData );


//////////////////////////////////////////////////////////////////////////
//
// Message
//
//////////////////////////////////////////////////////////////////////////


extern void					DLSendMessage_ToUser( unsigned int uiMsgID );		/*eDL_MSG*/
extern void					DLSendMessage_ForDebug( const CString& strMsg );


//////////////////////////////////////////////////////////////////////////
//
// Attach back-slash
//
//////////////////////////////////////////////////////////////////////////


extern void AttachBackSlash( CString& strString );


//////////////////////////////////////////////////////////////////////////
//
// Directory
//
//////////////////////////////////////////////////////////////////////////


bool MakeDirectory( const CString& strPath );