#ifndef _DBO_TSCHECKOBJITEM_H_
#define _DBO_TSCHECKOBJITEM_H_


#include "DboTSCoreDefine.h"


/**
	Check obejct item condition
*/


class CDboTSCheckObjItem : public CNtlTSCond
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	NTL_TS_T_ID							m_tQuestId;

// Constructions and Destructions
public:
	CDboTSCheckObjItem( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_COND_TYPE_ID_CHECK_OBJITEM; }

	NTL_TS_T_ID							GetQuestId( void );
	void								SetQuestId( NTL_TS_T_ID tId );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline NTL_TS_T_ID CDboTSCheckObjItem::GetQuestId( void )
{
	return m_tQuestId;
}


#endif