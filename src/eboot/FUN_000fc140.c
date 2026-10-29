/* HSTMATCH module=EBOOT.BIN start=0x000fc140 end=0x000fc19c symbol=FUN_000fc140 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

/* Destructor: resets the vtable word, runs the base destructor, frees the object when flags > 0. */
u32 * FUN_000fc140(u32 *self,short flags)
{
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_0030779c);
    FUN_00100b24(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
