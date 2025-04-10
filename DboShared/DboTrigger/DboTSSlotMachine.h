#ifndef _DBO_TSSLOTMACHINE_H_
#define _DBO_TSSLOTMACHINE_H_


#include "DboTSCoreDefine.h"


/**
	Slot machine
*/


class CDboTSSlotMachine : public CNtlTSEvent
{
	NTL_TS_DECLARE_RTTI


protected:

	int						m_iSt;


// Constructions
public:
	CDboTSSlotMachine( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_EVENT_TYPE_ID_SLOTMACHINE; }

	int									GetSt( void ) const;

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline int CDboTSSlotMachine::GetSt( void ) const
{
	return m_iSt;
}


#endif