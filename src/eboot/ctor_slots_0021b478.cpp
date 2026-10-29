/* HSTMATCH module=EBOOT.BIN start=0x0021b478 end=0x0021b5d0 symbol=FUN_0021b478 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/ease_screen.h"

#pragma opt_strength_reduction off
extern int DAT_003097a4;
extern int DAT_002f0160;
extern int DAT_002eff88;
extern int DAT_002f00b8;
extern int DAT_002f0100;
extern int DAT_002f0154;
extern int DAT_002f0158;
extern int DAT_002f0190;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" int FUN_001039d8(void *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void FUN_000143b0(void *, void *, int);
extern "C" void FUN_0021b79c(void *);

struct Entry {
    int idx;
    int id;
    int out;
};

extern "C" EaseScreen *FUN_0021b478(EaseScreen *self) {
    FUN_00102e38(self);
    self->vt = &DAT_003097a4;
    FUN_00104118(self, &DAT_002f0160, 0);
    FUN_00103540(self, *(float *)&DAT_002eff88);
    int slot_index = 0;
    int *slot_kinds = (int *)&DAT_002f00b8;
    int slot_off = 0;
    do {
        *(int *)((unsigned int)self + slot_off + 0x68) = FUN_001039d8(self, *slot_kinds, 0);
        slot_index++;
        slot_kinds++;
        slot_off += 4;
    } while (slot_index < EASE_SLOT_COUNT);
    int object_index = 0;
    Entry *entry = (Entry *)&DAT_002f0100;
    int object_off = 0;
    do {
        int *object = (int *)FUN_001026b8(*(int *)((char *)self + (entry->idx << 2) + 0x68), entry->id);
        *(int *)((unsigned int)self + object_off + 0x74) = (int)object;
        entry->out = object[9];
        object_index++;
        object_off += 4;
        entry++;
    } while (object_index < EASE_OBJECT_COUNT);
    int index_a = *(int *)&DAT_002f0154;
    int target_addr = *(int *)((char *)self->objects[index_a] + 0x20);
    self->target = (struct EaseTarget *)target_addr;
    int index_b = *(int *)&DAT_002f0158;
    self->unk94 = *(int *)((char *)self->objects[index_b] + 0x20);
    self->unk5c = 0;
    self->counter = EASE_COUNTER_IDLE;
    self->unk198 = 0;
    FUN_000143b0(self->buf, &DAT_002f0190, target_addr);
    FUN_0021b79c(self);
    return self;
}
