/* HSTMATCH module=EBOOT.BIN start=0x0021ab48 end=0x0021ab8c symbol=FUN_0021ab48 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the call to FUN_001b1c44 takes the module global by address and the state value 11 as the second argument Ghidra dropped (li a1,11 before the compare); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/selection_menu.h"

extern u8 DAT_0034179c;
extern void FUN_001b1c44(u8 *, int);
extern void FUN_0021abe0(SelectionState *, int);

/* When the state is 11, calls FUN_001b1c44 with 11 and switches to state 0. */
void FUN_0021ab48(SelectionState *self)
{
  if (self->state == 0xb) {
    FUN_001b1c44(&DAT_0034179c, 0xb);
    FUN_0021abe0(self, 0);
  }
}
