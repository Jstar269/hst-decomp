/* HSTMATCH module=EBOOT.BIN start=0x000dcc20 end=0x000dcc3c symbol=FUN_000dcc20 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

/* Store the two words at +0x68 / +0x6c, only while the object is active. */
void FUN_000dcc20(RuleObj *self,int a,int b)
{
  if (self->active != 0) {
    self->unk68 = a;
    self->unk6c = b;
  }
}
