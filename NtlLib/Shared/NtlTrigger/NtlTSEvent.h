#ifndef _NTL_TSEVENT_H_
#define _NTL_TSEVENT_H_


#include "NtlTSEntity.h"


/**
	Event entity
*/


class CNtlTSEvent : public CNtlTSEntity
{
	NTL_TS_DECLARE_RTTI

// Constructions and Destructions
public:
	CNtlTSEvent( void );
	virtual ~CNtlTSEvent( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return NTL_TSENTITY_TYPE_EVENT_BEGIN; }

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& ) { return; }
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& ) { return; }
};


#endif