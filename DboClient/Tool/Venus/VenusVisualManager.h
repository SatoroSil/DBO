//***********************************************************************************
//	File		:	CVenusVisualManager.h
//	Desc		:	
//	Begin		:	2005. 7.28
//	Copyright	:	�� 2005 by agebreak CO., Ltd
//	Author		:	agebreak
//	Update		:	
//***********************************************************************************

#pragma once

#include <d3d9.h>

#include <algorithm>

#include "NtlPLVisualManager.h"

#include "NtlEffectDefine.h"

#include "NtlResourceComponentSystem.h"

#include "NtlInstanceEffect.h"


/**
 * \ingroup Venus
 * \brief Venus�� Visual Manager
 * \date 2006-08-09
 * \author agebreak
 */
class CVenusVisualManager : public CNtlPLVisualManager
{
public:
    enum EMITTER_VERTEX
    {
        EMITTER_VERTEX_COUNT = 8,
        EMITTER_INDEX_COUNT = 48
    };

public:
	CVenusVisualManager(void);
	~CVenusVisualManager(void);

	static	CVenusVisualManager&	GetInstance(void);

	virtual RwBool	Create(void);
	virtual void	Destroy(void);
			void	Clear();

	virtual void	Update(RwReal fElapsed);
	virtual void	Render(void);	

    void    RenderEffect(RwBool bRender);                           ///< ����Ʈ �������� On/Off �Ѵ�.

	RwInt32	GetRenderingEffectCount();
	RwInt32 GetRenderingPolygonCount();
    RwUInt32 GetRenderingEffectUsedMemory();

	RwBool	ResetInstanceEffectFromSplinePath(const RwChar* strName);

	///< EffectEntity�� Property Data�� ������ �Ǿ��� ��� ȣ���� �ȴ�.
	RwBool	ResetInstanceEffect(const RwChar* strName);
	///< EffectEntity�� ������ �Ѵ�.
	RwBool	DeleteInstanceEffect(const RwChar* strName);

	void	EditInstanceEffect(RwInt32 nAxisType, POINT gap);
	void	EditInstanceEffect(RwMatrix* pEditMatrix);

    /// Effect�� ���ÿ����ȿ� ���ԉ���� üũ�Ѵ�.
	void	IntersectionEffect(POINT point, RwBool bShiftButton, RwBool bCtrlButton); 
	void	IntersectionEffect(POINT OldPoint, POINT CurPoint, RwBool bShiftButton, RwBool bCtrlButton); 
	void	InsertSelectEffect(CNtlInstanceEffect* pInstanceEffect, RwBool bShiftButton, RwBool bCtrlButton);

	void	AddSelectInstanceEffectPoint(RwV3d* pEditVector);
	void	SetSelectInstanceEffectPoint(RwV3d* pEditVector);
	void	SetSelectInstanceEffectPoint_X(float x);
	void	SetSelectInstanceEffectPoint_Y(float y);
	void	SetSelectInstanceEffectPoint_Z(float z);
	
	CNtlPLEntity*	CreateEventEffect(const RwChar *pKey);
	void			DeleteEventEffect(CNtlPLEntity *pEntity);

	///< ���õ� Effect System
	void	SetSelectResourceData(CNtlResourceEffect* pResourceEffect = NULL, CNtlResourceComponentSystem* pResourceComponentSystem = NULL, RwInt32 nSystemDataFlag = 0);

    /// �ٿ�� ���Ǿ �ڵ� �����Ѵ�.
    void    OnGenerateBoundingBoxAll();

protected:
	virtual void AlarmAutoDelete(CNtlPLEntity *pEntity);			///< �����Ǵ� Effect���� ���� ���� �Լ� (Repeat ����� ���ؼ� �������̵� �Ѵ�.)
    CNtlInstanceEffect* CreateEffect(RwUInt32 nIndex);              ///< �ٿ�� �ڽ��� ���ؼ� ����Ʈ�� �����ϴ� �Լ�

public:
    CNtlResourceEffect*				m_pResourceEffect;
    CNtlResourceComponentSystem*	m_pResourceSystem;
    RwInt32							m_nSystemDataFlag;	

    typedef std::vector<CNtlInstanceEffect*> svdef_InstanceEffect;
    svdef_InstanceEffect			m_svSelectInstanceEffect;

    LPDIRECT3DDEVICE9				m_lpDevice;

    RwReal							m_fDeltaTime;

    
    RwIm3DVertex					m_EmitterVertex[EMITTER_VERTEX_COUNT];
    RwImVertexIndex					m_EmitterIndex[EMITTER_INDEX_COUNT];

protected:
    // �ٿ�� �ڽ� ����� ���� �ӽ� ������
    CNtlInstanceEffect*             m_pBSCurrEffect;
    RwUInt32                        m_nBSIndex;
    RwBool                          m_bGenerateBS;
    RwReal                          m_fEffectLifeTime;

    RwInt32                         m_nEventEffectUsedMemory;                      ///< �̺�Ʈ���� ������ ����Ʈ���� ����ϴ� �޸�
};

inline void CVenusVisualManager::SetSelectResourceData(CNtlResourceEffect* pResourceEffect, CNtlResourceComponentSystem* pResourceComponentSystem, RwInt32 nSystemDataFlag)
{
	m_pResourceEffect = pResourceEffect;
	m_pResourceSystem = pResourceComponentSystem;
	m_nSystemDataFlag = nSystemDataFlag;
}

