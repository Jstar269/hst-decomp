/* HSTMATCH module=EBOOT.BIN start=0x00140acc end=0x00140d58 symbol=FUN_00140acc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/types.h"

#include "hst/xform_host.h"

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

/* Pulls transform data from the three global sources into the owner, then uploads its entry table. */
void FUN_00140acc(XformHost *self)
{
    FUN_0005c780(DAT_003313c4, self->unkdf0);
    FUN_0005c854(DAT_003313c4, 0, self->unke00, self->unke10);
    FUN_0005c854(DAT_003313c4, 1, self->unke20, self->unke30);

    self->unke50[0] = self->unke00[0];
    self->unke50[1] = self->unke00[1];
    self->unke50[2] = self->unke00[2];
    self->unke50[3] = self->unke00[3];
    self->unke70[0] = self->unke20[0];
    self->unke70[1] = self->unke20[1];
    self->unke70[2] = self->unke20[2];
    self->unke70[3] = self->unke20[3];
    self->unkea0[0] = self->unke00[0];
    self->unkea0[1] = self->unke00[1];
    self->unkea0[2] = self->unke00[2];
    self->unkea0[3] = self->unke00[3];
    self->unkec0[0] = self->unke20[0];
    self->unkec0[1] = self->unke20[1];
    self->unkec0[2] = self->unke20[2];
    self->unkec0[3] = self->unke20[3];

    if (DAT_003386cc != 0) {
        FUN_0005c780(DAT_003386cc, self->unke40);
        FUN_0005c854(DAT_003386cc, 0, self->unke50, self->unke60);
        FUN_0005c854(DAT_003386cc, 1, self->unke70, self->unke80);
    }

    if (DAT_00338714 != 0) {
        FUN_0005c780(DAT_00338714, self->unke90);
        FUN_0005c854(DAT_00338714, 0, self->unkea0, self->unkeb0);
        FUN_0005c854(DAT_00338714, 1, self->unkec0, self->unked0);
    }

    FUN_0005c900(DAT_003313c4, self->entryCount);
    u32 i = 0;
    if (self->entryCount != 0) {
        do {
            FUN_0005c954(DAT_003313c4, i, self->entries[i].unk00);
            FUN_0005c998(DAT_003313c4, i, self->entries[i].unk10);
            i = i + 1;
        } while (i < *(u32 *)&self->entryCount);
    }

    if (DAT_00338714 != 0) {
        FUN_0005c900(DAT_00338714, *(u32 *)&self->entryCount);
        u32 j = 0;
        if (self->entryCount != 0) {
            do {
                FUN_0005c954(DAT_00338714, j, self->entries[j].unk00);
                FUN_0005c998(DAT_00338714, j, self->entries[j].unk10);
                j = j + 1;
            } while (j < *(u32 *)&self->entryCount);
        }
    }

    FUN_0005ce18(DAT_003313c4, self->unk12e0[0], self->unk12e0[1], self->unk12e0[2], self->unk12e0[3]);
    FUN_0005ce2c(DAT_003313c4, self->unk12f0[0], self->unk12f0[1], self->unk12f0[2]);
}
