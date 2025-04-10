#ifndef _DBO_TSACTOPOBJECT_H_
#define _DBO_TSACTOPOBJECT_H_


#include "DboTSCoreDefine.h"


class CDboTSActOPObject : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Member variables
protected:
	bool								m_bApply;				// True ����, False ����
	unsigned int						m_uiOperateTime;		// �и� ������
	unsigned int						m_uiDirectionTblIdx;	// �𷺼� ���̺� �ε���

// Constructions
public:
	CDboTSActOPObject( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_OPERATEOBJECT; }

	bool								IsApply( void ) const;
	void								SetApply( bool bApply );

	unsigned int						GetOperateTime( void ) const;
	void								SetOperateTime( unsigned int uiOperateTime );

	unsigned int						GetDirectionTableIndex( void ) const;
	void								SetDirectionTableIndex( unsigned int uiDirTblIdx );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline bool CDboTSActOPObject::IsApply( void ) const
{
	return m_bApply;
}

inline unsigned int CDboTSActOPObject::GetOperateTime( void ) const
{
	return m_uiOperateTime;
}

inline unsigned int CDboTSActOPObject::GetDirectionTableIndex( void ) const
{
	return m_uiDirectionTblIdx;
}


#endif