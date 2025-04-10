#ifndef _DBO_TSACTNPCCONV_H_
#define _DBO_TSACTNPCCONV_H_


#include "DboTSCoreDefine.h"


/**
	NPC conversation action
	�뵵 : Client quest, client trigger
	���� : Ŭ���̾�Ʈ �������� ���Ǵ� NPC ��ȭ
*/


class CDboTSActNPCConv : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	unsigned int						m_uiNPCIdx;
	eNPCCONV_TYPE						m_eNPCConvType;
	unsigned int						m_uiNPCConv;

// Constructions
public:
	CDboTSActNPCConv( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_NPCCONV; }

	unsigned int						GetNPCIdx( void ) const;
	void								SetNPCIdx( unsigned int uiNPCIdx );

	eNPCCONV_TYPE						GetNPCConvType( void ) const;
	void								SetNPCConvType( eNPCCONV_TYPE eNPCConvType );

	unsigned int						GetNPCConv( void ) const;
	void								SetNPCConv( unsigned int uiNPCConv );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline unsigned int CDboTSActNPCConv::GetNPCIdx( void ) const
{
	return m_uiNPCIdx;
}

inline eNPCCONV_TYPE CDboTSActNPCConv::GetNPCConvType( void ) const
{
	return m_eNPCConvType;
}

inline unsigned int CDboTSActNPCConv::GetNPCConv( void ) const
{
	return m_uiNPCConv;
}


#endif