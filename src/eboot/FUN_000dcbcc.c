/* HSTMATCH module=EBOOT.BIN start=0x000dcbcc end=0x000dcbe8 symbol=FUN_000dcbcc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

/* Set flag byte 1 of the group at +0x64 while the object is active. */
void FUN_000dcbcc(RuleObj *self)
{
  if (self->active != 0) {
    self->unk64[1] = 1;
  }
}
