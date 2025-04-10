#pragma once

#include "Control/PropTree.h"

// CRectInfoDlg ��ȭ �����Դϴ�.

class CRectInfoDlg : public CDialog
{
	DECLARE_DYNCREATE(CRectInfoDlg)

public:
	CRectInfoDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRectInfoDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_RECTINFODLG };

	enum PROPERTY_ID
	{
		PROPERTY_NONE = 0,
		
		PROPERTY_CAPTION,
		PROPERTY_MOUSEPT,
		PROPERTY_GROUP_RECT,
		PROPERTY_RECT_XY,
		PROPERTY_RECT_WH,
		PROPERTY_RGBA
		// For Test
		//PROPERTY_ORIMOUSE,			// ��ȯ�Ǳ� ���� ���콺 ��ǥ.
		//PROPERTY_OFFSET,			// �ɼ�
		//PROPERTY_SRCRECT,			// ������ �ִ� ����
		//PROPERTY_CLIENTRECT			// Ŭ���̾�Ʈ ����
	};

	// Operation
	void	SetMousePoint( CPoint& point );
	void	SetSelectedRect( CRect& rect );
	//void	SetOffset( CPoint& offset );
	//void	SetOriMousePoint( CPoint& point );
	//void	SetSrcRect( CRect& rect );
	//void	SetClientRect( CRect& rect );

protected:
	CPropTree	m_PropertyTree;
	BOOL		m_bInitialized;

protected:
	// Internal Function
	void	InitProperty();		// �׸� ����.

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
