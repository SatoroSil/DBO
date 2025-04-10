#pragma once

#include "NtlSharedType.h"
#include "NtlAdmin.h"
#include "NtlVector.h"
#include <string>


BYTE GetIP( int nIP, BYTE byIndex );// [4/29/2008 SGpro]
std::string GetIP( int nIP );// [4/29/2008 SGpro]
int GetIP( std::string strIP );

//-----------------------------------------------------
// define

// �ִ� �ֱ��� ���� ����
const int NTL_REPEAT_NOTICE_MAX_COUNT = 64;

// �ֱ��� ������ �ִ� ����(multi byte) : ������ ������ �ΰ��� �̷������ ������ ���̴� �ϳ��� ���忡 ���� �ִ� ���̴�.(Multi Byte �����̴�)
const int NTL_REPEAT_NOTICE_MAX_STRING_LENGTH_MB = 64;

// �ð� ���ڿ��� �ִ� ����
const int NTL_GM_TOOL_MAX_DATE_STRING_LENGTH = 31;


// �˻� Ÿ��
enum eTOOL_SERACH_TYPE
{
	NTL_TOOL_SERACH_TYPE_ACCOUNTID = 0,
	NTL_TOOL_SERACH_TYPE_USERNAME,
	NTL_TOOL_SERACH_TYPE_CHARID,
	NTL_TOOL_SERACH_TYPE_CHARNAME,

	NTL_TOOL_SERACH_TYPE_FIRST = NTL_TOOL_SERACH_TYPE_ACCOUNTID,
	NTL_TOOL_SERACH_TYPE_LAST = NTL_TOOL_SERACH_TYPE_CHARNAME
};


// KICK_INFO ������ ���Ÿ��
enum eKICK_INFO_USE_TYPE
{
	KICK_INFO_USE_TOOL_PUBLIC_SEARCH_DATA,		// ������ ���� �˻� â�� �����ͷ� ���
};


// SM_SEARCH_ACCOUNTID_REQ ������ ��� Ÿ��
enum eGM_ACCOUNTID_INFO_USE_TYPE
{
	GM_ACCOUNTID_INFO_USE_CREATE_GM,			// GM�� �����Ҷ� ���
	GM_ACCOUNTID_INFO_USE_CONNECT_GM_ACCOUNTID,	// GM�� AccountID�� ������ �� ���
	GM_ACCOUNTID_INFO_USE_MODIFY_GM,
};


// GM Tool Authority TYPE
enum eGM_TOOL_AUTH_TYPE
{
	GM_TOOL_AUTH_SEARCH,					// ĳ���� �˻�

	GM_TOOL_AUTH_CHAR_INFO,					// ĳ���� ����
	GM_TOOL_AUTH_CHAR_INFO_CHANGE,			// ĳ���� ���� ����
	GM_TOOL_AUTH_CHAR_NAME_CHANGE,			// ĳ���͸� ����

	GM_TOOL_AUTH_MAIL_LIST,					// ���� ���� ��ȸ
	GM_TOOL_AUTH_MAIL_CONTENTSEE,			// ���� ���� ���� ��ȸ
	GM_TOOL_AUTH_MAIL_ITEMSEE,				// ���� ������ ���� ��ȸ
	GM_TOOL_AUTH_MAIL_DELETE,				// ���� ����


	GM_TOOL_AUTH_ITEM_INFO,					// ������ ����
	GM_TOOL_AUTH_ITEM_CREATE,				// ������ ����/����

	GM_TOOL_AUTH_QUEST_INFO,				// ����Ʈ ����
	GM_TOOL_AUTH_QUEST_CHANGE,				// ����Ʈ ����(����)

	GM_TOOL_AUTH_PUNISH_INFO,				// ���� ����
	GM_TOOL_AUTH_PUNISH_CONNECTION,			// ���� ���� ���� �� ����
	GM_TOOL_AUTH_PUNISH_FUNCTION,			// ��� ���� ���� �� ����
	GM_TOOL_AUTH_PUNISH_CHAR_NAME_CHANGE,	// ĳ���� �̸� ����(����)

	GM_TOOL_AUTH_GUILD_INFO,				// ���� ���� ��ȸ
	GM_TOOL_AUTH_GUILD_UPDATE,				// ���� ���� ����
	GM_TOOL_AUTH_GUILD_ITEM_DELETE,			// ������ ����

	GM_TOOL_AUTH_NOTICE_REPEAT_INFO,		// �ݺ� ���� ����
	GM_TOOL_AUTH_NOTICE_REPEAT,				// �ݺ� ���� ����
	GM_TOOL_AUTH_NOTICE_REALTIME,			// �ǽð� ���� ����

	GM_TOOL_AUTH_SVRSTATUS_INFO,			// ���� ���� ����
	GM_TOOL_AUTH_SVRSTATUS_CHANGE,			// ���� ���� ����
	GM_TOOL_AUTH_SVRSTATUS_SERVERONOFF_CHANGE,			// ���� ���� ����

	//GM_TOOL_PETITION_1,						// PETITION

	GM_TOOL_AUTH_GM_INFO,					// GM ��ȸ
	GM_TOOL_AUTH_GM_CREATE,					// GM ����
	GM_TOOL_AUTH_GM_CHANGE,					// GM ����
	GM_TOOL_AUTH_GM_DELETE,					// GM ����

	GM_TOOL_AUTH_GROUP_INFO,				// �׷� ��ȸ
	GM_TOOL_AUTH_GROUP_CREATE,				// �׷� �߰�/����
	GM_TOOL_AUTH_GROUP_AUTH_CHANGE,			// �׷� ���� ����
	GM_TOOL_AUTH_GROUP_LEVEL_CHANGE,		// �׷� ���� ����

	GM_TOOL_AUTH_FILTERING_INFO,			// ���͸� ��ȸ
	GM_TOOL_AUTH_FILTERING_CREATE,			// �߰�/����/����
	GM_TOOL_AUTH_CHANGE_CHARNAME_FILTERINGISNOT,		//���͸� ���� ����

	GM_TOOL_GM_COMMAND_USE,					// GM ��ɾ� ��� [7/1/2008 SGpro]

	// ���ο� ������ �߰� �� ��쿡�� ���� �Ʒ��ʿ� �߰� �ؾ� �Ѵ�.
	// ���� ���� ���̿� ���� ������� DB�� ������ Ʋ������ �ǹǷ� �����Ѵ�.

	GM_TOOL_AUTH_COUNT,
	GM_TOOL_AUTH_INVALID = INVALID_BYTE
};

//--------------------------------------------------------------------------------------------------
//

// SM_SEARCH_PC_DATA_REQ, MS_SEARCH_PC_DATA_RES ���������� � �뵵�� ����ϴ����� �з�
enum eSEARCH_USE_TYPE
{
	 SEARCH_USE_SEARCH_PAGE = 0			// �˻� ���������� ���
	,SEARCH_USE_PUBLIC_SEARCH_DATA		// ���� �˻� ���� ������Ʈ�� ���

	,SEARCH_USE_TYPE_COUNT
	,INVALID_SEARCH_USE_TYPE = -1
};

//--------------------------------------------------------------------------------------------------
//

// CQuery_GMLoginInfoLoad �� � �뵵�� �������� �з�
enum eLOGIN_INFO_USE_TYPE
{
	LOGIN_INFO_USE_PUNISHMENT,					// ���翡�� ���
	LOGIN_INFO_USE_TOOL_PUBLIC_SEARCH_DATA,		// ������ ���� �˻� â�� �����ͷ� ���
};


// �ֱ��� ���� : Visible
enum eGM_REPEAT_NOTICE_VISIBLE_TYPE
{
	GM_REPEAT_NOTICE_DISABLE = 0,
	GM_REPEAT_NOTICE_ENABLE
};



#pragma pack(1)

// 
struct sLOGIN_INFO_USE_PUNISHMENT
{
	ACCOUNTID				accountID;		  // Target AccountID
	CHARACTERID				charID;		  // target CharID 	
	BYTE					byPunishType;	  // Punish Type
	DWORD					dwPeriod;  // How Many Day or Minutes
	bool					bDateOption;	  // 0: Day 1: Minutes 
	bool					bIsOn;

	BYTE					byReasonType;
	
};


struct sLOGIN_INFO_USE_SUBDATA
{
	eLOGIN_INFO_USE_TYPE eType;		// ���� ��û�� �� ���� Ÿ���� ����

	union
	{
		sLOGIN_INFO_USE_PUNISHMENT			sUsePunishment;		// LOGIN_INFO_USE_PUNISHMENT �϶� ���
	};
};

//
//---------------------------------------------------------------------------------------------------------
//

// KICK ����
struct sKICK_INFO_USE_SUBDATA
{
	eKICK_INFO_USE_TYPE eType;		// ���� ��û�� �� ���� Ÿ���� ����
};	

//
//--------------------------------------------------------------------------------------------------------



// ������ �̸�
struct sSERVERFARM_NAME
{
	SERVERFARMID	serverFarmId;
	WCHAR			wszServerFarmName[NTL_MAX_SIZE_SERVER_FARM_NAME_UNICODE + 1];
};


// �Ѹ� ���� ����
struct sCHARSEARCH_ENTITY
{
	SERVERFARMID	serverFarmId;										// ������ ���̵�
	ACCOUNTID		accountID;											// User Serial
	WCHAR			wszUserID[NTL_MAX_SIZE_USERID + 1];		// User ID
	CHARACTERID		charID;												// Character Serial
	WCHAR			wszCharName[NTL_MAX_SIZE_CHAR_NAME + 1];	// Character Name
	BYTE			byLevel;
	BYTE			byRace;												// Race
	BYTE			byClass;											// Class
	BYTE			byGender;											// Gender
	BYTE			byDelType;											// ������ ĳ���� eDEL_TYPE - NtlCharacter.h [6/23/2008 SGpro]
	sDBO_TIME		tmCreateTime;										// ĳ���� ������ [6/23/2008 SGpro]
	sDBO_TIME		tmDeleteTime;										// ĳ���� ������ [6/23/2008 SGpro]
};


// Server Status
struct sSERVERSTATUS_ENTITY
{
	bool				bIsOn;					// on / off
	DWORD				dwMaxLoad;				// �ִ� ���ġ ����Ʈ��
	DWORD				dwLoad;					// ���� ������ ��
	DWORD				dwProcessUsage;			// Process Usage
	DWORD				dwSystemUsage;			// System Usage
	DWORD				dwMemoryUsage;			// Memory Usage
	DWORD				dwRecvQuery;			// During Queue Recieved Query
	DWORD				dwEndQuery;				// During Queue Ended Query
	DWORD				dwCurQuery;				// Current time Queue Query Count
	DWORD				dwPing;					// itzrnb

	BYTE				byServerType;		// eNtlServerType
	SERVERFARMID		serverFarmId;
	BYTE				byServerChannelIndex;
	BYTE				byServerIndex;
	char				achInternalAddress[NTL_MAX_LENGTH_OF_IP + 1];
	char				achExternalAddress[NTL_MAX_LENGTH_OF_IP + 1];
};

// Server Group Status [11/20/2007 SGpro]
struct sSERVERGROUPSTATUS_ENTITY
{
	BYTE				byServerGroupType; // eNtlServerGroupType
	SERVERFARMID		serverFarmId;
	BYTE				byServerChannelIndex;
	bool				bIsLock; //Lock & UnLock ���θ� ����
};


//------------------------------------------------------------------------------------------
// Punishment

// 
enum ePUNISH_APPLY_TYPE
{
	PUNISH_APPLY_OFF,		// ����
	PUNISH_APPLY_ON,		// ����
};


// ���� �ð� ����
enum ePUNISH_PERIOD_TYPE
{
	PUNISH_PERIOD_DAY,		// ��
	PUNISH_PERIOD_MINUTE,	// ��
	// PUNISH_PERIOD_NONE,		// �����ϼ��� [ by sooshia 07/17/2008 UI�� ���°� ���ٰ� �Ͽ� ������ ]

	PUNISH_PERIOD_COUNT
};


// ���� �⺻ ����
struct sPUNISHMENT_ENTITY
{
	SERVERFARMID			serverFarmID;
	ACCOUNTID				accountID;								//
	CHARACTERID				characterID;							//
	BYTE					byPunishType;							// enum ePUNISH_QUERY
	bool					bDateOption;							// 0: Day 1: Minutes 
	DWORD					dwPunishAmount;							// How Many Day or Minutes
	WCHAR					awchAccount[NTL_MAX_SIZE_USERID + 1]; // [7/16/2008 SGpro]
	WCHAR					awchName[NTL_MAX_SIZE_CHAR_NAME + 1]; // [7/16/2008 SGpro]

	// Apply
	WCHAR					wszApplyTime[NTL_GM_TOOL_MAX_DATE_STRING_LENGTH];
	WCHAR				    wchApplyGMName[NTL_MAX_SIZE_CHAR_NAME + 1];	// GM Char Name
	BYTE					byPunishReason;

	// Release
	WCHAR					wszReleaseTime[NTL_GM_TOOL_MAX_DATE_STRING_LENGTH];
	WCHAR				    wchReleaseGMName[NTL_MAX_SIZE_CHAR_NAME + 1];	// GM Char Name
	BYTE					byReleaseReason;

	// Is Active?
	bool					bActive;
};



//--------------------------------------------------------------------------------------------------------------
// GM Registration

// GM �˻� Ÿ��
enum eGM_SEARCH_TYPE
{
	eGM_SEARCH_GROUP = 0,
	eGM_SEARCH_GMID,

	eGM_SEARCH_COUNT,
	eINVALID_GM_SEARCH_TYPE = 255
};

// IP Address
union uGM_TOOL_IP_ADDRESS
{
	int				nIP;
	unsigned char	achIP[4];
};


// GM ����
struct sGM_ENTITY
{
	ACCOUNTID				gmAccountID;											// User Account ID
	WCHAR					wszUserID[NTL_MAX_SIZE_USERID + 1];				// User ID
	ACCOUNTID				accountID;												// Game Server������ GM AccountID
	DWORD					dwGroupSerial;											// Group
	uGM_TOOL_IP_ADDRESS		uAllowIP;												// ���� ������ IP

	WCHAR					wszGMName[NTL_MAX_SIZE_CHAR_NAME + 1];// ���� ��Ȳ�� GM �̸�
};



// GM Tool Authority
struct sGM_TOOL_AUTH_FLAG
{
	char achAuth[NTL_MAX_SIZE_TOOL_AUTH];
};


// GM Command Authority
struct sGM_COMMAND_AUTH_FLAG
{

	char achAuth[NTL_MAX_SIZE_COMMAND_AUTH];
};

// GM Etc Authority
struct sGM_ETC_AUTH_FLAG
{

	char achAuth[NTL_MAX_SIZE_ETC_AUTH];
};



//------------------------------------------------------------------------------
// ����

struct sGM_REPEAT_NOTICE_ENTITY
{
	DWORD				dwSerial;			// = System Tool���� ���� �߰� ��û�� INVALID_DWORD ������ ����
	BYTE				byEnable;			// eGM_REPEAT_NOTICE_VISIBLE_TYPE
	SERVERFARMID		serverFarmID;
	BYTE				channelID;
	BYTE				byNoticeType;		// eSERVER_TEXT_TYPE
	INT64				nStartTime;
	INT64				nEndTime;
	WORD				wNoticeTerm;		// ���� �� : �д���
	WCHAR				wszNotice[NTL_MAX_LENGTH_OF_CHAT_MESSAGE+1];
};

struct sGM_ACCOUNT_COMMENT
{
	ACCOUNTID			accountID;		
	WCHAR				wszComment[NTL_MAX_LENGTH_OF_CHAT_MESSAGE+1];
};

//���� ��Ŷ��
struct sGM_PACKET_ACCOUNT_COMMENT
{
	ACCOUNTID			accountID;
	unsigned __int16	nCommentSize;
	WCHAR				wszComment[NTL_MAX_LENGTH_OF_CHAT_MESSAGE+1];
};

// �˻� Ÿ�� [4/22/2008 SGpro]
enum eTOOL_GUILD_SERACH_TYPE
{
	NTL_TOOL_GUILD_SERACH_TYPE_GUILDNAME = 0,
	NTL_TOOL_GUILD_SERACH_TYPE_MASTERNAME,
	NTL_TOOL_GUILD_SERACH_TYPE_ALLSEARCH,

	NTL_TOOL_GUILD_SERACH_TYPE_FIRST = NTL_TOOL_GUILD_SERACH_TYPE_GUILDNAME,
	NTL_TOOL_GUILD_SERACH_TYPE_LAST = NTL_TOOL_GUILD_SERACH_TYPE_ALLSEARCH
};

#pragma pack()
