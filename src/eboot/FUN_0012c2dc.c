/* HSTMATCH module=EBOOT.BIN start=0x0012c2dc end=0x0012c364 symbol=FUN_0012c2dc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c0e30;
extern void FUN_0012ca4c();

int FUN_0012c2dc(int param_1)
{
  *(u8 **)(param_1 + 0x40) = &DAT_002c0e30;
  *(u32 *)(param_1 + 0x70) = 0;
  *(u32 *)(param_1 + 0x74) = 0;
  *(u32 *)(param_1 + 0x78) = 0;
  *(u32 *)(param_1 + 0x84) = 0;
  *(u32 *)(param_1 + 0x88) = 0;
  *(u32 *)(param_1 + 0x8c) = 0;
  if (*(u32 *)(param_1 + 0x78) < 10) {
    FUN_0012ca4c(param_1 + 0x70,10);
  }
  if (*(u32 *)(param_1 + 0x8c) < 10) {
    FUN_0012ca4c(param_1 + 0x84,10);
  }
  *(u32 *)(param_1 + 0x90) = 0x3f800000;
  *(u8 *)(param_1 + 0x94) = 0;
  return param_1;
}
