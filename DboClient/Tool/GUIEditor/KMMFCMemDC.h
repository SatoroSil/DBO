/******************************************************************************

  MemoryDC Class
  ==============
  - MFC/GDI ����� Memory DC �ٷ�� Ŭ����

  - ����ִ� / Bitmap in Resource / �ܺ� Bitmap ���� 
    HBITMAP ���� ����

  - Ư�� �Լ� ������ msimg32.lib �� ������ ���Խ������ ��.
    --> #pragma �̿��ؼ� �ڵ����� �ε��ϵ��� ����.

  - Ư�� �Լ� ������ Win9x ������ ���� ���� �� ����.
    �׽�Ʈ�� Win2k ������ �غ���.

  - MFC�� Ư���� MFCMemDC.cpp ������ include�� ������ �ʿ䰡 ���� ����.


  * Update

    2003.07.15 / klayman@gs
	- �����۾�

    2004.08.17 / klayman@gs
	- ��ɺ��� --> �������� �Լ����� ���� �ȹٷ� ���� ��!

    2005.06.02 / thkim@mcres.co.kr
	- Ŭ���� �̸� ����. (�ʹ� ����...)
	- ���ÿ��� �����Լ� �߰�.

    2005.06.10 / thkim@mcres.co.kr
	- Thumbnail �����Լ� �߰�. / HBITMAP�̳� MemDC ������ �ʿ��� ��.


  * To Do
    - ���������, ���� ������ ó��
	- ����ó��
			   
******************************************************************************/

// MFCMemDC.h: interface for the CKMMemDC class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCMEMDC_H__9618ED30_73ED_4971_A1C0_66666A54F315__INCLUDED_)
#define AFX_MFCMEMDC_H__9618ED30_73ED_4971_A1C0_66666A54F315__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <afxwin.h>


#pragma comment(lib, "msimg32.lib")



class CKMMemDC  
{
protected:

	CDC*	 m_pMDC;

	int		 m_nWidth;
	int		 m_nHeight;
	
public:
	COLORREF m_crColorkey;
	
public:
	CKMMemDC();

	CKMMemDC( CWnd* pSrcWnd, int width, int height, COLORREF clr = 0x00ffffff );
	CKMMemDC( CWnd* pSrcWnd, UINT nIDBitmap, BITMAP* pBMInfo = NULL );
	CKMMemDC( CWnd* pSrcWnd, const char* szFileName, BITMAP* pBMInfo = NULL );
	CKMMemDC( CWnd* pSrcWnd, HBITMAP hBitmap, BITMAP* pBMInfo = NULL );

	virtual ~CKMMemDC();

public:
	void InitMember();
	void Delete();

	// Create Memory DC - Empty/Solid
	int Create        ( CWnd* pSrcWnd, 
						int width, int height, COLORREF clr = 0x00ffffff );

	// Create Memory DC - From Resource ID
	int CreateFromID  ( CWnd* pSrcWnd, UINT nIDBitmap, 
						BITMAP* pBMInfo = NULL );

	// Create Memory DC - From File Name
	int CreateFromFile( CWnd* pSrcWnd, const char* szFileName, 
						BITMAP* pBMInfo = NULL );

	// Create Memory DC - From HBITMAP
	int CreateFromHBM ( CWnd* pSrcWnd, HBITMAP hBitmap, 
						BITMAP* pBMInfo = NULL );

public: //// ȭ�� ��� �Լ�

	// 1:1 ���
	int  BltTo			( CDC* pDestDC, 
						  int dx, int dy,
						  DWORD dwROP = SRCCOPY );

	int  BltTo			( int sx, int sy,
						  CDC* pDestDC, 
						  int dx, int dy,
						  DWORD dwROP = SRCCOPY );

	int  BltTo			( int sx, int sy, int sw, int sh,
						  CDC* pDestDC, 
						  int dx, int dy,
						  DWORD dwROP = SRCCOPY );
	
	// �÷���/�ٿ��� ���
	int  StretchBltTo	( CDC* pDestDC, 
						  int dx, int dy, int dw, int dh,
						  DWORD dwROP = SRCCOPY );

	int  StretchBltTo	( int sx, int sy,
						  CDC* pDestDC, 
						  int dx, int dy, int dw, int dh,
						  DWORD dwROP = SRCCOPY );

	int  StretchBltTo	( int sx, int sy, int sw, int sh,
						  CDC* pDestDC, 
						  int dx, int dy, int dw, int dh,
						  DWORD dwROP = SRCCOPY );


	// ���� ���� / ������ Colokey : �߰� library �ʿ��� ( msimg32.lib )
	int  TransBltTo		( CDC* pDestDC, 
						  int dx, int dy );

	int  TransBltTo		( int sx, int sy,
						  CDC* pDestDC, 
						  int dx, int dy );

	int  TransBltTo		( int sx, int sy, int sw, int sh,
						  CDC* pDestDC, 
						  int dx, int dy, int dw, int dh );

	// ���� ���� / Colokey ���� : �߰� library �ʿ��� ( msimg32.lib )
	int  TransBltTo		( CDC* pDestDC, 
						  int dx, int dy,
						  COLORREF clrKey );

	int  TransBltTo		( int sx, int sy,
						  CDC* pDestDC, 
						  int dx, int dy,
						  COLORREF clrKey );

	int  TransBltTo		( int sx, int sy, int sw, int sh,
						  CDC* pDestDC, 
						  int dx, int dy, int dw, int dh,
						  COLORREF clrKey );


	// ������ ����
	int  AlphaBltTo		( CDC* pDestDC, 
						  int dx, int dy,
						  BYTE alpha = 128 ); // alpha = 0 ~ 255

	int  AlphaBltTo		( int sx, int sy,
						  CDC* pDestDC, 
						  int dx, int dy,
						  BYTE alpha = 128 ); // alpha = 0 ~ 255

	int  AlphaBltTo		( int sx, int sy, int sw, int sh,
						  CDC* pDestDC, 
						  int dx, int dy, int dw, int dh,
						  BYTE alpha = 128 ); // alpha = 0 ~ 255


	// �ܼ� ��ä���
	int FillColor		( COLORREF clr = 0x00ffffff );
	int FillColor		( COLORREF clr, CRect rc );
	int FillColor		( COLORREF clr, int x, int y, int w, int h );


	// ���� �׸���.
	int DrawGrid		( int gridX, int gridY, COLORREF clr, int penWidth=1 );


public: ////

	// Colorkey ����.
	void SetColorkey	( BYTE r, BYTE g, BYTE b );
	void SetColorkey	( COLORREF colorkey );
	void SetColorkey	( int pixelX, int pixelY );

	// Colorkey�� ��.
	BOOL IsColorkey		( BYTE r, BYTE g, BYTE b );
	BOOL IsColorkey		( COLORREF color );

	// Colorkey�� ���Ͽ� ����ȭ.
	BOOL SelectFix_Optimize	( CRect& rcSelect );

	// MemDC�� ��/���̿� ���Ͽ� ����.
	BOOL SelectFix_Bound	( CRect& rcSelect );

	// Grid�������� ����.
	BOOL SelectFix_Grid		( int gridX, int gridY, CRect& rcSelect );

	// RECT �����ȿ� ��ġ�ϰ� �ִ°�? / Clipping �˻�(?)
	BOOL IsInRect ( CPoint pt, CRect* pRect );


public: ////

	BOOL GetThumbNail	( CWnd* pSrcWnd, CBitmap *pBMOut, 
							int sX, int sY, int sW, int sH, 
							int thW, int thH );

	BOOL GetThumbNail	( CWnd* pSrcWnd, CBitmap *pBMOut, 
							int thW, int thH );


public:
	// �ܼ� �� �����ֱ� �Լ��� ����
	inline int  GetWidth()	{ return m_nWidth; }
	inline int  GetHeight()	{ return m_nHeight; }

	inline CDC* GetMDC()	{ return m_pMDC; }
	inline HDC	GetHDC()	{ return m_pMDC->m_hDC; }

	inline operator CDC*()	{ return m_pMDC; }
	inline operator HDC()	{ return m_pMDC->m_hDC; }

	//
	int	IsEmpty()			{ return ( (m_pMDC==NULL)?1:0 ); }

};// end of class CKMMemDC

#endif // !defined(AFX_MFCMEMDC_H__9618ED30_73ED_4971_A1C0_66666A54F315__INCLUDED_)
