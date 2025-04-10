//////////////////////////////////////////////////////////////////////////
/**
*	Matrix4 Ŭ����
*	�޼� ��ǥ��, �຤�͸� �������� ������ 4 X 4 ���.
*
*	\file		NtlNaviMatrix4.h
*	\author		Jeong Ho, Rho
*/
//////////////////////////////////////////////////////////////////////////


#ifndef _NTL_NAVI_MATRIX4_H_
#define _NTL_NAVI_MATRIX4_H_


#include "NtlNaviVector4.h"
#include "NtlNaviMatrix3.h"



class CNtlNaviMatrix4
{
protected:

	union
	{
		float								m_fSAElem[16];
		float								m_fDAElem[4][4];
	};


public:

	inline									CNtlNaviMatrix4( bool bIdentity = false );

	inline									CNtlNaviMatrix4( const CNtlNaviMatrix3& m3Val );

	inline									CNtlNaviMatrix4( const CNtlNaviMatrix3& m3Rot, const CNtlNaviVector3& v3Trans );

	inline									CNtlNaviMatrix4( const CNtlNaviMatrix4& m4Val );

	inline									CNtlNaviMatrix4( const CNtlNaviVector3& v3ValX,
															 const CNtlNaviVector3& v3ValY,
															 const CNtlNaviVector3& v3ValZ );

	inline									CNtlNaviMatrix4( const CNtlNaviVector3& v3ValX,
															 const CNtlNaviVector3& v3ValY,
															 const CNtlNaviVector3& v3ValZ,
															 const CNtlNaviVector3& v3ValT );

	inline									CNtlNaviMatrix4( const CNtlNaviVector4& v4ValX,
															 const CNtlNaviVector4& v4ValY,
															 const CNtlNaviVector4& v4ValZ );

	inline									CNtlNaviMatrix4( const CNtlNaviVector4& v4ValX,
															 const CNtlNaviVector4& v4ValY,
															 const CNtlNaviVector4& v4ValZ,
															 const CNtlNaviVector4& v4ValT );

	inline									CNtlNaviMatrix4( float f00, float f01, float f02, float f03,
															 float f10, float f11, float f12, float f13,
															 float f20, float f21, float f22, float f23,
															 float f30, float f31, float f32, float f33 );

	inline									CNtlNaviMatrix4( const float* pfVal );

	
	// �Ҹ���.

	inline									~CNtlNaviMatrix4( void )	{ return; }


// ��� ���� ����.
public:

	// �⺻ ��� ���� ���� �Լ���.

	inline			float					GetElem( int nIdx ) const;

	inline			float					GetElem( int nRow, int nCol ) const;


	inline			void					SetElem( int nRow, int nCol, float fVal );

	inline			void					SetElem( const CNtlNaviMatrix3& m3Val );

	inline			void					SetElem( const CNtlNaviMatrix3& m3Rot, const CNtlNaviVector3& v3Trans );

	inline			void					SetElem( const CNtlNaviVector3& v3ValX,
													 const CNtlNaviVector3& v3ValY,
													 const CNtlNaviVector3& v3ValZ );

	inline			void					SetElem( const CNtlNaviVector3& v3ValX,
													 const CNtlNaviVector3& v3ValY,
													 const CNtlNaviVector3& v3ValZ,
													 const CNtlNaviVector3& v3ValT );

	inline			void					SetElem( const CNtlNaviVector4& v4ValX,
													 const CNtlNaviVector4& v4ValY,
													 const CNtlNaviVector4& v4ValZ );

	inline			void					SetElem( const CNtlNaviVector4& v4ValX,
													 const CNtlNaviVector4& v4ValY,
													 const CNtlNaviVector4& v4ValZ,
													 const CNtlNaviVector4& v4ValT );

	inline			void					SetElem( float f00, float f01, float f02, float f03,
													 float f10, float f11, float f12, float f13,
													 float f20, float f21, float f22, float f23,
													 float f30, float f31, float f32, float f33 );

	inline 			void					SetElem( const float* pfVal );


	// �� ���� ���� �Լ���.

	inline			CNtlNaviVector3&		GetRow( int nRow );

	inline			const CNtlNaviVector3&	GetRow( int nRow ) const;

	inline			void					GetRow( int nRow, CNtlNaviVector3& v3Val ) const;


	inline			void					SetRow( int nRow, const CNtlNaviVector3& v3Val );


	// �� ���� ���� �Լ���.

	inline			const CNtlNaviVector3	GetCol( int nCol ) const;

	inline			void					GetCol( int nCol, CNtlNaviVector3& v3Val ) const;


	inline			void					SetCol( int nCol, const CNtlNaviVector3& v3Val );


// ��� �Լ�.
public:

	// ����� ��� ��ҵ��� ��ȿȭ�Ѵ�.

	inline			void					MakeInvalid( void );


	// �� ��ķ� �����.

	inline			void					MakeZero( void );


	// ���� ��ķ� �����.

	inline			void					MakeIdentity( void );


	// ��İ�.

	inline			float					GetDet( void ) const;


	// �����.

	inline			bool					CanInverse( void ) const;

	inline			float					GetInverse( CNtlNaviMatrix4& m4Val ) const;

	inline			float					MakeInverse( void );


	// ��ġ ���.

	inline			CNtlNaviMatrix4			GetTranspose( void ) const;

	inline			void					MakeTranspose( void );


	// �밢 ����.

	inline			float					GetTrace( void ) const;


// ������.
public:

	// �Ҵ� ������.

	// CNtlNaviMatrix3 �� �ش��ϴ� ��Ҹ� �� �����Ѵ�.

	inline			CNtlNaviMatrix4&		operator = ( const CNtlNaviMatrix3& m3Val );

	inline			CNtlNaviMatrix4&		operator = ( const CNtlNaviMatrix4& m4Val );


	// ��� ���� ������.

	inline			float*					operator [] ( int nIdx );

	inline			const float*			operator [] ( int nIdx ) const;


	inline			float&					operator () ( int nRow, int nCol );

	inline			const float&			operator () ( int nRow, int nCol ) const;


	// �� ������.

	inline			bool					operator == ( const CNtlNaviMatrix4& m4Val ) const;

	inline			bool					operator != ( const CNtlNaviMatrix4& m4Val ) const;


	// ��� ������.

	inline			CNtlNaviMatrix4			operator - ( void ) const;


	inline			CNtlNaviMatrix4			operator * ( float fVal ) const;

	inline			CNtlNaviMatrix4			operator / ( float fVal ) const;


	inline			CNtlNaviMatrix4			operator + ( const CNtlNaviMatrix4& m4Val ) const;

	inline			CNtlNaviMatrix4			operator - ( const CNtlNaviMatrix4& m4Val ) const;

	inline			CNtlNaviMatrix4			operator * ( const CNtlNaviMatrix4& m4Val ) const;


	// ��� �ݿ� ������.

	inline			CNtlNaviMatrix4&		operator *= ( float fVal );

	inline			CNtlNaviMatrix4&		operator /= ( float fVal );


	inline			CNtlNaviMatrix4&		operator += ( const CNtlNaviMatrix4& m4Val );

	inline			CNtlNaviMatrix4&		operator -= ( const CNtlNaviMatrix4& m4Val );

	inline			CNtlNaviMatrix4&		operator *= ( const CNtlNaviMatrix4& m4Val );


	// ����ȯ ������.

	inline 									operator CNtlNaviMatrix3 ( void );

	inline 									operator float* ( void );

	inline									operator const float* ( void ) const;


	// Friend ó�� ������.

	inline friend	CNtlNaviMatrix4			operator * ( float fVal1, const CNtlNaviMatrix4& m4Val2 );

	inline friend	CNtlNaviMatrix4			operator / ( float fVal1, const CNtlNaviMatrix4& m4Val2 );


	inline friend	CNtlNaviVector4			operator * ( const CNtlNaviVector4& v4Val1, const CNtlNaviMatrix4& m4Val2 );

	inline friend	CNtlNaviVector4			operator * ( const CNtlNaviMatrix4& m4Val1, const CNtlNaviVector4& v4Val2 );


// ���� ����.
protected:

	inline			int						CompareArrays( const CNtlNaviMatrix4& m4Val ) const;
};


#include "NtlNaviMatrix4.inl"


#endif
