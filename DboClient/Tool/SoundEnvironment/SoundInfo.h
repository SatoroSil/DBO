/******************************************************************************
* File			: CSoundInfo.h
* Author		: Hong SungBock
* Copyright		: (��)NTL
* Date			: 2007. 12. 18
* Abstract		: 
* Update		: 
*****************************************************************************
* Desc			: �÷����� ���� ȯ�� ������ ǥ���Ѵ�
*****************************************************************************/

#pragma once

class CSoundInfo
{
public:
	CSoundInfo();
	virtual ~CSoundInfo();

	bool			Create();
	void			Destory();

	void			ReportSoundEnvironment();	

protected:
	void			DisplaySoundEnvironment(FILE* fp, FMOD::System* pFMODSystem);

	bool			GetSpeakerModeName(char* pcResultText, int ibufferSize, FMOD_SPEAKERMODE mode);
	bool			IsExistError(FILE* fp, FMOD_RESULT result);
};