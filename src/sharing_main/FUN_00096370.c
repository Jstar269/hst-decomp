/* HSTMATCH module=hstp_trans_main.prx start=0x00096370 end=0x000963a0 symbol=FUN_00096370 lang=c99 */
/* Clone of src/eboot/FUN_0009444c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/bone_link.h"

/* Constructor: clears every field. */
BoneLink * FUN_00096370(BoneLink *self)
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
