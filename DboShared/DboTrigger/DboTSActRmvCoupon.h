#ifndef _DBO_RMV_COUPON_H_
#define _DBO_RMV_COUPON_H_


#include "DboTSCoreDefine.h"


class CDboTSActRmvCoupon : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI


// Member variables
protected:

// Constructions
public:
	CDboTSActRmvCoupon( void );


// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_RMV_COUPON; }


// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


#endif