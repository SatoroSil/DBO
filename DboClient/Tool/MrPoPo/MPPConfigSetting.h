#pragma once
#include "afxwin.h"

#include "CustomItems.h"
#include "NtlScriptEncrypter.h"

enum EItemID
{
    ID_FILE_LOAD,
    ID_OP_IP,
    ID_OP_PORT,
    ID_LOCAL_DSP,
    ID_LOCAL_SYNC_DSP,
    ID_BUGTRAP_IP,
    ID_BUGTRAP_PORT,
};


/**
 * \ingroup MrPoPo
 * \brief   Config ���� ������ ��ȣȭ �� Ŭ����
 *
 * \date 2008-07-31
 * \author agebreak
 */
class CMPPConfigSetting : public CXTResizeFormView
{
	DECLARE_DYNCREATE(CMPPConfigSetting)

protected:
	CMPPConfigSetting();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CMPPConfigSetting();

public:
	enum { IDD = IDD_MPPCONFIGSETTING };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif


public:
    virtual void OnInitialUpdate();
    afx_msg void OnBnClickedBtnSavexml();
    afx_msg void OnBnClickedBtnSaveenc();

protected:
    DECLARE_MESSAGE_MAP()
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

    afx_msg LRESULT OnGridNotify(WPARAM, LPARAM);
        afx_msg void OnBnClickedBtnLuaCompile();

    void    UpdateConfigData();                         ///< ���Ǳ� �����͸� ������Ʈ�մϴ�.
    void    LoadLuaFiles();

protected:
    CButton m_btnSaveXML;
    CButton m_btnSaveEnc;
    CXTBrowseEdit   m_edLuaDir;
    CXTBrowseEdit   m_edOutDir;

    CXTPPropertyGrid        m_property;
    CXTPPropertyGridItem*   m_pCatConfig;
    CCustomItemFileBox*     m_pFileLoad;
    CXTPPropertyGridItem*   m_pOpIp;
    CXTPPropertyGridItem*   m_pOpPort;
    CCustomItemFileBox*     m_pLocalDsp;
    CCustomItemFileBox*     m_pLocalSyncDsp;
    CXTPPropertyGridItem*   m_pBugTrapIp;
    CXTPPropertyGridItem*   m_pBugTrapPort;

    SConfigData             m_configData;               ///< ���Ǳ� ���� ������
public:
    afx_msg void OnEnChangeEdLua();
};


