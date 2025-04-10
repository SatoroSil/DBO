#ifndef _DBO_TSUIFFACTORYTYPE_H_
#define _DBO_TSUIFFACTORYTYPE_H_


/** 
	UI ��ü�� Runtime �ÿ� �����ϱ� ���� ui type class ��
*/


class CDboTSUIFactoryType_CDboTSTRecv : public CNtlTSUIFactoryType_CNtlTSRecv
{
// Constructions and Destructions
public:
	CDboTSUIFactoryType_CDboTSTRecv( void );

// Methods
public:
	virtual	CNtlTSUIObject*				CreateObj( void );
	virtual void						DeleteObj( CNtlTSUIObject*& pObj );
	virtual const char*					GetKeyword( void ) const;
};


class CDboTSUIFactoryType_CDboTSQRecv : public CDboTSUIFactoryType_CDboTSTRecv
{
// Constructions and Destructions
public:
	CDboTSUIFactoryType_CDboTSQRecv( void );

// Methods
public:
	virtual	CNtlTSUIObject*				CreateObj( void );
	virtual void						DeleteObj( CNtlTSUIObject*& pObj );
	virtual const char*					GetKeyword( void ) const;
};


class CDboTSUIFactoryType_CDboTSTAgency : public CNtlTSUIFactoryType_CNtlTSAgency
{
// Constructions and Destructions
public:
	CDboTSUIFactoryType_CDboTSTAgency( void );

// Methods
public:
	virtual	CNtlTSUIObject*				CreateObj( void );
	virtual void						DeleteObj( CNtlTSUIObject*& pObj );
	virtual const char*					GetKeyword( void ) const;
};


class CDboTSUIFactoryType_CDboTSQAgency : public CDboTSUIFactoryType_CDboTSTAgency
{
// Constructions and Destructions
public:
	CDboTSUIFactoryType_CDboTSQAgency( void );

// Methods
public:
	virtual	CNtlTSUIObject*				CreateObj( void );
	virtual void						DeleteObj( CNtlTSUIObject*& pObj );
	virtual const char*					GetKeyword( void ) const;
};


class CDboTSUIFactoryType_CDboTSMain : public CNtlTSUIFactoryType_CNtlTSMain
{
// Constructions and Destructions
public:
	CDboTSUIFactoryType_CDboTSMain( void );

// Methods
public:
	virtual	CNtlTSUIObject*				CreateObj( void );
	virtual void						DeleteObj( CNtlTSUIObject*& pObj );
	virtual const char*					GetKeyword( void ) const;
};


#endif