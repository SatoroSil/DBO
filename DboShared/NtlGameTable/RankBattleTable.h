#pragma once
//last update 1.12.2014
#include "table.h"
#include "NtlRankBattle.h"


const DWORD		DBO_MAX_LENGTH_RANKBATTLE_CAMERA_NAME = 32;
//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
#pragma pack(push, 4)
struct sRANKBATTLE_TBLDAT : public sTBLDAT
{
public:

	sRANKBATTLE_TBLDAT( void ) { }

public:

	BYTE			byRuleType;				// Game rule eGAMERULE_TYPE
	BYTE			byBattleMode;			// Battle Type 0 = Individual, 1 = party

	BYTE			byMatchType;			//always 0 except at tblidx 2032 its 1

	WCHAR			wszName[ DBO_RANKBATTLE_NAME_LENGTH + 1 ];
	TBLIDX			worldTblidx;			// World_Table Index
	TBLIDX			needItemTblidx;			// Items necessary for entry
	DWORD			dwZenny;				// Zeni needed to enter
	BYTE			byMinLevel;				// Minimum level
	BYTE			byMaxLevel;				// Maximum level
	BYTE			byBattleCount;			// Stages Count

	DWORD			dwWaitTime;				// It enters standby time
	DWORD			dwDirectionTime;		// Directing time
	DWORD			dwMatchReadyTime;		// Match preparation time
	DWORD			dwStageReadyTime;		// Stage preparation time
	DWORD			dwStageRunTime;			// Stage game time
	DWORD			dwStageFinishTime;		// Stage end time
	DWORD			dwMatchFinishTime;		// Played Time
	DWORD			dwBossDirectionTime;	// I produced particles
	DWORD			dwBossKillTime;			// I'm particles hunting time
	DWORD			dwBossEndingTime;		// Cleanup Time
	DWORD			dwEndTime;				// End

	char			chScoreKO;				// KO�½� ����
	char			chScoreOutOfArea;		// ��ܽ½� ����
	char			chScorePointWin;		// �����½� ����
	char			chScoreDraw;			// ������� ����
	char			chScoreLose;			// �й�� ����

	char			chResultExcellent;		// ��� ��� ���,  >= chResultExcellent
	char			chResultGreate;			// ��� ��� ���,  < chResultExcellent, >= chResultGreate
	char			chResultGood;			// ��� ��� ���,  < chResultGreate, >= chResultDraw
	char			chResultDraw;			// ��� ��� ���,  == chResultDraw
	char			chResultLose;			// ��� ��� ���,  == chResultLost

	char			chBonusPerfectWinner;	// �Ͻ����� �������� ��� �߰� ����
	char			chBonusNormalWinner;	// �Ϲ����� ������ �������� �߰� ����

	//new
	WCHAR			wszBGMName[ DBO_RANKBATTLE_MAX_BGM_NAME + 1 ];
	BYTE			byDayEntryNum;
	bool			bOutSizeAble;
	char			szCameraName[ DBO_MAX_LENGTH_RANKBATTLE_CAMERA_NAME + 1 ];
	DWORD			dwInfoIndex;
	DWORD			dwStateMinClearTime;

protected:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
class CRankBattleTable : public CTable
{
public:

	CRankBattleTable( void );

	virtual ~CRankBattleTable( void );

public:

	virtual bool			LoadFromBinary(CNtlSerializer& serializer, bool bReload, bool bUpdate);

	virtual bool			SaveToBinary(CNtlSerializer& serializer);

public:

	bool					Create( DWORD dwCodePage );

	void					Destroy( void );

public:

	sTBLDAT*				FindData(TBLIDX tblidx); 

protected:

	void					Init( void );

	WCHAR**					GetSheetListInWChar( void ) { return &m_pwszSheetList[0]; }

	void*					AllocNewTable( WCHAR* pwszSheetName, DWORD dwCodePage );

	bool					DeallocNewTable( void* pvTable, WCHAR* pwszSheetName );

	bool					AddTable( void* pvTable, bool bReload, bool bUpdate );

	bool					SetTableData( void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData );


protected:

	static WCHAR*			m_pwszSheetList[];

};
