/* HSTMATCH module=hstp_trans_main.prx start=0x000e0d40 end=0x000e0d58 symbol=FUN_000e0d40 lang=c99 */
/* Clone of src/eboot/FUN_000dcc3c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

void FUN_000e0d40(RuleObj *self,u8 value)
{
  if (self->active != 0) {
    self->unk70 = value;
  }
}
