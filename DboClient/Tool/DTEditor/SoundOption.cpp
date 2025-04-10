// SoundOption.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DTEditor.h"
#include "SoundOption.h"

#include "NtlSoundManager.h"
// CSoundOption ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSoundOption, CDialog)

CSoundOption::CSoundOption(CWnd* pParent /*=NULL*/)
	: CDialog(CSoundOption::IDD, pParent)
{

}

CSoundOption::~CSoundOption()
{
}

void CSoundOption::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_BGM, m_BtnCheckBGMMute);
	DDX_Control(pDX, IDC_CHECK_WEATHER_EFFECT, m_BtnCheckWeatherEffect);
	DDX_Control(pDX, IDC_CHECK_WEATHER_MUSIC, m_BtnCheckWeatherMusic);
	DDX_Control(pDX, IDC_SLIDER_BGM, m_ScrollbarBGMVolume);
	DDX_Control(pDX, IDC_SLIDER_WEATHER_EFFECT, m_ScrollbarWeatherEffect);
	DDX_Control(pDX, IDC_SLIDER_WEATHER_MUSIC, m_ScrollbarWeatherMusic);
}

BOOL CSoundOption::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	float fBGMVolume			= GetSoundManager()->GetGroupVolume(CHANNEL_GROUP_BGM);
	float fWeatherEffectVolume	= GetSoundManager()->GetGroupVolume(CHANNEL_GROUP_WEATHER_EFFECT_SOUND);
	float fWeatherMusicVolume	= GetSoundManager()->GetGroupVolume(CHANNEL_GROUP_WEATHER_MUSIC);

	bool bBGMMute				= GetSoundManager()->IsMute(CHANNEL_GROUP_BGM);
	bool bWeatherEffectMute		= GetSoundManager()->IsMute(CHANNEL_GROUP_WEATHER_EFFECT_SOUND);
	bool bWeatherMusicMute		= GetSoundManager()->IsMute(CHANNEL_GROUP_WEATHER_MUSIC);


	// Music�� ������ �ʹ� Ŀ�� 50% �ٿ��� ����
	m_ScrollbarBGMVolume		.SetRangeMax(50);
	m_ScrollbarWeatherEffect	.SetRangeMax(50);
	m_ScrollbarWeatherMusic		.SetRangeMax(50);

	m_ScrollbarBGMVolume		.SetPos((int)(fBGMVolume * 100.f));
	m_ScrollbarWeatherEffect	.SetPos((int)(fWeatherEffectVolume * 100.f));
	m_ScrollbarWeatherMusic		.SetPos((int)(fWeatherMusicVolume * 100.f));


	if( bBGMMute )
		m_BtnCheckBGMMute.SetCheck(BST_CHECKED);
	else
		m_BtnCheckBGMMute.SetCheck(BST_UNCHECKED);

	if( bWeatherEffectMute )
		m_BtnCheckWeatherEffect.SetCheck(BST_CHECKED);
	else
		m_BtnCheckWeatherEffect.SetCheck(BST_UNCHECKED);

	if( bWeatherMusicMute )
		m_BtnCheckWeatherMusic.SetCheck(BST_CHECKED);
	else
		m_BtnCheckWeatherMusic.SetCheck(BST_UNCHECKED);


	UpdateData(FALSE);

	return TRUE;
}

BEGIN_MESSAGE_MAP(CSoundOption, CDialog)
	ON_BN_CLICKED(IDOK, &CSoundOption::OnBnClicked_OK)
	ON_BN_CLICKED(IDC_CHECK_BGM, &CSoundOption::OnBnClicked_CheckBgm)
	ON_BN_CLICKED(IDC_CHECK_WEATHER_EFFECT, &CSoundOption::OnBnClicked_CheckWeatherEffect)
	ON_BN_CLICKED(IDC_CHECK_WEATHER_MUSIC, &CSoundOption::OnBnClicked_CheckWeatherMusic)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CSoundOption �޽��� ó�����Դϴ�.

void CSoundOption::OnBnClicked_CheckBgm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if( BST_CHECKED == m_BtnCheckBGMMute.GetCheck() )
	{
		GetSoundManager()->SetMute(CHANNEL_GROUP_BGM, true);
	}
	else
	{
		GetSoundManager()->SetMute(CHANNEL_GROUP_BGM, false);
	}
}

void CSoundOption::OnBnClicked_CheckWeatherEffect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if( BST_CHECKED == m_BtnCheckWeatherEffect.GetCheck() )
	{
		GetSoundManager()->SetMute(CHANNEL_GROUP_WEATHER_EFFECT_SOUND, true);
	}
	else
	{
		GetSoundManager()->SetMute(CHANNEL_GROUP_WEATHER_EFFECT_SOUND, false);
	}
}

void CSoundOption::OnBnClicked_CheckWeatherMusic()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	if( BST_CHECKED == m_BtnCheckWeatherMusic.GetCheck() )
	{
		GetSoundManager()->SetMute(CHANNEL_GROUP_WEATHER_MUSIC, true);
	}
	else
	{
		GetSoundManager()->SetMute(CHANNEL_GROUP_WEATHER_MUSIC, false);
	}
}

void CSoundOption::OnBnClicked_OK()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}

void CSoundOption::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if( pScrollBar )
	{
		UpdateData(TRUE);

		if( pScrollBar == (CScrollBar*)&m_ScrollbarBGMVolume )
		{
			int iPos = m_ScrollbarBGMVolume.GetPos();
			GetSoundManager()->SetGroupVolume(CHANNEL_GROUP_BGM, ((float)iPos) / 100.f);
		}
		else if( pScrollBar == (CScrollBar*)&m_ScrollbarWeatherEffect )
		{
			int iPos = m_ScrollbarWeatherEffect.GetPos();
			GetSoundManager()->SetGroupVolume(CHANNEL_GROUP_WEATHER_EFFECT_SOUND, ((float)iPos) / 100.f);
		}
		else if( pScrollBar == (CScrollBar*)&m_ScrollbarWeatherMusic )
		{
			int iPos = m_ScrollbarWeatherMusic.GetPos();
			GetSoundManager()->SetGroupVolume(CHANNEL_GROUP_WEATHER_MUSIC, ((float)iPos) / 100.f);
		}
	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
