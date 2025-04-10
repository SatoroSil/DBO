#ifndef _DBO_TSCLICKNPC_H_
#define _DBO_TSCLICKNPC_H_


#include "DboTSCoreDefine.h"


/**
	Click NPC event
	�뵵 : Client quest, client trigger, server quest, server trigger pc
	���� : Ŭ���̾�Ʈ������ NPC�� ���õǾ��� �� �߻��ϴ� �̺��ͷν� ����
		   ���������� �ش� NPC�� ���õǾ����� �˻��ϴ� �뵵�� ����
*/


class CDboTSClickNPC : public CNtlTSEvent
{
	NTL_TS_DECLARE_RTTI

public:

	typedef std::list<unsigned int> listdef_NPCIdx;



// Member variables
protected:

	listdef_NPCIdx					m_defNPCIdx;
	listdef_NPCIdx::iterator		m_itNPCIdx;

// Constructions
public:
	CDboTSClickNPC( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_EVENT_TYPE_ID_CLICK_NPC; }

	
	int								GetNumOfNPCIdx( void ) const;
	unsigned int					GetNPCIdx( void );//BeginNextNPCIdx( void );
	unsigned int					NextNPCIdx( void );
	bool							AttachNPCIdx( unsigned int NPCId );
	void							DetachNPCIdx( unsigned int NPCId );
	bool							ParsingNPCIdx( const std::string& strContents );


// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};

inline int CDboTSClickNPC::GetNumOfNPCIdx(void) const
{
	return (int)m_defNPCIdx.size();
}




#endif