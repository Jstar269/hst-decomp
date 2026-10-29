/* HSTMATCH module=EBOOT.BIN start=0x000dcc3c end=0x000dcc54 symbol=FUN_000dcc3c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

void FUN_000dcc3c(RuleObj *self,u8 value)
{
  if (self->active != 0) {
    self->unk70 = value;
  }
}
