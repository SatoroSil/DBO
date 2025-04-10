//////////////////////////////////////////////////////////////////////////
/**
*	Vector3 Ŭ����
*
*	\file		NtlNaviVector3.h
*	\author		Jeong Ho, Rho
*/
//////////////////////////////////////////////////////////////////////////


#ifndef _TX_NAVI_VECTOR3_H_
#define _TX_NAVI_VECTOR3_H_


class CNtlNaviVector3
{
protected:

	float									m_fElem[3];


public:

	inline									CNtlNaviVector3( bool bZero = false );

	inline									CNtlNaviVector3( const CNtlNaviVector3& v3Val );

	inline									CNtlNaviVector3( float fX, float fY, float fZ );

	inline									CNtlNaviVector3( const float* pfVal );

	inline									~CNtlNaviVector3( void )	{ return; }


public:

	inline			float&					GetX( void );

	inline			const float&			GetX( void ) const;


	inline			float&					GetY( void );

	inline			const float&			GetY( void ) const;


	inline			float&					GetZ( void );

	inline			const float&			GetZ( void ) const;


	inline			void					GetXYZ( float& fX, float& fY, float& fZ ) const;


	inline			float&					GetElem( int nIdx );

	inline			const float&			GetElem( int nIdx ) const;


	inline			void					SetElem( float fVal );

	inline			void					SetElem( int nIdx, float fVal );

	inline			void					SetElem( const CNtlNaviVector3& v3Val );

	inline			void					SetElem( float fX, float fY, float fZ );

	inline			void					SetElem( float* pfVal );


// ��� �Լ�.
public:

	// ������ ��� ��ҵ��� ��ȿȭ�Ѵ�.

	inline			void					MakeInvalid( void );


	// ���͸� ���� ���ͷ� �����.

	inline			void					MakeUnitX( void );

	inline			void					MakeUnitY( void );

	inline			void					MakeUnitZ( void );


	// �� ���ͷ� �����.

	inline			void					MakeZero( void );


	// ����ȭ.

	inline			CNtlNaviVector3			GetNormalize( void ) const;

	inline			void					MakeNormalize( void );


	// �� ���͸� �̿��Ͽ� �ڽ��� ���� ���� < T = V1 + t * ( V2 - V1 ) > �Ѵ�.

	inline			void					MakeLerp( const CNtlNaviVector3& v3Val1, const CNtlNaviVector3& v3Val2, float t );


	// ����.
	inline			float					GetLength( void ) const;


	// ������ ����.

	inline			float					GetLengthSquared( void ) const;


	// ����.

	inline			float					GetDot( const CNtlNaviVector3& v3Val ) const;


	// ���� < R = T ^ V >.

	inline			CNtlNaviVector3			GetCross( const CNtlNaviVector3& v3Val ) const;

	inline			void					MakeCross( const CNtlNaviVector3& v3Val );


	// ����.

	inline			float					GetVolume( void ) const;


	// �ڽŰ� �־��� ��(�Ķ����) ���� �Ÿ�.

	inline			float					GetDistance( const CNtlNaviVector3& v3Val ) const;


	// �ڽŰ� �־��� ��(�Ķ����) ���� �Ÿ��� ����.

	inline			float					GetDistanceSquared( const CNtlNaviVector3& v3Val ) const;


// ������.
public:

	// �Ҵ� ������.

	inline			CNtlNaviVector3&		operator = ( const CNtlNaviVector3& v3Val );


	// ��� ���� ������.

	inline			float&					operator [] ( int nIdx );

	inline			const float&			operator [] ( int nIdx ) const;


	inline			float&					operator () ( int nIdx );

	inline			const float&			operator () ( int nIdx ) const;


	// �� ������.

	inline			bool					operator == ( const CNtlNaviVector3& v3Val ) const;

	inline			bool					operator != ( const CNtlNaviVector3& v3Val ) const;


	// ��� ������.

	inline			CNtlNaviVector3			operator - ( void ) const;


	inline			CNtlNaviVector3			operator * ( float fVal ) const;

	inline			CNtlNaviVector3			operator * ( const CNtlNaviVector3& v3Val ) const;

	inline			CNtlNaviVector3			operator / ( float fVal ) const;

	inline			CNtlNaviVector3			operator / ( const CNtlNaviVector3& v3Val ) const;

	inline			CNtlNaviVector3			operator + ( const CNtlNaviVector3& v3Val ) const;

	inline			CNtlNaviVector3			operator - ( const CNtlNaviVector3& v3Val ) const;


	// ��� ���� ������.

	inline			CNtlNaviVector3&		operator *= ( float fVal );

	inline			CNtlNaviVector3&		operator *= ( const CNtlNaviVector3& v3Val );

	inline			CNtlNaviVector3&		operator /= ( float fVal );

	inline			CNtlNaviVector3&		operator /= ( const CNtlNaviVector3& v3Val );


	inline			CNtlNaviVector3&		operator += ( const CNtlNaviVector3& v3Val );

	inline			CNtlNaviVector3&		operator -= ( const CNtlNaviVector3& v3Val );


	// ����ȯ ������.

	inline									operator float* ( void );

	inline									operator const float* ( void ) const;


	// ���� ������.

	inline			float					operator | ( const CNtlNaviVector3& v3Val ) const;


	// ���� ������.

	inline			CNtlNaviVector3			operator ^ ( const CNtlNaviVector3& v3Val ) const;


	// ���� ���� ������ < T = T * (T | V) >.

	inline			CNtlNaviVector3&		operator |= ( const CNtlNaviVector3& v3Val );


	// ���� ���� ������ < T = T ^ V >.

	inline			CNtlNaviVector3&		operator ^= ( const CNtlNaviVector3& v3Val );


	// Friend ó�� ������.

	inline friend	CNtlNaviVector3			operator * ( float fVal1, const CNtlNaviVector3& v3Val2 );

	inline friend	CNtlNaviVector3			operator / ( float fVal1, const CNtlNaviVector3& v3Val2 );


// ���� ����.
protected:

	inline			int						CompareArrays( const CNtlNaviVector3& v3Val ) const;
};


#include "NtlNaviVector3.inl"


#endif
