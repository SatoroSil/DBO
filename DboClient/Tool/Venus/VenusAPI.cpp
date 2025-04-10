//***********************************************************************************
//	File		:	VenusAPI.cpp
//	Desc		:	
//	Begin		:	2005. 7.28
//	Copyright	:	�� 2005 by agebreak CO., Ltd
//	Author		:	agebreak
//	Update		:	
//***********************************************************************************

#include "stdafx.h"

#include "VenusAPI.h"
#include "NtlMath.h"

#include "StatusBarDialog.h"


#ifndef _ZERO
	#define _ZERO	0.00001f
#endif

//---------------------------------------------------------------------------
//	FuncName	:	VENUS_TRACE
//	Desc		:	
//	Parameter	:	
//	Return		:	
//---------------------------------------------------------------------------
void VENUS_TRACE(const RwChar* fmt, ...)
{
	RwChar str_buffer[MAX_PATH];

	va_list	ArgPtr;
	va_start(ArgPtr, fmt);
	_vsnprintf(str_buffer, sizeof(str_buffer), fmt, ArgPtr);
	va_end(ArgPtr);

	//; Trace message ���
	CStatusBarDialog::GetInstance().InsertTrace(str_buffer);
}

// CTextureDataDialog ��ȭ �����Դϴ�.
void GetDIBFromBitmap(GFL_BITMAP *bitmap, BITMAPINFOHEADER *bitmap_info, unsigned char **data)
{
	int i, j, bytes_per_line; 
	unsigned char *ptr_src, *ptr_dst; 
	
	*data = NULL; 
	
	memset(bitmap_info, 0, sizeof(BITMAPINFOHEADER)); 
	
	bitmap_info->biSize   = sizeof(BITMAPINFOHEADER); 
	bitmap_info->biWidth  = bitmap->Width; 
	bitmap_info->biHeight = bitmap->Height; 
	bitmap_info->biPlanes = 1; 
	
	bytes_per_line = (bitmap->Width * 3 + 3) & ~3; 
	bitmap_info->biClrUsed = 0;
	bitmap_info->biBitCount = 24; 
    bitmap_info->biCompression = BI_RGB; 
    bitmap_info->biSizeImage = bytes_per_line * bitmap->Height; 
    bitmap_info->biClrImportant = 0; 
	
	if (bitmap->Type != GFL_BINARY &&
		bitmap->Type != GFL_GREY   &&
		bitmap->Type != GFL_COLORS  )
		return; 
	
	*data = (unsigned char*)malloc(bitmap_info->biSizeImage); 
	
	for (i=0; i<bitmap->Height; i++)
	{
		ptr_src = bitmap->Data + i * bitmap->BytesPerLine; 
		ptr_dst = *data + i * bytes_per_line; 
		
		if (bitmap->Type == GFL_BINARY || bitmap->Type == GFL_GREY)
		{
			for (j=0; j<bitmap->Width; j++)
			{
				*ptr_dst++ = *ptr_src; 
				*ptr_dst++ = *ptr_src; 
				*ptr_dst++ = *ptr_src++; 
			}
		}
		else
		{
			if (bitmap->Type == GFL_COLORS)
			{
				for (j=0; j<bitmap->Width; j++)
				{
					*ptr_dst++ = bitmap->ColorMap->Blue[*ptr_src]; 
					*ptr_dst++ = bitmap->ColorMap->Green[*ptr_src]; 
					*ptr_dst++ = bitmap->ColorMap->Red[*ptr_src++]; 
				}
			}
			else
			{
				for (j=0; j<bitmap->Width; j++)
				{
					*ptr_dst++ = ptr_src[2]; 
					*ptr_dst++ = ptr_src[1]; 
					*ptr_dst++ = ptr_src[0]; 
					ptr_src += bitmap->BytesPerPixel; 
				}
			}
		}
	}
}

//------------------------------------------------------------------
//	FuncName	: N3API_IntersectionPolygonFromRay();
//	Desc		: ������ ������ ����ϴ� �� ���Ͱ� �������� ����ϴ��� �˻��Ѵ�.
//				  ���� ���Ͱ� �������� ����ϸ� ������ ������ �������� ������������ �Ÿ��� ���Ҽ� �ִ�
//	Parameter	: fSize - ������ ������ ������ ������������ �Ÿ�
//				  v3RayPos - ������ ��
//				  v3RayDir - ������ ������ ����ϴ� ����
//				  v0, v1, v2 - �������� �����ϴ� �� ��
//	Return		: bool - ���Ͱ� �������� ����ϸ� true, ������� ������ false �� �����Ѵ�.
//------------------------------------------------------------------
RwBool API_IntersectionPolygonFromRay(const RwV3d* pRayPos, const RwV3d* pRayDir, const RwV3d* v0, const RwV3d* v1, const RwV3d* v2, FLOAT* pfSize)
{
	FLOAT u, v;

	// ������ �߽����� �Ͽ� �ٸ��� ������ ���� ���� ���͸� ���Ѵ�
	RwV3d edge1;
	RwV3d edge2;

	RwV3dSubMacro (&edge1, v1, v0);
	RwV3dSubMacro (&edge2, v2, v0);

	// Begin calculating determinant - also used to calculate U parameter
	RwV3d pvec;
	RwV3dCrossProduct (&pvec, pRayDir, &edge2);

	// ���� ������ �� �ִ��� üũ
	FLOAT det = RwV3dDotProduct (&edge1, &pvec);
	if(det < _ZERO)
		return FALSE;

	// Calculate distance from vert0 to ray origin
	RwV3d tvec;
	RwV3dSubMacro(&tvec, pRayPos, v0);

	// Calculate U parameter and test bounds
	u = RwV3dDotProduct(&tvec, &pvec);

	if(u < 0.0f || u > det)
		return FALSE;

	// Prepare to test V parameter
	RwV3d qvec;
	RwV3dCrossProduct(&qvec, &tvec, &edge1);

	// Calculate V parameter and test bounds
	v = RwV3dDotProduct(pRayDir, &qvec);

	if(v < 0.0f || u + v > det)
		return FALSE;

	if (pfSize != NULL)
	{
		// Calculate t, scale parameters, ray intersects triangle
		*pfSize = RwV3dDotProduct(&edge2, &qvec);
		FLOAT fInvDet = 1.0f / det;
		*pfSize	*= fInvDet;
		u		*= fInvDet;
		v		*= fInvDet;
		if (*pfSize < 0.f) return FALSE;
	}
	else
	{
		RwReal fSize = RwV3dDotProduct(&edge2, &qvec);
		FLOAT fInvDet = 1.0f / det;
		fSize	*= fInvDet;
		if (fSize < 0.f) return FALSE;
	}

	return TRUE;
}

//------------------------------------------------------------------
//	FuncName	: API_DistancePointFromRay();
//	Desc		: Ray �� ������ �������� ���� ���ϱ�
//	Parameter	: vRayPos, vRayDir - ray �� ��ġ�� ����
//				  v3Point - ������ ����
//	Return		: float - 
//------------------------------------------------------------------
RwReal API_DistancePointFromRay(const RwV3d* pRayPos, const RwV3d* pRayDir, RwV3d* pPoint, RwReal* pfParam)
{
	RwV3d v3KDiff;
	RwV3dSubMacro(&v3KDiff, pPoint, pRayPos);
	RwReal fT = RwV3dDotProduct(&v3KDiff, pRayDir);

	if (fT <= 0.0f)
	{
		fT = 0.0f;
	}
	else
	{
		fT = fT / RwV3dLength(pRayDir);
		v3KDiff.x -= pRayDir->x * fT;
		v3KDiff.y -= pRayDir->y * fT;
		v3KDiff.z -= pRayDir->z * fT;
	}
    if (pfParam != NULL)
	{
		*pfParam = fT;
	}
	return RwV3dLength(&v3KDiff);
}

//------------------------------------------------------------------
//	FuncName	: API_IntersectionSphereFromRay();
//	Desc		: Ray �� ���� ���� ����
//	Parameter	: vRayPos, vRayDir - ray �� ��ġ�� ����
//				  v3SpherePos, fRadius - ���� ��ġ�� ������
//	Return		: 
//------------------------------------------------------------------
RwBool API_IntersectionSphereFromRay(const RwV3d* pRayPos, const RwV3d* pRayDir, RwV3d* pPoint, RwReal fSphrerRadius, RwReal* pfParam)
{
	RwReal fSqrDistance = API_DistancePointFromRay(pRayPos, pRayDir, pPoint, pfParam);

	return fSqrDistance <= fSphrerRadius ? TRUE : FALSE;
}

//------------------------------------------------------------------
//	FuncName	: API_GetLocalRay();
//	Desc		: 
//	Parameter	: 
//	Return		: 
//------------------------------------------------------------------
void API_GetLocalRay(RwV3d* pLocalRayPos, RwV3d* pLocalRayDir, const RwMatrix* pLocalMatrix, const RwV3d* pRayPos, const RwV3d* pRayDir)
{
	RwMatrix matInverse;
	RwMatrixInvert(&matInverse, pLocalMatrix);

	RwV3dTransformPoint(pLocalRayPos, pRayPos, &matInverse);

	RwMatrixGetPos(&matInverse)->x = RwMatrixGetPos(&matInverse)->y = RwMatrixGetPos(&matInverse)->z = 0.f;
	RwV3dTransformPoint(pLocalRayDir, pRayDir, &matInverse);

    if(RwV3dLength(pLocalRayDir) != 0)    
	    RwV3dNormalize(pLocalRayDir, pLocalRayDir);
}

//---------------------------------------------------------------------------
//Name		: API_IntersectionPlane
//Desc		: 
//Return	: 
//Parameter	: 
//---------------------------------------------------------------------------
RwBool API_IntersectionPlane(const RwV3d* pRayPos, const RwV3d* pRayDir, RwV3d* p0, RwV3d* p1, RwV3d* p2, RwV3d* p3, RwReal& fDistance, RwBool b2Side)
{
	if(API_IntersectionPolygonFromRay(pRayPos, pRayDir, p0, p1, p2, &fDistance))
	{
		return TRUE;
	}
	else if(API_IntersectionPolygonFromRay(pRayPos, pRayDir, p0, p2, p3, &fDistance))
	{
		return TRUE;
	}
	if (b2Side)
	{
		if(API_IntersectionPolygonFromRay(pRayPos, pRayDir, p0, p2, p1, &fDistance))
		{
			return TRUE;
		}
		else if(API_IntersectionPolygonFromRay(pRayPos, pRayDir, p0, p3, p2, &fDistance))
		{
			return TRUE;
		}
	}
	return FALSE;
}


RwBool bFirstAtomic = TRUE;
//------------------------------------------------------------------
//	FuncName	: AtomicAddBoundingSphere();
//	Desc		: 
//	Parameter	:
//	Return		: 
//------------------------------------------------------------------
RpAtomic* API_AtomicBoundingSphere(RpAtomic* atomic, void* data)
{
    RwSphere atomicSphere, *clumpSphere;
    RwReal separation, radius;
    RwV3d center, temp;
    RwMatrix transform;

    /*
     * The clump's bounding-sphere is calculated by first setting the
     * bounding-sphere equal the first atomic's bounding-sphere, then growing
     * the clump's bounding-sphere to enclose the next and future atomic
     * bounding-sphere...
     */

	clumpSphere = (RwSphere *)data;
	atomicSphere = *RpAtomicGetBoundingSphere(atomic);

	transform = *RwFrameGetLTM(RpAtomicGetFrame(atomic));

    RwV3dTransformPoint(&atomicSphere.center, 
        &atomicSphere.center, &transform);

    if(bFirstAtomic)
    {
        /*
         * Initialize the clump's bounding-sphere with the center 
         * and radius of the first atomic bounding-sphere...
         */
        clumpSphere->center = atomicSphere.center;
        clumpSphere->radius = atomicSphere.radius;

        bFirstAtomic = FALSE;

        return atomic;
    }

    /*
     * Test if the clump's bounding-sphere already encloses this atomic's
     * bounding-sphere, by finding if the distance between the two bounding-
     * sphere centers plus the radius of the atomic's bounding-sphere, is 
     * less than the clump's bounding-sphere radius...
     */
    RwV3dSubMacro(&temp, &atomicSphere.center, &clumpSphere->center);
    separation = RwV3dLength(&temp);

    if( separation + atomicSphere.radius < clumpSphere->radius )
    {
        return atomic;
    }

    /*
     * Calculate the clump's new bounding-sphere radius...
     */
    radius = (separation + atomicSphere.radius + clumpSphere->radius) * 0.5f;

    /*
     * Calculate the clump's new bounding-sphere center...
     */
    RwV3dScale(&temp, &temp, 1.0f/separation);

    RwV3dScale(&temp, &temp, atomicSphere.radius - clumpSphere->radius);
    RwV3dAdd(&center, &clumpSphere->center, &atomicSphere.center);
    RwV3dAdd(&center, &center, &temp);
    
    RwV3dScale(&center, &center, 0.5f);

    clumpSphere->center = center;
    clumpSphere->radius = radius;

    return atomic;
}

//---------------------------------------------------------------------------
//Name		: API_CalculationShpere
//Desc		: 
//Return	: 
//Parameter	: 
//---------------------------------------------------------------------------
void API_CalculationShpere(RwSphere& sphere, RpClump* pClump)
{
	bFirstAtomic = TRUE;
    RpClumpForAllAtomics(pClump, API_AtomicBoundingSphere, &sphere);
}


RwBool API_GetAtUpVecApplyAngle(RwV3d* outLookAtVec, RwV3d* outLookUpVec, const RwV3d vAngle)
{
    if(!outLookAtVec || !outLookUpVec)
        return FALSE;
        
    RwMatrix    mat;    
    RwV3d vAxisX = {1.0f, 0.0f, 0.0f};
    RwV3d vAxisY = {0.0f, 1.0f, 0.0f};
    RwV3d vAxisZ = {0.0f, 0.0f, 1.0f};
    
    RwMatrixSetIdentity(&mat);

    RwMatrixRotate(&mat, &vAxisX, vAngle.x, rwCOMBINEREPLACE);
    RwMatrixRotate(&mat, &vAxisY, vAngle.y, rwCOMBINEPOSTCONCAT);
    RwMatrixRotate(&mat, &vAxisZ, vAngle.z, rwCOMBINEPOSTCONCAT);

    RwV3d tempLookAt = mat.at;
    RwV3d tempLookUp = mat.up;

    RwV3dNormalize(outLookAtVec, &tempLookAt);
    RwV3dNormalize(outLookUpVec, &tempLookUp);

    return TRUE;
}

/**
 * �־��� Vector��� Angle�� ���Ѵ�.
 * \param vUpVec LookUp Vector
 * \param vAtVec LookAt Vector
 * return Angle�� ���� RwV3d�� (X, Y, Z Angle, Degree)
 */
RwV3d API_GetAngle(RwV3d vUpVec, RwV3d vAtVec)
{
    RwV3d vOutAngle;
    ZeroMemory(&vOutAngle, sizeof(vOutAngle));

    RwMatrix mat;
    RwMatrixSetIdentity(&mat);

    mat.up = vUpVec;
    mat.at = vAtVec;
    RwV3dCrossProduct(&mat.right, &mat.at, &mat.up);

    CNtlMath::MathGetMatrixEulerAngle(&mat, &vOutAngle);

    return vOutAngle;    
}