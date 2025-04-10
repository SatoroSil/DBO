/*****************************************************************************
 *
 * File			: DLDownLoadSys.h
 * Author		:
 * Copyright	: (��)NTL
 * Date			:
 * Abstract		: 
 *****************************************************************************
 * Desc         : Http Protocol �� �̿��� �ٿ�ε� �ý���
 *
 *****************************************************************************/


#pragma once


#include "DLEventDef.h"


//////////////////////////////////////////////////////////////////////////
//
// CDLDownLoadSys
//
//////////////////////////////////////////////////////////////////////////


class CDLDownLoadSys
{
protected:
	bool					m_bPendingDestroy;

public:
	CDLDownLoadSys( void );
	~CDLDownLoadSys( void );

public:
	bool					Create( void );
	void					Delete( void );

	void					DLMessageProc( eDL_EVENT eMsg, sDL_EVENT_DATA_BASE* pData );

protected:
	bool					DoDownload( CString strServerName,
										CString strServerPath,
										CString strServerFileName,
										CString strClientPath,
										CString strClientFileName );
};
