/* HSTMATCH module=EBOOT.BIN start=0x001f4bbc end=0x001f4bfc symbol=FUN_001f4bbc lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_001f4bbc.c (tag: a1) */
#include "hst/slot_group.h"

extern unsigned int DAT_0034179c;
extern int FUN_001b1f84(void *, int *);

/* Release the group's handle (if it holds one) and mark it empty. */
void FUN_001f4bbc(SlotGroup *self)
{
    if (self->handle >= 0) {
        FUN_001b1f84(&DAT_0034179c, &self->handle);
        self->handle = -1;
    }
}
