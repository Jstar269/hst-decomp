/* HSTMATCH module=EBOOT.BIN start=0x0019ca8c end=0x0019ca94 symbol=FUN_0019ca8c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/view_params.h"

/* Set the float at 0x204. */
void FUN_0019ca8c(float value,ViewParams *self)
{
  self->unk204 = value;
  return;
}
