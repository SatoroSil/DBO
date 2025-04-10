#ifndef _DBO_TSCHECKAVATARDEAD_H_
#define _DBO_TSCHECKAVATARDEAD_H_


#include "DboTSCoreDefine.h"


class CDboTSCheckAvatarDead : public CNtlTSCond
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:

// Constructions
public:
	CDboTSCheckAvatarDead( void );


// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_COND_TYPE_ID_CHECK_AVATARDEAD; }


// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


#endif