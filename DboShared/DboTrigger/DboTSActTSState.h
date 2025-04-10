#ifndef _DBO_TSACTTSSTATE_H_
#define _DBO_TSACTTSSTATE_H_


#include "DboTSCoreDefine.h"


/**
	TS state update action
	TS �� ���¸� �����Ѵ�
*/


class CDboTSActTSState : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	// TS ���� Ÿ��
	eTSSTATE_TYPE						m_eStateType;

	// TS ���¸� ������Ʈ ��Ų��
	unsigned short						m_wTSState;

// Constructions
public:
	CDboTSActTSState( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_TSSTATE; }

	eTSSTATE_TYPE						GetType( void ) const;
	void								SetType( eTSSTATE_TYPE eType );

	unsigned short						GetTSState( void ) const;
	void								SetTSState( unsigned short wTSState );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline eTSSTATE_TYPE CDboTSActTSState::GetType( void ) const
{
	return m_eStateType;
}

inline unsigned short CDboTSActTSState::GetTSState( void ) const
{
	return m_wTSState;
}


#endif