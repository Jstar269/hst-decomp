/* HSTMATCH module=hstp_trans_main.prx start=0x00277a18 end=0x00277a98 symbol=FUN_00277a18 lang=c99 */
/* Clone of src/eboot/update_vector_active_00266a9c.c (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: typed Vec4 difference assignment and Vec3Pad local; exact match verified; names and types await human review. */
#include "hst/types.h"

struct Vec4 {
    float x, y, z, w;
};

struct Vec3Pad {
    float x, y, z;
    int pad;
};

extern void FUN_0002245c(struct Vec4 *, const void *, const void *);
extern void FUN_00022540(struct Vec3Pad *, const void *);
extern float FUN_0000c6f4(float, float);

void FUN_00277a18(char *param_1)
{
    struct Vec4 diff;
    struct Vec3Pad local_10;
    struct Vec4 tmp;

    if (*(u8 *)(param_1 + 0x160) != 0) {
        FUN_0002245c(&tmp, param_1 + 0x150, param_1 + 0x130);
        diff = tmp;
        *(float *)(param_1 + 0x168) = *(float *)(param_1 + 0x164);
        FUN_00022540(&local_10, &diff);
        local_10.pad = 0;
        *(float *)(param_1 + 0x164) = FUN_0000c6f4(local_10.x, local_10.z);
    }
}
