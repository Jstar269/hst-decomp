/* HSTMATCH module=EBOOT.BIN start=0x002799a8 end=0x00279a2c symbol=FUN_002799a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declaration order and loop pointer; readability pass; exact match verified; names and types await human review. */
#include "hst/mode_menu.h"

#define SLOT_COUNT 16

extern void FUN_000ffb3c(void *, int);

/* Of the 16 slots, the one at `selected` gets 0 for both of its objects, all others 1. */
void FUN_002799a8(ModeMenu *self, int selected)
{
    int i;
    for (i = 0; i < SLOT_COUNT; i++) {
        if (i == selected) {
            FUN_000ffb3c(self->slots[i].left, 0);
            FUN_000ffb3c(self->slots[i].right, 0);
        } else {
            FUN_000ffb3c(self->slots[i].left, 1);
            FUN_000ffb3c(self->slots[i].right, 1);
        }
    }
}
