// PagePC.cpp : implementation file
//

#include "stdafx.h"
#include "ModelTool.h"
#include "ModelToolApplication.h"
#include "NtlPLCharacterParser.h"
#include "PagePC.h"
#include "BottomToolView.h"
#include "RightToolView.h"
#include "AnimToolView.h"

#define PAGE_HEIGHT_BOTTOM_CTRL  120

// CPagePC dialog
CPagePC* CPagePC::m_pInstance = NULL;

IMPLEMENT_DYNAMIC(CPagePC, CPropertyPage)

CPagePC::CPagePC()
	: CPropertyPage(CPagePC::IDD)
{
    m_pImageList         = NULL;
    m_pCharacterProperty = NULL;
    m_vCharacter.clear();
}

CPagePC::CPagePC(int nEnum)
    : CPropertyPage(nEnum)
{
    m_pImageList         = NULL;
    m_pCharacterProperty = NULL;
}

CPagePC::~CPagePC()
{
    for(size_t i = 0; i < m_vCharacter.size(); ++i)
    {
        CMTCharacter* pCharacter = m_vCharacter[i];
        if(pCharacter)
        {
            pCharacter->Destroy();
            delete pCharacter;
            pCharacter = NULL;
        }
    }
    m_vCharacter.clear();

    if(m_pImageList)
    { 
        delete m_pImageList;
        m_pImageList = NULL;
    }
}

void CPagePC::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TREE_PC, m_treePC);
    DDX_Control(pDX, IDC_EDIT_SCRIPTFILE, m_edScriptFileName);
    DDX_Control(pDX, IDC_EDIT_CLUMPFILE, m_edClumpFileName);    
    DDX_Control(pDX, IDC_BT_SET_CLUMP, m_btLoadClump);
    DDX_Control(pDX, IDC_BUTTON1, m_btSaveScript);
    DDX_Control(pDX, IDC_BT_SAVE_ALL, m_btSaveAll);
}


BEGIN_MESSAGE_MAP(CPagePC, CPropertyPage)
    ON_WM_CONTEXTMENU()    
    ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_PC, &CPagePC::OnTvnSelchangedTreePc)
    ON_BN_CLICKED(IDC_BT_SET_CLUMP, &CPagePC::OnBnClickedBtSetClump)
    ON_BN_CLICKED(IDC_BUTTON1, &CPagePC::OnBnClickedButton1)
    ON_COMMAND(ID_MENU_LOAD_SCRIPT, &CPagePC::OnMenuLoadScript)    
    ON_WM_DESTROY()    
    ON_BN_CLICKED(IDC_BT_SAVE_ALL, &CPagePC::OnBnClickedBtSaveAll)    
    ON_WM_SIZE()
END_MESSAGE_MAP()


// CPagePC message handlers

BOOL CPagePC::OnInitDialog()
{
    USES_CONVERSION;

    CPropertyPage::OnInitDialog();

    m_treePC.SetRoot(L"PC");
    m_treePC.SetParent(this);
    m_btSaveScript.EnableWindow(FALSE);

    m_pInstance = this;
    
    CString sWorkFolder = A2W(CModelToolApplication::GetInstance()->GetWorkDir());
    sWorkFolder += L"\\TreePC.xml";
    m_treePC.LoadTree((LPWSTR)(LPCWSTR)sWorkFolder);

    // Save�� �����̸��� �����Ѵ�.
    m_sSaveFolderName = A2W(CModelToolApplication::GetInstance()->GetWorkDir());
    m_sSaveFolderName += L"\\Character\\";

    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

void CPagePC::OnContextMenu(CWnd* pWnd, CPoint point)
{
    m_treePC.OnContextMenu(pWnd, point);
}

void CPagePC::OnTvnSelchangedTreePc(NMHDR *pNMHDR, LRESULT *pResult)
{
    USES_CONVERSION;

    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    
    // ��� ��ȯ�� ������ ������ �����Ѵ�.
    HTREEITEM hItem =  pNMTreeView->itemOld.hItem;
    int nImage = 0, nSelectedImage = 0;
    m_treePC.GetItemImage(hItem, nImage, nSelectedImage);

    if(nImage == 3)
    {
        //CString oldScriptName = m_treePC.GetItemText(hItem);
        //if(oldScriptName != L"")
        //{
        //    OnSaveScript(oldScriptName, FALSE);
        //}

        // ������ ĳ���͸� ȭ�鿡�� �����Ѵ�.
        CMTCharacter* pCharacter = (CMTCharacter*)m_treePC.GetItemData(hItem);
        if(pCharacter)
        {
            pCharacter->SetVisible(FALSE);
        }
    }
    
    // ��ũ��Ʈ ��尡 ���õǾ����� ���ϳ����� ǥ���Ѵ�.
    CString sScriptFileName = m_treePC.SelectScriptName();
    if(sScriptFileName != L"")
    {
        m_edScriptFileName.SetWindowText(sScriptFileName);
        m_edClumpFileName.SetWindowText(L"");

        if(!m_treePC.GetItemData(m_treePC.GetSelectedItem()) && sScriptFileName == L"New Script")
        {
            // �ʱ�ȭ            
            CBottomToolView::GetInstance()->SetInit(NULL);
            CRightToolView::GetInstance()->SetInit(NULL);
            CAnimToolView::GetInstance()->SetInit(NULL, NULL); 
            m_edScriptFileName.SetWindowText(L"New Script");
            m_edClumpFileName.SetWindowText(L"");            
        }
        else
        {
            OnDisplayScriptInfo(sScriptFileName);                        
        }

        m_btLoadClump.EnableWindow(TRUE);        
    }
    else
    {
       m_edScriptFileName.SetWindowText(L"");
       m_edClumpFileName.SetWindowText(L"");       
       m_btLoadClump.EnableWindow(FALSE);               
    }

    *pResult = 0;
}

BOOL CPagePC::OnDisplayScriptInfo(CString strFileName)
{
    USES_CONVERSION;

    // ������ Ʈ���� ������ ĳ���Ͱ� �ִ��� Ȯ���Ѵ�
    CMTCharacter* pCharacter = NULL;
    pCharacter = (CMTCharacter*)m_treePC.GetItemData(m_treePC.GetSelectedItem());
    if(pCharacter)
    {
        m_pCharacterProperty = pCharacter->GetProperty();
    }
    else
    {

        std::string strFilePath = CModelToolApplication::GetInstance()->GetWorkDir();
        strFilePath += "\\Character\\";
        strFilePath += W2A(strFileName);

        // ������ ������ ĳ���� �ν��ϰ� ������ �߰��Ͽ� �ش�.
        pCharacter = new CMTCharacter;
        pCharacter->Create();
        m_treePC.SetItemData(m_treePC.GetSelectedItem(), (DWORD_PTR)pCharacter);   
        m_vCharacter.push_back(pCharacter);
        m_pCharacterProperty = pCharacter->GetProperty();
        RwBool bReturn = m_pCharacterProperty->LoadScript(strFilePath);
        if(bReturn)
        {   
            std::string sClumpFilePath = CModelToolApplication::GetInstance()->GetWorkDir();
            sClumpFilePath += "\\";
            //sClumpFilePath += m_pCharacterProperty->GetMeshPath();
            sClumpFilePath += m_pCharacterProperty->GetBaseMeshFileName();
            RwBool bReturn = pCharacter->LoadClump((RwChar*)sClumpFilePath.c_str());
            if(!bReturn)
            {
                MessageBox(L"Clump File Open Fail");
                return bReturn;
            }                   
        }        
    }

    pCharacter->SetVisible(TRUE);
    pCharacter->GetProperty()->GetBoneScaleData()->bBoneScale = TRUE;

    CModelToolApplication::GetInstance()->SetEditChar(pCharacter);

    CString strMeshName = A2W(m_pCharacterProperty->GetBaseMeshFileName().c_str());
    m_edClumpFileName.SetWindowText(strMeshName);


    // �ϴܺ�� �����ʺ信 ������ �����Ѵ�.
    CBottomToolView::GetInstance()->SetInit(pCharacter);
    CRightToolView::GetInstance()->SetInit(pCharacter);


    // ������ UI ����κ� �߰�
    CRightToolView::GetInstance()->SetEnable(CRightToolView::ENABLE_ANIMSET);
    m_btSaveScript.EnableWindow(TRUE);
    m_btSaveAll.EnableWindow(TRUE);

    return TRUE;
}


void CPagePC::OnBnClickedBtSetClump()
{
    // Clump ������ �ε��Ѵ�.
    USES_CONVERSION;

    WCHAR szOpenFilter[] = L"Clump File (*.dff)|*.dff||";
    CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szOpenFilter);    
    if(fileDlg.DoModal() == IDOK)
    {
        CString sLoadFilePath = L".";
        sLoadFilePath += fileDlg.GetPathName();	
        CString sLoadFileName = fileDlg.GetFileName();

        CMTCharacter* pCharacter = NULL;
        pCharacter = (CMTCharacter*)m_treePC.GetItemData(m_treePC.GetSelectedItem());
        if(!pCharacter)
        {
            // ������ �߰����ش�.
            pCharacter = new CMTCharacter;
            pCharacter->Create();
            m_treePC.SetItemData(m_treePC.GetSelectedItem(), (DWORD_PTR)pCharacter);
            m_vCharacter.push_back(pCharacter);
        }

        RwBool retBool = pCharacter->LoadClump(W2A(sLoadFilePath));
        if(retBool == (RwBool)TRUE)
        {
            m_edClumpFileName.SetWindowText(sLoadFileName);

            //  ������ ����ü�� �����Ѵ�.
            CMTCharacter* pCharacter = (CMTCharacter*)m_treePC.GetItemData(m_treePC.GetSelectedItem());
            if(pCharacter)
            {
                CModelToolApplication::GetInstance()->SetEditChar(pCharacter);                
                m_pCharacterProperty = pCharacter->GetProperty();                
                CString sWorkPath = A2W(CModelToolApplication::GetInstance()->GetWorkDir());
                
                sWorkPath = sWorkPath.MakeUpper();                
                sLoadFilePath = sLoadFilePath.MakeUpper();
                sLoadFileName = sLoadFileName.MakeUpper();

                sLoadFilePath.Replace(sWorkPath, L"");
                sLoadFilePath.Replace(sLoadFileName, L"");

                //m_pCharacterProperty->SetMeshPath(W2A(sLoadFilePath));
                sLoadFileName = sLoadFilePath + sLoadFileName;
                m_pCharacterProperty->SetBaseMeshFileName(W2A(sLoadFileName));

                // �ϴܺ�� �����ʺ信 ������ �����Ѵ�.
                CBottomToolView::GetInstance()->SetInit(pCharacter);
                CRightToolView::GetInstance()->SetInit(pCharacter);

                CRightToolView::GetInstance()->SetEnable(CRightToolView::ENABLE_ANIMSET);
                m_btSaveScript.EnableWindow(TRUE);
            }
        }
        else
        {   
            m_edClumpFileName.SetWindowText(L"");
            MessageBox(L"Clump File Load Fail");
        }
    }	
}

BOOL CPagePC::OnSetActive()
{
    // Ȱ��ȭ �ɶ� RightView�� �ڽ��� ������ �˷���� �Ѵ�.
    // RightView�� �������� ���ǰ�, LeftView�� ������ ����
    // �ִϸ��̼� ������ �޶����� �ϱ� ����
    CRightToolView::GetInstance()->SetActiveLeftView(CRightToolView::LEFT_PAGE_PC);

    // ���õ� �������� �ٽ��ѹ� ������ �ش�. (������ ������ Ȱ��ȭ�� ����)
    HTREEITEM hSelectedItem = m_treePC.GetSelectedItem();
    if(hSelectedItem)
    {
        m_treePC.SelectItem(m_treePC.GetRootItem());
        m_treePC.SelectItem(hSelectedItem);
    }
    
    return CPropertyPage::OnSetActive();
}


BOOL CPagePC::OnKillActive()
{
    CRightToolView::GetInstance()->SetEnable(CRightToolView::DISABLE_ALL);

    // ���� ȭ�鿡 �ִ� ���� ȭ�鿡�� �����.
    CMTCharacter* pCharacter = (CMTCharacter*)m_treePC.GetItemData(m_treePC.GetSelectedItem());
    if(pCharacter)
    {
        pCharacter->SetVisible(FALSE);
    }

    return CPropertyPage::OnKillActive();
}

void CPagePC::OnBnClickedButton1()
{
    OnSaveScript(m_treePC.SelectScriptName(), TRUE);
}

void CPagePC::OnSaveScript(const WCHAR* szScriptName, BOOL bVisible)
{
    USES_CONVERSION;

    CMTCharacter* pCharacter = (CMTCharacter*)m_treePC.GetItemData(m_treePC.GetSelectedItem());
    if(!pCharacter)
    {
        MessageBox(L"Not Exist Character");
        return;
    }

    CString sCurrentScriptFileName = szScriptName;
    if(sCurrentScriptFileName != L"New Script")
    {
        std::string sSaveFileName = W2A(m_sSaveFolderName);        
        sSaveFileName += W2A(sCurrentScriptFileName);
        sCurrentScriptFileName.Replace(L".XML", L"");
        pCharacter->GetProperty()->SetName(W2A(sCurrentScriptFileName));        
        RwBool bReturn = pCharacter->GetProperty()->SaveScript(sSaveFileName.c_str());
        if(bReturn)
        {
            if(bVisible)
            {
                MessageBox(L"Script File Save Success");
            }
        }
        else
        {
            MessageBox(L"Script File Save Fail");
        }                
    }
    else
    {
        if(bVisible)
        {
            CString sSavePath = m_sSaveFolderName;
            CString sMeshName;
            m_edClumpFileName.GetWindowText(sMeshName);
            sMeshName = sMeshName.MakeUpper();
            sMeshName.Replace(L".DFF", L".XML");
            sSavePath += sMeshName;
            WCHAR szSaveFilder[] = L"Character Script File (*.XML)|*.XML||";
            CFileDialog fileDlg(FALSE, L"XML", sSavePath, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szSaveFilder);
            if(fileDlg.DoModal() == IDOK)
            {
                CString sSaveFilePath = fileDlg.GetPathName();
                CString sSaveFileName = fileDlg.GetFileName();

                sSaveFileName.Replace(L".XML", L""); // ������Ƽ�� ���ӿ����� Ȯ���ڸ� �����Ѵ�.
                pCharacter->GetProperty()->SetName(W2A(sSaveFileName));                
                RwBool bReturn = pCharacter->GetProperty()->SaveScript(W2A(sSaveFilePath));
                if(bReturn)
                {
                    sSaveFileName += L".XML";   // �ٽ� Ȯ���ڸ� �ٿ��ش�.
                    m_edScriptFileName.SetWindowText(sSaveFileName);   
                    m_treePC.SetScriptName(sSaveFileName);
                }
                else
                {
                    MessageBox(L"Script File Save Fail");
                }
            }
        }
        else
        {
            pCharacter->GetProperty()->SaveScript(W2A(sCurrentScriptFileName));
        }
    }    
}

void CPagePC::OnBnClickedBtSaveAll()
{
    USES_CONVERSION;

    // ��� ��ũ��Ʈ�� �����Ѵ�.
    TREEITEM_VECTOR vAllITem;
    m_treePC.GetAllChildNode(m_treePC.GetRootItem(), vAllITem);
    for(size_t i = 0; i < vAllITem.size(); ++i)
    {
        if(vAllITem[i] && m_treePC.GetItemData(vAllITem[i]))
        {
            CString sScriptName = m_treePC.GetItemText(vAllITem[i]);
            if(sScriptName != "")
            {
                std::string sSaveFileName = W2A(m_sSaveFolderName);
                sSaveFileName += W2A(sScriptName);
                CMTCharacter* pCharacter = (CMTCharacter*)m_treePC.GetItemData(vAllITem[i]);
                if(pCharacter)
                {
                    pCharacter->GetProperty()->SaveScript(sSaveFileName.c_str());
                }

            }
        }                
    }

    MessageBox(L"Save All Complete");
}

void CPagePC::OnMenuLoadScript()
{
    USES_CONVERSION;
    // ��ũ��Ʈ ������ �ε� �Ѵ�. (��ũ��Ʈ ������ .\Character\ ������ �־�߸� �Ѵ�.)
    WCHAR sLoadFilter[] = L"Character Script File (*.xml)|*.xml||";
    CString workDir = A2W(CModelToolApplication::GetInstance()->GetWorkDir());
    workDir += L"\\Character\\*.xml";    
    CFileDialog fileDlg(TRUE, NULL, workDir, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, sLoadFilter);
    if(fileDlg.DoModal() == IDOK)
    {
        CString sLoadFileName = fileDlg.GetFileName();
        //OnDisplayScriptInfo(sLoadFileName);        

        // Ʈ���� �׸��� �߰��Ѵ�.
        m_treePC.AddItem(W2A(sLoadFileName));
    }
}

void CPagePC::OnMenuNewScript()
{
    // ���ο� ��ũ��Ʈ�� ������, DFF ���ϵ� ���� �����Ѵ�.
    OnBnClickedBtSetClump();
}

void CPagePC::OnDestroy()
{
    // â�� �������� ���� XML�� ������ �����Ѵ�.
    USES_CONVERSION;

    CString sWorkFolder = A2W(CModelToolApplication::GetInstance()->GetWorkDir());
    sWorkFolder += L"\\TreePC.xml";
    m_treePC.SaveTree(L"PC", (LPWSTR)(LPCWSTR)sWorkFolder);

    CPropertyPage::OnDestroy();    
}

void CPagePC::OnMenuScriptSave()
{
    // ���� ���õ� ��ũ��Ʈ�� �����Ѵ�.
    // NewScript��� ���� ������ �ϰ�, ���� ��ũ��Ʈ��� ���� ����.
    CString sScriptName = m_treePC.GetItemText(m_treePC.GetSelectedItem());
    OnSaveScript(sScriptName, TRUE); 
}

void CPagePC::OnMenuScriptSaveas()
{
    // ���ο� �̸����� ��ũ��Ʈ�� �����Ѵ�.
    OnSaveScript(L"New Script", TRUE);
}

void CPagePC::OnMenuScriptRename(CString sOrgScriptName, CString sNewScriptName)
{
    USES_CONVERSION;

    // ��ũ��Ʈ ���ϸ��� �����Ѵ�.    
    // �� ��ũ��Ʈ�� ��쿡�� �������̸����� �����Ѵ�.
    if(sOrgScriptName == L"New Script")
    {
        OnSaveScript(sNewScriptName, FALSE);
    }
    else
    {
        CMTCharacter* pCharacter = (CMTCharacter*)m_treePC.GetItemData(m_treePC.GetSelectedItem());
        if(pCharacter && pCharacter->GetProperty())
        {
            sNewScriptName.Replace(L".XML", L"");
            pCharacter->GetProperty()->SetName(W2A(sNewScriptName));
        }
        sOrgScriptName = m_sSaveFolderName + sOrgScriptName;
        sNewScriptName = m_sSaveFolderName + sNewScriptName;
        CFile::Rename(sOrgScriptName, sNewScriptName);   
    }    
}

void CPagePC::OnMenuDeleteScript(HTREEITEM hItem)
{
    if(!hItem)
        return;

    CMTCharacter* pCharacter = (CMTCharacter*)m_treePC.GetItemData(hItem);
    if(pCharacter)
    {
        pCharacter->SetVisible(FALSE);
    }
}
void CPagePC::OnSize(UINT nType, int cx, int cy)
{
    CPropertyPage::OnSize(nType, cx, cy);

    //if(m_treePC.GetSafeHwnd())
    //    m_treePC.MoveWindow(0, 0, cx, cy - PAGE_HEIGHT_BOTTOM_CTRL);
}
