// PeHeightPopup.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NtlWE.h"
#include "PeHeightPopup.h"


// CPeHeightPopup ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPeHeightPopup, CDialog)

CPeHeightPopup::CPeHeightPopup(CWnd* pParent /*=NULL*/)
	: CDialog(CPeHeightPopup::IDD, pParent)
	, m_strValue(_T(""))
{

}

CPeHeightPopup::~CPeHeightPopup()
{
}

void CPeHeightPopup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PE_HEIGHT, m_strValue);
}


BEGIN_MESSAGE_MAP(CPeHeightPopup, CDialog)
	ON_BN_CLICKED(IDOK, &CPeHeightPopup::OnBnClickedOk)
END_MESSAGE_MAP()


// CPeHeightPopup �޽��� ó�����Դϴ�.

BOOL CPeHeightPopup::OnInitDialog()
{
	CDialog::OnInitDialog();

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BOOL CPeHeightPopup::PreTranslateMessage(MSG* pMsg)
{
	// prevent keys; escape, return
	if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_ESCAPE:
			{
				return true;
				break;
			}
		case VK_RETURN:
			{
				return true;
				break;
			}
		default:
			break;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

LRESULT CPeHeightPopup::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CDialog::WindowProc(message, wParam, lParam);
}
void CPeHeightPopup::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);

 	m_fValue = static_cast<RwReal>(::atof(m_strValue.GetBuffer(0)));

	OnOK();
}
