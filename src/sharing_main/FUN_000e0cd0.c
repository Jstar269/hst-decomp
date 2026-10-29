/* HSTMATCH module=hstp_trans_main.prx start=0x000e0cd0 end=0x000e0cec symbol=FUN_000e0cd0 lang=c99 */
/* Clone of src/eboot/FUN_000dcbcc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

/* Set flag byte 1 of the group at +0x64 while the object is active. */
void FUN_000e0cd0(RuleObj *self)
{
  if (self->active != 0) {
    self->unk64[1] = 1;
  }
}
