/* HSTMATCH module=EBOOT.BIN start=0x0018bd64 end=0x0018bd80 symbol=FUN_0018bd64 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00310ff8;
extern void FUN_0018b7a0();

void FUN_0018bd64(int param_1)
{
  *(u8 *)(param_1 + 0x44) = 1;
  DAT_00310ff8 = (unsigned int)(FUN_0018b7a0);
}
