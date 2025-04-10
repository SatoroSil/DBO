//////////////////////////////////////////////////////////////////////////
/**
*	Vector4 Ŭ����
*
*	\file		NtlNaviVector4.h
*	\author		Jeong Ho, Rho
*/
//////////////////////////////////////////////////////////////////////////


#ifndef _TX_NAVI_VECTOR4_H_
#define _TX_NAVI_VECTOR4_H_


class CNtlNaviVector4
{
protected:

	float									m_fElem[4];


public:

	inline									CNtlNaviVector4( bool bZero = false );

	inline									CNtlNaviVector4( const CNtlNaviVector4& v4Val );

	inline									CNtlNaviVector4( float fX, float fY, float fZ, float fW );

	inline									CNtlNaviVector4( const float* pfVal );

	inline									~CNtlNaviVector4( void )	{ return; }


public:

	inline			float&					GetX( void );

	inline			const float&			GetX( void ) const;


	inline			float&					GetY( void );

	inline			const float&			GetY( void ) const;


	inline			float&					GetZ( void );

	inline			const float&			GetZ( void ) const;


	inline			float&					GetW( void );

	inline			const float&			GetW( void ) const;


	inline			void					GetXYZW( float& fX, float& fY, float& fZ, float& fW ) const;


	inline			float&					GetElem( int nIdx );

	inline			const float&			GetElem( int nIdx ) const;


	inline			void					SetElem( float fVal );

	inline			void					SetElem( int nIdx, float fVal );

	inline			void					SetElem( const CNtlNaviVector4& v4Val );

	inline			void					SetElem( float fX, float fY, float fZ, float fW );

	inline			void					SetElem( float* pfVal );


// ��� �Լ�.
public:

	// ������ ��� ��ҵ��� ��ȿȭ�Ѵ�.

	inline			void					MakeInvalid( void );

	
	// ���͸� ���� ���ͷ� �����.

	inline			void					MakeUnitX( void );

	inline			void					MakeUnitY( void );

	inline			void					MakeUnitZ( void );

	inline			void					MakeUnitW( void );


	// �� ���ͷ� �����.

	inline			void					MakeZero( void );


	// ����ȭ.

	inline			CNtlNaviVector4			GetNormalize( void ) const;

	inline			void					MakeNormalize( void );


	// ����.

	inline			float					GetLength( void ) const;


	// ������ ����.

	inline			float					GetLengthSquared( void ) const;


// ������.
public:

	// �Ҵ� ������.

	inline			CNtlNaviVector4&		operator = ( const CNtlNaviVector4& v4Val );


	// ��� ���� ������.

	inline			float&					operator [] ( int nIdx );

	inline			const float&			operator [] ( int nIdx ) const;


	inline			float&					operator () ( int nIdx );

	inline			const float&			operator () ( int nIdx ) const;


	// �� ������.

	inline			bool					operator == ( const CNtlNaviVector4& v4Val ) const;

	inline			bool					operator != ( const CNtlNaviVector4& v4Val ) const;


	// ��� ������.

	inline			CNtlNaviVector4			operator - ( void ) const;


	inline			CNtlNaviVector4			operator * ( float fVal ) const;

	inline			CNtlNaviVector4			operator * ( const CNtlNaviVector4& v4Val ) const;


	inline			CNtlNaviVector4			operator / ( float fVal ) const;

	inline			CNtlNaviVector4			operator / ( const CNtlNaviVector4& v4Val ) const;


	inline			CNtlNaviVector4			operator + ( const CNtlNaviVector4& v4Val ) const;

	inline			CNtlNaviVector4			operator - ( const CNtlNaviVector4& v4Val ) const;


	// ��� ���� ������.

	inline			CNtlNaviVector4&		operator *= ( float fVal );

	inline			CNtlNaviVector4&		operator *= ( const CNtlNaviVector4& v4Val );


	inline			CNtlNaviVector4&		operator /= ( float fVal );

	inline			CNtlNaviVector4&		operator /= ( const CNtlNaviVector4& v4Val );


	inline			CNtlNaviVector4&		operator += ( const CNtlNaviVector4& v4Val );

	inline			CNtlNaviVector4&		operator -= ( const CNtlNaviVector4& v4Val );


	// ����ȯ ������.

	inline									operator float* ( void );

	inline									operator const float* ( void ) const;


// ���� ����.
protected:

	inline			int						CompareArrays( const CNtlNaviVector4& v4Val ) const;
};


#include "NtlNaviVector4.inl"


#endif
