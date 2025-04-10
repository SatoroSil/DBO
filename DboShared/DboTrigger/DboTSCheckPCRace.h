#ifndef _DBO_TSCHECKPCRACE_H
#define _DBO_TSCHECKPCRACE_H


#include "DboTSCoreDefine.h"


/**
	Check pc race condition
	�뵵 : Client quest, client trigger, server quest, server trigger pc
*/


class CDboTSCheckPCRace : public CNtlTSCond
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	unsigned int						m_uiRaceFlags;

// Constructions
public:
	CDboTSCheckPCRace( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_COND_TYPE_ID_CHECK_PCRACE; }

	unsigned int						GetRaceFlags( void ) const;
	void								SetRaceFlags( unsigned int uiRaceFlags );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline unsigned int CDboTSCheckPCRace::GetRaceFlags( void ) const
{
	return m_uiRaceFlags;
}


#endif