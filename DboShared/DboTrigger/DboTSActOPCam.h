#ifndef _DBO_TSACTOPCAM_H_
#define _DBO_TSACTOPCAM_H_


#include "DboTSCoreDefine.h"


/**
	Operation camera action
	�뵵 : Client quest, client trigger
	���� : Ŭ���̾�Ʈ �������� ���Ǵ� ī�޶� ���� �׼�
*/


class CDboTSActOPCam : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	std::string							m_strFuncName;

// Constructions
public:
	CDboTSActOPCam( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_OPCAM; }

	const std::string&					GetFuncName( void ) const;
	void								SetFuncName( const std::string& strFName );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline const std::string& CDboTSActOPCam::GetFuncName( void ) const
{
	return m_strFuncName;
}


#endif