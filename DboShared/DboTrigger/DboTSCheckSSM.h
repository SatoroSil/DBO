#ifndef _DBO_TSCHECKSSM_H_
#define _DBO_TSCHECKSSM_H_


#include "DboTSCoreDefine.h"


/**
	Check storage slot memory condition
	�뵵 : ���
*/


class CDboTSCheckSSM : public CNtlTSCond
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	eSSM_OP_TYPE						m_eOPType;
	eSSM_ID								m_eSSMId;
	unsigned int						m_uiVariable;

// Constructions
public:
	CDboTSCheckSSM( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_COND_TYPE_ID_CHECK_SSM; }

	eSSM_OP_TYPE						GetOPType( void ) const;
	void								SetOPType( eSSM_OP_TYPE eOPType );

	eSSM_ID								GetSSMId( void ) const;
	void								SetSSMId( eSSM_ID eSSMId );

	unsigned int						GetVariable( void ) const;
	void								SetVariable( unsigned int uiVariable );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline eSSM_OP_TYPE CDboTSCheckSSM::GetOPType( void ) const
{
	return m_eOPType;
}

inline eSSM_ID CDboTSCheckSSM::GetSSMId( void ) const
{
	return m_eSSMId;
}

inline unsigned int CDboTSCheckSSM::GetVariable( void ) const
{
	return m_uiVariable;
}


#endif