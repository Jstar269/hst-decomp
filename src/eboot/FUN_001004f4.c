/* HSTMATCH module=EBOOT.BIN start=0x001004f4 end=0x00100538 symbol=FUN_001004f4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00051478();

void FUN_001004f4(u32 param_1,int param_2)
{
  if ((*(u16 *)(param_2 + 0xe) & 0x600) != 0) {
    FUN_00051478(param_1,0xd4000000);
    FUN_00051478(param_1,0xd50441e0);
  }
}
