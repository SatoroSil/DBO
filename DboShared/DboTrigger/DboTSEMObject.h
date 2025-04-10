#ifndef _DBO_TSEMOBJECT_H_
#define _DBO_TSEMOBJECT_H_


/** 
	Event mapper object
	Ư�� Object�� ������ �� �ִ� Trigger id�� �ܺο� ������ å���� ������
*/


class CDboTSEMObject : public CNtlTSEvtMapper
{
	NTL_TS_DECLARE_RTTI

// Constructions and Destructions
public:
	CDboTSEMObject( void );
	virtual ~CDboTSEMObject( void );

// Methods
public:
	virtual bool							AddBuildData( const std::string& strKey, const CNtlTSMain::mapdef_TLIST& TList, void* pTblList, void* pParameter );
	virtual bool							DelBuildData( const std::string& strKey );
};

#endif