//***********************************************************************************
//	File		:	VenusFramework.h
//	Desc		:	
//	Begin		:	2005. 7.28
//	Copyright	:	�� 2005 by agebreak CO., Ltd
//	Author		:	agebreak
//	Update		:	
//***********************************************************************************

#pragma once

#include "NtlPostEffectCamera.h"

// ī�޶� View 
enum EVenusCameraStaticView
{
    E_STATIC_VIEW_FRONT,
    E_STATIC_VIEW_BACK,
    E_STATIC_VIEW_UP,
    E_STATIC_VIEW_DOWN,
    E_STATIC_VIEW_LEFT,
    E_STATIC_VIEW_RIGHT,
};

/**
 * \ingroup Venus
 * \brief Venus�� ī�޶� Ŭ����. PostEffectCamera�κ��� ��ӹ޾Ƽ� �ǻ��� ����� �ȴ�.
 * \date 2006-08-01
 * \author agebreak
 */
class CVenusCamera : public CNtlPostEffectCamera
{
public:
	CVenusCamera(void);
	virtual ~CVenusCamera(void);

	void	Destroy();
	virtual RwCamera* Create( RwInt32 width,
						RwInt32 height, 
						RwBool zBuffer, 
						RwReal fNearClipPlane = 1.f, 
						RwReal fFarClipPlane = 1000.f);

    void	MouseMessages(UINT uMsg, POINT point, short zDelta = 0, UINT nFlags = 0);   ///< ���콺 �޽����� �����Ѵ�.

    /// View Matrix�� �ʱ�ȭ �Ѵ�.
    void	InitViewMatrix();
    void	InitViewMatrix(RwCamera* pCamera);

    /// View Matrix�� ������Ʈ �Ѵ�.
    void	UpdateViewMatrix(RwV3d* pMove);
    void	UpdateViewMatrix();
    void	UpdateViewMatrix(RwCamera* pCamera);

    RwMatrix*	GetViewMatrix();        ///< ���� ī�޶� Matrix�� ��ȯ�Ѵ�.
    RwV3d*	    GetViewPosition();      ///< ���� ī�޶� ��ġ�� ��ȯ�Ѵ�.

    RwBool	GetArrowMatrix(RwMatrix& matArrow);
    RwBool	GetClumpMatrix(RwMatrix& matClump);

    // Get/Set �޼ҵ�
    void   SetTargetPosition(const RwV3d vTargetPosition) {m_vTargetPosition = vTargetPosition;};    ///< Ÿ�� ��ġ�� �����Ѵ�.
    RwV3d  GetTargetPosition() {return m_vTargetPosition;} ///< LootAt Ÿ�� ��ġ�� ��ȯ�Ѵ�.

    void   SetViewDistance(RwReal fViewDistance) {m_fViewDistance = fViewDistance;} ///< �þ߰Ÿ��� �����Ѵ�.

    RwReal GetMoveSpeed() {return m_fMoveSpeed;}            ///< Move Speed�� ��ȯ�Ѵ�.
    void   SetMoveSpeed(const RwReal fMoveSpeed) {m_fMoveSpeed = fMoveSpeed;} ///< Move Speed�� ��ȯ�Ѵ�.

    RwReal GetRotationSpeed() {return m_fRotateSpeed;};     ///< Rotation Speed�� ��ȯ�Ѵ�.
    void   SetRotationSpeed(const RwReal fRotationSpeed) {m_fRotateSpeed = fRotationSpeed;} ///< ���� ȸ�� �ӵ��� ��ȯ�Ѵ�.

    RwReal GetWheelSpeed() {return m_fWheelSpeed;}          ///< Wheel Speed�� ��ȯ�Ѵ�.
    void   SetWheelSpeed(const RwReal fWheelSpeed) {m_fWheelSpeed = fWheelSpeed;} ///< Wheel Speed�� �����Ѵ�.

    void	GetMouseRay(const POINT& point, RwV3d& vRayPos, RwV3d& vRayDir);

    void    SetStaticView(EVenusCameraStaticView eStaticView);      ///< �̹� ���ǵ� View �������� ī�޶� ��ġ��Ų��.

    static	CVenusCamera&	GetInstance(void);

protected:
    void	RotateViewMatrix(POINT gap, RwCamera* pCamera);
    void	MoveViewMatrix(POINT gap, RwCamera* pCamera);

protected:
    RwReal		m_fViewDistance;                ///< �þ� �Ÿ�
    RwV3d		m_vTargetPosition;              ///< Look Ÿ���� ��ġ

    RwBool		m_bRButtonDown;                 ///< ���콺 ������ ��ư ���� ����
    POINT		m_RButtonDownPosition;          ///< ���콺 ������ ��ư�� ���������� ��ġ

    RwBool		m_bMButtonDown;                 ///< ���콺 �� ��ư ���� ����
    POINT		m_MButtonDownPosition;          ///< ���콺 �� ��ư�� ���������� ��ġ

    RwReal		m_fMoveSpeed;                   ///< ī�޶� Move Speed
    RwReal		m_fRotateSpeed;                 ///< ī�޶� ȸ�� Speed
    RwReal		m_fWheelSpeed;                  ///< ī�޶� �� Speed (�Ÿ� ����)
};
