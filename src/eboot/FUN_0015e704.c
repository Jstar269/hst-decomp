/* HSTMATCH module=EBOOT.BIN start=0x0015e704 end=0x0015e764 symbol=FUN_0015e704 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
extern void FUN_0001ebd4();
extern void FUN_0001efac();
extern bool FUN_0001efc0();
extern void FUN_0015e764();

void FUN_0015e704(u32 arg)
{
  u8 held;
  
  held = FUN_0001efc0();
  if (held != '\0') {
    FUN_0001efac();
  }
  FUN_0015e764(arg,DAT_002cfc8c);
  if (held != '\0') {
    FUN_0001ebd4();
  }
}
