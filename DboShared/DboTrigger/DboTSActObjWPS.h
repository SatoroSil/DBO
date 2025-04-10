#ifndef _DBO_TSACTOBJWPS_H_
#define _DBO_TSACTOBJWPS_H_


#include "DboTSCoreDefine.h"


/**
	Object WPS
*/


class CDboTSActObjWPS : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	unsigned int						m_uiScriptID;

// Constructions
public:
	CDboTSActObjWPS( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_OBJ_WPS; }

	unsigned int						GetObjWPS( void ) const;
	void								SetObjWPS( unsigned int uiScriptID );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline unsigned int CDboTSActObjWPS::GetObjWPS( void ) const
{
	return m_uiScriptID;
}


#endif