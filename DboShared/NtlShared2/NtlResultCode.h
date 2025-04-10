#pragma once

// Auth Server 100~199
// Character Server 200~299
// Community Server 300~399
// Query Server 400~
// Game Server 500~
// Petition System 10000~


enum eRESULTCODE
{
	//-----------------------------------------------------------------
	// Base ( 0 ~ 100 )
	//-----------------------------------------------------------------
	RESULT_SUCCESS = 0,
	RESULT_FAIL,					// �������� ����
	
	RESULT_LAST,					//always last
	//-----------------------------------------------------------------


	//-----------------------------------------------------------------
	// Auth ( 100 ~ 199 )
	//-----------------------------------------------------------------
	AUTH_SUCCESS = 100,				// ������������ ��� ����
	AUTH_FAIL,						// ������������ �������� ����
	AUTH_VERSION_FAIL,              // ���� ����ġ
	AUTH_TOO_LONG_ACCOUNT,          // ���� �̸��� ���̰� �ʰ��Ǿ����ϴ�. 
	AUTH_TOO_LONG_PASSWORD,         // �н������� ���̰� �ʰ��Ǿ����ϴ�. 
	AUTH_AUTHKEY_FAIL,              // ����Ű ������ �����Ͽ����ϴ�.
	AUTH_USER_SAMENAME_EXIST,       // �̹� �������� �����մϴ�. 
	AUTH_WRONG_PASSWORD,            // �н����尡 Ʋ���ϴ�. 
	AUTH_USER_NOT_FOUND,            // �������� �������� �ʽ��ϴ�.
	AUTH_USER_EXIST,                // �̹� �������Դϴ�.
	AUTH_USER_EXIST_IN_CHARACTER_SERVER,		// ĳ���� ������ �̹� �������Դϴ�.
	AUTH_DB_FAIL,					// DB �ε� ����
	AUTH_NO_AVAILABLE_CHARACTER_SERVER,			// ���� ���� ������ ĳ���� ������ �����ϴ�.
	AUTH_USER_BLOCK,				// ������ ��� �Ǿ����ϴ�. �ڼ��� ������ Ȩ�������� �����Ͻʽÿ�.
	AUTH_USER_TEMPORARY_BLOCK,		// ��۾����̶� �����Ͻ� �� �����ϴ�. ��� �� ������ �õ��غ��ʽÿ�.
	AUTH_SERVER_LOCKED,							// ���� ������ ��� ���¿��� ������ �� �����ϴ�.
	AUTH_COMMON_CANT_DO_THAT_FOR_SOME_REASON,			// �ý��� ������ �۾��� ó���� �� �����ϴ�.
	AUTH_IP_BLOCK,					// ��ϵ� IP �Դϴ�. (�κ� ������ �޽���. Ȯ�� ��ư)

	AUTH_RESULT_LAST,			// always last
	//-----------------------------------------------------------------


	//-----------------------------------------------------------------
	// Character ( 200 ~ 300 )
	//-----------------------------------------------------------------
	CHARACTER_SUCCESS = 200,		// ĳ���� �������� ��� ����
	CHARACTER_FAIL,                 // ĳ���� �������� �������� ����
	CHARACTER_AUTHKEY_FAIL,         // ����Ű ������ �����Ͽ����ϴ�.
	CHARACTER_TOO_LONG_NAME,		// ĳ���͸��� ���̰� �ʰ��Ǿ����ϴ�.
	CHARACTER_TOO_SHORT_NAME,		// ĳ���͸��� ���̰� �ʹ� ª���ϴ�.
	CHARACTER_SAMENAME_EXIST,		// �̹� ĳ���͸��� �����մϴ�.
	CHARACTER_COUNT_OVER,           // ĳ���� ���������� �ʰ��Ǿ����ϴ�.
	CHARACTER_NAME_NOT_EXIST,       // ĳ���Ͱ� �������� �ʽ��ϴ�.
	CHARACTER_CREATE_VALUE_FAIL,	// ĳ���� ���� ���� ��Ȯ���� �ʽ��ϴ�. 
	CHARACTER_USER_EXIST,           // �̹� �������Դϴ�.
	CHARACTER_USER_EXIST_IN_GAME_SERVER,		// ���� ������ �̹� �÷������� ĳ���Ͱ� �ֽ��ϴ�.
	CHARACTER_USER_ITEM_CREATE_FAIL,// ĳ���� ������ ������ �����Ͽ����ϴ�. 
	CHARACTER_USER_SKILL_CREATE_FAIL,			// ĳ���� ��ų ������ �����Ͽ����ϴ�.
	CHARACTER_USER_QUICK_SLOT_CREATE_FAIL,		// ĳ���� �������� �ʱ�ȭ���� ���߽��ϴ�.
	CHARACTER_DB_QUERY_FAIL, // ĳ���� �������� DB ������ �����Ͽ����ϴ�.
	CHARACTER_WRONG_SERVER_FARM_SELECTED,		// �߸��� ������ �����Ͽ����ϴ�.
	CHARACTER_USER_BLOCK,			// ĳ���Ͱ� ��� �Ǿ����ϴ�. �ڼ��� ������ Ȩ�������� �����Ͻʽÿ�.
	CHARACTER_BLOCK_STRING_INCLUDED, // �������� ��Ʈ���� ���ԵǾ� �ֽ��ϴ�.
	CHARACTER_TEMPORARY_BLOCK,		// ��۾����̶� �����Ͻ� �� �����ϴ�. ��� �� ������ �õ��غ��ʽÿ�.
	CHARACTER_AUTHKEY_MISMATCH,
	CHARACTER_AUTHKEY_CREATE_FAIL,
	CHARACTER_AUTHKEY_NOT_FOUND,
	CHARACTER_DELETE_GUILD_LEADER_FAIL,			// ��帮���� ĳ���� ���� �� �����ϴ�.
	CHARACTER_DELETE_BUDOKAI_REGISTER_FAIL,		// õ�����Ϲ���ȸ ��û�� �϶��� ĳ���͸� ������ �� �����ϴ�.
	CHARACTER_SERVER_LOCKED,					// ���� ������ ��� ���¿��� ������ �� �����ϴ�.
	CHARACTER_DISCONNECTED_FORCEDLY,			// ����� ���� ������ ������ ����Ǿ����ϴ�.
	CHARACTER_DISCONNECTED_TEMPORARILY,			// ��ڿ� ���Ͽ� �Ͻ������� �α׾ƿ� ó���� �Ǿ����ϴ�.
	CHARACTER_RACE_NOT_ALLOWED,					// ������ ���� ���� �Դϴ�.

	CHARACTER_COMMON_CANT_DO_THAT_FOR_SOME_REASON,			// �ý��� ������ �۾��� ó���� �� �����ϴ�.
	CHARACTER_USER_SHOULD_WAIT_FOR_CONNECT,
	CHARACTER_SERVER_IS_UNDER_CONSTRUCTION,					// ���� ���� �� �Դϴ�.
	CHARACTER_DELETE_CHAR_FAIL,					// ĳ���� ������ �����߽��ϴ�.

	//new
	CHARACTER_NO_PREMIUM_SLOT,
	CHARACTER_DELETE_CHAR_FAIL_NOT_MATCH_CODE,
	CHARACTER_COUNT_OVER_AND_DELETE_NFY,
	CHARACTER_DELETE_CHAR_TMP_FAIL,


	CHAR_RESULT_LAST,							// always last

	//-----------------------------------------------------------------


	//-----------------------------------------------------------------
	// Community ( 300 ~ 400 )
	//-----------------------------------------------------------------
	CHAT_SUCCESS = 300,				// Ŀ�´�Ƽ ���� ���� ��� ����
	COMMUNITY_FAIL,												// Ŀ�´�Ƽ ���� ���� �������� ����

	COMMUNITY_INVALID_AUTH_KEY,									// ����Ű ������ �����Ͽ����ϴ�.
	COMMUNITY_ALREADY_IN_SERVER,								// �̹� �������Դϴ�.  
	COMMUNITY_DISCONNECTED_FORCEDLY,							// ����� ���� ������ ������ ����Ǿ����ϴ�.
	COMMUNITY_DISCONNECTED_TEMPORARILY,							// ��ڿ� ���Ͽ� �Ͻ������� �α׾ƿ� ó���� �Ǿ����ϴ�.
	COMMUNITY_COMMON_SYSTEM_ERROR,								// Ŀ�´�Ƽ �ý��� �����Դϴ�.
	COMMUNITY_COMMON_NO_SUCH_A_TARGET,							// ����� �������� �ʽ��ϴ�.
	COMMUNITY_COMMON_TARGET_IS_NOT_YOUR_GUILD_MEMBER,			// ����� ����� ��忡 ���� ���� �ʽ��ϴ�.
	COMMUNITY_COMMON_NEED_MORE_TIME_TO_DO_IT,					// ��� �Ŀ� �ٽ� �õ��Ͻʽÿ�.
	COMMUNITY_PARTY_LEADER_DOESNT_EXIST,						// ������ Ŀ�´�Ƽ ������ �������� �ʽ��ϴ�.
	COMMUNITY_PARTY_SAME_PARTYID_ALREADY_EXIST,					// ���� ID�� ��Ƽ�� �̹� �����մϴ�.
	COMMUNITY_PARTY_NO_SUCH_A_PARTY,							// �������� �ʴ� ��Ƽ�Դϴ�.
	COMMUNITY_PARTY_MEMBER_ALREADY_EXIST,						// �̹� ��Ƽ�� �����ϴ� ����Դϴ�.
	COMMUNITY_PARTY_NO_SUCH_A_MEMBER,							// �������� �ʴ� ����Դϴ�.
	COMMUNITY_GUILD_CREATOR_NOT_FOUND,							// ��� ������ ��û�� �÷��̾ ã�� �� �����ϴ�.
	COMMUNITY_GUILD_GUILD_MEMBER_CANT_HAVE_MORE_GUILD,			// ��忡 ������ ����� �ٸ� ��忡 �ߺ��ؼ� ������ �� �����ϴ�.
	COMMUNITY_GUILD_NEED_MORE_PARTY_MEMBER_FOR_NEW_GUILD,		// ��� ������ ���ؼ��� ��Ƽ���� �� �ʿ��մϴ�.
	COMMUNITY_GUILD_YOU_DONT_BELONG_TO_GUILD,					// ��忡 ���� ���� �ʽ��ϴ�.
	COMMUNITY_GUILD_YOU_ARE_NOT_GUILD_MASTER,					// ����� ��� �����Ͱ� �ƴմϴ�.
	COMMUNITY_GUILD_GUILD_IS_BEING_DISBANDED,					// ��尡 ��ü �����Դϴ�.
	COMMUNITY_GUILD_GUILD_IS_NOT_BEING_DISBANDED,				// ��尡 ��ü ���°� �ƴմϴ�.
	COMMUNITY_GUILD_YOU_DONT_HAVE_RIGHT_TO_INVITE,				// ������ �ʴ��� �� �ִ� ������ �����ϴ�.
	COMMUNITY_GUILD_TARGET_IS_ALREADY_IN_A_GUILD,				// ��밡 �̹� ��忡 ���� �ֽ��ϴ�.
	COMMUNITY_GUILD_TARGET_ALREADY_HAS_INVITATION,				// ������ �̹� ��� �ʴ븦 ���� �����Դϴ�.
	COMMUNITY_GUILD_YOU_HAVE_NO_INVITATION,						// ����� ���κ��� �ʴ븦 ���� ���°� �ƴմϴ�.
	COMMUNITY_COMMON_NO_SUCH_A_GUILD,							// ��尡 �������� �ʽ��ϴ�.
	COMMUNITY_GUILD_YOU_ARE_ALREADY_IN_A_GUILD,					// �̹� ��忡 ���� �ֽ��ϴ�.
	COMMUNITY_GUILD_MAX_NUMBER_OF_MEMBERS,						// ���� �� �̻� �� ������ ���� �� �����ϴ�.
	COMMUNITY_GUILD_LEADER_CANT_LEAVE,							// ��� �����ʹ� ��带 Ż���� �� �����ϴ�.
	COMMUNITY_GUILD_YOU_DONT_HAVE_RIGHT_TO_KICK_OUT,			// ������ ������ Ż���ų �� �ִ� ������ �����ϴ�.
	COMMUNITY_GUILD_CANT_KICK_YOURSELF_OUT,						// �ڽ��� ������ Ż���ų �� �����ϴ�.
	COMMUNITY_GUILD_TRIED_TO_APPOINT_YOURSELF,					// �ڱ� �ڽſ� ���ؼ��� �Ӹ� ����� ����� �� �����ϴ�.
	COMMUNITY_GUILD_TARGET_IS_ALREADY_SECOND_MASTER,			// ����� �̹� Second Master�Դϴ�.
	COMMUNITY_GUILD_MAX_NUMBER_OF_SECOND_MASTERS,				// ���� �� �̻� �� Second Master�� �Ӹ��� �� �����ϴ�.
	COMMUNITY_GUILD_TARGET_IS_NOT_SECOND_MASTER,				// ����� ����� Second Master�� �ƴմϴ�.
	COMMUNITY_GUILD_FUNCTION_NOT_FOUND,							// �ش� ����� ��� �� �� �ִ� ������ �����ϴ�.
	COMMUNITY_GUILD_BANK_USING_NOW,								// ��� â�� �ٸ� ����� ��� �� �Դϴ�. ���� �ڿ� �ٽ� �õ� ���ּ���.	
	COMMUNITY_FRIEND_CHAR_NOT_FOUND,							// �ش�ĳ���Ͱ� �������� �ʽ��ϴ�.
	COMMUNITY_FRIEND_CHAR_ARLEADY_ADDED,						// �̹� ��� �� ĳ���Դϴ�.
	COMMUNITY_FRIEND_MAX_COUNT_OVER,							// ��ϰ��� ģ�� ������ �ʰ� �߽��ϴ�.
	COMMUNITY_FRIEND_CHAR_EXIST,								// ģ����Ͽ� �����ϴ� ĳ���Դϴ�.
	COMMUNITY_FRIEND_BLACK_CHAR_EXIST,							// Black List ��Ͽ� �����ϴ� ĳ���Դϴ�.
	COMMUNITY_FRIEND_SELF_FAIL,									// �ڱ� �ڽ��� �߰� �Ҽ� �����ϴ�.
	COMMUNITY_RANK_BATTLE_LIST_NOT_FOUND,						// ��ũ��Ʋ ����Ʈ�� �����ϴ�.
	COMMUNITY_GUILD_BANK_QUERY,									// ��� â���� DB ó�����Դϴ�. ����� �ٽ� �õ��ϼ���!
	COMMUNITY_GUILD_BANK_CLOSED,								// ��� â�� �������ϴ�.
	COMMUNITY_GUILD_KICKOUT,									// ��忡�� �߹� ���߽��ϴ�.
	COMMUNITY_GUILD_LEAVE,										// ��忡�� Ż�� �߽��ϴ�.
	COMMUNITY_TMQ_CHAR_NOT_FOUND,								// �ش� ĳ���Ͱ� �������� �ʽ��ϴ�.
	COMMUNITY_TMQ_DATA_NOT_FOUND,								// �ش� �����Ͱ� �������� �ʽ��ϴ�.
	COMMUNITY_DOJO_MAKE_FAIL,									// ���� ����⿡ �����߽��ϴ�.
	COMMUNITY_DOJO_DEL_FAIL,									// ���� ������ �����߽��ϴ�.
	COMMUNITY_DOJO_FIND_FAIL,									// ���� ã�⿡ �����߽��ϴ�.
	COMMUNITY_DOJO_SCRAMBLE_ARLEADY_HAVE,						// ���� ��Ż�� ��û�ڰ� �̹� �ֽ��ϴ�.
	COMMUNITY_DOJO_SCRAMBLE_WAIT,								// ���� ��Ż�� ��û�� ����� �ٽ� �õ����ֽʽÿ�.
	COMMUNITY_DOJO_SCRAMBLE_REJECT_FAIL_FOR_BANK_USE,			// â���̿��߿� ���� ��Ż�� ��û�źΰ� �Ұ����մϴ�.  
	COMMUNITY_DOJO_SCRAMBLE_REJECT_FAIL_SECOND,					// ���� ��Ż�� �źδ� �ѹ��� �����մϴ�. 
	COMMUNITY_DOJO_SEED_ALREADY_SETTING,						// �̹� õ�����Ϲ���ȸ �õ尪����� �Ǿ��ֽ��ϴ�. ������ �ٽ� ����ϼ���.
	COMMUNITY_DOJO_SEED_NAME_FAIL,								// �ش� ĳ���� ���ų� �߸��Ǿ����ϴ�.
	COMMUNITY_DOJO_SEED_NOT_SET,								// õ�����Ϲ���ȸ �õ尪����� �Ǿ����� �ʽ��ϴ�.
	COMMUNITY_DOJO_NON_EXISTING_FUNCTION,						// �ش� ������ �����ϴ�. 
	COMMUNITY_DOJO_YOU_ARE_NOT_OWNNER,							// ���忡 ���� ���� �ʽ��ϴ�.
	COMMUNITY_GUILD_FIND_FAIL,									// ��� ã�⿡ �����߽��ϴ�.
	COMMUNITY_DOJO_BANK_ZENNY_NOT_ENOUGH,						// â�� ���ϰ� �����մϴ�.
	COMMUNITY_GUILD_DISBANDE_FAIL_FOR_DOJO,						// ���忡 ���� ���� ������ �� �����ϴ�.
	COMMUNITY_GUILD_DISBANDE_FAIL_FOR_DOJO_SCRAMBLE,			// ���� ��Ż���߿��� ������ �� �����ϴ�.
	COMMUNITY_DOJO_SCRAMBLE_FAIL_FOR_BEING_DISBANDED,			// ��尡 ��ü ���¿��� �������� �� �� �����ϴ�.
	COMMUNITY_GUILD_INVITE_FAIL_FOR_BEING_SCRAMBLE,
	COMMUNITY_RANK_BATTLE_NO_REMAIN_COUNT,
	COMMUNITY_RANK_BATTLE_COUNT_ALREADY_FLUSHED,
	COMMUNITY_TMQ_COUNT_ALREADY_FLUSHED,
	COMMUNITY_COMMON_NOT_VALID_TARGET,


	CHAT_RESULT_LAST,							// always last


	//-----------------------------------------------------------------
	// Query ( 400 ~ 500 )
	//-----------------------------------------------------------------
	QUERY_SUCCESS = 400,			// �������� ���� ��� ����
	QUERY_FAIL,						// �������� ���� �������� ����

	QUERY_CANNOT_FIND_SQLUNIT,		// Can not find SQL Unit
	QUERY_EXECUTE_FAIL,				// ���� ���� ����
	QUERY_STORE_FAIL,				// ���� ���� ����
	

	//-----------------------------------------------------------------


	//-----------------------------------------------------------------
	// Game ( 500 ~ )
	//-----------------------------------------------------------------
	GAME_SUCCESS = 500,				// ���Ӽ��� ���� ��� ����
	GAME_FAIL,						// ���Ӽ��� ���� �������� ����

	GAME_DB_CHAR_DATA_LOAD_FAIL,	// ĳ���� ����Ÿ �ε��� �����Ͽ����ϴ�.
	GAME_DB_CHAR_NOT_FOUND,			// �ش��ϴ� ĳ��Ÿ ����Ÿ�� �������� �ʽ��ϴ�.

	GAME_INVALID_AUTH_KEY,			// ����Ű ������ �����Ͽ����ϴ�.
	GAME_USER_EXIST,				// �̹� �������Դϴ�.
	GAME_SERVER_LOCKED,				// ���� ������ ��� ���¿��� ������ �� �����ϴ�.
	GAME_WRONG_SERVER_CHANNEL_HAS_BEEN_SPECIFIED,			// �߸��� ���� ä���� �����Ͽ����ϴ�.

	GAME_CHAR_IS_WRONG_STATE,		//I can not do it now
	GAME_INPUT_PARAMETER_WRONG,		// Invalid input.

	GAME_TARGET_IS_WRONG_STATE,		// Target is not in proper state.
	GAME_TARGET_NOT_FOUND,			// ����� ã�� �� �����ϴ�.
	GAME_TARGET_TOO_FAR,			// ������ �Ÿ��� �ʹ� �ٴϴ�.
	GAME_TARGET_TOO_CLOSE,			// ������ �Ÿ��� �ʹ� �������ϴ�.
	GAME_TARGET_HAS_NOT_FUNCTION,	// ����� �ش� ����� �������� �ʽ��ϴ�.

	GAME_DISCONNECTED_FORCEDLY,							// ����� ���� ������ ������ ����Ǿ����ϴ�.
	GAME_DISCONNECTED_TEMPORARILY,						// ��ڿ� ���Ͽ� �Ͻ������� �α׾ƿ� ó���� �Ǿ����ϴ�.

	GAME_COMMON_YOU_ARE_NOT_IN_A_PARTY,					// ��Ƽ�� ���� ���� �ʽ��ϴ�.
	GAME_COMMON_YOU_ARE_NOT_A_PARTY_LEADER,				// ��Ƽ ������ �ƴմϴ�.
	GAME_COMMON_ZENNY_CANT_BE_USED_RIGHT_NOW,			// �Ͻ������� ���ϸ� ����� �� ���� ��Ȳ�Դϴ�. ��� �� �ٽ� �õ��ϼ���.
	GAME_COMMON_TEMPORARY_,
	GAME_COMMON_CANT_DO_THAT_FOR_SOME_REASON,			// �ý��� ������ �۾��� ó���� �� �����ϴ�.
	GAME_COMMON_NON_EXISTING_PET_SPECIFIED,				// �������� �ʴ� ���� �����Ͽ����ϴ�.

	GAME_COMMON_CANT_DO_THAT_IN_SPAWNING_STATE,				// ���� ���� ���߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_STANDING_STATE,				// �� ���� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_STANDING_JUMPING_STATE,		// ���ڸ� ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_JUMPING_STATE,				// ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_NON_JUMPING_STATE,			// ���� ���� �ƴ� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SITTING_STATE,				// �ɾ� ���� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FAINTING_STATE,				// �ǽ��� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CAMPING_STATE,				// ķ�� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_LEAVING_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_MOVING_STATE,				// �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_MOVING_JUMPING_STATE,		// ���� �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DESTMOVING_STATE,			// �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FOLLOWING_STATE,			// �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FALLING_STATE,				// �������� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DASH_STATE,					// �뽬 �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TELEPORTING_STATE,			// �ڷ���Ʈ ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SLIDING_STATE,				// �����̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_KNOCKDOWN_STATE,			// This command is not available during knockdown.
	GAME_COMMON_CANT_DO_THAT_IN_FOCUSING_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CASTING_STATE,				// During casting the skill is not available commands.
	GAME_COMMON_CANT_DO_THAT_IN_AFFECTING_STATE,			// During casting the skill is not available commands.
	GAME_COMMON_CANT_DO_THAT_IN_KEEPING_EFFECT_STATE,		// The effect of maintaining the status command is not available.
	GAME_COMMON_CANT_DO_THAT_IN_CASTING_ITEM_STATE,			// Some items are not available, use the command.
	GAME_COMMON_CANT_DO_THAT_IN_STUNNED_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SLEEPING_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_PARALYZED_STATE,			// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_HTB_STATE,					// HTB ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SANDBAG_STATE,				// HTB ��ų�� �ɸ� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CHARGING_STATE,				// �⸦ ������ �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_BLOCKING_STATE,				// Block ��忡���� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DESPAWNING_STATE,			// ���忡�� ����� ���߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_PRIVATESHOP_STATE,			// ���� ������ ���� ���� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DIRECT_PLAY_STATE,			// ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_OPERATING_STATE,			// ������Ʈ �����߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_RIDEON_STATE,				// The command can not ride a bullet in the state.
	GAME_COMMON_CANT_DO_THAT_IN_TURNING_STATE,				// In turn, the state is unable to command.

	GAME_COMMON_CANT_DO_THAT_IN_INVISIBLE_CONDITION,		// ���� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_HIDING_KI_CONDITION,		// �� ����� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TRANSPARENT_CONDITION,		// GM ���� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TERROR_CONDITION,			// ������ �ɸ� ���¿����� ��� �� �� ���� ����Դϴ�.

	GAME_COMMON_CANT_DO_THAT_IN_CONFUSE_CONDITION,			//new 562

	GAME_COMMON_CANT_DO_THAT_IN_AFTEREFFECT_CONDITION,		// ������ ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CHARGING_BLOCKED_CONDITION,		// �� �����Ⱑ �Ұ����� �����Դϴ�.

	GAME_GAMERULE_REG_CANT_PLAY_IN_FREEBATTLE,				// During the battle can not be free.
	GAME_GAMERULE_REG_CANT_PLAY_IN_RANKBATTLE,				// I can not rank during the battle.
	GAME_GAMERULE_REG_CANT_PLAY_IN_TMQ,						// Some quests can not be a time machine.
	GAME_GAMERULE_REG_CANT_PLAY_IN_SUMMON_DRAGONBALL,		// Dragon can not be summoned during the ball.
	GAME_GAMERULE_REG_CANT_PLAY_IN_PRIVATE_SHOP,			// ���λ��� �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_BUDOKAI,					// õ�����Ϲ���ȸ �߿��� �� �� �����ϴ�.

	GAME_GAMERULE_REG_ALREADY_JOINED_IN_FREEBATTLE,			// �̹� ������Ʋ ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_JOINED_IN_RANKBATTLE,			// �̹� ��ũ��Ʋ ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_JOINED_IN_TMQ,				// �̹� Ÿ�Ӹӽ� ����Ʈ ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_SUMMON_DRAGONBALL,			// �̹� �巡�ﺼ ��ȯ ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_OPENED_PRIVATE_SHOP,			// �̹� ���λ��� ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_JOINED_BUDOKAI,				// �̹� õ�����Ϲ���ȸ ���� ���Դϴ�.

	GAME_CONTENTS_LOCK,										// ���� ����ִ� �������Դϴ�.
	GAME_CONTENTS_CAN_NOT_PLAY_IN_BUDOKAI_REGISTER_STATE,	// õ�����Ϲ���ȸ ��ϱⰣ �߿��� �̿��� �� �����ϴ�.

	GAME_WORLD_CAN_NOT_CREATE_DYNAMIC_WORLD,			// ���带 ������ �� �����ϴ�.
	GAME_WORLD_NOW_CREATING,							// ��� �� �ٽ� �õ��Ͻʽÿ�.
	GAME_WORLD_ALREADY_WORLD_ENTERED,					// �̹� ���忡 ������ �ֽ��ϴ�.
	GAME_WORLD_CANT_ENTER_WORLD,						// ������ �� �ִ� ���尡 �����ϴ�.
	GAME_WORLD_ALREADY_WORLD_AREA_ENTERED,				// �̹� ���� ������ ������ �ֽ��ϴ�.
	GAME_WORLD_CANT_FIND_WORLD_AREA,					// ������ ���念���� ã�� �� �����ϴ�.
	GAME_WORLD_CANT_ENTER_WORLD_AREA,					// ������ �� �ִ¿��念���� �����ϴ�.
	
	GAME_SHORTCUT_KEY_ARLEADY_FOUND,					// ���� Ű�� �̹� �����Ǿ� �ֽ��ϴ�.
	GAME_SHORTCUT_KEY_DEL_NOT_FOUND,					// �����Ϸ��� Ű�� �����ϴ�.
	GAME_SHORTCUT_KEY_MODIFY_NOT_FOUND,					// �����Ϸ��� Ű�� �����ϴ�.

	GAME_COMMON_CANT_DO_THAT_NOT_ALLOWED_TARGET,		// ��� ������ �Ұ����� ���� �Դϴ�.

	GAME_COMMON_CANT_FIND_OBJECT,						// �ش� ������Ʈ�� ã�� �� �����ϴ�.

	GAME_CHAR_WRONG_REVIVAL_METHOD,						// �߸��� ��Ȱ ����Դϴ�.
	GAME_CANNOT_CONNECT_DUE_TO_TIMEOUT,					// Ÿ�Ӿƿ��Ǿ� ������ �� �����ϴ�.
	GAME_CANNOT_CONNECT_TARGET_CHANNEL_FULL,			// �̵��Ϸ��� ä�ο� ���� ������ �����ϴ�.
	GAME_CANNOT_CONNECT_DUE_TO_INVAlID_CHARACTER,		// �������� ĳ���Ͱ� �ƴմϴ�.
	GAME_TARGET_HAS_DIFFERENT_JOB,						// ����� ������ �ùٸ��� �ʽ��ϴ�.

	GAME_GMT_NOT_ENOUGH_RESET_POINT,					// GMT �缳�� ����Ʈ�� �����մϴ�.

	//-----------------------------------------------------------------
	GAME_SKILL_NOT_ACTIVE_TYPE,		// Active Ÿ���� ��ų�� �ƴմϴ�.
	GAME_SKILL_YOU_DONT_HAVE_THE_SKILL,		// ������ ���� ���� ��ų�Դϴ�.
	GAME_SKILL_NOT_EXISTING_SKILL,			// �������� �ʴ� ��ų�Դϴ�.
	GAME_SKILL_CANT_CAST_NOW,				// ���� ��ų�� ������ �� �ִ� ���°� �ƴմϴ�.
	GAME_SKILL_NO_TARGET_APPOINTED,				// ����� �����ϼž� �մϴ�.
	GAME_SKILL_INVALID_TARGET_APPOINTED,		// ���� Ÿ�ٿ� ��ų�� ����� �� �����ϴ�.
	GAME_SKILL_NOT_READY_TO_BE_CAST,		// ��ų�� ��Ÿ���� ��ٷ��� �մϴ�.
	GAME_SKILL_NOT_ENOUGH_LP,				// LP�� ������� �ʽ��ϴ�.
	GAME_SKILL_NOT_ENOUGH_EP,				// EP�� ������� �ʽ��ϴ�.
	GAME_SKILL_NOT_ENOUGH_RP_BALL,						// RP ������ ������� �ʽ��ϴ�.

	GAME_SKILL_NO_REQUIRED_ITEM,			// ��ų�� ����ϱ� ���� �ʿ��� �������� ������ ���� �ʽ��ϴ�.
	GAME_SKILL_TOO_MANY_LP_TO_USE_SKILL,				// LP�� 50% ������ ������ �� ��ų�� ����� �� �ֽ��ϴ�.
	GAME_SKILL_TARGET_IS_NOT_KNOCKED_DOWN,				// Target is not in a knock down state.
	GAME_SKILL_RESISTED,								// I resisted the skill.
	GAME_SKILL_TRIED_TO_LEARN_AN_EXISTING_SKILL,		// �̹� ������ �ִ� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_TRIED_TO_LEARN_WRONG_CLASS_SKILL,		// ������ ���� �ʴ� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_TOO_HIGH_LEVEL_TO_TRAIN,					// ������ ���Ƽ� ���� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_NOT_ENOUGH_ZENNY,						// Zenny�� ���ڶ� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_NO_EMPTY_SKILL_SLOT,						// �� ��ų ������ �����ϴ�.
	GAME_SKILL_YOU_HAVE_NO_LOWER_LEVEL_SKILL,			// ���׷��̵带 ���ؼ��� ������ ��ų���� �� �ܰ� ���� ��ų�� ������ �־�� �մϴ�.

	GAME_SKILL_ALREADY_MASTERED_SKILL,					// �̹� �ñ��� ��ų�� ������ �����Դϴ�.
	GAME_SKILL_NO_PREREQUISITE_SKILLS_YOU_HAVE,			// ��ų ������ ���� �̹� ���� �־�� �� ��ų�� ������ ���� �ʽ��ϴ�.
	GAME_SKILL_UPGRADE_ONLY_SKILL,		// ���׷��̵�θ� ���� �� �ִ� ��ų�Դϴ�.
	GAME_SKILL_SHOULD_BE_GAINED_BY_YOURSELF,			// ������ ����� �ϴ� ��ų�Դϴ�.
	GAME_SKILL_CANT_BE_GAINED_BY_YOURSELF,				// ������ ��� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_FOR_SOME_REASON,		// �ý��� ������ ��ų�� ����� �� �����ϴ�.
	GAME_SKILL_TARGET_IS_NOT_IN_FRONT_SIDE,		// Ÿ���� ��� �տ� ��ġ�ؾ� �մϴ�.
	GAME_SKILL_YOU_ARE_NOT_IN_BACKSIDE_OF_TARGET,		// ����� �ڿ����� ��ų�� ����� �� �ֽ��ϴ�.
	GAME_SKILL_TARGET_IS_IN_FAINT,		// Ÿ���� �ǽ��� �����Դϴ�.
	GAME_SKILL_CAN_BE_CAST_ONLY_ON_PLAYER,		// �÷��̾�Ը� ����� �� �ִ� ��ų�Դϴ�.

	GAME_SKILL_TARGET_IS_NOT_FAINTING,					// Ÿ���� �ǽ��� ���°� �ƴմϴ�.
	GAME_SKILL_NOT_BATTLE_AVAILABLE_LOCATION,			// ��ų ����ڿ� ��� ��� ������ ������ ������ ��ġ�ؾ� �մϴ�.
	GAME_SKILL_CASTING_CANCELED_BY_DAMAGE,				// ������ �޾� ��ų ������ ��ҵǾ����ϴ�.
	GAME_SKILL_CANT_SET_THAT_RP_BONUS_IN_SKILL,			// ������ ��ų������ ������ �� ���� RP ���ʽ� Ÿ���Դϴ�.
	GAME_SKILL_CANT_USE_THAT_RP_BONUS_IN_SKILL,			// ������ ��ų������ ����� �� ���� RP ���ʽ� Ÿ���Դϴ�.
	GAME_SKILL_NO_BUFF_TO_DROP_FOUND,					// ������ �� �ִ� ������ �����Ͽ��� �մϴ�.
	GAME_SKILL_ALREADY_TRANSFORMED,						// ������ ���� ���°� �����Ǿ�� ���ο� ������ ����� �� �ֽ��ϴ�.
	GAME_SKILL_NOT_TRANSFORMED,							// ���� ���°� �ƴմϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_SUPER_SAIYAN,		// �ʻ��̾��� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_PURE_MAJIN,			// ���� ���� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_GREAT_NAMEK,			// �Ŵ� ����ũ ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_KAIOKEN,				// ��ձ� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_SPINNING_ATTACK,		// ȸ�� ���� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_VEHICLE,				// Ż �� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_NOT_TRANSFORMED,		// �������� ���� ���¿����� ����� �� ���� ��ų�Դϴ�.

	GAME_SKILL_CANT_USE_SKILL_BOAST_NOW,				//new 645

	GAME_SKILL_NOT_ENOUGH_SP_POINT,						// SP POINT �� �����մϴ�.
	GAME_SKILL_ERASE_FAIL,								// ��ų�� ����ٰ� �����߽��ϴ�.
	GAME_BLOCK_ATTACK_NOW,								// ����� ����Ǿ� ����� �� �����ϴ�. 
	GAME_SKILL_HAVE_UPGRADED_SKILL,						// ��ų�� ���׷��̵� �� ��ų�� ������ �����Դϴ�.
	GAME_SKILL_CANT_BE_CAST_ON_YOURSELF,				// �ڽ��� �����ϰ� ����� �� ���� ��ų�Դϴ�.

	GAME_SKILL_CANT_USE_HTB_WHEN_TRANSFORMED,			// ���� �߿��� HTB�� ����� �� �����ϴ�.
	GAME_SKILL_CASTING_CANCELED_BY_TARGET_NEW_STATE,	// 651 // ����� ���°� �ٲ�� ������ ��ҵǾ����ϴ�.
    GAME_SKILL_CASTING_CANCELED_OBJECT_OCCLUSION,       // ĳ�����߿� ������Ʈ�� ������ ��ҵǾ����ϴ�.
	GAME_SKILL_CANT_USE_VEHICLE_WHEN_TRANSFORMED,		// ���� �߿��� Ż ���� �̿��� �� �����ϴ�.
	GAME_SKILL_CANT_USE_WHEN_TRANSFORMED,				// ���� �߿��� �̿��� �� �����ϴ�.

	GAME_SKILL_CANT_CANCEL_TRANSFORM_WHEN_USING_SKILL,
	GAME_SKILL_CANT_USE_ON_THIS_TARGET,
	GAME_SKILL_NO_SKILL_TO_INIT,
	GAME_SKILL_ALREADY_EXIST_SAME_KIND_BUFF,
	GAME_SKILL_BUFF_IS_FULL,
	GAME_SKILL_CURRENT_BUFF_IS_STRONGER_THEN_NEW,
	GAME_SKILL_ONE_RESET_FAIL,
	GAME_SKILL_GM_BUF_SUCCESS,
	GAME_SKILL_TOO_HIGH_LEVEL_FOR_SKILL_INIT,
	GAME_SKILL_DEBUFF_IS_FULL,
	GAME_SKILL_SUB_BUFF_IS_FULL,
	GAME_SKILL_REVIVAL_AFTEREFFECT_BUFF_IS_FULL,
	GAME_ANOTHER_SKILL_CANT_CAST_NOW,


	//-----------------------------------------------------------------
	GAME_CHAR_ONLY_ADULT_CAN_CHANGE_CLASS,				// � ���¿����� ������ �� �� �ֽ��ϴ�.
	GAME_CHAR_NO_AUTHORITY_FOR_CHANGING_CLASS,					// ������ �� �ִ� �ڰ��� ���߰� ���� �ʽ��ϴ�.
	GAME_GM_CANT_DO_THAT_WHEN_YOU_ARE_HIDING,					// 702 // ���� ���¿����� �� �� ���� ����Դϴ�.
	//-----------------------------------------------------------------
	GAME_ITEM_NUM_NULL,
	GAME_ITEM_POSITION_FAIL,
	GAME_ITEM_OWNER_NOT_SAME,
	GAME_ITEM_NOT_SAME,
	GAME_ITEM_OWNER_NULL,
	GAME_ITEM_STACK_FAIL,
	GAME_ITEM_NOT_FOUND,
	GAME_NEEDITEM_NOT_FOUND,
	GAME_NEEDITEM_NOT_FOUND_INVANTORY,
	GAME_ITEM_BAG_IS_NOT_EMPTY,

	GAME_ITEM_ALREADY_EXIST,
	GAME_ITEM_MAX_COUNT_OVER,
	GAME_ITEM_STACK_FULL,
	GAME_EQUIP_SLOT_NOT_EMPTY,
	GAME_ITEM_CLASS_FAIL,
	GAME_ITEM_NEED_MORE_LEVEL,
	GAME_ITEM_NEED_MORE_PARAMETER,
	GAME_ITEM_MAX_WATT_OVER,
	GAME_ITEM_INVEN_FULL,
	GAME_ITEM_LOOTING,

	GAME_ITEM_UNIDENTIFY,
	GAME_ITEM_UNIDENTIFY_FAIL,
	GAME_LOOTING_FAIL,
	GAME_ZENNY_NOT_ENOUGH,
	GAME_ITEM_IS_LOCK,
	GAME_ZENNY_IS_LOCK,
	GAME_REPAIR_VALUE_FAIL,
	GAME_REPAIR_NOT_FOUND,
	GAME_ITEM_YOU_ARE_USING_AN_ITEM,

	GAME_ITEM_NOT_FOR_USE,
	GAME_ITEM_NOT_BATTLE_AVAILABLE_LOCATION,
	GAME_ITEM_CANT_USE_FOR_SOME_REASON,
	GAME_ITEM_NOT_READY_TO_BE_USED,
	GAME_ITEM_TOO_LOW_LEVEL_TO_USE_ITEM,
	GAME_ITEM_NOT_ENOUGH_LP,
	GAME_ITEM_NOT_ENOUGH_EP,
	GAME_ITEM_NOT_ENOUGH_RP_BALL,
	GAME_ITEM_CASTING_CANCELED,
	GAME_ITEM_CANT_USE_NOW,

	GAME_ITEM_DUR_ZERO,
	GAME_SCOUTER_MAX_OVER,
	GAME_ITEM_NOT_ENOUGH,
	GAME_ITEM_UPGRADE_NO_SUBJECT_ITEM,
	GAME_ITEM_UPGRADE_NO_HOIPOI_STONE,
	GAME_ITEM_UPGRADE_WRONG_ITEM_TYPE,
	GAME_ITEM_UPGRADE_ALREADY_MAX_GRADE,
	GAME_ITEM_UPGRADE_FAIL,				
	GAME_ITEM_UPGRADE_FAIL_AND_DEL,
	GAME_BANK_NOT_READY,

	GAME_BANK_ALREADY_EXIST,		// â�� �̹� �����մϴ�.
	GAME_SCOUTER_PARTS_NOT_FOUND,	// �ش� ��ī���� ������ ã�� ���߽��ϴ�.
	GAME_SCOUTER_JAMMING,			// ���Ĺ��ط� ���� ǥ���� �� �����ϴ�. 
	GAME_SCOUTER_TARGET_FAIL,	 // ǥ�� ����� �������մϴ�.
	GAME_CHAR_LEVEL_FAIL,		// ������ ���� �ʽ��ϴ�.
	GAME_CHAR_CLASS_FAIL,		// �ش�Ŭ������ ���� �ʽ��ϴ�.
	GAME_CHAR_RACE_FAIL,		// �ش� ������ ���� �ʽ��ϴ�.
	GAME_ZENNY_OVER,			// �ݾ��� �����Ǿ����ϴ�.
	GAME_QUEST_ALREADY_EXIST,	// �̹� �����ϴ� ����Ʈ�Դϴ�.
	GAME_QUEST_COUNT_OVER,		// ���డ���� ����Ʈ���� �ʰ��Ǿ����ϴ�.

	GAME_QUEST_NOT_EXIST,		// �������� �ʴ� ����Ʈ�Դϴ�.
	GAME_ITEM_CREATE_COUNT_OVER,// �ѹ��� ������ �� �ִ� ������ �Ѿ���.
	GAME_ITEM_DELETE_COUNT_OVER,// �ѹ��� ������ �� �ִ� ������ �Ѿ���.
	GAME_GM_LEVEL_NOT_FOUND,	// GM Level �� ����
	GAME_GM_PUNISH_NOT_FOUND,	// Punish type error
	GAME_SCOUTER_BODY_IS_NOT_EMPTY, // ��ī���� ������ ����� �̵������մϴ�.
	GAME_SCOUTER_PARTS_LEVEL_FAIL,	// ��ī���� ���� ������ ���� �ʽ��ϴ�.
	GAME_TRADE_TARGET_WRONG_STATE,		// ������ ���� Ʈ���̵带 �� �� ���� �����Դϴ�.
	GAME_TRADE_ALREADY_USE,		// Ʈ���̵� ���Դϴ�.
	GAME_TRADE_DENY_USE,		// Ʈ���̵� ���� ���Դϴ�.

	GAME_TRADE_DENY,			// Ʈ���̵带 �����Ͽ����ϴ�.
	GAME_TRADE_REPLY_WAIT_OVER,
	GAME_TRADE_WRONG_STATE,		// Ʈ���̵��ϱ⿡ ������ ���°� �ƴմϴ�.
	GAME_TRADE_ITEM_INVALID,	// Ʈ���̵� �Ұ����� ������ �Դϴ�.
	GAME_TRADE_ALREADY_CLOSE,	// Ʈ���̵尡 �̹� ������ �Դϴ�.
	GAME_TRADE_ALREADY_OPEN,	// Ʈ���̵尡 �̹� �������� �Դϴ�.
	GAME_TRADE_CHANGED_STATE,	// Ʈ���̵� ��ǰ ������ �ٲ�����ϴ�.
	GAME_ITEM_NOT_GO_THERE,		// �ű�� ���� ��ġ�Դϴ�.
	GAME_DRAGONBALL_OBJECT_ARLEADY_USED, // ������ ��� ���Դϴ�.
	GAME_DRAGONBALL_NOT_FOUND,	 // �巡�ﺼ�� ã���� �����ϴ�.

	GAME_DRAGONBALL_REWARD_NOT_FOUND,   // �巡�ﺼ ������ ã�� �� �����ϴ�.
	GAME_DRAGONBALL_TIME_OVER,	// ���ð��� ����Ǿ����ϴ�.
	GAME_DRAGONBALL_SAME_EXIST,		// ���� �� �巡�ﺼ�� �ֽ��ϴ�.
	GAME_QUSET_ITEM_CREATE_COUNT_OVER,// ����Ʈ �κ��丮���� ������ �������� ������ �� �����ϴ�.
	GAME_ITEM_CANT_BE_USED_ON_YOURSELF,					// �ڽ��� �����ϰ� ����� �� ���� �������Դϴ�.
	GAME_ITEM_TYPE_NOT_MISMATCHED,	// Item type is not correct.
	GAME_ITEM_RECIPE_ALREADY_EXIST,	// The same recipe already exists.	
	GAME_ITEM_RECIPE_NOT_FOUND,		// The recipe does not exist.
	GAME_ITEM_RECIPE_REGISTER_PROFESSION,	// You must first select the appropriate item mix job.
	GAME_ITEM_RECIPE_LEVEL_MISMATCHED,	// The item recipe level is not correct.
	GAME_ITEM_RECIPE_TYPE_MISMATCHED,	// �ش� ������ ������ Ÿ���� ���� �ʽ��ϴ�.
	GAME_ITEM_RECIPE_REGISTER_FAIL,		// ������ ������ ��Ͽ� �����߽��ϴ�.
	GAME_ZENNY_LOOTING,					// I'm picking up Zenny.
	GAME_ITEM_RECIPE_REGISTER_PROFESSION_FAIL,	// ������ �ͽ� ������ �߸��Ǿ����ϴ�.
	GAME_SCOUTER_MAIN_PARTS_NOT_FOUND,	// ��ī���� ���� ������ ã�� ���߽��ϴ�.
	GAME_ITEM_HOIPOIMIX_FARE_NOT_SET,	// ȣ�����̸ӽŻ��ᰡ ���õǾ����� �ʽ��ϴ�. 
	GAME_ITEM_HOIPOIMIX_FARE_CAN_NOT_SET,	// ȣ�����̸ӽŻ��� ������ ĳ���ӽŸ� �����մϴ�. 
	GAME_ITEM_HOIPOIMIX_FARE_RATE_FAIL,	// ȣ�����̸ӽŻ��ᰡ ������ �ʰ� �Ǿ����ϴ�.
	GAME_ITEM_CANNOT_BUY_NOW,			// ������ �� �ִ� �������� �ƴմϴ�.
	GAME_TRADE_ONLY_PARTY,
	GAME_SKILL_SLOT_FAIL,	
	GAME_SKILL_ID_NULL,
	GAME_SKILL_OWNER_NULL,
	GAME_SKILL_SAME_EXIST,
	GAME_SKILL_NOT_FOUND,
	GAME_ITEM_NOT_PROPER_PLACE_TO_USE,						// It is not a good place to use items.
	GAME_ITEM_YOU_HAVE_NO_RELATED_QUEST_TO_USE,				// I do not have any quests related to items.
	GAME_CANT_DO_THAT_TO_FREE_PVP_ZONE_TARGET,
	GAME_CAN_BE_CAST_ONLY_ON_PLAYER,
	GAME_NO_REVIVAL_AFTEREFFECT_TO_REMOVE,
	GAME_REVIVAL_AFTEREFFECT_IS_TOO_STRONG_TO_BE_CURED,
	GAME_ITEM_CHANGE_BATTLE_ATTRIBUTE_NO_SUBJECT_ITEM,
	GAME_ITEM_CHANGE_BATTLE_ATTRIBUTE_WRONG_ITEM_TYPE,
	GAME_ITEM_CHANGE_BATTLE_ATTRIBUTE_WRONG_SUB_ITEM_TYPE,
	GAME_ITEM_CHANGE_BATTLE_ATTRIBUTE_WRONG_RANK,
	GAME_ITEM_CHANGE_BATTLE_ATTRIBUTE_WRONG_LV,
	GAME_SHOP_NOT_FOUND,
	GAME_SHOP_SO_FAR,
	GAME_SHOP_NOT_CLOSED,					// ������ ���������Դϴ�.
	GAME_SHOP_ITEM_INVALID,					// �ȼ� ���� ������ �Դϴ�.
	GAME_MOVE_CANT_GO_THERE,		// �� �� ���� ��ġ�Դϴ�
	GAME_WORLD_NOT_EXIST,				// �������� �ʴ� ���� �Դϴ�.
	GAME_MOVE_CANT_ALLOWED_ENTER,		// ������ ������ �ʽ��ϴ�.
	GAME_WORLD_CANT_MOVE_AGAIN,								// ���忡 ������ �� �� ���� �����Դϴ�.
	GAME_PARTY_ALREADY_IN_PARTY,						// �̹� ��Ƽ�� ���� �ֽ��ϴ�.
	GAME_PARTY_ANOTHER_PLAYER_IS_INVITING_YOU,				// �ٸ� �÷��̾ �̹� ����� �ʴ��ϰ� �ֽ��ϴ�.
	GAME_PARTY_ANOTHER_PARTY_IS_INVITING_YOU,				// �ٸ� ��Ƽ�� �̹� ����� �ʴ��ϰ� �ֽ��ϴ�.
	GAME_PARTY_NOT_PROPER_PARTY_NAME_LENGTH,				// ��Ƽ �̸� ���̰� �������� �ʽ��ϴ�.
	GAME_PARTY_PARTY_NAME_HAS_INVALID_CHARACTER,			// ��Ƽ �̸��� ��� �Ұ����� ���ڰ� ���ԵǾ� �ֽ��ϴ�.
	GAME_PARTY_NOT_CREATED_FOR_SOME_REASON,					// �ý��� ������ ��Ƽ�� �������� �ʾҽ��ϴ�.
	GAME_PARTY_YOU_ARE_NOT_IN_PARTY,						// ��Ƽ�� ���� ���� �ʽ��ϴ�.
	GAME_PARTY_ONLY_ALLOWED_TO_PARTY_LEADER,				// ��Ƽ ������ ����� �� �ִ� ����Դϴ�.
	GAME_PARTY_NOT_AVAILABLE_OPERATION_RIGHT_NOW,			// ��Ƽ�� �����ϰ� �ִ� �۾��� ������ �����մϴ�.
	GAME_PARTY_NO_SUCH_A_PLAYER,							// �������� �ʴ� �÷��̾��Դϴ�.
	GAME_PARTY_TARGET_ALREADY_IN_PARTY,						// ������ �̹� ��Ƽ�� ���� �ֽ��ϴ�.
	GAME_PARTY_TARGET_ALREADY_HAS_INVITATION,				// ������ �̹� ��Ƽ �ʴ븦 ���� �����Դϴ�.
	GAME_PARTY_NO_ROOM_FOR_NEW_MEMBER,						// �� �̻� ����� ���� �� �����ϴ�.
	GAME_PARTY_MEMBER_IS_ALREADY_REGISTERED_TIMEQUEST,		// ������ Ÿ�Ӹӽ� ����Ʈ�� �̹� ��ϵǾ� �ֽ��ϴ�.
	GAME_PARTY_YOU_HAVE_NO_INVITATION,						// ����� ��Ƽ�κ��� �ʴ븦 ���� ���°� �ƴմϴ�.
	GAME_PARTY_INVITOR_PLAYER_IS_IN_A_PARTY,				// ����� �ʴ��ߴ� �÷��̾ ã�� �� �����ϴ�.
	GAME_PARTY_NO_SUCH_A_PARTY,								// ��Ƽ�� �����ϱ� �ʽ��ϴ�.
	GAME_PARTY_COULDNT_JOIN_FOR_SOME_REASON,				// �ý��� ������ ��Ƽ�� ������ �� �������ϴ�.
	GAME_PARTY_NO_SUCH_A_PLAYER_IN_THE_PARTY,				// ��Ƽ�� �������� �ʴ� �÷��̾��Դϴ�.
	GAME_PARTY_COULDNT_KICK_OUT_FOR_SOME_REASON,			// �ý��� ������ ����� ������ Ż���ų �� �������ϴ�.
	GAME_PARTY_CANT_KICK_OUT_HIMSELF,						// �ڱ� �ڽ��� ������ Ż���ų �� �����ϴ�.
	GAME_PARTY_YOU_ARE_ALREADY_A_LEADER,					// �̹� �ڽ��� ��Ƽ �����Դϴ�.
	GAME_PARTY_COULDNT_ASSIGN_A_LEADER_FOR_SOME_REASON,		// �ý��� ������ ����� ������ ������ �� �������ϴ�.
	GAME_PARTY_COULDNT_BE_DONE_FOR_SOME_REASON,				// �ý��� ������ ��û�� ó���� �� �������ϴ�.
	GAME_PARTY_ZENNY_IS_LOCKED_RIGHT_NOW,					// ���� �κ��丮�� ���ϸ� ������ �� ���� �����Դϴ�.
	GAME_PARTY_THE_ITEM_IS_LOCKED,							// �������� ������ �� �����ϴ�.
	GAME_PARTY_YOU_DONT_BELONG_TO_THE_PARTY,				// ����� ��Ƽ�� ���� ���� ���� �� �����ϴ�.
	GAME_PARTY_YOU_DONT_HAVE_THAT_MUCH_ZENNY,				// �׸�ŭ�� ���ϸ� ������ ���� �ʽ��ϴ�.
	GAME_PARTY_ONLY_EQUIP_ITEM_AVAILABLE_IN_THAT_SLOT,		// ���� ������ �����۸� ����� �� �ִ� �����Դϴ�.
	GAME_PARTY_ZENNY_DOESNT_SATISFY_THE_CONDITION,			// ���ϰ� ������ ������ ������Ű�� �ʽ��ϴ�.
	GAME_PARTY_MEMBER_ZENNY_IS_IN_TRANSACTION,				// ���ϸ� ����� �� ���� ������ ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_UNKNOWN_ZENNY_LOOTING_METHOD,				// �߸��� ���� �й� ����Դϴ�.
	GAME_PARTY_UNKNOWN_ITEM_LOOTING_METHOD,					// �߸��� ������ �й� ����Դϴ�.
	GAME_PARTY_CANT_CHANGE_LOOTING_METHOD_YET,				// �ٽ� ����ǰ �й� ����� �ٲ� �� ���� ������ �ð��� �ʿ��մϴ�.
	GAME_PARTY_NOBODY_CANT_RECEIVE_ITEM_RIGHT_NOW,			// �������� ���� �� �ִ� ����� �ƹ��� �����ϴ�.
	GAME_PARTY_NO_EMPTY_SPACE_IN_INVENTORY,					// �κ��丮�� �� ������ �����ϴ�.
	GAME_PARTY_NO_EMPTY_SPACE_IN_PARTY_INVENTORY,			// ��Ƽ �κ��丮�� �� ������ �����ϴ�.
	GAME_PARTY_MEMBER_IS_TOO_FAR,							// ����� �ʹ� �ָ� ������ �ֽ��ϴ�. ����Ʈ ���� �Ҷ� ��� by niam
	GAME_PARTY_INVITING_IS_NOT_ALLOWED,						// �� ��Ƽ������ �ʴ밡 ������ �ʽ��ϴ�.
	GAME_PARTY_LEAVING_IS_NOT_ALLOWED,						// �� ��Ƽ������ Ż�� ������ �ʽ��ϴ�.
	GAME_PARTY_KICKING_OUT_IS_NOT_ALLOWED,					// �� ��Ƽ������ ���� Ż�� ������ �ʽ��ϴ�.
	GAME_PARTY_APPOINTING_A_LEADER_IS_NOT_ALLOWED,			// �� ��Ƽ������ ��Ƽ�� �Ӹ��� ������ �ʽ��ϴ�.
	GAME_PARTY_SHARETARGET_NOTFINDOBJECT,					// �ش� ������Ʈ�� �����ϴ� [3/28/2008 SGpro]
	GAME_PARTY_SHARETARGET_SLOTID_FAIL,						// ����Ÿ�� ����ID�� �߸��Ǿ����ϴ�[3/28/2008 SGpro]
	GAME_PARTY_DUNGEON_IN_PLAYER_FOUND,						// 1372 // ������ ���� �����ִ� ĳ���Ͱ� �ֽ��ϴ�. 
	GAME_PARTY_DICE_FAIL,									// ��Ƽ �ֻ��� ��� ����
	GAME_PARTY_INVEN_ITEM_EXIST,							// ��Ƽ�κ��� �������� �����ֽ��ϴ�.
	GAME_PARTY_ITEM_DICE_USING_NOW,							// ��Ƽ ������ ���̽��� ������Դϴ�.
	GAME_PARTY_ITEM_DICE_NOT_USING_NOW,						// ��Ƽ ������ ���̽��� �� ������Դϴ�.
	GAME_PARTY_DUNGEON_MIN_PLAYER_FAIL,						// ��Ƽ ������ �ּ��ο��� �����մϴ�.
	GAME_PARTY_DUNGEON_OUT_RESERVED,						// ��Ƽ ���� ������ ���� NTL_MIN_DUNGEON_PARTYOUT_TIME ���ҽ��ϴ�..(���ǵ� ���� �ٲ�� �ݵ�� ��ȹ�� GUI ����ڿ��� �˷� �ּ���)
	GAME_PARTY_MEMBER_NOT_SAME,								// ��Ƽ�κ��� ����� �ٸ��ϴ�.
	GAME_PARTY_DUNGEON_ENTER_PARTY_FAIL,					// ��Ƽ������ ���÷��� ��Ƽ�� �����Ͻʽÿ�.
	GAME_PARTY_DUNGEON_IN_CHANGE_DIFF_NOW,					// ��Ƽ�����ȿ��� ���̵� ������ �Ұ����մϴ�.
	GAME_PARTY_CANT_INVITE_YOURSELF,						// �ڱ� �ڽ��� ��Ƽ�� �ʴ��� �� �����ϴ�.
	GAME_PARTY_CANT_INVITE_IN_WORLD,
	GAME_PARTY_CANT_INVITE_FOR_SOME_REASON,
	GAME_PARTY_DUNGEON_IS_NOT_CREATED,
	GAME_PARTY_DUNGEON_DIFF_NOT_USE,
	GAME_PARTY_CANT_INVITE_TARGET_SANDBAG,
	GAME_PARTY_CANT_JOIN_TARGET_SANDBAG,
	GAME_PARTY_DUNGEON_BEING_INITIALIZED,
	GAME_PARTY_DUNGEON_ENTER_USING_NPC,
	GAME_PARTY_WRONG_CHARM_INVENTORY_SPECIFIED,				// ���� �κ��丮�� �߸� �����Ǿ����ϴ�.
	GAME_PARTY_CHARM_INVENTORY_IS_OPEN,						// ���� �κ��丮�� ���� �ֽ��ϴ�.
	GAME_PARTY_CHARM_INVENTORY_IS_CLOSED,					// ���� �κ��丮�� ���� �ֽ��ϴ�.
	GAME_PARTY_CHARM_INVENTORY_SLOT_IS_NOT_EMPTY,			// ���� �κ��丮 ������ ��� ���� ���� �����Դϴ�.
	GAME_PARTY_CHARM_INVENTORY_SLOT_IS_EMPTY,				// ���� �κ��丮 ������ ��� �ִ� �����Դϴ�.
	GAME_PARTY_NO_SUCH_A_VICTIM_ITEM,						// �������� �ʴ� ���� �������Դϴ�.
	GAME_PARTY_UNIDENTIFIED_VICTIM_ITEM,					// ���� �������� ������ ���� ���� �����Դϴ�.
	GAME_PARTY_VICTIM_ITEM_IS_NOT_YOURS,					// ����� ����� ���� �������� �ƴմϴ�.
	GAME_PARTY_CANT_UNREGISTER_CHARM_DUE_TO_VITIM,			// �̹� ����� ������ �־ ������ �ٽ� ������ �� �����ϴ�.
	GAME_PARTY_VICTIM_ZENNY_HASNT_CHANGED,					// ���� ������ ����� ������ ���� �ٲ��� �ʾҽ��ϴ�.
	GAME_PARTY_YOU_HAVENT_REGISTERED_VICTIM_ZENNY,			// ���ϸ� ���� ������ ����� ���� �����ϴ�.
	GAME_PARTY_TOO_MUCH_VICTIM_ZENNY_TO_UNREGISTER,			// ����� ������ �纸�� ���� ���� ���ϸ� ���������� �߽��ϴ�.
	GAME_PARTY_ONLY_LEADER_CAN_REGISTER_CHARM,				// ������ ��Ƽ ������ ����� �� �ֽ��ϴ�.
	GAME_PARTY_ONLY_CHARM_ITEM_AVAILABLE_IN_THAT_SLOT,		// ���� �����۸� ����� �� �ִ� �����Դϴ�.
	GAME_PARTY_SAME_CHARM_ALREADY_HAS_BEEN_REGISTERED,		// �̹� Ȱ��ȭ�Ǿ� �ִ� ���� �������Դϴ�.
	GAME_PARTY_CHARM_ITEM_HASNT_BEEN_REGISTERED,			// ���� ������ ��ϵǾ� ���� �ʽ��ϴ�.
	GAME_PARTY_CHARM_SLOT_HAS_AN_ITEM_OF_IMPROPER_TYPE,		// ���� ���Կ� ������ �ƴ� �������� ��ϵǾ� �ֽ��ϴ�.
	GAME_PARTY_CHARM_SLOT_HAS_UNKNOWN_CHARM_ITEM,			// ���� ���Կ� �� �� ���� ������ ��ϵǾ� �ֽ��ϴ�.
	GAME_PARTY_ITEMS_DONT_SATISFY_THE_CONDITION,			// ���� �������� ������ ������ ������Ű�� �ʽ��ϴ�.
	GAME_PARTY_MEMBER_DOESNT_HAVE_ENOUGH_CHARM_POINT,		// ����� ���� ����Ʈ���� ���� ����Ʈ�� ���� ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_DOESNT_HAVE_ENOUGH_ZENNY,				// ����� ���Ϻ��� ���� ���ϸ� ���� ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_CHARM_POINT_IS_IN_TRANSACTION,		// ���� ����Ʈ�� ����� �� ���� ������ ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_DOESNT_SATISFY_THE_CONDITION,			// ���� ��� ������ ������Ű�� ���� ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_CHARM_BUFF_REGISTERED_ALREADY,				// �̹� ��ϵ� ���� ������ �ֽ��ϴ�.
	GAME_PARTY_NO_CHARM_BUFF_REGISTERED,					// ��ϵ� ���� ������ �����ϴ�.
	GAME_PARTY_INVALID_INVENTORY_SLOT_INDEX,				// ��Ƽ �κ��丮�� ������ ��ġ�� �߸� �����Ǿ����ϴ�.
	GAME_PARTY_TOO_MANY_CONTRIBUTION_POINTS_TO_INVEST,		// ������ �� �ִ� �⿩���� ������ �Ѿ����ϴ�.
	GAME_PARTY_ONLY_EQUIP_ITEM_ALLOWED_FOR_CHARM_POINT,		// ���� ���������θ� ���� ����Ʈ�� ���� �� �ֽ��ϴ�.
	GAME_PARTY_IDENTIFIED_ITEM_NEEDED_FOR_CHARM_POINT,		// ������ ���������θ� ���� ����Ʈ�� ���� �� �ֽ��ϴ�.
	GAME_PARTY_INVEN_INVEST_ZENNY_NOT_ENOUGH,				// ��Ƽ�κ��� ������ ���� �����մϴ�.
	GAME_PARTY_INVEN_LOCKED,								// ��Ƽ�κ��� �����ϴ�.
	GAME_PARTY_INVEN_ITEM_NON_EXIST,						// ��Ƽ�κ� �ش� ���Կ� ������ �����ϴ�.
	GAME_PARTY_INVEN_DISTRIBUTE_METHOD_NOT_MATCH,			// �й����� ���� �ʽ��ϴ�.
	GAME_PARTY_MEMBER_ZENNY_IS_LOCK,						// ��Ƽ ����� ���ϰ� ��� ���°� �ֽ��ϴ�.
	GAME_PARTY_INVEN_LOCK_FIRST,							// ��Ƽ�κ��� �����ֽ��ϴ�. ���� �ݾ��ֽʽÿ�.
	GAME_PARTY_INVEN_UNDER_INVEST,							// ��Ƽ�κ��� ���ڵ� �ִ�ݾ� ���� ���ƾ��մϴ�.
	GAME_HTB_NO_HTB_RESULT,							// ������ HTB�� �����ϴ�
	GAME_HTB_CANT_FORWARD_ANYMORE,							// ���̻� ������ HTB�ܰ谡 �����ϴ�.
	GAME_HTB_NOT_ENOUGH_RP_BALL,							// RP ������ ������� �ʽ��ϴ�.
	GAME_HTB_YOU_ALREADY_USED_RP_BALL,						// �̹� RP ������ ����� �����Դϴ�.
	GAME_HTB_YOU_HAVE_NO_RELATION_WITH_HTB,					// 1404 // HTB�� ���� ���� �����Դϴ�.
	GAME_WORLD_ENTER_NEED_LOW_LEVEL, // �ش� ������ �����ϱ⿡�� ���� �����Դϴ�.
	GAME_WORLD_ENTER_NEED_HIGH_LEVEL, // �ش� ������ �����ϱ⿡�� ���� �����Դϴ�.
	GAME_WORLD_ENTER_NEED_ITEM, // �ش� ������ �����ϱ����� �ʿ�  �������� �����ϴ�.
	GAME_FREEBATTLE_TARGET_HAS_NO_MATCH, // ����� ������ ������ �� �����ϴ�.
	GAME_FREEBATTLE_WRONG_PLACE, // ������ �� �� ���� �����Դϴ�.
	GAME_FREEBATTLE_ALREADY_HAS_MATCH, // �̹� �������Դϴ�.
	GAME_FREEBATTLE_TARGET_ALREADY_HAS_MATCH, // �̹� �������� ����Դϴ�.
	GAME_FREEBATTLE_CHALLENGE_TIME_REMAIN, // ���� ���� ��� �ð��Դϴ�.
	GAME_FREEBATTLE_CHALLENGE_ACCEPT_DENIED, // ���� ��û�� �������߽��ϴ�.
	GAME_FREEBATTLE_CHALLENGE_ACCEPT_TIME_DENIED, // ���� ��û�� ������ ���� �ʾ� �ڵ����� �����Ǿ����ϴ�.
	GAME_FREEBATTLE_CHALLENGE_WAIT_TIME_DENIED, // ���� ��û�� ���� ������ ���� �ڵ����� �����Ǿ����ϴ�.
	GAME_FREEBATTLE_ERROR_HAS_NO_MATCH, // ����(�����ڵ�) - ������ ������ �� �����ϴ�.
	GAME_FREEBATTLE_ERROR_TARGET_HAS_NO_MATCH, // ����(�����ڵ�)  - ����� ������ ������ �� �����ϴ�.
	GAME_FREEBATTLE_ERROR_WRONG_PEER, // ����(�����ڵ�) - �߸��� ���� ����� ������ �ֽ��ϴ�.
	GAME_FREEBATTLE_ERROR_TARGET_WRONG_PEER, // ����(�����ڵ�) - ����� �߸��� ���� ����� ������ �ֽ��ϴ�.
	GAME_WORLD_ENTER_NEED_REPUTATION, // �ش� ������ �����ϱ����� �ʿ� ���� �����ϴ�.
	GAME_WORLD_NOT_FOUND,			  // �ش� ������ ã�� �� �����ϴ�.
	GAME_WORLD_ENTER_DISAPPROVAL,	 // �ش� ������ ������ �� �����ϴ�.
	GAME_SCOUTER_TARGET_SELF_FAIL,	 // �ڱ� �ڽ��� ������� �Ұ����մϴ�.
	GAME_SCOUTER_TARGET_FAIL_FOR_NPC,
	GAME_ITEM_CANNOT_DELETE,
	GAME_ITEM_LOOTING_FAIL_FOR_DICELOOT,
	GAME_ITEM_DICE_FAIL_NOT_EQUIPED,
	GAME_ITEM_DICE_FAIL_OVERFLOW_PARTYINVEN,
	GAME_ITEM_DICE_FAIL_NOT_FIND,
	GAME_ITEM_DICE_FAIL_INVALID_DICE,
	GAME_ITEM_DICE_FAIL_INVALID_PARTY,
	GAME_ITEM_DICE_FAIL_LIMITED_STATE,


	//////////////////////////////////////////////////////////////////////////
	//
	// Trigger system ���� �޽�����
	//
	//////////////////////////////////////////////////////////////////////////

	GAME_TS_WARNING_NOT_SATISFY_REWARD_CONDITIONS ,	// ���� ���� �� �ִ� ������ �������� ���մϴ�.
	GAME_TS_WARNING_MUST_SELECT_ONE_SEL_REWARD,		// ���� ������ �����մϴ�. �ݵ�� �ϳ��� ���ú����� �����ؾ� �մϴ�.
	GAME_TS_WARNING_PROCESSING_PRE_CONFIRM_REQ,		// ���� ���� ��û�� ó�����Դϴ�. (����)
	GAME_TS_WARNING_NOW_TIME_WAIT,					// ���� ���� ��û�� ó�����Դϴ�. (�ð�)
	GAME_TS_WARNING_OVERFLOW_MAX_TS_NUM,			// ���డ���� �ִ� Ʈ���� ������ �Ѿ����ϴ�.

	GAME_TS_WARNING_SYSTEM_WAIT,					// �ٸ� �ý��۰� �浹�� �Ͼ ���. ��� ��ٷ� �ּ���.
	GAME_TS_WARNING_INVENTORY_IS_LOCK,				// ������ �κ��丮�� lock�� �ɷ� ����
	GAME_TS_WARNING_INVENTORY_IS_FULL,				// ������ �κ��丮�� ����á��
	GAME_TS_WARNING_QUEST_INVENTORY_IS_FULL,		// ����Ʈ �κ��丮�� ���� á��
	GAME_TS_WARNING_INVALID_QUEST_ITEM_DELETE_COUNT,// ����Ʈ �������� ���� ��û ������ Ʋ��
	GAME_TS_WARNING_REWARD_FAIL,					// ������ ���� ����(�Ƹ� �� �޽����� ������ ��������)
	GAME_TS_WARNING_EQUIP_SLOT_NOT_EMPTY,			// ��� ������ ������� �ʽ��ϴ�.
	GAME_TS_WARNING_EQUIP_SLOT_LOCK,				// ��� ������ ����ֽ��ϴ�.
	GAME_TS_WARNING_CLASS_CHANGE_CLASS_FAIL,		// ���� Ŭ������ �ٸ�
	GAME_TS_WARNING_CLASS_CHANGE_LEVEL_FAIL,		// ���� ������ �ȵ�
	GAME_TS_WARNING_ESCORT_EXCEED_MEMBER,			// ��� �ʰ�
	GAME_TS_WARNING_ESCORT_NOT_SHARED,				// ���� ��尡 �ƴ�
	GAME_TS_WARNING_ESCORT_TRIGGER_TYPE_WRONG,		// Ʈ���� Ÿ���� �ٸ�
	GAME_TS_WARNING_ESCORT_TRIGGER_ID_WRONG,		// Ʈ���� ���̵� �ٸ�
	GAME_TS_WARNING_ESCORT_PARTY_WRONG,				// ��Ƽ�� �ٸ�
	GAME_TS_WARNING_ESCORT_ALREADY_EXIST,			// �̹� ��ϵǾ� ����
	GAME_TS_WARNING_TMQ_COUPON_NOT_ENOUGH,			// TMQ���� ������ ������

	GAME_TS_WARNING_WPS_ALREDY_USED_BY_OTHER_PLAYER,// �̹� �ٸ� ������ �������Դϴ�.
	GAME_TS_WARNING_WPS_CAN_NOT_JOIN_NOW,			// ������ ���� �� �� �����ϴ�.

	GAME_TS_WARNING_CAN_NOT_FIND_VISIT_EVT,			// ���õ� �湮 �̺�Ʈ�� �����ϴ�. for visit event
	GAME_TS_WARNING_ALREADY_VISITED,				// �̹� �Ϸ��߽��ϴ�. for visit event
	GAME_TS_WARNING_WRONG_CONDITION,				// ���� ������ ���� �ʽ��ϴ�.
	GAME_TS_WARNING_CANNOT_FIND_QUEST_ITEM,			// ����Ʈ �������� ã�� �� �����ϴ�.
	GAME_TS_WARNING_DEL_FORBIDDENDEL_QUEST_ITEM,	// ����� ���� ����Ʈ �������Դϴ�.

	GAME_TS_WARNING_IMPROPER_NUMBER_OF_SEL_REWARD,
	GAME_TS_WARNING_ROLLBACK_FAIL,
	GAME_TS_WARNING_ROLLBACK,
	GAME_TS_WARNING_NOT_YET_PROCESSED,

	//-----------------------------------------------------------------
	GAME_PARTYMATCHING_ROLEPLAY_CANCEL,
	GAME_PARTYMATCHING_ROLEPLAY_HAVE_NO_CHOICE,
	GAME_PARTYMATCHING_ROLEPLAY_INVALD,
	GAME_PARTYMATCHING_INVITE_FAIL,
	GAME_PARTYMATCHING_ENTER_DUNGEON_AGREE_FAIL,
	GAME_PARTYMATCHING_ALREADY_REGISTERED,
	GAME_PARTYMATCHING_ANY_MEMBER_IN_DYNAMIC_WORLD,
	GAME_PARTYMATCHING_ROLEPLAY_NOT_SELECTED,
	GAME_PARTYMATCHING_REGISTER_WRONG_STATE,
	GAME_PARTYMATCHING_PARTY_IS_NOT_REGISTER,
	GAME_PARTYMATCHING_PARTY_IS_REGISTER_ALREADY,

	//-----------------------------------------------------------------

	GAME_TS_ERROR_RUN_ERROR,						// Ʈ���� ���� ����
	GAME_TS_ERROR_CS_SCRIPT_MISSMATCH,				// ������ �����ؾ��� �����̳� Ÿ���� CS ���� ��ġ���� �ʽ��ϴ�.
	GAME_TS_ERROR_NO_IMP_CONT_TYPE,					// �������� ���� �����̳� Ÿ���� ���Ǿ����ϴ�.
	GAME_TS_ERROR_CANNOT_CREATE_TS_OBJECT,			// Ʈ���� ������Ʈ ���� ����.
	GAME_TS_ERROR_CANNOT_FIND_TID,					// Ʈ���Ÿ� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_FIND_TCID,					// �����̳ʸ� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_PROGRESS_REPEAT_QUEST,		// �ݺ� ����Ʈ�� ������ �ѹ��� ������ �� �ֽ��ϴ�

	GAME_TS_ERROR_SYSTEM,							// �Ϲ����� �ý��ۻ��� ����[����]
	GAME_TS_ERROR_TRIGGER_SYSTEM,					// Trigger System ���� ������ �� ���
	GAME_TS_ERROR_QUERY_SERVER,						// ���� ���� ����
	GAME_TS_ERROR_CANNOT_FIND_ITEM_TBLIDX,			// ���̺��� �������� ã���� ����
	GAME_TS_ERROR_CANNOT_FIND_SKILL_TBLIDX,			// ��ų�� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_LEARN_SKILL,				// ��ų�� ��� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_ADD_QUEST_EVENT_DATA,		// �̺�Ʈ �������� �̺�Ʈ�� ����� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_FIND_QUEST_ITEM,			// ����Ʈ �������� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CREATE_ITEM_COUNT_OVER,			// �ѹ��� ������ �� �ִ� ���� ������ �Ѿ���.
	GAME_TS_ERROR_DELETE_ITEM_COUNT_OVER,			// �ѹ��� ������ �� �ִ� ���� ������ �Ѿ���
	GAME_TS_ERROR_CANNOT_FIND_PC,					// PC�� ã�� �� ����
	GAME_TS_ERROR_TRIGGER_OBJECT_NOT_EXIST,			// �������� �ʴ� Ʈ���� ������Ʈ �Դϴ�.
	GAME_TS_ERROR_TRIGGER_OBJECT_INVALID_FUNCFLAG,	// ����� �ùٸ��� ���� Ʈ���� ������Ʈ�Դϴ�.

	//-----------------------------------------------------------------
	GAME_PET_CANT_MAKE_MORE_SUMMON_PET,			// �� �̻� ��ȯ���� �θ� �� �����ϴ�.
	GAME_PET_CANT_MAKE_MORE_ITEM_PET,					 // �� �̻� ������ ���� �θ� �� �����ϴ�.
	GAME_PET_COULDNT_BE_DONE_FOR_SOME_REASON,			// �ý��� ������ ��û�� ó���� �� �����ϴ�.
	GAME_PET_TARGET_IS_NOT_SPAWNED,						// ����� ��ȯ�Ǿ� ���� �ʽ��ϴ�.
	//-----------------------------------------------------------------
	GAME_GUILD_NO_GUILD_MANAGER_NPC_FOUND,			// ��� �Ŵ��� NPC�� ã�� �� �����ϴ�.
	GAME_GUILD_NOT_GUILD_MANAGER_NPC,						// ��� �Ŵ��� NPC�� �ƴմϴ�.
	GAME_GUILD_GUILD_MANAGER_IS_TOO_FAR,					// ������ ��� �Ŵ����� �ʹ� �־� ��ȭ�� �� �� �����ϴ�.
	GAME_GUILD_NEED_MORE_ZENNY_FOR_NEW_GUILD,				// ��� ������ ���ؼ��� ���ϰ� �� �ʿ��մϴ�.
	GAME_GUILD_NOT_PROPER_GUILD_NAME_LENGTH,				// ��� �̸� ���̰� �������� �ʽ��ϴ�.
	GAME_GUILD_GUILD_NAME_HAS_INVALID_CHARACTER,			// ��� �̸��� ��� �Ұ����� ���ڰ� ���ԵǾ� �ֽ��ϴ�.
	GAME_GUILD_NOT_PROPER_GUILD_NAME,						// ��� �̸��� �������� �ʽ��ϴ�.
	GAME_GUILD_SAME_GUILD_NAME_EXIST,						// ���� ��� �̸��� �����մϴ�.
	GAME_GUILD_NOT_EXIST,									// �ش� ��尡 �������� �ʽ��ϴ�.
	GAME_GUILD_NON_EXISTING_GUILD_FUNCTION,					// �� �� ���� ��� ����Դϴ�.

	GAME_GUILD_ALREADY_HAS_GUILD_FUNCTION,					// �̹� ������ �ִ� ��� ����Դϴ�.
	GAME_GUILD_NEED_PREREQUISITE_GUILD_FUNCTION,			// �� �ܰ� ���� ��� ����� ȹ���� ���¿��� �մϴ�.
	GAME_GUILD_NEED_MORE_GUILD_POINT,						// �� ���� ��� ����Ʈ�� �ʿ��մϴ�.
	GAME_GUILD_NEED_MORE_ZENNY,								// �� ���� ���ϰ� �ʿ��մϴ�.
	GAME_GUILD_NEED_LEVEL_MORE,								// ������ �����մϴ�.
	GAME_GUILD_GIVE_ZENNY_NOT_MATCHED,						// ��� ����Ʈ�� ������ؼ��� 1000���� ������ �������� 1000 �̻��̿��� �մϴ�.
	GAME_GUILD_NO_GUILD_FOUND,								// ��忡 ���ԵǾ� ���� �ʽ��ϴ�.
	GAME_GUILD_MARK_ARLEADY_CREATED,						// ��帶ũ�� �̹� ���� �Ǿ� �ֽ��ϴ�.
	GAME_GUILD_MARK_NOT_CREATED,							// ��帶ũ�� ���� �Ǿ� ���� �ʽ��ϴ�.
	GAME_GUILD_NEED_DOJO_NOT_FOUND,							// ������ ã�� �� �����ϴ�.

	GAME_GUILD_MAKE_DOJO_ALREADY_TAKEN,						// �̹� ���İ� ������ �����ϰ� �־� ������ ������ �� �����ϴ�.
	GAME_GUILD_NEED_GUILD_FUNCTION,							// ����� ����� �����ϴ�. ���ȹ���� �����Ͻʽÿ�.
	GAME_GUILD_NO_DOJO_MANAGER_NPC_FOUND,					// ���� �Ŵ��� NPC�� ã�� �� �����ϴ�.
	GAME_GUILD_NOT_DOJO_MANAGER_NPC,						// ���� �Ŵ��� NPC�� �ƴմϴ�.
	GAME_GUILD_DOJO_MANAGER_IS_TOO_FAR,						// ������ ���� �Ŵ����� �ʹ� �־� ��ȭ�� �� �� �����ϴ�.
	GAME_GUILD_NON_EXISTING_DOJO_FUNCTION,					// �� �� ���� ���� ����Դϴ�.
	GAME_GUILD_MAKE_DOJO_NOT_TAKEN,							// ������ ������ �����ϴ�.
	GAME_GUILD_DOGI_NOT_CREATED,							// ���� ���� �Ǿ� ���� �ʽ��ϴ�.
	GAME_GUILD_DOGI_ARLEADY_CREATED,						// ������ �̹� ���� �Ǿ� �ֽ��ϴ�.
	GAME_GUILD_ALREADY_HAS_DOJO_FUNCTION,					// �̹� ������ �ִ� ���� ����Դϴ�.

	GAME_GUILD_NEED_PREREQUISITE_DOJO_FUNCTION,				// �� �ܰ� ���� ���� ����� ȹ���� ���¿��� �մϴ�.
	GAME_GUILD_HOIPOIROCK_ITEM_NOT_FOUND,					// ȣ�����̶� �������� ã�� ���߽��ϴ�.
	GAME_GUILD_HOIPOIROCK_ITEM_NOT_MATCHED,					// ȣ�����̶� �������� �ƴմϴ�.
	GAME_GUILD_HOIPOIROCK_ITEM_COUNT_FAIL,					// ȣ�����̶� ������ ������ �����մϴ�.
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGE_HAVE,				// ���� ��Ż ��û��尡 �̹� �ֽ��ϴ�.
	GAME_GUILD_DOJO_YOU_ARE_NOT_A_PARTY_LEADER,				// ������ ������ ���� �ְ������� �����մϴ�.
	GAME_GUILD_DOJO_YOU_ARE_NOT_OWNNER,						// ������ ������ �ƴմϴ�.
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGE_STATUS_FAIL,			// ������Ż�� ��û���� ���°� �ƴմϴ�. 
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGE_HAVE_DOJO,			// ������ ������ ���Ĵ� ��Ż���� ��û�� �� �����ϴ�.
	GAME_GUILD_DOJO_SCRAMBLE_REJECT_STATUS_FAIL,			// ������Ż�� ��û�źΰ��� ���°� �ƴմϴ�. 

	GAME_GUILD_DOJO_NOT_FOUND_TABLE,						// �������̺��� ã���� �����ϴ�. 
	GAME_GUILD_DOJO_NEED_FUNCTION,							// ���弳�� ������ �����ϴ�. ����ȹ���� �����Ͻʽÿ�.
	GAME_GUILD_DOJO_SCRAMBLE_MAX_COUNT_OVER,				// ������Ż���� ���� �ִ� �ο� ���� �ʰ� �߽��ϴ�.	
	GAME_GUILD_DOJO_NOT_FOUND,								// �ش� ������ ã�� �� �����ϴ�.	
	GAME_GUILD_DOJO_SELF_SCRAMBLE_FAIL,						// �ڽ��� ���� ���忡 ��Ż���� ��û�Ҽ� �����ϴ�.	
	GAME_GUILD_DOJO_SCRAMBLE_NOT_A_PARTY_LEADER,			// ��Ż���� ��û�� �ְ����� �� �� �ֽ��ϴ�.
	GAME_GUILD_DOJO_YOU_ARE_NOT_ENOUGH_REPUTATION,			// ��Ż���� ��û�ϱ⿡�� ���� ����Ʈ�� ������� �ʽ��ϴ�. 
	GAME_GUILD_DOJO_YOU_ARE_NOT_ENOUGH_ZENNY,				// ��Ż���� ��û�ϱ⿡�� ������ ���ϰ� �����մϴ�. 
	GAME_GUILD_DOJO_YOU_ARE_ARLREADY_REJECT,				// ��Ż���� �źδ��� ��û�� �� ���� �����Դϴ�. ���� ��û�Ⱓ�� �����մϴ�. 
	GAME_GUILD_DOJO_YOU_DONT_BELONG_TO_ANY_DOJO,			// ���忡 ���� ���� �ʽ��ϴ�.

	GAME_GUILD_DOJO_YOU_DONT_BELONG_TO_THAT_DOJO,			// �ش� ���忡 ���� ���� �ʽ��ϴ�.
	GAME_GUILD_DOJO_YOU_ARE_ARLREADY_REJECT_ONE_TIME,		// ��Ż�� �źδ� �ѹ��� �����մϴ�.
	GAME_GUILD_DOJO_YOU_CANT_ATTACK_YOUR_TEAM_SEAL,			// �ڽ��� ���� ���� ������ ������ �� �����ϴ�.
	GAME_GUILD_DOJO_SEAL_CANT_BE_ATTACKED,					// ������ ������ ������ �� �����ϴ�.
	GAME_GUILD_DOJO_TOO_MANY_ATTACKER_ON_SEAL,				// �̹� ���� �÷��̾ ������ �����ϰ� �ֽ��ϴ�.
	GAME_GUILD_YOUR_GUILD_CANT_DO_DOJO_TELEPORT,			// 2155 // �ڷ����� ����� ����� �� ���� ���Ŀ� ���� �ֽ��ϴ�.
	GAME_GUILD_DOJO_FUNCTION_ADD_FIRST,						// ������ ����� ���� �����Ͻ� �� ����� �ּ���. 
	GAME_GUILD_DOJO_DOGI_CHANGE_FUNCTION_NEED,
	GAME_GUILD_DOGI_CHANGE_FUNCTION_NEED,
	GAME_GUILD_DOJO_ALREADY_HAVE,
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGE_ONLY_ONETIME,
	GAME_GUILD_DOJO_SCRAMBLE_SEAL_INVEN_NOT_FOUND,
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGER_CANT_DO,

	//-----------------------------------------------------------------
	GAME_ROOM_ENTER_EXCEED_MAX_MEMBER_COUNT,			// �濡 �ο��� ���� á���ϴ�.
	GAME_ROOM_ENTER_EXCEED_MAX_ROOM_COUNT,					// ���̻� ���� ���� �� �����ϴ�.
	GAME_ROOM_ENTER_NEED_MORE_MEMBER,						// �濡 �ο��� �� �ʿ� �մϴ�.
	GAME_ROOM_ENTER_TOO_LOW_LEVEL,							// �濡 �����ϱ⿡�� ������ �ʹ� �����ϴ�
	GAME_ROOM_ENTER_TOO_HIGHTLEVEL,							// �濡 �����ϱ⿡�� ������ �ʹ� �����ϴ�
	GAME_ROOM_ENTER_MUST_HAVE_NEED_ITEM,					// �濡 �����ϱ����� �ʿ� �������� �����ϴ�
	GAME_ROOM_ENTER_MUST_HAVE_NEED_ZENNY,					// �濡 �����ϱ����� ���ϰ� �����մϴ�.
	GAME_ROOM_ENTER_ROOM_NOT_EXIST,							// ���� �������� �ʽ��ϴ�.
	GAME_ROOM_ENTER_ROOMMANAGER_NOT_EXIST,					// �Խ����� �������� �ʽ��ϴ�.
	GAME_ROOM_ENTER_NEED_MORE_PARTY_MEMEBER,				// ��Ƽ����� �� �ʿ��մϴ�.
	GAME_ROOM_ENTER_NOT_MATCH_MEMBER,						// ���� ����� �ƴմϴ�.
	GAME_ROOM_ENTER_NOT_WAIT_STATE,							// ��� ���°� �ƴմϴ�.
	GAME_ROOM_ENTER_FAIL,									// ������ �õ��� �����Ͽ����ϴ�
	GAME_ROOM_LEAVE_LIMIT_TIME_ELAPSED,						// ���뿡�� ������ ���� �ð� �Դϴ�
	GAME_ROOM_LEAVE_FAIL,									// ���� ������ ����
	GAME_ROOM_NOT_OWNER,									// ���� �����ڰ� �ƴմϴ�.
	GAME_ROOM_CAN_NOT_FIND_PARTY_MEMBER,					// ��Ƽ����� ã�� �� �����ϴ�.

	GAME_RANKBATTLE_NOR_REGISTERED,							// ��ϵǾ� ���� �ʽ��ϴ�.
	GAME_RANKBATTLE_CANNOT_LEAVE_NOW,						// ��� �� �� �����ϴ�.
	GAME_RANKBATTLE_CANNOT_LEAVE_IN_MATCH,					// ����߿��� ����� �� �����ϴ�.
	GAME_RANKBATTLE_CANNOT_FIND_ARENA,						// ������� ã�� �� �����ϴ�.
	GAME_RANKBATTLE_CANNOT_FIND_OPPONENT,					// ��븦 ã�� �� �����ϴ�.
	GAME_RANKBATTLE_MEMBER_ALREADY_JOINED_RANKBATTLE,		// ��Ƽ���� �̹� ��ũ��Ʋ ���Դϴ�.
	GAME_RANKBATTLE_ARENA_IS_FULL,							// ����ִ� ������� �����ϴ�.
	GAME_RANKBATTLE_OBJECT_IS_TOO_FAR,						// �ʹ� �ָ� ������ �ֽ��ϴ�.

	GAME_RANKBATTLE_NO_REMAIN_COUNT,						//new 2225

	GAME_MATCH_CAN_NOT_USE_SKILL_IN_THIS_WORLD,				// ���� ���忡���� ����� �� ���� ��ų�Դϴ�.
	GAME_MATCH_CAN_NOT_USE_SKILL_IN_OUTOFAREA,				// ����϶��� ��ų�� ����� �� �����ϴ�.
	GAME_TIMEQUEST_CANNOT_LEAVE_IN_PARTY_WHEN_PLAYING_RANKBATTLE,	// ��ũ��Ʋ ���϶����� ��Ƽ���� ���� �� �����ϴ�.

	
	//-----------------------------------------------------------------
	GAME_TIMEQUEST_WORLD_NOT_FOUND,					// Ÿ�Ӹӽ� ����Ʈ�� �ش��ϴ� ���带 ã�� �� �����ϴ�
	GAME_TIMEQUEST_ROOM_NOT_FOUND,							// Ÿ�Ӹӽ� ����Ʈ ������ ã�� �� �����ϴ�
	GAME_TIMEQUEST_ALREADY_JOINED,							// Ÿ�Ӹӽ� ����Ʈ ���ǿ� �̹� �����ϰ� �ֽ��ϴ�
	GAME_TIMEQUEST_HAVE_NO_JOIN_ROOM,						// Ÿ�Ӹӽ� ����Ʈ ���ǿ� �����ϰ� ���� �ʽ��ϴ�
	GAME_TIMEQUEST_CANT_MAKE_PARTY,							// Ÿ�Ӹӽ� ����Ʈ�� �ڵ� ��Ƽ�� ������ �� �����ϴ�.
	GAME_TIMEQUEST_NEED_MORE_MEMBER,						// Ÿ�Ӹӽ� ����Ʈ�� �� �ο��� ������� �ʽ��ϴ�
	GAME_TIMEQUEST_NOT_ALLOWED_MEMBER,						// Ÿ�Ӹӽ� ����Ʈ�� ������ �㰡���� ���� ��� �Դϴ�.
	GAME_TIMEQUEST_EXCEED_MAX_MEMBER_COUNT,					// Ÿ�Ӹӽ� ����Ʈ �����ִ� �ο��� �ʰ��Ǿ����ϴ�.
	GAME_TIMEQUEST_TOO_LOW_LEVEL,							// Ÿ�Ӹӽ� ����Ʈ�� �ϱ����� ������ �ʹ� �����ϴ�.
	GAME_TIMEQUEST_TOO_HIGH_LEVEL,							// Ÿ�Ӹӽ� ����Ʈ�� �ϱ����� ������ �ʹ� �����ϴ�.
	GAME_TIMEQUEST_MUST_HAVE_NEED_ITEM,						// Ÿ�Ӹӽ� ����Ʈ�� �����ϱ����� �������� �����ϴ�
	GAME_TIMEQUEST_MUST_HAVE_NEED_ZENNY,					// Ÿ�Ӹӽ� ����Ʈ�� �����ϱ����� ���ϰ� �����մϴ�.
	GAME_TIMEQUEST_ROOM_NOT_WAIT_STATE,						// Ÿ�Ӹӽ� ����Ʈ ���ǿ� ������ �� �����ϴ�.
	GAME_TIMEQUEST_ROOM_PARTY_JOIN_FAIL,					// Ÿ�Ӹӽ� ����Ʈ ���ǿ� ��Ƽ����� �� �� �����ϴ�.
	GAME_TIMEQUEST_ROOM_PARTY_ALREADY_JOINED,				// Ÿ�Ӹӽ� ����Ʈ ���ǿ� �̹� ��Ƽ����� �Ǿ� �ֽ��ϴ�.
	GAME_TIMEQUEST_ROOM_OUT_OF_ENTER_RANGE,					// Ÿ�Ӹӽ� ����Ʈ�� ���� ������ ������ϴ�.
	GAME_TIMEQUEST_ROOM_CANNOT_TELEPORT_NOW,				// ������ Ÿ�Ӹӽ��� ��ġ�� �̵��� �� �����ϴ�.
	GAME_TIMEQUEST_DAYRECORD_IS_ALREADY_RESET,				// ���̷��ڵ� ������ �̹� ó���Ǿ����ϴ�.
	GAME_TIMEQUEST_WORLD_ENTER_FAIL,						// Ÿ�Ӹӽ� ����Ʈ ������ �����Ͽ����ϴ�.
	GAME_TIMEQUEST_CANNOT_LEAVE_IN_PARTY_WHEN_PLAYING_TMQ,	// Ÿ�Ӹӽ� ����Ʈ�� ���� �� ������ ��Ƽ���� ���� �� �����ϴ�.

	GAME_TIMEQUEST_MEMBER_LIMIT_COUNT_IS_OVER,
	GAME_TIMEQUEST_ERROR,
	GAME_TOO_LOW_MEMBER_LEVEL,
	GAME_TOO_HIGHT_MEMBER_LEVEL,
	GAME_HAVE_NEED_ZENNY_MEMBER,
	GAME_TIMEQUEST_MEMBER_LIMIT_PLUS_COUNT_IS_OVER,

	//-----------------------------------------------------------------
	GAME_TUTORIAL_CHAR_ALREADY_TUTORIAL_ACCOMPLISHED, // ĳ���Ͱ� �̹� Ʃ�丮���� �����߽��ϴ�
	GAME_TUTORIAL_CANT_FIND_TUTORIAL_WAIT_ROOM,				// Ʃ�丮�� ������ ���� ���� �ʽ��ϴ�
	GAME_TUTORIAL_CANT_ENTER_TUTORIAL_WAIT_ROOM,			// Ʃ�丮�� ���뿡 ������ �� �����ϴ�
	GAME_TUTORIAL_YOU_HAVE_NO_JOIN_ROOM,					// Ʃ�丮�� ��⸦ �ϰ� ���� �ʽ��ϴ�.

	//-----------------------------------------------------------------
	GAME_PRIVATESHOP_NOTAUTH,												// ������ �����ϴ�
	GAME_PRIVATESHOP_NOTRUNSTATE,											// ���� ���¿����� ���� �� �� �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_NOT_CREATE_PLACE,							// ���� ������ ���� ���� ��� �Դϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_ANOTHER_PRIVATESHOP,						// ��ó�� �ٸ� ���λ����� �־ ���λ����� �� �� �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_NULL,										// ������ �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_INVENTORY_SAVEITEM_OVER,					// ���� �κ��丮�� �󽽷��� �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_INVENTORY_SLOT_ALREADY_ITEM,				// ���� �κ��丮 ���Կ� �̹� �������� �ֽ��ϴ�
	GAME_PRIVATESHOP_ITEM_NULL,												// �������� �����ϴ�
	GAME_PRIVATESHOP_ITEM_NOTVALID,											// �ȼ� ���� �������Դϴ�
	GAME_PRIVATESHOP_VISITOR_NULL,											// �մ��� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_NOT_MONEY,										// �մԿ� ���� ���ڸ��ϴ�
	GAME_PRIVATESHOP_VISITOR_NOT_INVENTORY_EMPTY,							// �մԿ� �κ��丮 ���Կ� �����۵��� �� �� �ֽ��ϴ�
	GAME_PRIVATESHOP_VISITOR_ALREADYENTER,									// �մ��� �̹� ������ �����߽��ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_NULL,								// �մ��� ���� �������� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_OVER,								// ���̻� �������� ���� �� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_ALREADY,							// �̹� ���� �������Դϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_ALLSELL,							// ������ �����۵��� ��� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_INVENSOLT_SHORTOF,					// �κ��丮�� �� ������ �����մϴ�
	GAME_PRIVATESHOP_VISITOR_FULL,											// ������ �մ��� �� �� �ִ� ���ڸ��� �����ϴ�
	GAME_PRIVATESHOP_OWNER_MONEY_FULL,										// ���� ���� ���� ���̻� �þ�� �����ϴ�
	GAME_PRIVATESHOP_OWNER_THEREISNO,										// ���� ������ �ڸ��� �����ϴ�
	GAME_PRIVATESHOP_OWNER_BUSINESS_REFUSED,								// ������ ������ �ź����̴�
	GAME_PRIVATESHOP_INVENTORY_NOTINVENTTORY,								// �߸��� �κ��丮 �Դϴ�
	GAME_PRIVATESHOP_INVENTORY_SAVEITEM_OVER,								// Inventory�� �� ������ �����ϴ�
	GAME_PRIVATESHOP_STOP_PROGRESS,											// �������Դϴ�
	GAME_PRIVATESHOP_OWNER_BARGAINS,										// ������ �ٸ������ �������Դϴ�
	GAME_PRIVATESHOP_ITEM_TABLE_ITEMID_DIFFERENT,							// �������� �������� �ʽ��ϴ�
	GAME_PRIVATESHOP_ITEM_SELECTITEM_NOTBUSINESS,							// �̹� ������ �������� ������ �� �����ϴ�
	GAME_PRIVATESHOP_OWNER_BUSINESS_NOT_CONSENT,							// ���� ������ ������ �ź��߽��ϴ�
	GAME_PRIVATESHOP_SAMENOT_PRICEFLUCTUATIONSCOUNTER,						// ������ ���� ������ Ƚ���� �մ��� ���� ���� ��Ŷ�� ���� ���� �ٸ��ϴ�.
	GAME_PRIVATESHOP_ZENNY_LOCK,											// �ٸ� ����� Item Buy���̿��� Zenny�� Lock�� �Ǿ����ϴ�. ó���� ���������� ��ٷ� �ּ���
	GAME_PRIVATESHOP_NOT_PROGRESS_COMPLETE,									// ���� ��û�� ó���ɶ����� ���������� ��ٷ� �ּ��� (��Ŷ�� Qry Srv�� �ӹ��� �ִ�)
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_ALREADYBUYANDBUSINESSITEM,			// �̹� �ٸ� �մ��� ������ �������Դϴ�.
	GAME_PRIVATESHOP_PRIVATESHOP_ANOTHER_NPC,								// ��ó�� NPC�� �־ ���λ����� �� �� �����ϴ�

	//-----------------------------------------------------------------
	GAME_MAIL_TARGET_AWAY_STATE,						// ���� �޴� ����� �������̶� ���źҰ����մϴ�.
	GAME_MAIL_NOT_FOUND,									// ���� ã�� ���߽��ϴ�.
	GAME_MAIL_ALREADY_READ,									// ������ �̹� ���� �����Դϴ�.
	GAME_MAIL_INVALID_DEL,									// �ش������ ���� �� �����ϴ�.
	GAME_MAIL_INVALID_RETURN,								// �ش������ ������ �� �����ϴ�.
	GAME_MAIL_INVALID_ACCEPT,								// �ش������ ���� �� ���� �����Դϴ�.
	GAME_MAIL_INVALID_LOCK,									// �ش������ ��ݼ����� ���� �Ұ����մϴ�.
	GAME_MAIL_INVALID_ZENNY,								// ���� �� �ִ� ������ �ѵ��� �ʰ��߽��ϴ�.
	GAME_MAIL_NOT_EXISTING_PLAYER,							// �ش� ĳ���ʹ� �������� ���� ĳ�����Դϴ�.
	GAME_MAIL_CANT_SEND_MAIL_TO_YOURSELF,					// �ڱ� �ڽſ��Դ� ������ ���� �� �����ϴ�.
	GAME_MAIL_MAILING_PARTS_NOT_FOUND,						// ���� ����Ĩ�� �����ϴ�.
	GAME_MAIL_TRANSMIT_PARTS_NOT_FOUND,						// ���� ����Ĩ�� �����ϴ�.
	GAME_MAIL_SCOUTER_FAIL,									// ���������� ���� ��ī���͸� ����� �� ���� �����Դϴ�.
	//new
	GAME_MAIL_INVALID_CHAR_DEL,
	//-----------------------------------------------------------------
	GAME_PORTAL_ARLEADY_ADDED,						// �̵̹�ϵ� ��Ż�Դϴ�.
	GAME_PORTAL_NOT_EXIST,									// �̵�� ��Ż�Դϴ�. 

	GAME_WARFOG_ARLEADY_ADDED,						// �̵̹�ϵ� �������Դϴ�.
	//-----------------------------------------------------------------
	GAME_PROCESSING_DB,						// ���ó�����Դϴ�.
	//-----------------------------------------------------------------
	GAME_RIDE_ON_STATE,						// ���� Ÿ �ִ� ���� �Դϴ�.
	GAME_VEHICLE_CANNOT_WHILE_DRIVING,						// ���� �߿� �� �� �����ϴ�.
	GAME_VEHICLE_ENGINE_ALREADY_STARTED,					// �̹� �õ��� ���� �ֽ��ϴ�.
	GAME_VEHICLE_ENGINE_ALREADY_STOPED,						// �̹� �õ��� ���� �ֽ��ϴ�.
	GAME_VEHICLE_INVALID_FUEL_ITEM,							// 
	GAME_VEHICLE_FAIL_TO_USE_FUEL_ITEM,						// ���� ������ ��뿡 �����߽��ϴ�.
	GAME_VEHICLE_NO_FUEL_ITEM_REMAINING,					// ���� ���� �������� �����ϴ�.
	GAME_VEHICLE_END_BY_USER,								// ������ Ż�Ϳ��� �����⸦ ��û�߽��ϴ�.
	GAME_VEHICLE_END_BY_HIT,								// �ǰ� ���߱� ������ Ż�Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_CONVERTCLASS,						// �������� ���� Ż �Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_TELEPORT,							// �ڷ���Ʈ�� ���� Ż �Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_FORCED,								// Ż �� ���°� ������ Ǯ�Ƚ��ϴ�.
	GAME_VEHICLE_END_BY_TMQ,								// TMQ ���¿� �����ϱ� ������ Ż�Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_FORBIDDEN_ZONE,						// Ż ���� ������ �ʴ� �����Դϴ�.
	//new
	GAME_VEHICLE_NOT_ON_VEHICLE,
	GAME_VEHICLE_WILL_GET_OFF_SOON,

	//-----------------------------------------------------------------
	GAME_PETITION_NOTAUTH,							//������ �����ϴ�
	GAME_PETITION_TOO_LONG_NAME,							//ĳ���͸��� ���̰� �ʰ��Ǿ����ϴ�.
	GAME_PETITION_TOO_SHORT_NAME,							//ĳ���͸��� ���̰� �ʹ� ª���ϴ�.
	GAME_PETITION_TOO_LONG_QUESTION_CONTENT,				//���� ������ ���̰� �ʰ��Ǿ����ϴ�.
	GAME_PETITION_TOO_SHORT_QUESTION_CONTENT,				//���� ������ ���̰� �ʹ� ª���ϴ�.
	GAME_PETITION_CATEGORY_1_FAIL,							//ī�װ� 1�� ���� �̻��մϴ�.
	GAME_PETITION_CATEGORY_2_FAIL,							//ī�װ� 2�� ���� �̻��մϴ�.
	GAME_PETITION_CREATE_PETITION_FAILE ,					//���� ������ �����߽��ϴ�
	GAME_PETITION_DELETE_FAILE_STARTED ,					//�̹� ����߿� ������ �����̱⿡ ������ �� �����ϴ�
	GAME_PETITION_ISNOT_STARTED ,							//���� ���°� ������ �ƴմϴ�
	GAME_PETITION_ALREADYSTARTED ,							//�̹� �������Դϴ�
	GAME_PETITION_INSERT_ERROR_ZERO_ID ,					//����Ÿ ���� ���� - ID�� 0�Դϴ�
	GAME_PETITION_INSERT_FAILE ,							//����Ÿ ���� ���� (std::map���� ������ �뺸, �� �� ���� ����
	GAME_PETITION_INSERT_ALLREADY_ID ,						//����Ÿ ���� ���� (�̹� ��ϵǾ� �ִ� ID �Դϴ�
	GAME_PETITION_CREATE_PETITION_ID_FAILE ,				//Petition ID ���� ����
	GAME_PETITION_NOTRUNSTATE,								//���� ���¿����� ���� �� �� �����ϴ�
	GAME_PETITION_ACCOUNTNOTPETITION,						//�ش� ������ ������ �����ϴ�
	GAME_PETITION_ALREADY_INSERT,							//�̹� ������ ������ Account�Դϴ�.
	GAME_PETITION_LOCK,										// Petition�� Lock�Ǿ� �ֽ��ϴ�
	GAME_PETITION_PETITIONID_INVALID,						// Petition ID�� invalid �Դϴ�.
	GAME_PETITION_ALREADYFINISH,							//�̹� �Ϸ�� �����Դϴ�.

	//-----------------------------------------------------------------
	GAME_BUDOKAI_INVALID_TEAM_NAME,					// ���� �̸��� �ùٸ��� �ʽ��ϴ�.
	GAME_BUDOKAI_TOO_LONG_TEAM_NAME,						// ���� �̸��� �ʹ� ��ϴ�.
	GAME_BUDOKAI_TOO_SHORT_TEAM_NAME,						// ���� �̸��� �ʹ� ª���ϴ�.
	GAME_BUDOKAI_NEED_MORE_MEMBER,							// ������ �ʹ� �����ϴ�.
	GAME_BUDOKAI_NOT_REGISTER_PERIOD,						// ��� �Ⱓ�� �ƴմϴ�.
	GAME_BUDOKAI_OVER_COUNT,								// �����ο��� �ʰ��Ǿ����ϴ�.
	GAME_BUDOKAI_CHARACTER_ALREADY_JOIN,					// �̹� ��û�� �����Դϴ�.
	GAME_BUDOKAI_CHARACTER_NOT_JOINED,						// ��û���� ���� �����Դϴ�.
	GAME_BUDOKAI_MEMBER_ALREADY_JOINED,						// �̹� ��û�� ����� �ֽ��ϴ�.
	GAME_BUDOKAI_YOU_ARE_NOT_A_TEAM_LEADER,					// �� ������ �ƴմϴ�.
	GAME_BUDOKAI_NOT_MATCH_PLAYING,							// �������� ��Ⱑ �����ϴ�.
	GAME_BUDOKAI_NOT_OPENED,								// ���±Ⱓ�� �ƴմϴ�.
	GAME_BUDOKAI_NOT_MATCH_WORLD,							// õ�����Ϲ���ȸ ������� �ƴմϴ�.

	GAME_CAN_NOT_TELEPORT,									// �̵��� �� �����ϴ�.
	GAME_CAN_NOT_TELEPORT_THIS_STATE,						// �̵��� �� ���� �����Դϴ�. ��� �� �ٽ� �õ��ϼ���.

	GAME_MUDOSA_NOT_OPEND,									// ���� �Ⱓ�� �ƴմϴ�.
	GAME_MUDOSA_POINT_CANT_BE_USED_RIGHT_NOW,				// �Ͻ������� ������ ����Ʈ�� ����� �� ���� ��Ȳ�Դϴ�. ��� �� �ٽ� �õ��ϼ���.
	GAME_MUDOSA_POINT_NOT_ENOUGH,							// ������ ������ ������� �ʽ��ϴ�.
	GAME_MUDOSA_POINT_MAX_OVER,								// ������ ������ �ִ븦 �ʰ��Ͽ����ϴ�.

	GAME_MINORMATCH_CANNOT_TELEPORT_THIS_STATE,				// ������ ������ ���׿����� ������ �� �����ϴ�.

	GAME_NETP_POINT_CANT_BE_USED_RIGHT_NOW,					// �Ͻ������� NetPY ����Ʈ�� ����� �� ���� ��Ȳ�Դϴ�. ��� �� �ٽ� �õ��ϼ���.
	GAME_NETP_POINT_MAX_OVER,								// NetPY Point�� �ִ븦 �ʰ��Ͽ����ϴ�.
	GAME_NETP_POINT_NOT_ENOUGH,								// NetPY Point�� ������� �ʽ��ϴ�.
	GAME_NETPY_IS_LOCK,										// NetPY�� ��� �����Դϴ�.
	GAME_NETPY_NOT_ENOUGH,									// NetPY�� �����մϴ�.	

	GAME_CASHITEM_CANT_MOVE,								// �ش� ĳ���������� ������ �� �����ϴ�.
	GAME_CASHITEM_NOT_LOADED,								// ĳ�������� �ε��� �Ϸ���� �ʾҽ��ϴ�.
	GAME_CASHITEM_NOT_FOUND,								// �ش� ĳ���������� ã�� �� �����ϴ�.
	
	//new
	GAME_BUDOKAI_QUERY_FAIL_EXIST_MATCH_INDEX,
	GAME_BUDOKAI_QUERY_FAIL_INSERT_FAIL,
	GAME_BUDOKAI_CAN_NOT_TELEPORT_JUNIOR,

	//-----------------------------------------------------------------
	// Game, Item ����. 800���뿡�� �̾���. ( 3000 ~ )
	//-----------------------------------------------------------------
	GAME_ITEM_UPGRADE_ITEM_IS_ZERO_GRADE,			// �� ȣ������ ������ ����� �� �����ϴ�.
	GAME_DRAGONBALL_NOT_SAME_EXIST,							// �ٸ� ������ �巡�ﺼ �Դϴ�.
	GAME_ITEM_DURATIONTIME_ZERO,							// ��� �Ⱓ�� �������ϴ�.
	GAME_ITEM_RECIPE_CANNOT_RESET_NORMAL_TYPE,				// �⺻ ���� ����� ������ �� �����ϴ�.
	GAME_ITEM_NOT_USE_THIS_PLACE,							// ���⼭ ����� �� ���� �������Դϴ�.
	GAME_ITEM_STACK_FAIL_ITEMTYPE_DURATION,					// ���Ⱓ�� �ִ� �������� Stack�� �� �����ϴ�.
	GAME_ITEM_RECIPE_NORMAL_RECIPE_ALREADY_STARTED,			// �⺻ ���� ����� �̹� ��� �����Դϴ�.
	GAME_ITEM_RECIPE_SPECIAL_RECIPE_ALREADY_STARTED,		// Ư�� ���� ����� �̹� ��� �����Դϴ�.
	GAME_ITEM_RECIPE_CANNOT_RESET_CAUSE_NOT_STARTED_YET,	// ���� ����� ���� ����� �ʱ�ȭ �� �� �����ϴ�.
	GAME_ITEM_RECIPE_CANNOT_SET_YOU_NEED_HIGHER_LEVEL,		// ������ �����ϱ� ������ ��������� ��� �� �����ϴ�.
	GAME_ITEM_RECIPE_CANNOT_SET_YOU_NEED_MORE_ZENNY,		// ���ϰ� �����ϱ� ������ ��������� ��� �� �����ϴ�.
	GAME_ITEM_CANT_USE_CAUSE_CAPSULE_ITEM_ALREADY_IN_USE,	// ĸ�� �������� �̹� ������Դϴ�.

	GAME_SCOUTER_CHIP_NOT_EXIST,							// ��ī���� Ĩ�� �������� �ʽ��ϴ�.
	//new
	GAME_SCOUTER_PC_INFO_JAMMING,
	GAME_SCS_CHECK_FAIL,
	GAME_ITEM_UPGRADE_NO_HOIPOI_STONE_CORE,
	GAME_ITEM_UPGRADE_ITEM_AND_HOIPOI_STONE_DONT_MATCH,
	GAME_ITEM_UPGRADE_CANT_USE_STONE_CORE_WITH_BLACK_STONE,
	GAME_QUICK_TELEPORT_ITEM_NOT_FOUND,
	GAME_QUICK_TELEPORT_ITEM_LOCK,
	GAME_QUICK_TELEPORT_INFO_NOT_FOUND,
	GAME_QUICK_TELEPORT_INFO_NOT_VALID,
	GAME_ITEM_CANT_USE_ADD_CHARACTER_PLUS,
	GAME_EMPTY_ITEM_SLOT_NOT_ENOUGH,
	GAME_SAMENAME_EXIST,
	GAME_CHARACTER_NAME_HAS_INVALID_CHARACTER,
	GAME_CHARACTER_FAIL_BY_PARTY,
	GAME_CHARACTER_FAIL_BY_GUILD,
	GAME_CHARACTER_FAIL_BY_BUDOKAI,
	GAME_CHARACTER_FAIL_BY_LIMITED,
	GAME_GUILD_NOT_PROPER_GUILD_NAME_DOJO,
	GAME_GUILD_NOT_PROPER_GUILD_NAME_CHALLENGE_DOJO,
	GAME_ITEM_USEFUL_ONLY_WHEN_FAINTING,
	GAME_GAMERULE_REG_ALREADY_JOINED_DOJO_SCRAMBLE,
	GAME_GAMERULE_REG_CANT_PLAY_IN_DOJO_SCRAMBLE,
	GAME_CHARACTER_TOO_LONG_NAME,
	GAME_CHARACTER_TOO_SHORT_NAME,
	GAME_NPC_SERVER_IS_DOWN,
	GAME_ITEM_HOIPOI_CANNOT_MAKE_INVEN_FULL,
	GAME_ITEM_NEED_LESS_LEVEL,
	GAME_ITEM_TOO_HIGH_LEVEL_TO_USE_ITEM,
	GAME_ITEM_CANT_RENEWRAL,
	GAME_CANNOT_TRADE_NO_BAGSLOT,
	GAME_CANNOT_VISIT_INVALID_AREA,
	GAME_CANNOT_VISIT_SELF,
	GAME_ITEM_GENDER_DOESNT_MATCH,
	GAME_ITEM_UPGRADE_MUST_USE_STONE_WEAPON,
	GAME_ITEM_UPGRADE_MUST_USE_STONE_ARMOR,
	GAME_ITEM_UPGRADE_MUST_USE_PROPER_LEVEL_STONE,
	GAME_ITEM_UPGRADE_ALREADY_HIGHEST_GRADE,
	GAME_ITEM_UPGRADE_ALREADY_LOWEST_GRADE,
	GAME_ITEM_USE_ONLY_CHARACTER,
	GAME_ITEM_USE_ONLY_PLYAER,
	GAME_ITEM_CANT_USE_INVALID_PLAYER,
	GAME_ITEM_CANT_USE_INVALID_WORLD,
	GAME_ITEM_UPGRADE_COUPON_NOT_FOUND,
	GAME_ITEM_UPGRADE_COUPON_GRADE_FAIL,
	GAME_ITEM_UPGRADE_FAIL_FOR_DURATION_ITEM,
	GAME_ITEM_UPGRADE_FAIL_FOR_GRADE_DATA,
	GAME_ITEM_CANNOT_USE_INVALID_TARGET,
	GAME_ITEM_ALREADY_SEAL,
	GAME_ITEM_CANNOT_SEAL_BY_INVALID_RESTRICT,
	GAME_ITEM_NOT_SEALITEM,
	GAME_ITEM_CANNOT_SEAL_MORE_SEALITEM,
	GAME_ITEM_CANNOT_EXTRACT_SEAL_INVALID_ITEM,
	GAME_ITEM_UPGRADE_FAIL_AND_NODEL_BY_CORE,
	GAME_ITEM_UPGRADE_CANT_USE_STONE_CORE_WITH_SAFE,
	GAME_ITEM_UPGRADE_MUST_USE_PROPER_LEVEL_CORE_STONE,
	GAME_ITEM_NOT_BEAD,
	GAME_ITEM_NOT_SOCKET,
	GAME_ITEM_NOT_INSERT_BEAD_FOR_DURATION,
	GAME_ITEM_NOT_INSERT_BEAD_INVALID_LEVEL,
	GAME_ITEM_INVALID_DESTROY_BEAD,
	GAME_ITEM_INVALID_BEAD_OPTION,
	GAME_ITEM_INVALID_DURATION_BEAD,
	GAME_ITEM_CANNOT_INSERT_BEAD_BY_NO_MATCH_ITEM,
	GAME_ITEM_NOT_DESTROY_BEAD,
	GAME_ITEM_INSERT_BEAD_FAIL_AND_DEL,
	
	//-----------------------------------------------------------------
	CASHITEM_FAIL,
	CASHITEM_FAIL_NOT_DEFINED_SYSTEM,
	CASHITEM_FAIL_NOT_READY_SERVICE,
	CASHITEM_FAIL_NETWORK_ERROR,
	CASHITEM_FAIL_UNKNOWN_ERROR,
	CASHITEM_FAIL_CONFIRM_ERROR,
	CASHITEM_FAIL_NEED_MORE_CASH,
	CASHITEM_FAIL_NOT_EXIST_ITEM,
	CASHITEM_FAIL_NOT_ON_SALE_ITEM,
	CASHITEM_FAIL_CANT_BUY_CURRENT_SERVER,
	CASHITEM_FAIL_BANK_ALREADY_EXIST,
	CASHITEM_FAIL_CANT_FIND_CHARNAME,
	CASHITEM_FAIL_CANT_GIFT_MYSELF,
	CASHITEM_FAIL_CANT_RENEWAL,
	


	//-----------------------------------------------------------------
	REPORT_FAIL,											// ������ ����

	//-----------------------------------------------------------------
	// Petition System ( 10000 ~ )
	//-----------------------------------------------------------------
	PETITION_FAIL,											// Petition ����

	PETITION_NOT_STARTED_CLEINT_GM_CHAT,					// Ŭ���̾�Ʈ�� GM ä���� ���۵��� �ʾҽ��ϴ�
	PETITION_DIFFERENT_CHAATING_GM_ID,						// Ŭ���̾�Ʈ�� ä������ GM�� ID�� �ٸ� GM ID�̴�.
	PETITION_NOT_YET_ENTER_WORLD,							// ������ ���忡 ���� �ʾҴ�
	PETITION_AREADY_GM_CHATTING,							// ������ �̹� GM ä�����̴�




	//--NEW------------------------------------------------------------
	// Event System ( 11000 ~ )
	//-----------------------------------------------------------------
	EVENT_YOU_ALREADY_HAVE_CHARACTER,
	EVENT_NO_MORE_NEW_CHARACTER_ALLOWED,
	EVENT_OFF_CONTENTS_USED,

	//--NEW------------------------------------------------------------
	// Scramble System ( 12000 ~ )
	//-----------------------------------------------------------------
	SCRAMBLE_CANNOT_DO_WHILE_JOINED,
	SCRAMBLE_CANNOT_DO_WHILE_NOT_JOINED,
	SCRAMBLE_CANNOT_DO_ALREADY_REWARDED,
	SCRAMBLE_CANNOT_DO_TARGET_IS_NOT_JOINED,
	SCRAMBLE_CANNOT_TRADE_TARGET_IS_NOT_PARTY_MEMBER,
	SCRAMBLE_CANNOT_TRADE_TARGET_IS_ALREADY_REWARED,
	SCRAMBLE_CANNOT_INVITE_TARGET_IS_NOT_JOINED,
	SCRAMBLE_CANNOT_INVITE_TARGET_IS_JOINED,
	SCRAMBLE_CANNOT_RIDE_BUS_WHILE_JOINED,
	SCRAMBLE_CANNOT_PICK_WHILE_NOT_JOINED,
	SCRAMBLE_CANNOT_PICK_ALREADY_REWARDED,
	SCRAMBLE_CANNOT_JOIN_LEVEL_IS_TOO_LOW,
	SCRAMBLE_INVALID_BATTLE_DRAGONBALL,
	SCRAMBLE_CANNOT_JOIN_WHILE_TMQ,
	SCRAMBLE_CANNOT_JOIN_WHILE_RANKBATTLE,
	SCRAMBLE_CANNOT_JOIN_WHILE_DOJO,
	SCRAMBLE_CANNOT_JOIN_WHILE_TENKAICHIBUDOKAI,
	SCRAMBLE_CANNOT_JOIN_WHILE_FREEBATTLE,
	SCRAMBLE_CANNOT_REWARD_LIMIT_COUNT_OVER,
	SCRAMBLE_CANNOT_PICK_LIMIT_COUNT_OVER,
	SCRAMBLE_CANNOT_REWARD_WHILE_COOLTIME,
	SCRAMBLE_CANNOT_PICK_WHILE_COOLTIME,
	SCRAMBLE_CANNOT_NO_SEASON,
	SCRAMBLE_CANNOT_REWARD_WHILE_FAINT,
	SCRAMBLE_CANNOT_REWARD_WHILE_SANDBAG,
	SCRAMBLE_CANNOT_REWARD_SEASON_IS_END,


	//--NEW------------------------------------------------------------
	// TENKAICHI DAISIJYOU System ( 13000 ~ )
	//-----------------------------------------------------------------
	TENKAICHIDAISIJYOU_CANNOT_SELL_NO_MONEY,
	TENKAICHIDAISIJYOU_CANNOT_NOT_EXIST,
	TENKAICHIDAISIJYOU_CANNOT_LACK_OF_ITEM_STACK,
	TENKAICHIDAISIJYOU_CANNOT_BUY_NO_MONEY,
	TENKAICHIDAISIJYOU_CANNOT_LIST_IS_NOT,
	TENKAICHIDAISIJYOU_CANNOT_BUY_NOT_MATCH_ITEM,
	TENKAICHIDAISIJYOU_CANNOT_INVALID_ITEM,
	TENKAICHIDAISIJYOU_CANNOT_NOT_SELL_RESTRICT,
	TENKAICHIDAISIJYOU_CANNOT_NOT_SELL_INVALID_TAB_TYPE,
	TENKAICHIDAISIJYOU_CANNOT_NOT_SELL_NOT_TAB_TYPE,
	TENKAICHIDAISIJYOU_CANNOT_SYSTEM_DATA_ERROR,
	TENKAICHIDAISIJYOU_CANNOT_BUY_MYITEM,
	TENKAICHIDAISIJYOU_CANNOT_CANCEL_OTHER_ITEM,
	TENKAICHIDAISIJYOU_CANNOT_SELL_INVALID_TIME,
	TENKAICHIDAISIJYOU_CANNOT_SELL_INVALID_PRICE,
	TENKAICHIDAISIJYOU_CANNOT_FIND_INVALID_LEVEL,
	TENKAICHIDAISIJYOU_CANNOT_SELL_INVALID_DUR,
	TENKAICHIDAISIJYOU_CANNOT_NO_SELL_LIST,
	TENKAICHIDAISIJYOU_CANNOT_LIST_INVALID_ITEMNAME,
	TENKAICHIDAISIJYOU_CANNOT_LIST_COMPLETE,

	//--NEW------------------------------------------------------------
	// Maskot System ( 14000 ~ )
	//-----------------------------------------------------------------
	MASCOT_FAIL,
	MASCOT_ALREADY_EXIST,
	MASCOT_NOT_EXIST,
	MASCOT_WAS_NOT_SUMMONED,
	MASCOT_EXCEED_HAVE_COUNT,
	MASCOT_TBLDAT_FINDING_FAILED,
	MASCOT_ITEM_INVALID,
	MASCOT_RING_ITEM_NOT_EXIST,
	MASCOT_RING_ITEM_ABILITY_NOT_EXIST,
	MASCOT_NOT_ENOUGH_SP,
	MASCOT_BODY_ITEM_IS_INVALID,
	MASCOT_IS_SAME_CUR_MASCOT,
	MASCOT_SP_IS_FULL,
	MASCOT_SP_IS_HUNGRY,
	SUMMONING_MASCOT_CANT_DELETE,
	CANT_MOVE_ITEM_TO_MASCOT_BAG,
	MASCOT_FAIL_ACTIVATE_RING,
	MASCOT_FAIL_NOT_DISASSEMBLE_ITEM,
	MASCOT_FAIL_NOT_ACTIVATE_RING,
	SAME_RING_EXIST_IN_MASCOT_RING_CONTAINER,
	MASCOT_FAIL_INACTIVE_RING_CONTENT,
	MASCOT_FAIL_EXIST_ACTIVE_RING,

	//--NEW------------------------------------------------------------
	// wagu wagu machine System ( 15000 ~ )
	//-----------------------------------------------------------------
	WAGUWAGUMACHINE_FAIL,
	WAGUWAGUMACHINE_NOT_EXIST_MACHINE,
	WAGUWAGUMACHINE_NOT_EXIST_QNTT,
	WAGUWAGUMACHINE_NOT_ENOUGH_COIN,
	WAGUWAGUMACHINE_OVER_MAX_COIN,
	WAGUWAGUMACHINE_INVALID_CHARID,
	WAGUWAGUMACHINE_NOT_LIST_WINNERS,
	WAGUWAGUMACHINE_WINNER_REST,
	WAGUWAGUMACHINE_STOP_MACHINE,
	WAGUWAGUMACHINE_NO_HAVE_ITEMS,
	WAGUWAGUMACHINE_NOT_ENOUGH_ITEMS,
	WAGUWAGUMACHINE_SOME_FAILED_TO_EXTRACT,
	WAGUWAGUMACHINE_OVER_MAX_EVENTCOIN,

	//-----------------------------------------------------------------
	GAME_COMMON_MESSAGE_02,
	GAME_COMMON_ALREADY_REGISTERED,
	GAME_COMMON_NOT_REGISTERED,
	GAME_COMMON_CAN_NOT_DO_HERE,
	GAME_COMMON_CAN_FIND_MEMBER,
	GAME_COMMON_TOO_MANY_PLAYER,
	GAME_COMMON_TOO_FEW_PLAYER,
	GAME_COMMON_HAVE_NOT_THE_REQUIRED_ACHIEVEMENT,
	GAME_COMMON_CAN_NOT_FIND_TABLE_DATA,
	GAME_COMMON_ALREADY_EXIST,
	GAME_COMMON_EXIST_USER_WHO_DO_NOT_AGREE,
	GAME_COMMON_EXIST_USER_WHO_OVER_LIMIT_COUNT,
	GAME_COMMON_LACK_OF_SPACE_REWARD_HAS_BEEN_DELIVERED_BY_MAIL,

	//-----------------------------------------------------------------
	DWC_FAIL,

	//-----------------------------------------------------------------
	GAME_BATTLE_DUNGEON_FAIL,
	GAME_BATTLE_DUNGEON_NOT_READY_ALL,
	GAME_BATTLE_DUNGEON_NOT_IN_RANGE,
	GAME_BATTLE_DUNGEON_NOT_SAME_MEMBER,
	GAME_BATTLE_DUNGEON_NOT_EXIST_MESSAGE,
	GAME_BATTLE_DUNGEON_FAIL_STATE,

	//-----------------------------------------------------------------
	GAME_CLOSED_BOX_FAIL,
	GAME_CLOSED_BOX_KEY_NOT_FOUND,
	GAME_CLOSED_BOX_KEY_NOT_ENOUGH,
	GAME_CLOSED_BOX_KEY_MISMATCH,

	//-----------------------------------------------------------------
	GAME_ITEM_EXCHANGE_FAIL,
	GAME_ITEM_EXCHANGE_NOT_STACKED,
	GAME_ITEM_UPGRADED_EXCHANGE_POWDER_NOT_FOUND,
	GAME_ITEM_UPGRADED_EXCHANGE_POWDER_NEED_MORE,
	GAME_ITEM_UPGRADED_EXCHANGE_OLD_ITEM_GRADE_FAIL,
	GAME_ITEM_UPGRADED_EXCHANGE_NEW_ITEM_GRADE_FAIL,
	GAME_ITEM_UPGRADED_EXCHANGE_LEVEL_FAIL,
	GAME_ITEM_UPGRADED_EXCHANGE_ITEM_FAIL,

	//-----------------------------------------------------------------
	CHARTITLE_NO_HAVE,
	CHARTITLE_YOU_ALREADY_HAVE_THE_TITLE,
	CHARTITLE_TITLE_IS_ON_PROGRESS,

	//-----------------------------------------------------------------
	AIR_FAIL,
	AIR_CANNOT_FLY_JUMP_NOT_ENOUGH_AP,
	GAME_COMMON_CANT_DO_THAT_IN_AIR_MODE_STATE,
	AIR_CANNOT_FLY_ACCEL,

	GAME_SKILL_CANT_USE_SKILL_WHEN_ROLLING_ATTACK,
	GAME_SKILL_CANT_USE_SKILL_WHEN_RABIES,

	GAME_RESULT_LAST, // must be last result


	RESULT_DUMMY = 0xFFFF
	//////////////////////////////////////////////////////////////////////////
};
