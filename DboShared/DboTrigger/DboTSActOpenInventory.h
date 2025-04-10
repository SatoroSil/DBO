#ifndef _DBO_TSACTOPENINVENTORY_H_
#define _DBO_TSACTOPENINVENTORY_H_


#include "DboTSCoreDefine.h"


class CDboTSActOpenInventory : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	bool								m_bShow;

// Constructions
public:
	CDboTSActOpenInventory( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_OPEN_INVENTORY; }

	bool								GetShow( void ) const;
	void								SetShow( bool bShow );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline bool CDboTSActOpenInventory::GetShow( void ) const
{
	return m_bShow;
}


#endif