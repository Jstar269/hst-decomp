/* HSTMATCH module=hstp_trans_main.prx start=0x0011d5e4 end=0x0011d678 symbol=FUN_0011d5e4 lang=c99 */
/* Clone of src/eboot/FUN_001133a8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b100c;
extern u8 DAT_003b101c;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();

/* Destructor body for the object with a base at +0x10: restores the vtables and, when asked, destroys the base; frees when `flags` > 0. */
int * FUN_0011d5e4(int *self,int flags)
{
  int *base;
  
  if (self != (int *)0x0) {
    self[1] = (int)&DAT_003b100c;
    *(u8 **)*self = &DAT_003b101c;
    base = self + 4;
    *(int *)(*self + 0xd0) = (int)base - *self;
    if ((flags != 0) && (base != (int *)0x0)) {
      self[4] = (int)&DAT_003b0a68;
      FUN_0010642c(base,0);
    }
    if (0 < (short)flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
