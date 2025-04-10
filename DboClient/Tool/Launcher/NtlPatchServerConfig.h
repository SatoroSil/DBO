/*****************************************************************************
*
* File			: NtlPatchServerConfig.h
* Author		: agebreak
* Copyright	: (��)NTL
* Date			: 2007. 10. 4.
* Abstract		: 
*****************************************************************************
* Desc         : Patch Server�� �����ϴ� PatchServerConfig.XML������ ������ �о �м��ϴ� Ŭ����
*
*****************************************************************************/
#pragma once

#include <string>

/// ��ġ������ �����ϴ� PatchServerConfig.XML ������ ������ �о �м��ϴ� ����
class CNtlPatchServerConfig
{
public:    
    static CNtlPatchServerConfig* GetInstance();
    static void                   DeleteInstance();

    BOOL LoadServerConfigFile(const char* pszXMLFileName);              ///< XML ������ �ε��Ѵ�.

    BOOL            GetPatchEnable() {return m_bPatchEnable;}           ///< ��ġ ���� ������ ��ȯ�Ѵ�.
    std::string&    GetPatchErrMsg()    {return m_strErrorMsg;}         ///< �����޽����� ��ȯ�Ѵ�.
    std::string&    GetFullVerServerIP() {return m_strFullVerServerIP;} ///< Ǯ������ �ִ� ������ IP�� ��ȯ�Ѵ�.
    std::string&    GetFullVerServerFolder() {return m_strFullVerServerFolder;} ///< Ǯ������ �ִ� ������ ������θ� ��ȯ�Ѵ�.

protected:
    CNtlPatchServerConfig();
    ~CNtlPatchServerConfig();

protected:
    static CNtlPatchServerConfig* m_pInstance;
    
    BOOL            m_bPatchEnable;
    std::string     m_strFullVerServerIP;
    std::string     m_strFullVerServerFolder;
    std::string     m_strErrorMsg;
};