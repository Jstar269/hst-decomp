/* HSTMATCH module=hstp_trans_main.prx start=0x002251c8 end=0x0022520c symbol=FUN_002251c8 lang=c99 */
/* Clone of src/eboot/FUN_002161c4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/target_obj.h"

extern u32 DAT_003f3488;
extern void FUN_00000a00();

/* Destructor: clear the global that FUN_00216174 set, and free the object when `flag` is positive. */
TargetObj * FUN_002251c8(TargetObj *self,short flag)
{
  if ((self != 0) && (DAT_003f3488 = 0, 0 < flag)) {
    FUN_00000a00();
  }
  return self;
}
