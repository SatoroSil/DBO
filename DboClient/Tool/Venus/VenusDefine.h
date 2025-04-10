//***********************************************************************************
//	File		:	NtlResourceParticleSystem.h
//	Desc		:	
//	Begin		:	2005. 7.28
//	Copyright	:	�� 2005 by NTL-inc CO., Ltd
//	Author		:	agebreak
//	Update		:	
//***********************************************************************************


#ifndef _VENUS_DEFINE_H_
#define _VENUS_DEFINE_H_

// Version ����
#define VERSION_VENUS   "VENUS 9.7.29 by agebreak"

#define FRAME_FIX_FPS 30.0f                           ///< Frame Fix ��ġ
#define PATH_TREE_XML   ".\\Tool\\VenusData\\"        ///< Ʈ�� XML ���ϵ��� �����Ǵ� ���� ���

static CString GetFileNameFromPath(CString strFilePath)
{
    int nIndex = strFilePath.ReverseFind(L'\\');
    if(nIndex)
    {
        int nLength = strFilePath.GetLength() - nIndex - 1;
        strFilePath = strFilePath.Right(nLength);
    }

    return strFilePath;
}

#endif