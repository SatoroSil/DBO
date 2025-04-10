#ifndef _DBO_TSACTTELMUDOSA_H_
#define _DBO_TSACTTELMUDOSA_H_


#include "DboTSCoreDefine.h"


/**
	Teleport Mudosa
*/


class CDboTSActTelMudosa : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:

// Constructions
public:
	CDboTSActTelMudosa( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_TELMUDOSA; }


// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


#endif