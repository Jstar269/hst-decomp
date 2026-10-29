/* HSTMATCH module=EBOOT.BIN start=0x0009444c end=0x0009447c symbol=FUN_0009444c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/bone_link.h"

/* Constructor: clears every field. */
BoneLink * FUN_0009444c(BoneLink *self)
{
  self->unk00[0] = 0;
  self->unk00[1] = 0;
  self->unk00[2] = 0;
  self->unk00[3] = 0;
  self->unk00[4] = 0;
  self->unk00[5] = 0;
  self->unk00[6] = 0;
  self->unk00[7] = 0;
  self->nameA = 0;
  self->nameB = 0;
  return self;
}
