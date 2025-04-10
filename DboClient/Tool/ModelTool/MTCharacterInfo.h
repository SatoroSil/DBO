#pragma once

typedef std::map<std::string, RwFrame *>				FRAME_TABLE_MAP;
typedef std::map<std::string, RwFrame *>::iterator		FRAME_TABLE_ITER;

typedef std::map<std::string, RpMaterial *>				MATERIAL_TABLE_MAP;
typedef std::map<std::string, RpMaterial *>::iterator	MATERIAL_TABLE_ITER;

typedef std::map<std::string, RpAtomic *>				ATOMIC_TABLE_MAP;
typedef std::map<std::string, RpAtomic *>::iterator		ATOMIC_TABLE_ITER;
typedef std::map<RpMaterial*, RpAtomic*>                MATERIAL_ATOMIC_MAP;
typedef std::map<RpMaterial*, RpAtomic*>::iterator      MATERIAL_ATOMIC_MAP_ITER;


#define MAX_NUM_BONES   128

/// ���� ���� ����ü
typedef	struct _BoneMod
{
    RwReal	length;		///< ���� ����
    RwReal	width;		///< ���� �β�
    RwV3d	angles;		///< ���� ����
}BoneMod;

/**
 * \ingroup ModelTool
 * \brief Clump(ĳ����) ���� ������ �����ϴ� Ŭ���� 
 * \date 2006-04-10
 * \author agebreak
 */
class MTCharacterInfo
{
public:
	MTCharacterInfo(void);
	virtual ~MTCharacterInfo(void);

public:
	RwBool		Create(RpClump* pClump);				         ///< ���̺� ������ �����Ѵ�.
	void		Destroy();								         ///< ������ �����Ѵ�.

	RwFrame*	GetFrameByName(RwChar* chFrameName);	         ///< Ư�� Frame�� ��ȯ�Ѵ�.
	RpMaterial* GetMaterialByName(RwChar* chMaterialName);       ///< Ư�� Material�� ��ȯ�Ѵ�.
	RpAtomic*	GetAtomicByName(RwChar* chAtomicName);	         ///< Ư�� Atomic�� ��ȯ�Ѵ�.
    RpAtomic*   GetAtomicByMaterial(RpMaterial* pMaterial);      ///< �ش� Material�� �������ִ� Atomic�� ��ȯ�Ѵ�.

    void        UpdateHeightWidth();                             ///< ���̿� ���� ������ ������Ʈ �Ѵ�.

    // ȭ�鿡 ǥ���� ���� ����
    void        DisplayInfo(RtCharset* pCharSet);                ///< Clump ������ ȭ��� ǥ���Ѵ�.

	// CallBack �Լ���
	static RpAtomic*	GetClumpAllAtomics(RpAtomic* pAtomic, void* pData);		///< Clump���� ��� Atomic�� ������ �����ϴ� �ݹ� �Լ�
	static RwFrame*		GetChildFrame(RwFrame* pFrame, void* pData);			///< ��� �ڽ� Frame�� �����ͼ� �ʿ� �����ϴ� �ݹ� �Լ�
	static RpMaterial*	GetAllMaterials(RpMaterial* material, void* pData);     ///< ��� Material�� �����ͼ� �ʿ� �����ϴ� �ݹ� �Լ�

protected:
	void		SetClumpInfo();							///< Clump ���� ������ Map�� �����Ѵ�.


public:
	FRAME_TABLE_MAP		m_mapFrameTable;				///< Frame ���̺�
	MATERIAL_TABLE_MAP	m_mapMaterialtable;				///< Material ���̺�
	ATOMIC_TABLE_MAP	m_mapAtomicTable;				///< Atomic ���̺�
    MATERIAL_ATOMIC_MAP m_mapMaterialAtomicTable;       ///< Material - Atomic ���̺�

    static RpAtomic*    m_pTempAtomic;                  ///< Material - Atomic MAP�� ����� ���� �ӽ� Atomic ������

protected:
	RpClump*			m_pTargetClump;					///< ������ �о�� Clump

    // ȭ�鿡 ǥ���� ������
    static int          m_nTotalTriangels;              ///< ��ü Triangle ����
    static int          m_nTotalVertices;               ///< ��ü Vertex ����

    RwReal              m_fClumpHeight;                 ///< Clump�� ����
    RwReal              m_fClumpWidth;                  ///< Clump�� ����

    

};
