/* HSTMATCH module=hstp_trans_main.prx start=0x0014c118 end=0x0014c3a4 symbol=FUN_0014c118 lang=c99 */
/* Clone of src/eboot/update_transforms_00140acc.c (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/types.h"

extern void *DAT_003da704;
extern void *DAT_003e1a0c;
extern void *DAT_003e1a54;

extern void FUN_0005d408(void *, void *);
extern void FUN_0005d580(void *, int, void *, void *);
extern void FUN_0005d68c(void *, u32);
extern void FUN_0005d6e0(void *, u32, void *);
extern void FUN_0005d724(void *, u32, void *);
extern void FUN_0005dbe0(void *, float, float, float, float);
extern void FUN_0005dbf4(void *, float, float, float);

#pragma opt_strength_reduction off

void FUN_0014c118(char *param_1)
{
    FUN_0005d408(DAT_003da704, param_1 + 0xdf0);
    FUN_0005d580(DAT_003da704, 0, param_1 + 0xe00, param_1 + 0xe10);
    FUN_0005d580(DAT_003da704, 1, param_1 + 0xe20, param_1 + 0xe30);

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

    if (DAT_003e1a0c != 0) {
        FUN_0005d408(DAT_003e1a0c, param_1 + 0xe40);
        FUN_0005d580(DAT_003e1a0c, 0, param_1 + 0xe50, param_1 + 0xe60);
        FUN_0005d580(DAT_003e1a0c, 1, param_1 + 0xe70, param_1 + 0xe80);
    }

    if (DAT_003e1a54 != 0) {
        FUN_0005d408(DAT_003e1a54, param_1 + 0xe90);
        FUN_0005d580(DAT_003e1a54, 0, param_1 + 0xea0, param_1 + 0xeb0);
        FUN_0005d580(DAT_003e1a54, 1, param_1 + 0xec0, param_1 + 0xed0);
    }

    FUN_0005d68c(DAT_003da704, (int)*(int *)(param_1 + 0xd14));
    u32 uVar1 = 0;
    if (*(int *)(param_1 + 0xd14) != 0) {
        do {
            FUN_0005d6e0(DAT_003da704, uVar1, (char *)*(int *)(param_1 + 0xd10) + (uVar1 << 5));
            FUN_0005d724(DAT_003da704, uVar1, (char *)*(int *)(param_1 + 0xd10) + (uVar1 << 5) + 0x10);
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(u32 *)(param_1 + 0xd14));
    }

    if (DAT_003e1a54 != 0) {
        FUN_0005d68c(DAT_003e1a54, *(u32 *)(param_1 + 0xd14));
        u32 uVar2 = 0;
        if (*(int *)(param_1 + 0xd14) != 0) {
            do {
                FUN_0005d6e0(DAT_003e1a54, uVar2, (char *)*(int *)(param_1 + 0xd10) + (uVar2 << 5));
                FUN_0005d724(DAT_003e1a54, uVar2, (char *)*(int *)(param_1 + 0xd10) + (uVar2 << 5) + 0x10);
                uVar2 = uVar2 + 1;
            } while (uVar2 < *(u32 *)(param_1 + 0xd14));
        }
    }

    FUN_0005dbe0(DAT_003da704, *(float *)(param_1 + 0x12e0), *(float *)(param_1 + 0x12e4),
                 *(float *)(param_1 + 0x12e8), *(float *)(param_1 + 0x12ec));
    FUN_0005dbf4(DAT_003da704, *(float *)(param_1 + 0x12f0), *(float *)(param_1 + 0x12f4),
                 *(float *)(param_1 + 0x12f8));
}
