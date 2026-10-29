/* HSTMATCH module=EBOOT.BIN start=0x0023a900 end=0x0023a928 symbol=FUN_0023a900 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/hist_obj.h"

extern void FUN_0023c338();

/* Calls FUN_0023c338 on the sub-object when the mode word is positive. */
void FUN_0023a900(HistObj *self)
{
  if (0 < self->unk3c) {
    FUN_0023c338(self->unk50);
  }
}
