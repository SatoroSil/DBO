//////////////////////////////////////////////////////////////////////////
/**
*	Matrix3 Ŭ����
*	�޼� ��ǥ��, �຤�͸� �������� ������ 3 X 3 ���.
*
*	\file		NtlNaviMatrix3.h
*	\author		Jeong Ho, Rho
*/
//////////////////////////////////////////////////////////////////////////


#ifndef _NTL_NAVI_MATRIX3_H_
#define _NTL_NAVI_MATRIX3_H_


#include "NtlNaviVector3.h"


class CNtlNaviMatrix3
{
protected:

	union
	{
		float								m_fSAElem[9];
		float								m_fDAElem[3][3];
	};


public:

	inline									CNtlNaviMatrix3( bool bIdentity = false );

	inline									CNtlNaviMatrix3( const CNtlNaviMatrix3& m3Val );

	inline									CNtlNaviMatrix3( const CNtlNaviVector3& v3ValX,
															 const CNtlNaviVector3& v3ValY,
															 const CNtlNaviVector3& v3ValZ );

	inline									CNtlNaviMatrix3( float f00, float f01, float f02,
															 float f10, float f11, float f12,
															 float f20, float f21, float f22 );

	inline									CNtlNaviMatrix3( const float* pfVal );

	inline									~CNtlNaviMatrix3( void )	{ return; }


public:
	inline			float					GetElem( int nIdx ) const;

	inline			float					GetElem( int nRow, int nCol ) const;


	inline			void					SetElem( int nRow, int nCol, float fVal );

	inline			void					SetElem( float f00, float f01, float f02,
													 float f10, float f11, float f12,
													 float f20, float f21, float f22 );

	inline			void					SetElem( const CNtlNaviVector3& v3ValX,
													 const CNtlNaviVector3& v3ValY,
													 const CNtlNaviVector3& v3ValZ );

	inline 			void					SetElem( const float* pfVal );


	inline			CNtlNaviVector3&		GetRow( int nRow );

	inline			const CNtlNaviVector3&	GetRow( int nRow ) const;

	inline			void					GetRow( int nRow, CNtlNaviVector3& v3Val ) const;

	inline			void					SetRow( int nRow, const CNtlNaviVector3& v3Val );


	inline			const CNtlNaviVector3	GetCol( int nRow ) const;

	inline			void					GetCol( int nCol, CNtlNaviVector3& v3Val ) const;


	inline			void					SetCol( int nCol, const CNtlNaviVector3& v3Val );

	inline			void					Scale( float fX, float fY, float fZ );

public:

	// ����� ��� ��ҵ��� ��ȿȭ�Ѵ�.

	inline			void					MakeInvalid( void );


	// �� ��ķ� �����.

	inline			void					MakeZero( void );


	// ���� ��ķ� �����.

	inline			void					MakeIdentity( void );


	// �밢 ��ķ� �����.

	inline			void					MakeDiagonal( float fVal );

	inline			void					MakeDiagonal( float f00, float f11, float f22 );

	inline			void					MakeDiagonal( const CNtlNaviVector3& v3Val );


	// ���Ϸ�(Euler) ȸ��.
	// ��������(Orthonormal) ����� ������� �����Ѵ�.

	inline			void					GetEulerRotXYZ( float& fX, float& fY, float& fZ ) const;

	inline			void					GetEulerRotXZY( float& fX, float& fY, float& fZ ) const;

	inline			void					GetEulerRotYXZ( float& fX, float& fY, float& fZ ) const;

	inline			void					GetEulerRotYZX( float& fX, float& fY, float& fZ ) const;

	inline			void					GetEulerRotZXY( float& fX, float& fY, float& fZ ) const;

	inline			void					GetEulerRotZYX( float& fX, float& fY, float& fZ ) const;


	inline			void					MakeEulerRotX( float fVal );

	inline			void					MakeEulerRotY( float fVal );

	inline			void					MakeEulerRotZ( float fVal );

	inline			void					MakeEulerRotXYZ( float fX, float fY, float fZ );

	inline			void					MakeEulerRotXZY( float fX, float fY, float fZ );

	inline			void					MakeEulerRotYXZ( float fX, float fY, float fZ );

	inline			void					MakeEulerRotYZX( float fX, float fY, float fZ );

	inline			void					MakeEulerRotZXY( float fX, float fY, float fZ );

	inline			void					MakeEulerRotZYX( float fX, float fY, float fZ );


	// ������ ���� ���͸� �������� �־��� �� ��ŭ ȸ��.
	// v3Axis�� ���� �����̴�.

	inline			void					GetAxisAngleFromRotMat( CNtlNaviVector3& v3Axis, float& fAngle ) const;

	inline			void					MakeRotMatFromAxisAngle( const CNtlNaviVector3& v3Axis, float fAngle );


	// ��İ�.

	inline			float					GetDet( void ) const;


	// �����.

	inline			bool					CanInverse( void ) const;

	inline			float					GetInverse( CNtlNaviMatrix3& m3Val ) const;

	inline			float					MakeInverse( void );


	// ��ġ ���.

	inline			CNtlNaviMatrix3			GetTranspose( void ) const;

	inline			void					MakeTranspose( void );


	// �밢 ����.

	inline			float					GetTrace( void ) const;


// ������.
public:

	// �Ҵ� ������.

	inline			CNtlNaviMatrix3&		operator = ( const CNtlNaviMatrix3& m3Val );


	// ��� ���� ������.

	inline			float*					operator [] ( int nIdx );

	inline			const float*			operator [] ( int nIdx ) const;


	inline			float&					operator () ( int nRow, int nCol );

	inline			const float&			operator () ( int nRow, int nCol ) const;


	// �� ������.

	inline			bool					operator == ( const CNtlNaviMatrix3& m3Val ) const;

	inline			bool					operator != ( const CNtlNaviMatrix3& m3Val ) const;


	// ��� ������.

	inline			CNtlNaviMatrix3			operator - ( void ) const;


	inline			CNtlNaviMatrix3			operator * ( float fVal ) const;

	inline			CNtlNaviMatrix3			operator / ( float fVal ) const;


	inline			CNtlNaviMatrix3			operator + ( const CNtlNaviMatrix3& m3Val ) const;

	inline			CNtlNaviMatrix3			operator - ( const CNtlNaviMatrix3& m3Val ) const;

	inline			CNtlNaviMatrix3			operator * ( const CNtlNaviMatrix3& m3Val ) const;


	// ��� �ݿ� ������.

	inline			CNtlNaviMatrix3&		operator *= ( float fVal );

	inline			CNtlNaviMatrix3&		operator /= ( float fVal );


	inline			CNtlNaviMatrix3&		operator += ( const CNtlNaviMatrix3& m3Val );

	inline			CNtlNaviMatrix3&		operator -= ( const CNtlNaviMatrix3& m3Val );

	inline			CNtlNaviMatrix3&		operator *= ( const CNtlNaviMatrix3& m3Val );


	// ����ȯ ������.

	inline 									operator float* ( void );

	inline									operator const float* ( void ) const;


	// Friend ó�� ������.

	inline friend	CNtlNaviMatrix3			operator * ( float fVal1, const CNtlNaviMatrix3& m3Val2 );

	inline friend	CNtlNaviMatrix3			operator / ( float fVal1, const CNtlNaviMatrix3& m3Val2 );


	inline friend	CNtlNaviVector3			operator * ( const CNtlNaviVector3& v3Val1, const CNtlNaviMatrix3& m3Val2 );

	inline friend	CNtlNaviVector3			operator * ( const CNtlNaviMatrix3& m3Val1, const CNtlNaviVector3& v3Val2 );


// ���� ����.
protected:

	inline			int						CompareArrays( const CNtlNaviMatrix3& m3Val ) const;
};


#include "NtlNaviMatrix3.inl"


#endif
