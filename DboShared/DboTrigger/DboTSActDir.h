#ifndef _DBO_TSACTDIR_H_
#define _DBO_TSACTDIR_H_


#include "DboTSCoreDefine.h"


/**
	Direction action
	�뵵 : Client quest, client trigger, Server quest, server trigger pc
	���� : ������ Ŭ���̾�Ʈ���� ���� ���·� �ٲٶ�� �޽����� �����ش�.
		   Ŭ���̾�Ʈ, ������ TS���� m_tcJump�� ���� ó���� ���ش�
*/


class CDboTSActDir : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	float								m_fRange;
	unsigned char						m_byDirectionType;
	unsigned int						m_uiDirectionTblIdx;

// Constructions
public:
	CDboTSActDir( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_DIR; }

	float								GetRange( void ) const;
	void								SetRange( float fRange );

	unsigned char						GetDirectionType( void ) const;
	void								SetDirectionType( unsigned char byDirectionType );

	unsigned int						GetDirectionTblIdx( void ) const;
	void								SetDirectionTblIdx( unsigned int TblIdx );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline float CDboTSActDir::GetRange( void ) const
{
	return m_fRange;
}


inline unsigned char CDboTSActDir::GetDirectionType( void ) const
{
	return m_byDirectionType;
}


inline unsigned int CDboTSActDir::GetDirectionTblIdx( void ) const
{
	return m_uiDirectionTblIdx;
}


#endif