#ifndef _DBO_TSCHECKPCCLS_H
#define _DBO_TSCHECKPCCLS_H


#include "DboTSCoreDefine.h"


/**
	Check pc class condition
	�뵵 : Client quest, client trigger, server quest, server trigger pc
*/


class CDboTSCheckPCCls : public CNtlTSCond
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	unsigned int						m_uiClsFlags;

// Constructions
public:
	CDboTSCheckPCCls( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_COND_TYPE_ID_CHECK_PCCLS; }

	unsigned int						GetClsFlags( void ) const;
	void								SetClsFlags( unsigned int uiClsFlags );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline unsigned int CDboTSCheckPCCls::GetClsFlags( void ) const
{
	return m_uiClsFlags;
}


#endif