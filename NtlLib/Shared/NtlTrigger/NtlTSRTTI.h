#ifndef _NTL_TSRTTI_H_
#define _NTL_TSRTTI_H_


/** 
	Runtime type infomation
*/


//////////////////////////////////////////////////////////////////////////


#define NTL_TS_DECLARE_RTTI \
	public: \
		static	const CNtlTSRTTI	RTTI; \
		virtual	const CNtlTSRTTI&	GetRTTI( void )	const { return RTTI; } \
				const char*			GetClassName( void ) const { return GetRTTI().GetClassName(); } \
				bool				IsSameClass( const CNtlTSRTTI& clVal ) const { return GetRTTI().IsSameClass( clVal ); } \
				bool				IsDerivedClass( const CNtlTSRTTI& clVal ) const { return GetRTTI().IsDerivedClass( clVal ); } \
				bool				IsDerivedClass( const std::string& strClassName ) const { return GetRTTI().IsDerivedClass( strClassName ); }


#define NTL_TS_IMPLEMENT_RTTI_ROOT( classname ) \
	const CNtlTSRTTI	classname::RTTI( #classname, 0 );


#define NTL_TS_IMPLEMENT_RTTI( classname, baseclassname ) \
	const CNtlTSRTTI	classname::RTTI( #classname, &baseclassname::RTTI );


//////////////////////////////////////////////////////////////////////////


class CNtlTSRTTI
{
// Member variables
private:

	// Ŭ������ �̸��� ���� ��� ������ const char* �� ����ؼ�
	// �����ڸ� ���� �Ѱܹ��� ���ڿ��� �����͸� �״�� �����ص� �������
	// ������ �ܺο��� �Ѱ� �޴� Ŭ���� �̸��� ���� ������ ����ǹǷ�
	// ���� �ش� ���ڿ��� �����͸� ��������� �����ϴ� ���� �޸�
	// ���� �������� ������ �ִ�.

	const char*							m_pClassName;

	const CNtlTSRTTI*					m_pBaseRTTI;


// Constructions and Destructions
public:
	CNtlTSRTTI( const char* pClassName, const CNtlTSRTTI* pBaseRTTI );


// ��� �Լ�.
public:
	const char*							GetClassName( void ) const;

	bool								IsSameClass( const CNtlTSRTTI& clVal ) const;

	bool								IsDerivedClass( const CNtlTSRTTI& clVal ) const;

	bool								IsDerivedClass( const std::string& strClassName ) const;
};


#include "NtlTSRTTI.inl"


//////////////////////////////////////////////////////////////////////////


#endif