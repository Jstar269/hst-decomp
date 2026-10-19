/* HSTMATCH module=hstp_trans_main.prx start=0x000a57c0 end=0x000a5920 symbol=FUN_000a57c0 lang=c99 */
/* Clone of src/eboot/FUN_000a3054.c (hstclone.py tag s10172123g5r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: clamp macro, angle scaling, componentwise matrix translation and copy; exact match verified; names and types await human review. */

extern int DAT_003ea5c4;
extern int DAT_003ea5c8;
extern int DAT_002cc260;
extern void FUN_0004d64c(float angle, void *out, void *identity);

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

struct Obj {
    char pad[336];
    int f150;      // 336 (0x150)
    char pad2[1408 - 340];
    struct Vec4 pos; // 1408 (0x580)
};

void FUN_000a57c0(float *out, struct Obj *obj, _Bool flag, float angle)
{
    float val = (angle < (float)DAT_003ea5c8) ? (float)DAT_003ea5c8 : ((angle > (float)DAT_003ea5c4) ? (float)DAT_003ea5c4 : angle);

    val = (val * 0.87266463f) / (float)DAT_003ea5c4;

    if (flag == (obj->f150 == 0)) {
        val = val * -1.0f;
    }

    struct Mat4 local_mat;
    FUN_0004d64c(val, &local_mat, &DAT_002cc260);

    local_mat.r3.x = obj->pos.x;
    local_mat.r3.y = obj->pos.y;
    local_mat.r3.z = obj->pos.z;
    local_mat.r3.w = obj->pos.w;

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
