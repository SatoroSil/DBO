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

protected:
    void   Init();                                          ///< �ʱ�ȭ �۾��� �����Ѵ�.
    void   Destroy();                                       ///< ������ �۾��� �����Ѵ�.
    void   Run();                                           ///< �����带 �����Ͽ�, �۾��� �����Ѵ�.
};
