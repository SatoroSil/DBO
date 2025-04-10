#ifndef _DBO_TSCHECKSTOCEVT_H
#define _DBO_TSCHECKSTOCEVT_H


#include "DboTSCoreDefine.h"


/**
	Check server to client event condition
	�뵵 : Client quest, client trigger, server quest, server trigger pc
*/


class CDboTSCheckSToCEvt : public CNtlTSCond
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	eSTOC_EVT_DATA_TYPE					m_eSToCEvtDataType;

// Constructions
public:
	CDboTSCheckSToCEvt( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_COND_TYPE_ID_CHECK_STOCEVT; }

	eSTOC_EVT_DATA_TYPE					GetSToCEvtDataType( void ) const;
	void								SetSToCEvtDataType( eSTOC_EVT_DATA_TYPE eSToCEvtDataType );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline eSTOC_EVT_DATA_TYPE CDboTSCheckSToCEvt::GetSToCEvtDataType( void ) const
{
	return m_eSToCEvtDataType;
}


#endif