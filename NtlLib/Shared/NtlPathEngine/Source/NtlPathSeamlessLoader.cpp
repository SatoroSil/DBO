#include "Precomp_NtlPathEngine.h"
#include "NtlPathSeamlessLoader.h"

#include "NtlPathSeamlessLoadingManager.h"
#include "NtlSeamlessMesh.h"

// Debug
#include "PerformanceChecker.h"
#include "NtlPathEngineLog.h"

CNtlPathSeamlessLoader::CNtlPathSeamlessLoader()
: m_pManager( NULL )
{

}

CNtlPathSeamlessLoader::~CNtlPathSeamlessLoader()
{

}

bool CNtlPathSeamlessLoader::Create(  )
{
	return true;
}

unsigned int __stdcall CNtlPathSeamlessLoader::ThreadFunc( void* pParam )
{
	while( !GetNtlPathEngineLoadingManager()->IsExit() )
	{
		// WaitSingleObject
		WaitForSingleObjectEx( GetNtlPathEngineLoadingManager()->GetEvent(), INFINITE, FALSE );

		// 1. �ε� �Ǿ�� �� �͵��� �ִ��� üũ
		CNtlSeamlessMesh* pMesh = GetNtlPathEngineLoadingManager()->GetLoadReservation();
		if( !pMesh )
			continue;

		// 2. �ε� �Ϸ� ������ �ε� �Ϸ��ߴٰ� �־���

		static CPerformanceChecker perf;
		perf.Run();
		pMesh->BuildMeshFromIndexs();
		perf.Stop();
		CNtlPathEngineLog::GetInstance()->Log( "1 Tile Loaded Time %f", perf.GetLastTime() );
		
		GetNtlPathEngineLoadingManager()->Loaded( pMesh );

		// Test
		printf_s("Loading Complete! \n");
	}

	return 0;
}

void CNtlPathSeamlessLoader::Destroy()
{

}