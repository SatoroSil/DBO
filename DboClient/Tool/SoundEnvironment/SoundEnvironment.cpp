#include "precomp_soundenvironment.h"

#include "conio.h"
#include "SoundInfo.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CSoundInfo soundInfo;

	if( !soundInfo.Create() )
		return 0;

	soundInfo.ReportSoundEnvironment();

	soundInfo.Destory();

	printf("\n�ƹ�Ű�� ������ ���α׷��� �����Ͽ� �ֽʽÿ�\n");
	getch();

	return 0;
}
