/* HSTMATCH module=EBOOT.BIN start=0x0010b684 end=0x0010b6d4 symbol=FUN_0010b684 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010b150();
extern void FUN_0010b368();

void FUN_0010b684(int param_1,u32 param_2,u8 param_3)
{
  FUN_0010b368(param_1,0);
  *(u8 *)(param_1 + 0x114) = param_3;
  *(u32 *)(param_1 + 0x118) = param_2;
  FUN_0010b150(param_1);
}
