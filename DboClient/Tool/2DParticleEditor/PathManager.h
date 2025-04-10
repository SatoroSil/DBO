#ifndef _PATHMANAGER_H_
#define _PATHMANAGER_H_

#pragma once

//class CPathPoint;
#include "gui_precomp.h"
#include "guicore_precomp.h"

#include "gui_particlepath.h"
#include "gui_particle_doc.h"

#include "gui_line_renderer.h"

class CPathPoint;

class CPathManager
{
public:
	~CPathManager();

	void Destroy();

	void SetControlPoint( gui::SCtrlPoint* pCtrlPoint, int nCount );

	// SetActive/DeActive
	void SetActivePathItem( gui::CValueItem* pValueItem );
	void DeActivePathItem();

	// Build Active
	void BuildActivePathItem();
	
	// Update/Save
	void UpdateCurrentPathData();
	void SaveCurrentPathData();

	// Tooltip
	void ShowToolTip( int nPosX, int nPosY, TCHAR* tcToolTip, BOOL bShow = TRUE );
	
	// Offset�� ����Ǿ��� �� ȣ��
	void RefreshOffsetData();
	
	// Render
	void Render();

	// Getter/Setter
public:
	int GetCount();
	// Path�� �� �ð��� ����
	void SetTotalTime( float fTime );

	static CPathManager* GetInstance()
	{
		static CPathManager instance;
		return &instance;
	}

	///< Line
	void	CreateActivePathLine();
	void	DestroyActivePathLine();

protected:
	// Create
	CPathManager();

	void Create( int nCount );

protected:
	CPathPoint*			m_pPath;					///< ���� ���� ������
	
	gui::SCtrlPoint*	m_pCtrlPoint;				///< ���� Ctrl Point�� Data
	gui::SPathInfo		m_sPathInfo;				///< �н��� ����
	gui::CParticlePath	m_GuiPath;					///< ���̺귯�� �н�
	
	gui::CValueItem*	m_pActiveValueItem;			///< ���� �������� Path

	gui::CStaticBox*	m_pStbToolTip;				///< ToolTip�� �ڽ�

	gui::CGuiLine*		m_pLinePath;				///< �н��� ����

	int					m_nCount;						///< �н� ����
};

static CPathManager* GetPathManager()
{
	return CPathManager::GetInstance();
}

#endif//_PATHMANAGER_H_