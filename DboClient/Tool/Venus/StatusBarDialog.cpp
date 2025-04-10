// StatusBarDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Venus.h"
#include "StatusBarDialog.h"
#include ".\statusbardialog.h"

#include ".\venusconfig.h"
#include "VenusFramework.h"


// CStatusBarDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CStatusBarDialog, CDialog)
CStatusBarDialog::CStatusBarDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CStatusBarDialog::IDD, pParent)
	, m_fFps(0)
	, m_strTimeSpeed(_T(""))
	, m_nPolygonCount(0)
	, m_nEffectCount(0)
{
}

CStatusBarDialog::~CStatusBarDialog()
{
}

void CStatusBarDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TRACE_LIST, m_TraceList);
	DDX_Text(pDX, IDC_FPS, m_fFps);
	DDX_Control(pDX, IDC_TIME_SPEED, m_TimeSpeedSlider);
	DDX_Text(pDX, IDC_EDIT_TIME_SPEED, m_strTimeSpeed);
	DDX_Control(pDX, IDC_TIME_PAUSE, m_btnTimePause);
	DDX_Text(pDX, IDC_POLYGON_COUNT, m_nPolygonCount);
	DDX_Text(pDX, IDC_EFFECT_COUNT, m_nEffectCount);
	DDX_Control(pDX, IDC_SHOW_GRID, m_ShowGrid);
	DDX_Control(pDX, IDC_SHOW_TERRAIN, m_ShowTerrain);
	DDX_Control(pDX, IDC_SHOW_SKY, m_ShowObject);
	DDX_Control(pDX, IDC_TIME_REPEAT, m_btnTimeRepeat);
}


BEGIN_MESSAGE_MAP(CStatusBarDialog, CDialog)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_TIME_PAUSE, OnBnClickedTimePause)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_SHOW_GRID, OnBnClickedShowGrid)
	ON_BN_CLICKED(IDC_SHOW_SKY, OnBnClickedShowObject)
	ON_BN_CLICKED(IDC_SHOW_TERRAIN, OnBnClickedShowTerrain)
	ON_BN_CLICKED(IDC_TIME_REPEAT, OnBnClickedTimeRepeat)
END_MESSAGE_MAP()

CStatusBarDialog& CStatusBarDialog::GetInstance()
{
	static CStatusBarDialog dlg;
	return dlg;
}

// CStatusBarDialog �޽��� ó�����Դϴ�.

BOOL CStatusBarDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_TimeSpeedSlider.SetRange(1, 50);	
	m_TimeSpeedSlider.SetTic(10);
	m_TimeSpeedSlider.SetTicFreq(5);
	m_TimeSpeedSlider.SetChannelColor(RGB(0, 255, 0));
	m_TimeSpeedSlider.SetPos((int)(CVenusConfig::GetInstance().m_fTimeSpeed * 10.f));

	m_strTimeSpeed.Format("%1.1f", CVenusConfig::GetInstance().m_fTimeSpeed);

	UpdateDymmyButton();

	UpdateTimeButton();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CStatusBarDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

void CStatusBarDialog::InsertTrace(const RwChar* strTrace)
{
	m_TraceList.AddString(strTrace);
}

void CStatusBarDialog::BuildData()
{
	UpdateDymmyButton();
	UpdateTime();
}
void CStatusBarDialog::UpdateDymmyButton()
{
	m_ShowGrid.SetCheck(CVenusConfig::GetInstance().m_bShowGrid);
	m_ShowTerrain.SetCheck(CVenusConfig::GetInstance().m_bShowTerrain);	
	m_ShowObject.SetCheck(FALSE);

	UpdateData(FALSE);
}


void CStatusBarDialog::UpdateFps(RwReal fFps)
{
	m_fFps = fFps;
	UpdateData(FALSE);
}

void CStatusBarDialog::UpdateTime()
{
	m_strTimeSpeed.Format("%1.1f", CVenusConfig::GetInstance().m_fTimeSpeed);
	m_TimeSpeedSlider.SetPos((int)(CVenusConfig::GetInstance().m_fTimeSpeed * 10.f));
	UpdateTimeButton();
}

void CStatusBarDialog::UpdateTimeButton()
{
	m_btnTimePause.SetCheck(CVenusConfig::GetInstance().m_bTimePause);
	m_btnTimeRepeat.SetCheck(CVenusConfig::GetInstance().m_bTimeRepeat);
}

void CStatusBarDialog::UpdateCount(RwInt32 nEffectCount, RwInt32 nPolygonCount)
{
	m_nEffectCount = nEffectCount;
	m_nPolygonCount = nPolygonCount;
	UpdateData(FALSE);
}

void CStatusBarDialog::OnBnClickedTimePause()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CVenusConfig::GetInstance().m_bTimePause = m_btnTimePause.GetCheck();
}
void CStatusBarDialog::OnBnClickedTimeRepeat()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CVenusConfig::GetInstance().m_bTimeRepeat = m_btnTimeRepeat.GetCheck();
}

void CStatusBarDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch(pScrollBar->GetDlgCtrlID())
	{
		case IDC_TIME_SPEED:
		CVenusConfig::GetInstance().m_fTimeSpeed = (float)m_TimeSpeedSlider.GetPos() / 10.f;
		m_strTimeSpeed.Format("%1.1f", CVenusConfig::GetInstance().m_fTimeSpeed);
		UpdateData(FALSE);
		break;
	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CStatusBarDialog::OnBnClickedShowGrid()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CVenusConfig::GetInstance().m_bShowGrid = m_ShowGrid.GetCheck();
}

void CStatusBarDialog::OnBnClickedShowObject()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.	
	CVenusFramework::GetInstance().ShowObject(m_ShowObject.GetCheck());
}

void CStatusBarDialog::OnBnClickedShowTerrain()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CVenusConfig::GetInstance().m_bShowTerrain = m_ShowTerrain.GetCheck();
	CVenusFramework::GetInstance().ShowTerrain(CVenusConfig::GetInstance().m_bShowTerrain);
}

