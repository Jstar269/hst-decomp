/* HSTMATCH module=EBOOT.BIN start=0x0010b308 end=0x0010b368 symbol=FUN_0010b308 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010b368();
extern void FUN_00115f68();

void FUN_0010b308(int param_1)
{
  *(u32 *)(param_1 + 0xd4) = 0;
  *(u32 *)(param_1 + 0xd8) = 0;
  *(u32 *)(param_1 + 0x110) = 0;
  *(u8 *)(param_1 + 0x114) = 0;
  *(u32 *)(param_1 + 0x118) = 0;
  if (*(u32 *)(param_1 + 0x128) < 4) {
    FUN_00115f68(param_1 + 0x120,4);
  }
  *(u8 *)(param_1 + 0x12d) = 1;
  FUN_0010b368(param_1,0);
}
