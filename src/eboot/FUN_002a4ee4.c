/* HSTMATCH module=EBOOT.BIN start=0x002a4ee4 end=0x002a4f18 symbol=FUN_002a4ee4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/savedata_screen.h"

extern void FUN_0010abe8();

/* While running, step the worker. */
void FUN_002a4ee4(SaveScreen *self)
{
  if (self->state == SAVE_STATE_RUN) {
    FUN_0010abe8(self->worker,&self->unk5d4);
  }
}
