#ifndef _DBO_TSEMSVREVT_H_
#define _DBO_TSEMSVREVT_H_


/** 
	Event mapper server event
	Ư�� server event�� ������ �� �ִ� Trigger id�� �ܺο� ������ å���� ������
*/


class CDboTSEMSvrEvt : public CNtlTSEvtMapper
{
	NTL_TS_DECLARE_RTTI

// Constructions and Destructions
public:
	CDboTSEMSvrEvt( void );
	virtual ~CDboTSEMSvrEvt( void );

// Methods
public:
	virtual bool							AddBuildData( const std::string& strKey, const CNtlTSMain::mapdef_TLIST& TList, void* pTblList, void* pParameter );
	virtual bool							DelBuildData( const std::string& strKey );
};

#endif