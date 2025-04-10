#ifndef _DBO_TSRCVSVREVT_H_
#define _DBO_TSRCVSVREVT_H_


#include "DboTSCoreDefine.h"


class CDboTSRcvSvrEvt : public CNtlTSEvent
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	unsigned int						m_uiEvtID;

// Constructions
public:
	CDboTSRcvSvrEvt( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_EVENT_TYPE_ID_RCV_SVR_EVT; }

	unsigned int						GetEvtID( void ) const;
	void								SetEvtID( unsigned int uiEvtID );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline unsigned int CDboTSRcvSvrEvt::GetEvtID( void ) const
{
	return m_uiEvtID;
}


#endif