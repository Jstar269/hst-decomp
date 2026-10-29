/* HSTMATCH module=EBOOT.BIN start=0x00216174 end=0x002161c4 symbol=FUN_00216174 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/target_obj.h"

extern u32 DAT_0034a150;
extern void FUN_00216208();

/* Constructor: remember the object in the global, reset it and set the starting position. */
TargetObj * FUN_00216174(TargetObj *self)
{
  DAT_0034a150 = (unsigned int)(self);
  FUN_00216208();
  self->pos.x = 24.0f;
  self->pos.y = 0.36f;
  self->pos.z = 0.04f;
  return self;
}
