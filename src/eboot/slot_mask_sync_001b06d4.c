/* HSTMATCH module=EBOOT.BIN start=0x001b06d4 end=0x001b08a0 symbol=FUN_001b06d4 lang=c99 */
/* Hand-written reconstruction from the disassembly; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_table.h"

extern void FUN_00062418(void *, int);
extern void FUN_001b0ef8(SlotTable *, int, int, int, int);

/* Load the `count` slots listed in `slots`; when `prune` is set, first delete every slot object that is not in the list. */
void FUN_001b06d4(SlotTable *table, int *slots, int count, int prune)
{
    int i, j;
    unsigned char used[SLOT_COUNT];
    unsigned char *p;
    int n;

    if (prune != 0) {
        n = SLOT_COUNT;
        p = used;
        if (p != 0) {
            do {
                *p++ = 0;
            } while (--n);
        }
        for (i = 0; i < count; i++)
            used[slots[i]] = 1;
        for (j = 0; j < SLOT_COUNT; j++) {
            if (used[j] == 0) {
                if (table->slot[j] != 0) {
                    FUN_00062418(table->slot[j], 1);
                    table->slot[j] = 0;
                }
            }
        }
    }
    for (j = 0; j < count; j++)
        FUN_001b0ef8(table, slots[j], 0, 0, 0);
}
