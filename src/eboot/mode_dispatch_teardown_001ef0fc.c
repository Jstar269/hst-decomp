/* HSTMATCH module=EBOOT.BIN start=0x001ef0fc end=0x001ef1ac symbol=FUN_001ef0fc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/prize_screen.h"

extern void FUN_001f2934(PrizeScreen *self);
extern void FUN_001f293c(PrizeScreen *self);
extern void FUN_001f2944(PrizeScreen *self);
extern void FUN_001f294c(PrizeScreen *self);
extern int FUN_001f92ec(PrizeScreen *self);
extern void FUN_002199c8(void *obj);

/* Per-frame step while the screen is on: common helper, then a helper chosen by mode, then the helper
   object is updated when the check helper reports non-zero. */
void FUN_001ef0fc(PrizeScreen *self)
{
    if (self->active == 0)
        return;

    FUN_001f2934(self);

    switch (self->sub.mode) {
    case 1:
        FUN_001f293c(self);
        break;
    case 14:
        FUN_001f2944(self);
        break;
    case 16:
        FUN_001f294c(self);
        break;
    }

    if (FUN_001f92ec(self) != 0) {
        if (self->obj != 0)
            FUN_002199c8(self->obj);
    }
}
