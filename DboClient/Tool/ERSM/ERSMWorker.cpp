#include "StdAfx.h"
#include "ERSMWorker.h"
#include "ERSMConfig.h"
#include "ERSMDef.h"
#include "NtlUnzip.h"

CERSMWorker::CERSMWorker(void)
{
	m_vecErrorReportFiles.reserve(100);
}

CERSMWorker::~CERSMWorker(void)
{
	Clear();
}

void CERSMWorker::Clear() 
{
	for(UINT i = 0; i < m_vecErrorReportFiles.size(); ++i)
	{
		delete m_vecErrorReportFiles[i];
	}

	m_vecErrorReportFiles.clear();
}

bool CERSMWorker::ProcessErrReports() 
{
	Clear();

	if(!GetListZipFiles(NCGetSGT(ERSMConfig)->GetERSFolder()))
		return FALSE;

	cout<<"--- Get Error Report List(Zip Files) Success ---\n";

	// ó���� ������ ������ True�� ��ȯ�ϰ� ������.
	if(m_vecErrorReportFiles.empty())
	{
		cout<<"--- Error Report Files Empty --- "<<GetTime()<<"\n";
		return TRUE;
	}

	if(!RenameZipFiles())
		return FALSE;

	cout<<"--- Rename Error Report Files Success ---"<<GetTime()<<"\n";

	return TRUE;
}

bool CERSMWorker::GetListZipFiles( const std::string& strFolderName ) 
{
	BOOL bResult = TRUE;
	WIN32_FIND_DATA wfd;
	std::string strFilter;
	std::string strFolder;
	HANDLE hSerach;	
	char buf[ERSM_BUF_SIZE] = {0,}; 
	SYSTEMTIME timeFile;
	std::vector<std::string> vecFolderName;
	
	// 1. ���� ������ �˻��Ѵ� (��������Ʈ ������ ��Ʈ �������� 1�ܰ� ���������� �����Ѵ�)
	strFilter = strFolderName + "\\*.*";
	hSerach = FindFirstFile(strFilter.c_str(), &wfd);
	if(hSerach == INVALID_HANDLE_VALUE)
		return FALSE;

	while(bResult)
	{
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)	// ������ ���
		{
			if(strcmp(wfd.cFileName, ".") != 0 &&
			   strcmp(wfd.cFileName, "..") != 0)
			{
				vecFolderName.push_back(wfd.cFileName);
			}
			
		}

		bResult = FindNextFile(hSerach, &wfd);
	}
	FindClose(hSerach);

	// 2. ���� �����鿡�� ZipFile���� �˻��Ѵ�.	
	for(UINT i = 0; i < vecFolderName.size(); ++i)
	{		
		strFolder = NCGetSGT(ERSMConfig)->GetERSFolder() + "\\";
		strFolder += vecFolderName[i];
		strFolder += "\\";		
		strFilter = strFolder + "*.zip";
		
		bResult = TRUE;

		hSerach = FindFirstFile(strFilter.c_str(), &wfd);
		if(hSerach == INVALID_HANDLE_VALUE)
			continue;

		while(bResult)
		{
			// ���������� ����Ʈ�� ��´�.
			SErrorReportFile* pERF = new SErrorReportFile();
			m_vecErrorReportFiles.push_back(pERF);

			// ���� �̸�
			pERF->m_strFolderName = strFolder;
			
			// ���� �̸�			
			pERF->m_strFileName =  wfd.cFileName;
			
			// ���� ���� ��¥
			FileTimeToSystemTime(&wfd.ftLastWriteTime, &timeFile);
			sprintf_s(buf, "%d%02d%02d", timeFile.wYear, timeFile.wMonth, timeFile.wDay);
			pERF->m_strFileDate = buf;

			// ���Ͼȿ� ���Ե� ���� ���̵�
			std::string strFullPathName = strFolder + wfd.cFileName;
			pERF->m_strUserID = GetUserIDFromZipFile(strFullPathName);

			bResult = FindNextFile(hSerach	, &wfd);
			Sleep(0);
		}
		FindClose(hSerach);
	}

	return TRUE;
}

std::string CERSMWorker::GetUserIDFromZipFile( const std::string& strZipFileName ) 
{
	std::string strUserID;

	// 1. Zip File�κ��� UserID������ ������ �ִ� �α� ������ ������.
	sUZ_FILEINFO uzFileInfo;
	ZeroMemory(&uzFileInfo, sizeof(uzFileInfo));

	char buf[ERSM_FILE_BUF_SIZE] = {0,};
	char szUserID[ERSM_BUF_SIZE] = {0,};

	CNtlUnzip unZip(strZipFileName.c_str());	
	bool bResult = unZip.GotoFirstFile();
	while(bResult)
	{
		ZeroMemory(buf, ERSM_FILE_BUF_SIZE);

		if(!unZip.GetFileInfo(uzFileInfo))
		{
			bResult = unZip.GotoNextFile();
			continue;
		}

		if(strcmp(uzFileInfo.szFileName, ERSM_ID_FILE_NAME) != 0)
		{
			bResult = unZip.GotoNextFile();
			continue;
		}

		if(!unZip.ReadFileData(buf, uzFileInfo.dwUncompressedSize))
		{
			bResult = unZip.GotoNextFile();
			continue;
		}

		// 2. ������ Ǭ ����(XML)�κ��� ����ID�� �д´�.
		CNtlXMLDoc xmlDoc;
		if(xmlDoc.Create())
		{
			if(xmlDoc.LoadXML(buf))
			{
				ZeroMemory(szUserID, ERSM_BUF_SIZE);

				xmlDoc.GetDataWithXPath(ERSM_NODE_USER_ID, szUserID, ERSM_BUF_SIZE);

				strUserID = szUserID;
				break;
			}
		}

		bResult = unZip.GotoNextFile();
	}
	
	return strUserID;
}

bool CERSMWorker::RenameZipFiles() 
{
	for(UINT i = 0; i < m_vecErrorReportFiles.size(); ++i)
	{
		SErrorReportFile* pERF = m_vecErrorReportFiles[i];
		if(!pERF)
			continue;

		// ��¥�� ������ �����Ѵ�. (�̹� ������ �����ϰ� ������ False�� �����ϴµ�, �������)
		std::string strNewFolder = pERF->m_strFolderName + pERF->m_strFileDate;
		CreateDirectory(strNewFolder.c_str(), NULL);

		// ������ ������ ���� �̸��� �����Ͽ� �ִ´�.
		std::string strOldFileName = pERF->m_strFolderName + pERF->m_strFileName;
		std::string strNewFileName = strNewFolder;
		strNewFileName += "\\";
		strNewFileName += pERF->m_strUserID + "_";
		strNewFileName += pERF->m_strFileName;
		
		rename(strOldFileName.c_str(), strNewFileName.c_str());

		cout<<"# Rename Process Success--- ["<<strOldFileName<<"] to ["<<strNewFileName<<"]"<<GetTime()<<"\n";

	}
	return TRUE;
}

std::string CERSMWorker::GetTime() 
{
	CTime ctCurrentTime = CTime::GetCurrentTime();
	
	char buf[64] = {0,};
	sprintf_s(buf, "[%d-%02d-%02d %2d:%2d]", ctCurrentTime.GetYear(), ctCurrentTime.GetMonth(), ctCurrentTime.GetDay(), ctCurrentTime.GetHour(), ctCurrentTime.GetMinute());

	return buf;
}