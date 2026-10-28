/* HSTMATCH module=EBOOT.BIN start=0x00127788 end=0x001277e8 symbol=FUN_00127788 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0033b4a8;
extern u32 DAT_0033b4ac;
extern void FUN_000006e8();
extern void FUN_000009e4();
extern void FUN_00055e48();

void FUN_00127788(void)
{
  if (DAT_0033b4ac != 0) {
    if (DAT_0033b4ac != 0) {
      FUN_000009e4(DAT_0033b4ac + -0x10);
    }
    DAT_0033b4ac = 0;
  }
  if (DAT_0033b4a8 != 0) {
    FUN_000006e8(DAT_0033b4a8,FUN_00055e48);
    DAT_0033b4a8 = 0;
  }
}
