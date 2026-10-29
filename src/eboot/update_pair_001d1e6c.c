/* HSTMATCH module=EBOOT.BIN start=0x001d1e6c end=0x001d1ec4 symbol=FUN_001d1e6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order and loop pointer; readability pass; exact match verified; names and types await human review. */
#include "hst/pair_items_obj.h"

extern void FUN_000ffb3c(void *, int);

/* Call the item hook on both items; the flag is 1 for every item except the selected one. */
void FUN_001d1e6c(PairItemsObj *self, unsigned int selected)
{
    unsigned int i;
    char *p = (char *)self;
    for (i = 0; i < PAIR_ITEM_COUNT; i++, p += 4) {
        FUN_000ffb3c(*(void **)(p + 0x6c), i != selected);
    }
}
