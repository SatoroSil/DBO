#pragma once
#include "NtlXMLDoc.h"
NCDeclareSGT(ERSMConfig);

/**
 * \ingroup ERSManager
 * \brief ERSMan�� Config ����(XML)�κ��� �������� �о���� Ŭ����
 * \date 2007-01-26
 * \author agebreak
 */
class ERSMConfig : public CNtlXMLDoc
{
public:
    ERSMConfig(void);
    virtual ~ERSMConfig(void);

    bool ReadConfig(const std::string& strFileName);            ///< Config ���Ϸκ��� ������ �о� �´�.

    // Get Methods
    std::string     GetERSFolder() {return m_strERSFolder;}
    int             GetRunTime() {return m_nRunTime;}
    std::string     GetSMTPServerIP() {return m_strSMTPServerIP;}
    std::string     GetSMTPServerID() {return m_strSMTPID;}
    std::string     GetSMTPPass() {return m_strSMTPPass;}
    int             GetSMTPRunTime() {return m_nSMTPRunTime;}

protected:
    std::string     m_strERSFolder;                             ///< ���� ����Ʈ ����
    int             m_nRunTime;                                 ///< ���� �۾� �ð� �� (��)
    std::string     m_strSMTPServerIP;                          ///< SMTP ���� IP
    std::string     m_strSMTPID;                                ///< SMTP ���� ID
    std::string     m_strSMTPPass;                              ///< SMTP ���� �н�����
    int             m_nSMTPRunTime;                             ///< ������ �߼��� �ð� �� (��)	
	std::string		m_strSMTPSender;							///< ���� �߼��� �̸�
};
