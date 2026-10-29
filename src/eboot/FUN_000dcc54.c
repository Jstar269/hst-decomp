/* HSTMATCH module=EBOOT.BIN start=0x000dcc54 end=0x000dcc6c symbol=FUN_000dcc54 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

void FUN_000dcc54(RuleObj *self,int value)
{
  if (self->active != 0) {
    self->unk7c = value;
  }
}
