/* HSTMATCH module=EBOOT.BIN start=0x00162200 end=0x001622d8 symbol=FUN_00162200 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_00162200.c; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00341508;
extern u32 DAT_0034150c;
extern u32 DAT_00341510;
extern void FUN_000006e8();
extern void FUN_00000a00();
extern int * FUN_00165724();
extern int * FUN_00165840();
extern void FUN_001622d8();

/* Deleting destructor (short flag): releases two global handles when self is the current global instance, destroys the embedded member and the base, frees self when flag > 0. */
int FUN_00162200(int self,short flag)
{
  int member;
  
  if (self != 0) {
    if (self == DAT_00341508) {
      if (DAT_0034150c != 0) {
        FUN_000006e8(DAT_0034150c,FUN_00162200);
        DAT_0034150c = 0;
      }
      if (DAT_00341510 != 0) {
        FUN_000006e8(DAT_00341510,FUN_001622d8);
        DAT_00341510 = 0;
      }
    }
    member = self + 0xc;
    if ((member != 0) && (member != 0)) {
      FUN_00165840(member,0);
    }
    if ((self != 0) && (0 != self)) {
      FUN_00165724(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
