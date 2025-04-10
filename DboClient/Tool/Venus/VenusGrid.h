//***********************************************************************************
//	File		:	VenusGrid.h
//	Desc		:	
//	Begin		:	2004.9.30
//	Copyright	:	�� 2004 by agebreak CO., Ltd
//	Author		:	agebreak
//	Update		:	
//***********************************************************************************

#pragma once

#include "rwcore.h"


/**
 * \ingroup Venus
 * \brief ȭ�鿡 Grid�� �׸��� Ŭ����
 * \date 2006-08-01
 * \author agebreak
 */
class CVenusGrid
{
public:
	CVenusGrid(void);
	~CVenusGrid(void);

	static	CVenusGrid&	GetInstance(void);

	RwBool	Create();
	RwBool	Destroy();

	RwBool	CreateGrid(RwInt32 nTileCount);                     ///< �׸��带 �����Ѵ�.
	

	RwBool	Render();                                           ///< �׸��带 ȭ�鿡 ������ �Ѵ�.

    /// Intersection�� �����͸� ã�´�.
    RwBool	Intersection3dPoint(RwV3d* pIntersectionPoint, const RwV3d* pCenter, const RwV3d* pRayPos, const RwV3d* pRayDir);
    RwBool	IntersectionStart(POINT point, const RwV3d* pCenter);
    void	IntersectionEnd();
    RwBool	IntersectionMove(RwV3d* pMove, POINT point, const RwV3d* pCenter);

    // Get/Set �޼ҵ�
    void    SetTileCount(RwInt32 nTileCont) {m_nTileCount = nTileCont;} ///< Ÿ�� ������ �����Ѵ�.
    RwInt32 GetTileCount() {return m_nTileCount;}                       ///< Ÿ�� ������ ��ȯ�Ѵ�.

    RwBool	SetGridWidth(RwReal fGridWidth);                            ///< �׸����� ���̸� �����Ѵ�.
    RwReal  GetGridWidth() {return m_fGridWidth;}                       ///< �׸����� ���̸� ��ȯ�Ѵ�.

    RwBool  GetIntersection() {return m_bIntersection;}                 ///< Intersection ������ ��ȯ�Ѵ�.

protected:
    RwInt32					m_nTileCount;                       ///< Ÿ�� ����
    RwInt32					m_nVertexCount;                     ///< ���ؽ� ����
    RwReal					m_fGridWidth;                       ///< Grid ����
    RwIm3DVertex*			m_pVertex;                          ///< ���ؽ� ������ ������
    RwBool					m_bIntersection;                    ///< Intersection ����
    RwV3d					m_vOldIntersectionPoint;            ///< ���� Intersection ��ġ
    RwIm3DVertex			m_IntersectionPlaneVertex[4];       ///< Intersection�� Plane�� ���ؽ�
    RwV3d					m_vOldCenter;                       ///< ���� �߽���
};
