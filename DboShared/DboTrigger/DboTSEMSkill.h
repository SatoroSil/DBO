#ifndef _DBO_TSEMSKILL_H_
#define _DBO_TSEMSKILL_H_


/** 
	Event mapper skill
	Ư�� Skill�� ������ �� �ִ� Trigger id�� �ܺο� ������ å���� ������
*/


class CDboTSEMSkill : public CNtlTSEvtMapper
{
	NTL_TS_DECLARE_RTTI

// Constructions and Destructions
public:
	CDboTSEMSkill( void );
	virtual ~CDboTSEMSkill( void );

// Methods
public:
	virtual bool							AddBuildData( const std::string& strKey, const CNtlTSMain::mapdef_TLIST& TList, void* pTblList, void* pParameter );
	virtual bool							DelBuildData( const std::string& strKey );
};

#endif