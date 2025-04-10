#ifndef _DBO_TSCHECKINWORLD_H_
#define _DBO_TSCHECKINWORLD_H_


#include "DboTSCoreDefine.h"


class CDboTSCheckInWorld : public CNtlTSCond
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	unsigned int						m_uiWorldIdx;

// Constructions
public:
	CDboTSCheckInWorld( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_COND_TYPE_ID_CHECK_IN_WORLD; }

	unsigned int						GetWorldTblIdx( void ) const;
	void								SetWorldTblIdx( unsigned int uiWorldTblIdx );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline unsigned int CDboTSCheckInWorld::GetWorldTblIdx( void ) const
{
	return m_uiWorldIdx;
}


#endif