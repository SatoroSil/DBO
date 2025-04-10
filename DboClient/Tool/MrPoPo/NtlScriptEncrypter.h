#pragma once

#include <string>

// config data
typedef struct _SConfigData
{
    CString     strAddr;		// account server ip address(��ŷ�� ������ �ϵ��ڵ��� ����Ѵ�?)
    DWORD       dwPort;				// account server ip port(��ŷ�� ������ �ϵ��ڵ��� ����Ѵ�?)
    CString     strLocalDsp;
    CString     strLocalSyncDsp;
    CString     strBugTrapServerIP;        
    DWORD       dwBugTrapServerPort;    
}SConfigData;

/**
 * \ingroup Util
 * \brief Ŭ���̾�Ʈ ��ũ��Ʈ�� ��ȣȭ�ϱ� ���� Ŭ����
 *  ��ȣȭ �������� ����ϱ� ���ؼ� �ε����ϰ� Util�� �־�д�.
 * \date 2008-07-31
 * \author agebreak
 */
class CNtlScriptEncrypter
{
public:
    CNtlScriptEncrypter(void);
    ~CNtlScriptEncrypter(void);

    static BOOL LoadConfigOption(OUT SConfigData* pConfigData, char* szFileName);             
    static BOOL SaveConfigOption(SConfigData* pConfigData, char* szFileName, BOOL bEncrypt = FALSE); 

protected:
    static BOOL LoadConfigOptionXML(OUT SConfigData* pConfigData, char* szFileName);
    static BOOL LoadConfigOptionENC(OUT SConfigData* pConfigData, char* szFileName);
    static BOOL SaveConfigOptionXML(SConfigData* pConfigData, char* szFileName);
    static BOOL SaveConfigOptionENC(SConfigData* pConfigData, char* szFileName, char* szCryptPassword);
};
