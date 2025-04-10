#pragma once

#include <vector>
#include "NtlAnimEventData.h"


/// �����̴��� ���Ǵ� ��Ŀ ����ü
struct SSliderMarker
{
    int          m_nPoint;           ///< ��Ŀ�� ����Ű�� ��ġ
    CRect        m_rt;               ///< ��Ŀ�� ����
    SEventAnim*  m_pAnimEvent;       ///< ��Ŀ�� ��Ī�� ������ 
};

typedef std::vector<SSliderMarker> VMarker;

// �޽��� ����
#define EXSM_MARKER_ADD     (WM_USER + 100)
#define EXSM_MARKER_REMOVE  (WM_USER + 101)
#define EXSM_MARKER_SELECT  (WM_USER + 102)
#define EXSM_POS_CHANGED    (WM_USER + 103)
#define EXSM_MARKER_POS_CHANGED (WM_USER + 104)
#define EXSM_MARKER_POS_CHANGE_END (WM_USER + 105)

class CExSliderCtrl : public CSliderCtrl
{
	DECLARE_DYNAMIC(CExSliderCtrl)
private:
	/// Bar ����
	int m_nBarHeight;

	/// Tick �ʺ�
	int m_nTickWidth;

	/// Point �ʺ�
	int m_nPntWidth;

	/// ����Ʈ ����
	int m_nPntHeight;

	/// ��ü ����
	CRect m_rtWnd;

    CRect m_rtMarkerSpace;          ///< ��Ŀ ����
	/// Bar ����
	CRect m_rtBar;

	/// ���� �� ����
	CRect m_rtStart;

	/// ���� �� ����
	CRect m_rtEnd;

	/// Tick ����
	CRect m_rtTick;

	/// ������ ��
	int m_nStartPnt;

	/// ������ ��
	int m_nEndPnt;

    BOOL m_bClickMarker;            ///< ��Ŀ�� Ŭ���Ǿ����� ����
    int  m_nClickMarkerID;          ///< Ŭ���� ��Ŀ�� ID

	/// ���� ���� Ŭ���Ǿ����� ����
	BOOL m_bClickStart;

	/// ���� ���� Ŭ���Ǿ����� ����
	BOOL m_bClickEnd;

	/// Tick�� Ŭ���Ǿ����� ����
	BOOL m_bClickTick;

	/// ���� ���� Ŭ���Ǿ��� ��� ���콺 ��ǥ
	CPoint m_ptClick;	

	/// ���� ��Ʈ��
	CToolTipCtrl m_ctrTip;

	/// ���� ������ �����ߴ��� ����
	BOOL m_bSetRange;

    VMarker m_vMarker;          ///< ��Ŀ���� ����

public:
	CExSliderCtrl();
	virtual ~CExSliderCtrl();

	/**
	������ �����Ѵ�. ������ �����ϰ� �Ǹ� Start Point�� End Point��
	Min���� Max���� ���� �� �����ȴ�.

	* @ param nMin		�ּ� ��
	* @ param nMax		�ִ� ��
	* @ param bRedraw	�ٽ� �׸��� ����
	*/
	void SetRange(int nMin, int nMax, BOOL bRedraw = FALSE);	
	void SetRangeMin(int nMin, BOOL bRedraw = FALSE);	
	void SetRangeMax(int nMax, BOOL bRedraw = FALSE);

	/**
	�������� ���� ���´�. 

	* @ return ������ ��
	*/
	int GetStartPnt(){return m_nStartPnt;};

	/**
	������ ���� �����Ѵ�. ���� �ּ� ������ ���� �� ����, ���� �� ������ Ŭ �� ����.
	�ּ� ������ ���� ��� = �ּ� ������ ����
	���� ������ ū   ��� = ���� ������ ����

	* @ param nVal ���� ��
	*/
	void SetStartPnt(int nVal);

	/**
	�������� ���� ���´�.

	* @ return ���� ��
	*/
	int GetEndPnt(){return m_nEndPnt;};

    

	/**
	���� ���� �����Ѵ�. ���� �ִ� ������ Ŭ �� ����, ������ ������ ���� �� ����.
	�ִ� ������ ū ��� = �ִ� ������ ����
	������ ������ ���� ��� = ������ ������ ����

	* @ param nVal ���� ��
	*/
	void SetEndPnt(int nVal);

    SSliderMarker* GetSelectMarker();           ///< ���� ���õ� ��Ŀ�� ��ȯ�Ѵ�.
    void SelectMarker(int nPos);                ///< ��Ŀ�� �����Ѵ�.
    void AddMarker(int nPos, SEventAnim* pEventAnim = NULL);                   ///< ��Ŀ�� �߰��Ѵ�.
    void RemoveMarker(int nPos);                ///< ������ �ִ� ��Ŀ�� �����Ѵ�.
    void ClearMarker();                         ///< ��� ��Ŀ�� �����Ѵ�.
    void SetSelectMarkerPos(int nPos);          ///< ���õ� ��Ŀ�� ��ġ�� �����Ѵ�.

protected:
	/**
	�����̴� ��Ʈ���� �� �������(ƽ, ��, ���� ����Ʈ ��)�� ������ ����Ѵ�.
	���α׷� �߰��߰��� �� �Լ��� ���� �Ҹ���µ�, �ƹ����� ������ ������
	�ʿ��ҵ� �ʹ�. ��Ʈ���� ����� ������� �ʴ� �̻� ��� ������ ������� 
	�ʱ� �����̴�.
	*/
	void CalcLayout();

	/**
	Pos�� ���� Bar ������ ����� ��ġ�ϴ��� �˱� ���� ����ϴ� �Լ��̴�.

	* @ param rtBar Bar ����
	* @ param nPos	Pos ��
	* @ return		Bar ������ X��ǥ(��ǥ ������ ��ü Ŭ���̾�Ʈ �����̴�.)
	*/
	int PosToPixel(CRect rtBar, int nPos);

	/**
	PosToPixel�� �ݴ� �����̴�. Bar ������ X��ǥ ���� �ָ� �̸� Pos ������ ȯ���Ѵ�.

	* @ param rtBar		Bar ����
	* @ param nPixel	X��ǥ
	* @ return			Pos ��
	*/
	int PixelToPos(CRect rtBar, int nPixel);

	/**
	������ ��ư�� ������ ��� �˾� �޴��� ���� ���� ���Ǵ� �Լ��̴�.
	Start, End�� ���콺�� ������ ���������� ���� ������ ������ ����,
	����ڰ� Ű����� �Է��� �� �ֵ��� ���̾�α� â�� ����.	
	�޴��� �� 3������. ��ü ���� ����, ���� ����, ���� ����.

	* @ param point �޴��� ��� ���� ���콺�� ��ǥ ��
	*/
	void PopupMenu(CPoint point);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);    
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

protected:
	void OnNeedText(NMHDR* pnmh, LRESULT* pResult);
	virtual void PreSubclassWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
    
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};