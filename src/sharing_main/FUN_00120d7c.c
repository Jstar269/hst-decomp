/* HSTMATCH module=hstp_trans_main.prx start=0x00120d7c end=0x00120e40 symbol=FUN_00120d7c lang=c99 */
/* Clone of src/eboot/FUN_00115e60.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b11d0;
extern u8 DAT_003b11e4;
extern u8 DAT_003b122c;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();
extern int * FUN_0010d2d4();

/* Destructor of a class with a virtual base: resets the vtables, destroys the member objects, frees the object when flags > 0. */
int * FUN_00120d7c(int *self,int flags)
{
  int *member;
  
  if (self != (int *)0x0) {
    self[1] = (int)&DAT_003b11d0;
    *(u8 **)*self = &DAT_003b11e4;
    *(int *)(*self + 0x130) = (int)(self + 0x1c) - *self;
    if ((flags != 0) && (self + 0x1c != (int *)0x0)) {
      member = self + 100;
      self[0x1c] = (int)&DAT_003b122c;
      if ((member != (int *)0x0) && (member != (int *)0x0)) {
        FUN_0010d2d4(member,0);
      }
      if (self + 0x1c != (int *)0x0) {
        self[0x1c] = (int)&DAT_003b0a68;
        FUN_0010642c(self + 0x1c,0);
      }
    }
    if (0 < (short)flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
