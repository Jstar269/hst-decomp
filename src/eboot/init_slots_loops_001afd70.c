/* HSTMATCH module=EBOOT.BIN start=0x001afd70 end=0x001afe0c symbol=FUN_001afd70 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: loop bounds written inclusive (i <= 0x31 etc.) to get slti at; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_table.h"

extern void FUN_001b04d0(SlotTable *self, int slot);

void FUN_001afd70(SlotTable *self)
{
    int i; /* slot id */
    i = 0x28;
    do {
        FUN_001b04d0(self, i);
        i = i + 1;
    } while (i <= 0x31);
    i = 0x84;
    do {
        FUN_001b04d0(self, i);
        i = i + 1;
    } while (i <= 0x97);
    i = 0x98;
    do {
        FUN_001b04d0(self, i);
        i = i + 1;
    } while (i <= 0xab);
    self->unk7a4 = -1;
    self->unk7c4 = -1;
    self->unk7c8 = SLOT_COUNT;
}
