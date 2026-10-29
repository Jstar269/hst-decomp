/* HSTMATCH module=EBOOT.BIN start=0x0019ca84 end=0x0019ca8c symbol=FUN_0019ca84 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Set the float at 0x208. */
void FUN_0019ca84(float value,ViewParams *self)
{
  self->unk208 = value;
  return;
}
