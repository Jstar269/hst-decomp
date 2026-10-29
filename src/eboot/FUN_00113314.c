/* HSTMATCH module=EBOOT.BIN start=0x00113314 end=0x001133a8 symbol=FUN_00113314 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307cf0;
extern u8 DAT_00307cfc;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

/* Destructor body for the object with a base at +0x80: restores the vtables and, when asked, destroys the base; frees when `flags` > 0. */
int * FUN_00113314(int *self,int flags)
{
  int *base;
  
  if (self != (int *)0x0) {
    self[0x1f] = (int)&DAT_00307cf0;
    *(u8 **)*self = &DAT_00307cfc;
    base = self + 0x20;
    *(int *)(*self + 0xd0) = (int)base - *self;
    if ((flags != 0) && (base != (int *)0x0)) {
      self[0x20] = (int)&DAT_0030779c;
      FUN_00100b24(base,0);
    }
    if (0 < (short)flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
