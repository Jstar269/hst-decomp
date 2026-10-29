/* Parameter block of a view object: three float4 values, an angle in degrees and two more floats. */
#ifndef HST_VIEW_PARAMS_H
#define HST_VIEW_PARAMS_H

#include "hst/vec.h"

typedef struct ViewParams {
    char pad00[0x1d0];
    Float4 vec1d0;       /* 0x1d0 */
    Float4 vec1e0;       /* 0x1e0 */
    Float4 vec1f0;       /* 0x1f0 */
    float angleDeg;      /* 0x200 angle in degrees; unk214 is derived from it */
    float unk204;        /* 0x204 */
    float unk208;        /* 0x208 */
    char pad20c[8];
    float unk214;        /* 0x214 */
} ViewParams;

#endif
