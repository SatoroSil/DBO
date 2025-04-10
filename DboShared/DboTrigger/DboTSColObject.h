#ifndef _DBO_TSCOLOBJCT_H_
#define _DBO_TSCOLOBJCT_H_


#include "DboTSCoreDefine.h"


/**
	Collsion object event
	�뵵 : Client quest, client trigger, server quest, server trigger pc
	���� : Ŭ���̾�Ʈ������ Object�� �浹�Ǿ��� �� �߻��ϴ� �̺��ͷν� ����
		   ���������� �ش� Object�� �浹�Ǿ�����( �ش� ������ ���Դ��� ) �˻��ϴ� �뵵�� ����
*/


class CDboTSColObject : public CNtlTSEvent
{
	NTL_TS_DECLARE_RTTI

// Declarations
public:
	typedef std::map<unsigned int, unsigned int> mapdef_OBJECT_LIST;

// Member variables
protected:
	unsigned int						m_uiWorldIdx;
	mapdef_OBJECT_LIST					m_defObjIdxList;
	mapdef_OBJECT_LIST::iterator		m_defObjIdxListIT;

// Constructions
public:
	CDboTSColObject( void );

// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_EVENT_TYPE_ID_COL_OBJECT; }

	unsigned int						GetWorldIdx( void ) const;
	void								SetWorldIdx( unsigned int uiWorldIdx );

	bool								HasObjectIdx( unsigned int uiObjIdx );

	int									GetNumOfObjectIdx( void ) const;
	unsigned int						BeginObjectIdx( void );
	unsigned int						NextObjectIdx( void );

// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );

	void								PackingObjectIdxList( std::string& strObjList, const mapdef_OBJECT_LIST& defObjList );
	void								UnPackingObjectIdxList( const std::string& strObjList, mapdef_OBJECT_LIST& defObjList );
};


inline unsigned int CDboTSColObject::GetWorldIdx( void ) const
{
	return m_uiWorldIdx;
}

inline int CDboTSColObject::GetNumOfObjectIdx( void ) const
{
	return (int)m_defObjIdxList.size();
}


#endif