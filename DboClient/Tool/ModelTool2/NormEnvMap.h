#pragma once
#include "rtnormmap.h"
#include "rpnormmap.h"

#define  FAST_MODE

/**
 * \ingroup ModelTool2
 * \brief Normal Map�� Env Map�� ����, �����ϴ� Ŭ����
 * \date 2006-06-28
 * \author agebreak
 */
class CNormEnvMap
{
public:
    CNormEnvMap(void);
    virtual ~CNormEnvMap(void);

    static void SetEnableNormMap(RpClump* pClump, RwBool bEnable);                    ///< �븻��, EnvMap�� �����Ѵ�.
    static void SetNormMap(RpMaterial* pMaterial, RwBool bEnable);                    ///< �븻���� �����Ѵ�.
    static void SetEnvMap(RpMaterial* pMaterial, RwTexture* pTexture);                ///< EnvMap�� �����Ѵ�.
    static void SetEnvMapShininess(RpMaterial* pMaterial, RwReal fShininess);         ///< Shininess�� �����Ѵ�.

protected:
    static RwTexture* NormalMapTextureSpaceCreateFromTexture(RwTexture *texture, RwReal bumpness);
    static RwRaster*  NormalMapTextureSpaceCreateFromImage(RwImage *image, RwUInt32 rasterFlags, RwBool clamp, RwReal bumpness);
    static RwBool IsAnim(RpClump* pClump);                                            ///< Anim�� ����ƴ��� �ȵƴ����� ��ȯ�Ѵ�.
};
