/* HSTMATCH module=hstp_trans_main.prx start=0x002411d0 end=0x00241214 symbol=FUN_002411d0 lang=c99 */
/* Clone of src/eboot/FUN_002310d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/singleton_holder.h"

extern SingletonHolder * DAT_003f398c;  /* the singleton */
extern void FUN_00241268();
extern void FUN_00241348();

/* Constructor: register the holder as the singleton, create its target and set it pending. */
SingletonHolder * FUN_002411d0(SingletonHolder *self,u8 flag)
{
  self->target = 0;
  DAT_003f398c = self;
  self->flag = flag;
  FUN_00241268();
  FUN_00241348(self,1);
  return self;
}
