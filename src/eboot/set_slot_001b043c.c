/* HSTMATCH module=EBOOT.BIN start=0x001b043c end=0x001b04d0 symbol=FUN_001b043c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag FUN_001b043c) corrected by hand: slot pointer is &table->unk778[index] computed once and reused, shared slot_id = id + 0x15b, constant select if/else; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_table.h"

#define SLOT_ID_BASE 0x15b   /* added to the caller's id to get the slot number */

extern void FUN_001b0610(SlotTable *, int);
extern void FUN_001b0ef8(SlotTable *, int, int, int, int);

/* Release the old reference in entry `index`, load slot (id + SLOT_ID_BASE) (mode 1 when flag is set, else 2) and store its object in the entry. */
void FUN_001b043c(SlotTable *table, int index, int id, int flag)
{
    int *entry;
    int mode;
    int slot_id;

    entry = (int *)((char *)table + 0x778) + index;  /* unk778[index] */
    if (*entry != 0) {
        FUN_001b0610(table, index);
    }
    slot_id = id + SLOT_ID_BASE;
    if (flag != 0) {
        mode = 1;
    } else {
        mode = 2;
    }
    FUN_001b0ef8(table, slot_id, mode, 0, 0);
    *entry = (int)table->slot[slot_id];
}
