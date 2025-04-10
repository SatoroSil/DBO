#pragma once

#include <GdiPlus.h>
using namespace Gdiplus;

// GDI+�� ���� ���۸� Ŭ����
class CGDIPlusDBuffer
{
    HWND			m_hWnd;				// ���� ���۸��� ������ ������ �ڵ�
    Graphics*		m_pGraphics;		// ���� ���۸��� Graphics ������
    Bitmap*			m_pMemBmp;			// �޸� ��Ʈ�� ������

public:
    // ������ : �ݵ�� ������ �ڵ��� ���ڷ� �����ؾ� �Ѵ�
    CGDIPlusDBuffer(HWND hWnd);


    // �Ҹ��� : ���ۿ� ��µ� �׷����� ȭ�鿡 ����Ѵ�
    virtual ~CGDIPlusDBuffer();	


    // ���� ���۸��� Graphics �����͸� �����ϴ� �Լ�
    Graphics* GetGraphics()		{ return m_pGraphics; }
};