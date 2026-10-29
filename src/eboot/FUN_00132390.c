/* HSTMATCH module=EBOOT.BIN start=0x00132390 end=0x001323e8 symbol=FUN_00132390 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

extern void FUN_00000a00();
extern int * FUN_0013c908();

/* Deleting wrapper: destroy the array, then free the object when flag > 0. */
RawVec * FUN_00132390(RawVec *self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_0013c908(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
