/* HSTMATCH module=EBOOT.BIN start=0x0028144c end=0x002815c4 symbol=FUN_0028144c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/slot_block.h"

extern SetupData *DAT_003415a8;
extern unsigned char DAT_003417be;
extern int DAT_0034a77c;
extern int FUN_0024dd40(int, float);

/* Looks up the setup-table float for a slot id (0.0f when the flag byte is set) and converts it through FUN_0024dd40. */
static inline int GetSlotVal(short id) {
    SetupData *setup = DAT_003415a8;
    SetupTable *table = &setup->table;
    SetupEntry *e;
    if (id >= 0) {
        if (id < SETUP_ENTRY_COUNT) {
            e = &table->entries[id];
        } else {
            e = 0;
        }
    } else {
        e = 0;
    }
    float f = e->f4;
    if (DAT_003417be != 0) {
        f = 0.0f;
    }
    return FUN_0024dd40(DAT_0034a77c, f);
}

/* Assigns the team byte of each of the three slots according to the mode. */
void FUN_0028144c(SlotBlockOwner *self) {
    int team0 = GetSlotVal(self->block.slots[0].id);
    int team1 = 0;
    if (self->unk5c == 1) {
        if (self->mode == 3) {
        } else if (self->mode != 0) {
            team1 = GetSlotVal(self->block.slots[1].id);
        }
    }
    switch (self->mode) {
    case 3:
        self->block.slots[0].team = team0;
        self->block.slots[1].team = 9;
        self->block.slots[2].team = 9;
        break;
    case 2:
        self->block.slots[0].team = team0;
        self->block.slots[1].team = team1;
        self->block.slots[2].team = team1;
        break;
    case 1:
    case 0:
        self->block.slots[0].team = team0;
        self->block.slots[1].team = team1;
        self->block.slots[2].team = team1;
        break;
    }
}
