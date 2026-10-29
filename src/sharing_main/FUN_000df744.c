/* HSTMATCH module=hstp_trans_main.prx start=0x000df744 end=0x000df7a8 symbol=FUN_000df744 lang=c99 */
/* Clone of src/eboot/FUN_000db724.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

extern u8 DAT_003b08c4;
extern RuleObj * DAT_003e1e84;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();

/* Rule object destructor; frees the memory when delete_flag is positive. */
RuleObj * FUN_000df744(RuleObj *self,short delete_flag)
{
  if (self != (RuleObj *)0x0) {
    self->vtable = &DAT_003b08c4;
    DAT_003e1e84 = 0;
    FUN_0001ed28(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
