#ifndef _DBO_TSEMNPC_H_
#define _DBO_TSEMNPC_H_


/** 
	Event mapper npc
	Ư�� NPC�� ������ �� �ִ� Trigger id�� �ܺο� ������ å���� ������
*/


class CDboTSEMNPC : public CNtlTSEvtMapper
{
	NTL_TS_DECLARE_RTTI

// Constructions and Destructions
public:
	CDboTSEMNPC( void );
	virtual ~CDboTSEMNPC( void );

// Methods
public:
	virtual bool							AddBuildData( const std::string& strKey, const CNtlTSMain::mapdef_TLIST& TList, void* pTblList, void* pParameter );
	virtual bool							DelBuildData( const std::string& strKey );
};

#endif