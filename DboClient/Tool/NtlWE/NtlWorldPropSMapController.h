#pragma once


#include "ntlworldpropbasetemplate.h"


class CNtlWorldPropSMapController :	public CNtlWorldPropBaseTemplate
{
public:
	CNtlWorldPropSMapController(void);
	virtual ~CNtlWorldPropSMapController(void);

protected:
	VOID LoadPropImage(RwChar* pTexName, RwInt32 IdxProp);
	VOID AppendPropDat(RwV3d& PosTile, DWORD _PropDat);
	VOID DeletePropDat(RwV3d& PosTile, DWORD _PropDat);
	VOID SavePropImage(RwInt32 Width, RwInt32 Height, RwInt32 Depth, RwInt32 IdxProp, RwChar* pIdxName);
};

// ���� 4����Ʈ�� ǥ���Ҽ� �ִ� ��� ��ġ������ ��ũ��Ʈ �ε����� ǥ�����ڰ� ����ߴ�. �̶� ���̺��� ���� �ۼ�