#ifndef _DBO_TSACTWPSFD_H_
#define _DBO_TSACTWPSFD_H_


#include "DboTSCoreDefine.h"


/**
	WPSFD action
*/


class CDboTSActWPSFD : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:

	NTL_TS_T_ID						m_tSidx;
	NTL_TS_TA_ID					m_TaIdx;

// Constructions
public:
	CDboTSActWPSFD( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_WPSFD; }


	NTL_TS_T_ID						GetTsIdx( void ) const;
	NTL_TS_TA_ID					GetTaIdx( void ) const;

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline NTL_TS_T_ID CDboTSActWPSFD::GetTsIdx( void ) const
{
	return m_tSidx;
}

inline NTL_TS_TA_ID CDboTSActWPSFD::GetTaIdx( void ) const
{
	return m_TaIdx;
}


#endif