// AnimAssetAnimSetDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CharacterEditor.h"
#include ".\animationsetdialog.h"
#include "NewAssetOpen.h"
#include "NtlPLResourceManager.h"

// CAnimAssetAnimSetDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAnimationSetDialog, CDialog)
CAnimationSetDialog::CAnimationSetDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimationSetDialog::IDD, pParent)
{
}

CAnimationSetDialog::~CAnimationSetDialog()
{
}

void CAnimationSetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ANIM_PROPERTY_LIST, m_propertyControl);
}


BEGIN_MESSAGE_MAP(CAnimationSetDialog, CDialog)
END_MESSAGE_MAP()


// CAnimAssetAnimSetDlg �޽��� ó�����Դϴ�.

BOOL CAnimationSetDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	theApp.m_pAnimationSetDialog = this;

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CAnimationSetDialog::UpdateTree()
{
	m_propertyAnimDataManager.SetData(&m_propertyAnimData);
	m_propertyAnimDataManager.AttachCallBack(this);
	m_propertyControl.SetPropertyItemManager(&m_propertyAnimDataManager);	
}

void CAnimationSetDialog::SetAnimDataInfoChange(SToolAnimData *pToolAnimData)
{
	m_propertyControl.ResetContent();
	m_propertyAnimDataManager.UpdateData(pToolAnimData);
	
	m_propertyAnimDataManager.SetData(&m_propertyAnimData);
	m_propertyAnimDataManager.AttachCallBack(this);
	m_propertyControl.SetPropertyItemManager(&m_propertyAnimDataManager);
	theApp.m_DboApplication.SetAllChannelChangeAnimation(pToolAnimData->uiAnimKey);
}

void CAnimationSetDialog::SetAnimationFileOpen(SToolAnimData *pToolAnimData)
{
	char curDirectory[256];
	GetCurrentDirectory(strlen(curDirectory), curDirectory);

	CNewAssetOpen dlg(TRUE);
	if(dlg.DoModal() != IDOK)
		return;
	else
	{
		SetCurrentDirectory(curDirectory);
		if(pToolAnimData != NULL)
		{
			pToolAnimData->pAnimData->strAnimFileName = dlg.GetFileName();
			
			if(pToolAnimData->pAnimData->pAnimRes)
			{
				CNtlPLResourceManager::GetInstance()->UnLoad(pToolAnimData->pAnimData->pAnimRes);
				pToolAnimData->pAnimData->pAnimRes = NULL;

			}
			SetAnimDataInfoChange(pToolAnimData);

			//theApp.m_DboApplication.SetAllChannelChangeAnimation(pToolAnimData->uiAnimKey);
		}
	}
}
