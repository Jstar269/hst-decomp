/* HSTMATCH module=hstp_trans_main.prx start=0x00225178 end=0x002251c8 symbol=FUN_00225178 lang=c99 */
/* Clone of src/eboot/FUN_00216174.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/target_obj.h"

extern u32 DAT_003f3488;
extern void FUN_0022520c();

/* Constructor: remember the object in the global, reset it and set the starting position. */
TargetObj * FUN_00225178(TargetObj *self)
{
  DAT_003f3488 = (unsigned int)(self);
  FUN_0022520c();
  self->pos.x = 24.0f;
  self->pos.y = 0.36f;
  self->pos.z = 0.04f;
  return self;
}
