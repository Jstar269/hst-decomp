/* HSTMATCH module=hstp_trans_main.prx start=0x00241214 end=0x00241268 symbol=FUN_00241214 lang=c99 */
/* Clone of src/eboot/FUN_00231114.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/singleton_holder.h"

extern SingletonHolder * DAT_003f398c;  /* the singleton */
extern void FUN_00000a00();
extern void FUN_002412cc();

/* Deleting destructor: clear the singleton, destroy the target, free the holder when flags > 0. */
SingletonHolder * FUN_00241214(SingletonHolder *self,short flags)
{
  if (self != 0) {
    DAT_003f398c = 0;
    FUN_002412cc();
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
