//***********************************************************************************
//	File		:	VenusPlayer.h
//	Desc		:	
//	Begin		:	2005. 7.28
//	Copyright	:	�� 2005 by NTL CO., Ltd
//	Author		:	agebreak
//	Update		:	
//***********************************************************************************

#pragma once

#include "rwcore.h"
#include "rpworld.h"

#include <rphanim.h>
#include <rpskin.h>
#include <rpuvanim.h>
#include <rtdict.h>

#include "NtlPLEntity.h"
#include "NtlPLResource.h"

#include <vector>

#include "NtlPLEntityRenderHelpers.h"

/**
 * \ingroup Venus
 * \brief Event Layer���� ����ϴ� ĳ���� ��ü
 * \date 2006-08-02
 * \author agebreak
 */
class CVenusPlayer
{
public:
	enum FADE_OUT_TYPE
	{
		FADE_OUT_NONE,
		FADE_OUT_DELEETE,
		FADE_OUT_STOP,
		FADE_OUT_BALL
	};

	struct EVENT
	{
		std::string		strEffectName;
		RwInt32			nBoneIndex;

		RwBool			bFadeIn;
		RwBool			bFadeOut;
		RwReal			fFadeInTime;
		RwReal			fFadeOutTime;
		RwInt32			nFadeOutType;

		CNtlPLEntity*	pEffectEntity;
	};
    typedef std::vector<EVENT*>	svdef_EVENT;

public:
	CVenusPlayer(void);
	~CVenusPlayer(void);

	void	Create();
    void	Delete();
    void	DeleteEffectEntity();

	void	CopyData(CVenusPlayer* pSrcPlayer);

	void	InitializeEvent(EVENT* pEvent);

	RwBool	Update(RwReal fElapsedTime);
	RwBool	Render();

	void	SetWorldMatrix(const RwMatrix& matWorld);

			RwInt32		GetNumNode();                       ///< Bone�� ������ ��ȯ�Ѵ�.
            RwChar*     GetBoneName(int nIndex);            ///< Bone�� �̸��� ��ȯ�Ѵ�.
	const	RwMatrix*	GetNodeMatrix(RwInt32 nNode);

	RwBool	Save(FILE* pFile);
	RwBool	Load(FILE* pFile);

	CVenusPlayer::EVENT*	GetEvent(RwInt32 nIndex)		{ return m_svEvent[nIndex]; }

    // Get/Set �޼ҵ�
    std::string GetClumpName() {return m_strClumpName;}             ///< Clump �̸��� ��ȯ�Ѵ�.
    void        SetClumpName(std::string& strClumpName) {m_strClumpName = strClumpName;} ///< Clump �̸��� �����Ѵ�.

    std::string GetAnimationName() {return m_strAnimationName;}     ///< Animation �̸��� ��ȯ�Ѵ�.
    void        SetAnimationName(std::string& strAnimName) { m_strAnimationName = strAnimName;} ///< Animation �̸��� �����Ѵ�.

    CNtlPLResource* GetAnimationResource() {return m_pAnimationResource;} ///< Animation Resource�� ��ȯ�Ѵ�.

    svdef_EVENT& GetEventVector() {return m_svEvent;}               ///< Event Vector�� ��ȯ�Ѵ�.

    RwReal      GetAnimCurrentTime() {return m_fCurrentTime;}       ///< ���� �ִϸ��̼� �ð��� ��ȯ�Ѵ�.
    RwUInt32    GetMaxTime() {return m_nMaxTime;}                   ///< MaxTime�� ��ȯ�Ѵ�.

protected:
    void	DeleteEvent();

protected:
    svdef_EVENT			m_svEvent;                      ///< Event ��ü���� Vector

    std::string			m_strClumpName;                 ///< Clump Name
    std::string			m_strAnimationName;             ///< Animation Name

    CNtlPLResource*		m_pClumpResource;               ///< Clump Resource
    CNtlPLResource*		m_pAnimationResource;           ///< Animation Resource
    RpHAnimHierarchy*   m_pBaseHierarchy;               ///< ĳ���� ���� Hierarchy

    RwReal				m_fLifeTime;    

    RwReal				m_fCurrentTime;
    RwUInt32			m_nMaxTime;
    SToonData*          m_pToonData;                     ///< ���� ����� �޽ø� ���� �� ����
};
