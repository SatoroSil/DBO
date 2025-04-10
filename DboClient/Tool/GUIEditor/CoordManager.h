//-----------------------------------------------------------------------------
// Name: class CCoordManager
// Desc: View�� Ȯ�� ��ҽ� ���콺 ������ �� Draw�� ������ �����Ѵ�. 
//
//			 
// 2006.01.20 Peessi@hitel.net  
//
//-----------------------------------------------------------------------------
#pragma once

#include <afxwin.h>

class CCoordManager
{
public:
	enum	MARGINRECT { CENTER = 0, LEFT, LEFTUP, UP, RIGHTUP, RIGHT, RIGHTDOWN, DOWN, LEFTDOWN };

	CCoordManager(void);
	~CCoordManager(void);

	void	InitMember();	// ������� �ʱ�ȭ.
	void	Reset();		// �׸��� �ٽ� �ε�ɶ�.

	void    Create( CScrollView* pView, INT nMargin );// OnCreate���� �ѹ��� ȣ���Ѵ�.
	void	Destroy() { InitMember(); }							 

	CPoint  FixMousePt( CPoint& point );
	CRect	GetSrcRect();
	CRect   GetDestRect();

	FLOAT	GetScaleFactor() { return m_fScaleFactor; }
	FLOAT	GetFixXScaleFactor() { return m_fFixXScaleFactor; }
	FLOAT	GetFixYScaleFactor() { return m_fFixYScaleFactor; }
	INT		GetMargin() { return m_nMargin; }
	CPoint	GetOffset() { return m_ptOffset; }
	CRect	GetViewRect() { return m_rcView; }
    
	void	SetMargin( INT nMargin );							// ������ �����Ҷ� ȣ��.
	void	SetMouseDelta( INT nDelta );						// WM_MOUSEWHEEL���� ȣ��

	void	SetClientRect( INT cx, INT cy );					// WM_SIZE���� ȣ��.
	void	SetImageRect( CRect& rcImage ) { m_rcImage = rcImage; }	// �׸� �ε�� ȣ��.

	void	ResetOffset() { m_ptOffset = CPoint( 0, 0 ); }
	void	SetOffset( CPoint& point );							// �ɼ��� ��ġ�� point�� �̵���Ų��.
	void	MoveOffset( CPoint& point );						// �ɼ��� ��ġ�� point'��ŭ' �̵���Ų��.
	
	MARGINRECT PtInMargin( CPoint& point );
	void	MarginMove( MARGINRECT eMarginRect );

	void	SetPtToCenter( CPoint& point );

	BOOL	IsScrollNeed();
	BOOL	IsHScrollNeed();
	BOOL	IsVScrollNeed();
	void	FixOffset();

private:
	void	SetViewRect();										// �ݵ�� ����, Client���� �����Ŀ� ���.
	void	SetFixScaleFactor();
	
private:
	
	CRect	m_rcImage;				// �ε�� �׸��� ũ��.
	CRect   m_rcView;				// ������ ������ ũ��.	( ������ ���� - ���� )
	CRect	m_rcClient;				// ������ ������ ũ��.
	CPoint	m_ptOffset;				// �׸��� ��� �ɼ�.( ���������̹��� ���� )
		
	INT		m_nMargin;				// ���� ( ������ �ȼ� )
	INT		m_nMouseDelta;			
		
	FLOAT	m_fScaleFactor;			// Ȯ�� ��� ����.
	FLOAT	m_fFixXScaleFactor;		// ������ X�� ����.
	FLOAT	m_fFixYScaleFactor;		// ������ Y�� ����.
	
	CScrollView* m_pView;
};
