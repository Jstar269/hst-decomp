/* HSTMATCH module=EBOOT.BIN start=0x00115e60 end=0x00115f24 symbol=FUN_00115e60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307f04;
extern u8 DAT_00307f18;
extern u8 DAT_00307f60;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();
extern int * FUN_00107514();

/* Destructor of a class with a virtual base: resets the vtables, destroys the member objects, frees the object when flags > 0. */
int * FUN_00115e60(int *self,int flags)
{
  int *member;
  
  if (self != (int *)0x0) {
    self[1] = (int)&DAT_00307f04;
    *(u8 **)*self = &DAT_00307f18;
    *(int *)(*self + 0x130) = (int)(self + 0x1c) - *self;
    if ((flags != 0) && (self + 0x1c != (int *)0x0)) {
      member = self + 100;
      self[0x1c] = (int)&DAT_00307f60;
      if ((member != (int *)0x0) && (member != (int *)0x0)) {
        FUN_00107514(member,0);
      }
      if (self + 0x1c != (int *)0x0) {
        self[0x1c] = (int)&DAT_0030779c;
        FUN_00100b24(self + 0x1c,0);
      }
    }
    if (0 < (short)flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
