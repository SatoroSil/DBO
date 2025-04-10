#pragma once

#include "Table.h"

const DWORD		DBO_MAX_FORMULA_RATE_COUNT = 4;
const DWORD		DBO_MAX_FORMULA_IDX = 11000;

#pragma pack(push, 4)
struct sFORMULA_TBLDAT : public sTBLDAT
{
public:
	bool			bValidity_Able;
	float			afRate[DBO_MAX_FORMULA_RATE_COUNT];

protected:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

class CFormulaTable : public CTable
{
public:

	CFormulaTable(void);
	virtual ~CFormulaTable(void);

	bool Create(DWORD dwCodePage);
	void Destroy();

protected:
	void Init();

public:
	sTBLDAT *			FindData(TBLIDX tblidx); 

protected:
	WCHAR** GetSheetListInWChar() { return &(CFormulaTable::m_pwszSheetList[0]); }
	void* AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage);
	bool DeallocNewTable(void* pvTable, WCHAR* pwszSheetName);
	bool AddTable(void * pvTable, bool bReload, bool bUpdate);
	bool SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData);


public:

	virtual bool				LoadFromBinary(CNtlSerializer& serializer, bool bReload, bool bUpdate);

	virtual bool				SaveToBinary(CNtlSerializer& serializer);


public:

	// WARNING :
	// The value of 'm' in the variable 'afRate[m][n]' means tblidx.
	// For example, if you want to get data whose tblidx is 6, you must use 'm_afRate[6]' instead of 'm_afRate[5]'.
	// The value of 'n' in the variable 'afRate[m][n]' means an index.
	// For example, if you want to get value of 'fRate2', you must use 'm_afRate[m][2]' instead of 'm_afRate[m][1]'.
	// m_afRate[m][n]������ m�� tblidx�� ���մϴ�.
	// ���� ���, tblidx�� 6�� ���� ����Ÿ�� ���� ������ m_afRate[5]�� �ƴ� m_afRate[6]�� ����ؾ� �մϴ�.
	// m_afRate[m][n]������ n�� �ε����� ���մϴ�.
	// ���� ���, fRate2�� ���� ���� ������ m_afRate[m][1]�� �ƴ� m_afRate[m][2]�� ����ؾ� �մϴ�.
	// by YOSHIKI(2009-07-13)
	static float				m_afRate[DBO_MAX_FORMULA_IDX + 1][DBO_MAX_FORMULA_RATE_COUNT + 1];

	enum eITEM_DURABILITY_FORMULA_TYPE
	{
		ITEM_DURABILITY_FORMULA_TYPE_HAND = 0x1A90,
		ITEM_DURABILITY_FORMULA_TYPE_SUB_WEAPON = 0x1AF4,
		ITEM_DURABILITY_FORMULA_TYPE_JACKET = 0x1B58,
		ITEM_DURABILITY_FORMULA_TYPE_PANTS = 0x1BBC,
		ITEM_DURABILITY_FORMULA_TYPE_BOOTS = 0x1C20,
		ITEM_DURABILITY_FORMULA_TYPE_SCOUTER = 0x1C84,
	};

	enum eDEFINE
	{


		AGGRO_NORMAL_DAMAGE = 0x1F41,
		AGGRO_DIRECT_DAMAGE = 0x1F42,
		AGGRO_DIRECT_LP_HEAL = 0x1F43,
		AGGRO_DIRECT_EP_HEAL = 0x1F44,
		AGGRO_DAMAGE_OVER_TIME = 0x1F45,
		AGGRO_LP_HEAL_OVER_TIME = 0x1F46,
		AGGRO_EP_HEAL_OVER_TIME = 0x1F47,
		AGGRO_SCAN_POINT_RATE = 0x1F48,
		TARGET_CHANGE_FOR_MIN_TIME = 0x1F55,
		ATTACK_TIME_FOR_CHEATING_PLAYER = 0x1F56,
	};


private:
	static WCHAR* m_pwszSheetList[];
};