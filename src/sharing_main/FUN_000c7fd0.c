/* HSTMATCH module=hstp_trans_main.prx start=0x000c7fd0 end=0x000c803c symbol=FUN_000c7fd0 lang=c99 */
/* Clone of src/eboot/FUN_000c4734.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b06fc;
extern u32 DAT_003e1e30;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_000c803c();

/* Destructor: resets the vtable word, runs the cleanup, clears the global instance pointer, frees the object when flags > 0. */
u32 * FUN_000c7fd0(u32 *self,short flags)
{
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_003b06fc);
    FUN_000c803c();
    DAT_003e1e30 = 0;
    FUN_0001ed28(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
