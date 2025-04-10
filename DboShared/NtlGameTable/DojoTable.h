//***********************************************************************************
//
//	File		:	DojoTable.h
//
//	Begin		:	2008-12-29
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Chung,DooSup ( mailto:john@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#pragma once


#include "table.h"
#include "NtlVector.h"

const DWORD	    DOJO_MAX_UPGRADE_OBJECT_COUNT	= 4;
const DWORD	    DOJO_MAX_REWARD_TYPE_COUNT	= 5;

struct sDOJO_REWARD
{
	DWORD	dwGetPoint;
	BYTE	byGetRock;
};
//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
#pragma pack(push, 4)
struct sDOJO_TBLDAT : public sTBLDAT
{
public:

	sDOJO_TBLDAT( void ) { }

public:

	TBLIDX			zoneTblidx; // WorldTable Index
	TBLIDX			objectTblidx[DOJO_MAX_UPGRADE_OBJECT_COUNT];
	TBLIDX			mapName;		// town name textalltblidx
	BYTE			byReceiveHour;	// ��û�����۽ð�
	BYTE			byReceiveMinute; // ��û�����ۺ�
	BYTE			byRepeatType;	// ��û��� ���� �ݺ� ��� eDBO_DOJO_REPEAT_TYPE
	BYTE			byRepeatTime;	// ��û�������� ������ �ݺ��Ǵ� ���� �ð� -> �ݺ�Ÿ���� �ð��ϰ�츸 ���
	WORD			wWeekBitFlag;   // ��û��� ���� ���� -> ������ �����Ͽ� �����ѳ� eDBO_DOJO_WEEK_BITFLAG
	BYTE			byReceiveDuration; // ���۽ð����� ��û������ �ð� �� �� 30��
	BYTE			byRejectDuration;  // ���۽ð� ���� �źΰ����� �ð� �� �� 20��
	BYTE			byStandbyDuration; // ��Ż�� �غ������ ���ۺ��� ����Ǵ� �Ⱓ �� �� 20��
	BYTE			byInitialDuration; // ��Ż�� �غ���� ���� �������� ���� �ʱ�ȭ ���°� ����Ǵ� �Ⱓ �� 7��
	BYTE			byReadyDuration;   // �ʱ�ȭ���� ���� �ð� ��3��
	BYTE			byBattleDuration;  // ��Ż�� ������ �Ϸ������ �ִ� �ð�
	DWORD			dwReceivePoint;
	DWORD			dwReceiveZenny;
	TBLIDX			controllerTblidx;
	DWORD			dwBattlePointGoal;
	DWORD			dwBattlePointGet;
	DWORD			dwBattlePointCharge;
	DWORD			dwChargePointGoal;
	DWORD			dwChargeTime;
	DWORD			dwChageTimePoint;
	TBLIDX			rockTblidx;
	sDOJO_REWARD	asRawrd[DOJO_MAX_REWARD_TYPE_COUNT];


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
class CDojoTable : public CTable
{
public:

	CDojoTable( void );

	virtual ~CDojoTable( void );

public:

	virtual bool			LoadFromBinary(CNtlSerializer& serializer, bool bReload, bool bUpdate);

	virtual bool			SaveToBinary(CNtlSerializer& serializer);

public:

	bool					Create( DWORD dwCodePage );

	void					Destroy( void );

public:

	sTBLDAT*				FindData(TBLIDX tblidx); 

	sTBLDAT*				GetDojoData(); 

	bool					IsWorldDojo( TBLIDX worldIdx );

	TBLIDX					GetTblidxByWorldIdx(TBLIDX worldIdx );

	sDOJO_TBLDAT*			GetDojoByMapName(TBLIDX mapname);

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
