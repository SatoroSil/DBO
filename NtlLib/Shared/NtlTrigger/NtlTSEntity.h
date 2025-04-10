#ifndef _NTL_TSENTITY_H_
#define _NTL_TSENTITY_H_


#include "NtlTSLog.h"
#include "NtlTSRTTI.h"
#include "NtlTSCoreDefine.h"
#include "NtlTSScrObject.h"


class CNtlTSRecv;


/**
	Entity
*/


class CNtlTSEntity : public CNtlTSScrObject
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	CNtlTSEntity*						m_pParent;		// �θ� Entity

// Constructions and Destructions
public:
	CNtlTSEntity( void );
	virtual ~CNtlTSEntity( void ) { return; }

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return NTL_TSENTITY_TYPE_INVALID; }

	CNtlTSEntity*						GetParent( void );
	CNtlTSEntity*						SetParent( CNtlTSEntity* pParent );

	CNtlTSEntity*						GetRoot( void );

	// �ڽ� �� �ڽ� entity�鿡 ���� Ž�� �� ����
	virtual	NTL_TSRESULT				SearchSelf( CNtlTSRecv* pTSRecv, void* pParam );
	virtual	NTL_TSRESULT				RunSelf( CNtlTSRecv* pTSRecv, void* pParam );

// Implementations
protected:
	// ��ũ��Ʈ���� ���Ǵ� �θ� ���� �Լ���
	virtual	CNtlTSScrObject*			GetParentForScript( void );
	virtual	void						SetParentForScript( CNtlTSScrObject* pParent );

	// ��ũ��Ʈ���� ���Ǵ� �ڽ� ���� �Լ���
	virtual	CNtlTSScrObject*			BeginChildForScript( void ) { return 0; }
	virtual	CNtlTSScrObject*			NextChildForScript( void ) { return 0; }
	virtual	void						AttachChildForScript( CNtlTSScrObject* ) { return; }

public:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& ) { return; }
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& ) { return; }

public:
	virtual void						MakeAllObjectList( std::vector<CNtlTSScrObject*>& defObjList );
};


inline CNtlTSScrObject* CNtlTSEntity::GetParentForScript( void )
{
	return m_pParent;
}

inline void CNtlTSEntity::SetParentForScript( CNtlTSScrObject* pParent )
{
	if ( pParent->IsDerivedClass( "CNtlTSEntity" ) )
	{
		m_pParent = (CNtlTSEntity*)pParent;
	}
	else
	{
		printf( "Can not do type cast from CNtlTSScrObject to CNtlTSEntity. ParamInfo [%s]. [%s]",
						pParent ? pParent->GetClassName() : "NULL", TS_CODE_TRACE() );
	}
}


#endif