#ifndef _DBO_TSTAGENCY_H_
#define _DBO_TSTAGENCY_H_


#include "DboTSCoreDefine.h"


class CDboTSCompleteQInfo;
class CDboTSTRecv;
class CDboTSTCtrl;
class CDboTSMain;


/** 
	Trigger agency
*/


class CDboTSTAgency : public CNtlTSAgency
{
	NTL_TS_DECLARE_RTTI

// Declarations
public:
	typedef std::map<NTL_TS_T_ID, CDboTSTCtrl*> mapdef_TRIGGER_LIST;

// Member variables
protected:
	CDboTSMain*							m_pParent;
	CDboTSTRecv*						m_pRecv;

	mapdef_TRIGGER_LIST					m_defCurTList;		// ���� ���� ���� Ʈ���� ����

// Constructions and Destructions
public:
	CDboTSTAgency( void );
	virtual ~CDboTSTAgency( void );

// Methods
public:
	// Ʈ���� �������� ����
	virtual void						Update( void );

	// �� Ʈ���� �ý���
	CDboTSMain*							GetParent( void );
	void								SetParent( CDboTSMain* pParent );

	// Ʈ���� ���ù�
	CDboTSTRecv*						GetRecv( void );
	void								SetRecv( CDboTSTRecv* pRecv );

	// ���� ���� ���� Ʈ���� ����Ʈ
	mapdef_TRIGGER_LIST*				GetCurTList( void ) { return &m_defCurTList; }

	// ������ Ʈ����
	CDboTSTCtrl*						FindProgressTrigger( NTL_TS_T_ID tId );
	void								AttachProgressTrigger( NTL_TS_T_ID tId, CDboTSTCtrl* pCtrl );
	void								DetachProgressTrigger( NTL_TS_T_ID tId );

// Implementations
protected:
	virtual CDboTSTCtrl*				MakeTriggerController( CNtlTSTrigger* pTrig );
};


inline CDboTSMain* CDboTSTAgency::GetParent( void )
{
	return m_pParent;
}

inline CDboTSTRecv* CDboTSTAgency::GetRecv( void )
{
	return m_pRecv;
}


#endif