#ifndef _DBO_DIRINDICATOR_H_
#define _DBO_DIRINDICATOR_H_


#include "DboTSCoreDefine.h"


class CDboTSActDirIndicator : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI


// Declarations
public:
	union uDirData
	{
		struct sTriggerObjectData
		{
			unsigned int				uiObjTblIdx;
		};

		struct sNPCData
		{
			unsigned int				uiNPCTblIdx;
		};

		struct sPointData
		{
			float						fX, fY, fZ;
		};

		sTriggerObjectData sTObj;
		sNPCData sNPC;
		sPointData sPos;
	};

// Member variables
protected:
	bool								m_bSelfDirIndicator;	// �ڽſ��Ը� ���� �Ǿ� �ϴ����� ���� �÷���
	bool								m_bDirIndicatorStart;	// True �� ����, False �� ����
	unsigned char						m_byDirType;
	uDirData							m_uiData;

// Constructions
public:
	CDboTSActDirIndicator( void );


// Methods
public:
	virtual unsigned int				GetEntityType( void ) const { return DBO_ACT_TYPE_ID_ACT_DIRINDICATOR; }

	bool								IsSelfDirIndicator( void ) const;
	void								SetSelfDirIndicator( bool bSelfDirIndicator );

	bool								IsDirIndicatorStart( void ) const;
	void								SetDirIndicatorStart( bool bDirIndicatorStart );

	unsigned char						GetDirectionIndicatorType( void ) const;
	void								SetDirectionIndicatorType( unsigned char byType );

	const uDirData&						GetDirectionIndicatorData( void ) const;
	void								SetDirectionIndicatorData( const uDirData& uData );


// Implementations
protected:
	// ��ũ��Ʈ�� ���� ������Ʈ ��ü�� �����͸� �ε� �� �Է� ��Ű�� ���� �Լ�
	virtual	void						ApplyScriptDataForScript( const CNtlTSScrProperty& clProperty );
	virtual	void						TakeScriptDataForScript( CNtlTSScrProperty& clProperty );
};


inline bool CDboTSActDirIndicator::IsSelfDirIndicator( void ) const
{
	return m_bSelfDirIndicator;
}

inline void CDboTSActDirIndicator::SetSelfDirIndicator( bool bSelfDirIndicator )
{
	m_bSelfDirIndicator = bSelfDirIndicator;
}

inline bool CDboTSActDirIndicator::IsDirIndicatorStart( void ) const
{
	return m_bDirIndicatorStart;
}

inline void CDboTSActDirIndicator::SetDirIndicatorStart( bool bDirIndicatorStart )
{
	m_bDirIndicatorStart = bDirIndicatorStart;
}

inline unsigned char CDboTSActDirIndicator::GetDirectionIndicatorType( void ) const
{
	return m_byDirType;
}


inline void CDboTSActDirIndicator::SetDirectionIndicatorType( unsigned char byDirType )
{
	m_byDirType = byDirType;
}


inline const CDboTSActDirIndicator::uDirData& CDboTSActDirIndicator::GetDirectionIndicatorData( void ) const
{
	return m_uiData;
}


inline void CDboTSActDirIndicator::SetDirectionIndicatorData( const uDirData& uData )
{
	m_uiData = uData;
}


#endif