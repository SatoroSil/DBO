//-----------------------------------------------------------------------------
// Name: class CDevIL
// Desc: DevIL SDK�� �̿��Ͽ� �̹����� �ε��ϴ� Ŭ����.
//
//			 
// 2004.08	  KlayMan@gs
// 2006.01.16 Peessi@hitel.net  ���� �� ���ȭ
//-----------------------------------------------------------------------------

#include "stdafx.h"					// for Windows MFC
#include "CDevIL.h"

CDevIL::CDevIL()
{
	ClearMember();
	Init();
}

CDevIL::~CDevIL()
{
	Shutdown();
}

void CDevIL::ClearMember()
{
	m_imageIdx	= 0;
	m_nWidth	= 0;  
	m_nHeight	= 0; 
	m_nBytes	= 0;
	m_nBits		= 0;  
	m_nFormat	= 0; 
	m_nType		= 0;   
	m_nFSet		= 0;
	m_nFMode	= 0;
	m_nTSet		= 0;
	m_nTMode	= 0;
	m_nOrgMode	= 0;

	m_pPic		= NULL;
}


void CDevIL::Init()
{
	ilInit();
	iluInit();
	ilutRenderer( ILUT_WIN32 );
}

void CDevIL::Shutdown()
{
	Unload();		// �ε�Ǿ� �ִ°� �켱 �����.
	ilShutDown();	
}

BOOL CDevIL::Load( LPCTSTR szFilename )
{
	// IL0. ���� Image�� �ı��Ѵ�. 
	Unload();


	// IL1. 1���� Image�� 'imageIdx'��� �̸�(����)���� �����.
	ilGenImages( 1, &m_imageIdx );


	// IL2. 'imageIdx'��� �̸��� ���� �ٷ�� �ִ� Image�� ���Ѵ�.
	ilBindImage( m_imageIdx );


	// IL2-1. �׸� �������丶�� �ȼ��� ���Ϸ� ����Ǵ� ������ �ٸ��Ƿ�,
	//      ������ '������ �Ʒ�' ������ �ǵ��� '������' ���Ѵ�.
	ilEnable( IL_ORIGIN_SET );
	ilOriginFunc( IL_ORIGIN_UPPER_LEFT );


	// IL3. �׸��� �о ���� Image�� �ִ´�.
	//      ���������� �˾Ƽ� �ν��Ѵ�.
	if( ilLoadImage( (char*)szFilename ) == IL_FALSE ) 
	{
		Unload();
		return FALSE;
	}

	// IL3-1. ���������� ���缭 �а� �ʹٸ� ilLoad()�� �̿��Ѵ�.
	//ilLoad( fileType, szFileName );

	// IL4. Image�� Pixel���� � ���̴� ����
	//      BGRA����/32��Ʈ�� ubyte���� ���·� �ٲ۴�. 
	//      --> Alpha ������ �������� ��� ������.
	ilConvertImage( IL_BGRA, IL_UNSIGNED_BYTE );

	// IL4-1. Alpha ä���� ���ٸ� �����ϰ� �ε��ص� ����.
	//ilConvertImage( IL_BGR, IL_UNSIGNED_BYTE );

	// IL4-2. Alpha ä���� ���µ� BGRA������ Alpha ä�� �������� �������ϸ�
	//        Alpha ���� ������ 0xFF(255)�� �ȴ�.

	// IL4-2. �ϴ� �������� �Ǹ� ���������� ������ �� ���·� �����ȴ�.
	//        ���� �������������� �����ϴ� ���� �߿��ϴٸ�,
	//        �̷��� �����ϰ� �������ؼ��� �ȵȴ�.

	//// Infomation Setting
	m_nWidth	= ilGetInteger( IL_IMAGE_WIDTH );
	m_nHeight	= ilGetInteger( IL_IMAGE_HEIGHT );
	m_nBytes	= ilGetInteger( IL_IMAGE_BYTES_PER_PIXEL );
	m_nBits		= ilGetInteger( IL_IMAGE_BITS_PER_PIXEL );
	m_nFormat	= ilGetInteger( IL_IMAGE_FORMAT );
	m_nType		= ilGetInteger( IL_IMAGE_TYPE );
	m_nFSet		= ilGetInteger( IL_FORMAT_SET );
	m_nFMode	= ilGetInteger( IL_FORMAT_MODE );
	m_nTSet		= ilGetInteger( IL_TYPE_SET );
	m_nTMode	= ilGetInteger( IL_TYPE_MODE );
	m_nOrgMode  = ilGetInteger( IL_ORIGIN_MODE );	

	// pixel data pointer setting
	m_pPic		= ilGetData();

	return TRUE;
}

void CDevIL::Unload()
{
	// 1. IL�� �о���� �̹����� �����Ѵ�. 
	//    ������ �ε����� ������ ������ ��ü�� ���� �ִ�.
	ilDeleteImages( 1, &m_imageIdx );	

	// 2. ���� �����ߴ� �Ӽ� �� �ʱ�ȭ. 
	ClearMember();						
}

BOOL CDevIL::GetPixel( INT x, INT y, BYTE* pRed, BYTE* pGreen, BYTE* pBlue, BYTE* pAlpha )
{
	if( m_imageIdx && x >= 0 && x < m_nWidth && y >= 0 && y < m_nHeight )
	{
		*pRed	= m_pPic[ ( m_nWidth * m_nBytes ) * y + ( m_nBytes * x ) + 2 ];
		*pGreen = m_pPic[ ( m_nWidth * m_nBytes ) * y + ( m_nBytes * x ) + 1 ];
		*pBlue  = m_pPic[ ( m_nWidth * m_nBytes ) * y + ( m_nBytes * x )     ];
		*pAlpha = m_pPic[ ( m_nWidth * m_nBytes ) * y + ( m_nBytes * x ) + 3 ];
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
