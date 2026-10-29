/* HSTMATCH module=EBOOT.BIN start=0x00192d44 end=0x00192d8c symbol=FUN_00192d44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/pose_holder.h"

extern u32 * FUN_00192b7c();
extern u32 * FUN_00192fb8();

/* Constructor: empty list, no owned objects, both poses initialized. */
PoseHolder * FUN_00192d44(PoseHolder *self)
{
  FUN_00192fb8(&self->list);
  self->objB = 0;
  self->objA = 0;
  FUN_00192b7c(&self->poseA);
  FUN_00192b7c(&self->poseB);
  self->unk0 = 0;
  return self;
}
