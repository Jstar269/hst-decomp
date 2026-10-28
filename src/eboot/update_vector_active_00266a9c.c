/* HSTMATCH module=EBOOT.BIN start=0x00266a9c end=0x00266b1c symbol=FUN_00266a9c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: typed Vec4 difference assignment and Vec3Pad local; exact match verified; names and types await human review. */
#include "hst/types.h"

struct Vec4 {
    float x, y, z, w;
};

struct Vec3Pad {
    float x, y, z;
    int pad;
};

extern void FUN_00022434(struct Vec4 *, const void *, const void *);
extern void FUN_00022518(struct Vec3Pad *, const void *);
extern float FUN_0000c6dc(float, float);

void FUN_00266a9c(char *param_1)
{
    struct Vec4 diff;
    struct Vec3Pad local_10;
    struct Vec4 tmp;

    if (*(u8 *)(param_1 + 0x160) != 0) {
        FUN_00022434(&tmp, param_1 + 0x150, param_1 + 0x130);
        diff = tmp;
        *(float *)(param_1 + 0x168) = *(float *)(param_1 + 0x164);
        FUN_00022518(&local_10, &diff);
        local_10.pad = 0;
        *(float *)(param_1 + 0x164) = FUN_0000c6dc(local_10.x, local_10.z);
    }
}
