#ifndef _DBO_TSACTITEM_H_
#define _DBO_TSACTITEM_H_


#include "DboTSCoreDefine.h"


/**
	Item action
	�뵵 : Server quest, server trigger pc
	���� : �Ϲ� �������� ���� �� ���� �Ѵ�
*/


struct stTS_ITEM_INFO
{
	eTSITEM_SLOT_TYPE					eItemSlotType;	// �������� �� ��ġ
	unsigned int						uiItemIdx;		// ���� �� ������ �������� �ε���
};


class CDboTSActItem : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

// Declarations
public:
	enum { eMAX_TS_ITEM_COUNT = 3 };

// Member variables
protected:
	eTSITEM_TYPE						m_eItemType;
	stTS_ITEM_INFO						m_stItemInfo[eMAX_TS_ITEM_COUNT];

// Constructions
public:
	CDboTSActItem( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_ITEM; }

	eTSITEM_TYPE						GetItemType( void ) const;
	void								SetItemType( eTSITEM_TYPE eItemType );

	const stTS_ITEM_INFO&				GetItemInfo( int nIdx ) const;
	void								SetItemInfo( int nIdx, const stTS_ITEM_INFO& stItemInfo );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline eTSITEM_TYPE CDboTSActItem::GetItemType( void ) const
{
	return m_eItemType;
}

inline const stTS_ITEM_INFO& CDboTSActItem::GetItemInfo( int nIdx ) const
{
	return m_stItemInfo[nIdx];
}


#endif