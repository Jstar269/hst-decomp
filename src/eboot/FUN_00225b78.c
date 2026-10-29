/* HSTMATCH module=EBOOT.BIN start=0x00225b78 end=0x00225c34 symbol=FUN_00225b78 lang=c99 rodata=0x002c9a04 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_parts.h"

extern u8 DAT_0034179c;
extern char DAT_002f1280[];
extern char DAT_002f1290[];
extern char DAT_002f12a0[];
extern char DAT_002f12b0[];
extern char DAT_002f12c0[];
extern void FUN_001b28f0();

/* Pass the string that belongs to entry `index` (0..10) on to FUN_001b28f0. */
void FUN_00225b78(ModeObj *self,u32 index)
{
  switch(index) {
  case 0:
  case 2:
  case 3:
  case 9:
    FUN_001b28f0((int)&DAT_0034179c,DAT_002f1280);
    break;
  case 1:
  case 4:
  case 5:
    FUN_001b28f0((int)&DAT_0034179c,DAT_002f1290);
    break;
  case 6:
  case 7:
    FUN_001b28f0((int)&DAT_0034179c,DAT_002f12a0);
    break;
  case 8:
    FUN_001b28f0((int)&DAT_0034179c,DAT_002f12b0);
    break;
  case 10:
    FUN_001b28f0((int)&DAT_0034179c,DAT_002f12c0);
  }
}
