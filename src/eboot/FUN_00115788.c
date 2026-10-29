/* HSTMATCH module=EBOOT.BIN start=0x00115788 end=0x00115800 symbol=FUN_00115788 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307bd8;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();
extern int * FUN_001163a8();

/* Destructor: destroys the member object at 0x8c, runs the base destructor, frees the object when flag > 0. */
u32 * FUN_00115788(u32 *self,short flag)
{
  u32 *member;
  
  if (self != (u32 *)0x0) {
    member = self + 0x23;
    *self = (unsigned int)(&DAT_00307bd8);
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_001163a8(member,0);
    }
    FUN_00102ea4(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
