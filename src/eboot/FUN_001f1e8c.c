/* HSTMATCH module=EBOOT.BIN start=0x001f1e8c end=0x001f1ea8 symbol=FUN_001f1e8c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/prize_screen.h"

/* On the first frame sets a flag byte. */
void FUN_001f1e8c(PrizeScreen *self)
{
  if (self->unk44 == 0) {
    self->unk515 = 1;
  }
}
