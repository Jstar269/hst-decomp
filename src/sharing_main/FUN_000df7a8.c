/* HSTMATCH module=hstp_trans_main.prx start=0x000df7a8 end=0x000df814 symbol=FUN_000df7a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

extern u8 DAT_003e1e88; /* mode flag: when set the rule is forced to a short format */
extern u8 DAT_003eaaf3;
extern u8 DAT_003eabd3;
extern u8 DAT_003eacf3;
extern void FUN_000df814();
extern void FUN_000df888();

/* Apply the short-format settings if the mode flag is set, then reset score and state. */
void FUN_000df7a8(RuleObj *self)
{
  if (DAT_003e1e88 != 0) {
    DAT_003eaaf3 = 0;
    DAT_003eabd3 = 2;
    DAT_003eacf3 = 1;
    self->numSets = 1;
    self->gamesPerSet = 9;
  }
  FUN_000df814(self);
  FUN_000df888(self);
  self->unkb0 = 0;
}
