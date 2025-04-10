#ifndef _DBO_TSACTCONTGCOND_H_
#define _DBO_TSACTCONTGCOND_H_


#include "DboTSCoreDefine.h"


/**
	General condition container
	�̺�Ʈ �� ���ǵ��� ��� �����̳�
*/


class CDboTSContGCond : public CNtlTSCont
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	NTL_TS_TC_ID						m_tcYesId;
	NTL_TS_TC_ID						m_tcNoId;

	bool								m_bRewardMark;

// Constructions
public:
	CDboTSContGCond( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_CONT_TYPE_ID_CONT_GCOND; }

	NTL_TS_TC_ID						GetYesLinkID( void ) const;
	bool								AttachYesLinkID( NTL_TS_TC_ID tcId );
	void								DetachYesLinkID( void );

	NTL_TS_TC_ID						GetNoLinkID( void ) const;
	bool								AttachNoLinkID( NTL_TS_TC_ID tcId );
	void								DetachNoLinkID( void );

	bool								IsRewardMark( void ) const;
	void								SetRewardMark( bool bClear );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline NTL_TS_TC_ID CDboTSContGCond::GetYesLinkID( void ) const
{
	return m_tcYesId;
}

inline NTL_TS_TC_ID CDboTSContGCond::GetNoLinkID( void ) const
{
	return m_tcNoId;
}

inline bool CDboTSContGCond::IsRewardMark( void ) const
{
	return m_bRewardMark;
}


#endif