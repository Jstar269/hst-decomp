/* HSTMATCH module=EBOOT.BIN start=0x00100b24 end=0x00100bb4 symbol=FUN_00100b24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307b6c;
extern void FUN_00000a00();
extern int * FUN_000fc284();
extern int * FUN_000fc2ec();
extern void FUN_00100bb4();

/* Destructor: resets the vtable word, destroys the two embedded members (last first), frees the object when flags > 0. */
u32 * FUN_00100b24(u32 *self,short flags)
{
  u32 *member;
  
  if (self != (u32 *)0x0) {
    *self = (unsigned int)(&DAT_00307b6c);
    FUN_00100bb4();
    member = self + 4;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_000fc2ec(member,0);
    }
    member = self + 1;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_000fc284(member,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
