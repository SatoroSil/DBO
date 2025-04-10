#ifndef _DBO_TSCHECKCUSTOMEVENT_H
#define _DBO_TSCHECKCUSTOMEVENT_H


#include "DboTSCoreDefine.h"


/**
	Check custom event condition
*/


class CDboTSCheckCustomEvent : public CNtlTSCond
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	NTL_TS_T_ID							m_tQuestID;

// Constructions
public:
	CDboTSCheckCustomEvent( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_COND_TYPE_ID_CHECK_CUSTOMEVENT; }

	NTL_TS_T_ID							GetQuestID( void ) const;
	void								SetQuestID( NTL_TS_T_ID tQuestID );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline NTL_TS_T_ID CDboTSCheckCustomEvent::GetQuestID( void ) const
{
	return m_tQuestID;
}


#endif