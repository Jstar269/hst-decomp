/* HSTMATCH module=EBOOT.BIN start=0x002a4558 end=0x002a45d8 symbol=FUN_002a4558 lang=c99 */
/* Hand-written reconstruction (external matching lane): the table read has to happen inside the
   second half of the && (a comma in the condition) so that it is issued after FUN_0022c988 and
   before the 0x1b0 == 5 test, which is retail's order; hoisting it into its own statement moves
   the load past the call. Exact match verified; names and types await human review. */
#include "hst/state_owner.h"

extern int DAT_002cc07c[]; /* mode id per index */
extern int FUN_0022c1c4();
extern int FUN_0022c988(int);
extern void FUN_002a2488(int, int);

/* Switch to the mode the table lists for the current index, unless blocked or the owner is locked. */
void FUN_002a4558(StateOwner *self)
{
    int index;
    int blocked;
    int mode;

    index = FUN_0022c1c4();
    blocked = FUN_0022c988(index);
    if (blocked == 0 && ((mode = DAT_002cc07c[index]), self->state != OWNER_STATE_LOCKED)) {
        self->prevMode = self->mode;
        self->mode = mode;
        self->unk1bc = 0;
        FUN_002a2488((int)self, 1);
    }
}
