// PointCustomEditDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DTEditor.h"
#include "PointCustomEditDlg.h"
#include "CustomItems.h"
#include "DTEditorGlobal.h"

// simulation
#include "precomp_ntlsimulation.h"
#include "NtlDTProp.h"



#define IDC_PROPERTY_CUSTOM				201


#define CUSTOM_ITEM_SOUND_LOOP			1000
#define FILEBOX_FILTER_SOUND			"Sound File(*.wav;*.ogg;*.mp3)|*.wav;*.ogg;*.mp3||"

#define CUSTOM_CURVE_RECT_SIZE			20
#define CUSTOM_CURVE_RECT_INTERVAL		20
#define CUSTOM_CURVE_SEL_RECT_SIZE		24


// CPointCustomEditDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPointCustomEditDlg, CDialog)

CPointCustomEditDlg::CPointCustomEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPointCustomEditDlg::IDD, pParent)
{
	m_nCurveNum = 3;
	m_nSelIdx	= 0;
}

CPointCustomEditDlg::~CPointCustomEditDlg()
{
}

void CPointCustomEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSVE_SOUND_LOOP, m_btnLoop);
	DDX_Control(pDX, IDC_CUSVE_SOUND_FILENAME, m_editFileName);
}


BEGIN_MESSAGE_MAP(CPointCustomEditDlg, CDialog)
	ON_WM_SIZE()
	ON_MESSAGE(XTPWM_PROPERTYGRID_NOTIFY, OnAttributeNotify)
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_CUSVE_SOUND_LOOP, &CPointCustomEditDlg::OnBnClickedCusveSoundLoop)
	ON_EN_CHANGE(IDC_CUSVE_SOUND_FILENAME, &CPointCustomEditDlg::OnEnChangeCusveSoundFilename)
	ON_BN_CLICKED(IDC_CUSVE_SOUND_CLEAR, &CPointCustomEditDlg::OnBnClickedCusveSoundClear)
END_MESSAGE_MAP()

void CPointCustomEditDlg::OnPropUpdate(void)
{
	m_nCurveNum = 0;
	m_nSelIdx	= 0;

	m_btnLoop.SetCheck(FALSE);
	SetDlgItemText(IDC_CUSVE_SOUND_FILENAME, "");

	Invalidate(TRUE);
}

void CPointCustomEditDlg::OnPropSelectUpdate(int nSx, int nEx)
{
	CNtlDTSpline *pDTSplineProp = (CNtlDTSpline*)GetActiveDTProp();
	if(pDTSplineProp == NULL)
		return;

	const SSplineProp *pSplineProp = pDTSplineProp->GetSplineProp();
	SSplineCustomData *pCustomData = pDTSplineProp->GetSplineCustomData(nSx*pSplineProp->iCurveSubDivision);

	m_nCurveNum = pSplineProp->iCurveSubDivision;
	m_nSelIdx	= 0;

	m_btnLoop.SetCheck(FALSE);
	SetDlgItemText(IDC_CUSVE_SOUND_FILENAME, "");

	if(pCustomData)
	{
		if(pCustomData->bSoundLoop)
			m_btnLoop.SetCheck(TRUE);

		if(strlen(pCustomData->chSoundFile) > 0)
			SetDlgItemText(IDC_CUSVE_SOUND_FILENAME, pCustomData->chSoundFile);
	}
	
	Invalidate(TRUE);
}

void CPointCustomEditDlg::InData(void)
{
	CNtlDTSpline *pDTSplineProp = (CNtlDTSpline*)GetActiveDTProp();
	if(pDTSplineProp == NULL)
		return;

	int nSelSx, nSelEx;
	GetActiveSelectControlPoint(nSelSx, nSelEx);

	const SSplineProp *pSplineProp = pDTSplineProp->GetSplineProp();
	SSplineCustomData *pCustomData = pDTSplineProp->GetSplineCustomData(nSelSx*pSplineProp->iCurveSubDivision + m_nSelIdx);

	m_btnLoop.SetCheck(FALSE);
	SetDlgItemText(IDC_CUSVE_SOUND_FILENAME, "");

	if(pCustomData)
	{
		if(pCustomData->bSoundLoop)
			m_btnLoop.SetCheck(TRUE);

		if(strlen(pCustomData->chSoundFile) > 0)
			SetDlgItemText(IDC_CUSVE_SOUND_FILENAME, pCustomData->chSoundFile);
	}
}

void CPointCustomEditDlg::OutData(void)
{
	CNtlDTSpline *pDTSplineProp = (CNtlDTSpline*)GetActiveDTProp();
	if(pDTSplineProp == NULL)
		return;

	int nSelSx, nSelEx;
	GetActiveSelectControlPoint(nSelSx, nSelEx);

	RwBool bLoop;
	if(m_btnLoop.GetCheck())
		bLoop = TRUE;
	else
		bLoop = FALSE;

	CString str;
	GetDlgItemText(IDC_CUSVE_SOUND_FILENAME, str);

	if(str.GetLength() > 0 && str.GetLength() < SPLINE_CUSTOM_SOUND_FILNE_LEN)
	{
		const SSplineProp *pSplineProp = pDTSplineProp->GetSplineProp();
		pDTSplineProp->SetSplineCustomSoundData(nSelSx*pSplineProp->iCurveSubDivision + m_nSelIdx, 
												(LPCTSTR)str, bLoop);
	}
}

CRect CPointCustomEditDlg::GetCurveRect(INT nIdx)
{
	CRect rt;
	rt.SetRect(m_rtCurveArea.left + (CUSTOM_CURVE_RECT_SIZE + CUSTOM_CURVE_RECT_INTERVAL)*nIdx, 
				m_rtCurveArea.top,
				m_rtCurveArea.left + (CUSTOM_CURVE_RECT_SIZE + CUSTOM_CURVE_RECT_INTERVAL)*nIdx+CUSTOM_CURVE_RECT_SIZE, 
				m_rtCurveArea.top + CUSTOM_CURVE_RECT_SIZE);

	return rt;
}

// CPointCustomEditDlg �޽��� ó�����Դϴ�.

BOOL CPointCustomEditDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	CRect rtCustom, rtDlg, rtCurve;

	GetClientRect(rtDlg);
	ClientToScreen(rtDlg);

	CWnd *pCurveWnd = GetDlgItem(IDC_CUSTOM_CURVE_POINT);
	pCurveWnd->GetClientRect(rtCurve);
	pCurveWnd->ClientToScreen(rtCurve);
		
	m_rtCurveArea.SetRect(rtCurve.left - rtDlg.left,
						  rtCurve.top - rtDlg.top, 
						  rtCurve.left - rtDlg.left + rtCurve.Width(),
						  rtCurve.top - rtDlg.top + rtCurve.Height());

	m_rtCurveArea.left += 10;
	m_rtCurveArea.top = m_rtCurveArea.top + (m_rtCurveArea.Height() - CUSTOM_CURVE_RECT_SIZE)/2;
	m_rtCurveArea.bottom = m_rtCurveArea.top + CUSTOM_CURVE_RECT_SIZE;

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CPointCustomEditDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

LRESULT CPointCustomEditDlg::OnAttributeNotify(WPARAM wParam, LPARAM lParam)
{
    if(wParam == XTP_PGN_ITEMVALUE_CHANGED)
    {
//		OnItemValueChangedGridNotify(wParam, lParam);
	}
	else if(wParam == XTP_PGN_EDIT_CHANGED)
	{
//		OnEditChangedGridNotify(wParam, lParam);
	}

	return 0;
}

void CPointCustomEditDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CDialog::OnPaint()��(��) ȣ������ ���ʽÿ�.

	CRect rt;

	if(m_nCurveNum > 0)
	{
		for(INT i = 0; i < m_nCurveNum; i++)
		{
			rt = GetCurveRect(i);

			if(i == m_nSelIdx)
			{
				dc.FillSolidRect(rt, RGB(170, 13, 60));
				dc.Draw3dRect(rt, RGB(232, 17, 82), RGB(87, 6, 31));
			}
			else
			{
				dc.FillSolidRect(rt, RGB(170, 170, 60));
				dc.Draw3dRect(rt, RGB(232, 232, 82), RGB(87, 87, 31));
			}
		}
	}
}

void CPointCustomEditDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

void CPointCustomEditDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(m_nCurveNum > 0)
	{
		for(INT i = 0; i < m_nCurveNum; i++)
		{
			CRect rt = GetCurveRect(i);
			if(rt.PtInRect(point))
			{
				m_nSelIdx = i;
				InData();
				Invalidate(TRUE);
				break;
			}
		}
	}
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialog::OnLButtonDown(nFlags, point);
}

void CPointCustomEditDlg::OnBnClickedCusveSoundLoop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	OutData();
}

void CPointCustomEditDlg::OnEnChangeCusveSoundFilename()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� �������ϰ�  ����ũ�� OR �����Ͽ� ������
	// ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ���ؾ߸�
	// �ش� �˸� �޽����� �����ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	OutData();
}

void CPointCustomEditDlg::OnBnClickedCusveSoundClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	m_btnLoop.SetCheck(FALSE);
	SetDlgItemText(IDC_CUSVE_SOUND_FILENAME, "");

	CNtlDTSpline *pDTSplineProp = (CNtlDTSpline*)GetActiveDTProp();
	if(pDTSplineProp == NULL)
		return;

	int nSelSx, nSelEx;
	GetActiveSelectControlPoint(nSelSx, nSelEx);
	const SSplineProp *pSplineProp = pDTSplineProp->GetSplineProp();
	pDTSplineProp->ClearSplineCustomData(nSelSx*pSplineProp->iCurveSubDivision + m_nSelIdx);
}
