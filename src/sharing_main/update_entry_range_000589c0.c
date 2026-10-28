/* HSTMATCH module=hstp_trans_main.prx start=0x000589c0 end=0x00058b30 symbol=FUN_000589c0 lang=c99 */
/* Clone of src/eboot/update_entry_range_00057d6c.c (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Resets the animation-entry range of the object: with the manager at +0x8c present it copies the
   manager's pose block into the object's own block at +0x160, then walks the 52-byte entries in
   [start_idx, end_idx], stores (entry->f18 - 1.0f) into entry->f14 and calls the per-entry update
   FUN_000593fc; finally it clears the flag byte at +0xec and refreshes the pose (FUN_0005982c) and
   the matrices (FUN_00059f10) when the object's animation list at +0x16c is present. */
#include "hst/types.h"

typedef struct {
    char pad[8];
    void *f8;
} Mgr;

typedef struct {
    int f00;
    int f04;
    u8 f08;
    char pad1[3];
    float f0c;
    float f10;
    float f14;
    float f18;
    int f1c;
    char pad2[4];
    int f24;
    char pad3[12];
} Rec;

typedef struct {
    char pad[0x8c];
    Mgr *f8c;
    char pad1[0xec - 0x90];
    u8 flag_ec;
    char pad2[3];
    Rec recs[2];
    int start_idx;
    int end_idx;
    void *f160;
    char pad3[8];
    void *f16c;
} Self;

extern void FUN_00048fb8(void);
extern void FUN_00049020(void);
extern void FUN_000351f0(void *src, void *dst);
extern void FUN_0005982c(Self *self);
extern void FUN_00059f10(Self *self);
extern void FUN_000593fc(Self *self, int idx, int flag, float value);

void FUN_000589c0(Self *self)
{
    if (self->f8c == 0 || self->f8c->f8 == 0) {
        return;
    }
    FUN_00048fb8();
    int flag = 1;
    if (self->f16c != 0 && self->recs[self->start_idx].f04 != 0 &&
        self->recs[self->end_idx].f04 != 0) {
        flag = 0;
    }
    if (flag != 0) {
        FUN_000351f0(self->f8c->f8, self->f160);
    }
    int i = self->start_idx;
    if (i <= self->end_idx) {
        do {
            self->recs[i].f14 = self->recs[i].f18 - 1.0f;
            FUN_000593fc(self, i, 1, self->recs[i].f18);
            i++;
        } while (i <= self->end_idx);
    }
    self->flag_ec = 0;
    if (flag != 0) {
        if (self->f16c != 0) {
            FUN_0005982c(self);
        }
        FUN_00059f10(self);
    }
    FUN_00049020();
}
