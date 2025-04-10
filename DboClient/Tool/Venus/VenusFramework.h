//***********************************************************************************
//	File		:	VenusFramework.h
//	Desc		:	
//	Begin		:	2005. 7.28
//	Copyright	:	�� 2005 by agebreak CO., Ltd
//	Author		:	agebreak
//	Update		:	
//***********************************************************************************

#pragma once

#include "d3d9types.h"
#include "NtlApplication.h"

#include "rpworld.h"
#include "rtcharse.h"
#include "NtlPLWorldEntity.h"
#include "NtlPLEventHandler.h"
#include "NtlPlSun.h"
#include "NtlPLEntityRenderHelpers.h"

#include ".\ntllightingcontroller.h"

/**
 * \ingroup Venus
 * \brief Venus�� Main FrameWork
 * \date 2006-07-31
 * \author agebreak
 */
class CVenusFramework : public CNtlApplication
{
public:
	CVenusFramework(void);
	virtual ~CVenusFramework(void);

	virtual void	Destroy();
	virtual RwBool	Update(RwReal fTime, RwReal fElapsedTime);
			void	OnIdle()	{ CNtlApplication::Update(); }

            void	SetSelectRectangle(POINT& OldPoint, POINT& CurPoint);  ///< ���ÿ��� �簢���� �����Ѵ�.
            void	CreateEffectClump(const RwChar* strPathName);          ///< Effect Clump�� �����Ѵ�.
    
            void	UpdateAmbient();                                       ///< Ambient Light�� ������Ʈ�Ѵ�.
            void	UpdateMainLight();                                     ///< Main Light�� ������Ʈ�Ѵ�.
            RpLight* CreateMainLight();                                    ///< Main Light�� �����Ѵ�.

            void	ShowTerrain(RwBool bShow);                             ///< ���� ǥ�� ������ �����Ѵ�.
            void	ShowObject(RwBool bShow);                              ///< Decal Test�� ���� Object ǥ�� ������ �����Ѵ�.

            /// Get/Set Method
            RwBool  GetSelectMode() {return m_bSelectMode;}                ///< Select Mode�� �����Ѵ�,.
            void    SetSelectMode(RwBool bSelectMode) {m_bSelectMode = bSelectMode;} ///< Select Mode�� ��ȯ�Ѵ�.

            RwRGBA  GetBackGroundColor() {return m_BackgroundColor;}       ///< Background Color�� ��ȯ�Ѵ�.
            void    SetBackGroundColor(const RwRGBA& color) {m_BackgroundColor = color;} ///< BackGround Color�� �����Ѵ�.

            void    SetFrameFix(RwBool bEnable) {m_bFrameFix = bEnable;}           ///< Frame Fix ������ �����Ѵ�. (����� 30 fps�� �����Ѵ�.)                    
            RwBool  GetFrameFix() {return m_bFrameFix;}                            ///< Frame Fix ������ ��ȯ�Ѵ�. 

			RwBool	CreateWorld();												   ///< VENUS���� ����� World�� �����Ѵ�.

	static	CVenusFramework&	GetInstance(void);

protected:
    virtual RwBool  AttachPlugin();                                        ///< Plugin���� Attach �Ѵ�.
    virtual RwBool	CreateSubSystem(RwUInt32 iWidth, RwUInt32 iHeight, RwBool bZBuffer); ///< SubSystem�� �����Ѵ�.

    RpClump* LoadDummyClump(const RwChar* strFileName, RwV3d v, RwV3d s);  ///< Dummy Clump�� �����Ѵ�.

    void	SetPauseVertex();                                              ///< Pause�� ��Ÿ���� ȭ�� �׵θ� ���ؽ��� �����Ѵ�.
    void	DisplayInfo();
    
    void	RenderSelectRectangle();                                       ///< ���� ������ ȭ�鿡 ������ �Ѵ�.
    void	AutoTempFileSave();                                            ///< �ӽ� ������ �ڵ����� �����Ѵ�.
    void    SetErrorReport();                                              ///< BugTrap�� �̿��� ���� ����Ʈ ������ �Ѵ�.
	RwBool	VENUS_PLInit();												   ///< API_PLInit�� ������ Venus�� �°� �����ߴ�.
	void	VENUS_PLTerminate();										   ///< API_PLTerminate�� ������ Venus�� �°� �����ߴ�.

protected:
    RtCharset*						m_pCharset;             ///< Display ������ ǥ���ϱ� ���� ��ü
    RpWorld*						m_pWorld;               ///< World ��ü
	CNtlPLWorldEntity*				m_pWorldEntity;			///< World Entity ��ü
    RpLight*						m_pAmbientLight;        ///< Ambient Light ��ü
    RpLight*						m_pMainLight;           ///< Main Light ��ü

    RpClump*						m_pEffectClump;         ///< Effect Clump
	CNtlPLEntity*					m_pDecalTestObject;		///< Decal Test�� Object ��ü

    RwRGBA							m_BackgroundColor;      ///< BackGround Color
    RwRGBA							m_ForegroundColor;      ///< ForeGround Color

    RwBool							m_bSelectMode;          ///< ���� Mode Flag
	CNtlPLEventHandler		       *m_pPLEventHandler;

    // ���� �簢�� ���ؽ�
    enum RECTANGLE_VERTEX
    {
        RECTANGLE_VERTEX_COUNT = 5
    };
    RwIm2DVertex					m_RectangleVertex[RECTANGLE_VERTEX_COUNT];      ///< Select �簢�� ���ؽ�

    CNtlLightingController			m_LightningController;		///< ���� ������.

    RwIm2DVertex					m_PauseVertex[16];          ///< Pause ���ؽ�

    RwReal							m_fAutoSaveTime;            ///< Auto Save�� Time ��

    RwBool                          m_bFrameFix;                ///< FrameFix ������ �����Ѵ�.
    RwReal                          m_fTimeFrameFix;            ///< FrameFix�� ����� Time���� �����ϰ� �ִ� ����
    SToonData*                      m_pToonData;                     ///< ���� ����� �޽ø� ���� �� ����

public:
	CNtlPLSun*						m_pSun;						///< LensFlare Test�� ���� ��ü

};
