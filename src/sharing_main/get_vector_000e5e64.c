/* HSTMATCH module=hstp_trans_main.prx start=0x000e5e64 end=0x000e5f04 symbol=FUN_000e5e64 lang=c99 */
/* Clone of src/eboot/get_vector_000e189c.c (hstclone.py tag s10172123g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: Vec4 local temporaries and field-wise destination copy; exact match verified; names and types await human review. */
typedef unsigned int uint;

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

extern uint DAT_0037d8ac[];
extern void FUN_0001d430(Vec4 *out, uint param_2);

void FUN_000e5e64(char *param_1, int param_2)
{
    Vec4 v1;
    Vec4 v2;
    Vec4 *dst;

    FUN_0001d430(&v1, *(uint *)(*(int *)(param_1 + 0x3c) + 0x38));
    if (DAT_0037d8ac[param_2] != 0) {
        FUN_0001d430(&v2, DAT_0037d8ac[param_2]);
        v1 = v2;
    }
    dst = (Vec4 *)(param_1 + 0x80);
    dst->x = v1.x;
    dst->y = v1.y;
    dst->z = v1.z;
    dst->w = v1.w;
}
