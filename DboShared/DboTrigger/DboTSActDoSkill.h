#ifndef _DBO_TSACTDOSKILL_H_
#define _DBO_TSACTDOSKILL_H_


#include "DboTSCoreDefine.h"


/**
	Do skill action
*/


class CDboTSActDoSkill : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	unsigned int						m_uiSkillIdx;

// Constructions
public:
	CDboTSActDoSkill( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_DO_SKILL; }

	unsigned int						GetSkillIdx( void ) const;
	void								SetSkillIdx( unsigned int uiSkillIdx );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline unsigned int CDboTSActDoSkill::GetSkillIdx( void ) const
{
	return m_uiSkillIdx;
}


#endif