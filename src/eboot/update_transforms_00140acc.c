/* HSTMATCH module=EBOOT.BIN start=0x00140acc end=0x00140d58 symbol=FUN_00140acc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/types.h"

extern void *DAT_003313c4;
extern void *DAT_003386cc;
extern void *DAT_00338714;

extern void FUN_0005c780(void *, void *);
extern void FUN_0005c854(void *, int, void *, void *);
extern void FUN_0005c900(void *, u32);
extern void FUN_0005c954(void *, u32, void *);
extern void FUN_0005c998(void *, u32, void *);
extern void FUN_0005ce18(void *, float, float, float, float);
extern void FUN_0005ce2c(void *, float, float, float);

#pragma opt_strength_reduction off

void FUN_00140acc(char *param_1)
{
    FUN_0005c780(DAT_003313c4, param_1 + 0xdf0);
    FUN_0005c854(DAT_003313c4, 0, param_1 + 0xe00, param_1 + 0xe10);
    FUN_0005c854(DAT_003313c4, 1, param_1 + 0xe20, param_1 + 0xe30);

    *(float *)(param_1 + 0xe50) = *(float *)(param_1 + 0xe00);
    *(float *)(param_1 + 0xe54) = *(float *)(param_1 + 0xe04);
    *(float *)(param_1 + 0xe58) = *(float *)(param_1 + 0xe08);
    *(float *)(param_1 + 0xe5c) = *(float *)(param_1 + 0xe0c);
    *(float *)(param_1 + 0xe70) = *(float *)(param_1 + 0xe20);
    *(float *)(param_1 + 0xe74) = *(float *)(param_1 + 0xe24);
    *(float *)(param_1 + 0xe78) = *(float *)(param_1 + 0xe28);
    *(float *)(param_1 + 0xe7c) = *(float *)(param_1 + 0xe2c);
    *(float *)(param_1 + 0xea0) = *(float *)(param_1 + 0xe00);
    *(float *)(param_1 + 0xea4) = *(float *)(param_1 + 0xe04);
    *(float *)(param_1 + 0xea8) = *(float *)(param_1 + 0xe08);
    *(float *)(param_1 + 0xeac) = *(float *)(param_1 + 0xe0c);
    *(float *)(param_1 + 0xec0) = *(float *)(param_1 + 0xe20);
    *(float *)(param_1 + 0xec4) = *(float *)(param_1 + 0xe24);
    *(float *)(param_1 + 0xec8) = *(float *)(param_1 + 0xe28);
    *(float *)(param_1 + 0xecc) = *(float *)(param_1 + 0xe2c);

    if (DAT_003386cc != 0) {
        FUN_0005c780(DAT_003386cc, param_1 + 0xe40);
        FUN_0005c854(DAT_003386cc, 0, param_1 + 0xe50, param_1 + 0xe60);
        FUN_0005c854(DAT_003386cc, 1, param_1 + 0xe70, param_1 + 0xe80);
    }

    if (DAT_00338714 != 0) {
        FUN_0005c780(DAT_00338714, param_1 + 0xe90);
        FUN_0005c854(DAT_00338714, 0, param_1 + 0xea0, param_1 + 0xeb0);
        FUN_0005c854(DAT_00338714, 1, param_1 + 0xec0, param_1 + 0xed0);
    }

    FUN_0005c900(DAT_003313c4, (int)*(int *)(param_1 + 0xd14));
    u32 uVar1 = 0;
    if (*(int *)(param_1 + 0xd14) != 0) {
        do {
            FUN_0005c954(DAT_003313c4, uVar1, (char *)*(int *)(param_1 + 0xd10) + (uVar1 << 5));
            FUN_0005c998(DAT_003313c4, uVar1, (char *)*(int *)(param_1 + 0xd10) + (uVar1 << 5) + 0x10);
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(u32 *)(param_1 + 0xd14));
    }

    if (DAT_00338714 != 0) {
        FUN_0005c900(DAT_00338714, *(u32 *)(param_1 + 0xd14));
        u32 uVar2 = 0;
        if (*(int *)(param_1 + 0xd14) != 0) {
            do {
                FUN_0005c954(DAT_00338714, uVar2, (char *)*(int *)(param_1 + 0xd10) + (uVar2 << 5));
                FUN_0005c998(DAT_00338714, uVar2, (char *)*(int *)(param_1 + 0xd10) + (uVar2 << 5) + 0x10);
                uVar2 = uVar2 + 1;
            } while (uVar2 < *(u32 *)(param_1 + 0xd14));
        }
    }

    FUN_0005ce18(DAT_003313c4, *(float *)(param_1 + 0x12e0), *(float *)(param_1 + 0x12e4),
                 *(float *)(param_1 + 0x12e8), *(float *)(param_1 + 0x12ec));
    FUN_0005ce2c(DAT_003313c4, *(float *)(param_1 + 0x12f0), *(float *)(param_1 + 0x12f4),
                 *(float *)(param_1 + 0x12f8));
}
