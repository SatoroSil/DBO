#ifndef _NTL_TSSCRFACTORY_H_
#define _NTL_TSSCRFACTORY_H_


class CNtlTSScrObject;
class CNtlTSScrFactoryType;


/** 
	Script factory
	Script �� ���ؼ� ��ü�� �ڵ������ϱ� ���ؼ��� �Ʒ� Ŭ������ ��ӹ޾� Factory Ŭ������ �����ؾ� ��
*/


class CNtlTSScrFactory
{
// Constructions and Destructions
public:
	virtual ~CNtlTSScrFactory( void ) { return; }

// Methods
public:
	// �����ϰ��� �ϴ� Ŭ���� �̸��� �Ķ���ͷ� �Է��ϸ�,
	// �ش� Ŭ������ ������ �� �ִ� FactoryType�� ���ϵȴ�
	virtual	CNtlTSScrFactoryType*		GetFactoryType( const std::string& strClassName ) = 0;

	virtual	CNtlTSScrObject*			CreateObj( const std::string& strTypeName ) = 0;
	virtual void						DeleteObj( CNtlTSScrObject*& pObj ) = 0;
};


#endif