/* HSTMATCH module=EBOOT.BIN start=0x001b052c end=0x001b0610 symbol=FUN_001b052c lang=c99 */
/* Hand-written reconstruction from the disassembly; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_table.h"

extern void FUN_00062418(void *, int);

/* Release reference `index` of the 4-entry table: when no other entry refers to the same slot, delete that slot's object; then clear the entry and its flag byte. */
void FUN_001b052c(SlotTable *table, int index)
{
    int *entry;
    int *cursor;
    int matches;
    void *object;
    int scaled;

    scaled = index * 4;
    scaled += (int)table;
    entry = (int *)scaled + 0x1da;
    if (table->unk768[index] != 0) {
        cursor = table->unk768;
        matches = 0;
        if (cursor != table->unk778) {
            do {
                if (*cursor == *entry) {
                    matches = matches + 1;
                }
                cursor = cursor + 1;
            } while (cursor != table->unk778);
        }
        if (matches < 2) {
            register int i = 0;
            register void **p = table->slot;
            do {
                if ((int)*p == *entry) {
                    object = table->slot[i];
                    if (object != 0) {
                        FUN_00062418(object, 1);
                        table->slot[i] = 0;
                    }
                    break;
                }
                i = i + 1;
                p = p + 1;
            } while (i < SLOT_COUNT);
        }
        *entry = 0;
        table->unk798[index] = 0;
    }
}
/* Matching idiom: the entry pointer is formed from the scaled index first, then the base, then the 0x1da-int
   offset; the free loop is `do { if (*p == v) { if (slot[i]) { delete; slot[i] = 0; } break; } i++; p++; } while (i < SLOT_COUNT);`. */
