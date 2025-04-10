#ifndef _NTL_TSCOND_H_
#define _NTL_TSCOND_H_


#include "NtlTSEntity.h"


/**
	Condition entity
*/

class CNtlTSCond : public CNtlTSEntity
{
	NTL_TS_DECLARE_RTTI

// Constructions and Destructions
public:
	CNtlTSCond( void  );
	virtual ~CNtlTSCond( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return NTL_TSENTITY_TYPE_COND_BEGIN; }

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& ) { return; }
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& ) { return; }
};


#endif