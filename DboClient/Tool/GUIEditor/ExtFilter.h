//-----------------------------------------------------------------------------
// Name: class CExtFilter
// Desc: PathName�� �޾Ƽ� Ȯ���ڸ� �����ְų� Ŭ����.
//       ��ϵ� Ȯ�������� ������ Ŭ����. 
//
// 2006.01.17 Peessi@hitel.net  
//-----------------------------------------------------------------------------
#pragma once

#include <map>
#include <string>
#include "windows.h"

class CExtFilter
{
public:
	CExtFilter(void);
	~CExtFilter(void);

	enum    EXTTYPE { NONE = 0, IMAGE, RESOURCE, SURFACE, COMPONENT };

	typedef std::string					   stlString;
	typedef std::map< stlString, EXTTYPE > stlExtMap;
	
	void	Create();
	void    Destroy();

	void    ExtDefinition();		// ���⿡ ���̴� Ȯ���ڸ� ���� �ִ´�.

	// operation
	BOOL	IsValid( LPCTSTR szPath );
	EXTTYPE GetType( LPCTSTR szPath );
	BOOL	GetExt( LPCTSTR szPath, stlString* pExt );

private:
	
    // Variables
	stlExtMap m_stlExtMap;
};
