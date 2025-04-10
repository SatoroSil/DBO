#ifndef _DBO_TSACTTMQINFOSHOW_H_
#define _DBO_TSACTTMQINFOSHOW_H_


#include "DboTSCoreDefine.h"
#include "NtlTimeQuest.h"


class CDboTSActTMQInfoShow : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	eTIMEQUEST_INFORMATION_TYPE			m_eInfoType;

// Constructions
public:
	CDboTSActTMQInfoShow( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_TMQINFOTYPE; }

	eTIMEQUEST_INFORMATION_TYPE			GetTMQInfoType( void ) const;
	void								SetTMQInfoType( eTIMEQUEST_INFORMATION_TYPE eInfoType );



// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline eTIMEQUEST_INFORMATION_TYPE CDboTSActTMQInfoShow::GetTMQInfoType( void ) const
{
	return m_eInfoType;
}


#endif