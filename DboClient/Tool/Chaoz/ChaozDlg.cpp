// ChaozDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Chaoz.h"
#include "ChaozDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CChaozDlg ��ȭ ����




CChaozDlg::CChaozDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChaozDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChaozDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_Edit_PitchRate);
	DDX_Control(pDX, IDC_COMBO1, m_Combo_Channel);
	DDX_Control(pDX, IDC_EDIT3, m_Edit_FileName);
	DDX_Control(pDX, IDC_EDIT4, m_Edit_SoundPosX);
	DDX_Control(pDX, IDC_EDIT5, m_Edit_SoundPosY);
	DDX_Control(pDX, IDC_EDIT6, m_Edit_SoundPosZ);
	DDX_Control(pDX, IDC_EDIT7, m_Edit_Min);
	DDX_Control(pDX, IDC_EDIT8, m_Edit_Max);
	DDX_Control(pDX, IDC_EDIT9, m_Edit_Volume);
	DDX_Control(pDX, IDC_CHECK1, m_CheckBox_Loop);
	DDX_Control(pDX, IDC_EDIT1, m_Static_Message);
}

BEGIN_MESSAGE_MAP(CChaozDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON2, &CChaozDlg::OnBnClickedButton_CheatPlayManyEffectSound)
	ON_BN_CLICKED(IDC_BUTTON3, &CChaozDlg::OnBnClickedButton_CheatPitchRate)
	ON_BN_CLICKED(IDC_BUTTON5, &CChaozDlg::OnBnClickedButton_OpenSound)
	ON_BN_CLICKED(IDC_BUTTON1, &CChaozDlg::OnBnClickedButton_PlaySound)
	ON_BN_CLICKED(IDC_BUTTON4, &CChaozDlg::OnBnClickedButton_StopSound)
END_MESSAGE_MAP()


// CChaozDlg �޽��� ó����

BOOL CChaozDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_Combo_Channel.AddString(_T("2D Sound"));
	m_Combo_Channel.AddString(_T("3D Sound"));

	m_Combo_Channel.SetCurSel(0);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CChaozDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CChaozDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CChaozDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChaozDlg::OnBnClickedButton_CheatPlayManyEffectSound()
{
	static bool bPlay = false;

	if( bPlay )
	{
		SendMessageToDBO("/stopmanysound");
	}
	else
	{
		SendMessageToDBO("/playmanysound");
	}
	
	bPlay = !bPlay;
}

void CChaozDlg::OnBnClickedButton_CheatPitchRate()
{
	CString strText;
	float fNumber;

	m_Edit_PitchRate.GetWindowText(strText);
	fNumber = (float)atof( strText.GetString() );
	if( fNumber == 0 )
	{
		DisplayMessage( _T("Error! Wrong number") );
		return;
	}

	char acBuffer[24] = "";
	sprintf_s(acBuffer, 24, "/minmaxrate %f", fNumber);
	SendMessageToDBO(acBuffer);
}

void CChaozDlg::OnBnClickedButton_OpenSound()
{
	TCHAR chCurDir[1024];
	GetCurrentDirectory(1024, chCurDir);

	CFileDialog	LoadDlg( TRUE, _T( "dtf" ), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
						_T( "All Files (*.*)|*.*||" ), NULL );

	if( LoadDlg.DoModal() == IDOK )
	{
		CString strFull			= LoadDlg.GetPathName();
		char acBuffer[1024] = "";
		char* pFindText = NULL;
	
		sprintf_s(acBuffer, 1024, "%s", strFull.GetString());
		pFindText = strstr(acBuffer, "DBO_Resource\\sound\\");

		if( pFindText )
		{
			m_Edit_FileName.SetWindowText( pFindText + strlen("DBO_Resource\\sound\\") );
		}
		else
		{
			DisplayMessage( _T("Error! Input file name under 'DBO_Resource\sound\' folder") );
		}
	}

	SetCurrentDirectory(chCurDir);
}

void CChaozDlg::OnBnClickedButton_PlaySound()
{
	int iComboBoxChannel = m_Combo_Channel.GetCurSel();
	if( iComboBoxChannel == LB_ERR )
	{
		DisplayMessage( _T("Error! Input channel") );
		return;
	}

	// Dbo cleint���� �޾Ƶ��̴� ���� 1, 2�̴�
	++iComboBoxChannel;

	CString strFileName;
	m_Edit_FileName.GetWindowText(strFileName);
	if( strFileName.IsEmpty() )
	{
		DisplayMessage( _T("Error! Input file name under 'DBO_Resource\sound\' folder") );
		return;
	}

	char acBuffer[128] = "";
	if( iComboBoxChannel == 0 )
	{
		sprintf_s(acBuffer, 128, "/playsound %d %s", iComboBoxChannel, strFileName.GetString());
		SendMessageToDBO(acBuffer);
		return;
	}


	CString strPosX, strPosY, strPosZ, strMin, strMax, strVolume, strLoop;

	m_Edit_SoundPosX.GetWindowText(strPosX);
	m_Edit_SoundPosY.GetWindowText(strPosY);
	m_Edit_SoundPosZ.GetWindowText(strPosZ);
	m_Edit_Min.GetWindowText(strMin);
	m_Edit_Max.GetWindowText(strMax);
	m_Edit_Volume.GetWindowText(strVolume);
	m_CheckBox_Loop.GetWindowText(strLoop);

	// soundmanager�� play �Լ��� ����Ʈ ������ �ʱ�ȭ �صξ�
	// ������ ���� �Է¹��� ���ߴ��� ���θ� �Ǵ��ϴ� �б⸦ �α� �ʰ�
	// �ѹ��� �޼����� ���� �� �ֵ��� �Ѵ�.
	float fPosX = 0.f;
	float fPosY = 0.f;
	float fPosZ = 0.f;
	float fMin = 10.f;
	float fMax = 50.f;
	float fVolume = 1.f;
	int iLoop = 0;
	float fTemp;

	if( strPosX.IsEmpty() )
	{
		DisplayMessage( _T("Error! Input position x") );
		return;
	}
	else
	{
		fTemp = (float)atof(strPosX.GetString());
		if( fTemp == 0 )
		{
			DisplayMessage( _T("Error! Input position x") );
			return;
		}

		fPosX = fTemp;
	}


	if( strPosY.IsEmpty() )
	{
		DisplayMessage( _T("Error! Input position y") );
		return;
	}
	else
	{
		fTemp = (float)atof(strPosY.GetString());
		if( fTemp == 0 )
		{
			DisplayMessage( _T("Error! Input position y") );
			return;
		}

		fPosY = fTemp;
	}

	if( strPosZ.IsEmpty() )
	{
		DisplayMessage( _T("Error! Input position z") );
		return;
	}
	else
	{
		fTemp = (float)atof(strPosZ.GetString());
		if( fTemp == 0 )
		{
			DisplayMessage( _T("Error! Input position z") );
			return;
		}

		fPosZ = fTemp;
	}

	if( strMin.IsEmpty() )
	{
		DisplayMessage( _T("Error! Input position z") );
		return;
	}
	else
	{
		fTemp = (float)atof(strMin.GetString());
		if( fTemp == 0 )
		{
			DisplayMessage( _T("Error! Input position z") );
			return;
		}

		fMin = fTemp;
	}

	if( strMax.IsEmpty() )
	{
		DisplayMessage( _T("Error! Input min distance") );
		return;
	}
	else
	{
		fTemp = (float)atof(strMax.GetString());
		if( fTemp == 0 )
		{
			DisplayMessage( _T("Error! Input min distance") );
			return;
		}

		fMin = fTemp;
	}

	if( strVolume.IsEmpty() )
	{
		DisplayMessage( _T("Error! Input volume") );
		return;
	}
	else
	{
		fTemp = (float)atof(strVolume.GetString());
		if( fTemp == 0 )
		{
			DisplayMessage( _T("Error! Input volume") );
			return;
		}

		fVolume = fTemp;
	}

	iLoop = m_CheckBox_Loop.GetCheck();

	sprintf_s(acBuffer, 128, "/playsound %d %s %f %f %f %d %f %f %f",
			  iComboBoxChannel, strFileName.GetString(), fPosX, fPosY, fPosZ, iLoop, fVolume, fMin, fMax);
	SendMessageToDBO(acBuffer);
}

void CChaozDlg::OnBnClickedButton_StopSound()
{
	SendMessageToDBO("/stopsound");
}

bool CChaozDlg::SendMessageToDBO(const char* pMessage)
{
	HWND hWnd = ::FindWindow(NULL, _T("DragonBallOnline") );
	if( hWnd == NULL )
	{
		DisplayMessage( _T("Error! Dbo cleint is not operating") );
		return false;
	}

	COPYDATASTRUCT cds;
	static char acBuffer[1024] = "";

	cds.dwData		= 0;
	cds.cbData		= (DWORD)strlen(pMessage);
	cds.lpData		= (VOID*)pMessage;

	::SendMessage(hWnd, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&cds);

	DisplayMessage( _T("") );
	return true;
}

void CChaozDlg::DisplayMessage(_TCHAR* pText)
{
	m_Static_Message.SetWindowText(pText);
}