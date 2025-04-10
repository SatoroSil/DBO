#pragma once


#include "TSTrigger.h"


/** 
	CTSProject
*/


class CTSProject
{
// Declarations
public:
	#define PROJECT_FILE_EXTENTION		(_T("pro"))
	#define TS_FILE_EXTENTION			(_T("ts"))

// Member variables
protected:
	bool								m_bCreated;

	CString								m_strHeader;
	DWORD								m_dwVersion;	// Project version
	CString								m_strProjName;	// Project name
	DWORD								m_dwTSType;		// Trigger system type

	CArray<CString, const CString&>		m_aTriggerList;	// Ʈ���� ���� ����Ʈ
	CTSTrigger							m_TSTrigger;	// ���� �ε��� Ʈ����

	CString								m_strPath;

// Constructions and Destructions
public:
	CTSProject( void );
	virtual ~CTSProject( void );

// Methods
public:
	bool								IsCreated( void ) const	{ return m_bCreated; }

	void								CreateOnInit( const CString& strProjPath, const CString& strProjName, DWORD dwMode );
	void								Delete( void );

	DWORD								GetProjectVersion( void ) const;
	DWORD								GetProjectMode( void ) const;
	const CString&						GetProjectPath( void ) const;
	CString								GetProjectFullName( void ) const;

	CTSTrigger&							GetTrigger( void );
	CArray<CString, const CString&>&	GetTriggerList( void );

	void								Load( const CString& strFullName );
	void								Reload( void );
	void								Save( const CString& strFullName );

// Implementations
protected:
	void								Create( const CString& strProjPath );

	bool								LoadTS( const CString& strPath );
	bool								AddTriggerList( CString& strName );
};


inline DWORD CTSProject::GetProjectVersion( void ) const
{
	return m_dwVersion;
}

inline DWORD CTSProject::GetProjectMode( void ) const
{
	return m_dwTSType;
}

inline const CString& CTSProject::GetProjectPath( void ) const
{
	return m_strPath;
}

inline CString CTSProject::GetProjectFullName( void ) const
{
	return m_strPath + CString(_T("\\")) + m_strProjName + CString(_T(".pro"));
}

inline CTSTrigger& CTSProject::GetTrigger( void )
{
	return m_TSTrigger;
}

inline CArray<CString, const CString&>& CTSProject::GetTriggerList( void )
{
	return m_aTriggerList;
}
