/* HSTMATCH module=hstp_trans_main.prx start=0x000963e0 end=0x000963ec symbol=FUN_000963e0 lang=c99 */
/* Clone of src/eboot/FUN_000944bc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/bone_link.h"

/* Sets the two bone names. */
void FUN_000963e0(BoneLink *self,const char *name_a,const char *name_b)
{
  self->nameA = name_a;
  self->nameB = name_b;
}
