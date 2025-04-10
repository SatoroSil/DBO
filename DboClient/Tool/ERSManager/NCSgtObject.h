#pragma once

#include <Windows.h>
#include <assert.h>


template <class T> class NCSgtObject;


// NCSgtObject<classname>�� ����.
#if !defined (NCSGT)
#define NCSGT(classname) \
	Sgt##classname
#endif /* NCSGT */


//-------------------------------------------------------------
/*! '�̱���-������Ʈ' ���� ��ũ�� ����.
# NCDeclareSGT	: �ش�Ŭ���� �տ� Sgt�� ���� �̸���
#				 '�̱���-������Ʈ'�� ���Ѵ�.
#
# NCDefInitSGT,	
# NCInitSGT		: '�̱���-������Ʈ'�� �ʱ�ȭ�ϴ� �Լ��� ȣ��.
# NCDestroySGT	: '�̱���-������Ʈ'�� ������Ű�� �Լ��� ȣ��.
#
# NCGetSGT		: '�̱���-������Ʈ'�� �����ϴµ� ���.
*/
//------------------------------------------------------------
#if !defined (NCDeclareSGT)
#define NCDeclareSGT(classname) \
class classname; \
	typedef NCSgtObject<classname> NCSGT(classname)
#endif /* NCDeclareSGT */


#if !defined (NCDefInitSGT) 
#define NCDefInitSGT(classname) \
	NCSGT(classname)::Init() // default constructor
#endif /* NCDefInitSGT */

#if !defined (NCInitSGT)
#define NCInitSGT(classname, argu) \
{ \
	NCSGT(classname)::Init( false ); \
	assert( !NCSGT(classname)::ms_pObject ); \
	NCSGT(classname)::ms_pObject = NCNEW classname(argu); \
} 
#endif /* NCInitSGT */


#if !defined (NCDestroySGT)
#define NCDestroySGT(classname) \
	NCSGT(classname)::Destroy()
#endif /* NCDestroySGT */


#if !defined (NCGetSGT)
#define NCGetSGT(classname) \
	NCSGT(classname)::Get()
#endif /* NCGetSGT */

#if !defined (NCIsInitedSGT)
#define NCIsInitedSGT(classname) \
	NCSGT(classname)::IsInit()
#endif /* NCIsInitedSGT */


//----------------------------------------------------
/*! '�̱���(Singleton)-������Ʈ' Ŭ����
# ����, Ŭ������ T�� �����ڿ� �Ҹ��� �� �� �ϳ���
#public �Ǿ����� ���� ���,
# �̱���-������Ʈ�� ����� �� ����.
* \brief �̱���-������Ʈ Ŭ����
*/
//----------------------------------------------------
template <class T> class NCSgtObject
{ 
public:
	/*! �̱���-������Ʈ�� �ʱ�ȭ(�޸� �Ҵ�)��Ų��.
	# ����, �̹� �Ҵ�Ǿ� ���� ��쿡�� �޸𸮸� ���Ҵ����� �ʴ´�.
	*/
	static void Init();
	static void Init( bool binit );

	/*! �̱���-������Ʈ�� ������Ų��.
	# �ʱ�ȭ �� ������Ʈ�� �ݵ�� Destory()�� ȣ���� �־�� �Ѵ�.
	*/
	static void Destroy();

	/*! �̱���-������Ʈ�� �����Ѵ�.
	# �ݵ�� �ʱ�ȭ(Init) �� ȣ���Ѵ�.
	*/
	static T* Get();


	static bool IsInit();


	//---------------
	// ������/�Ҹ���
	//---------------
private:
	NCSgtObject( bool binit = true );

public:
	virtual ~NCSgtObject();

	//----------
	// �ɹ�����
	//----------
public:
	static T* ms_pObject;
private:
	static NCSgtObject<T>* ms_pThis;
};







// inline
#include "NCSgtObject.inl"



