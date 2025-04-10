#ifndef _NTL_TSENTITYFACTORY_H_
#define _NTL_TSENTITYFACTORY_H_


#include "NtlTSScrFactory.h"


class CNtlTSEntityFactoryType;


/**
	Entity factory
*/


class CNtlTSEntityFactory : public CNtlTSScrFactory
{
// Declarations
public:
	typedef std::map<std::string,CNtlTSEntityFactoryType*> mapdef_EntityTypeList;

// Member variables
protected:
	mapdef_EntityTypeList				m_defEntityTypeList;		// �ǽð� ���� ������ �����ϱ� ���� Ÿ�� ����Ʈ

// Constructions and Destructions
public:
	CNtlTSEntityFactory( void );
	virtual ~CNtlTSEntityFactory( void );

// Methods
public:
	virtual	CNtlTSScrFactoryType*		GetFactoryType( const std::string& strClassName );

	virtual	CNtlTSScrObject*			CreateObj( const std::string& strName );
	virtual void						DeleteObj( CNtlTSScrObject*& pObj );

	// Runtime ������ ���� Entity type ���
	virtual	void						RegisterEntityType( void );
	virtual	void						UnRegisterEntityType( void );
};


#endif