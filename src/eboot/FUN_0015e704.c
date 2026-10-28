/* HSTMATCH module=EBOOT.BIN start=0x0015e704 end=0x0015e764 symbol=FUN_0015e704 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
extern void FUN_0001ebd4();
extern void FUN_0001efac();
extern bool FUN_0001efc0();
extern void FUN_0015e764();

void FUN_0015e704(u32 param_1)
{
  u8 cVar1;
  
  cVar1 = FUN_0001efc0();
  if (cVar1 != '\0') {
    FUN_0001efac();
  }
  FUN_0015e764(param_1,DAT_002cfc8c);
  if (cVar1 != '\0') {
    FUN_0001ebd4();
  }
}
