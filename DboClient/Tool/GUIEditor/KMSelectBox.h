/******************************************************************************

  KMSelectBox
  =========
  - Win32 API ���. MFC������ ��밡��.
  - XOR ��带 �̿��� ��ǥǥ�ü�/���ÿ��� �׸���
  - ���ÿ���(RECT) ���

 * Update 

   2003.03.20 / klayman@gameschool.co.kr
   - �����۾�

   2005.06.01 / thkim@mcres.co.kr 
   - �����̸�, �������̽� �̸� ����.

   2006.01.19 / peessi@ntl-inc
   - Ȯ��, ��Ҹ� ���� CDC�� �޾� �� ���� �׸����� ����. 
   

 * To Do
   - Ư�� �ȼ������� ���ÿ��� �׸���.
                                    
******************************************************************************/

#ifndef __KM_SELECT_BOX__
#define __KM_SELECT_BOX__

#include <afxwin.h>

class CKMSelectBox
{
public:
	CKMSelectBox()			{ InitMember(); }
	virtual ~CKMSelectBox()	{ Delete();     }
	
	void InitMember();
	void Create( HWND hWnd, BOOL bUseCross );
	void Delete();
	
	//
	void Draw			( POINT ptCur );
	void Erase			( );
	
	//
	void BoxBegin		( POINT ptStart );
	void BoxEnd			( );
	
	//
	void UpdateClientSize( int nWidth, int nHeight );

	//
	void SetDC( CDC* pDC ) { m_pDC = pDC; }
	inline
	RECT& GetCurRect()	{ return m_rcSelectCur; }
	inline
	RECT& GetOldRect()	{ return m_rcSelectOld; }
	
	void  ClearRects();
	
	
protected:

	HWND	m_hWnd;
	CDC*	m_pDC;

	//// point, rect
	POINT	m_ptCrossCur;
	POINT	m_ptCrossOld;
	
	RECT	m_rcSelectCur;
	RECT	m_rcSelectOld;
	
	SIZE	m_czClient;
	
	//// pen, brush

	COLORREF m_crCross;
	COLORREF m_crSelect;
	
	HPEN	m_penCross;
	HPEN	m_penSelect;
	HBRUSH	m_brSelect;

	// is...
	BOOL	m_bUseCrossMode;
	BOOL	m_bInBoxMode;
	BOOL	m_bIsOneClick;

	
protected:
//public:

	//
	void CrossDraw		( POINT ptMove );
	void CrossErase		( );

	//
	void BoxDraw		( POINT ptMoveBR );
	void BoxErase		( );

	//	
	void DrawXORCross   ( POINT point );
	void DrawXORBox		( RECT  rect  );
	
	void NormalizeRect	( RECT& rect );
};


#endif//__KM_SELECT_BOX__
