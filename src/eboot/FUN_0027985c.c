/* HSTMATCH module=EBOOT.BIN start=0x0027985c end=0x002798e8 symbol=FUN_0027985c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
extern void FUN_0001dfe8();
extern void FUN_0001e23c();

void FUN_0027985c(int param_1)
{
  FUN_0001dfe8(DAT_002cfc8c,0x2000);
  FUN_0001e23c(DAT_002cfc8c,0x2000,1);
  FUN_0001dfe8(DAT_002cfc8c,0x4000);
  FUN_0001e23c(DAT_002cfc8c,0x4000,1);
  *(u8 *)(param_1 + 0x170) = 0;
  *(u8 *)(param_1 + 0x171) = 0;
  *(u8 *)(param_1 + 0x172) = 0;
  *(u8 *)(param_1 + 0x173) = 0;
  *(u8 *)(param_1 + 0x174) = 0;
  *(u8 *)(param_1 + 0x175) = 0;
  *(u8 *)(param_1 + 0x176) = 0;
  *(u8 *)(param_1 + 0x177) = 0;
  *(u8 *)(param_1 + 0x17d) = 0;
}
