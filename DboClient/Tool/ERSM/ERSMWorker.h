#pragma once

/// ���� ����Ʈ ���� ����ü
struct SErrorReportFile
{
	std::string m_strFolderName;	///< ������ ��ġ�� ������
	std::string	m_strFileName;		///< ���� �̸� (���� ����)
	std::string m_strUserID;		///< ���� ID
	std::string m_strFileDate;		///< ���� ���� ��¥ (20070130 ����)
};

/// ���� ������� �۵��ϸ鼭 �۾��� ó���ϴ� Ŭ����
class CERSMWorker
{
public:
	CERSMWorker(void);
	virtual ~CERSMWorker(void);

public:
	bool ProcessErrReports();										///< ���� ����Ʈ ���ϵ��� ó���� �����Ѵ�.
	
protected:
	bool GetListZipFiles(const std::string& strFolderName);			///< �����κ��� Zip������ �����ͼ� ���͸� �����Ѵ�.
	std::string GetUserIDFromZipFile(const std::string& strZipFileName);	///< Zip���Ϸκ��� ���� ID�� �����´�.
	bool RenameZipFiles();											///< ZipFile���� �̸��� �����Ѵ�.	

	void Clear();													///< ���ͳ��� ������ ����.
	string GetTime();												///< ���� �ð��� ���ڿ��� ��ȯ�Ѵ�.

protected:
	std::vector<SErrorReportFile*>	m_vecErrorReportFiles;			///< ���� ����Ʈ ���� ����ü���� ����
};
