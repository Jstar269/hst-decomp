/* HSTMATCH module=EBOOT.BIN start=0x000db788 end=0x000db7f4 symbol=FUN_000db788 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

extern u8 DAT_00338b48; /* mode flag: when set the rule is forced to a short format */
extern u8 DAT_003417bb;
extern u8 DAT_0034189b;
extern u8 DAT_003419bb;
extern void FUN_000db7f4();
extern void FUN_000db868();

/* Apply the short-format settings if the mode flag is set, then reset score and state. */
void FUN_000db788(RuleObj *self)
{
  if (DAT_00338b48 != 0) {
    DAT_003417bb = 0;
    DAT_0034189b = 2;
    DAT_003419bb = 1;
    self->numSets = 1;
    self->gamesPerSet = 9;
  }
  FUN_000db7f4(self);
  FUN_000db868(self);
  self->unkb0 = 0;
}
