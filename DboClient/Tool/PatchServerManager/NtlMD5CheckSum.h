#pragma once

/// üũ�� ������ ���� ����ü
struct SChecksumInfo
{
    char szFileName[MAX_PATH];
    char checksum[33];

    SChecksumInfo()
    {
        ZeroMemory(szFileName, MAX_PATH);
        ZeroMemory(checksum, 33);
    }
};

/**
 * \ingroup MD5SumTest
 * \brief ���ϵ��� MD5 Checksum�� �̿��Ͽ�, ���Ἲ �˻縦 �����ϴ� Ŭ����
 *
 * \date 2009-02-23
 * \author agebreak
 */
class CNtlMD5CheckSum
{
public:
    CNtlMD5CheckSum(void);
    virtual ~CNtlMD5CheckSum(void);

	unsigned int CheckSumBuildCount(char* szFolder);					///< ����Ǵ� üũ�� ������ �� ����
    int CheckSumBuild(char* szChecksumFileName, char* szFolder);		///< ������ ���ϵ�(���� ���� ����)�� ���� üũ�� ������ �����Ѵ�.
	unsigned int CheckSumTestCount(char* szChecksumFileName);			///< ����Ǿ��ִ� üũ�� ������ �� ����
    int ChecksumTest(char* szChecksumFileName);							///< ������ üũ�� ���ϵ��� ���Ѵ�.

protected:
    int md5_wrapper( char *filename, unsigned char *sum );
    int md5_print(const char *filename, char* checksum );
    int md5_check( char *filename );

    bool RecursiveChecksumBuild( bool bForCounter, unsigned int& uiCnt );		///< ���� �������� ��ͷ����� ���鼭 üũ�� ������ �����.
    int  WriteChecksumBuild(char* szFileName);									///< ������� üũ�� ������ ���Ͽ� ����Ѵ�.

	virtual bool IsSkipFileOnChecksumBuild(char* szFileName, bool bFolder) { return false; }

    virtual bool OnEvent_ChecksumBuild(const char* szFileName, int returnCode);		///< üũ�� ���� ����� �޴� �Լ�
    virtual bool OnEvent_ChecksumTest(const char* szFileName, int returnCode);		///< üũ�� �� ����� �޴� �Լ�

protected:
    std::list<SChecksumInfo*>       m_listCheksum;                      ///< üũ�� ���� ����Ʈ
    size_t                          m_nWorkingFolderLength;             ///< �۾� ���� �̸��� ����
};
