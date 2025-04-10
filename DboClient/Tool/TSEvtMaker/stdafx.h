// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

// �Ʒ� ������ �÷����� �켱�ϴ� �÷����� ������� �ϴ� ��� ���� ���Ǹ� �����Ͻʽÿ�.
// �ٸ� �÷����� ���Ǵ� �ش� ���� �ֽ� ������ MSDN�� �����Ͻʽÿ�.
#ifndef WINVER				// Windows XP �̻󿡼��� ����� ����� �� �ֽ��ϴ�.
#define WINVER 0x0501		// �ٸ� ������ Windows�� �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#ifndef _WIN32_WINNT		// Windows XP �̻󿡼��� ����� ����� �� �ֽ��ϴ�.                   
#define _WIN32_WINNT 0x0501	// �ٸ� ������ Windows�� �µ��� ������ ������ ������ �ֽʽÿ�.
#endif						

#ifndef _WIN32_WINDOWS		// Windows 98 �̻󿡼��� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_WINDOWS 0x0410 // Windows Me �̻� �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#ifndef _WIN32_IE			// IE 6.0 �̻󿡼��� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_IE 0x0600	// �ٸ� ������ IE�� �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#define WIN32_LEAN_AND_MEAN		// ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C�� ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// renderware
#include <rwcore.h>
#include <rwplcore.h>
#include <rpworld.h>
#include <rpusrdat.h>
#include <rphanim.h>
#include <rpskin.h>
#include <rpmatfx.h>
#include <rphanim.h>
#include <rpprtstd.h>
#include <rpprtadv.h>
#include <rpuvanim.h>
#include <rpusrdat.h>
#include <rptoon.h>
#include <rpcollis.h>
#include <rpid.h>
#include <rtanim.h>
#include <rtfsyst.h>
#include <rtanim.h>
#include <rtquat.h> 
#include <rtpick.h>
#include <rtray.h>
#include <rtdict.h>
#include <rtslerp.h>
#include <rtimport.h>
#include <rtintsec.h>
#include <rtpng.h>
#include <rtbmp.h>
#include <rtcharse.h>

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
