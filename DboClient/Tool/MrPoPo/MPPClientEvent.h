#pragma once

#include "CNtlMrPoPoMsg.h"

/**
 * \ingroup MrPoPo
 * \brief Ŭ���̾�Ʈ�� ������ �̺�Ʈ�� �����ϴ� Ŭ����
 *
 * \date 2008-08-01
 * \author agebreak
 */
class CMPPClientEvent
{
public:
    CMPPClientEvent(void);
    ~CMPPClientEvent(void);

    BOOL    CheckClientConnect();                           ///< Ŭ���̾�Ʈ���� ������ üũ�Ѵ�.
    void    SendEvent(int nMsgCode, DWORD param);    

protected:
    HWND     m_hDBOClient;                                   ///< Ŭ���̾�Ʈ �������� �ڵ�
};

static CMPPClientEvent* GetMPPClientEvent()
{
    static CMPPClientEvent mppClientEvent;
    return &mppClientEvent;
}
    
static DWORD Float2DWORD(CString& str)
{
    float fVal = (float)_wtof(str);
    return *(DWORD*)&fVal;
}