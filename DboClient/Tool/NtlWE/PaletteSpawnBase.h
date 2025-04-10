#pragma once


#include "SpawnMacro.h"
#include "Spawn.h"


class CPaletteSpawnBase : public CDialog
{
	DECLARE_DYNAMIC(CPaletteSpawnBase)

public:
	CPaletteSpawnBase(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPaletteSpawnBase();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SPAWN_BASE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_CurSpawnPos;
	CString m_CurSpawnDir;
	CString m_CurSpawnMacro;
	CString m_CurSpawnInfo;

protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();

public:
	VOID Refresh(RwV3d& _SpawnPos, RwV3d& _SpawnDir, CSpawnMacro& _SpawnMacro, CSpawn* pSpawn);
};
