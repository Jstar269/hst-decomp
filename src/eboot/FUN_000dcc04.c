/* HSTMATCH module=EBOOT.BIN start=0x000dcc04 end=0x000dcc20 symbol=FUN_000dcc04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

/* Set flag byte 3 of the group at +0x64 while the object is active. */
void FUN_000dcc04(RuleObj *self)
{
  if (self->active != 0) {
    self->unk64[3] = 1;
  }
}
