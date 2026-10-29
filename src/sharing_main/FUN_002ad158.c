/* HSTMATCH module=hstp_trans_main.prx start=0x002ad158 end=0x002ad1a0 symbol=FUN_002ad158 lang=c99 */
/* Clone of src/eboot/FUN_0029dfdc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea8ec;
extern void FUN_00103cd4();
extern void FUN_002a5ba8();
extern void FUN_002aa06c();
extern int FUN_002ad1a0();

typedef struct Target {
  char pad00[0x28];
  u32 unk28;  /* 0x28 cleared */
} Target;

typedef struct Holder {
  char pad00[0x3c];
  Target *target;  /* 0x3c */
} Holder;

void FUN_002ad158(Holder *self)
{
  Target *target;
  
  target = self->target;
  FUN_002ad1a0();
  FUN_00103cd4(0);
  target->unk28 = 0;
  FUN_002aa06c(target,3);
  FUN_002a5ba8(DAT_003ea8ec);
}
