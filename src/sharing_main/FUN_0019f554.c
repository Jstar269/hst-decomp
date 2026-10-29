/* HSTMATCH module=hstp_trans_main.prx start=0x0019f554 end=0x0019f59c symbol=FUN_0019f554 lang=c99 */
/* Clone of src/eboot/FUN_00192d44.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/pose_holder.h"

extern u32 * FUN_0019f38c();
extern u32 * FUN_0019f7c8();

/* Constructor: empty list, no owned objects, both poses initialized. */
PoseHolder * FUN_0019f554(PoseHolder *self)
{
  FUN_0019f7c8(&self->list);
  self->objB = 0;
  self->objA = 0;
  FUN_0019f38c(&self->poseA);
  FUN_0019f38c(&self->poseB);
  self->unk0 = 0;
  return self;
}
