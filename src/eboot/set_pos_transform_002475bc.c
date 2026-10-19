/* HSTMATCH module=EBOOT.BIN start=0x002475bc end=0x00247674 symbol=FUN_002475bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-s256a/v2) corrected by hand: Vec4 struct value copy, explicit field assignments for subsequent float stores; exact match verified; names and types await human review. */

typedef struct {
    float x, y, z, w;
} Vec4;

extern void FUN_000550c8(int, Vec4 *);

void FUN_002475bc(int param_1, const Vec4 *param_2)
{
    Vec4 local_10 = *param_2;
    FUN_000550c8(param_1 + 0xe0, &local_10);
    if (*(int *)(param_1 + 0x454) != 150 && *(int *)(param_1 + 0x454) != 151) {
        FUN_000550c8(param_1 + 0x290, &local_10);
    }
    *(float *)(param_1 + 0x40) = local_10.x;
    *(float *)(param_1 + 0x44) = local_10.y;
    *(float *)(param_1 + 0x48) = local_10.z;
    *(float *)(param_1 + 0x4c) = local_10.w;
    *(float *)(param_1 + 0x50) = *(float *)(param_1 + 0x40);
    *(float *)(param_1 + 0x54) = *(float *)(param_1 + 0x44);
    *(float *)(param_1 + 0x58) = *(float *)(param_1 + 0x48);
    *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x4c);
}
