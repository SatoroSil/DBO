#ifndef _DBO_TSACTCONCCHECK_H_
#define _DBO_TSACTCONCCHECK_H_


#include "DboTSCoreDefine.h"


class CDboTSActConcCheck : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:

	int									m_nConcurrencyCnt;
	unsigned int						m_uiResetTime;

	unsigned int						m_uiExcuteObjTblIdx;	// �����ų ������Ʈ ���̺� �ε���
	NTL_TS_T_ID							m_tExcuteTID;			// �����ų ������Ʈ Ʈ���� ���̵�

// Constructions
public:
	CDboTSActConcCheck( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_CONC_CHECK; }

	int									GetConcurrencyCnt( void ) const;
	void								SetConcurrencyCnt( int nConcurrencyCnt );

	unsigned int						GetResetTime( void ) const;
	void								SetResetTime( unsigned int uiResetTime );

	unsigned int						GetExcuteObjTblIdx( void ) const;
	void								SetExcuteObjTblIdx( unsigned int uiExcuteObjTblIdx );

	NTL_TS_T_ID							GetExcuteTID( void ) const;
	void								SetExcuteTID( NTL_TS_T_ID tExcuteTID );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline int CDboTSActConcCheck::GetConcurrencyCnt( void ) const
{
	return m_nConcurrencyCnt;
}


inline unsigned int CDboTSActConcCheck::GetResetTime( void ) const
{
	return m_uiResetTime;
}


inline unsigned int CDboTSActConcCheck::GetExcuteObjTblIdx( void ) const
{
	return m_uiExcuteObjTblIdx;
}


inline NTL_TS_T_ID CDboTSActConcCheck::GetExcuteTID( void ) const
{
	return m_tExcuteTID;
}


#endif