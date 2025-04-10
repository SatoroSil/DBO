#ifndef _DBO_TSACTINSSM_H_
#define _DBO_TSACTINSSM_H_


#include "DboTSCoreDefine.h"


/**
	Input SSM action
	SSM�� �־��� ���� �Է��Ѵ�
	�뵵 : ���
	���� : Slot storage memory�� �ش� ���� �Է��� �� ���
*/


class CDboTSActInSSM : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	eSSM_ID								m_eSSMId;
	unsigned int						m_uiValue;	// SSM �� �Է��� ��

// Constructions
public:
	CDboTSActInSSM( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_INSSM; }

	eSSM_ID								GetSSMId( void ) const;
	void								SetSSMId( eSSM_ID eSSMId );

	unsigned int						GetValue( void ) const;
	void								SetValue( unsigned int uiValue );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline eSSM_ID CDboTSActInSSM::GetSSMId( void ) const
{
	return m_eSSMId;
}

inline unsigned int CDboTSActInSSM::GetValue( void ) const
{
	return m_uiValue;
}


#endif