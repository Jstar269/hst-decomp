/* HSTMATCH module=hstp_trans_main.prx start=0x000e0d24 end=0x000e0d40 symbol=FUN_000e0d24 lang=c99 */
/* Clone of src/eboot/FUN_000dcc20.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

/* Store the two words at +0x68 / +0x6c, only while the object is active. */
void FUN_000e0d24(RuleObj *self,int a,int b)
{
  if (self->active != 0) {
    self->unk68 = a;
    self->unk6c = b;
  }
}
