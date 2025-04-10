#ifndef _NTL_TSUIFACTORY_H_
#define _NTL_TSUIFACTORY_H_


class CNtlTSUIObject;
class CNtlTSUIFactoryType_CNtlTSUIObject;


/**
	UI factory
*/


class CNtlTSUIFactory
{
// Declarations
public:
	typedef std::map<std::string, CNtlTSUIFactoryType_CNtlTSUIObject*> mapdef_UITypeList;

// Member variables
protected:
	mapdef_UITypeList					m_defUITypeList;		// �ǽð� ���� ������ �����ϱ� ���� Ÿ�� ����Ʈ

// Constructions and Destructions
public:
	virtual ~CNtlTSUIFactory( void );

// Methods
public:
	virtual	CNtlTSUIObject*				CreateObj( const std::string& strName );
	virtual void						DeleteObj( CNtlTSUIObject*& pObj );

	// Runtime ������ ���� UI type ���
	virtual	void						RegisterUIType( void ) { return; }
	virtual	void						UnRegisterUIType( void );
};


#endif