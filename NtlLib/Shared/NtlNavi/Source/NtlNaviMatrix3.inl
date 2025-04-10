//////////////////////////////////////////////////////////////////////////
/**
 *	Matrix3 Ŭ����
 *	�޼� ��ǥ��, �຤�͸� �������� ������ 3 X 3 ���.
 *
 *	\file		NtlNaviMatrix3.h
 *	\author		Jeong Ho, Rho
*/
//////////////////////////////////////////////////////////////////////////


CNtlNaviMatrix3::CNtlNaviMatrix3( bool bIdentity )
{
	if ( bIdentity ) MakeIdentity();
}


CNtlNaviMatrix3::CNtlNaviMatrix3( const CNtlNaviMatrix3& m3Val )
{
	memcpy( m_fSAElem, m3Val.m_fSAElem, sizeof(float)*9 );
}


CNtlNaviMatrix3::CNtlNaviMatrix3( const CNtlNaviVector3& v3ValX,
								  const CNtlNaviVector3& v3ValY,
								  const CNtlNaviVector3& v3ValZ )
{
	SetElem( v3ValX, v3ValY, v3ValZ );
}


CNtlNaviMatrix3::CNtlNaviMatrix3( float f00, float f01, float f02,
								  float f10, float f11, float f12,
								  float f20, float f21, float f22 )
{
	SetElem( f00, f01, f02, f10, f11, f12, f20, f21, f22 );
}


CNtlNaviMatrix3::CNtlNaviMatrix3( const float* pfVal )
{
	SetElem( pfVal );
}


float CNtlNaviMatrix3::GetElem( int nIdx ) const
{
	return m_fSAElem[nIdx];
}


float CNtlNaviMatrix3::GetElem( int nRow, int nCol ) const
{
	return m_fDAElem[nRow][nCol];
}


void CNtlNaviMatrix3::SetElem( int nRow, int nCol, float fVal )
{
	m_fDAElem[nRow][nCol] = fVal;
}


void CNtlNaviMatrix3::SetElem( float f00, float f01, float f02,
							   float f10, float f11, float f12,
							   float f20, float f21, float f22 )
{
	m_fDAElem[0][0] = f00;	m_fDAElem[0][1] = f01;	m_fDAElem[0][2] = f02;
	m_fDAElem[1][0] = f10;	m_fDAElem[1][1] = f11;	m_fDAElem[1][2] = f12;
	m_fDAElem[2][0] = f20;	m_fDAElem[2][1] = f21;	m_fDAElem[2][2] = f22;
}


void CNtlNaviMatrix3::SetElem( const CNtlNaviVector3& v3ValX,
							   const CNtlNaviVector3& v3ValY,
							   const CNtlNaviVector3& v3ValZ )
{
	v3ValX.GetXYZ( m_fDAElem[0][0], m_fDAElem[0][1], m_fDAElem[0][2] );
	v3ValY.GetXYZ( m_fDAElem[1][0], m_fDAElem[1][1], m_fDAElem[1][2] );
	v3ValZ.GetXYZ( m_fDAElem[2][0], m_fDAElem[2][1], m_fDAElem[2][2] );
}


void CNtlNaviMatrix3::SetElem( const float* pfVal )
{
	memcpy( m_fSAElem, pfVal, sizeof(float)*9 );
}


CNtlNaviVector3& CNtlNaviMatrix3::GetRow( int nRow )
{
	return *(CNtlNaviVector3*)&m_fDAElem[nRow][0];
}


const CNtlNaviVector3& CNtlNaviMatrix3::GetRow( int nRow ) const
{
	return *(const CNtlNaviVector3*)&m_fDAElem[nRow][0];
}


void CNtlNaviMatrix3::GetRow( int nRow, CNtlNaviVector3& v3Val ) const
{
	v3Val.SetElem( m_fDAElem[nRow][0], m_fDAElem[nRow][1], m_fDAElem[nRow][2] );
}


void CNtlNaviMatrix3::SetRow( int nRow, const CNtlNaviVector3& v3Val )
{
	v3Val.GetXYZ( m_fDAElem[nRow][0], m_fDAElem[nRow][1], m_fDAElem[nRow][2] );
}


const CNtlNaviVector3 CNtlNaviMatrix3::GetCol( int nRow ) const
{
	return CNtlNaviVector3( m_fDAElem[nRow][0], m_fDAElem[nRow][1], m_fDAElem[nRow][2] );
}


void CNtlNaviMatrix3::GetCol( int nCol, CNtlNaviVector3& v3Val ) const
{
	v3Val.SetElem( m_fDAElem[0][nCol], m_fDAElem[1][nCol], m_fDAElem[2][nCol] );
}


void CNtlNaviMatrix3::SetCol( int nCol, const CNtlNaviVector3& v3Val )
{
	v3Val.GetXYZ( m_fDAElem[0][nCol], m_fDAElem[1][nCol], m_fDAElem[2][nCol] );
}

void CNtlNaviMatrix3::Scale( float fX, float fY, float fZ )
{
	m_fDAElem[0][0] *= fX;	m_fDAElem[0][1] *= fX;	m_fDAElem[0][2] *= fX;
	m_fDAElem[1][0] *= fY;	m_fDAElem[1][1] *= fY;	m_fDAElem[1][2] *= fY;
	m_fDAElem[2][0] *= fZ;	m_fDAElem[2][1] *= fZ;	m_fDAElem[2][2] *= fZ;
}

void CNtlNaviMatrix3::MakeInvalid( void )
{
	m_fDAElem[0][0] = NAVI_FLT_MAX;	m_fDAElem[0][1] = NAVI_FLT_MAX;	m_fDAElem[0][2] = NAVI_FLT_MAX;
	m_fDAElem[1][0] = NAVI_FLT_MAX;	m_fDAElem[1][1] = NAVI_FLT_MAX;	m_fDAElem[1][2] = NAVI_FLT_MAX;
	m_fDAElem[2][0] = NAVI_FLT_MAX;	m_fDAElem[2][1] = NAVI_FLT_MAX;	m_fDAElem[2][2] = NAVI_FLT_MAX;
}


void CNtlNaviMatrix3::MakeZero( void )
{
	m_fDAElem[0][0] = 0.f;	m_fDAElem[0][1] = 0.f;	m_fDAElem[0][2] = 0.f;
	m_fDAElem[1][0] = 0.f;	m_fDAElem[1][1] = 0.f;	m_fDAElem[1][2] = 0.f;
	m_fDAElem[2][0] = 0.f;	m_fDAElem[2][1] = 0.f;	m_fDAElem[2][2] = 0.f;
}


void CNtlNaviMatrix3::MakeIdentity( void )
{
	m_fDAElem[0][0] = 1.f;	m_fDAElem[0][1] = 0.f;	m_fDAElem[0][2] = 0.f;
	m_fDAElem[1][0] = 0.f;	m_fDAElem[1][1] = 1.f;	m_fDAElem[1][2] = 0.f;
	m_fDAElem[2][0] = 0.f;	m_fDAElem[2][1] = 0.f;	m_fDAElem[2][2] = 1.f;
}


void CNtlNaviMatrix3::MakeDiagonal( float fVal )
{
	m_fDAElem[0][0] = fVal;	m_fDAElem[0][1] = 0.f;	m_fDAElem[0][2] = 0.f;
	m_fDAElem[1][0] = 0.f;	m_fDAElem[1][1] = fVal;	m_fDAElem[1][2] = 0.f;
	m_fDAElem[2][0] = 0.f;	m_fDAElem[2][1] = 0.f;	m_fDAElem[2][2] = fVal;
}


void CNtlNaviMatrix3::MakeDiagonal( float f00, float f11, float f22 )
{
	m_fDAElem[0][0] = f00;	m_fDAElem[0][1] = 0.f;	m_fDAElem[0][2] = 0.f;
	m_fDAElem[1][0] = 0.f;	m_fDAElem[1][1] = f11;	m_fDAElem[1][2] = 0.f;
	m_fDAElem[2][0] = 0.f;	m_fDAElem[2][1] = 0.f;	m_fDAElem[2][2] = f22;
}


void CNtlNaviMatrix3::MakeDiagonal( const CNtlNaviVector3& v3Val )
{
	v3Val.GetXYZ( m_fDAElem[0][0], m_fDAElem[1][1], m_fDAElem[2][2] );

									m_fDAElem[0][1] = 0.f;			m_fDAElem[0][2] = 0.f;
	m_fDAElem[1][0] = 0.f;											m_fDAElem[1][2] = 0.f;
	m_fDAElem[2][0] = 0.f;			m_fDAElem[2][1] = 0.f;
}


void CNtlNaviMatrix3::GetEulerRotXYZ( float& fX, float& fY, float& fZ ) const
{
	//
	//	P' = P * RMX(fX) * RMY(fY) * RMZ(fZ)
	//
	//	|	Cy * Cz						Cy * Sz						-Sy			|
	//	|	Cz * Sx * Sy - Cx * Sz		Sx * Sy * Sz + Cx * Cz		Cy * Sx		|
	//	|	Cx * Cz * Sy + Sx * Sz		Cx * Sy * Sz - Cz * Sx		Cy * Cx		|
	//

	if ( m_fDAElem[0][2] < 1.f )
	{
		if ( m_fDAElem[0][2] > -1.f )
		{
			//	-1 < Sy < 1 <=> 0 < y < NAVI_PI / 2 || NAVI_PI / 2 < y < NAVI_PI <=> Cy != 0
			//	����, Cy�� �����Ⱑ �����ϴ�

			//	(Cy * Sx) / (Cy * Cx)
			fX = atan2f( m_fDAElem[1][2], m_fDAElem[2][2] );

			//	-sinf(y) = R[0][2] <=> sinf(y) = -R[0][2] <=> y = asinf( -R[0][2] )
			fY = asinf( -m_fDAElem[0][2] );

			//	(Cy * Sz) / (Cy * Cz)
			fZ = atan2f( m_fDAElem[0][1], m_fDAElem[0][0] );
		}
		//	�������� ����� ������� �ϱ� ������ -Sy �� -1 ���� ���� �� ����
		//	���⼭�� -Sy�� -1���� ���� ��� -1�� ó���Ѵ�
		else
		{
			fY = NAVI_PI / 2.f;

			//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
			//
			//	|	0					0			-1	|
			//	|	S(x-z)				C(x-z)		0	|
			//	|	C(x-z)				-S(x-z)		0	|
			//
			//	���⼭, x, z�� ������ ���� �ظ� ������.
			//	����, X -> Y -> Z�� ������ ȸ�� ����� �����ǹǷ�
			//	���ǻ� x = 0 ���� ���� z�� ȸ������ �����Ѵ�

			fX = 0.f;
			fZ = -atan2f( m_fDAElem[1][0], m_fDAElem[2][0] );
		}
	}
	//	�������� ����� ������� �ϱ� ������ -Sy �� 1 ���� Ŭ �� ����
	//	���⼭�� -Sy�� 1���� ū ��� 1�� ó���Ѵ�
	else
	{
		fY = -NAVI_PI / 2.f;

		//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
		//
		//	|	0					0			1	|
		//	|	-S(x+z)				C(x+z)		0	|
		//	|	-C(x+z)				-S(x+z)		0	|
		//
		//	���⼭, x, z�� ������ ���� �ظ� ������.
		//	����, X -> Y -> Z�� ������ ȸ�� ����� �����ǹǷ�
		//	���ǻ� x = 0 ���� ���� z�� ȸ������ �����Ѵ�

		fX = 0.f;
		fZ = atan2f( m_fDAElem[1][0], m_fDAElem[2][0] );
	}
}


void CNtlNaviMatrix3::GetEulerRotXZY( float& fX, float& fY, float& fZ ) const
{
	//
	//	������ �� P�� RMX(fX) -> RMZ(fZ) -> RMY(fY)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMX(fX) * RMZ(fZ) * RMY(fY)
	//
	//	|	Cz * Cy						Sz			-Cz * Sy				|
    //	|	Sx * Sy - Cx * Cy * Sz		Cz * Cx		Cy * Sx + Cx * Sy * Sz	|
    //	|	Cx * Sy + Cy * Sx * Sz		-Cz * Sx	Cx * Cy - Sx * Sy * Sz	|
	//

	if ( m_fDAElem[0][1] < 1.f )
	{
		if ( m_fDAElem[0][1] > -1.f )
		{
			//	-1 < Sz < 1 <=> 0 < z < NAVI_PI / 2 || NAVI_PI / 2 < z < NAVI_PI <=> Cz != 0
			//	����, Cz�� �����Ⱑ �����ϴ�

			//	(-Cz * Sx) / (Cz * Cx)
			fX = -atan2f( m_fDAElem[2][1], m_fDAElem[1][1] );

			//	(-Cz * Sy) / (Cz * Cy) = -Tan(y) = (m_fDAElem[0][2]/m_fDAElem[0][0])
			fY = -atan2f( m_fDAElem[0][2], m_fDAElem[0][0] );

			//	sinf(z) = R[0][1]
			fZ = asinf( m_fDAElem[0][1] );
		}
		//	�������� ����� ������� �ϱ� ������ Sz �� -1 ���� ���� �� ����
		//	���⼭�� Sz�� -1���� ���� ��� -1�� ó���Ѵ�
		else
		{
			fZ = -NAVI_PI / 2.f;

			//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
			//
			//	|	0			-1		0		|
			//	|	C(x-y)		0		S(x-y)	|
			//	|	-S(x-y)		0		C(x-y)	|
			//
			//	���⼭, x, y�� ������ ���� �ظ� ������.
			//	����, X -> Z -> Y�� ������ ȸ�� ����� �����ǹǷ�
			//	���ǻ� x = 0 ���� ���� y�� ȸ������ �����Ѵ�

			fX = 0.f;
			fY = -atan2f( m_fDAElem[1][2], m_fDAElem[2][2] );
		}
	}
	//	�������� ����� ������� �ϱ� ������ Sz �� 1 ���� Ŭ �� ����
	//	���⼭�� Sz�� 1���� ū ��� 1�� ó���Ѵ�
	else
	{
		fZ = NAVI_PI / 2.f;

		//	|	Cz * Cy						Sz			-Cz * Sy				|
		//	|	Sx * Sy - Cx * Cy * Sz		Cz * Cx		Cy * Sx + Cx * Sy * Sz	|
		//	|	Cx * Sy + Cy * Sx * Sz		-Cz * Sx	Cx * Cy - Sx * Sy * Sz	|

		//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
		//
		//	|	0			1		0		|
		//	|	-C(x+y)		0		S(x+y)	|
		//	|	S(x+y)		0		C(x+y)	|
		//
		//	���⼭, x, y�� ������ ���� �ظ� ������.
		//	����, X -> Z -> Y�� ������ ȸ�� ����� �����ǹǷ�
		//	���ǻ� x = 0 ���� ���� y�� ȸ������ �����Ѵ�

		fX = 0.f;
		fY = atan2f( m_fDAElem[1][2], m_fDAElem[2][2] );
	}
}


void CNtlNaviMatrix3::GetEulerRotYXZ( float& fX, float& fY, float& fZ ) const
{
	//
	//	������ �� P�� RMY(fY) -> RMX(fX) -> RMZ(fZ)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMY(fY) * RMX(fX) * RMZ(fZ)
	//
	//	|	Cy * Cz - Sx * Sy * Sz		Cz * Sx * Sy + Cy * Sz		-Cx * Sy	|
    //	|	-Cx * Sz					Cx * Cz						Sx			|
    //	|	Cz * Sy + Cy * Sx * Sz		-Cy * Cz * Sx + Sy * Sz		Cx * Cy		|
	//

	if ( m_fDAElem[1][2] < 1.f )
	{
		if ( m_fDAElem[1][2] > -1.f )
		{
			//	-1 < Sx < 1 <=> 0 < x < NAVI_PI / 2 || NAVI_PI / 2 < x < NAVI_PI <=> Cx != 0
			//	����, Cx�� �����Ⱑ �����ϴ�

			fX = asinf( m_fDAElem[1][2] );

			//	(-Cx * Sy) / (Cx * Cy) = -Tan(y) = (m_fDAElem[0][2]/m_fDAElem[2][2])
			fY = -atan2f( m_fDAElem[0][2], m_fDAElem[2][2] );

			//	(-Cx * Sz) / (Cx * Cz) = -Tan(z) = (m_fDAElem[1][0]/m_fDAElem[1][1])
			fZ = -atan2f( m_fDAElem[1][0], m_fDAElem[1][1] );
		}
		//	�������� ����� ������� �ϱ� ������ Sx �� -1 ���� ���� �� ����
		//	���⼭�� Sx�� -1���� ���� ��� -1�� ó���Ѵ�
		else
		{
			fX = -NAVI_PI / 2.f;

			//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
			//
			//	|	C(y-z)		-S(y-z)		0	|
			//	|	0			0			-1	|
			//	|	S(y-z)		C(y-z)		0	|
			//
			//	���⼭, y, z�� ������ ���� �ظ� ������.
			//	����, Y -> X -> Z�� ������ ȸ�� ����� �����ǹǷ�
			//	���ǻ� y = 0 ���� ���� z�� ȸ������ �����Ѵ�

			fY = 0.f;
			fZ = -atan2f( m_fDAElem[2][0], m_fDAElem[0][0] );
		}
	}
	//	�������� ����� ������� �ϱ� ������ Sx �� 1 ���� Ŭ �� ����
	//	���⼭�� Sx�� 1���� ū ��� 1�� ó���Ѵ�
	else
	{
		fX = NAVI_PI / 2.f;

		//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
		//
		//	|	C(y+z)		S(y+z)		0	|
		//	|	0			0			1	|
		//	|	S(y+z)		-C(y+z)		0	|
		//
		//	���⼭, y, z�� ������ ���� �ظ� ������.
		//	����, Y -> X -> Z�� ������ ȸ�� ����� �����ǹǷ�
		//	���ǻ� y = 0 ���� ���� z�� ȸ������ �����Ѵ�

		fY = 0.f;
		fZ = atan2f( m_fDAElem[2][0], m_fDAElem[0][0] );
	}
}


void CNtlNaviMatrix3::GetEulerRotYZX( float& fX, float& fY, float& fZ ) const
{
	//
	//	������ �� P�� RMY(fY) -> RMZ(fZ) -> RMX(fX)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMY(fY) * RMZ(fZ) * RMX(fX)
	//
	//	|	Cy * Cz		Sx * Sy + Cx * Cy * Sz		-Cx * Sy + Cy * Sx * Sz		|
    //	|	-Sz			Cx * Cz						Cz * Sx						|
    //	|	Cz * Sy		-Cy * Sx + Cx * Sy * Sz		Cx * Cy + Sx * Sy * Sz		|
	//

	if ( m_fDAElem[1][0] < 1.f )
	{
		if ( m_fDAElem[1][0] > -1.f )
		{
			//	-1 < -Sz < 1 <=> 0 < z < NAVI_PI / 2 || NAVI_PI / 2 < z < NAVI_PI <=> Cz != 0
			//	����, Cz�� �����Ⱑ �����ϴ�

			//	(Cz * Sx) / (Cz * Cx)
			fX = -atan2f( m_fDAElem[1][2], m_fDAElem[1][1] );

			//	(Cz * Sy) / (Cz * Cy)
			fY = atan2f( m_fDAElem[2][0], m_fDAElem[0][0] );

			//	-sinf(z) = m_fDAElem[1][0]
			fZ = -asinf( m_fDAElem[1][0] );
		}
		//	�������� ����� ������� �ϱ� ������ -Sz �� -1 ���� ���� �� ����
		//	���⼭�� -Sz�� -1���� ���� ��� -1�� ó���Ѵ�
		else
		{
			fZ = NAVI_PI / 2.f;

			//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
			//
			//	|	0		C(x-y)		S(x-y)	|
			//	|	-1		0			0		|
			//	|	0		-S(x-y)		C(x-y)	|
			//
			//	���⼭, x, y�� ������ ���� �ظ� ������.
			//	����, Y -> Z -> X�� ������ ȸ�� ����� �����ǹǷ�
			//	���ǻ� y = 0 ���� ���� x�� ȸ������ �����Ѵ�

			fY = 0.f;
			fX = atan2f( m_fDAElem[0][2], m_fDAElem[2][2] );
		}
	}
	//	�������� ����� ������� �ϱ� ������ -Sz �� 1 ���� Ŭ �� ����
	//	���⼭�� -Sz�� 1���� ū ��� 1�� ó���Ѵ�
	else
	{
		fZ = -NAVI_PI / 2.f;

		//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
		//
		//	|	0		-C(x+y)		-S(x+y)	|
		//	|	1		0			0		|
		//	|	0		-S(x+y)		C(x+y)	|
		//
		//	���⼭, x, y�� ������ ���� �ظ� ������.
		//	����, Y -> Z -> X�� ������ ȸ�� ����� �����ǹǷ�
		//	���ǻ� y = 0 ���� ���� x�� ȸ������ �����Ѵ�

		fY = 0.f;
		fX = atan2f( m_fDAElem[2][1], m_fDAElem[0][1] );
	}
}


void CNtlNaviMatrix3::GetEulerRotZXY( float& fX, float& fY, float& fZ ) const
{
	//
	//	������ �� P�� RMZ(fZ) -> RMX(fX) -> RMY(fY)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMZ(fZ) * RMX(fX) * RMY(fY)
	//
    //	|	Cy * Cz + Sx * Sy * Sz		Cx * Sz		-Cz * Sy + Cy * Sx * Sz		|
    //	|	Cz * Sx * Sy - Cy * Sz		Cx * Cz		Cy * Cz * Sx + Sy * Sz		|
    //	|	Cx * Sy						-Sx			Cx * Cy						|
	//

	if ( m_fDAElem[2][1] < 1.f )
	{
		if ( m_fDAElem[2][1] > -1.f )
		{
			//	-1 < -Sx < 1 <=> 0 < x < NAVI_PI / 2 || NAVI_PI / 2 < x < NAVI_PI <=> Cx != 0
			//	����, Cx�� �����Ⱑ �����ϴ�

			//	-sinf(x) = m_fDAElem[2][1]
			fX = -asinf( m_fDAElem[2][1] );

			//	(Cx * Sy) / (Cx * Cy)
			fY = atan2f( m_fDAElem[2][0], m_fDAElem[2][2] );

			//	(Cx * Sz) / (Cx * Cz)
			fZ = atan2f( m_fDAElem[0][1], m_fDAElem[1][1] );
		}
		//	�������� ����� ������� �ϱ� ������ -Sx �� -1 ���� ���� �� ����
		//	���⼭�� -Sx�� -1���� ���� ��� -1�� ó���Ѵ�
		else
		{
			fX = NAVI_PI / 2.f;

			//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
			//
			//	|	C(y-z)		0		-S(y-z)	|
			//	|	S(y-z)		0		C(y-z)	|
			//	|	0			-1		0		|
			//
			//	���⼭, y, z�� ������ ���� �ظ� ������.
			//	����, Z -> X -> Y�� ������ ȸ�� ����� �����ǹǷ�
			//	���ǻ� z = 0 ���� ���� y�� ȸ������ �����Ѵ�

			fZ = 0.f;
			fY = atan2f( m_fDAElem[1][0], m_fDAElem[0][0] );
		}
	}
	//	�������� ����� ������� �ϱ� ������ -Sx �� 1 ���� Ŭ �� ����
	//	���⼭�� -Sx�� 1���� ū ��� 1�� ó���Ѵ�
	else
	{
		fX = -NAVI_PI / 2.f;

		//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
		//
		//	|	C(y+z)		0		-S(y+z)	|
		//	|	-S(y+z)		0		-C(y+z)	|
		//	|	0			1		0		|
		//
		//	���⼭, y, z�� ������ ���� �ظ� ������.
		//	����, Z -> X -> Y�� ������ ȸ�� ����� �����ǹǷ�
		//	���ǻ� z = 0 ���� ���� y�� ȸ������ �����Ѵ�

		fZ = 0.f;
		fY = atan2f( m_fDAElem[0][2], m_fDAElem[1][2] );
	}
}


void CNtlNaviMatrix3::GetEulerRotZYX( float& fX, float& fY, float& fZ ) const
{
	//
	//	������ �� P�� RMZ(fZ) -> RMY(fY) -> RMX(fX)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMZ(fZ) * RMY(fY) * RMX(fX)
	//
	//	|	Cy * Cz		Cz * Sx * Sy + Cx * Sz		-Cx * Cz * Sy + Sx * Sz		|
    //	|	-Cy * Sz	Cx * Cz - Sx * Sy * Sz		Cz * Sx + Cx * Sy * Sz		|
    //	|	Sy			-Cy * Sx					Cy * Cx						|
	//

	if ( m_fDAElem[2][0] < 1.f )
	{
		if ( m_fDAElem[2][0] > -1.f )
		{
			//	-1 < Sy < 1 <=> 0 < y < NAVI_PI / 2 || NAVI_PI / 2 < y < NAVI_PI <=> Cy != 0
			//	����, Cy�� �����Ⱑ �����ϴ�

			//	(-Cy * Sx) / (Cy * Cx) = -Tan(x) = (m_fDAElem[2][1]/m_fDAElem[2][2])
			fX = -atan2f( m_fDAElem[2][1], m_fDAElem[2][2] );

			fY = asinf( m_fDAElem[2][0] );

			//	(-Cy * Sz) / (Cy * Cz) = -Tan(z) = (m_fDAElem[1][0]/m_fDAElem[0][0])
			fZ = atan2f( m_fDAElem[1][0], m_fDAElem[0][0] );
		}
		//	�������� ����� ������� �ϱ� ������ Sy �� -1 ���� ���� �� ����
		//	���⼭�� Sy�� -1���� ���� ��� -1�� ó���Ѵ�
		else
		{
			fY = -NAVI_PI / 2.f;

			//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
			//
			//	|	0		S(z-x)		C(z-x)	|
			//	|	0		C(z-x)		-S(z-x)	|
			//	|	-1		0			0		|
			//
			//	���⼭, x, z�� ������ ���� �ظ� ������.
			//	����, Z -> Y -> X�� ������ ȸ�� ����� �����ǹǷ�
			//	���ǻ� z = 0 ���� ���� x�� ȸ������ �����Ѵ�

			fZ = 0.f;
			fX = -atan2f( m_fDAElem[0][1], m_fDAElem[1][1] );
		}
	}
	//	�������� ����� ������� �ϱ� ������ Sy �� 1 ���� Ŭ �� ����
	//	���⼭�� Sy�� 1���� ū ��� 1�� ó���Ѵ�
	else
	{
		fY = NAVI_PI / 2.f;

		//	ȸ�� ��Ŀ� ���� ������ �����ϸ� �Ʒ��� ����.
		//
		//	|	0		S(z+x)		-C(z+x)	|
		//	|	0		C(z+x)		S(z+x)	|
		//	|	-1		0			0		|
		//
		//	���⼭, x, z�� ������ ���� �ظ� ������.
		//	����, Z -> Y -> X�� ������ ȸ�� ����� �����ǹǷ�
		//	���ǻ� z = 0 ���� ���� x�� ȸ������ �����Ѵ�

		fZ = 0.f;
		fX = atan2f( m_fDAElem[0][1], m_fDAElem[1][1] );
	}
}


void CNtlNaviMatrix3::MakeEulerRotX( float fVal )
{
	//
	//	C = cosf
	//	S = sinf
	//
	//	X���� �������� �־��� ��(fVal) ��ŭ ȸ���ϴ� ���
	//
	//	|	1	0	0	|
	//	|	0	C	S	|
	//	|	0	-S	C	|
	//

	float fC = cosf( fVal );
	float fS = sinf( fVal );

	m_fDAElem[0][0] = 1.f;	m_fDAElem[0][1] = 0.f;	m_fDAElem[0][2] = 0.f;
	m_fDAElem[1][0] = 0.f;	m_fDAElem[1][1] = fC;	m_fDAElem[1][2] = fS;
	m_fDAElem[2][0] = 0.f;	m_fDAElem[2][1] = -fS;	m_fDAElem[2][2] = fC;
}


void CNtlNaviMatrix3::MakeEulerRotY( float fVal )
{
	//
	//	C = cosf
	//	S = sinf
	//
	//	Y���� �������� �־��� ��(fVal) ��ŭ ȸ���ϴ� ���
	//
	//	|	C	0	-S	|
	//	|	0	1	0	|
	//	|	S	0	C	|
	//

	float fC = cosf( fVal );
	float fS = sinf( fVal );
	
	m_fDAElem[0][0] = fC;	m_fDAElem[0][1] = 0.f;	m_fDAElem[0][2] = -fS;
	m_fDAElem[1][0] = 0.f;	m_fDAElem[1][1] = 1.f;	m_fDAElem[1][2] = 0.f;
	m_fDAElem[2][0] = fS;	m_fDAElem[2][1] = 0.f;	m_fDAElem[2][2] = fC;
}


void CNtlNaviMatrix3::MakeEulerRotZ( float fVal )
{
	//
	//	C = cosf
	//	S = sinf
	//
	//	Z���� �������� �־��� ��(fVal) ��ŭ ȸ���ϴ� ���
	//
	//	|	C	S	0	|
	//	|	-S	C	0	|
	//	|	0	0	1	|
	//

	float fC = cosf( fVal );
	float fS = sinf( fVal );

	m_fDAElem[0][0] = fC;	m_fDAElem[0][1] = fS;	m_fDAElem[0][2] = 0.f;
	m_fDAElem[1][0] = -fS;	m_fDAElem[1][1] = fC;	m_fDAElem[1][2] = 0.f;
	m_fDAElem[2][0] = 0.f;	m_fDAElem[2][1] = 0.f;	m_fDAElem[2][2] = 1.f;
}


void CNtlNaviMatrix3::MakeEulerRotXYZ( float fX, float fY, float fZ )
{
	//
	//	������ �� P�� RMX(fX) -> RMY(fY) -> RMZ(fZ)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMX(fX) * RMY(fY) * RMZ(fZ)
	//
	//	|	Cy * Cz						Cy * Sz						-Sy			|
	//	|	Cz * Sx * Sy - Cx * Sz		Sx * Sy * Sz + Cx * Cz		Cy * Sx		|
	//	|	Cx * Cz * Sy + Sx * Sz		Cx * Sy * Sz - Cz * Sx		Cx * Cy		|
	//

	float fCx = cosf( fX );
	float fSx = sinf( fX );
	float fCy = cosf( fY );
	float fSy = sinf( fY );
	float fCz = cosf( fZ );
	float fSz = sinf( fZ );

	m_fDAElem[0][0] = fCy * fCz;
	m_fDAElem[0][1] = fCy * fSz;
	m_fDAElem[0][2] = -fSy;

	m_fDAElem[1][0] = fCz * fSx * fSy - fCx * fSz;
	m_fDAElem[1][1] = fSx * fSy * fSz + fCx * fCz;
	m_fDAElem[1][2] = fCy * fSx;

	m_fDAElem[2][0] = fCx * fCz * fSy + fSx * fSz;
	m_fDAElem[2][1] = fCx * fSy * fSz - fCz * fSx;
	m_fDAElem[2][2] = fCx * fCy;
}


void CNtlNaviMatrix3::MakeEulerRotXZY( float fX, float fY, float fZ )
{
	//
	//	������ �� P�� RMX(fX) -> RMZ(fZ) -> RMY(fY)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMX(fX) * RMZ(fZ) * RMY(fY)
	//
	//	|	Cy * Cz						Sz			-Cz * Sy				|
    //	|	Sx * Sy - Cx * Cy * Sz		Cx * Cz		Cy * Sx + Cx * Sy * Sz	|
    //	|	Cx * Sy + Cy * Sx * Sz		-Cz * Sx	Cx * Cy - Sx * Sy * Sz	|
	//

	float fCx = cosf( fX );
	float fSx = sinf( fX );
	float fCy = cosf( fY );
	float fSy = sinf( fY );
	float fCz = cosf( fZ );
	float fSz = sinf( fZ );

	m_fDAElem[0][0] = fCy * fCz;
	m_fDAElem[0][1] = fSz;
	m_fDAElem[0][2] = -fCz * fSy;

	m_fDAElem[1][0] = fSx * fSy - fCx * fCy * fSz;
	m_fDAElem[1][1] = fCx * fCz;
	m_fDAElem[1][2] = fCy * fSx + fCx * fSy * fSz;

	m_fDAElem[2][0] = fCx * fSy + fCy * fSx * fSz;
	m_fDAElem[2][1] = -fCz * fSx;
	m_fDAElem[2][2] = fCx * fCy - fSx * fSy * fSz;
}


void CNtlNaviMatrix3::MakeEulerRotYXZ( float fX, float fY, float fZ )
{
	//
	//	������ �� P�� RMY(fY) -> RMX(fX) -> RMZ(fZ)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMY(fY) * RMX(fX) * RMZ(fZ)
	//
	//	|	Cy * Cz - Sx * Sy * Sz		Cz * Sx * Sy + Cy * Sz		-Cx * Sy	|
    //	|	-Cx * Sz					Cx * Cz						Sx			|
    //	|	Cz * Sy + Cy * Sx * Sz		-Cy * Cz * Sx + Sy * Sz		Cx * Cy		|
	//

	float fCx = cosf( fX );
	float fSx = sinf( fX );
	float fCy = cosf( fY );
	float fSy = sinf( fY );
	float fCz = cosf( fZ );
	float fSz = sinf( fZ );

	m_fDAElem[0][0] = fCy * fCz - fSx * fSy * fSz;
	m_fDAElem[0][1] = fCz * fSx * fSy + fCy * fSz;
	m_fDAElem[0][2] = -fCx * fSy;

	m_fDAElem[1][0] = -fCx * fSz;
	m_fDAElem[1][1] = fCx * fCz;
	m_fDAElem[1][2] = fSx;

	m_fDAElem[2][0] = fCz * fSy + fCy * fSx * fSz;
	m_fDAElem[2][1] = -fCy * fCz * fSx + fSy * fSz;
	m_fDAElem[2][2] = fCx * fCy;
}


void CNtlNaviMatrix3::MakeEulerRotYZX( float fX, float fY, float fZ )
{
	//
	//	������ �� P�� RMY(fY) -> RMZ(fZ) -> RMX(fX)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMY(fY) * RMZ(fZ) * RMX(fX)
	//
	//	|	Cy * Cz		Sx * Sy + Cx * Cy * Sz		-Cx * Sy + Cy * Sx * Sz		|
    //	|	-Sz			Cx * Cz						Cz * Sx						|
    //	|	Cz * Sy		-Cy * Sx + Cx * Sy * Sz		Cx * Cy + Sx * Sy * Sz		|
	//

	float fCx = cosf( fX );
	float fSx = sinf( fX );
	float fCy = cosf( fY );
	float fSy = sinf( fY );
	float fCz = cosf( fZ );
	float fSz = sinf( fZ );

	m_fDAElem[0][0] = fCy * fCz;
	m_fDAElem[0][1] = fSx * fSy + fCx * fCy * fSz;
	m_fDAElem[0][2] = -fCx * fSy + fCy * fSx * fSz;

	m_fDAElem[1][0] = -fSz;
	m_fDAElem[1][1] = fCx * fCz;
	m_fDAElem[1][2] = fCz * fSx;

	m_fDAElem[2][0] = fCz * fSy;
	m_fDAElem[2][1] = -fCy * fSx + fCx * fSy * fSz;
	m_fDAElem[2][2] = fCx * fCy + fSx * fSy * fSz;
}


void CNtlNaviMatrix3::MakeEulerRotZXY( float fX, float fY, float fZ )
{
	//
	//	������ �� P�� RMZ(fZ) -> RMX(fX) -> RMY(fY)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMZ(fZ) * RMX(fX) * RMY(fY)
	//
    //	|	Cy * Cz + Sx * Sy * Sz		Cx * Sz		-Cz * Sy + Cy * Sx * Sz		|
    //	|	Cz * Sx * Sy - Cy * Sz		Cx * Cz		Cy * Cz * Sx + Sy * Sz		|
    //	|	Cx * Sy						-Sx			Cx * Cy						|
	//

	float fCx = cosf( fX );
	float fSx = sinf( fX );
	float fCy = cosf( fY );
	float fSy = sinf( fY );
	float fCz = cosf( fZ );
	float fSz = sinf( fZ );

	m_fDAElem[0][0] = fCy * fCz + fSx * fSy * fSz;
	m_fDAElem[0][1] = fCx * fSz;
	m_fDAElem[0][2] = -fCz * fSy + fCy * fSx * fSz;

	m_fDAElem[1][0] = fCz * fSx * fSy - fCy * fSz;
	m_fDAElem[1][1] = fCx * fCz;
	m_fDAElem[1][2] = fCy * fCz * fSx + fSy * fSz;

	m_fDAElem[2][0] = fCx * fSy;
	m_fDAElem[2][1] = -fSx;
	m_fDAElem[2][2] = fCx * fCy;
}


void CNtlNaviMatrix3::MakeEulerRotZYX( float fX, float fY, float fZ )
{
	//
	//	������ �� P�� RMZ(fZ) -> RMY(fY) -> RMX(fX)�� ���� ȸ�� ��Ű�� ���
	//
	//	P' = P * RMZ(fZ) * RMY(fY) * RMX(fX)
	//
	//	|	Cy * Cz		Cz * Sx * Sy + Cx * Sz		-Cx * Cz * Sy + Sx * Sz		|
    //	|	-Cy * Sz	Cx * Cz - Sx * Sy * Sz		Cz * Sx + Cx * Sy * Sz		|
    //	|	Sy			-Cy * Sx					Cx * Cy						|
	//

	float fCx = cosf( fX );
	float fSx = sinf( fX );
	float fCy = cosf( fY );
	float fSy = sinf( fY );
	float fCz = cosf( fZ );
	float fSz = sinf( fZ );

	m_fDAElem[0][0] = fCy * fCz;
	m_fDAElem[0][1] = fCz * fSx * fSy + fCx * fSz;
	m_fDAElem[0][2] = -fCx * fCz * fSy + fSx * fSz;

	m_fDAElem[1][0] = -fCy * fSz;
	m_fDAElem[1][1] = fCx * fCz - fSx * fSy * fSz;
	m_fDAElem[1][2] = fCz * fSx + fCx * fSy * fSz;

	m_fDAElem[2][0] = fSy;
	m_fDAElem[2][1] = -fCy * fSx;
	m_fDAElem[2][2] = fCx * fCy;
}

void CNtlNaviMatrix3::GetAxisAngleFromRotMat( CNtlNaviVector3& v3Axis, float& fAngle ) const
{
	//
	//	������ ȸ���� A ( Ax, Ay, Az ),
	//	���� ��� E,
	//	CR = |	0		Az		-Ay	|	�̶� ������ 
	//		 |	-Az		0		Ax	|
	//		 |	Ay		-Ax		0	|
	//	������ �� A(v3Axis) �� �������� �־��� ��(fAngle) ��ŭ ȸ����Ű�� ��� R��
	//	�Ʒ��� ���� �������� ������ �� �ִ�
	//
	//	R = E + sinf(t) * CR	+ (1 - cosf(t)) * CR^2	-- (��)
	//
	//	  = |	C + Ax * Ax * ( 1 - C )			Ax * Ay * ( 1 - C ) + Az * S		Ax * Az * ( 1 - C ) - Ay * S	|
	//		|	Ax * Ay * ( 1 - C ) - Az * S	C + Ay * Ay * ( 1 - C )				Ay * Az * ( 1 - C ) + Ax * S	|
	//		|	Ax * Az * ( 1 - C ) + Ay * S	Ay * Az * ( 1 - C ) - Ax * S		C + Az * Az * ( 1 - C )			|
	//
	//	���⼭,
	//	(1) cosf(t) = (trace(R) - 1) / 2 �� �̿��Ͽ� ȸ������ ����Ѵ�
	//	(2) R - R^T = 2 * sinf(t) * CR �� �̿��Ͽ� ȸ������ ����ϸ� �ǳ�
	//		t = 0, NAVI_PI �� ��� sinf(t)�� �纯�� ���� ���� �����Ƿ� �ٸ� ������ �̿��ؾ� �Ѵ�
	//		���⼭, t = 0 �̸� ȸ���� ������ ������ ���� ȸ�� ������ ���ϸ� �ǰ�
	//		t = NAVI_PI �� ��� (��)���� �̿��Ͽ� ȸ������ ����Ѵ�
	//

	float fTrace = m_fDAElem[0][0] + m_fDAElem[1][1] + m_fDAElem[2][2];
	fAngle = acosf( 0.5f * (fTrace - 1) );

	if ( fAngle > 0.f )
	{
		if ( fAngle < NAVI_PI )
		{
			//	(2) ���� �̿��Ͽ� ȸ������ ����Ѵ�
			v3Axis.SetElem( m_fDAElem[1][2] - m_fDAElem[2][1],
							m_fDAElem[2][0] - m_fDAElem[0][2],
							m_fDAElem[0][1] - m_fDAElem[1][0] );
			v3Axis.MakeNormalize();
		}
		else
		{
			//	(��) ���� Ǯ�� �밢 ������ �������� �̿��Ͽ� ȸ������ ����Ѵ�
			//	R = |	1 - 2 ( Ay^2 + Az^2 )	2 * Ax * Ay				2 * Ax * Az				|
			//		|	2 * Ax * Ay				1 - 2 ( Ax^2 + Az^2 )	2 * Ay * Az				|
			//		|	2 * Ax * Az				2 * Ay * Az				1 - 2 ( Ax^2 + Ay^2 )	|

			if ( m_fDAElem[0][0] >= m_fDAElem[1][1] )
			{
				if ( m_fDAElem[0][0] >= m_fDAElem[2][2] )
				{
					//	m_fDAElem[0][0] �� �밢 ������ �ִ밪�� ���´�
					float fAx = 0.5f * sqrtf( m_fDAElem[0][0] - m_fDAElem[1][1] - m_fDAElem[2][2] + 1.f );

					if ( fAx <= NAVI_ZERO_THRESHOLD )
					{
						v3Axis.MakeInvalid();
					}
					else
					{
						v3Axis[0] = fAx;

						fAx = 0.5f * (1.f / fAx);
						v3Axis[1] = m_fDAElem[0][1] * fAx;
						v3Axis[2] = m_fDAElem[0][2] * fAx;
					}
				}
				else
				{
					//	m_fDAElem[2][2] �� �밢 ������ �ִ밪�� ���´�
					float fAz = 0.5f * sqrtf( m_fDAElem[2][2] - m_fDAElem[0][0] - m_fDAElem[1][1] + 1.f );

					if ( fAz <= NAVI_ZERO_THRESHOLD )
					{
						v3Axis.MakeInvalid();
					}
					else
					{
						v3Axis[2] = fAz;

						fAz = 0.5f * (1.f / fAz);
						v3Axis[0] = m_fDAElem[0][2] * fAz;
						v3Axis[1] = m_fDAElem[1][2] * fAz;
					}
				}
			}
			else
			{
				if ( m_fDAElem[1][1] >= m_fDAElem[2][2] )
				{
					//	m_fDAElem[1][1] �� �밢 ������ �ִ밪�� ���´�
					float fAy = 0.5f * sqrtf( m_fDAElem[1][1] - m_fDAElem[0][0] - m_fDAElem[2][2] + 1.f );

					if ( fAy <= NAVI_ZERO_THRESHOLD )
					{
						v3Axis.MakeInvalid();
					}
					else
					{
						v3Axis[1] = fAy;

						fAy = 0.5f * (1.f / fAy);
						v3Axis[0] = m_fDAElem[0][1] * fAy;
						v3Axis[2] = m_fDAElem[1][2] * fAy;
					}
				}
				else
				{
					//	m_fDAElem[2][2] �� �밢 ������ �ִ밪�� ���´�
					float fAz = 0.5f * sqrtf( m_fDAElem[2][2] - m_fDAElem[0][0] - m_fDAElem[1][1] + 1.f );

					if ( fAz <= NAVI_ZERO_THRESHOLD )
					{
						v3Axis.MakeInvalid();
					}
					else
					{
						v3Axis[2] = fAz;

						fAz = 0.5f * (1.f / fAz);
						v3Axis[0] = m_fDAElem[0][2] * fAz;
						v3Axis[1] = m_fDAElem[1][2] * fAz;
					}
				}
			}
		}
	}
	else
	{
		//	ȸ���� ���� ���
		//	ȸ������ ���Ƿ� X������ ���Ѵ�
		v3Axis.SetElem( 1.f, 0.f, 0.f );
	}
}


void CNtlNaviMatrix3::MakeRotMatFromAxisAngle( const CNtlNaviVector3& v3Axis, float fAngle )
{
	//
	//	C = cosf
	//	S = sinf
	//	������ ȸ���� = A ( Ax, Ay, Az )
	//
	//	������ �� A(v3Axis) �� �������� �־��� ��(fAngle) ��ŭ ȸ����Ű�� ���
	//
	//	|	C + Ax * Ax * ( 1 - C )			Ax * Ay * ( 1 - C ) + Az * S		Ax * Az * ( 1 - C ) - Ay * S	|
	//  |	Ax * Ay * ( 1 - C ) - Az * S	C + Ay * Ay * ( 1 - C )				Ay * Az * ( 1 - C ) + Ax * S	|
	//  |	Ax * Az * ( 1 - C ) + Ay * S	Ay * Az * ( 1 - C ) - Ax * S		C + Az * Az * ( 1 - C )			|
	//

	float fC = cosf( fAngle );
	float fS = sinf( fAngle );
	float fOMC = 1 - fC;

	float fX, fY, fZ;
	v3Axis.GetXYZ( fX, fY, fZ );

	float fXY = fX * fY;
	float fXZ = fX * fZ;
	float fYZ = fY * fZ;

	m_fDAElem[0][0] = fC + fX * fX * fOMC;
	m_fDAElem[0][1] = fXY * fOMC + fZ * fS;
	m_fDAElem[0][2] = fXZ * fOMC - fY * fS;

	m_fDAElem[1][0] = fXY * fOMC - fZ * fS;
	m_fDAElem[1][1] = fC + fY * fY * fOMC;
	m_fDAElem[1][2] = fYZ * fOMC + fX * fS;

	m_fDAElem[2][0] = fXZ * fOMC + fY * fS;
	m_fDAElem[2][1] = fYZ * fOMC - fX * fS;
	m_fDAElem[2][2] = fC + fZ * fZ * fOMC;
}


float CNtlNaviMatrix3::GetDet( void ) const
{
	return
		m_fDAElem[0][0] * ( m_fDAElem[1][1] * m_fDAElem[2][2] - m_fDAElem[1][2] * m_fDAElem[2][1] ) -
		m_fDAElem[0][1] * ( m_fDAElem[1][0] * m_fDAElem[2][2] - m_fDAElem[1][2] * m_fDAElem[2][0] ) +
		m_fDAElem[0][2] * ( m_fDAElem[1][0] * m_fDAElem[2][1] - m_fDAElem[1][1] * m_fDAElem[2][0] );
}


bool CNtlNaviMatrix3::CanInverse( void ) const
{
	return fabsf( GetDet() ) > NAVI_ZERO_THRESHOLD;
}


float CNtlNaviMatrix3::GetInverse( CNtlNaviMatrix3& m3Val ) const
{
	float fDet = GetDet();

	if ( fabsf( fDet ) <= NAVI_ZERO_THRESHOLD )
	{
		m3Val.MakeInvalid();
		return fDet;
	}

	float fIDet = 1.f / fDet;

	m3Val.m_fDAElem[0][0] =  fIDet * ( m_fDAElem[1][1] * m_fDAElem[2][2] - m_fDAElem[1][2] * m_fDAElem[2][1] );
	m3Val.m_fDAElem[0][1] = -fIDet * ( m_fDAElem[0][1] * m_fDAElem[2][2] - m_fDAElem[0][2] * m_fDAElem[2][1] );
	m3Val.m_fDAElem[0][2] =  fIDet * ( m_fDAElem[0][1] * m_fDAElem[1][2] - m_fDAElem[0][2] * m_fDAElem[1][1] );

	m3Val.m_fDAElem[1][0] = -fIDet * ( m_fDAElem[1][0] * m_fDAElem[2][2] - m_fDAElem[1][2] * m_fDAElem[2][0] );
	m3Val.m_fDAElem[1][1] =  fIDet * ( m_fDAElem[0][0] * m_fDAElem[2][2] - m_fDAElem[0][2] * m_fDAElem[2][0] );
	m3Val.m_fDAElem[1][2] = -fIDet * ( m_fDAElem[0][0] * m_fDAElem[1][2] - m_fDAElem[0][2] * m_fDAElem[1][0] );

	m3Val.m_fDAElem[2][0] =  fIDet * ( m_fDAElem[1][0] * m_fDAElem[2][1] - m_fDAElem[1][1] * m_fDAElem[2][0] );
	m3Val.m_fDAElem[2][1] = -fIDet * ( m_fDAElem[0][0] * m_fDAElem[2][1] - m_fDAElem[0][1] * m_fDAElem[2][0] );
	m3Val.m_fDAElem[2][2] =  fIDet * ( m_fDAElem[0][0] * m_fDAElem[1][1] - m_fDAElem[0][1] * m_fDAElem[1][0] );

	return fDet;
}


float CNtlNaviMatrix3::MakeInverse( void )
{
	return GetInverse( *this );
}


CNtlNaviMatrix3 CNtlNaviMatrix3::GetTranspose( void ) const
{
	CNtlNaviMatrix3 matTranspose;

	for ( int i = 0; i < 3; ++i )
	{
		for ( int j = 0; j < 3; ++j )
		{
			matTranspose.m_fDAElem[j][i] = m_fDAElem[i][j];
		}
	}

	return matTranspose;
}


void CNtlNaviMatrix3::MakeTranspose( void )
{
	float fTemp;

	int i, j;
	for ( i = 0; i < 2; ++i )
	{
		for ( j = i + 1; j < 3; ++j )
		{
			fTemp = m_fDAElem[i][j];
			m_fDAElem[i][j] = m_fDAElem[j][i];
			m_fDAElem[j][i] = fTemp;
		}
	}
}


float CNtlNaviMatrix3::GetTrace( void ) const
{
	return m_fDAElem[0][0] + m_fDAElem[1][1] + m_fDAElem[2][2];
}


CNtlNaviMatrix3& CNtlNaviMatrix3::operator = ( const CNtlNaviMatrix3& m3Val )
{
	memcpy( m_fSAElem, m3Val.m_fSAElem, sizeof(float)*9 );

	return *this;
}


float* CNtlNaviMatrix3::operator [] ( int nIdx )
{
	return m_fDAElem[nIdx];
}


const float* CNtlNaviMatrix3::operator [] ( int nIdx ) const
{
	return m_fDAElem[nIdx];
}


float& CNtlNaviMatrix3::operator () ( int nRow, int nCol )
{
	return m_fDAElem[nRow][nCol];
}


const float& CNtlNaviMatrix3::operator () ( int nRow, int nCol ) const
{
	return m_fDAElem[nRow][nCol];
}


bool CNtlNaviMatrix3::operator == ( const CNtlNaviMatrix3& m3Val ) const
{
	return CompareArrays( m3Val ) == 0;
}


bool CNtlNaviMatrix3::operator != ( const CNtlNaviMatrix3& m3Val ) const
{
	return CompareArrays( m3Val ) != 0;
}


CNtlNaviMatrix3 CNtlNaviMatrix3::operator - ( void ) const
{
	return CNtlNaviMatrix3(
		-m_fDAElem[0][0], -m_fDAElem[0][1], -m_fDAElem[0][2],
		-m_fDAElem[1][0], -m_fDAElem[1][1], -m_fDAElem[1][2],
		-m_fDAElem[2][0], -m_fDAElem[2][1], -m_fDAElem[2][2] );
}


CNtlNaviMatrix3 CNtlNaviMatrix3::operator * ( float fVal ) const
{
	return CNtlNaviMatrix3(
		m_fDAElem[0][0] * fVal, m_fDAElem[0][1] * fVal, m_fDAElem[0][2] * fVal,
		m_fDAElem[1][0] * fVal, m_fDAElem[1][1] * fVal, m_fDAElem[1][2] * fVal,
		m_fDAElem[2][0] * fVal, m_fDAElem[2][1] * fVal, m_fDAElem[2][2] * fVal );
}


CNtlNaviMatrix3 CNtlNaviMatrix3::operator / ( float fVal ) const
{
	if ( fabsf( fVal ) <= NAVI_ZERO_THRESHOLD )
	{
		return CNtlNaviMatrix3(
			NAVI_FLT_MAX, NAVI_FLT_MAX, NAVI_FLT_MAX,
			NAVI_FLT_MAX, NAVI_FLT_MAX, NAVI_FLT_MAX,
			NAVI_FLT_MAX, NAVI_FLT_MAX, NAVI_FLT_MAX );
	}

	fVal = 1.f / fVal;

	return CNtlNaviMatrix3(
		m_fDAElem[0][0] * fVal, m_fDAElem[0][1] * fVal, m_fDAElem[0][2] * fVal,
		m_fDAElem[1][0] * fVal, m_fDAElem[1][1] * fVal, m_fDAElem[1][2] * fVal,
		m_fDAElem[2][0] * fVal, m_fDAElem[2][1] * fVal, m_fDAElem[2][2] * fVal );
}


CNtlNaviMatrix3 CNtlNaviMatrix3::operator + ( const CNtlNaviMatrix3& m3Val ) const
{
	return CNtlNaviMatrix3(
		m_fDAElem[0][0] + m3Val.m_fDAElem[0][0], m_fDAElem[0][1] + m3Val.m_fDAElem[0][1], m_fDAElem[0][2] + m3Val.m_fDAElem[0][2],
		m_fDAElem[1][0] + m3Val.m_fDAElem[1][0], m_fDAElem[1][1] + m3Val.m_fDAElem[1][1], m_fDAElem[1][2] + m3Val.m_fDAElem[1][2],
		m_fDAElem[2][0] + m3Val.m_fDAElem[2][0], m_fDAElem[2][1] + m3Val.m_fDAElem[2][1], m_fDAElem[2][2] + m3Val.m_fDAElem[2][2] );
}


CNtlNaviMatrix3 CNtlNaviMatrix3::operator - ( const CNtlNaviMatrix3& m3Val ) const
{
	return CNtlNaviMatrix3(
		m_fDAElem[0][0] - m3Val.m_fDAElem[0][0], m_fDAElem[0][1] - m3Val.m_fDAElem[0][1], m_fDAElem[0][2] - m3Val.m_fDAElem[0][2],
		m_fDAElem[1][0] - m3Val.m_fDAElem[1][0], m_fDAElem[1][1] - m3Val.m_fDAElem[1][1], m_fDAElem[1][2] - m3Val.m_fDAElem[1][2],
		m_fDAElem[2][0] - m3Val.m_fDAElem[2][0], m_fDAElem[2][1] - m3Val.m_fDAElem[2][1], m_fDAElem[2][2] - m3Val.m_fDAElem[2][2] );
}


CNtlNaviMatrix3 CNtlNaviMatrix3::operator * ( const CNtlNaviMatrix3& m3Val ) const
{
	return CNtlNaviMatrix3(
		m_fDAElem[0][0] * m3Val.m_fDAElem[0][0] + m_fDAElem[0][1] * m3Val.m_fDAElem[1][0] + m_fDAElem[0][2] * m3Val.m_fDAElem[2][0],
		m_fDAElem[0][0] * m3Val.m_fDAElem[0][1] + m_fDAElem[0][1] * m3Val.m_fDAElem[1][1] + m_fDAElem[0][2] * m3Val.m_fDAElem[2][1],
		m_fDAElem[0][0] * m3Val.m_fDAElem[0][2] + m_fDAElem[0][1] * m3Val.m_fDAElem[1][2] + m_fDAElem[0][2] * m3Val.m_fDAElem[2][2],

		m_fDAElem[1][0] * m3Val.m_fDAElem[0][0] + m_fDAElem[1][1] * m3Val.m_fDAElem[1][0] + m_fDAElem[1][2] * m3Val.m_fDAElem[2][0],
		m_fDAElem[1][0] * m3Val.m_fDAElem[0][1] + m_fDAElem[1][1] * m3Val.m_fDAElem[1][1] + m_fDAElem[1][2] * m3Val.m_fDAElem[2][1],
		m_fDAElem[1][0] * m3Val.m_fDAElem[0][2] + m_fDAElem[1][1] * m3Val.m_fDAElem[1][2] + m_fDAElem[1][2] * m3Val.m_fDAElem[2][2],

		m_fDAElem[2][0] * m3Val.m_fDAElem[0][0] + m_fDAElem[2][1] * m3Val.m_fDAElem[1][0] + m_fDAElem[2][2] * m3Val.m_fDAElem[2][0],
		m_fDAElem[2][0] * m3Val.m_fDAElem[0][1] + m_fDAElem[2][1] * m3Val.m_fDAElem[1][1] + m_fDAElem[2][2] * m3Val.m_fDAElem[2][1],
		m_fDAElem[2][0] * m3Val.m_fDAElem[0][2] + m_fDAElem[2][1] * m3Val.m_fDAElem[1][2] + m_fDAElem[2][2] * m3Val.m_fDAElem[2][2] );
}


CNtlNaviMatrix3& CNtlNaviMatrix3::operator *= ( float fVal )
{
	m_fDAElem[0][0] *= fVal; m_fDAElem[0][1] *= fVal; m_fDAElem[0][2] *= fVal;
	m_fDAElem[1][0] *= fVal; m_fDAElem[1][1] *= fVal; m_fDAElem[1][2] *= fVal;
	m_fDAElem[2][0] *= fVal; m_fDAElem[2][1] *= fVal; m_fDAElem[2][2] *= fVal;

	return *this;
}


CNtlNaviMatrix3& CNtlNaviMatrix3::operator /= ( float fVal )
{
	if ( fabsf( fVal ) <= NAVI_ZERO_THRESHOLD )
	{
		MakeInvalid();
	}
	else
	{
		fVal = 1.f / fVal;

		m_fDAElem[0][0] *= fVal; m_fDAElem[0][1] *= fVal; m_fDAElem[0][2] *= fVal;
		m_fDAElem[1][0] *= fVal; m_fDAElem[1][1] *= fVal; m_fDAElem[1][2] *= fVal;
		m_fDAElem[2][0] *= fVal; m_fDAElem[2][1] *= fVal; m_fDAElem[2][2] *= fVal;
	}

	return *this;
}


CNtlNaviMatrix3& CNtlNaviMatrix3::operator += ( const CNtlNaviMatrix3& m3Val )
{
	m_fDAElem[0][0] += m3Val.m_fDAElem[0][0]; m_fDAElem[0][1] += m3Val.m_fDAElem[0][1]; m_fDAElem[0][2] += m3Val.m_fDAElem[0][2];
	m_fDAElem[1][0] += m3Val.m_fDAElem[1][0]; m_fDAElem[1][1] += m3Val.m_fDAElem[1][1]; m_fDAElem[1][2] += m3Val.m_fDAElem[1][2];
	m_fDAElem[2][0] += m3Val.m_fDAElem[2][0]; m_fDAElem[2][1] += m3Val.m_fDAElem[2][1]; m_fDAElem[2][2] += m3Val.m_fDAElem[2][2];

	return *this;
}


CNtlNaviMatrix3& CNtlNaviMatrix3::operator -= ( const CNtlNaviMatrix3& m3Val )
{
	m_fDAElem[0][0] -= m3Val.m_fDAElem[0][0]; m_fDAElem[0][1] -= m3Val.m_fDAElem[0][1]; m_fDAElem[0][2] -= m3Val.m_fDAElem[0][2];
	m_fDAElem[1][0] -= m3Val.m_fDAElem[1][0]; m_fDAElem[1][1] -= m3Val.m_fDAElem[1][1]; m_fDAElem[1][2] -= m3Val.m_fDAElem[1][2];
	m_fDAElem[2][0] -= m3Val.m_fDAElem[2][0]; m_fDAElem[2][1] -= m3Val.m_fDAElem[2][1]; m_fDAElem[2][2] -= m3Val.m_fDAElem[2][2];

	return *this;
}


CNtlNaviMatrix3& CNtlNaviMatrix3::operator *= ( const CNtlNaviMatrix3& m3Val )
{
	*this = *this * m3Val;

	return *this;
}


CNtlNaviMatrix3::operator float* ( void )
{
	return m_fSAElem;
}


CNtlNaviMatrix3::operator const float* ( void ) const
{
	return m_fSAElem;
}


CNtlNaviMatrix3 operator * ( float fVal1, const CNtlNaviMatrix3& m3Val2 )
{
	return m3Val2 * fVal1;
}


CNtlNaviMatrix3 operator / ( float fVal1, const CNtlNaviMatrix3& m3Val2 )
{
	return m3Val2 / fVal1;
}


CNtlNaviVector3 operator * ( const CNtlNaviVector3& v3Val1, const CNtlNaviMatrix3& m3Val2 )
{
	const float* pVal = v3Val1;

	return CNtlNaviVector3(
		pVal[0] * m3Val2.m_fDAElem[0][0] + pVal[1] * m3Val2.m_fDAElem[1][0] + pVal[2] * m3Val2.m_fDAElem[2][0],
		pVal[0] * m3Val2.m_fDAElem[0][1] + pVal[1] * m3Val2.m_fDAElem[1][1] + pVal[2] * m3Val2.m_fDAElem[2][1],
		pVal[0] * m3Val2.m_fDAElem[0][2] + pVal[1] * m3Val2.m_fDAElem[1][2] + pVal[2] * m3Val2.m_fDAElem[2][2] );
}


CNtlNaviVector3 operator * ( const CNtlNaviMatrix3& m3Val1, const CNtlNaviVector3& v3Val2 )
{
	const float* pVal = v3Val2;

	return CNtlNaviVector3(
		m3Val1.m_fDAElem[0][0] * pVal[0] + m3Val1.m_fDAElem[0][1] * pVal[1] + m3Val1.m_fDAElem[0][2] * pVal[2],
		m3Val1.m_fDAElem[1][0] * pVal[0] + m3Val1.m_fDAElem[1][1] * pVal[1] + m3Val1.m_fDAElem[1][2] * pVal[2],
		m3Val1.m_fDAElem[2][0] * pVal[0] + m3Val1.m_fDAElem[2][1] * pVal[1] + m3Val1.m_fDAElem[2][2] * pVal[2] );
}


int CNtlNaviMatrix3::CompareArrays( const CNtlNaviMatrix3& m3Val ) const
{
	return memcmp( m_fDAElem, m3Val.m_fDAElem, sizeof(float)*9 );
}

