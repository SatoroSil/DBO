#ifndef _DBO_TSCHECKLVL_H
#define _DBO_TSCHECKLVL_H


#include "DboTSCoreDefine.h"


/**
	Check level condition
	�뵵 : Client quest, client trigger, server quest, server trigger pc
*/


class CDboTSCheckLvl : public CNtlTSCond
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	int									m_nMinLvl;
	int									m_nMaxLvl;

// Constructions
public:
	CDboTSCheckLvl( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_COND_TYPE_ID_CHECK_LVL; }

	int									GetMinLvl( void ) const;
	void								SetMinLvl( int nLvl );

	int									GetMaxLvl( void ) const;
	void								SetMaxLvl( int nLvl );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline int CDboTSCheckLvl::GetMinLvl( void ) const
{
	return m_nMinLvl;
}

inline int CDboTSCheckLvl::GetMaxLvl( void ) const
{
	return m_nMaxLvl;
}


#endif