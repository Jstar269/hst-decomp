/* HSTMATCH module=hstp_trans_main.prx start=0x000e8340 end=0x000e83a4 symbol=FUN_000e8340 lang=c99 */
/* Clone of src/eboot/FUN_000e1610.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b095c;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_000e84bc();

/* Destructor: resets the vtable word, runs the member and base destructors, frees the object when flags > 0. */
u32 * FUN_000e8340(u32 *self,short flags)
{
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_003b095c);
    FUN_000e84bc();
    FUN_0001ed28(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
