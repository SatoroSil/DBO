#ifndef _DBO_TSACTHINT_H_
#define _DBO_TSACTHINT_H_


#include "DboTSCoreDefine.h"


class CDboTSActHint : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	unsigned int						m_uiHintType;
	unsigned int						m_uiTableIdx;

// Constructions
public:
	CDboTSActHint( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_HINT; }

	unsigned int						GetHintType( void ) const;
	void								SetHintType( unsigned int uiHintType );

	unsigned int						GetTableIndex( void ) const;
	void								SetTableIndex( unsigned int uiTblIdx );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline unsigned int CDboTSActHint::GetHintType( void ) const
{
	return m_uiHintType;
}

inline unsigned int CDboTSActHint::GetTableIndex( void ) const
{
	return m_uiTableIdx;
}


#endif