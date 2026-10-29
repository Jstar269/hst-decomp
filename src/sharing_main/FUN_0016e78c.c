/* HSTMATCH module=hstp_trans_main.prx start=0x0016e78c end=0x0016e864 symbol=FUN_0016e78c lang=c99 */
/* Clone of src/eboot/FUN_00162200.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea848;
extern u32 DAT_003ea84c;
extern u32 DAT_003ea850;
extern void FUN_000006e8();
extern void FUN_00000a00();
extern int * FUN_00171914();
extern int * FUN_00171a30();
extern void FUN_0016e864();

/* Deleting destructor (short flag): releases two global handles when self is the current global instance, destroys the embedded member and the base, frees self when flag > 0. */
int FUN_0016e78c(int self,short flag)
{
  int member;
  
  if (self != 0) {
    if (self == DAT_003ea848) {
      if (DAT_003ea84c != 0) {
        FUN_000006e8(DAT_003ea84c,FUN_0016e78c);
        DAT_003ea84c = 0;
      }
      if (DAT_003ea850 != 0) {
        FUN_000006e8(DAT_003ea850,FUN_0016e864);
        DAT_003ea850 = 0;
      }
    }
    member = self + 0xc;
    if ((member != 0) && (member != 0)) {
      FUN_00171a30(member,0);
    }
    if ((self != 0) && (0 != self)) {
      FUN_00171914(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
