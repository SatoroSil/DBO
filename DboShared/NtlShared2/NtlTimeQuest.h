//***********************************************************************************
//
//	File		:	NtlTimeQuest.h
//
//	Begin		:	2007-05-31
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Hyun Woo, Koo   ( zeroera@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#pragma once

#include "NtlParty.h"
#include "NtlTSCoreDefine.h"

#include "NtlBitFlag.h"


//-----------------------------------------------------------------------------------
// Enumeration
//-----------------------------------------------------------------------------------

// Ÿ�Ӹӽ� Ÿ��
enum eTIMEQUEST_TYPE
{
	TIMEQUEST_TYPE_TUTORIAL, // Ʃ�丮�� Ÿ�� ����Ʈ ( ������ �������� �ʴ´� )
	TIMEQUEST_TYPE_PARTY, // ��Ƽ�� Ÿ�� ����Ʈ
	TIMEQUEST_TYPE_GROUP, // �׷��� Ÿ�� ����Ʈ

	MAX_TIMEQUEST_TYPE,
};


// Ÿ�Ӹӽ� ���
enum eTIMEQUEST_MODE
{
	TIMEQUEST_MODE_INDIVIDUAL, // ���ε���� ���
	TIMEQUEST_MODE_PARTY, // ��Ƽ����� ���

	MAX_TIMEQUEST_MODE,
	INVALID_TIMEQUEST_MODE = 0xFF, // ���� ����� �ȵǾ��� ���
};

// Game Time Machine condition
enum eTIMEQUEST_GAME_STATE
{
	TIMEQUEST_GAME_STATE_WAIT, // Generate and TMQ player enters standby
	TIMEQUEST_GAME_STATE_PREPARE, // After checking the condition after all players decide whether entry
	TIMEQUEST_GAME_STATE_ARRIVE, // TMQ arrival status (waiting for TS event from the user waiting time event appears)
	TIMEQUEST_GAME_STATE_BEGIN, // Starting the game (script controlled)
	TIMEQUEST_GAME_STATE_STAGE_READY, // Stage preparation (script controlled)
	TIMEQUEST_GAME_STATE_STAGE_START, // Starting Stage (script controlled)
	TIMEQUEST_GAME_STATE_STAGE_FINISH, // Stage exit (script controlled)
	TIMEQUEST_GAME_STATE_END, // End Game
	TIMEQUEST_GAME_STATE_LEAVE, // Exit TMQ State
	TIMEQUEST_GAME_STATE_FAIL, // The game ends (TMQ failure)
	TIMEQUEST_GAME_STATE_CLOSE, // TMQ exit

	MAX_TIMEQUEST_GAME_STATE
};


// Stage Time Machine condition
enum eTIMEQUEST_STAGE_STATE
{

	MAX_TIMEQUEST_STAGE_STATE
};


//Time Machine Difficulty
enum eTIMEQUEST_DIFFICULTY
{
	TIMEQUEST_DIFFICULTY_EASY,
	TIMEQUEST_DIFFICULTY_NORMAL,
	TIMEQUEST_DIFFICULTY_HARD,

	MAX_TIMEQUEST_DIFFICULTY,

	FIRST_TIMEQUEST_DIFFICULTY = TIMEQUEST_DIFFICULTY_NORMAL,
	INVALID_TIMEQUEST_DIFFICULTY = 0xFF,
};


// Time Machine Difficulty flag
enum eTIMEQUEST_DIFFICULTY_FLAG
{
	TIMEQUEST_DIFFICULTY_FLAG_EASY = MAKE_BIT_FLAG(TIMEQUEST_DIFFICULTY_EASY),
	TIMEQUEST_DIFFICULTY_FLAG_NORMAL	= MAKE_BIT_FLAG( TIMEQUEST_DIFFICULTY_NORMAL ),
	TIMEQUEST_DIFFICULTY_FLAG_HARD		= MAKE_BIT_FLAG( TIMEQUEST_DIFFICULTY_HARD ),
};


// Time Machine-progress message type
enum eTIMEQUEST_PROGRESS_MESSAGE_TYPE
{
	TIMEQUEST_PROGRESS_MESSAGE_TYPE_START,
	TIMEQUEST_PROGRESS_MESSAGE_TYPE_END,
	TIMEQUEST_PROGRESS_MESSAGE_TYPE_CLEAR,
	TIMEQUEST_PROGRESS_MESSAGE_TYPE_FAIL,

	MAX_TIMEQUEST_PROGRESS_MESSAGE_TYPE,
	INVALID_TIMEQUEST_PROGRESS_MESSAGE_TYPE = 0xFF,
};


// Time Quest Information Output Type
enum eTIMEQUEST_INFORMATION_TYPE
{
	TIMEQUEST_INFORMATION_TYPE_SCENARIO,
	TIMEQUEST_INFORMATION_TYPE_STAGE,

	MAX_TIMEQUEST_INFORMATION_TYPE,
	INVALID_TIMEQUEST_INFORMATION_TYPE = 0xFF,
};


//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
//	��� ����
//-----------------------------------------------------------------------------------
const DWORD		DBO_TIMEQUEST_MAX_ROOM_COUNT = 10; // Ÿ�Ӹӽ� �ʴ� ���� �ִ� ����

const DWORD		DBO_TIMEQUEST_MAX_MEMBER_COUNT = NTL_MAX_MEMBER_IN_PARTY; // Ÿ�Ӹӽ� �ִ� ��� �ο�

const DWORD		DBO_TIMEQUEST_ROOM_START_REPORT_TIME = 30000; // Ÿ�Ӹӽ� ��� �˸��� �����ִ� �ð�

const DWORD		DBO_TIMEQUEST_ROOM_LEAVE_LIMIT_TIME = 60000; // Ÿ�Ӹӽ� ���뿡�� ������ ���ϴ� �ð�

const DWORD		DBO_TIMEQUEST_MAX_STAGE_NUMBER = 64; // Ÿ�Ӹӽ� ����Ʈ�� �ִ� ��������

const DWORD		DBO_TIMEQUEST_MAX_KILL_COUNT = 3; // Ÿ�Ӹӽ� ����Ʈ�� �ִ� ųī��Ʈ (�Ѿ�� �ڵ� ����)

const DWORD		DBO_TIMEQUEST_ROOM_REFRESH_TIME = 10000; // Ÿ�Ӹӽ� ����Ʈ�� ������ �������� �ð�

const WORD		DBO_TIMEQUEST_COUNPON_CHANGE_POINT = 1000; // ���� 1������ ��ȯ�Ǵ� Ÿ������Ʈ ����Ʈ����

const WORD		DBO_TIMEQUEST_COUNPON_LIMIT_COUNT = 4; // ������ �ִ� �ִ� ���� ����

const WORD		DBO_TIMEQUEST_DEFAULT_DAYRECORD_RANK_COUNT = 6;	// tblidx�� ���̵� ���� ����� rank�� ���� //old 5

const WORD		DBO_TIMEQUEST_DEFAULT_TOTAL_RANK_COUNT = DBO_TIMEQUEST_DEFAULT_DAYRECORD_RANK_COUNT + 1;	// tblidx�� ���̵� ���� ����� rank�� ���� �� BestRecord +

const DWORD		DBO_TIMEQUEST_MAX_LIMIT_COUNT = 10;

const DWORD		DBO_TIMEQUEST_MAX_LIMIT_PLUS_COUNT = 10;

//-----------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
#pragma pack( 1 )

// Ÿ�Ӹӽ� ����Ʈ ���� ����
struct sTIMEQUEST_STAGE
{
	BYTE					byStageNumber; // �������� ��ȣ
};


// Ÿ�Ӹӽ� ����Ʈ ���� ����
struct sTIMEQUEST_STATE
{
	BYTE					byGameState; // eTIMEQUEST_GAME_STATE
	sTIMEQUEST_STAGE		sTimeQuestStage;
};


// Ÿ������Ʈ ���� ����
struct sTIMEQUEST_RULE_INFO
{
	TBLIDX					timeQuestTblidx; // �ش� Ÿ�� ����Ʈ ���̺� �ε���
	BYTE					byStartHour; // ���۽ð� (��)
	BYTE					byStartMin; // ���۽ð� (��)
	BYTE					byTimeQuestMode; // eTIMEQUEST_MODE
	BYTE					byDifficulty; // eTIMEQUEST_DIFFICULTY
	bool					bCountDown; // ī��Ʈ �ٿ� ����
//	DWORD					dwLimitTime; // ���� �ð�
//	DWORD					dwBonusTime; // ���ʽ� �ð�
//	DWORD					dwDayRecord; // �ش� Ÿ������Ʈ�� DayRecord
	sTIMEQUEST_STATE		sTimeQuestState;
};


// TMQ ���� ����ϴ� �ð� ���� ����
struct sTIMEQUEST_TIME
{
	// ���� ��� �ð��� ���
	void	NextTime(BYTE byTermMinute)
	{
		byHour = byHour + (BYTE)(byTermMinute / 60);
		byMinute += byTermMinute % 60;

		if( 60 <= byMinute)
		{
			byMinute -= 60;
			byHour++;
		}

		if(24 < byHour)
		{
			byHour -= 24;
		}
	}

	void	NextBySec(DWORD dwTermSec)
	{
		NextTime( (BYTE)(dwTermSec / 60));
	}

	BYTE	byHour;
	BYTE	byMinute;
};



//-----------------------------------------------------------------------------
// Protocol ������ ����Ѵ�


struct sTIMEQUEST_DAYRECORD_DATA
{
	BYTE		byDifficult;
	DWORD		dwClearTime;
	BYTE		byMemberCount;
	CHARACTERID	aMemberCharId[NTL_MAX_MEMBER_IN_PARTY];
};


//--------------------------------------------
// Query Server <-> Game Server
struct sTIMEQUEST_TEAM_DATA
{
	DWORD				dwClearTime;	// clear time
	BYTE				byMode;			// eTIMEQUEST_MODE
	WCHAR				wszPartyName[NTL_MAX_SIZE_PARTY_NAME];
	BYTE				byMemberCount;
	WCHAR				awszMember[NTL_MAX_MEMBER_IN_PARTY][NTL_MAX_SIZE_CHAR_NAME + 1];
};

struct sTIMEQUEST_MEMBER_DATA
{
	CHARACTERID			charId;
	WCHAR				wszName[NTL_MAX_SIZE_CHAR_NAME + 1];
};

//------------------------------------------------------------------
struct sTIMEQUEST_PARTY_MEMBER_DATA
{
	BYTE				byLevel;
	BYTE				byClass;
	WCHAR				wszName[NTL_MAX_SIZE_CHAR_NAME + 1];
};
	
struct sTIMEQUEST_TEAM_RANK_DATA
{
	DWORD				dwClearTime;	// clear time
	BYTE				byMode;			// eTIMEQUEST_MODE
	WCHAR				wszPartyName[NTL_MAX_SIZE_PARTY_NAME];
};

struct sTIMEQUEST_TEAM_MEMBER_DATA
{
	BYTE							byMemberCount;
	sTIMEQUEST_PARTY_MEMBER_DATA	asMember[NTL_MAX_MEMBER_IN_PARTY];
};


//----------------------------------------------
// Game Server <-> Client

struct sTIMEQUEST_MEMBER_VAR
{
	WORD		wName;		// WCHAR[NTL_MAX_SIZE_CHAR_NAME]
	CHARACTERID	charId;
};

struct sTIMEQUEST_TEAM_VAR
{
	DWORD				dwClearTime;	// clear time
	WORD				wPartyName;		// WCHAR [NTL_MAX_SIZE_PARTY_NAME];
	BYTE				byMemberCount;
	WORD				wMember;		// sTIMEQUEST_MEMBER [NTL_MAX_MEMBER_IN_PARTY];
};




//-----------------------------------------------------------------------------
//	index - data�� ��ġ
//	[ 1byte | .... ] [ 2byte | .... ] [ 2byte | .... ] [ 1byte | .... ]
//  [ size  | data ] [ size  | data ] [ size  | data ] [ size  | data ]
//  size: 1 ~ 2byte first bit of the first byte is a bit for checking whether the size is beyond 127

struct sVARIABLE_DATA
{
protected:
	WORD	wReserveSize;
	WORD	wOffset;			// The new position and size of the data into the data
	BYTE	abyData[2048];

public:
	sVARIABLE_DATA() : wOffset(0), wReserveSize(1){}						// It should be used only in the protocol.
	sVARIABLE_DATA(WORD wReserve) : wOffset(0)
	{
		Init( wReserve );
	}
	~sVARIABLE_DATA() {}

	void Init( WORD wReserve )
	{
		wOffset = 0;

		if( wReserve >= 4096/*PACKET_MAX_SIZE*/ )
		{
			_ASSERT(0);

			wReserveSize = 0;
			return;
		}

		wReserveSize = wReserve;

		::memset( abyData, 0xff, sizeof(BYTE) * wReserve );
	}


	// When using a function to facilitate the initialization packet (packet using the specialized function)
	void InitPacketSize( WORD wDefaultPacketSize )
	{
		wOffset = 0;

		wReserveSize = 4096/*PACKET_MAX_SIZE*/ - wDefaultPacketSize + sizeof(BYTE);

		if( wReserveSize >= 4096/*PACKET_MAX_SIZE*/ )
		{
			_ASSERT(0);

			wReserveSize = 0;
			return;
		}

		::memset( abyData, 0xff, sizeof(BYTE) * wReserveSize );
	}


	// Functions to easily calculate the size of the packet using the packet (the packet using specialized function)
	WORD GetPacketSize( WORD wDefaultPacketSize ) { return wDefaultPacketSize - sizeof(BYTE) + GetDataSize(); }


	// The total size of sVARIABLE_DAT: offset + sizeof (sVARIABLE_DATA) - abyData[1] Size
	WORD GetTotalSize() { return wOffset + sizeof(sVARIABLE_DATA) - sizeof(BYTE);}
	// Size of Data
	WORD GetDataSize() { return wOffset;}

	// Set the size of reservations (no cracking when converting the amount of physical memory. This value indicates an external Since when creating or generating).
//	void SetReserveSize(WORD wReserve) { wReserveSize = wReserve; }
	WORD GetReserveSize() { return wReserveSize;}

	void WriteLock() { wReserveSize = GetDataSize(); }


	// Copy Data.
	void __SetData( WORD wOff, BYTE * pData)
	{
		wOffset = wOff;
		::memcpy( abyData, pData, wOff);
	}

	// pData: location, wReserverSize copying: Actual size of available storage space (free space)
	bool CopyTo( sVARIABLE_DATA * pData, WORD wReserve)
	{
		if(NULL == pData)
		{
			return false;
		}

		if(wReserve < GetDataSize())
		{
			return false;
		}

		pData->__SetData( wOffset, abyData);
		pData->WriteLock();

		return true;
	}


	//-----------------------------------------------------------------------------------
	//	Purpose	: If less than 127 stores and a separate large or equal to 127
	//			 The first bit of the size of the display does not exceed the size of the character data exceeding the 127
	//			  The total size does not exceed the 15 th power of 2.
	//	Return	: 
	//-----------------------------------------------------------------------------------
	WORD Write( WORD wSize, void * pData)
	{
		WORD wTemp = wOffset;

		if( 127 >= wSize)	// If the length is less than or equal to 127
		{
			// Check whether there is enough space reserved
			if( wOffset + wSize + 1 > wReserveSize)
			{
				return INVALID_WORD;
			}


			// write
			abyData[wOffset] = (BYTE)wSize;
			::memcpy( &(abyData[wOffset + 1]), pData, wSize);

			// offset adjustment
			wOffset += wSize + 1;
		}
		else				// If a length greater than 127-type size to save WORD
		{
			// Check whether there is enough space reserved
			if( wOffset + wSize + 2 > wReserveSize)
			{
				return INVALID_WORD;
			}

			// write
			abyData[wOffset] = (BYTE)((wSize % 0x80) | 0x80);	// The first byte
			abyData[wOffset+1] = (BYTE)(wSize >> 7);			// The second byte

			::memcpy( &(abyData[wOffset + 2]), pData, wSize);

			// offset adjustment
			wOffset += wSize + 2;
		}

		return wTemp;
	}


	//-----------------------------------------------------------------------------------
	//	Purpose	: If less than 127 stores and a separate large or equal to 127
	//			  The first bit of the size of the display does not exceed the size of the character data exceeding the 127
	//			  The total size does not exceed the 15 th power of 2.
	//	Return	: Allocate a memory size enough wSize and returns the offset.
	//			  (Memory allocation is the same as Write (), but not write any value to the allocated memory.)
	//-----------------------------------------------------------------------------------
	WORD Malloc( WORD wSize)
	{
		WORD wTemp = wOffset;

		if( 127 >= wSize)	// If the length is less than or equal to 127
		{
			// Check whether there is enough space reserved
			if( wOffset + wSize + 1 > wReserveSize)
			{
				return INVALID_WORD;
			}


			// write
			abyData[wOffset] = (BYTE)wSize;

			// offset adjustment
			wOffset += wSize + 1;
		}
		else				//If a length greater than 127-type size to save WORD
		{
			// Check whether there is enough space reserved
			if( wOffset + wSize + 2 > wReserveSize)
			{
				return INVALID_WORD;
			}

			// write
			abyData[wOffset] = (BYTE)((wSize % 0x80) | 0x80);	// The first byte
			abyData[wOffset+1] = (BYTE)(wSize >> 7);			// The second byte

			// offset adjustment
			wOffset += wSize + 2;
		}

		return wTemp;
	}


	//-----------------------------------------------------------------------------------
	//	Purpose	: wReadLoc�� ��ġ�� Data�� ũ�⸦ ��ȯ
	//	Return	: 
	//-----------------------------------------------------------------------------------
	WORD GetSize( WORD wReadLoc)
	{
		if( wReadLoc >= wOffset)
		{
			return 0;
		}

		// ũ�Ⱑ 127�� �Ѵ� ���
		if( 0x80 & abyData[wReadLoc])
		{
			// ũ�Ⱑ ����� ��ġ�� ��ȿ���� üũ(2byte �� ����ϹǷ�)
			if(wReadLoc + 1 >= wOffset)
			{
				return 0;
			}

			// get size
			WORD wSize = (abyData[wReadLoc] & 0x7f) + (abyData[wReadLoc + 1] << 7);

			// ����� ũ��� ����� �������� ũ�Ⱑ ��ȿ���� üũ
			if(wReadLoc + wSize + 2 > wOffset)
			{
				return 0;
			}

			return wSize;
		}
		// ũ�Ⱑ 127�� ���� �ʴ� ���
		else								
		{
			// ����� ũ��� ����� �������� ũ�Ⱑ ��ȿ���� üũ
			if(wReadLoc + abyData[wReadLoc] + 1 > wOffset)
			{
				return 0;
			}

			return abyData[wReadLoc];
		}
	}


	//-----------------------------------------------------------------------------------
	//	Purpose	: wReadLoc�� ��ġ�� Data�� pData�� �����Ѵ�.
	//	Return	: 
	//-----------------------------------------------------------------------------------
	bool Read( WORD wReadLoc, void * pData)
	{
		// ũ�⸦ �����ϴ� ������ ��ȿ���� üũ
		if( wReadLoc >= wOffset)
		{
			return false;
		}

		// ũ�Ⱑ 127�� �Ѵ� ���
		if( 0x80 & abyData[wReadLoc])
		{
			// ũ�⸦ �����ϴ� ������ ��ȿ���� üũ(2byte �� ����ϹǷ�)
			if(wReadLoc + 1 >= wOffset)
			{
				return false;
			}

			// get size
			WORD wSize = (abyData[wReadLoc] & 0x7f) + (abyData[wReadLoc + 1] << 7);

			// �����͸� �����ϴ� ������ ��ȿ���� üũ
			if(wReadLoc + wSize + 2 > wOffset )
			{
				return false;
			}

			// copy
			::memcpy( pData, &(abyData[wReadLoc + 2]), wSize);
		}
		// ũ�Ⱑ 127�� ���� �ʴ� ���
		else
		{
			// �����͸� �����ϴ� ������ ��ȿ���� üũ
			if(wReadLoc + abyData[wReadLoc] + 1 > wOffset)
			{
				return false;
			}

			// copy
			::memcpy( pData, &(abyData[wReadLoc + 1]), abyData[wReadLoc]);
		}

		return true;
	}


	//-----------------------------------------------------------------------------------
	//	Purpose	: wReadLoc�� ��ġ�� Data�� ��ȯ�Ѵ�.
	//	Return	: 
	//-----------------------------------------------------------------------------------
	void * Read( WORD wReadLoc)
	{
		// ũ�⸦ �����ϴ� ������ ��ȿ���� üũ
		if( wReadLoc >= wOffset)
		{
			return NULL;
		}


		// ũ�Ⱑ 127�� �Ѵ� ���
		if( 0x80 & abyData[wReadLoc])
		{
			// ũ�⸦ �����ϴ� ������ ��ȿ���� üũ(2byte �� ����ϹǷ�)
			if(wReadLoc + 1 >= wOffset)
			{
				return NULL;
			}

			// get size
			WORD wSize = (abyData[wReadLoc] & 0x7f) + (abyData[wReadLoc + 1] << 7);

			// �����͸� �����ϴ� ������ ��ȿ������ üũ
			if(wReadLoc + wSize + 2 > wOffset)
			{
				return NULL;
			}

			return &(abyData[wReadLoc + 2]);
		}
		// ũ�Ⱑ 127�� ���� �ʴ� ���
		else
		{
			// �����͸� �����ϴ� ������ ��ȿ������ üũ
			if(wReadLoc + abyData[wReadLoc] + 1 > wOffset)
			{
				return NULL;
			}

			return &(abyData[wReadLoc + 1]);
		} // end if
	} // end void * Read() func
};


#pragma pack()



