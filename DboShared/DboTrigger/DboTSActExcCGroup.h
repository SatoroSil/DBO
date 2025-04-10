#ifndef _DBO_TSACTEXCCGROUP_H_
#define _DBO_TSACTEXCCGROUP_H_


#include "DboTSCoreDefine.h"


/**
	Execute Client Group
*/


class CDboTSActExcCGroup : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	bool								m_bReg;
	NTL_TS_TG_ID						m_tgExcCGID;

// Constructions
public:
	CDboTSActExcCGroup( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_EXC_C_GROUP; }

	bool								IsRegister( void ) const;

	NTL_TS_TG_ID						GetExcuteClientTSGroupID( void ) const;

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};

inline bool CDboTSActExcCGroup::IsRegister( void ) const
{
	return m_bReg;
}

inline NTL_TS_TG_ID CDboTSActExcCGroup::GetExcuteClientTSGroupID( void ) const
{
	return m_tgExcCGID;
}


#endif