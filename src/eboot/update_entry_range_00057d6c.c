/* HSTMATCH module=EBOOT.BIN start=0x00057d6c end=0x00057edc symbol=FUN_00057d6c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Resets the animation-entry range of the object: with the manager at +0x8c present it copies the
   manager's pose block into the object's own block at +0x160, then walks the 52-byte entries in
   [start_idx, end_idx], stores (entry->f18 - 1.0f) into entry->f14 and calls the per-entry update
   FUN_00058748; finally it clears the flag byte at +0xec and refreshes the pose (FUN_00058b78) and
   the matrices (FUN_0005922c) when the object's animation list at +0x16c is present. */
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

extern void FUN_00049194(void);
extern void FUN_000491cc(void);
extern void FUN_000351c8(void *src, void *dst);
extern void FUN_00058b78(Self *self);
extern void FUN_0005922c(Self *self);
extern void FUN_00058748(Self *self, int idx, int flag, float value);

void FUN_00057d6c(Self *self)
{
    if (self->f8c == 0 || self->f8c->f8 == 0) {
        return;
    }
    FUN_00049194();
    int flag = 1;
    if (self->f16c != 0 && self->recs[self->start_idx].f04 != 0 &&
        self->recs[self->end_idx].f04 != 0) {
        flag = 0;
    }
    if (flag != 0) {
        FUN_000351c8(self->f8c->f8, self->f160);
    }
    int i = self->start_idx;
    if (i <= self->end_idx) {
        do {
            self->recs[i].f14 = self->recs[i].f18 - 1.0f;
            FUN_00058748(self, i, 1, self->recs[i].f18);
            i++;
        } while (i <= self->end_idx);
    }
    self->flag_ec = 0;
    if (flag != 0) {
        if (self->f16c != 0) {
            FUN_00058b78(self);
        }
        FUN_0005922c(self);
    }
    FUN_000491cc();
}
