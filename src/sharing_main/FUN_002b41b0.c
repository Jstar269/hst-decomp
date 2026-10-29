/* HSTMATCH module=hstp_trans_main.prx start=0x002b41b0 end=0x002b4214 symbol=FUN_002b41b0 lang=c99 */
/* Clone of src/eboot/FUN_000db724.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

extern u8 DAT_003b31ac;
extern RuleObj * DAT_003f469c;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();

/* Rule object destructor; frees the memory when delete_flag is positive. */
RuleObj * FUN_002b41b0(RuleObj *self,short delete_flag)
{
  if (self != (RuleObj *)0x0) {
    self->vtable = &DAT_003b31ac;
    DAT_003f469c = 0;
    FUN_0001ed28(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
