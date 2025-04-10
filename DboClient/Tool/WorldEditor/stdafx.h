// stdafx.h : �� ������� �ʰ� ���� ����ϴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������ 
// ��� �ִ� ���� �����Դϴ�.
#ifndef	_STD_AFX_H_
#define _STD_AFX_H_

#pragma once

#pragma warning (disable:4786)	// template parameter length waning
#pragma warning (disable:4018)	// sign/unsign Waning
#pragma warning (disable:4244)	// data converting warning
#pragma warning (disable:4805)	// bool/BOOL converting warning
#pragma warning (disable:4311)	// convert warning
#pragma warning (disable:4312)	// convert warning
#pragma warning (disable:4275)	// dll parent class warning
#pragma warning (disable:4100)	// unreferenced formal parameter warning

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Windows ������� ���� ������ �ʴ� ������ ���ܽ�ŵ�ϴ�.
#endif

// �Ʒ� ������ �÷������� �켱�ϴ� �÷����� ������� �ϴ� ��� ���� ���Ǹ� �����Ͻʽÿ�.
// �ٸ� �÷����� ���Ǵ� �ش� ���� �ֽ� ������ MSDN�� �����Ͻʽÿ�.
#ifndef WINVER				// Windows 95 �� Windows NT 4 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define WINVER 0x0400		// Windows 98�� Windows 2000 ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#ifndef _WIN32_WINNT		// Windows NT 4 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_WINNT 0x0400		// Windows 98�� Windows 2000 ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#ifndef _WIN32_WINDOWS		// Windows 98 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_WINDOWS 0x0410 // Windows Me ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#ifndef _WIN32_IE			// IE 4.0 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_IE 0x0400	// IE 5.0 ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// �Ϻ� CString �����ڴ� ��������� ����˴ϴ�.

// MFC�� ���� �κа� ���� ������ ��� �޽����� ���� ����⸦ �����մϴ�.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC �ٽ� �� ǥ�� ���� ���
#include <afxext.h>         // MFC �ͽ��ټ�
#include <afxdisp.h>        // MFC �ڵ�ȭ Ŭ����

#include <afxdtctl.h>		// Internet Explorer 4 ���� ��Ʈ�ѿ� ���� MFC ����
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Windows ���� ��Ʈ�ѿ� ���� MFC ����
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxtempl.h>

// STL

#include <list>
#include <vector>
#include <hash_map>
using std::list;
using std::vector;
using stdext::hash_map;

// Windows API

#include <WinSock2.h> 
#include <Windowsx.h> 
#include <WinNls.h>

#define CRTDBG_MAP_ALLOC

#include <StdDef.h>

// Direct X

#include <D3D9.h>

// Randerware

//#include <RwPlCore.h>
#include <RwCore.h>

#include <RpWorld.h>
#include <RpCollis.h>
#include <RpMatFx.h>
#include <RpSkin.h>
#include <RpHAnim.h>
#include <RpUVAnim.h>
#include <RpRandom.h>
#include <RpLtMap.h>
#include <RpPvs.h>

#include <RtImport.h>
#include <RtIntsec.h>
#include <RtPick.h>
#include <RtCharse.h>
#include <RtFSyst.h>
#include <RtDict.h>
#include <RtQuat.h> 
#include <RtAnim.h>
#include <RtLtMap.h>

// NTL Common Library

#include "NtlSharedCommon.h"
#include "NtlXMLDoc.h"

// NTL Core Layer

#include "NtlDebug.h"
#include "NtlText.h"

// NTL Presentation Layer

#include "NtlPlResource.h"
#include "NtlPlResourceManager.h"
#include "NtlPLProperty.h"
#include "NtlPLObjectProperty.h"
#include "NtlPLTerrainProperty.h"
#include "NtlPLPropertyContainer.h"
#include "NtlPLApi.h"

// NTL Framework Layer

#include "NtlApplication.h"
#include "NtlCamera.h"

// Etcs

//#include "DebugEx.h"
#include "PropTree.h"
#include "WorldMonitor.h"
#include "CLogMessageManager.h"
#include "UserDefinedAssert.h"

#endif //_STD_AFX_H_