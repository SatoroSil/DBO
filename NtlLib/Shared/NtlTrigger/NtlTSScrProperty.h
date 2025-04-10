#ifndef _NTL_TSSCRPROPERTY_H_
#define _NTL_TSSCRPROPERTY_H_


#include "NtlTSCoreDefine.h"
#include "NtlTSLog.h"


/** 
	Script property
*/


class CNtlTSScrProperty
{
// Declarations
public:
	typedef std::map<std::string,std::string> hashdef_PROPERTY;
	typedef hashdef_PROPERTY::iterator PROP_IT;
	typedef hashdef_PROPERTY::const_iterator PROP_CIT;

// Member variables
public:
	hashdef_PROPERTY					m_defProperty;

// Constructions and Destructions
public:
	CNtlTSScrProperty( void ) { return; }
	~CNtlTSScrProperty( void ) { return; }

// Methods
public:
	PROP_IT								Begin( void );
	PROP_IT								End( void );

	PROP_CIT							Begin( void ) const;
	PROP_CIT							End( void ) const;

	// �ش� Property �� �����ϴ� ���� �˻��Ѵ�.
	bool								IsExist( const std::string& strPropertyName ) const;

	// ����� Property �� ������ �����Ѵ�
	int									GetCount( const std::string& strPropertyName ) const;

	// �ش� Property Name �� ���ؼ� Property Value�� ��´�
	const std::string&					GetValue( const std::string& strPropertyName, int nOffset = 0 ) const;

	// int �� �ش� Property �� ��´�
	int									GetValueAsInt( const std::string& strPropertyName, int nOffset = 0 ) const;

	// bool�� �ش� Property �� ��´�
	bool								GetValueAsBool( const std::string& strPropertyName, int nOffset = 0 ) const;

	// Property�� �߰� �Ѵ�
	void								AddProperty( const std::string& strPropertyName, const std::string& strPropertyValue );

	// �ش� Property�� ���� �Ѵ�
	void								RemoveProperty( const std::string& strPropertyName );

	// ��� Property�� �����Ѵ�
	void								Clear( void );

// Operator
public:
	const std::string& operator[] ( const std::string& strPropertyName ) const;
};


#include "NtlTSScrProperty.inl"


#endif

