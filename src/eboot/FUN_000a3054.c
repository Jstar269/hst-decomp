/* HSTMATCH module=EBOOT.BIN start=0x000a3054 end=0x000a31b4 symbol=FUN_000a3054 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: clamp macro, angle scaling, componentwise matrix translation and copy; readability pass; exact match verified; names and types await human review. */

#include "hst/rig_obj.h"

extern int DAT_00341284;
extern int DAT_00341288;
extern int DAT_002bc410;
extern void FUN_0004d2d4(float angle, void *out, void *identity);

struct Vec4 {
    float x, y, z, w;
};

struct Mat4 {
    union {
        struct {
            struct Vec4 r0, r1, r2, r3;
        };
        float m[16];
    };
};

/* Builds a rotation matrix from a clamped angle (negated for the matching hand) and copies it to out with the object's position as the last row. */
void FUN_000a3054(float *out, RigObj *obj, _Bool flag, float angle)
{
    float val = (angle < (float)DAT_00341288) ? (float)DAT_00341288 : ((angle > (float)DAT_00341284) ? (float)DAT_00341284 : angle);

    val = (val * 0.87266463f) / (float)DAT_00341284;

    if (flag == (obj->hand == 0)) {
        val = val * -1.0f;
    }

    struct Mat4 local_mat;
    FUN_0004d2d4(val, &local_mat, &DAT_002bc410);

    local_mat.r3.x = obj->rows[3].x;
    local_mat.r3.y = obj->rows[3].y;
    local_mat.r3.z = obj->rows[3].z;
    local_mat.r3.w = obj->rows[3].w;

    out[0] = local_mat.m[0];
    out[1] = local_mat.m[1];
    out[2] = local_mat.m[2];
    out[3] = local_mat.m[3];
    out[4] = local_mat.m[4];
    out[5] = local_mat.m[5];
    out[6] = local_mat.m[6];
    out[7] = local_mat.m[7];
    out[8] = local_mat.m[8];
    out[9] = local_mat.m[9];
    out[10] = local_mat.m[10];
    out[11] = local_mat.m[11];
    out[12] = local_mat.m[12];
    out[13] = local_mat.m[13];
    out[14] = local_mat.m[14];
    out[15] = local_mat.m[15];
}
