/* HSTMATCH module=hstp_trans_main.prx start=0x0010642c end=0x001064bc symbol=FUN_0010642c lang=c99 */
/* Clone of src/eboot/FUN_00100b24.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0e38;
extern void FUN_00000a00();
extern int * FUN_001019c0();
extern int * FUN_00101a28();
extern void FUN_001064bc();

/* Destructor: resets the vtable word, destroys the two embedded members (last first), frees the object when flags > 0. */
u32 * FUN_0010642c(u32 *self,short flags)
{
  u32 *member;
  
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_003b0e38);
    FUN_001064bc();
    member = self + 4;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_00101a28(member,0);
    }
    member = self + 1;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_001019c0(member,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
