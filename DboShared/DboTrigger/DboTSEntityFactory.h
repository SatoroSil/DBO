#ifndef _DBO_TSENTITYFACTORY_H_
#define _DBO_TSENTITYFACTORY_H_


/**
	Entity factory
*/


class CDboTSEntityFactory : public CNtlTSEntityFactory
{
// Methods
public:
	// Runtime ������ ���� Entity type ���
	virtual	void						RegisterEntityType( void );
};


#endif