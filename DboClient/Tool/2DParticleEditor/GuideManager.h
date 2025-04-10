#ifndef __GUIDE_MANAGER_H__
#define __GUIDE_MANAGER_H__

// Pre-Compile
#include "gui_precomp.h"
#include "guicore_precomp.h"

#include "gui_line_renderer.h"

#pragma once

/**
* \brief TOOL���� Guide Line�� �׸��� ���� �Ŵ��� Ŭ����
*/
class CGuideManager
{
public:
	enum eCENTER_LINE
	{
		eCENTER_LINE_HORIZONTAL,	///< ����
		eCENTER_LINE_VERTICAL,		///< ����

		eCENTER_LINE_NUMS			///< ���̵���� ����
	};

	CGuideManager(void);
	virtual ~CGuideManager(void);

	static CGuideManager* GetInstance(VOID)
	{
		static CGuideManager instance;
		return &instance;
	}

	// Guide Line ( �߾Ӽ� )
	VOID			SetCenter( float fX, float fY );

	VOID			SetBox( float fX, float fY, float fWidth, float fHeight );
	VOID			ShowBox( BOOL bShow );
	
	VOID			Render();

protected:
	gui::CGuiLine	m_lineCenter[eCENTER_LINE_NUMS];			///< ȭ���� �߾Ӽ� ( + ǥ�� )

	float			m_fCenterX;
	float			m_fCenterY;

	gui::CGuiLine	m_lineBox;									///< Emitter�� Box Type�� ��� ������ ���ִ� �������̽�
	BOOL			m_bLineBox;

	float			m_fBoxPosX;
	float			m_fBoxPosY;
	float			m_fBoxWidth;
	float			m_fBoxHeight;
};

static CGuideManager* GetGuideManager(void)
{
	return CGuideManager::GetInstance();
}

#endif