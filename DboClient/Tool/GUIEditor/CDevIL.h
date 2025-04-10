//-----------------------------------------------------------------------------
// Name: class CDevIL
// Desc: DevIL SDK�� �̿��Ͽ� �̹����� �ε��ϴ� Ŭ����.
//
//			 
// 2006.01.16 Peessi@hitel.net  
//
// TODO: �ϳ��� �̹����� �ε��ϰ� �Ǿ� �ִ�. 
//-----------------------------------------------------------------------------

#ifndef	__CDEVIL_H__
#define __CDEVIL_H__

#ifdef _DEBUG
#define IL_DEBUG
#endif

#include <windows.h>

// TODO: ������ġ�� �����ش�.
#include "DevIL/include/il/il.h"
#include "DevIL/include/il/ilu.h"
#include "DevIL/include/il/ilut.h"

class CDevIL
{
protected:

	ILuint		m_imageIdx;			// �̹��� �ε���. 0�� �ƴϸ� �ε�Ǿ� �ִ�.
	
	// Infomation Variable
	INT			m_nWidth;  
	INT			m_nHeight; 
	INT			m_nBytes;
	INT			m_nBits;  
	INT			m_nFormat; 
	INT			m_nType;   
	INT			m_nFSet;
	INT			m_nFMode;
	INT			m_nTSet;
	INT			m_nTMode;
	INT			m_nOrgMode;

	ILubyte*	m_pPic;				// Image Data.

public:

	CDevIL();
	~CDevIL();

	void Init();
	void Shutdown();

	void ClearMember();
	
	virtual BOOL Load( LPCTSTR szFilename );
	virtual void Unload();

	// Operation
	BOOL	GetPixel( INT x, INT y, BYTE* pRed, BYTE* pGreen, BYTE* pBlue, BYTE* pAlpha );
	
	// query
	BOOL	IsLoaded()				{ return ilIsImage( m_imageIdx ); }
		
	// access
	INT		GetWidth()				{ return m_nWidth; }
	INT		GetHeight()				{ return m_nHeight; }
	INT		GetBytesPerPixel()		{ return m_nBytes; }
	INT		GetBItsPerPixel()		{ return m_nBits; }
	INT		GetFormat()				{ return m_nFormat; }
	INT		GetType()				{ return m_nType; }
	INT		GetFormatSet()			{ return m_nFSet; }
	INT		GetFormatMode()			{ return m_nFMode; }
	INT		GetTypeSet()			{ return m_nTSet; }
	INT		GetTypeMode()			{ return m_nTMode; }
	INT		GetOriginMode()			{ return m_nOrgMode; }

};

#endif // __C_DEVIL_H__