#ifndef _NTL_TSLOG_H_
#define _NTL_TSLOG_H_


/**
	Log
	TS���� �߻��ϴ� �ΰ� �����ʿ��� ����ϱ� ���ؼ���
	�Ʒ� Ŭ������ ����ؾ߼� ���� ��, ���� �Լ� Register�� ���� ����ؾ� ��
	��� �޾� ������ �ΰ� ��ü�� ��� �Ϸ� �� �ݵ�� Unregister�� ���� ���� �ؾ� ��
*/


class CNtlTSLog
{
// Declarations
public:
	enum
	{
		LOG_MAX_BUFFER					= 2048
	};

// Static variables
protected:
	static CNtlTSLog*					s_pLog;
	static char							s_szStrBuf[LOG_MAX_BUFFER];

// Static methods
public:
	static void							Register( CNtlTSLog* pLog );
	static void							Unregister( void );
	static void							Log( const char* pFormat, ... );

// Constructions and Destructions
public:
	virtual ~CNtlTSLog( void ) { return; }

// Implementations
protected:
	virtual void						OnLogEvent( const char* pLog );
};


#endif