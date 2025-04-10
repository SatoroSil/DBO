#ifndef _NTL_TSCONTROLFACTORY_H_
#define _NTL_TSCONTROLFACTORY_H_


class CNtlTSControlObject;
class CNtlTSControlFactoryType_CNtlTSControlObject;


/**
	Control factory
*/


class CNtlTSControlFactory
{
// Declarations
public:
	typedef std::map<std::string, CNtlTSControlFactoryType_CNtlTSControlObject*> mapdef_CtrlTypeList;

// Member variables
protected:
	mapdef_CtrlTypeList					m_defCtrlTypeList;		// �ǽð� ���� ������ �����ϱ� ���� Ÿ�� ����Ʈ

// Constructions and Destructions
public:
	virtual ~CNtlTSControlFactory( void );

// Methods
public:
	virtual	CNtlTSControlObject*		CreateObj( const std::string& strName );
	virtual void						DeleteObj( CNtlTSControlObject*& pObj );

	// Runtime ������ ���� controller type ���
	virtual	void						RegisterCtrlType( void ) { return; }
	virtual	void						UnRegisterCtrlType( void );
};


#endif