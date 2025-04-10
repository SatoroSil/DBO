#ifndef _DBO_TSQUEST_H
#define _DBO_TSQUEST_H


#include "DboTSCoreDefine.h"


/**
	Check 
*/


class CDboTSQuest : public CNtlTSEvent
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:

// Constructions
public:
	CDboTSQuest( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_EVENT_TYPE_ID_QUEST; }


// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


#endif