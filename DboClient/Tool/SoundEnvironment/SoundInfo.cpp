#include "precomp_soundenvironment.h"
#include "SoundInfo.h"

CSoundInfo::CSoundInfo()
{
}

CSoundInfo::~CSoundInfo()
{
}

bool CSoundInfo::Create()
{
	NTL_FUNCTION("CSoundInfo::Create");

	NTL_RETURN(true);
}

void CSoundInfo::Destory()
{
}

void CSoundInfo::ReportSoundEnvironment()
{
	FILE*					fp;
	FMOD::System*			pFMODSystem;
	FMOD_RESULT				result;

	if( fopen_s(&fp, "SoundInfo.txt", "wt") != 0 )
	{
		printf_s("Can not open 'SoundInfo.txt'");
		return;
	}

	// FMOD �ý��� ����
	result = FMOD::System_Create(&pFMODSystem);
	if( IsExistError(fp, result) )
	{
		fclose(fp);
		return;
	}
	

	DisplaySoundEnvironment(fp, pFMODSystem);


	pFMODSystem->close();
	pFMODSystem->release();
	fclose(fp);
}

void CSoundInfo::DisplaySoundEnvironment(FILE* fp, FMOD::System* pFMODSystem)
{
	unsigned int			uiVersion;				// FMOD ���̺귯�� ����
	FMOD_SPEAKERMODE		SpeakerMode;			// ���� ��ǻ���� ����Ŀ ���
	char					acDriverName[256];		// ���� ī�� �̸�
	int						iHardware2DChannels;	// ���� ī���� 2D ä��
	int						iHardware3DChannels;	// ���� ī���� 3D ä��
	int						iHardwareTotalChannels;	// ���� ī���� �� ä�μ�
	
	FMOD_RESULT				result;
	FMOD_CAPS				caps;
	FMOD_SPEAKERMODE		userSetSpeakMode;	


	// ���� üũ
	result = pFMODSystem->getVersion(&uiVersion);
	if( IsExistError(fp, result) )
		return;

	// ���� ����̹� ����
	result = pFMODSystem->getDriverCaps(0, &caps, 0, 0, &SpeakerMode);
	if( IsExistError(fp, result) )
		return;

	// ��ǻ���� ����Ŀ ���
	result = pFMODSystem->setSpeakerMode(SpeakerMode);  /* Set the user selected speaker mode. */
	if( IsExistError(fp, result) )
		return;

	userSetSpeakMode = SpeakerMode;

	// ������ ������ ���� ��带 ����ī�尡 ������ �� ������ ���׷��� ���� �÷��� �Ѵ�
	result = pFMODSystem->init(100, FMOD_INIT_NORMAL, 0);    /* Replace with whatever channel count and flags you use! */
	if (result == FMOD_ERR_OUTPUT_CREATEBUFFER)         /* Ok, the speaker mode selected isn't supported by this soundcard.  Switch it back to stereo... */
	{
		result = pFMODSystem->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
		if( IsExistError(fp, result) )
			return;

		result = pFMODSystem->init(100, FMOD_INIT_NORMAL, 0); /* Replace with whatever channel count and flags you use! */
		if( IsExistError(fp, result) )
			return;
	}

	// ���� ī�尡 �������� �� ���� ������(���� �ֽ�)���� ī���� �̸�
	// ���� ī�尡 �ϳ��� ���� �ֵ���̹��� �ִٰ� ������ ���ͼ� ����
	// ī�� ���θ� �˻������� �ʴ´�
	int iCount;
	result = pFMODSystem->getNumDrivers(&iCount);
	if( IsExistError(fp, result) )
		return;

	result = pFMODSystem->getDriverName(iCount - 1, acDriverName, 256);
	if( IsExistError(fp, result) )
		return;

	// ���� ī���� ä�� ����
	pFMODSystem->getHardwareChannels(&iHardware2DChannels, &iHardware3DChannels, &iHardwareTotalChannels);
	if( IsExistError(fp, result) )
		return;


	fprintf_s(fp, "FMOD Version : %x\n\n", uiVersion);
	printf_s("FMOD Version : %x\n\n", uiVersion);

	char pcText[256] = "";

	if( SpeakerMode != userSetSpeakMode )
	{
		fprintf_s(fp, "������ ������ ����Ŀ ��带 ���� ī�忡�� �������� �ʽ��ϴ�\n");
		printf("������ ������ ����Ŀ ��带 ���� ī�忡�� �������� �ʽ��ϴ�\n");

		GetSpeakerModeName(pcText, 256, userSetSpeakMode);
		fprintf_s(fp, "�������� ����Ŀ ��� ��� : %s\n\n", pcText);
		printf("�������� ����Ŀ ��� : %s\n\n", pcText);
	}

	GetSpeakerModeName(pcText, 256, SpeakerMode);
	fprintf_s(fp, "����Ŀ ��� : %s\n\n", pcText);
	printf("����Ŀ ��� : %s\n\n", pcText);



	fprintf_s(fp, "����̹� : %s\n", acDriverName);
	printf("����̹� : %s\n", acDriverName);

	fprintf_s(fp, "���� ī�� 2D ä�� : %d\n", iHardware2DChannels);
	printf("���� ī�� 2D ä�� : %d\n", iHardware2DChannels);

	fprintf_s(fp, "���� ī�� 3D ä�� : %d\n", iHardware3DChannels);
	printf("���� ī�� 3D ä�� : %d\n", iHardware3DChannels);

	fprintf_s(fp, "���� ī�� �� ä�� : %d\n", iHardwareTotalChannels);
	printf("���� ī�� �� ä�� : %d\n", iHardwareTotalChannels);
}

bool CSoundInfo::GetSpeakerModeName(char* pcResultText, int ibufferSize, FMOD_SPEAKERMODE mode)
{
	if( !pcResultText )
		return false;

	switch(mode)
	{
	case FMOD_SPEAKERMODE_RAW:
		{
			sprintf_s(pcResultText, ibufferSize, "%s", "There is no specific speakermode");
			break;
		}
	case FMOD_SPEAKERMODE_MONO:
		{
			sprintf_s(pcResultText, ibufferSize, "%s", "The speakers are monaural");
			break;
		}
	case FMOD_SPEAKERMODE_STEREO:
		{
			sprintf_s(pcResultText, ibufferSize, "%s", "The speakers are stereo (DEFAULT)");
			break;
		}
	case FMOD_SPEAKERMODE_QUAD:		
		{
			sprintf_s(pcResultText, ibufferSize, "%s", "4 speaker setup.\n\t  This includes front left, front right, rear left, rear right.");
			break;
		}
	case FMOD_SPEAKERMODE_SURROUND:
		{
			sprintf_s(pcResultText, ibufferSize, "%s", "4 speaker setup.\n\t  This includes front left, front right, center, rear center (rear left/rear right are averaged).");
			break;
		}
	case FMOD_SPEAKERMODE_5POINT1:
		{
			sprintf_s(pcResultText, ibufferSize, "%s", "5.1 speaker setup.\n\t  This includes front left, front right, center, \n\trear left, rear right and a subwoofer.");
			break;
		}
	case FMOD_SPEAKERMODE_7POINT1:
		{
			sprintf_s(pcResultText, ibufferSize, "%s", "7.1 speaker setup.\n\t  This includes front left, front right, center,\n\t rear left, rear right, side left, side right and a subwoofer.");
			break;
		}
	case FMOD_SPEAKERMODE_PROLOGIC:
		{
			sprintf_s(pcResultText, ibufferSize, "%s", "Stereo output, but data is encoded in a way\n\t that is picked up by a Prologic/Prologic2 decoder and split into a 5.1 speaker setup.");
			break;
		}
	default:
		return false;
	}

	return true;
}

bool CSoundInfo::IsExistError(FILE* fp, FMOD_RESULT result)
{
	static char acBuffer[256] = "";

	if( result != FMOD_OK )
	{
		sprintf_s(acBuffer, 256, "FMOD error! (%d) %s", result, FMOD_ErrorString(result));

		printf(acBuffer);
		fprintf_s(fp, "%s", acBuffer);

		return true;
	}

	return false;
}