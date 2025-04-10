#pragma once

NCDeclareSGT(ERSMCore);

/**
 * \ingroup ERSManager
 * \brief ERSManager�� ���� ó���� �ϴ� Core Ŭ����
 * \date 2007-01-26
 * \author agebreak
 */
class ERSMCore
{
public:
    ERSMCore(void);
    virtual ~ERSMCore(void);

    bool   Init();                                          ///< �ʱ�ȭ �۾��� �����Ѵ�.
    void   Destroy();                                       ///< ������ �۾��� �����Ѵ�.
    bool   Run();                                           ///< �����带 �����Ͽ�, �۾��� �����Ѵ�.

protected:
	static DWORD WINAPI WorkThread(LPVOID pParam);			///< ���� �۾��� �����ϴ� ������
	std::string GetModulePath();							///< ���� ���� ���α׷� ������ ��θ� �����´�.

public:
	static bool	m_bEndFlag;									///< �����带 ������ ���� �÷���
	static CTime m_prevRunTime;

};
